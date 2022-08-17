#include <vector>
#include <string>
#include <iostream>
using namespace std;

#include "animals.h"

// person constructor, calls Animal constructor, target automatically set to 0
Person::Person(string s, Position p) : Animal{s, p}, myAngularDistChange{-2.0}
{
}

// Person chase()
bool Person::Chase() {
    return true; // TO-DO!, modify the position, use myAngularDistChange to IncrementPosition
}

// cat constructor
Cat::Cat(string s, Position p) : Animal{s, p}, myAngularDistChange{1.25}, myRadiusDistChange{1.0}
{
}

// cat chase
bool Cat::Chase() {
    return true; // TO-DO!!
}

// cat set target
void Cat::SetTarget(Animal* target) {
    myTarget = target;
}

// mouse constructor, calls Animal constructor, target automatically set to 0
Mouse::Mouse(string s, Position p) : Animal{s, p}, myAngularDistChange{1.0}
{
}

// mouse chase
bool Mouse::Chase() {
    return true; //TO-DO!!
}
