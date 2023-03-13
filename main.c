#include <stdio.h>
#include <stdlib.h>
#include "game_play.h"

/*
Takes in user input of number of rows, number of columns, and number of pieces needed to win in a game of connect 4 to play the game
*/

void check_argument(int argc, char** argv, int* num_rows, int* num_cols, int* number_of_pieces_in_a_row_needed_to_win);

/**
check if there is enough arguments entered from user in command line and if so convert it from a string value to integer values then 
assign those values to number of rows, number of columns, and number of pieces needed to win
* @param argc: the number of arguments 
* @param argv: the values entered by user in command line 
* @param num_rows: the number of rows entered by the user
* @param num_cols: the number of columns entered by the user 
* @param number_of_pieces_in_a_row_needed_to_win: the number of pieces that the user need to win the game
*/

void check_argument(int argc, char** argv, int* num_rows, int* num_cols, int* number_of_pieces_in_a_row_needed_to_win){    
    if(argc > 4){
      printf("Too many arguments entered\n");
      printf("Usage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win\n");
      exit(0);
    }else if(argc < 4){
      printf("Not enough arguments entered\n");
      printf("Usage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win\n");
      exit(0);
    }else{
      *num_rows = atoi(argv[1]);
      *num_cols = atoi(argv[2]);
      *number_of_pieces_in_a_row_needed_to_win = atoi(argv[3]);
    }
  }

int main(int argc, char* argv[]){
  int num_rows;
  int num_cols;
  int number_of_pieces_in_a_row_needed_to_win;

	char blank_char = '*';
	char** board;
	char* player_pieces;
	int player_turn;
  check_argument(argc, argv, &num_rows, &num_cols, &number_of_pieces_in_a_row_needed_to_win);   
	setup_game(num_rows, num_cols, blank_char, &board, &player_turn, &player_pieces);
	play_game(board, num_rows, num_cols, number_of_pieces_in_a_row_needed_to_win, blank_char, player_turn, player_pieces);
	clean_up(board, num_rows, player_pieces);
	return 0;

}