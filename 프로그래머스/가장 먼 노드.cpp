#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector <int> v[20001];
int INF = 50001;
int d[20001];
vector <int> ans;

int solution(int n, vector<vector<int>> edge) {
	int answer = 0;
	return answer;
}

bool cmp(int a, int b) {
	return a > b;
}

void dikstra() {
	priority_queue<pair<int, int>> pq; //가중치 , 시작점
	d[1] = 0;
	pq.push(make_pair(0, 1));
	while (!pq.empty()) {
		int start = pq.top().second;
		int num = -pq.top().first;
		pq.pop();
		for (int i = 0; i < v[start].size(); i++) {
			int k = v[start][i]; //start와 연결된 노드 넘버
			if (d[k] < num) {
				continue;
			}
			if (d[k] > 1 + num) {
				d[k] = 1 + num;
				pq.push(make_pair(-d[k], k));
			}
		}
		
	}
}

int main() {
	int n = 6;
	vector<vector<int>> edge;
	edge = { {3, 6} ,{4, 3},{3, 2},{1, 3},{1, 2},{2, 4},{5, 2} };
	for (int i = 1; i <= n; i++) {
		d[i] = INF;
	}
	for (int i = 0; i < edge.size(); i++) {
		int a = edge[i][0];
		int b = edge[i][1];
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dikstra();
	for (int i = 1; i <= n; i++) {
		ans.push_back(d[i]);
	}
	sort(ans.begin(), ans.end(),cmp);
	int k = ans[0];
	int idx = 1;
	int answer = 1;
	while (true) {
		if (k != ans[idx]) {
			break;
		}
		answer++;
		idx++;
	}

	cout << answer;


}