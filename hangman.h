/** hangman.h
 * ===========================================================
 * Name: Nicolette McDonald, 4 DEC 2020
 * Section: T1/T2
 * Project: Final project - hangman
 * ===========================================================
 */
#ifndef HANGMAN_H
#define HANGMAN_H
#define DICTSIZE 178691; //number of words in the file used

void printHangman(int strikes);
void getWord(char fileName[], char *word);
void prepGuessWord(char word[], char *gWord);
void turn(char world[], char gWord[]);
int findLetter(char word[], int *locations, char *gWord, char letter);
void check4end(int strike, int count);
void changeGword(int *locations, char *gWord, char letter, int count);
int count_char(char str[], char c);
#endif //HANGMAN_H