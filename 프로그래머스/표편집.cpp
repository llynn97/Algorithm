#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>

using namespace std;

map <string, int> m; 
map <string, int> m2;//삭제된 행

vector <pair<int, int>> v;
string solution(int n, int k, vector<string> cmd) {
	string answer = "";
	return answer;
}

int main(void) {
	int n = 8;
	int k = 2;
	int idx2 = 0;
	idx2 = n;
	vector<string> cmd = { "D 2","C","U 3","C","D 4","C","U 2","Z","Z","U 1","C" };
	for (int i = 0; i < n; i++) {
		m[to_string(i)] = i;
	}

	for (int i = 0; i < cmd.size(); i++) {
		string s = cmd[i];
		int num = -1;
		if (s.find(' ') != string::npos) {
			int idx = s.find(' ');
			num = stoi(s.substr(idx + 1, s.length() - 1));
			s = s.substr(0, idx);
		}
		if (s == "U") {
			while (num--) {
				if (k == 0) {
					k = n - 1;
			   }
				k -= 1;
			}
		}
		if (s == "D") {
			while (num--) {
				if (k == n - 1) {
					k = 0;
				}
				k += 1;
			}

		}
		if (s == "C") {
			if (k == n - 1) {
				v.push_back(make_pair(k, m[to_string(k)]));
				n -= 1;
				k -= 1;
				//m[to_string(n)] = -1;

			}
			else {
				m2[to_string(m[to_string(k)])] = 1;
				
				v.push_back(make_pair(k, m[to_string(k)]));
				n -= 1;
				for (int j = k; j < n; j++) {
					m[to_string(j)] = m[to_string(j + 1)];
				}
				//m[to_string(n)] = -1;
			}
		}
		if (s == "Z") {
			int a = v.back().first; 
			int b = v.back().second;
			v.pop_back();
			if (a >= n) {
				n += 1;
				m[to_string(a)] = b;
				m2.erase(to_string(b));

			}
			else {
				
				for (int j = n-1; j >=a; j--) {
					m[to_string(j+1)] = m[to_string(j)];
				}
				n += 1;
				m[to_string(a)] = b;
				m2.erase(to_string(b));
				k += 1;
				
					
			}

		}
		cout << "===============================\n";
	
	}
	for (int i = 0; i < idx2; i++) {
		if (m2.find(to_string(i))==m2.end()) {
			cout << "0";
		}
		else {
			cout << "X";
		}
	}
}