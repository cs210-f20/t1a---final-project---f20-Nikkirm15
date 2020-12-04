/** hangmanMain.c
 * ===========================================================
 * Name: Nicolette McDonald, 4 DEC 2020
 * Section: T1/T2
 * Project: Final project - hangman
 * Documentation: During class lab periods Col Neff assisted me 
 * in debugging my strike count and my memory allocation
 * ===========================================================
 */

#include "hangman.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main(){
    //PLEASE LOOK AT HEADER.TXT FOR REQUIRMENTS AND DIRECTIONS
    char fileName[]= "dictionary.txt"; //dictionary file to read the words in from
    char theWord[20]; 
    char gWord[20];
    printf("\n");
    printf("\n");
    printf("  WELCOME TO HANGMAN\n");
    printf("\n");
    printf("you have 6 strikes to guess all the letters in the unknown word!!\n");
    printf("All guessed letters must be capital letters\n");
    printf("\n");
    printf("\n");
    getWord(fileName,theWord); //choose random word from file
    prepGuessWord(theWord, gWord); //fill guess word with question mark to the length of the unknown word
    turn(theWord, gWord); //take turns until game is over
    //game is over 
    printf("the word is %s\n", theWord);
    printf("END GAME\n");
    int d;
    printf("enter num to exit \n");
    scanf(" %d", &d); 
    return 0;
}
