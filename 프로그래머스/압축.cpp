#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;
string msg = "";
vector <int> v; //색인번호
vector<int> answer;


vector<int> solution(string msg) {
	vector<int> answer;
	return answer;
}

int main(void) {
	msg = "KAKAO";
	map <string, int> word;
	vector <string> a;
	int cnt = 1;
	int current = 27;
	for (int i = 0; i < 26; i++) {
		string s = "";
		char t = 'A' + i;
		s += t;
		a.push_back(s);
	}
	
	for (int i = 0; i < 26; i++) {
		
		word.insert(make_pair(a[i], i + 1));
	}
	while (true) {
		string w = msg.substr(0, cnt);
		string c = msg.substr(cnt, 1);
		string wc = w + c;
		if (word.find(w) != word.end()) {
			if (word.find(wc) != word.end()) {
				if (cnt < msg.size()) {
					cnt++;
				}
			}
			else {
				answer.push_back(word[w]);
				a.push_back(wc);
				word.insert(make_pair(wc, current++));
				msg.erase(0, cnt);
				cnt = 1;

			}
		}
		if (c == "\0") {
			answer.push_back(word[w]);
			break;
		}
	}

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
	}
	

}