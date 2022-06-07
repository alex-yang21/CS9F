#include "positions.h"
#include <iostream>
#include <cmath>
using namespace std;

/**
 * You define the GetPositions function.
 * It should read legal cat and mouse positions from the user
 * and return the position values in its two arguments.
 */

void GetPositions(Position cat_position, Position mouse_position)
{
    // TODO: Your code here
    // take in input from the user for the mouse (just angle since it has a 1m radius) and cat (angle and radius from statue)
    float cat_angle;
    float cat_radius;
    float mouse_angle;

    std::cout << "Input cat angle: ";
    std::cin >> cat_angle;

    std::cout << "\n" << "Input cat radius: ";
    std::cin >> cat_radius;

    std::cout << "\n" << "Input mouse angle: ";
    std::cin >> mouse_angle;
    std::cout <<"\n";

    // set the private attributes of the Position objects
    cat_position = Position(cat_radius, cat_angle); // constructor or setter needed here?
    mouse_position = Position(1, mouse_angle); // mouse radius always 1
}

/**
 * You define the RunChase function.
 * Given initialized cat and mouse positions,
 * it should simulate the cat chasing the mouse, printing the
 * result of each movement of cat and mouse.  Either the cat will
 * catch the mouse, or 30 time units will go by and the cat will
 * give up.
 */
void RunChase(Position cat_position, Position mouse_position)
{
    // TODO: Your code here
    int timer = 30;
    bool caught = false;

    while (timer > 0) {
      // 1. update cat position
      float prev_cat_angle = cat_position.myAngleInRadians; // not sure if this is legal since is private?
      if (cat_position.Sees(mouse_position)) { // if cat can see mouse, cat moves one meter towards statue
        cat_position.IncrementPosition(-1, 0);
      } else { // if not, cat circles 1.25 meters counterclockwise
        /* When the cat circles distance d around the statue, its radius does not change,
           and the change in its angle can be calculated from the relationship d = angle * radius */
        float angle_change = 1.25 / cat_position.myRadius;
        cat_position.IncrementPosition(0, angle_change);
      }

      // 2. check if cat can eat mouse
      /* The cat catches the mouse when it (the cat) moves past the mouse while at the base of the statue,
         i.e. when the cat radius is 1.0 and the mouse angle lies between the old cat angle and the new cat angle.
         An angle B is between angles A and C in the following circumstances (both):
           - cos (B - A) > cos (C - A)
           - cos (C - B) > cos (C - A) (angles in radian)
         The difference C - A is assumed to be less than 90°, or π/2 radians. */
      float new_cat_angle = cat_position.myAngleInRadians;
      float mouse_angle = mouse_position.myAngleInRadians;
      if (cat_position.IsAtStatue() && cos(mouse_angle - old_cat_angle) > cos(new_cat_angle - old_cat_angle) && cos(new_cat_angle - mouse_angle) > cos(new_cat_angle - old_cat_angle)) {
        std::cout << "Cat catches mouse on turn " << timer << endl;
        caught = true;
        break;
      }

      // 3. update mouse position one meter counterclockwise
      mouse_position.IncrementPosition(0, 1) // change and radius both 1

      // 4. decrement time and print positions
      std::cout << "Cat position: ";
      cat_position.Print();

      std::cout << "Mouse position: ";
      mouse_position.Print();

      timer -= 1;
    }

    // cat gives up
    if (!caught) {
      std::cout << "Cat gives up.";
    }
}

int main()
{
    Position cat, mouse;
    GetPositions(cat, mouse);
    RunChase(cat, mouse);

    return 0;
}
