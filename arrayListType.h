//
// Created by Jaquan Jones on 3/7/20.
//

#ifndef H_arrayListType
#define H_arrayListType

#include <iostream>
#include <cassert>

using namespace std;

template<class elemType>
class arrayListType {
public:

    void print() const;

    void insertAt(int location, const elemType &insertItem);

    void removeAt(int location);

    elemType min() const;

    arrayListType(int size = 5);

    arrayListType(elemType *list, int length, int maxSize);

    ~arrayListType();

protected:
    elemType *list;  //array to hold the list elements
    int length;      //to store the length of the list
    int maxSize;     //to store the maximum size of the list
};

/* +++++ Write function definition for the four functions below	++++ */

// print function definition
template<class elemType>
void arrayListType<elemType>::print() const {

    for (int i = 0; i < length; i++) {
        cout << list[i] << " ";
    }
    cout << endl;
}

// find minimum value of the list
template<class elemType>
elemType arrayListType<elemType>::min() const {

    if (length == 0) {
        throw 0;
    }

    elemType min = list[0];

    for (int i = 1; i < length; i++) {
        if (list[i] < min) {
            min = list[i];
        }
    }

    return min;
}

// insertAt function definition
template<class elemType>
void arrayListType<elemType>::insertAt
        (int location, const elemType &insertItem) {

    if ((0 <= location < maxSize) && length < 5) {
        for (int i = length; i > location; i--) {
            list[i] = list[i - 1];
        }
        list[location] = insertItem;
        length++;
    } else {

        if (0 <= location >= maxSize) {
            cout << "Index out of range.\n";
        }

        if (length == maxSize) {
            cout << "List is full.\n";
        }
    }

}


// removeAt function definition
template<class elemType>
void arrayListType<elemType>::removeAt(int location) {
    if ((location < 0) || location >= length) {
        cout << "The location of the item to be removed is out of range.\n";
        cout << "The list does not change.\n";
    } else if (location == 0) {
        list[location] = list[length - 1];
        length--;
        cout << "After removing the element at position " << location << " the list is: ";
        print();
        cout << endl;
    } else {
        for (int i = location; i < length - 1; i++) {
            list[i] = list[i + 1];
        }
        length--;
        cout << "After removing the element at position " << location << " the list is: ";
        print();
        cout << endl;
    }
}

// ++++ You need the two templates below to avoid errors +++++++

// constructor function
template<class elemType>
arrayListType<elemType>::arrayListType(int size) {
    if (size < 0) {
        cerr << "The array size must be positive. Creating "
             << "an array of size 5. " << endl;
        maxSize = 5;
    } else
        maxSize = size;

    length = 0;
    list = new elemType[maxSize];
    assert(list != NULL);
}

// destructor function
template<class elemType>
arrayListType<elemType>::~arrayListType() {
    delete[] list;
}

#endif

