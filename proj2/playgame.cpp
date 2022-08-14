#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include "board.cpp"
using namespace std;

// global board
Board board;

void play(istream&);
void InterpretSet(istream&);
void InterpretPrint(istream&);

/**
 * Driver Function
 */
int main()
{
    play(cin);
    return 0;
}

void play(istream& cmds)
{
    string line, lineInWord;

    while (getline(cmds, line))
    {
        istringstream lineIn(line.c_str()); // this makes a copy of line as a string stream, requires C string

        if (!(lineIn >> lineInWord))
        {
            cerr << "No words given." << endl;
        }
        else if (lineInWord == "set")
        {
            InterpretSet(lineIn);
        }
        else if (lineInWord == "print")
        {
            InterpretPrint(lineIn);
        }
        else
        {
            cerr << "Unrecognizable command word." << endl;
        }
    }
}

void InterpretSet(istream& cmd) {
    int player;
    int row;
    int col;
    char c;

    cmd >> player >> row >> col >> c; // no error check
    board.SetCell(player, row, col, c);
}

void InterpretPrint(istream& cmd) {
    int player;
    cmd >> player;
    board.Print(player);
}
