#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <map>

using namespace std;
int num = 0; //보석 개수
set <string> m; //찾아야하는 보석
map <string, int> m2; //
vector <string> jew; //보석들
int gsize;
bool check[100001];
vector <pair<int, int>> v;
vector<int> answer;
vector<int> solution(vector<string> gems) {
	vector<int> answer;
	return answer;
}

bool comp(pair <int, int> a, pair <int, int> b)
{
	if (a.second - a.first == b.second - b.first)
		return a.first < b.first;
	return a.second - a.first < b.second - b.first;
}


int main(void) {

	vector<string> gems = { "DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA" };
	for (int i = 0; i < gems.size(); i++) {
		m.insert(gems[i]);
	

	}
	int end = 0;
	int start = 0;
	while (true) {
		if (m.size() == m2.size()) {
			v.push_back(make_pair(start, end - 1));
			if (m2[gems[start]] == start) {
				m2.erase(gems[start]);

			}
			start++;
			if (end > gems.size()) {
				break;
			}

		}
		
		else {
			if (end >= gems.size()) {
				break;
			}
			m2[gems[end]] = end;
			end++;
		}
	}
	
	

	sort(v.begin(), v.end(),comp);
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << " " << v[i].second << "\n";
	}
	answer.push_back(v[0].first + 1);
	answer.push_back(v[0].second + 1);

	
	
}