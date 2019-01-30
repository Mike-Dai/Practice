#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
   string str;
   for (decltype(str.size()) index = 0;
   index != str.size() && !isspace(str[index]); index++) {
       if (!ispunct(str[index])) {
           cout << str[index];
       }
   }
   return 0;
}
