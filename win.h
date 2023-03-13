#ifndef WIN_H
	#define WIN_H
	#include <stdbool.h>
	bool is_game_over(char** board, int num_rows, int num_cols, int number_of_pieces_to_win, char blank_char);
	bool someone_won(char** board, int num_rows, int num_cols, int number_of_pieces_to_win, char blank_char);
	bool someone_won_horizontally(char** board, int num_rows, int num_cols, int number_of_pieces_to_win,  char blank_char);
	bool someone_won_vertically(char** board, int num_rows, int num_cols, int number_of_pieces_to_win,  char blank_char);
	bool someone_won_diagonally(char** board, int num_rows, int num_cols, int number_of_pieces_to_win,  char blank_char);
	bool someone_won_left_diagonally(char** board, int num_rows, int num_cols, int number_of_pieces_to_win,  char blank_char);
	bool someone_won_right_diagonally(char** board, int num_rows, int num_cols, int number_of_pieces_to_win, char blank_char);
	bool tie(char** board, int num_rows, int num_cols, int number_of_pieces_to_win, char blank_char);

#endif