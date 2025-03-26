#include <iostream>
#include <map>
#include <string>
using namespace std;


void enterNumber(int& var, const string& prompt, int min, int max);

void getNumX();
void getNumN();

int main() {
    struct menuItem{
        string title;
        function<void()> action;
    };

    map<int, menuItem> menu {
        {1, {"Enter a number X", getNumX}},
        {2, {"Enter a number N", getNumN}},
        {3, {"Find first digit of X", getFDigitX}},
        {4, {"Find N digit of X", getNDigitX}},
    };

    int choice = 0;

    while (true) {
        cout << "Menu:" << endl;

        for (const auto& item : menu) {
            cout << item.first << ". " << item.second.title << endl;
        }

        enterNumber(choice, "Choose the option to proceed: ", 0, 4);

        if (choice == 0) {
            cout << "Poka Poka" << endl;
            break;
        } else {
            menu[choice].action();
        }

        cout << endl << endl;
    }

    return 0;
}


void enterNumber(int& var, const string& prompt, int min, int max) {
    string input;
    cout << prompt;
    while (true) {
        getline(cin, input);
        if (input.empty()) {
            cout << "Input is empty" << endl;
            continue;
        }
        try {
            int number = stoi(input);
            if (number < min) {
                cout << "Minimum valid number is " << min << endl;
                continue;
            } else if (number > max) {
                cout << "Maximum valid number is " << max << endl;
                continue;
            }
            var = number;
            break;
        } catch (const exception& e) {
            cout << "Input is not integer" << endl;
        }
    }
}

void getNumX() {
    enterNumber(x, "Enter X (100-999): ", 100, 999);
}

void getNumN() {
    enterNumber(n, "Enter N (1-2): ", 1, 2);
}

int x = 0, n = 0;
