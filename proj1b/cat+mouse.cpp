#include "positions.h"
#include <iostream>
#include <cmath>
using namespace std;

/**
 * You define the GetPositions function.
 * It should read legal cat and mouse positions from the user
 * and return the position values in its two arguments.
 */

/* Notes from specs
  - each second is one time step, if more than 30 timesteps, then cat fails
  - the cat moves first
  - the cat's radius can never be less than 1 (it cannot move into the base)
  - It should print the position of the cat and mouse after each move,
    followed by the results of the chase (either the mouse becomes lunch, or the cat gives up after 30 minutes)
  - The cat sees the mouse if (cat radius) * cos (cat angle - mouse angle) >= 1.0 (angles in radian)
  - When the cat circles distance d around the statue, its radius does not change,
    and the change in its angle can be calculated from the relationship d = angle * radius (angles in radian)
  - The cat catches the mouse when it (the cat) moves past the mouse while at the base of the statue,
    i.e. when the cat radius is 1.0 and the mouse angle lies between the old cat angle and the new cat angle.
    An angle B is between angles A and C in the following circumstances (both):
      - cos (B - A) > cos (C - A)
      - cos (C - B) > cos (C - A) (angles in radian)
    The difference C - A is assumed to be less than 90°, or π/2 radians.
*/

// M_PI is pi

void GetPositions(Position cat_position, Position mouse_position)
{
    // TODO: Your code here
    // take in input from the user for the mouse (just angle since it has a 1m radius) and cat (angle and radius from statue)
    float cat_angle;
    float cat_radius;
    float mouse_angle;



    // set the private attributes of the Position objects

}

/**
 * You define the RunChase function.
 * Given initialized cat and mouse positions,
 * it should simulate the cat chasing the mouse, printing the
 * result of each movement of cat and mouse.  Either the cat will
 * catch the mouse, or 30 time units will go by and the cat will
 * give up.
 */
void RunChase(/* TODO: Your code here */)
{
    // TODO: Your code here
    int timer = 30;

    while (timer > 0) {
      // check if cat can eat mouse

      // update cat and mouse positions
      timer -= 1;
    }

    // cat gives up
}

int main()
{
    Position cat, mouse;
    GetPositions(cat, mouse);
    RunChase(cat, mouse);

    return 0;
}
