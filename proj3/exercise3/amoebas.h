#ifndef AMOEBA_H
#define AMOEBA_H

#include <string>

class Amoeba
{
public:
    Amoeba(std::string);           // birth of an amoeba
    std::string Name();            // returns your name
    Amoeba* Parent();              // returns your parent
    void AddChild(Amoeba*);        // add a baby amoeba to the family
    void PrintChildren();          // prints names of children
    void PrintGrandchildren();     // prints names of grandchildren
    void PrintDescendents();       // prints names of all descendents in tree order
private:
    std::string myName;            // this amoeba's name
    Amoeba* myParent;              // good old mom (or is it dad?)
    Amoeba* myOlderSibling;        // the next older brother/sister
    Amoeba* myYoungestChild;       // the youngest kid
    Amoeba* myOldestChild;         // the oldest kid
    void DFS(int numIndents);                    // helper function for PrintDescendents
};

#endif
