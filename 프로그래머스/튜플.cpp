#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <map>

using namespace std;
vector <int> v;
map <int, int> m;

vector <pair<int, int>> v2;

vector<int> solution(string s) {
	vector<int> answer;
	return answer;
}

bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.first > b.first;
}

int main() {
	string s = "{{1,2,3},{2,1},{1,2,4,3},{2}}";
	s = s.substr(1, s.length() - 2);
	/*cout << s << "\n";
	s=s.substr(1, s.length() - 1);
	cout << s;*/
	string a = "11,2,3";
	while (true) {
		if (a.find(',') == string::npos) {
			cout << "ss: " << a << "\n";
			break;
		}
		int idx = a.find(',');
		string b = a.substr(0, idx);
		cout << b << "\n";
		a = a.substr(idx + 1, a.length() - 1);
		cout << "a: " << a << "\n";
	}

	while (true) {
		if (s.find("},") == string::npos) {
			s=s.substr(1, s.length() - 2);
			//cout << "s3: " << s << "\n";
			while (true) {
				if (s.find(',') == string::npos) {
					//cout << "ss: " << a << "\n";
					if (m.find(stoi(s)) == m.end()) {
						m[stoi(s)] = 1;
						v.push_back(stoi(s));
					}
					else {
						m[stoi(s)]++;
					}
					break;
				}
				int idx = s.find(',');
				string b = s.substr(0, idx);
				if (m.find(stoi(b)) == m.end()) {
					m[stoi(b)] = 1;
					v.push_back(stoi(b));
				}
				else {
					m[stoi(b)]++;
				}
				//cout << b << "\n";
				s = s.substr(idx + 1, s.length() - 1);
				//cout << "a: " << a << "\n";
			}
			break;

		}
		s=s.substr(1, s.length() - 1);
		//cout <<"s: "<< s << "\n";
		int idx = s.find("},");
		string a = s.substr(0, idx);
		while (true) {
			if (a.find(',') == string::npos) {
				//cout << "ss: " << a << "\n";
				if (m.find(stoi(a)) == m.end()) {
					m[stoi(a)] = 1;
					v.push_back(stoi(a));
				}
				else {
					m[stoi(a)] ++;
				}
				break;
			}
			int idx = a.find(',');
			string b = a.substr(0, idx);
			if (m.find(stoi(b)) == m.end()) {
				m[stoi(b)] =1 ;
				v.push_back(stoi(b));
			}
			else {
				m[stoi(b)]++;
			}
			//cout << b << "\n";
			a = a.substr(idx + 1, a.length() - 1);
			//cout << "a: " << a << "\n";
		}
		while (true) {
			if (a.find(',') == string::npos) {
				break;
			}
		}
		//cout << a << "\n";
		s = s.substr(idx + 2, s.length() - 1);
		//cout << "s2: " << s << "\n";

	}
	cout << "\n";
	for (int i = 0; i < v.size(); i++) {
		v2.push_back(make_pair(m[v[i]], v[i]));
	}
	sort(v2.begin(), v2.end(), cmp);
	for (int i = 0; i < v2.size(); i++) {
		cout << v2[i].second << "\n";
	}
}