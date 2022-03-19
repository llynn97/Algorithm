#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <stack>
using namespace std;
string s;
int cnt = 0;
int young = 0;
vector<int> solution(string s) {
	vector<int> answer;
	return answer;
}


int main(void) {

	s = "01110";
	stack <int> st;
	string str = "";
	while (true) {
		if (s == "1") {
			break;
		}
		str = "";
		int x = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '0') {
				x++;
				continue;
			}
			str += s[i];
		}
		cout << "Str: " << str << " " ;
		young += x;
		s = "";
		int strlength = str.length();
		
		while (true) {
			if (strlength <= 1) {
				st.push(strlength);
				break;
			}
			st.push(strlength % 2);
			strlength = strlength / 2;
			
		}
		while (!st.empty()) {
			s+=to_string(st.top());
			st.pop();
		}
		cout << "S: " << s << "\n";
		
		cnt++;

	}

	cout << cnt <<" "<< young;

}