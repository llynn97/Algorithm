#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string str;

int main(void) {

	while (true) {
		string s = "";
		cin >> str;
		if (str == "0") {
			break;
		}
		for (int i = str.length() - 1; i >= 0; i--) {
			s += str[i];
		}
		if (str == s) {
			cout << "yes";
		}
		else {
			cout << "no";
		}
		cout << "\n";
	}
}