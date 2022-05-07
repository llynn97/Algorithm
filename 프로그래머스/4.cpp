#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <queue>

using namespace std;
vector<pair<int, int>> v[50001]; //끝점 , 가중치, [시작점]
map <string, int> m1; //출입구
map<string, int> m2; //산봉우리
vector <int> v2;
bool check[50001];
int maxNum = 100001;
int ans1 = 100001; //
int ans2 = 50001;
int ans4 = 100001;

vector < int> v5;



vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
	vector<int> answer;
	return answer;
}

void init(int n) {
	for (int i = 0; i <= n; i++) {
		check[i] = false;
	}
}

void dfs(int summ,int num,int dist2) {
	if (num == summ) {
		maxNum =min(maxNum, dist2);
		if (ans4 > maxNum) {
			ans4 = maxNum;
		}
		cout << "dd: " << maxNum << "\n";
		return;
	}
	for (int i = 0; i < v[num].size(); i++) {
		int num4 = v[num][i].first;
		int dist = v[num][i].second;

		if (!check[num4] && m1.find(to_string(num4)) == m1.end()) {
			if (m2.find(to_string(num4)) == m2.end()) {
				cout << "num4 : " << num4 << " " << dist << "\n";
				check[num4] = true;
				dist2 = max(dist, dist2);
				dfs(summ, num4,dist2);
				check[num4] = false;
			}
			else {
				if (num4 == summ) {
					check[num4] = true;
					dist2 = max(dist, dist2);
					dfs(summ, num4, dist2);
					check[num4] = false;
				}
			}
		}
	}

}
int main(void) {
	int n = 6;
	vector<vector<int>> path = { {1, 2, 3} ,{2, 3, 5},{2, 4, 2},{2, 5, 4},{3, 4, 4},{4, 5, 3},{4, 6, 1},{5, 6, 1} };
	
	vector<int> gates = { 1,3 };
	vector<int> summits = { 5 };
	for (int i = 0; i < gates.size(); i++) {
		m1[to_string(gates[i])] = 1;
	}
	for (int i = 0; i < summits.size(); i++) {
		m2[to_string(summits[i])] = 1;
	}
	for (int i = 0; i < path.size(); i++) {
		v[path[i][0]].push_back(make_pair(path[i][1], path[i][2]));
		v[path[i][1]].push_back(make_pair(path[i][0], path[i][2]));

	}
	for (int i = 0; i < gates.size(); i++) {
		int start = gates[i];
		
		for (int j = 0; j < summits.size(); j++) {
			int maxNum = -1;
			int summ = summits[j];
			init(n);
			check[start] = true;
			dfs(summ, start,-1);
			
			
			

			if (ans4 != -1) {
				cout << "dff: " << maxNum << " " << summ << "\n";

				if (ans4 == ans1) {
					if (ans2 > summ) {
						ans2 = summ;
					}
				}
				else if (ans4 > ans1) {
					ans1 = ans4;
					ans2 = summ;
				}
			}
		}
	}

	cout << ans1 << " " << ans2;

}