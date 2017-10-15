//
//  main.cpp
//  DLList
//
//  Created by Philip Leblanc on 2017-10-13.
//  Copyright © 2017 Philip Leblanc. All rights reserved.
//
#include "DLList.h"
#include <iostream>
using namespace std;


int main(int argc, const char * argv[]) {
    
    DLList myList;
    
    //test addition
    myList.addFront(1);
    myList.addFront(2);
    myList.addFront(3);
    myList.addFront(4);
    
    myList.display();
    
    myList.clear();
    
    myList.display();
    
    myList.addBack(1);
    myList.addBack(2);
    myList.addBack(3);
    myList.addBack(4);
    
    myList.display();
    
    myList.addFront(5);
    myList.addFront(6);
    myList.addFront(7);
    
    myList.display();
    
    //test removal
    myList.removeBack();
    myList.removeBack();
    myList.removeBack();
    myList.display();
    
    myList.removeFront();
    myList.removeFront();
    myList.removeFront();
    myList.display();
    
    myList.removeBack();
    myList.removeBack();
    myList.display();
    
    myList.addFront(1);
    myList.addFront(2);
    myList.addFront(3);
    myList.addFront(4);
    myList.addBack(1);
    myList.addBack(2);
    myList.addBack(3);
    myList.addBack(4);
    myList.addFront(5);
    myList.addFront(6);
    myList.addFront(7);
    myList.display();
    
    //test contains()
    cout << "List contains 1: " << myList.contains(1) << endl;
    cout << "List contains 8: " << myList.contains(8) << endl << endl;
    
    //test remove(int)
    myList.remove(1);
    myList.display();
    myList.remove(7);
    myList.display();
    myList.remove(2);
    myList.display();
    myList.remove(0);
    myList.display();
    
    return 0;
}
