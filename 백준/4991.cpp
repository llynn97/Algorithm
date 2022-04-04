#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;
int w, h;
char map[21][21];
bool check[21][21];
int dist[21][21];
int dist2[21][21];
vector <int> order;
int starti = 0;
int startj = 0;
int dirt;
vector <pair<int, int>> dirt1;
int ans = 0;
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };

void init() {

	for (int i = 0; i < 21; i++) {
		for (int j = 0; j < 21; j++) {
			check[i][j] = false;
		}
	}
	for (int i = 0; i < 21; i++) {
		for (int j = 0; j < 21; j++) {
			dist[i][j] = 0;
			
		}
	}
	

}

void init2() {
	for (int i = 0; i < 21; i++) {
		for (int j = 0; j < 21; j++) {
			
			dist2[i][j] = 0;
		}
	}
	order.clear();
	

	dirt1.clear();
}

int bfs(int x, int y, int fx, int fy) {
	queue<pair<int, int>> q;
	check[x][y] = true;
	q.push(make_pair(x, y));
	while (!q.empty()) {
		int x = q.front().second;
		int y = q.front().first;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (nx >= 0 && ny >= 0 && nx < w && ny < h && !check[ny][nx]) {
				if (map[ny][nx] == '.' || map[ny][nx] == '*' || map[ny][nx] == 'o') {
					dist[ny][nx] = dist[y][x] + 1;
					check[ny][nx] = true;
					q.push(make_pair(ny, nx));
				}

			}
		}
	
	}
	return dist[fx][fy];
	

}

int main(void) {
	string s;
	
	
	
	while (true) {
		cin >> w >> h;
		if (w == 0 && h == 0) {
			break;
		}
		
		init2();
		int answer = 100000;
		dirt = 0;

		for (int i = 0; i < h; i++) {
			cin >> s;
			for (int j = 0; j < w; j++) {
				map[i][j] = s[j];
				if (map[i][j] == 'o') {
					starti = i;
					startj = j;
				}
				if (map[i][j] == '*') {
					dirt++;
					dirt1.push_back(make_pair(i, j));
				}
			}

		}


		order.push_back(0); //·Îº¿Ä­ orderÀ» 0À¸·Î ÀâÀ½
		for (int i = 1; i <= dirt1.size(); i++) {
			order.push_back(i);
		}


		dist2[0][0] = 0;
		for (int i = 1; i < order.size(); i++) {
			init();
			dist2[0][i] = bfs(starti, startj, dirt1[i - 1].first, dirt1[i - 1].second);
		}
		for (int i = 1; i < order.size(); i++) {
			for (int j = 0; j < order.size(); j++) {
				init();
				if (i == j) {
					dist2[i][j] = 0;
				}
				else if (j == 0) {
					dist2[i][j] = bfs(dirt1[i - 1].first, dirt1[i - 1].second, starti, startj);
				}
				else {
					dist2[i][j] = bfs(dirt1[i - 1].first, dirt1[i - 1].second, dirt1[j - 1].first, dirt1[j - 1].second);
				}

			}
		}

		vector <int> order2;
		int idx = 0;
		ans = 0;
		for (int i = 1; i < order.size(); i++) {
			order2.push_back(order[i]);
		}
		bool check = false;

		for (int i = 0; i < order2.size(); i++) {
			if (dist2[idx][order2[i]] != 0) {
				ans += dist2[idx][order2[i]];

				idx = order2[i];
			}
			else {
				check = true;
			}
		}
		if (!check) {
			answer = min(answer, ans);
		}

		while (next_permutation(order2.begin(), order2.end())) {
			idx = 0;
			ans = 0;
			bool check = false;


			for (int i = 0; i < order2.size(); i++) {
				if (dist2[idx][order2[i]] != 0) {
					ans += dist2[idx][order2[i]];

					idx = order2[i];
				}
				else {
					check = true;
				}
			}
			
			if (!check) {
				answer = min(answer, ans);
			}
		}
		if (answer == 100000) {
			cout << "-1"<<"\n";
		}
		else {
			cout << answer<<"\n";
		}
	}

}