/******************************************************************************
Zakaria Elkhodary 
CISC187_Chapter 18 Programming Assignment- Linked Lists
10/29/24
*******************************************************************************/
#include "beautifulbeads.h"
#include <limits>  

int main() {
    beautifulbeads necklace;
    int selection;
    string stone;
    int pos;

    do {
        showMenu();
        cin >> selection;

        if (selection == 1 || selection == 2) {
            cout << "Type in which stone you want on your necklace (turquoise, coral, gold, copper): ";
            cin >> stone;

            // Validation for string input
            if (cin.fail() || (isdigit(stone[0]) && stone.length() == 1)) {
                cin.clear(); 
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the users invalid input.
                cout << "Sorry but this --> " << stone << " is not an option pal.\n";
                continue; // This prompts the user for input again
            }
        }

        switch (selection) {
        case 1:
            necklace.append(stone);
            break;

        case 2:
            cout << "Enter which spot you would like me to insert at: ";
            cin >> pos;
            if (necklace.insert(stone, pos) == -1) {
                cout << "Nope not an option...Try again pal!\n";
            }
            break;

        case 3:
            cout << "What stone do you want to delete form the list? ";
            cin >> pos;
            if (necklace.deleteNode(pos) == -1) {
                cout << "Nope not an option...Try again bud!\n";
            }
            break;

        case 4:
            necklace.display();
            break;

        case 5:
            cout << "Enter which stone you want me to search for: ";
            cin >> stone;
            necklace.search(stone);
            break;

        case 6:
            cout << "Hasta la vista baby!\n";
            break;

        default:
            cout << "Sorry pal thats not an option please try again!\n";
        }
    } while (selection != 6);

    return 0;
} 