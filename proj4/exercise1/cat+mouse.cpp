#include <iostream>
using namespace std;

#include "park.h"

void RunChase(Scene allAnimals)
{
    for (int time = 1; time <= 30; time++)
    {
        for (int k = 0; k < allAnimals.Length(); k++)
        {
            if (allAnimals[k]->Chase())
            {
                cout << "Chase ended at turn: " << time+1 << endl; // my line
                return;
            }
        }
    }
    cout << "Chase took too long; all animals drifted away." << endl;
}

int main()
{
    Scene allAnimals;
    RunChase(allAnimals);
    return 0;
}
