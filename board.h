#ifndef BOARD_H
	#define BOARD_H
	#include <stdbool.h>
	char** create_empty_board(int num_rows, int num_cols, char blank_char);
	void print_board(char** board, int num_rows, int num_cols);
	void delete_board(char** board, int num_rows);
	bool move_is_on_board(int num_rows, int num_cols, int col);
	bool is_between(int value, int min_val, int max_val);
	void place_piece(char piece, char** board, int col, int num_rows, int num_cols, char blank_char);
	bool all_same(char* values, int len);
	char* get_column(char** board, int dimensions, int col);

#endif