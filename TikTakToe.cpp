﻿#include <iostream>
#include <cctype>
using std::cout;
using std::cin;

char board[3][3];
enum { EMPTY = ' ', CROSS = 'X', ZERO = '0' };

char player_char;
char computer_char;

void init() {
	setlocale(LC_ALL, "ru_RU");
	do {
		cout << "Сделайте свой выбор [ Х | 0 ]: ";
		cin >> player_char; 
		player_char = toupper(player_char); // 'x' - > 'X'
	} while (player_char != 'X' && player_char != '0');

	computer_char = (player_char == 'X' ? '0' : 'X');

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			board[i][j] = EMPTY;
		}
	}

}

bool is_full() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[i][j] == EMPTY) {
				return false;
			}
		}
	}
	return true;
}

bool is_game_over() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[i][0] != EMPTY && board[i][0] == board[i][1] && board[i][0] == board[i][2])
				return true;
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[0][i] != EMPTY && board[0][i] == board[1][i] && board[0][i] == board[2][i])
				return true;
		}
	}
	if (board[0][0] != EMPTY && board[0][0] == board[1][1] && board[0][0] == board[2][2])
		return true;
	if (board[0][2] != EMPTY && board[0][2] == board[1][1] && board[0][2] == board[2][0])
		return true;

	return is_full();
}

void get_coords() {
	int row, col;
	do {
		cout << "Введите координаты X: [1; 3]  Y: [1; 3]: ";
		cin >> col >> row;
		col--;
		row--;
	} while (col < 0 || col> 2 || row < 0 || row > 2 || board[row][col] != EMPTY);
}

void make_move() {

}

void print() {
	for (int i = 0; i < 3; i++) {
		cout << board[i][0];
		for (int j = 0; j < 2; j++) {
			cout << "  |" << board[i][j];
		}
		cout << "\n";
		if (i == 2) {
			break;
		}
		for (int j = 0; j < 3; j++) {
			cout << "---" << ((j == 2) ? '\n' : '+');
		}
	}
	cout << "\n";
}