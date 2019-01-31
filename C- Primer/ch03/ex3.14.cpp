#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::vector;
using std::string;
int main() {
	vector<int> ivec;
	int num;
	while (cin >> num) {
		ivec.push_back(num);
	}
	return 0;
}