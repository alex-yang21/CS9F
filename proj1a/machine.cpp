// TODO: Your code here
#include <stdio.h>
#include <iostream>

// Input to the program will be integers, submitted one per line. Input should be handled as follows:
// - a nonzero value should be added into a subtotal;
// - a zero value should cause the subtotal to be printed and reset to zero;
// - two consecutive zeroes should cause the total of all values input to be printed and the program to be terminated.

int main() {
  int input;
  int prev = -1;
  int running_sum = 0;
  int curr_sum = 0;

  while (true) { // run program until we encounter two 0s
    std::cin >> input;

    if (input == 0 && prev == 0) {
      std::cout << "Total " << running_sum << "\n";
      break;
    } else if (input == 0) {
      std::cout << "Subtotal " << curr_sum << "\n";
      curr_sum = 0;
    } else {
      running_sum += input;
      curr_sum += input;
    }
    prev = input;
  }
  return 0;
}
