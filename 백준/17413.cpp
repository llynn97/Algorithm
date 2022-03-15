#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>


using namespace std;

stack <char> stk;

string s;

int main(void) {

	getline(cin, s);
	for (int i = 0; i < s.length(); i++) {
		if ((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'z')) {
			stk.push(s[i]);
		}
		else if (s[i] == ' ') {
			if (!stk.empty()) {
				while (!stk.empty()) {
					cout << stk.top();
					stk.pop();
				}
				cout << " ";
			}
		}
		else if (s[i] == '<') {
			if (i!=0 && s[i - 1] != '>') {
				if (!stk.empty()) {
					while (!stk.empty()) {
						cout << stk.top();
						stk.pop();
					}
					
				}
			}
			while (s[i] != '>') {
				cout << s[i];
				i = i + 1;
			}
			cout << s[i];
		}
	}
	if (!stk.empty()) {
		while (!stk.empty()) {
			cout << stk.top();
			stk.pop();
		}
	}
}