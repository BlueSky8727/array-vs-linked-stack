#include "LinkedList.h"
#include <iostream>
#include <limits>
#include <iomanip>
using namespace std;

void printTable(const LinkedList& list) {
    cout << "\n-------------------------------\n";
    cout << "| Index | Value               |\n";
    cout << "-------------------------------\n";
    for (int i = 0; i < list.size(); ++i) {
        cout << "| " << setw(5) << i << " | " << setw(18) << list.get(i) << " |\n";
    }
    cout << "-------------------------------\n";
}

int main() {
    LinkedList list;
    int choice, index, value;

    while (true) {
        cout << "\n--- LinkedList Menu ---" << endl;
        cout << "1. Add Data" << endl;
        cout << "2. Set Data" << endl;
        cout << "3. Get Data" << endl;
        cout << "4. IndexOf" << endl;
        cout << "5. Remove" << endl;
        cout << "6. Size" << endl;
        cout << "7. Display" << endl;
        cout << "8. oddCount" << endl;
        cout << "9. evenCount" << endl;
        cout << "10. Sum" << endl;
        cout << "11. Mean" << endl;
        cout << "12. Sort" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid number.\n";
            continue;
        }

        if (choice < 0 || choice > 12) {
            cout << "Invalid choice. Please enter a number between 0 and 12.\n";
            continue;
        }

        if (choice == 0) {
            cout << "Exiting program...\n";
            break;
        }

        switch (choice) {
            case 1:
                cout << "Enter index and value: ";
                if (cin >> index >> value) {
                    list.add(index, value);
                }
                break;
            case 2:
                cout << "Enter index and value: ";
                if (cin >> index >> value) {
                    list.set(index, value);
                }
                break;
            case 3:
                cout << "Enter index: ";
                if (cin >> index) {
                    cout << "Value at index " << index << ": " << list.get(index) << endl;
                }
                break;
            case 4:
                cout << "Enter value: ";
                if (cin >> value) {
                    cout << "Index of " << value << ": " << list.indexOf(value) << endl;
                }
                break;
            case 5:
                cout << "Enter index: ";
                if (cin >> index) {
                    cout << "Removed: " << list.remove(index) << endl;
                }
                break;
            case 6:
                cout << "Size of LinkedList: " << list.size() << endl;
                break;
            case 7:
                printTable(list);
                break;
            case 8:
                cout << "Odd count feature not implemented yet!" << endl;
                break;
            case 9:
                cout << "Even count feature not implemented yet!" << endl;
                break;
            case 10:
                cout << "Sum feature not implemented yet!" << endl;
                break;
            case 11:
                cout << "Mean feature not implemented yet!" << endl;
                break;
            case 12:
                cout << "Sort feature not implemented yet!" << endl;
                break;
        }
    }
    return 0;
}
