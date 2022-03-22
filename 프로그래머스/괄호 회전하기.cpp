#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;
string s;
int answer = 0;
stack <char> st;


int solution(string s) {
	int answer = -1;
	return answer;
}




int main(void) {
	s = "}]()[{";
	string str = "";
	string str2 = s;

	int index = 0;
	for (int i = 0; i < s.length(); i++) {
		str = "";
		bool check = false;
		for (int j = 1; j < s.length(); j++) {

			str += str2[j];

		}


		str += str2[0];

		str2 = str;
		//cout << str << "\n";
		for (int j = 0; j < str.length(); j++) {
			if (str[j] == '[' || str[j] == '(' || str[j] == '{') {
				st.push(str[j]);
			}
			else {
				if (st.size() == 0) {
					check = true;
				}
				else if (str[j] == ')') {
					if (st.top() == '(') {
						st.pop();
					}

				}
				else if (str[j] == ']') {
					if (st.top() == '[') {
						st.pop();
					}

				}
				else if (str[j] == '}') {
					if (st.top() == '{') {
						st.pop();
					}

				}

			}

		}
		if (check == false && st.size() == 0) {
			answer++;
			//cout << "index´Â " << index << "\n";
		}
		else {
			while (!st.empty()) {
				
				st.pop();
			}
		
		}

		index++;
	}
	cout << answer;
}