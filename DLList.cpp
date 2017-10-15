//
//  DLList.cpp
//  DLList
//
//  Created by Philip Leblanc on 2017-10-13.
//  Copyright © 2017 Philip Leblanc. All rights reserved.
//

#include "DLList.h"
#include <iostream>
using namespace std;

DLList::DLList()
{
    head = nullptr;
    tail = head;
    length = 0;
}

DLList::~DLList()
{
    clear();
}

void DLList::clear()
{
    iter = head;
    while (iter != nullptr)
    {
        head = head->next;
        iter->next = nullptr;
        delete iter;
        iter = head;
        length--;
    }
    head = tail = iter; //iter is nullptr at this point
}

void DLList::addFront(int d)
{
    iter = new Node;
    iter->data = d;
    if(head != nullptr)
    {
        iter->next = head;
        head->prev = iter;
        head = iter;
    }
    else
        head = iter;
    length++;
    if(length == 1)
    {
        tail = head;
    }
}

void DLList::addBack(int d)
{
    iter = new Node;
    iter->data = d;
    if(tail != nullptr)
    {
        iter->prev = tail;
        tail->next = iter;
        tail = iter;
    }
    else
        tail = iter;
    length++;
    if(length == 1)
    {
        head = tail;
    }
}

void DLList::removeFront()
{
    if (head != nullptr)
    {
        iter = head;
        head = head->next;
        if (head != nullptr)
            head->prev = nullptr;
        iter->next = nullptr;
        delete iter;
        length--;
        if (length == 0)
            tail = head = nullptr;
    }
}

void DLList::removeBack()
{
    if (tail != nullptr)
    {
        iter = tail;
        tail = tail->prev;
        if (tail != nullptr)
            tail->next = nullptr;
        iter->prev = nullptr;
        delete iter;
        length--;
        if (length == 0)
            head = tail = nullptr;
    }
}

bool DLList::contains(int d)
{
    iter = head;
    while (iter != nullptr)
    {
        if (iter->data == d)
        {
            return true;
        }
        iter = iter->next;
    }
    return false;
}

void DLList::remove(int d)
{
    iter = head;
    while (iter != nullptr)
    {
        if (iter->data == d)
            removeNode(iter);
        else
            iter = iter->next;
    }
}

void DLList::display()
{
    iter = head;
    cout << "head -> ";
    while(iter != nullptr)
    {
        cout << iter->data;
        if(iter->next != nullptr)
            cout << " <-> ";
        iter = iter->next;
    }
    cout << endl;
    iter = tail;
    cout << "tail -> ";
    while(iter != nullptr)
    {
        cout << iter->data;
        if(iter->prev != nullptr)
            cout << " <-> ";
        iter = iter->prev;
    }
    cout << endl << endl;
}

// -------------------helper functions-------------------//
void DLList::removeNode(Node * n)
{
    if (n == head)
    {
        removeFront();
        iter = head;
    }
    else if(n == tail)
    {
        removeBack();
        iter = nullptr;
    }
    else //at least 3 nodes
    {
        iter = n->next;
        //jump over the node
        iter->prev = n->prev;
        n->prev->next = iter;
        //delete the node
        n->next = nullptr;
        n->prev = nullptr;
        delete n;
    }
}
