/** hangman.h
 * ===========================================================
 * Name: Nicolette McDonald, 24 NOV 2020
 * Section: T1/T2
 * Project: Final project - hangman
 * ===========================================================
 */
#ifndef HANGMAN_H
#define HANGMAN_H
//do i need any kind of constant???
#define DICTSIZE 178691;

void printHangman(int strikes);
char* getWord(fileName);
char* prepGuessWord(char word[]);
void turn(char world[], int strike, int count);
//int findLocations(char str[], int locations[], char searchChar);
int findLetter(char word[]);
void check4end(int strike, int count);

#endif //HANGMAN_H