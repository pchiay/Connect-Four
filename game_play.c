#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game_play.h"
#include "board.h"
#include "win.h"
#include "input_validation.h"

/* 
Plays the game of Connect 4 
*/

/**
determine which player turn it is always is player 1
*@return: the turn is player 1 everytime the game start
*/
int get_starting_player_turn(){
	return 0; 
}

/**
determine which player's piece goes to the player's turn
*@return: the player's piece
*/
char* get_player_pieces(){
	char* player_pieces = (char*)calloc(3, sizeof(char));
	strcpy(player_pieces, "XO");
	return player_pieces;
}

/**
sets the game up by creating a board and determining which player turn it is and what piece they have
* @param num_rows: the number of rows from user input
* @param num_cols: the number of columns from user input
* @param blank_char: '*' character
* @param out_board: the board 
* @param out_starting_player_turn: player's turn
* @param out_player_pieces: the player piece X/O
*/
void setup_game(int num_rows, int num_cols, char blank_char, char** *out_board,
								int *out_starting_player_turn, char* *out_player_pieces){
	char** board = create_empty_board(num_rows, num_cols, blank_char);
	int player_turn = get_starting_player_turn();
	char* player_pieces = get_player_pieces();
	*out_board = board;
	*out_starting_player_turn = player_turn;
	*out_player_pieces = player_pieces;
}

/**
the player is taking their turn and placing a piece on the board
* @param board: the board
* @param num_rows: the number of rows from user input	
* @param num_cols: the number of columns from the user input
* @param number_of_pieces_in_a_row_needed_to_win: the number of pieces needed to win
* @param blank_char: '*' character
* @param cur_player_piece: the player's piece 
*/
void cur_player_take_turn(char**board, int num_rows, int num_cols, int number_of_pieces_in_a_row_needed_to_win, char blank_char, char cur_player_piece ){
	int col;
	print_board(board,num_rows, num_cols);
	get_valid_move_from_player(board, num_rows, num_cols, blank_char, &col);
	place_piece(cur_player_piece, board, col, num_rows, num_cols, blank_char);
}

/**
check to see if player's move is valid or not
*@param board: the board
*@param num_rows: the number of rows from user input
*@param num_cols: the number of columns from user input
*@param blank_char: '*' character
*@param out_col: the column user want to place the piece in 
*/
void get_valid_move_from_player(char** board, int num_rows, int num_cols,  char blank_char,
																int*out_col){
	int num_args_read;
	static int num_times_called = 0;
	do{
		printf("Enter a column between 0 and %d to play in: ", num_cols - 1);
		num_args_read = scanf("%d", out_col);
		num_times_called++;
		if(num_times_called > 20){
			exit(0);
		}
	}while(!is_valid_move(num_args_read, board, num_rows, num_cols, blank_char, *out_col));
}

/**
check if the move from player is valid 
* @param num_args_read: the number of values that was read from the user
* @param board: the board
* @param num_rows: the number of rows from the user input 
* @param num_cols: the number of columns from the user input
* @param blank_char: '*' character
* @param col: the column the user wants to place the piece in
@return: if the move is valid and is on the board and that the board is not already full at that position
*/
bool is_valid_move(int num_args_read, char** board, int num_rows, int num_cols, char blank_char, int col){
	const int num_args_needed = 1;
	return isValidFormat(num_args_read, num_args_needed) &&
					move_is_on_board(num_rows,num_cols, col) && board[num_rows][col] == blank_char;
}

/**
switches players turn
* @param cur_player_turn: the current player's turn
* @param number_of_players: the number of players that are playing always set to 2
*/
void change_turns(int* cur_player_turn, int number_of_players){
	*cur_player_turn = (*cur_player_turn + 1 ) % number_of_players;
}

/**
tells the user who won 
* @param board: the board
* @param num_rows: the number of rows from user input
* @param num_cols: the number of columns form user input
* @param number_of_pieces_in_a_row_needed_to_win: 
* @param blank char: '*' character
* @param cur_player_turn: the player's turn 
*/
void announce_results(char** board, int num_rows, int num_cols, int number_of_pieces_in_a_row_needed_to_win,  char blank_char, int cur_player_turn){
	if(someone_won(board, num_rows, num_cols, number_of_pieces_in_a_row_needed_to_win,  blank_char)){
			if(cur_player_turn == 0){
				printf("Player 1 won the game!\n");
			}else{
				printf("Player 2 won the game!\n");
			}
	}else{
		printf("Tie game\n");
	}

}

/**
play the game of connect 4 when given the user inputs of the places they 
* @param board: the board
* @param num_rows: the number of rows from user input
* @param num_cols: the number of columns form user input
* @param number_of_pieces_in_a_row_needed_to_win: the number of pieces needed to win from user input
* @param blank_char: '*' character
* @param starting_play_turn: which player starts 
* @param player_pieces: the player piece 
*/
void play_game(char** board, int num_rows, int num_cols, int number_of_pieces_in_a_row_needed_to_win,  char blank_char, int starting_player_turn,
               char* player_pieces){
	int cur_player_turn = starting_player_turn;
	const int num_players = 2;
	while(true){
		cur_player_take_turn(board, num_rows, num_cols, number_of_pieces_in_a_row_needed_to_win,  blank_char, player_pieces[cur_player_turn]);
		if(is_game_over(board, num_rows, num_cols, number_of_pieces_in_a_row_needed_to_win,  blank_char)){
			break;
		}
		change_turns(&cur_player_turn, num_players);
	}
	print_board(board,num_rows, num_cols);
	announce_results(board, num_rows, num_cols, number_of_pieces_in_a_row_needed_to_win, blank_char, cur_player_turn);
}

/**
clears the board 
* @param oard: the board
* @param num_rows: the number of rows from user input
* @param player_pieces: 
*/
void clean_up(char** board, int num_rows, char* player_pieces){
	delete_board(board, num_rows);
	free(player_pieces);
}