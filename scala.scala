import scala.math.sqrt
import scala.math.pow
import scala.collection.mutable.ListBuffer


object ScalaGame {
  
  def main(args: Array[String]){
    
    val rng = scala.util.Random
    
    /*** CREATE ATTACKERS FACTION WITH 5 MEMBERS ***/   
    
    var attackers = new ListBuffer[Player]()     // attackers faction
    
    for (i <- 1 to 5)          
      attackers.append(new Attacker("Attacker " + i, 50, 2*i, new Coord( rng.nextInt(10), rng.nextInt(10)), 1 + rng.nextInt(2) ))

    println
    attackers.foreach(println)
    
    /*** CREATE DEFENDERS FACTION WITH 5 MEMBERS ***/
    
    var defenders = new ListBuffer[Player]()    // defenders faction
    
    for (i <- 1 to 5)          
      defenders.append(new Defender("Defender " + i, 70 + rng.nextInt(10)*5, 2, new Coord( rng.nextInt(10), rng.nextInt(10)), 3+rng.nextInt(3)))


    defenders.foreach(println)
    println
    
   
    /*** START THE GAME ***/
    
    var respawn = false
    
    while(attackers.nonEmpty && defenders.nonEmpty){  // Game Cycle: ends when one of the two factions loss
      
      respawn = false
           
      var distance = attackers(0).pos.distance(defenders(0).pos.x, defenders(0).pos.y)  // Initial distance between attacker and defender position
        
      while (attackers.nonEmpty && distance > 0 && attackers(0).hp > 0) {  // Moving Attacker to Defender Cycle 
                  
        distance = moveAndAttack(attackers(0).asInstanceOf[Attacker],defenders(0).asInstanceOf[Defender], distance)   // remaining distance to be traveled
      
        if(attackers(0).hp <= 0) {               // attacker died during the travel 
          println("\n" + attackers(0).name + " DIED\n")  
          attackers.remove(0)
          }  
      }
    
    if(attackers.nonEmpty) println("\n" + attackers(0).name + " REACHED " + defenders(0).name + " !\n")
    
    while (attackers.nonEmpty && defenders.nonEmpty && (attackers(0).hp > 0 && defenders(0).hp > 0) && !respawn){   // Attacking Cycle
      
      doAttack(attackers(0), defenders(0))            // attacker attack defender
      doAttack(defenders(0), attackers(0))            // defender attack attacker
      
      if(attackers(0).hp <= 0) {                      // attacker died during fight
        println("\n" + attackers(0).name + " DIED\n") 
        attackers.remove(0)
        respawn = true                                // a new attacker will move to the alive defender
       }
      
      if(defenders(0).hp <= 0) {                      // defender died during fight
        println("\n" + defenders(0).name + " DIED\n")  
        defenders.remove(0)
        respawn = true                                // the survivor attacker will move to the next defender
       }
    }    
  }   
    
    if(attackers.isEmpty && defenders.nonEmpty) println("\nGAME OVER")
    if(defenders.isEmpty && attackers.nonEmpty) println("\nYOU WIN")
    if(defenders.isEmpty && attackers.isEmpty)  println("\nTIE")
      
}   
 

/*** UTILITIES METHODS ***/
    
  def doAttack(a: {def attack : Int}, d: Player) {
    d.defend(a.attack)
  }
  
  def moveAndAttack(p : Attacker, d : Defender, dist : Double) = {
    
    println(p.name + " is moving to "  + d.name)
    doAttack(d,p)
    move(p,dist)
  }
  
  def move[T <: Movable](p : T, dist : Double) : Double = {   
    p.move(dist)   
  }
  
}


// beheviour traits
trait Movable { def move(distance : Double) : Double}  

trait Attack { def attack : Int }

trait Defend { def defend(dmg : Int) }

trait Act extends Attack with Defend


/*
 * Generic Player Class:
 * name : name of the player
 * hp 	: health points
 * dmg 	: damage dealth
 * pos	: spawn coordinates 
 * 
 */
abstract class Player(val name: String, private var _hp: Int, val dmg: Int, val pos : Coord) extends Act {
  
  def hp = _hp
  def hp_(nhp : Int) {
    println(name + " is taking damage! HP: " + hp + " -> " + nhp)
    _hp = nhp
  }  
  

  def attack = dmg
  def defend(dmg : Int) = hp_(_hp-dmg)
 }



/*
 * Attacker Class: is movable, can deal damage and take damage
 * step	: length of the step on the map
 */
class Attacker(override val name: String, private var _hp: Int,override val dmg: Int,override val pos: Coord, val step: Int) 
extends Player(name,_hp,dmg,pos) with Movable
{
  
    def move(distance : Double) = distance - step
    
    override def toString() : String = {
      val jumper = if(step == 1) " jumper " else ""
     return name + " HP: " + hp + " DMG: " + dmg +  "SPAWNED AT: (" + pos.x + "," + pos.y + ")" + " " + jumper
  }
}

/*
 * Defender Class: can deal damage and take damage
 * range	: area within it deals damage
 */
class Defender(override val name: String, private var _hp: Int,override val dmg: Int,override val pos: Coord, val range: Int) 
extends Player(name,_hp,dmg,pos){
  
    override def toString() : String = {
     return name + " HP: " + hp + " DMG: " + dmg + " SPAWNED AT: (" + pos.x + "," + pos.y + ") with RANGE: " + range
  }
}


// coordinates class for the game map
class Coord(var x : Int, var y : Int){
  
  def distance(px : Int, py: Int) : Double = sqrt(pow(x-px,2) + pow(y-py,2))  
}





