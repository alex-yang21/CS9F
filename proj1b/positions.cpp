// TODO: Your code here
#include <iostream>
#include <positions.h>

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
    cout << "At least one argument must be 0.";
    return;
  }
  myRadius += rChange;
  myAngleInRadians += angularDistChange;
}

void Position::Print() const { // const means it can't modify anything
  cout << "Radius: " << myRadius << "\n";
  cout << "Angle: " << myAngleInRadians << "\n";
}

bool Position::Sees(Position pos) const {

  if (!pos.IsAtStatue()) { // argument position must be at the statue
    return false;
  }



}

bool Position::IsAtStatue() const {
  if (myRadius <= 1) {
    return true;
  } else {
    return false;
  }
}

bool Position::IsBetween(Position pos1, Position pos2) const {

}
