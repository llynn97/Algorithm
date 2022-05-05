#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;
map <string, int> m;
bool solution(vector<string> phone_book) {
	bool answer = true;
	sort(phone_book.begin(), phone_book.end());
	if (phone_book.size() != 1) {
		for (int i = 1; i < phone_book.size(); i++) {
			string str = phone_book[i - 1];
			if (str == phone_book[i].substr(0, str.length())) {
				return false;
				break;
			}
		}
	}
	
	return answer;
}



int main(void) {
	vector<string> phone_book = { "12","123","1235","567","88" };
	bool ans = solution(phone_book);
	if (ans) {
		cout << "¾Æ´Ô";
	}
	else {
		cout << "ÀÖÀ½";
	}
}