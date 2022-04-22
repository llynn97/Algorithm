#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;
int d1[201]; //A
int d2[201]; //B
int d3[201]; //S
int INF = 987654321;
vector <pair<int,int>> v[201]; // 끝, 가중치  [시작]
int num;
int answer = 100001;


void init() {
	for (int i = 0; i <= num; i++) {
		
			d1[i] = INF;
			d2[i] = INF;
			d3[i] = INF;
		
	}
}
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
	int answer = 0;
	return answer;
}

void dikstra(int start , int d4[201]) {
	d4[start] = 0;
	priority_queue <pair<int, int>> pq; //가중치 , 시작
	pq.push(make_pair(0, start));
	while (!pq.empty()) {
		int start = pq.top().second;
		int num = -pq.top().first;
		pq.pop();

		for (int i = 0; i < v[start].size(); i++) {
			int end = v[start][i].first;
			int num2 = v[start][i].second;
			if (d4[end]<num) {
				continue;
			}
			if (num2 + num < d4[end]) {
				d4[end] = num2+ num;
				pq.push(make_pair(-(num2 + num), end));
			}
		}
	}
}

int main(void) {

	int n;
	int s;
	int a;
	int b;
	vector<vector<int>> fares;
	n = 7;
	num = 7;
	s = 3;
	a = 4;
	b = 1;
	fares = { {5, 7, 9} ,{4, 6, 4},{3, 6, 1},{3, 2, 3},{2, 1, 6} };
	for (int i = 0; i < fares.size(); i++) {
		int m1 = fares[i][0];
		int m2 = fares[i][1];
		int m3 = fares[i][2];
		v[m1].push_back(make_pair(m2, m3));
		v[m2].push_back(make_pair(m1, m3));
	}
	for (int i = 0; i < v[6].size(); i++) {
		cout << v[6][i].first << " ";
	}
	cout << "\n";
	init();
	dikstra(a, d1);
	dikstra(b, d2);
	dikstra(s, d3);
	for (int i = 1; i <= n; i++) {
		cout << d1[i] << " ";
	}
	cout << "\n";
	for (int i = 1; i <= n; i++) {
		cout << d2[i] << " ";
	}
	cout << "\n";
	for (int i = 1; i <= n; i++) {
		cout << d3[i] << " ";
	}
	cout << "\n";
	answer = 987654321;
	for (int i = 1; i <= n; i++) {
		if (d1[i] == 987654321 || d2[i] == 987654321 || d3[i] == 987654321) {
			continue;
		}
		int num4 = d1[i] + d2[i] + d3[i];
		if (num4 < answer) {
			answer = num4;
		}
		
		
		
	}

	cout << answer;
}