#include "arrayListType.h"
#include <iostream>

int main() {
    arrayListType<int> list;
    int input, position;

    // insert initial list input
    cout << "\nEnter 5 integers:\n";
    for (int i = 0; i < 5; i++) {
        cin >> input;
        list.insertAt(i, input);
    }

    cout << "\nThe list you entered is: ";
    list.print();
    cout << endl;

    cout << "Enter the position followed by integer to be inserted: ";
    cin >> position >> input;
    list.insertAt(position, input);
    list.print();

    cout << "Enter the position of item to be deleted: ";
    cin >> position;
    list.removeAt(position);


    cout << "The smallest element: " << list.min() << endl;

    return 0;
}
