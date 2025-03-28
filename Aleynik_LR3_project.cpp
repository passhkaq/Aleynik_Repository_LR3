#include <iostream>
#include <map>
#include <string>
using namespace std;

int x = 0, n = 0;

void enterNumber(int& var, const string& prompt, int min, int max);

void getNumX();
void getNumN();
void getFDigitX(int x);
void getNDigitX(int x, int n);

int main() {
    struct menuItem{
        string title;
        function<void()> action;
    };

    map<int, menuItem> menu {
        {1, {"Enter a number X", getNumX}},
        {2, {"Enter a number N", getNumN}},
        {3, {"Find first digit of X", [&]() { getFDigitX(x); }}},
        {4, {"Find N digit of X", [&]() { getNDigitX(x, n); }}},
    };

    int choice = 0;
    bool flag = true;

    while (flag) {
        cout << "Menu:" << endl;
        cout << "0. Exit" << endl;

        for (const auto& item : menu) {
            cout << item.first << ". " << item.second.title << endl;
        }

        enterNumber(choice, "Choose the option to proceed: ", 0, 4);

        switch (choice) {
        case 0:
            cout << "Poka Poka" << endl;
            flag = false;
            break;
        case 1:
            menu[1].action();
            break;
        case 2:
            menu[2].action();
            break;
        case 3:
            menu[3].action();
            break;
        case 4:
            menu[4].action();
            break;
        default:
            break;
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

void getFDigitX(int x) {
    int var = 0;
    var = x / 100;
    cout << "First digit of X is " << var << endl;
}

void getNDigitX(int x, int n) {
    int var = (n == 1) ? x % 10 : (x / 10) % 10;
    cout << n << " digit of X is " << var << endl;
}



