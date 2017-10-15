//
//  DLList.h
//  DLList
//
//  Created by Philip Leblanc on 2017-10-13.
//  Copyright © 2017 Philip Leblanc. All rights reserved.
//

#ifndef DLList_h
#define DLList_h

#include <stdio.h>

struct Node {
    int data = 0;
    Node * next = nullptr;
    Node * prev = nullptr;
};

class DLList {
private:
    Node * head;
    Node * tail;
    Node * iter; //used as a helper node pointer to iterate / add / delete
    int length;
    
    void removeNode(Node *);
    
public:
    DLList();
    ~DLList();
    DLList(const DLList &list);
    int inline size() {return length;}
    
    void clear(); //empty the list
    void addFront(int data);
    void addBack(int data);
    void removeFront();
    void removeBack();
    bool contains(int data); //search for data
    void remove(int data); //remove the elements with data
    
    void display(); // print out the list to the terminal starting from head
};

#endif /* DLList_h */
