#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;
int n;
char map[51][51];
int doorx;
int doory;
int check[51][51][4];
int dy[4] = { 0,1,0,-1 };
int dx[4] = { -1,0,1,0 };
vector <pair<int, int>> v;
void init() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < 4; k++) {
				check[i][j][k] = -1;
			}
		}
	}
}

void bfs(int x, int y) {
	queue < pair<int, pair<int, int>>> q;
	for (int i = 0; i < 4; i++) {
		check[x][y][i] = 0;
	}
	
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && ny >= 0 && nx < n && ny < n && map[ny][nx] != '*') {

			int dir = i;
			q.push(make_pair(dir, make_pair(ny, nx)));
			check[ny][nx][i] = 0;


		}

	}
	
	while (!q.empty()) {
		int x = q.front().second.second;
		int y = q.front().second.first;
		int dir = q.front().first;
		q.pop();
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx >= 0 && ny >= 0 && nx < n && ny < n && map[ny][nx] != '*') {
			if (map[ny][nx] == '!') {
				if (check[ny][nx][dir] == -1) {
					check[ny][nx][dir] = check[y][x][dir];
					q.push(make_pair(dir, make_pair(ny, nx)));
				}
				else {
					if (check[ny][nx][dir] >= check[y][x][dir]) {
						check[ny][nx][dir] = check[y][x][dir];
						q.push(make_pair(dir, make_pair(ny, nx)));
						
					}
				}
			

				
			}
			int dir2;
			dir2 = (dir + 1) % 4;
			if (nx >= 0 && ny >= 0 && nx < n && ny < n && map[ny][nx] != '*') {
				if (check[ny][nx][dir2] == -1) {
					check[ny][nx][dir2] = check[y][x][dir]+1;
					q.push(make_pair(dir2, make_pair(ny, nx)));
				}
				else {
					if (check[ny][nx][dir2] >= check[y][x][dir] + 1) {
						check[ny][nx][dir2] = check[y][x][dir] + 1;
						q.push(make_pair(dir2, make_pair(ny, nx)));
					}
				}
			}
			dir2 = (dir + 3) % 4;
			if (nx >= 0 && ny >= 0 && nx < n && ny < n && map[ny][nx] != '*') {
				if (check[ny][nx][dir2] == -1) {
					check[ny][nx][dir2] = check[y][x][dir] + 1;
					q.push(make_pair(dir2, make_pair(ny, nx)));
				}
				else {
					if (check[ny][nx][dir2] >= check[y][x][dir] + 1) {
						check[ny][nx][dir2] = check[y][x][dir] + 1;
						q.push(make_pair(dir2, make_pair(ny, nx)));
					}
				}
			}

		}
		else if (map[ny][nx] == '.' || map[ny][nx] == '#') {
			if (check[ny][nx][dir] == -1) {
				check[ny][nx][dir] = check[y][x][dir];
			}
			else if (check[ny][nx][dir] >= check[y][x][dir]) {
				check[ny][nx][dir] = check[y][x][dir];
				q.push(make_pair(dir, make_pair(ny, nx)));

			}
		}
		
			
			
	
		

		
		
	}
	

}

int main(void) {
	string s;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < n; j++) {
			map[i][j] = s[j];
			if (map[i][j] == '#') {
				v.push_back(make_pair(i, j));
			}
		}
	}
	doorx = v[0].first;
	doory = v[0].second;
	map[doorx][doory] = '*';
	init();
	bfs(doorx, doory);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << check[i][j][2] << " ";
		}
		cout << "\n";
	}
	for (int i = 0; i < 4; i++) {
		cout << check[v[1].first][v[1].second][i] << " ";
	}
}