#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "board.h"

/*
Create the board for the game and placing the pieces in it
*/

/**
creates the board and assign it with '*'
* @param num_rows: the number of rows from user input
* @param num_cols: the number of columns from user input
* @param blank_char: '*' character
@return: the board
*/

char** create_empty_board( int num_rows, int num_cols, char blank_char){
	char** board = (char**)calloc(num_rows, sizeof(char*));
	for(int i = 0; i < num_rows; ++i){
		board[i] = (char*)calloc(num_cols, sizeof(char));
		for(int j = 0; j < num_cols; ++j){
			board[i][j] = blank_char;
		}
	}
	return board;
}

/**
prints out the board 
* @param board: the board
* @param num_rows: the number of rows from user input
* @param num_cols: the number of columns from user input
*/
void print_board(char** board, int num_rows, int num_cols){
	printf("  ");
	for(int j = 0; j < num_cols; ++j){
		printf("%d ", j);
	}
	printf("\n");
	for(int i = num_rows - 1; i >= 0; --i){
		printf("%d ", i);
		for(int j = 0; j < num_cols; ++j){
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}

/**
places player's piece into the board
* @param piece: the player's piece x/o
* @param board: the board
* @param col: the column the user want to place the piece in
* @param num_rows: the number of rows from user input
* @param num_cols: the number of columns from user input
* @param blank_char: '*' character
*/
void place_piece(char piece, char** board, int col, int num_rows, int num_cols, char blank_char){
	for (int i = 0; i < num_rows; i++){
		if (i == num_rows - 1 && board[i][col] == blank_char){
				board[i][col] = piece;
		}else if(board[i][col] != blank_char){
			board[i-1][col] = piece;
		}
	}
}

/**
deletes the board 
*@param num_rows: the number of rows from user input
*@param board: the board
*/
void delete_board(char** board, int num_rows){
	for(int i = 0 ; i < num_rows; ++i){
		free(board[i]);
	}
	free(board);
}

/**
checks if the user desired place to place a piece at a column is valid
* @param num_rows: number of rows from user input
* @param num_cols: number of columns from user input
* @param col: the column the user want to place the piece in
*/
bool move_is_on_board(int num_rows, int num_cols, int col){
	return is_between(col, 0, num_cols - 1) && is_between(col, 0, num_rows);
}

/**
checks if the desired column to place a piece in from user is in bound of the board dimensions
*@param value: the desired place to place the piece in at at a column
*@param min_val: the lowest value possible that the user's piece can be placed in on the board
*@param max_val: the greatest value possible that the user's piece can be placed in on the board
*/
bool is_between(int value, int min_val, int max_val){
	return value >= min_val && value <= max_val;
}

