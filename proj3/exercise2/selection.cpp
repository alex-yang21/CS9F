#include "CLLNode.h"
#include <iostream>
using namespace std;

int main()
{
    const int N = 8;
    const int K = 2;

    CLLNode* list = 0;
    for (int j = N; j > 0; j--)
    {
        CLLNode* newGuy = new CLLNode(j);
        // TODO: Your code here
        // insert nodes here
        (*list).insert(newGuy);
    }
    list->print();

    while (!list->lengthIsOne())
    {
        for (int j = 0; j < K; j++)
        {
            list = list->next();
        }

        // TODO: Your code here
        // play game, remove player and pass to next player
        (*list).remove();
    }
    cout << "Only one person remains: ";
    list->print();

    return 0;
}
