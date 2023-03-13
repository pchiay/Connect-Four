#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include "input_validation.h"

/*
Checks if the user inputted valid values
*/

bool isValidFormat(const int numArgsRead, const int numArgsNeed);

/**
 * check if user input is a valid format
 * @param numArgsNeeded: the number of format placeholders that needed to have been read in the last scanf
 * @param numArgsRead: the actual number of placeholders that were read from scanf, ie its return value
 * @return: true if the input is correctly formatted and false otherwise
 */

bool isValidFormat(const int numArgsRead, const int numArgsNeed) {
  bool formatIsGood = numArgsRead == numArgsNeed;
  char character;
  do{
    scanf("%c", &character); 
		if(!isspace(character)){ 
			formatIsGood = false;
		}
	}while(character != '\n');
  return formatIsGood;
}

/**
 * Get an integer from the user but close the program if one is not entered
 * @param prompt : what the user inputted
 * @return a valid integer
 */
int getValidInt(const char* prompt){
  int num;
  const int numArgsNeeded = 1;
  int numArgsRead;
  do{
    printf("%s", prompt);
    numArgsRead = scanf(" %d", &num); 
  }while(!isValidFormat(numArgsRead, numArgsNeeded));

  return num;
}

/**
* check if a value is within the given ranges of numbers one being maximum value it should be less than and minimum value it shoudl be greater than
*@param val: the value being checked if is between the max and min value
*@param lowerBound: the minimum value 
*@param upperBound: the maximum value
*@return: a valid value within the max and min
*/
bool inbetween(int val, int lowerBound, int upperBound){
  return val >= lowerBound && val <= upperBound;
}

/**
 * check if user input has any space in between 
 * @param c: the input of user being checked
 * @return: if there is any white space
*/
bool my_isspace(char c){
	return c == ' ' || c == '\n' || c == '\t';
}