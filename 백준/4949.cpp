#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>


using namespace std;

string str;
stack <char> stk;

int main(void) {

	

	while (true) {
		while (!stk.empty()) {
			stk.pop();
		}
		getline(cin, str);
		if (str == ".") {
			break;
		}
		string ans = "";
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == '(' || str[i] == '[') {
				stk.push(str[i]);
			}
			if (str[i] == ')') {
				if (stk.empty()) {
					ans = "no";
				}
				else{
					
				   if (!stk.empty() && stk.top() == '(') {
					stk.pop();
				   }
				   else {
					   ans = "no";
				   }
				}
			}
			if (str[i] == ']') {
				if (stk.empty()) {
					ans = "no";
				}
				else{
					
					if (!stk.empty() && stk.top() == '[') {
						stk.pop();
					}
					else {
						ans = "no";
					}
				}
			}
		}
		if (ans != "") {
			cout << "no";
		}
		else {
			if (stk.empty()) {
				cout << "yes";
			}
			else {
				cout << "no";
			}
		}
		cout << "\n";
	
	}
}