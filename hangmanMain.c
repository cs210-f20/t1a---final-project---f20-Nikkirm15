/** hangmanMain.c
 * ===========================================================
 * Name: Nicolette McDonald, 24 NOV 2020
 * Section: T1/T2
 * Project: Final project - hangman
 * ===========================================================
 */

#include "hangman.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main(){

 printHangman(0);
char fileName[]= "dictionary.txt";
char *theWord = getWord(fileName);
char *gWord = prepGuessWord(theWord);
char let;
scanf("%c", &let);
int letter = findLetter(theWord, let);
//printf("1 is yes letter %d\n", letter);
turn(theWord, 3, 23); // manually change strike and count input to test

 char c;
 printf("end");
 scanf("%c", &c);   
    return 0;
}
