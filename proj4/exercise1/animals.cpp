#include <vector>
#include <string>
#include <iostream>
using namespace std;

#include "animals.h"
#include "positions.h"

// person constructor, calls Animal constructor, target automatically set to 0
Person::Person(string s, Position p) : Animal{s, p}, myAngularDistChange{-2.0}
{
}

// Person chase()
bool Person::Chase() {
    assert(myTarget != 0);

    if (!myPos.Sees(myTarget->Pos())) { // person doesn't see target, move 2 m clockwise
        myPos.IncrementPosition(0, -2.0);
    } 

    return false; // person cannot stop the chase
}

// person set target, may not be needed
void Person::SetTarget(Animal* target) {
    myTarget = target;
}

// cat constructor
Cat::Cat(string s, Position p) : Animal{s, p}, myAngularDistChange{1.25}, myRadiusDistChange{1.0}
{
}

// cat chase
bool Cat::Chase() {
    assert(myTarget != 0);

    Position oldPos = myPos;
    
    // move cat
    if (myPos.Sees(myTarget->Pos())) { // see mouse, move closer 1 m
        myPos.IncrementPosition(1, 0);
    } else { // doesn't see mouse, move counterclockwise 1.25 m
        myPos.IncrementPosition(0, 1.25);
    }

    // check if cat just caught the mouse
    if (myTarget->Pos().IsBetween(oldPos, myPos)) {
        return true;
    } else {
        return false;
    }
}

// cat set target, may not be needed
void Cat::SetTarget(Animal* target) {
    myTarget = target;
}

// mouse constructor, calls Animal constructor, target automatically set to 0
Mouse::Mouse(string s, Position p) : Animal{s, p}, myAngularDistChange{1.0}
{
}

// mouse chase
bool Mouse::Chase() {
    myPos.IncrementPosition(0, 1.0);
    return false;
}
