/** hangman.c
 * ===========================================================
 * Name: Nicolette McDonald, 4 DEC 2020
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
void getWord(char fileName[], char *word){
    FILE *file = fopen(fileName, "r");
    srand(time(0)); //This function is only called once so it is okay to do srand here.
    int rando = rand() % DICTSIZE;
    for(int i = 0 ; i < rando ; i++){ //Get random word.
        fgets(word , 20 , file);
    }
    return word;
}


/** ----------------------------------------------------------
 * prepGuessWord() is used to creat the blank string that gets
 * filled in with guesses
 * @param word is the word chosen from the text file
 * @return string the same length as the word but filled with ?s
 * ----------------------------------------------------------
 */
void prepGuessWord(char word[], char *gWord){
    printf("string length for word is %d\n", strlen(word)-1);
    for(int i = 0; i < strlen(word)-1; i++){ 
       gWord[i] = '?'; //fill the gWord with ? marks
    }
    //gWord = (char*)realloc(gWord, strlen(word) * sizeof(char));  Col Neff tried to fgure this out with me but my dynamic memeory allocation messed up the program
    gWord[strlen(word)-1] = '\0'; // Add null cahrcter at the end.
    printf("string length for guess is %d\n", strlen(gWord));
    printf("\n");
    printf("\n");
    printf("the word to be guessed is %s\n", gWord );
    printf("\n");
    printf("\n");
}
/** ----------------------------------------------------------
 * turn() is the bulk of the game. The user to keep guessing 
 * letters unitl the word is guessed or the hangman is drawn
 * @param word is the string of the word to be guessed 
 * @param gWord is the string of ?s to be filled in as letters
 * are guessed 
 * ----------------------------------------------------------
 */
void turn( char word[], char gWord[]){
    int strike  = 0; //wrong guesses
    int count = 0; //number of appearances for the letter
    int totCount =0; //total amount of letters guessed correctly
    int locations[20]; //After every letter fill in we need to reset locations.
    while(strike <6 && totCount < strlen(word)-1){
        count = findLetter(word, locations,gWord, strike);
        if(count == 0){
            strike = strike +1; //If guess is wrong, add a strike.
            printHangman(strike);
            printf("\n WORD : %s\n", gWord);
        }
      else{
            totCount = totCount + count; //Add to the total after each turn.
      }
    printf(" strike value is : %d  count value is : %d\n", strike, totCount);
    printf("---------------------------------------------------------------------\n");
     
    }
    check4end(strike, totCount);
}


/** ----------------------------------------------------------
 * findLetter() is used to see if the letter is in the word
 * @param word is the word
 * @param locations is the integer array of indexs where the 
 * guessed letter is located in the word
 * @param gWord is the string of ?s to be filled in as letters
 * @param strike is the number of wrong guesses
 * @return # of times the letter appears. 0 if it is not in the word
 * ----------------------------------------------------------
 */
int findLetter(char word[], int *locations, char *gWord,int *strike){
   int index = 0;
   char letter;
   int count;
   printf("enter a letter to be searched for (must be capital letter)" );
   scanf(" %c", &letter);
   printf("\nthe letter to be searched for is %c\n",letter );
    for(int i= 0; i< strlen(word); i++){
        if(word[i] == letter){ //Search for the letter in the unknown word.
            locations[index] = i; // Add the index of each letter appearance to an array.
            index = index +1; //number of appearances
        }
    }
    count = count_char(word, letter);
    printf("index is %d and the count from recursion is %d\n", index, count);
    if(count > 0){
        changeGword(locations, gWord, letter, count);
    }
    return count;
}
/** ----------------------------------------------------------
 * countChar() counts the occurences of a char c in the given
 * string
 * @param str is the string to be searched
 * @param c is the character to be searched for
 * @return int of the number of occurences of c in the string
 * ----------------------------------------------------------
 */
int count_char(char str[], char c) {
    if(*str == '\0'){
        return 0;
    }
    else if ( *str == c){
       return 1+ count_char(str +1, c);
    }
    else{
        return count_char(str +1, c);
    }
    
}
/** ----------------------------------------------------------
 * changeGword() fillins in the correctly giessed letters in 
 * the gWord string
 * @param locations is the integer array of indexs where the
 * guessed letter is located in the word
 * @param gWord is the string of ?s to be filled in as letters
 * @param letter is the character guessed by the user
 * @param count is the number of times the letter is in the word
 * ----------------------------------------------------------
 */
void changeGword(int *locations, char *gWord, char letter, int count){ //call this in find letter so you can pass in letter
    for(int i =0; i<count; i++){
        gWord[locations[i]] = letter; //Change the ? to the guessed letter.
    }
    printf("\n");
    printf("\n");
    printf("\nthe new gWord is %s\n", gWord);
    printf("\n");
    printf("\n");
    locations = 'NULL'; //Empty the array for the next letter to be guessed.
}


/** ----------------------------------------------------------
 * check4end determines if the game is ending becuase the word 
 * was guessed or the hangman was complete
 * @param strike is the number of wrong guesses
 * @param count is the number of correct guesses
 * ----------------------------------------------------------
 */
void check4end(int strike, int count){
    if(strike >=6){
            printf("\n");
            printf("\n");
            printf("++++++++++++++++++++++++++++\n");
            printf("+                          +\n");
            printf("+   too many strikes!!     +\n");
            printf("+     GAME OVER!!!!        +\n");
            printf("+                          +\n");
            printf("++++++++++++++++++++++++++++\n");
        }
        else{
            printf("\n");
            printf("\n");
            printf("++++++++++++++++++++++++++++\n");
            printf("+                          +\n");
            printf("+  you guessed the word!!  +\n");
            printf("+       YOU WIN!!!!!!!!    +\n");
            printf("+                          +\n");
            printf("++++++++++++++++++++++++++++\n");
           
        }
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
    printf("strikes: %d\n", strikes);
    printf(" |------|\n");
    printf(" |      |\n");
    printf(" |\n");
    printf(" |\n");
    printf(" |\n");
    printf(" ----------\n");
    break;
case 1:

 printf("\n");
    printf("strikes: %d\n", strikes);
    printf(" |------|\n");
    printf(" |      |\n");
    printf(" |      O\n");
    printf(" |\n");
    printf(" |\n");
    printf(" ----------\n");
    break;
case 2:
    printf("\n");
    printf("strikes: %d\n", strikes);
    printf(" |------|\n");
    printf(" |      |\n");
    printf(" |      O\n");
    printf(" |      |\n");
    printf(" |\n");
    printf(" ----------\n");
    break;
case 3:
    printf("\n");
    printf("strikes: %d\n", strikes);
    printf(" |------|\n");
    printf(" |      |\n");
    printf(" |      O\n");
    printf(" |      |\n");
    printf(" |     /\n");
    printf(" ----------\n");
    break;
case 4:
    printf("\n");
    printf("strikes: %d\n", strikes);
    printf(" |------|\n");
    printf(" |      |\n");
    printf(" |      O\n");
    printf(" |      |\n");
    printf(" |     / \\ \n");
    printf(" ----------\n");
    break;
case 5:
    printf("\n");
    printf("strikes: %d\n", strikes);
    printf(" |------|\n");
    printf(" |      |\n");
    printf(" |      O\n");
    printf(" |    --|\n");
    printf(" |     / \\ \n");
    printf(" ----------\n");
    break;
default:
    printf("\n");
    printf("strikes: %d\n", strikes);
    printf(" |------|\n");
    printf(" |      |\n");
    printf(" |      O\n");
    printf(" |    --|--\n");
    printf(" |     / \\ \n");
    printf(" ----------\n");

    break;
}
}
