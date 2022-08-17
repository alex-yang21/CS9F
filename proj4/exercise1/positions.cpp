#include "positions.h"
#include <cmath>
#include <iostream>
using namespace std;

// constructor 1
Position::Position()
: myRadius(1), myAngleInRadians(0)
{
  // default values if no parameters passed in
}

// constructor 2
Position::Position(float r)
: myRadius(r), myAngleInRadians(0)
{
  // assign radius, default angle is 0
}

// constructor 3
Position::Position(float r, float thetaInRadians)
{
  // assign both radius and angle
  myRadius = r;
  myAngleInRadians = fmodf(thetaInRadians, (float) (2 * M_PI));
}

// beginning of member functions
void Position::SetAbsolutePosition(float r, float thetaInRadians) {
  myRadius = r;
  myAngleInRadians = thetaInRadians;
}

void Position::IncrementPosition(float rChange, float angularDistChange) {
  if (rChange != 0 && angularDistChange != 0) {
    std::cout << "At least one argument must be 0." << endl;
    return;
  }

  // we need to make sure the radius is never less than 1, order of change does not matter since both will not be changed at once
  myRadius += rChange;
  if (myRadius < 1) {
    myRadius = 1;
  }

  /* When the cat circles distance d around the statue, its radius does not change,
     and the change in its angle can be calculated from the relationship d = angle * radius
  */
  float angle_change = angularDistChange / myRadius;
  myAngleInRadians += angle_change;
  myAngleInRadians = fmodf(myAngleInRadians, (float) (2 * M_PI));  // we need to make sure the angles wrap around
}

void Position::Print() {
  std::cout << "Radius: " << myRadius << ", Angle: " << myAngleInRadians << endl;
}

// we will call this on the mouse's position with the cat's position
bool Position::Sees(Position pos) {

  if (!pos.IsAtStatue()) { // argument position (mouse) must be at the statue
    return false;
  }

  // cat sees mouse if (cat radius) * cos (cat angle - mouse angle) >= 1.0 (angles in radian)
  bool cat_sees = myRadius * cos(myAngleInRadians - pos.myAngleInRadians) >= 1.0 ? true : false;
  return cat_sees;
}

bool Position::IsAtStatue() {
  if (myRadius == 1) {
    return true;
  } else {
    return false;
  }
}

bool Position::IsBetween(Position pos1, Position pos2) { // pos1 is old, pos2 is current
  float a = pos1.myAngleInRadians;
  float b = myAngleInRadians;
  float c = pos2.myAngleInRadians;

  float r1 = pos1.myRadius;
  float r2 = pos2.myRadius;

  /*
    Precondition: the counterclockwise difference between the first and second argument positions
                  is less than pi radians, and the radii of all the positions are the same.
    An angle B is between angles A and C in the following circumstances (both):
       - cos (B - A) > cos (C - A)
       - cos (C - B) > cos (C - A) (angles in radian)
     The difference C - A is assumed to be less than 90°, or π/2 radians. */

  if (c-a <= M_PI && myRadius == r1 == r2 && cos(b - a) > cos(c - a) && cos(c - b) > cos(c - a)) {
    return true;
  } else {
    return false;
  }
}

// NEW STUFF, operator overloading, private func

// Compare two positions.
bool Position::operator==(Position coords) {
  if (myAngleInRadians == coords.myAngleInRadians && myRadius == coords.myRadius) {
    return true;
  } else {
    return false;
  }
}