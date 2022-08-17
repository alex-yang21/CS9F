#include <string>
#include "park.h"

#ifndef PERSON_H
#define PERSON_H
class Person: public Animal 
{
    public:
        Person(string s, Position p);
        bool Chase();

    private:
        double myAngularDistChange; // move clockwise 2 meters
};
#endif

#ifndef CAT_H
#define CAT_H
class Cat: public Animal
{
    public:
        Cat(string s, Position p);
        bool Chase();
        void SetTarget(Animal* target);

    private:
        double myAngularDistChange; // move counterclockwise 1.25 meters
        double myRadiusDistChange; // move 1 meter closer if sees target
};
#endif

#ifndef MOUSE_H
#define MOUSE_H
class Mouse: public Animal
{
    public:
        Mouse(string s, Position p);
        bool Chase();

    private:
        double myAngularDistChange; // move 1.25 meters counterclockwise
};

#endif