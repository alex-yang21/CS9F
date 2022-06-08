#include "positions.h"
#include "positions.cpp"
#include <iostream>
#include <cmath>
using namespace std;

/* Convert from degrees to radians */
float toRadians(float angleInDegrees) {
  if (angleInDegrees < 0) {
    angleInDegrees += 360;
  }
  return angleInDegrees * (M_PI / 180);
}

/**
 * You define the GetPositions function.
 * It should read legal cat and mouse positions from the user
 * and return the position values in its two arguments.
 */

void GetPositions(Position &cat_position, Position &mouse_position)
{
    // TODO: Your code here
    // take in input from the user for the mouse (just angle since it has a 1m radius) and cat (angle and radius from statue)
    float cat_radius;
    float cat_angle;
    float mouse_angle;

    cout << "\n" << "Input cat radius: ";
    cin >> cat_radius;

    cout << "Input cat angle: ";
    cin >> cat_angle;

    cout << "\n" << "Input mouse angle: ";
    cin >> mouse_angle;
    cout <<"\n";

    // convert to to radians
    cat_angle = toRadians(cat_angle);
    mouse_angle = toRadians(mouse_angle);

    // set the private attributes of the Position objects
    cat_position.SetAbsolutePosition(cat_radius, cat_angle);
    mouse_position.SetAbsolutePosition(1, mouse_angle); // mouse radius always 1
}

/**
 * You define the RunChase function.
 * Given initialized cat and mouse positions,
 * it should simulate the cat chasing the mouse, printing the
 * result of each movement of cat and mouse.  Either the cat will
 * catch the mouse, or 30 time units will go by and the cat will
 * give up.
 */
void RunChase(Position &cat_position, Position &mouse_position) // we want the pointer to the position so we can keep a copy of the old position
{
    // TODO: Your code here
    int timer = 0;
    bool caught = false;

    Position old_cat_position = cat_position;

    while (timer < 30) {
      // 1. update cat position
      if (cat_position.Sees(mouse_position)) { // if cat can see mouse, cat moves one meter towards statue
        cat_position.IncrementPosition(-1, 0);
      } else { // if not, cat circles 1.25 meters counterclockwise
        cat_position.IncrementPosition(0, 1.25);
      }

      // 2. check if cat can eat mouse
      /* The cat catches the mouse when it (the cat) moves past the mouse while at the base of the statue,
         i.e. when the cat radius is 1.0 and the mouse angle lies between the old cat angle and the new cat angle. */
      if (mouse_position.IsBetween(old_cat_position, cat_position)) {
        cout << "Cat catches mouse on turn " << timer+1 << endl;
        caught = true;
        break;
      }

      // 3. update mouse position one meter counterclockwise
      mouse_position.IncrementPosition(0, 1);

      // 4. increment time and print positions, reassign old_cat_position
      cout << "Cat position: ";
      cat_position.Print();

      cout << "Mouse position: ";
      mouse_position.Print();

      timer += 1;
      old_cat_position = cat_position;
    }

    // cat gives up
    if (!caught) {
      cout << "Cat gives up.";
    }
}

int main()
{
    Position cat, mouse;
    GetPositions(cat, mouse);
    RunChase(cat, mouse);

    return 0;
}
