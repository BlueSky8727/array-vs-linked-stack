#include <iostream>
#include <limits>
#include <iomanip>
#include "arraylist.h"

void printTable(const ArrayList& list) {
    std::cout << "\n-------------------------------\n";
    std::cout << "| Index | Value               |\n";
    std::cout << "-------------------------------\n";
    for (int i = 0; i < list.size(); ++i) {
        std::cout << "| " << std::setw(5) << i << " | " << std::setw(18) << list.get(i) << " |\n";
    }
    std::cout << "-------------------------------\n";
}

int main() {
    ArrayList list;
    int choice, index, value;

    // ตัวแปรสำหรับเก็บค่าล่าสุดที่เลือก
    int lastChoice = -1;
    int lastIndex = -1;
    int lastValue = -1;

    while (true) {  // ทำงานวนลูปเรื่อย ๆ จนกว่าจะเลือกออก
        std::cout << "\nMenu:\n";
        std::cout << "1. Add data\n";
        std::cout << "2. Set data\n";
        std::cout << "3. Get data\n";
        std::cout << "4. IndexOf\n";
        std::cout << "5. Remove\n";
        std::cout << "6. Size\n";
        std::cout << "7. Display\n";
        std::cout << "8. Clear\n";
        std::cout << "9. Min\n";
        std::cout << "10. Max\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice (0-10): ";

        // ตรวจสอบว่าใส่ค่าผู้ใช้เป็นตัวเลขหรือไม่
        if (!(std::cin >> choice)) {
            std::cin.clear();  // ล้างสถานะข้อผิดพลาด
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // ล้างบัฟเฟอร์
            std::cout << "Invalid input. Please enter a number between 0 and 10.\n";
            continue;  // ให้วนลูปใหม่
        }

        // ตรวจสอบว่าค่าที่ใส่เข้าไปอยู่ในช่วงที่ถูกต้องหรือไม่
        if (choice < 0 || choice > 10) {
            std::cout << "Invalid choice. Please enter a number between 0 and 10.\n";
            continue;  // ให้วนลูปใหม่
        }

        // ถ้าเลือก 0 ให้ออกจากโปรแกรม
        if (choice == 0) {
            std::cout << "Exiting...\n";
            break;  // ออกจากลูป
        }

        // จัดการเลือกเมนูต่าง ๆ
        switch (choice) {
            case 1:  // Add data
                std::cout << "Enter index and value: ";
                if (std::cin >> index >> value) {
                    list.add(index, value);
                    lastChoice = choice;
                    lastIndex = index;
                    lastValue = value;
                } else {
                    std::cin.clear();  // ล้างข้อผิดพลาด
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Invalid input. Please enter numeric values.\n";
                }
                break;
            case 2:  // Set data
                std::cout << "Enter index and value: ";
                if (std::cin >> index >> value) {
                    list.set(index, value);
                    lastChoice = choice;
                    lastIndex = index;
                    lastValue = value;
                } else {
                    std::cin.clear();  // ล้างข้อผิดพลาด
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Invalid input. Please enter numeric values.\n";
                }
                break;
            case 3:  // Get data
                std::cout << "Enter index: ";
                if (std::cin >> index) {
                    try {
                        lastValue = list.get(index);
                        std::cout << "Element at index " << index << ": " << lastValue << std::endl;
                        lastChoice = choice;
                        lastIndex = index;
                    } catch (const std::out_of_range& e) {
                        std::cout << e.what() << std::endl;
                    }
                } else {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Invalid input. Please enter a valid index.\n";
                }
                break;
            case 4:  // IndexOf
                std::cout << "Enter value: ";
                if (std::cin >> value) {
                    lastValue = value;
                    std::cout << "Index of " << value << ": " << list.indexOf(value) << std::endl;
                    lastChoice = choice;
                } else {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Invalid input. Please enter a numeric value.\n";
                }
                break;
            case 5:  // Remove
                std::cout << "Enter index: ";
                if (std::cin >> index) {
                    try {
                        lastValue = list.remove(index);
                        std::cout << "Removed element: " << lastValue << std::endl;
                        lastChoice = choice;
                        lastIndex = index;
                    } catch (const std::out_of_range& e) {
                        std::cout << e.what() << std::endl;
                    }
                } else {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Invalid input. Please enter a valid index.\n";
                }
                break;
            case 6:  // Size
                lastChoice = choice;
                std::cout << "Size of the list: " << list.size() << std::endl;
                break;
            case 7:  // Display
                printTable(list);  // แสดงข้อมูลในลิสต์
                lastChoice = choice;
                break;
            case 8:  // Clear
                list.clear();
                std::cout << "List cleared." << std::endl;
                lastChoice = choice;
                break;
            case 9:  // Min
                try {
                    lastValue = list.min();
                    std::cout << "Min element: " << lastValue << std::endl;
                    lastChoice = choice;
                } catch (const std::out_of_range& e) {
                    std::cout << e.what() << std::endl;
                }
                break;
            case 10:  // Max
                try {
                    lastValue = list.max();
                    std::cout << "Max element: " << lastValue << std::endl;
                    lastChoice = choice;
                } catch (const std::out_of_range& e) {
                    std::cout << e.what() << std::endl;
                }
                break;
            default:
                break;
        }

        // แสดงข้อมูลจากเมนูที่เลือกล่าสุด
        std::cout << "\nLast selected: " << lastChoice;
        std::cout << " (Index: " << lastIndex << ", Value: " << lastValue << ")\n";
        
        // แสดงตารางข้อมูลล่าสุดที่ผู้ใช้ใส่
        printTable(list);
    }

    return 0;
}
