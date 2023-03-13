#include <stdbool.h>
#include <stdlib.h>
#include "win.h"
#include "board.h"

/*
Checks if a player has won the game
*/

/**
checks to see if game is over by determining if someone has won the game or if there is a tie
*@param board: the board
*@param num_rows: the number of rows from user input
*@param num_cols: the number of columns from user input
*@param number_of_pieces_in_a_row_needed_to_win: the number of pieces need to win from user input 
*@param blank_char: '*' character
@return: if someone won or there is a tie
*/

bool is_game_over(char** board, int num_rows, int num_cols, int number_of_pieces_in_a_row_needed_to_win, char blank_char){
	return someone_won(board, num_rows, num_cols, number_of_pieces_in_a_row_needed_to_win, blank_char) || tie(board, num_rows, num_cols, number_of_pieces_in_a_row_needed_to_win,  blank_char);
}

/**
checks if player won and if so either vertically, horizontally, or diagonally
*@param board: the board
*@param num_rows: the number of rows from user input
*@param num_cols: the number of columns from user input
*@param number_of_pieces_in_a_row_needed_to_win: the number of pieces need to win from user input 
*@param blank_char: '*' character
*@return: if someone won vertically, horizontally, or diagonally
*/
bool someone_won(char** board, int num_rows, int num_cols, int number_of_pieces_in_a_row_needed_to_win, char blank_char){
	return someone_won_vertically(board, num_rows, num_cols, number_of_pieces_in_a_row_needed_to_win, blank_char) ||
	someone_won_horizontally(board, num_rows, num_cols, number_of_pieces_in_a_row_needed_to_win, blank_char) ||
	someone_won_diagonally(board, num_rows, num_cols, number_of_pieces_in_a_row_needed_to_win, blank_char);
}
/**
checks if player won horizontally 
* @param board: the board
* @param num_rows: the number of rows from user input
* @param num_cols: the number of columns from user input
* @param number_of_pieces_in_a_row_needed_to_win: the number of pieces need to win from user input 
* @param blank_char: '*' character
@return: true if player won horizontally and false if player did not
*/
bool someone_won_horizontally(char** board, int num_rows, int num_cols, int number_of_pieces_in_a_row_needed_to_win, char blank_char){
	for(int i = 0; i < num_rows; ++i){
		int count = 0;
		for(int j = 0; j< num_cols; j++){
			if(board[i][j] == board[i][j-1] && board[i][j] != blank_char){
				count++;
				if(count == number_of_pieces_in_a_row_needed_to_win){
					return true;
				}
			}else{
				count = 1;
			}
		}
	}
	return false;
}

/**
checks if player won vertically 
* @param board: the board
* @param num_rows: the number of rows from user input
* @param num_cols: the number of columns from user input
* @param number_of_pieces_in_a_row_needed_to_win: the number of pieces need to win from user input 
* @param blank_char: '*' character
* @return: true if player won vertically and false if player did not
*/
bool someone_won_vertically(char** board, int num_rows, int num_cols, int number_of_pieces_in_a_row_needed_to_win, char blank_char){
	for(int j = 0; j < num_cols; ++j){
		int count = 0;
		for(int i = 0; i < num_rows; i++){
			if(board[i][j] == board[i-1][j] && board[i][j] != blank_char){
				count++;
				if(count == number_of_pieces_in_a_row_needed_to_win){
					return true;
				}
			} else{
				count = 1;
			}
		}
	}
	return false;
}

/**
checks if player won diagonally 
* @param board: the board
* @param num_rows: the number of rows from user input
* @param num_cols: the number of columns from user input
* @param number_of_pieces_in_a_row_needed_to_win: the number of pieces need to win from user input 
* @param blank_char: '*' character
* @param return: true if player won diagonally and false if player did not
*/
bool someone_won_diagonally(char** board, int num_rows, int num_cols, int number_of_pieces_in_a_row_needed_to_win, char blank_char){
	return someone_won_left_diagonally(board, num_rows, num_cols, number_of_pieces_in_a_row_needed_to_win, blank_char) ||
	 			 someone_won_right_diagonally(board, num_rows, num_cols, number_of_pieces_in_a_row_needed_to_win, blank_char);
}

/**
checks if player won left diagonally 
* @param board: the board
* @param num_rows: the number of rows from user input
* @param num_cols: the number of columns from user input
* @param number_of_pieces_in_a_row_needed_to_win: the number of pieces need to win from user input 
* @param blank_char: '*' character
* @return: true if player won left diagonally and false if player did not
*/
bool someone_won_left_diagonally(char** board, int num_rows, int num_cols, int number_of_pieces_in_a_row_needed_to_win, char blank_char){

	for(int i = 0; i < num_rows - number_of_pieces_in_a_row_needed_to_win +1; i++){
		for(int j = 0; j < num_cols - number_of_pieces_in_a_row_needed_to_win + 1; j++){
			int count = 1;
			for(int k = 1; k < number_of_pieces_in_a_row_needed_to_win; k++){
				if(board[i+k][j+k] == board[i+k -1][j+k-1] && board[i+k][j+k] == blank_char){
					count++;
					if(count == number_of_pieces_in_a_row_needed_to_win){
						return true;
					}
				}else{
					count = 1;
				}
			}
		}
	}
	return false;
}

/**
checks if player won right diagonally  
* @param board: the board
* @param num_rows: the number of rows from user input
* @param num_cols: the number of columns from user input
* @param number_of_pieces_in_a_row_needed_to_win: the number of pieces need to win from user input 
* @param blank_char: '*' character
* @param return: true if player won right diagonally and false if player did not
*/

bool someone_won_right_diagonally(char** board, int num_rows, int num_cols, int number_of_pieces_in_a_row_needed_to_win, char blank_char){
	for (int i = number_of_pieces_in_a_row_needed_to_win -1; i < num_rows; i++){
		for(int j = 0; j < num_cols - number_of_pieces_in_a_row_needed_to_win + 1; j++){
			int count = 1;
			for(int k = 1; k < number_of_pieces_in_a_row_needed_to_win; k++){
				if(board[i-k][j+k] == board[i-k+1][j+k-1] && board[i-k][j+k] != blank_char){
					count++;
					if(count == number_of_pieces_in_a_row_needed_to_win){
						return true;
					}
				}else{
					count = 1;
				}
			}
		}
	}
	return false;
}

/**
checks if there is a tie
* @param board: the board
* @param num_rows: the number of rows from user input
* @param num_cols: the number of columns from user input
*@param number_of_pieces_in_a_row_needed_to_win: the number of pieces need to win from user input 
*@param blank_char: '*' character
*@return: true if there is a tie and false if there is not
*/

bool tie(char** board, int num_rows, int num_cols, int number_of_pieces_in_a_row_needed_to_win,  char blank_char){
	if(someone_won(board, num_rows, num_cols, number_of_pieces_in_a_row_needed_to_win, blank_char)){
		return false;
	}
	for(int i = 0; i < num_rows; ++i){ 
		for(int j = 0; j < num_cols; ++j) 
			if(board[i][j] == blank_char){
				return false;
			}
	}
	return true;

}