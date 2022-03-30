#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

vector<string> record;
vector<string> answer;
map <string, string> m;
vector <pair<string, string>> v;
vector<string> solution(vector<string> record) {
	vector<string> answer;
	return answer;
}


int main(void) {

	record = { "Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan" };
	string s = "Enter uid1234 Muzi";
	
	for (int i = 0; i < record.size(); i++) {
		string s = record[i];
		int idx = s.find(" ");

		string a = s.substr(0, idx);
		//cout << a << "\n";
		s = s.substr(idx + 1, s.length());
		idx = s.find(" ");
		//cout << s << "\n";
		string b = s.substr(0, idx);
		//cout << b << "\n";
		string c = s.substr(idx + 1, s.length());
		//cout << c << "\n";
		if (a == "Enter") {
			if (m.find(b) != m.end()) {
				m[b] = c;
			}
			else {
				m.insert(make_pair(b, c));
			}
			
		}
		else if (a == "Change") {
			m[b] = c;
			
		}
		v.push_back(make_pair(a, b));
		
		
	}
	for (int i = 0; i < v.size(); i++) {
		string nickname = m[v[i].second];
		if (v[i].first == "Enter") {
			
			string ans = "";
			ans += nickname;
			ans += "´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.";
			answer.push_back(ans);
		}
		else if (v[i].first == "Leave") {
			string ans = "";
			ans += nickname;
			ans += "´ÔÀÌ ³ª°¬½À´Ï´Ù.";
			answer.push_back(ans);
		}
	}
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
	}
}
