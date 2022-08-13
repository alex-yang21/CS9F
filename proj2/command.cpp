#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
using namespace std;

// Function Prototypes

void InterpretCommands(istream&);

void InterpretUpdate(istream&);

void InterpretList(istream&);

void InterpretBatch(istream&);

void InterpretQuit(istream&);

/**
 * Driver Function
 */
int main()
{
    InterpretCommands(cin);
    return 0;
}

/**
 * TODO: Write your function description here.
 */
void InterpretCommands(istream& cmds)
{
    string line, lineInWord;
    // TODO: Declare other variables here.

    while (getline(cmds, line)) // TODO: Get a line.
    {
        istringstream lineIn(line.c_str()); // this makes a copy of line as a string stream, requires C string

        if (!(lineIn >> lineInWord)) // TODO: Get the line's first word.
        {
            cerr << "No words given." << endl; // TODO: Do something if there weren't any words.
        }
        else if (lineInWord == "update")
        {
            InterpretUpdate(lineIn);
        }
        else if (lineInWord == "list")
        {
            InterpretList(lineIn);
        }
        else if (lineInWord == "batch")
        {
            InterpretBatch(lineIn);
        }
        else if (lineInWord == "quit")
        {
            InterpretQuit(lineIn);
        }
        else
        {
            cerr << "Unrecognizable command word." << endl;
        }
    }
}

void InterpretUpdate(istream& cmd) {
    string word;
    int num;

    if (!(cmd >> word >> num)) { // no other words given, error
        cerr << "Update command requires a corresponding word and number." << endl;
    }

    cout << "Update " << word << " " << num << endl; // temp place holder

    return;
}

void InterpretList(istream& cmd) {
    string word;

    if (!(cmd >> word)) {
        cerr << "List requires another command 'names' or 'quantities'." << endl;
    } else if (word == "names") {
        ;
    } else if (word == "quantities") {
        ;
    } else {
        cerr << "Unrecognizable command word for 'list'." << endl;
    }
    return;
}

void InterpretBatch(istream& cmd) {
    /* 
    For the batch command, do the following: read, recognize, and process commands from the specified file, 
    then (assuming that a quit command has not been read) resume reading commands from cin. 
    Assume that the file does not contain any batch commands.
    */ 
    string fileName;

    if (!(cmd >> fileName)) {
        cerr << "Batch requires the name of a file." << endl;
    }

    ifstream file; 
    file.open(fileName);
    InterpretCommands(file);
    file.close();

    return;
}

void InterpretQuit(istream& cmd) {
    string temp;
    if (cmd >> temp) {
        cerr << "Exit command should have no other arguments." << endl;
    }
    exit(0);
    return;
}