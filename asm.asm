// a simple example with a tic tac toe game

asm Info3ASM

import StandardLibrary

signature:
	// DOMAINS
	enum domain Task = { FARE_SPESA | STUDIARE | RIUNIONE | PARTITA_SCACCHI | ALLENAMENTO }

	enum domain Operazione = { INSERISCI_TASK | LOGOUT }

	enum domain Stato = { INSERISCI_USERNAME | INSERISCI_PASSWORD | MENU | SELEZIONA_TASK }

	abstract domain Utente

	// FUNCTIONS
	// controlled
	dynamic controlled print : Any
	dynamic controlled stato : Stato
	dynamic controlled utenteAttivo : Utente
	dynamic controlled listaTask : Utente -> Seq(Task)

	// monitored
	dynamic monitored operazione : Operazione
	dynamic monitored username : Utente
	dynamic monitored password : String
	dynamic monitored task : Task

	// costanti
	static lorenzo : Utente
	static admin : Utente

	// static functions
	derived getPassword : Utente -> String	// dichiarazione

definitions:
	// DOMAIN DEFINITIONS

	// FUNCTION DEFINITIONS

	function getPassword($u in Utente) =	// implementazione
		switch($u)
			case lorenzo : "password"
			case admin : "admin"
		endswitch


	// RULE DEFINITIONS
macro rule r_inserisciUsername =
	if ( stato = INSERISCI_USERNAME ) then
		if ( exist unique $u in Utente with $u = username ) then
			par
				utenteAttivo := username
				stato := INSERISCI_PASSWORD
				print := "Inserire password"
			endpar
		endif
	endif

macro rule r_inserisciPassword =
	if ( stato = INSERISCI_PASSWORD ) then
		let ( $password = getPassword(utenteAttivo) ) in
			if ($password = password) then
				par
					stato := MENU
					print := "Benvenuto, seleziona l'operazione che vuoi eseguire"
				endpar
			else
				par
					stato := INSERISCI_USERNAME
					print := "Password sbagliata, riprova"
				endpar
			endif
		endlet
	endif

macro rule r_menu =
	if( stato = MENU ) then
		par
			if ( operazione = INSERISCI_TASK ) then
				par
					stato := SELEZIONA_TASK
					print := "Seleziona un task"
				endpar
			endif
			if( operazione = LOGOUT ) then
				par
					stato := INSERISCI_USERNAME
					print := "Logout effettuato con successo"
				endpar
			endif
		endpar
	endif

macro rule r_sceltaTask =
	if( stato = SELEZIONA_TASK ) then
		if( exist unique $t in Task with $t = task ) then
			par
				listaTask( utenteAttivo ) := append( listaTask( utenteAttivo ), task)
				print := concat ("task aggiunto alla lista: ", toString( task ) )
				stato := MENU
			endpar
		endif
	endif

	// INVARIANTS

	// MAIN RULE
	main rule r_Main =
		seq
		r_inserisciUsername[]
		par
			r_inserisciPassword[]
			r_menu[]
			r_sceltaTask[]
		endpar
	endseq


// INITIAL STATE
default init s0:
	function stato = INSERISCI_USERNAME
	function print = "Inserire username"
	function listaTask( $u in Utente ) = []

