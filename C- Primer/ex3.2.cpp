/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string line, word;
    /*
    while (getline(cin,line)) {
        cout << line;
    }
    */
    while (cin >> word) {
        cout << word << endl;
    }
    return 0;
}
