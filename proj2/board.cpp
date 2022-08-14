#include "board.h"
#include <iostream>
using namespace std;

#define M 19
#define N 19

Board::Board() {
    char initial = '.';
    vector<vector<char>> board(M, vector<char>(N, initial));
}

void Board::SetCell(int player, int row, int col, char c) {
    if (player != orientation) { // rotate 180 degrees
        rotate(board);
        rotate(board);
    } 
    board[row][col] = c;
    orientation = player; // we store the board's orientation based on the last call
}

void Board::Print(int player) {
    if (player != orientation) { // rotate 180 degrees
        rotate(board);
        rotate(board);
    } 
    // print the board
    for (int i=0; i < M; i++) {
        for (int j=0; j < N; j++) {
            cout << board[i][j];
            if (j != N-1) {
                cout << " ";
            }
        }
        cout << endl;
    }
    orientation = player;
}

void rotate(vector<vector<char>>& board) {
    // transpose matrix
    for (int i=0; i < 19; i++) {
        for (int j=0; j < 19; j++) {
            swap(board[i][j], board[j][i]);
        }
    }

    // reverse columns
    int i, j ,k;
    for (i=0; i < 19 ;i++) {
        k = 18;
        for (j=0; j < 9; j++) {
            swap(board[i][j],board[i][k--]);
        }
    }
}