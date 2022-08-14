#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define M 3
#define N 3

class Board 
{
public:
    Board() {
        // vector<vector<char> > board(M, vector<char>(N, '.'));

		board.resize(M);
		for (int i = 0; i < N; i++) {
			board[i] = vector<char>(N);
			for (int j = 0; j < N; j++) {
				board[i][j] = '.';
			}
		}
    }

    void SetCell(int player, int row, int col, char c) {
        if (player != 0) {
            board[M-1-row][N-1-col] = c;
        } else {
            board[row][col] = c;
        }
    }

    void Print(int player) {
        if (player != 0) { 
            // print the board backward
            for (int i=M-1; i >= 0; i--) {
                for (int j=N-1; j >= 0; j--) {
                    cout << board[i][j];
                    if (j != 0) {
                        cout << " ";
                    }
                }
                cout << endl;
            }
        } else {
            // print the board forward
            for (int i=0; i < M; i++) {
                for (int j=0; j < N; j++) {
                    cout << board[i][j];
                    if (j != M-1) {
                        cout << " ";
                    }
                }
                cout << endl;
            }
        }
    }

private:
    vector<vector<char> > board;
};

int main() {
    Board board;

	board.Print(0);
    cout << endl;
	board.Print(1);
    cout << endl;

	board.SetCell(0, 0, 0, 'X');
	board.SetCell(1, 0, 0, 'O');

	board.Print(0);
    cout << endl;
	board.Print(1);
    cout << endl;

	board.SetCell(0, 1, 2, 'X');
	board.SetCell(1, 0, 1, 'O');

	board.Print(0);
    cout << endl;
	board.Print(1);
    cout << endl;

	return 0;
}