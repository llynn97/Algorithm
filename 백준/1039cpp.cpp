#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <set>
#include <map>
#include <queue>

using namespace std;

int n, k;
set <string> s;
string str;
int answer = 0;

void bfs() {
	queue <string> q;
	q.push(str);
	for (int t = 1; t <= k; t++) {
		s.clear();
		int idx = q.size();
		for (int i = 0; i < idx; i++) {
			string s1 = q.front();
			q.pop();
			for (int j = 0; j < s1.length() - 1; j++) {
				for (int p = j + 1; p < s1.length(); p++) {
					if (j == 0 && s1[p] == '0') {
						continue;
					}
					else {
						//cout << "i j: " << j << " " << p << "\n";
						string s2 = s1;
						char tmp = s2[j];
						s2[j] = s2[p];
						s2[p] = tmp;
						//cout << "s1: " << s2 << "\n";
						if (s.find(s2) == s.end()) {
							s.insert(s2);
							q.push(s2);
							if (t == k) {
								//cout << answer << "\n";
								answer = max(answer, stoi(s2));
							}

						}
						
					}
				}

}
			}

		}
	}


int main(void) {

	cin >> n >> k;
	str = to_string(n);
	if (str.length() == 1) {
		cout << "-1";
	}
	else if(str.length()==2) {
		if (str[1] == '0') {
			cout << "-1";
		}
		else {
			bfs();
			cout << answer;
		}
		
	}
	else {
		bfs();
		cout << answer;
	}


	

}
