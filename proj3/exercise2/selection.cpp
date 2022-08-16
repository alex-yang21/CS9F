// #include "CLLNode.h"
#include <iostream>
#include "CLLNode.cpp"
using namespace std;

int main()
{
    const int N = 8;
    const int K = 2;

    CLLNode* list = new CLLNode(1); // line modified
    for (int j = 2; j <= N; j++)
    {
        CLLNode* newGuy = new CLLNode(j);
        // TODO: Your code here
        // insert nodes here
        list->insert(newGuy);
    }
    list->print();

    while (!list->lengthIsOne())
    {
        for (int j = 0; j < K; j++)
        {
            list = list->next();
        }

        // TODO: Your code here
        // play game, remove player and pass to next player using remove()
        list = list->remove();
    }

    cout << "Only one person remains: ";
    list->print();

    return 0;
}
