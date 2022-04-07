#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

string solution(string new_id) {
	string answer = "";
	return answer;
}

int main() {
	string new_id = "abcdefghijklmn.p";
	for (int i = 0; i < new_id.length(); i++) {
		new_id[i] = tolower(new_id[i]);
	}
	string s = "";
	for (int i = 0; i < new_id.length(); i++) {
		if (new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.' || (new_id[i] >= '0' && new_id[i] <= '9') || (new_id[i] >= 'a' && new_id[i] <= 'z')) {
			s += new_id[i];
		}
	}
	new_id = s;
	s = "";
	for (int i = 0; i < new_id.length(); i++) {
		if (new_id[i] == '.') {
			int t = i;
			int count = 0;
			while (true) {
				if (t >= new_id.length() - 1 || new_id[t] != new_id[t + 1]) {
					break;
				}
				t++;
				count++;
			}
			s += '.';
			i += count;
		}
		else {
			s += new_id[i];
		}
	}
	
	new_id = s;
	s = "";
	for (int i = 0; i < new_id.length(); i++) {
		if (i == 0) {
			if (new_id[i] == '.') {
				continue;
			}
			else {
				s += new_id[i];
			}
		}
		else if (i == new_id.length() - 1) {
			if (new_id[i] == '.') {
				continue;
			}
			else {
				s += new_id[i];
			}
		}
		else {
			s += new_id[i];
		}
	}
	new_id = s;
	if (new_id.length() == 0) {
		new_id = "a";
	}
	if (new_id.length() >= 16) {
		new_id = new_id.substr(0, 15);
		if (new_id[new_id.length() - 1] == '.') {
			new_id = new_id.substr(0, 14);
		}
	}
	if (new_id.length() <= 2) {
		char str2 = new_id[new_id.length() - 1];
		while (true) {
			if (new_id.length() == 3) {
				break;
			}
			new_id += str2;
		}
	}
	cout << new_id;


}