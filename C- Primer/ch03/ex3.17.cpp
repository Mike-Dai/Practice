#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
	vector<string> svec;
	for (string word; cin >> word; svec.push_back(word));
	for (auto &str : svec) for (auto &c : str) c = toupper(c);
	for (string::size_type i = 0; i != svec.size(); ++i) {
		if (i != 0 && i % 8 == 0) cout << endl;
		cout << svec[i] << " ";
	}
	cout << endl;
	return 0;
}
