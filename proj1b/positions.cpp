// TODO: Your code here
#include <iostream>
#include "positions.h"
#include <cmath>
using namespace std;

// constructor 1
Position::Position()
: myRadius(1), myAngleInRadians(0))
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
: myRadius(r), myAngleInRadians(thetaInRadians)
{
  // assign both radius and angle
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

  // we need to make sure the radius is never less than 1
  myRadius += rChange;
  if (myRadius < 1) {
    myRadius = 1;
  }

  // we need to make sure the angles wrap around
  myAngleInRadians += angularDistChange;
  myAngleInRadians %= (2 * M_PI);
}

void Position::Print() const { // const means it can't modify anything
  std::cout << "Radius: " << myRadius << ", Angle: " << myAngleInRadians << endl;
}

// we will call this on the mouse's position with the cat's position
bool Position::Sees(Position pos) const {

  if (!pos.IsAtStatue()) { // argument position (mouse) must be at the statue
    return false;
  }

  // cat sees mouse if (cat radius) * cos (cat angle - mouse angle) >= 1.0 (angles in radian)
  bool cat_sees;
  cat_sees = myRadius * cos(myAngleInRadians - pos.myAngleInRadians) >= 1.0 ? true : false;

  // if the statue position is between the cat and the mouse, then the cat can't see
  Position statuePosition = Position(0, 0);
  if (myAngleInRadians == 0 && !statuePosition.IsBetween(pos, *this)) {
    return false;
  } else {
    return cat_sees;
  }
}

bool Position::IsAtStatue() const {
  if (myRadius == 1) {
    return true;
  } else {
    return false;
  }
}

bool Position::IsBetween(Position pos1, Position pos2) const {
  float angle1 = pos1.myAngleInRadians;
  float angle2 = pos2.myAngleInRadians;

  float radius1 = pos1.myRadius;
  float radius2 = pos2.myRadius;

  if (angle1 - angle2 < M_PI && radius1 == radius2) {
    return true;
  } else {
    return false;
  }
}
