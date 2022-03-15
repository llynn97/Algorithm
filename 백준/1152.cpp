#include <iostream>
#include <vector>
#include <algorithm>
#include <string>


using namespace std;


string str;
int start = 0;
int final = 0;
bool check = false;
int ans = 0;
int j = 0;
int main(void) {

	getline(cin, str);
	
	if (str.empty()) {
		cout << "0";
		return 0;
	}
	ans = 1;
	
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == ' ') {
			ans++;
		}
	}
	if (str[0] == ' ') {
		ans--;
	}
	if (str[str.length() - 1] == ' ') {
		ans--;
	}
	cout << ans;
	return 0;
	
	

}