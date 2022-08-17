#ifndef ANIMALS_H
#define ANIMALS_H

#include <string>
#include "park.h"

class Person: public Animal 
{
    public:
        Person(string s, Position p);
        bool Chase();

    private:
        float myAngularDistChange; // move clockwise 2 meters
};

class Cat: public Animal
{
    public:
        Cat(string s, Position p);
        bool Chase();

    private:
        float myAngularDistChange; // move counterclockwise 1.25 meters
        float myRadiusDistChange; // move 1 meter closer if sees target
};

class Mouse: public Animal
{
    public:
        Mouse(string s, Position p);
        bool Chase();

    private:
        float myAngularDistChange; // move 1.25 meters counterclockwise
};

#endif