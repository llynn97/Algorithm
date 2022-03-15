#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string str;
string s; //Æø¹ß ¹®ÀÚ
string ans = "";
vector <int> v; 
int dif = 0;

int main(void) {
	
	cin >> str;
	cin >> s;

	for (int i = 0; i < str.length(); i++) {
		ans += str[i];
		if (s[s.length() - 1] == ans[ans.length() - 1]) {
			if (ans.length() >= s.length()) {
				int cnt = 0;
				for (int j = 0; j < s.length(); j++ ) {
					if (s[s.length() - 1 - j] == ans[ans.length() - 1 - j]) {
						cnt++;
					}
				}
				if (cnt == s.length()) {
					for (int j = 0; j < s.length(); j++) {
						ans.pop_back();
					}
				}
			}
		}
	}

	if (ans == "") {
		cout << "FRULA";
	}
	else {
		cout << ans;
	}

	
	
	
}