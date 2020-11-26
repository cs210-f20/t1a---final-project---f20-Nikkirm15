/** hangman.c
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
#include<time.h>
/** ----------------------------------------------------------
 * getWord() is used to read a random word
 * from a textual file
 * @param fileName is the name of the text file
 * @return random word
 * ----------------------------------------------------------
 */
char* getWord(fileName){
    char word[20];
    FILE *file = fopen(fileName, "r");
    srand(time(0));
    int rando = rand() % DICTSIZE;
    printf("rando is %d\n", rando);
    for(int i = 0 ; i < rando ; i++){
        fgets(word , sizeof(word) , file);
    }
    printf("%d\n", strlen(word));
   // word = (char*)malloc(strlen(word)*sizeof(char));
printf("the word is %s\n", word);
return word;
}

void turn( char word[], int strike, int count){
    if(strike <6 && count < strlen(word)){
      //turn code  
    }
    else {
       check4end(strike, count);
    }
}

void check4end(int strike, int count){
    if(strike >=6){
            
            printf("you lose too many strikes\n");
        }
        else{
            printf("you win you guessed the word\n");
           
        }
}
/*
int findLocations(char str[], int locations[], char searchChar){
    int length = strlen(str);
    int count = 0;
    for (int i =0; i<length; ++i){
        if(str[i] == searchChar){
            locations[count] = i;
            count = count +1;
        }
        
        
    }
    return count;
}
*/
/** ----------------------------------------------------------
 * findLetter() is used to see if the letter is in the word
 * @param word is the word
 * @param letter is the character to search for
 * @return 1 if the letter is there. 0 if it is not in the word
 * ----------------------------------------------------------
 */
int findLetter(char word[]){
   int yes=0;
   char letter;
   //printf("the word is %s\n", word);
   scanf("%c", &letter);
    for(int i= 0; i< strlen(word); i++){
        if(word[i] == letter){
           printf("inloop\n");  
           yes =1;
        }
    }
    return yes;
}

/** ----------------------------------------------------------
 * prepGuessWord() is used to creat the blank string that gets
 * filled in with guesses
 * @param word is the word chosen from the text file
 * @return string the same length as the word but filled with ?s
 * ----------------------------------------------------------
 */
char* prepGuessWord(char word[]){
    printf("string length for word is %d\n", strlen(word));
    char insert ='?';
    char guess[30];// = (char*)malloc((strlen(word)+1) * sizeof(char)); //why does it allocate to 3
   //printf("string length for guess is %d\n", strlen(guess));
   for(int i = 0; i < strlen(word); i++){
       guess[i] = insert;
       // printf("%d\n", i);
    }
     guess[strlen(word)] = '\0';
    *guess  = (char*)malloc((strlen(word)+1) * sizeof(char)); //why does it allocate to 3
    printf("string length for guess is %d\n", strlen(guess));
   
    printf("the word to be guessed is %s\n", guess );

}





/** ----------------------------------------------------------
 * printHangman() prints the corresponding picture to the 
 * number of strikes
 * @param strikes is the number of wrong guesses 
 * ----------------------------------------------------------
 */
void printHangman(int strikes){

switch (strikes)
{
case 0:
    printf("\n");
    printf(" |------|\n");
    printf(" |      |\n");
    printf(" |\n");
    printf(" |\n");
    printf(" |\n");
    printf(" ----------\n");
    break;
case 1:
 printf("\n");
    printf(" |------|\n");
    printf(" |      |\n");
    printf(" |      O\n");
    printf(" |\n");
    printf(" |\n");
    printf(" ----------\n");
    break;
case 2:
    printf("\n");
    printf(" |------|\n");
    printf(" |      |\n");
    printf(" |      O\n");
    printf(" |      |\n");
    printf(" |\n");
    printf(" ----------\n");
    break;
case 3:
    printf("\n");
    printf(" |------|\n");
    printf(" |      |\n");
    printf(" |      O\n");
    printf(" |      |\n");
    printf(" |     /\n");
    printf(" ----------\n");
    break;
case 4:
    printf("\n");
    printf(" |------|\n");
    printf(" |      |\n");
    printf(" |      O\n");
    printf(" |      |\n");
    printf(" |     / \\ \n");
    printf(" ----------\n");
    break;
case 5:
    printf("\n");
    printf(" |------|\n");
    printf(" |      |\n");
    printf(" |      O\n");
    printf(" |    --|\n");
    printf(" |     / \\ \n");
    printf(" ----------\n");
    break;
default:
    printf("\n");
    printf(" |------|\n");
    printf(" |      |\n");
    printf(" |      O\n");
    printf(" |    --|--\n");
    printf(" |     / \\ \n");
    printf(" ----------\n");

    break;
}
}
//strike =0
 /* |------|
    |      |
    |
    |
    |
   ----------
  */
 //strike 1
 /* |------|
    |      |
    |      O
    |
    |
   ----------
  */
//strike 2
 /* |------|
    |      |
    |      O
    |      |
    |
   ----------
  */
 //strike 3
 /* |------|
    |      |
    |      O
    |      |
    |     /
   ----------
  */
 //strike 4
 /* |------|
    |      |
    |      O
    |      |
    |     / \
   ----------
  */
 //strike 5
 /* |------|
    |      |
    |      O
    |    --|
    |     / \
   ----------
  */
 //strike 6
 /* |------|
    |      |
    |      O
    |    --|--
    |     / \
   ----------
  */

/*
void replStr(char str[], char aChar, char bChar){
    //char* index;
    int len = strlen(str);
    for(int i =0; i < len; ++i){
        if(str[i] == aChar){
            str[i] = bChar;
        }
    }
}
*/