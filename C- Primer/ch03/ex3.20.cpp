#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main() {
	vector<int> vec;
	for (int num; cin >> num; vec.push_back(num));
	if (vec.empty() || vec.size() == 1) return -1;
	for (int i = 0; i < vec.size() - 1; ++i) {
		cout << vec[i] + vec[i+1] << " ";
	}
	cout << endl;
	for (int i = 0; i < vec.size() / 2; ++i) {
		cout << vec[i] + vec[vec.size()-i-1];
	}
	cout << endl;
	return 0;
}