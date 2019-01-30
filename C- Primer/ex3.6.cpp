#include <iostream>

using namespace std;

int main()
{
   string str("some string");
   for (auto &c:str) {
       c = 'X';
   }
   cout << str;
   return 0;
}
