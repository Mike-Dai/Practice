#include <iostream>
#include <string>
using namespace std;
int main() {
    string str1, str2;
    cin >> str1 >> str2;
    if (str1 == str2) {
        cout << str1 << " is equal to " << str2 << endl;
    }
    else {
        if (str1 > str2) {
            cout << str1 << " is larger" << endl;
        }
        else if (str2 > str1) {
            cout << str2 << " is larger" << endl;
        }
    }
    if (str1.size() == str2.size()) {
        cout << str1 << "has the same length with " << str2 << endl;
    }
    else {
        if (str1.size() > str2.size()) {
            cout << str1 << "is longer" << endl;
        }
        else {
            cout << str2 << "is longer" << endl;
        }
    }
}
