#include <vector>
#include <string>
using namespace std;

struct item {
    string itemName;
    int amount;
};

class Inventory
{
public:
    Inventory();

    void Update(string itemName, int amount);

    void ListByName();

    void ListByQuantity();

    void PrintItems();

private:
    // TODO: Your code here
    // we want to maintain a vector of structs
    vector<item> items;
};
