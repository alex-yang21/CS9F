#ifndef SORTEDLIST_H
#define SORTEDLIST_H

#include <iostream>
#include <cassert>
using namespace std; // added

template <class NODETYPE>
class SortedList;
template <class NODETYPE>
class SortedListIterator;
template <class NODETYPE>

class ListNode
{
    friend class SortedList<NODETYPE>;
    friend class SortedListIterator<NODETYPE>;

public:
    ListNode(const NODETYPE& value);
    NODETYPE Info();

private:
    NODETYPE myInfo;
    ListNode* myNext;
};

template <class NODETYPE>
ListNode<NODETYPE>::ListNode(const NODETYPE& value)
{
    myInfo = value;
    myNext = 0;
}

template <class NODETYPE>
NODETYPE ListNode<NODETYPE>::Info()
{
    return myInfo;
}

template <class NODETYPE>
class SortedList
{
    friend class SortedListIterator<NODETYPE>;
public:
    SortedList();
    ~SortedList();
    SortedList(const SortedList<NODETYPE>& list);
    void Insert(const NODETYPE& value);
    bool IsEmpty();
    SortedList<NODETYPE>& operator=(const SortedList<NODETYPE>& list);

private:
    ListNode<NODETYPE>* myFirst;
};

template <class NODETYPE>
SortedList<NODETYPE>::SortedList() 
{
    // constructor
    myFirst = 0;
}

template <class NODETYPE>
SortedList<NODETYPE>::~SortedList()
{
    // destructor
    if (!IsEmpty())
    {
        cerr << "*** in destructor, destroying: ";
        ListNode<NODETYPE>* current = myFirst;
        ListNode<NODETYPE>* temp;
        while (current != 0)
        {
            cerr << " " << current->myInfo;
            temp = current;
            current = current->myNext;
            delete temp;
        }
        cerr << endl;
    }
}
template <class NODETYPE>
SortedList<NODETYPE>::SortedList(const SortedList<NODETYPE>& list)
{
    // copy constructor
    cerr << "*** in copy constructor" << endl;
    ListNode<NODETYPE>* listCurrent = list.myFirst;
    ListNode<NODETYPE>* newCurrent = 0;
    while (listCurrent != 0)
    {
        ListNode<NODETYPE>* temp = new ListNode<NODETYPE>(listCurrent->Info());
        if (newCurrent == 0)
        {
            myFirst = temp;
            newCurrent = myFirst;
        }
        else
        {
            newCurrent->myNext = temp;
            newCurrent = temp;
        }
        listCurrent = listCurrent->myNext;
    }
}

template <class NODETYPE>
void SortedList<NODETYPE>::Insert(const NODETYPE& value)
{
    // Insert
    ListNode<NODETYPE>* toInsert = new ListNode<NODETYPE>(value);
    if (IsEmpty())
    {
        myFirst = toInsert;
    }
    else if (value < myFirst->Info())
    {
        toInsert->myNext = myFirst;
        myFirst = toInsert;
    }
    else
    {
        ListNode<NODETYPE>* temp = myFirst;
        for (temp = myFirst; temp->myNext != 0 && temp->myNext->Info() < value; temp = temp->myNext)
        {
        }
        toInsert->myNext = temp->myNext;
        temp->myNext = toInsert;
    }
}

template <class NODETYPE>
bool SortedList<NODETYPE>::IsEmpty()
{
    // IsEmpty
    return myFirst == 0;
}

template <class NODETYPE>
SortedList<NODETYPE>& SortedList<NODETYPE>::operator=(const SortedList<NODETYPE>& list) {
    /*
    Your function should first delete all the ListNode objects in the variable being assigned to (the left hand side of the =).
    It should then construct a copy of the list on the right hand side of the = to assign to the variable on the left hand side.
    The default assignment operator is a shallow copy, and here we are making a deep copy by dynamically allocating new data.
    */

    // check that we are not self-assigning
    if (this == &list) {
        cout << "*** Assigning a list to itself." << endl;
        return *this;
    }

    // delete old nodes if not empty
    if (!IsEmpty()) {
        cerr << "*** in operator=, destroying: ";
        ListNode<NODETYPE>* currNode = myFirst;
        while (currNode) {
            cerr << " " << currNode->myInfo;

            // preserve current node to be deleted
            ListNode<NODETYPE>* deleteNode = currNode;

            // move to next node
            currNode = currNode->myNext;

            // delete current node
            delete deleteNode;
        }
        cerr << endl;
    }

    // create deep copy

    // set the "this" SortedList back to an empty list, should already be empty after deleting
    myFirst = 0;

    // insert new nodes into our this list
    ListNode<NODETYPE>* currNode1 = list.myFirst;
    while (currNode1) {
        // we can use Insert here because it will maintain sorted order, also dynamically allocates new memory
        this->Insert(currNode1->myInfo);
        currNode1 = currNode1->myNext;
    }

    return *this;
}

template <class NODETYPE>
class SortedListIterator
{
    public:
        SortedListIterator<NODETYPE>(SortedList<NODETYPE>& list);
        bool MoreRemain();
        NODETYPE Next();

    private:
        ListNode<NODETYPE>* currNode;
};

// sorted list constructor, create an iterator of an iterable sortedlist
template <class NODETYPE>
SortedListIterator<NODETYPE>::SortedListIterator(SortedList<NODETYPE>& list) : currNode(list.myFirst)
{
}

template <class NODETYPE>
bool SortedListIterator<NODETYPE>::MoreRemain() {
    if (currNode == 0) {
        return false;
    } else {
        return true;
    }
}

template <class NODETYPE>
NODETYPE SortedListIterator<NODETYPE>::Next() {
    if (!MoreRemain()) {
        return 0;
    }
    // return the current node's value and move on to the next node
    NODETYPE val = currNode->myInfo;
    currNode = currNode->myNext;
    return val;
}

#endif
