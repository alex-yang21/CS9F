#include "CLLNode.h"
#include <iostream>
#include <cassert>
using namespace std;

/**
 * Return the successor of the given node.
 * Precondition: this != 0.
 */
CLLNode* CLLNode::next()
{
    assert(this != 0);
    assert(myPrevious != 0); // Consistency checks on circular list
    assert(myNext != 0);
    return myNext;
}

/**
 * Return the predecessor of the given node.
 * Precondition: this != 0.
 */
CLLNode* CLLNode::previous()
{
    assert(this != 0);
    assert(myPrevious != 0); // Consistency checks on circular list
    assert(myNext != 0);
    return myPrevious;
}

/**
 * Insert the node pointed to by ptr at the head of list and return a pointer
 * to new element.
 */
CLLNode* CLLNode::insert(CLLNode* ptr)
{
    // TODO: You fill this in
    // save the current node's previous's next to the new node
    // set new node's previous to be the original previous
    // set new node's next to be current node
    // set current node's previous as the new node
    this->myPrevious->myNext = ptr;
    ptr->myPrevious = this->myPrevious;
    ptr->myNext = this;
    this->myPrevious = ptr;

    return ptr;
}

/**
 * Delete the first node from the list and return pointer to its successor, or
 * 0 if there was only one element in the list to start with.
 * Precondition: this != 0.
 */
CLLNode* CLLNode::remove()
{
    // TODO: You fill this in
    assert(this != 0);

    // check if there is only one element in the list to start with
    if (this->lengthIsOne()) {
        delete this;
        return 0;
    }

    // set previous's next to be current next
    this->myPrevious->myNext = this->myNext;

    // set next's previous to be current previous
    this->myNext->myPrevious = this->myPrevious;

    // save next pointer
    CLLNode* next = this->myNext;

    // delete current node
    delete this;

    return next;
}

/**
 * Print the list.
 */
void CLLNode::print() const
{
    if (this != 0)
    {
        const CLLNode* temp = this;
        do
        {
            cout << temp->myValue << " ";
            temp = temp->myNext;
        } while (temp != this);
    }
    cout << endl;
}

/**
 * Return true if the list contains exactly 1 element.
 */
bool CLLNode::lengthIsOne() const
{
    if (this == 0)
    {
        return false;
    }
    else if (this == myPrevious)
    {
        assert(myNext == myPrevious); // Consistency check on 1-elem list
        return true;
    }
    else if (this == myNext)
    {
        assert(false); // Failed consistency check!
    }
    else
    {
        return false;
    }
}
