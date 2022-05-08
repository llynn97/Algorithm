#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>


using namespace std;
map <string, int> m1;
map <string, vector<string>> m2;
map <string,int> m3; 

map <string, int> m4;
vector <string> v;
vector < pair<int, pair<int, string>> > ans;

bool cmp(pair<int, pair<int, string>> a, pair<int, pair<int, string>> b) {
	if (a.first == b.first) {
		if (a.second.first == b.second.first) {
			return a.second.second < b.second.second;
		}
		else {
			return a.second.first < b.second.first;
		}
	}
	else {
		return a.first < b.first;
	}
}
int main(void) {
	vector<string> rooms = { "[403]James", "[404]Azad,Louis,Andy", "[101]Azad,Guard" };
	int target = 403;
	

	for (int i = 0; i < rooms.size(); i++) {
		string s = rooms[i];
		int idx = s.find(']');
		string a = s.substr(1, idx - 1); //È£¼ö
		bool check = false;
		if (target == stoi(a)) {
			check = true;
		}
		s = s.substr(idx + 1, s.length() - 1);
		while (true) {
			if (s.find(',') == string::npos) {
				if (check) {
					m4[s] = 1;
				}
				if (m1.find(s) == m1.end()) {
					m1[s] = 1;
					m3[s] = abs(target - stoi(a));
					v.push_back(s);
				}
				else {
					m1[s]++;
					if (m3[s] > abs(target - stoi(a))) {
						m3[s] = abs(target - stoi(a));
					}
				}
				m2[a].push_back(s);
				break;
			}
			idx = s.find(',');
			string b = s.substr(0, idx);
			if (check) {
				m4[b] = 1;
			}
			if (m1.find(b) == m1.end()) {
				m1[b] = 1;
				m3[b] = abs(target - stoi(a));
				v.push_back(b);
			}
			else {
				m1[b]++;
				if (m3[b] > abs(target - stoi(a))) {
					m3[b] = abs(target - stoi(a));
				}
			}
			m2[a].push_back(b);

			s = s.substr(idx + 1, s.length() - 1);

		}
	}
	
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << "\n";
	}


	for (int i = 0; i < v.size(); i++) {
		string str3 = v[i];
		if (m4.find(str3) == m4.end()) {
			ans.push_back(make_pair(m1[str3], make_pair(m3[str3], str3)));
		}
	}
	sort(ans.begin(), ans.end(), cmp);
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i].first << " " << ans[i].second.first << " " << ans[i].second.second << "\n";
	}


}