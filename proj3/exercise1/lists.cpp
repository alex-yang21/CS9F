#include "lists.h"
#include <iostream>
#include <cassert>
using namespace std;

/**
 * Delete the node and all nodes accessible through it.
 * Precondition: this != 0.
 */
ListNode::~ListNode()
{
    cout << "Deleting node with value " << myValue << endl;

    // recursively delete
    if (this == 0) {
        return;
    }
    
    delete this->myNext;

    // this version is buggy
    // for (ListNode* p = this; p; p = p->myNext)
    // {
    //     delete p;
    // }
}

/**
 * Print the list.
 */
void ListNode::print() const
{
    for (const ListNode* list = this; list; list = list->rest())
    {
        cout << list->first() << " ";
    }
    cout << endl;
}
