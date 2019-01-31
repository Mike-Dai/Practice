#include <iostream>
#include <string>
#include <vector>

int main() {
	std::vector<std::string> svec;
	for (std::string str; std::cin >> str; svec.push_back(str));
	return 0;
}