#include "amoebas.h"
#include <iostream>

using namespace std;

string indent = "    ";

// An amoeba is born, named s
Amoeba::Amoeba(string s)
{
    myName = s;
    myParent = 0;
    myOlderSibling = 0;
    myOldestChild = 0;
    myYoungestChild = 0;
}

// Access functions
string Amoeba::Name()
{
    return myName;
}

Amoeba* Amoeba::Parent()
{
    return myParent;
}

void Amoeba::AddChild(Amoeba* newChild)
{
    // make child point to parent
    newChild->myParent = this;

    // check for parent having other children
    Amoeba* otherSibling = myYoungestChild;
    if (!otherSibling)
    {
        // the new amoeba is an only child
        myYoungestChild = newChild;   // make the parent's child
        myOldestChild = newChild;     // ptrs point to the new one
        newChild->myOlderSibling = 0; // no older sibling
    }
    else
    {
        // there are other kids; make this one the youngest
        myYoungestChild = newChild;              // no younger siblings,
        newChild->myOlderSibling = otherSibling; // but new kid now
    }                                            // has older siblings.
}

void Amoeba::PrintChildren() {
    Amoeba* currChild = myYoungestChild;
    while (currChild) {
        cout << currChild->myName << endl;
        currChild = currChild->myOlderSibling;
    }
}

void Amoeba::PrintGrandchildren() {
    Amoeba* currChild = myYoungestChild;
    while (currChild) {
        currChild->PrintChildren();
        currChild = currChild->myOlderSibling;
    }
}

void Amoeba::DFS(int numIndents) {
    if (this == 0) { // base case, end recursion
        return;
    }

    // print name
    for (int i = 0; i < numIndents; i++) {
        cout << indent;
    }
    cout << myName << endl;

    // if there are children, recurse on them
    Amoeba* currChild = myYoungestChild;
    while (currChild) {
        currChild->DFS(numIndents+1);
        currChild = currChild->myOlderSibling;
    }
}

void Amoeba::PrintDescendents() {
    // we do a DFS on all children
    Amoeba* currChild = myYoungestChild;
    while (currChild) {
        currChild->DFS(0);
        currChild = currChild->myOlderSibling;
    }
}

