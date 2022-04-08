#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>

using namespace std;

int n;
int map[21][21];
int sharkx;
int sharky;
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };
int sharkSize = 2;
int d[21][21];
int ans = 0;
int fish = 0;
bool check[21][21];
vector <pair<int, pair<int, int >>> v2; //물고기 있는 칸까지 가는게 걸린 시간
vector <pair<int, int>> v; //물고기 있는 칸 행,열

bool checkFish() {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 0 || map[i][j] >= sharkSize) {
				cnt++;
			}
		}
	}
	if (cnt == n * n) {
		return true;
	}
	
		return false;
	
	
}

void fishWhere() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] >= 1 && map[i][j] <= 6) {
				if (sharkSize > map[i][j] && map[i][j] != 0) {
					v.push_back(make_pair(i, j));
				}
			}
		}
	}
}

void init() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			check[i][j] = false;
			d[i][j] = 0;
		}
	}
}

bool cmp(pair<int, pair<int, int >> a, pair<int, pair<int, int >> b) {
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

void bfs(int x, int y) {
	queue <pair<int, int>> q;
	q.push(make_pair(x, y));
	check[x][y] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
				if (map[nx][ny] <= sharkSize && !check[nx][ny]) {
					check[nx][ny] = true;
					d[nx][ny] = d[x][y] + 1;
					q.push(make_pair(nx, ny));
				}
			}

		}
	}
}
int main(void) {

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				sharkx = i;
				sharky = j;
			}

		}
	}
	map[sharkx][sharky] = 0;
	int jx = sharkx;
	int jy = sharky;

	while (true) {
		if (checkFish()) {  //더이상 먹을 물고기가 없으면
			break;
		}

		fishWhere();
	/*	for (int i = 0; i < v.size(); i++) {
			cout << "v: " << v[i].first << " " << v[i].second << "\n";
		}*/
		init();
		bfs(jx, jy);

		/*cout << "d[]=============\n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << d[i][j] << " ";
			}
			cout << "\n";
		}
		cout << "=======================\n";*/
		for (int i = 0; i < v.size(); i++) {
			int num = d[v[i].first][v[i].second];
			if (num != 0) {
				v2.push_back(make_pair(num, make_pair(v[i].first, v[i].second)));
			}

		}
		if (v2.size() == 0) {
			break;
		}
		sort(v2.begin(), v2.end(), cmp);
		jx = v2[0].second.first;
		jy = v2[0].second.second;
		/*for (int i = 0; i < v2.size(); i++) {
			cout << "v2: " << v2[i].first << " " << v2[i].second.first << " " << v2[i].second.second << "\n";
		}*/

		ans += v2[0].first;
		fish++;
		map[jx][jy] = 0;
		if (sharkSize == fish) {
			sharkSize += 1;
			fish = 0;
		}
		/*for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << map[i][j] << " ";
			}
			cout << "\n";

		}
		cout << "========================\n";*/
		v2.clear();
		v.clear();

	}

	cout << ans;

}