#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


#define STRING_ARRAY_SIZE    5
#define URL_ARRAY_SIZE       10
#define STRING_SIZE          20

typedef struct
{
	char *url;
	char *shorturl;
} Url;

void URL_Array_Allocator(Url ** urls, char ** strings, int * size);

void shorturlcpy(char * s);

void printUrlArray(Url **urls, int size);


int main(void)
{
    srand(time(NULL)); // reset rng radix

    char **strings = (char **)malloc(sizeof(char *) * STRING_ARRAY_SIZE); // array of 5 strings

    for (int i = 0; i < STRING_ARRAY_SIZE; i++)
       *(strings + i) = (char *)malloc(sizeof(char) * STRING_SIZE); // strings of 20 chars

    *(strings) 		= "www.unibg.it";
    *(strings + 1) 	= "www.lorenzoconti.it";
    *(strings + 2) 	= "www.amazon.com";
    *(strings + 3) 	= "www.google.com";
    *(strings + 4) 	= "www.facebook.com";

    for (int i = 0; i < STRING_ARRAY_SIZE; i++) printf("%s\n", *(strings + i));  // strings list

    Url **urls = (Url **)malloc(sizeof(Url *) * URL_ARRAY_SIZE);    // array of 10 URLs

    for (int i = 0; i < URL_ARRAY_SIZE; i++)		*(urls + i) = (Url *)malloc(sizeof(Url));   // URL allocation

    int size = 0;   // number of URLs saved in the URLs array

    URL_Array_Allocator(urls,strings,&size);

    printf("\n\n\n");

    printUrlArray(urls, size);

    return 0;
}

void URL_Array_Allocator(Url ** urls, char ** strings, int * size){

    if(*size >= URL_ARRAY_SIZE) {               // no empty space
        printf("\nARRAY FULL, NO EMPTY SPACE");
        return;
    };

    for(int i = 0; i < STRING_ARRAY_SIZE; i++){

        (**(urls + i)).url = *(strings + i);

        (**(urls + i)).shorturl = (char *) malloc(sizeof(char)*15);	// string allocation in order to use strcpy and strncat functions

        shorturlcpy((**(urls + i)).shorturl); 	// create shorturl

        printf("\nitem added : %s | %s \narray size: %d\n", (**(urls + i)).url, (**(urls + i)).shorturl, 1 +  *size);

        ++(*size);

    }
}

void shorturlcpy(char * s){

	strcpy(s,"cyc.url/");

    for(int i=0; i < 6; i++){

    	char c = (char) ( rand() % (90-65) ) + 65 +(rand() % 2 )*32 ;

    	strncat(s, &c, 1);
    }
}


void printUrlArray(Url **urls, int size){

	printf("URLs ARRAY LIST: \n\n");

	for(int i=0; i < size; i++)		printf("%d: %s -> %s\n", i, (**(urls+i)).url, (**(urls+i)).shorturl);
    return;
}
