#include "beautifulbeads.h"

// Constructor  
beautifulbeads::beautifulbeads() : head(nullptr) {}

// Destructor  
beautifulbeads::~beautifulbeads() {
    ListNode* nodePtr = head;
    while (nodePtr != nullptr) {
        ListNode* temp = nodePtr;
        nodePtr = nodePtr->next;
        delete temp;  
    }
}

// Stone type validation 
bool beautifulbeads::stoneVal(const string& stone) const {
    return stone == "turquoise" || stone == "coral" || stone == "gold" || stone == "copper";
}

// Appends (adds) stone to the end of the list
void beautifulbeads::append(string stone) {
    if (!stoneVal(stone)) {  
        cerr << "Error: " << stone << " is not a valid stone type.\n";
        return;
    }
    ListNode* newNode = new ListNode(stone);
    if (!head) {
        head = newNode;  // If list is empty, set new node as head
    } else {
        ListNode* nodePtr = head;
        while (nodePtr->next) {  // Traverse to end of list
            nodePtr = nodePtr->next;
        }
        nodePtr->next = newNode;  // Link last node to new node
    }
    cout << "Good choice! a " << stone << " stone has been added to your necklace.\n";
}

// Inserts stone at a specified position
int beautifulbeads::insert(string stone, int position) {
    if (!stoneVal(stone)) {  // Validate stone type
        cerr << "Error: " << stone << " is not a valid stone type.\n";
        return -1;
    }
    ListNode* newNode = new ListNode(stone);
    if (position == 0) {  // Insert at head
        newNode->next = head;
        head = newNode;
        return 0;
    }

    ListNode* nodePtr = head;
    for (int i = 0; nodePtr && i < position - 1; i++) {
        nodePtr = nodePtr->next;
    }

    if (!nodePtr) return -1;  // Position doesn't exist
    newNode->next = nodePtr->next;
    nodePtr->next = newNode;
    cout << "Nice! a " << stone << " stone has been inserted at position " << position << ".\n";
    return 0;
}

// Deletes stone at specified position
int beautifulbeads::deleteNode(int position) {
    if (!head) return -1;

    if (position == 0) {  // Deleting head node
        ListNode* temp = head;
        head = head->next;
        delete temp;
        return 0;
    }

    ListNode* nodePtr = head;
    ListNode* previousNode = nullptr;
    for (int i = 0; nodePtr && i < position; i++) {
        previousNode = nodePtr;
        nodePtr = nodePtr->next;
    }

    if (!nodePtr) return -1;  // Position doesn't exist
    previousNode->next = nodePtr->next;
    delete nodePtr;
    cout << "The stone at (" << position << ") has been deleted from your list.\n";
    return 0;
}

// Displays all stones in the list
void beautifulbeads::display() const {
    if (!head) {
        cout << "Sorry but the list is currently empty. Please add some stones to the necklace! \n";
        return;
    }

    ListNode* nodePtr = head;
    int position = 0;
    cout << "Here are the stones you currently have on your list:\n";
    while (nodePtr) {
        cout << "(" << position << ") " << nodePtr->stonetype << "\n";
        nodePtr = nodePtr->next;
        position++;
    }
}

// this function searches for a stone and returns its position
void beautifulbeads::search(const string& stone) const {
    ListNode* nodePtr = head;
    int position = 0;
    bool found = false;

    while (nodePtr) {
        if (nodePtr->stonetype == stone) {
            cout << "A " << stone << " stone is located at (" << position << ")\n";
            found = true;
        }
        nodePtr = nodePtr->next;
        position++;
    }

    if (!found) {
        cout << "Stone not found.\n";
    }
}

// Displays menu options
void showMenu() {
     cout << "--------------";
    cout << "\nNecklace Menu: \n";
    cout << "--------------\n";
    cout << "1. Append (Add) a stone to the necklace.\n";
    cout << "2. Insert stone at desired spot.\n";
    cout << "3. Delete stone at desired spot.\n";
    cout << "4. Show the necklace (This will show the spot of each stone on the necklace).\n";
    cout << "5. Search for a type of stone on the necklace.\n";
    cout << "6. Exit.\n";
    cout << "Enter a number from above: ";
}
