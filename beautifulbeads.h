#ifndef BEAUTIFULBEADS_H
#define BEAUTIFULBEADS_H

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

// class declaration
class beautifulbeads {
private:
    struct ListNode {  // Inner struct for each node in the linked list
        string stonetype;
        ListNode* next;

        ListNode(string stone) : stonetype(stone), next(nullptr) {}
    };

    ListNode* head;  // Head pointer for the linked list
    bool stoneVal(const string& stone) const;  // Validation function for stone types

public:
    beautifulbeads();           // Constructor
    ~beautifulbeads();          // Destructor
    void append(string stone);   // Append (add) stone to end
    int insert(string stone, int position);   // Insert stone at specified position
    int deleteNode(int position);  // Delete stone at specified position
    void display() const;  // Display all stones in the list
    void search(const string& stone) const;   // Search for stone and return its position
};

// Function prototypes
void showMenu();

#endif
