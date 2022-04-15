#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

int w, h;
char map[101][101];
int dist[101][101];
vector <pair<int, int>> people;

int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };


void bfs(int x, int y) {
	queue <pair<pair<int, int>, pair<int, int>>> q;
	dist[x][y] = 0;
	q.push(make_pair(make_pair(x, y), make_pair(4, 0)));



	while (!q.empty()) {
		int x = q.front().first.second;
		int y = q.front().first.first;
		int dir = q.front().second.first;
		int next = q.front().second.second;
		

		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny >= 0 && nx >= 0 && nx < w && ny < h && map[ny][nx] != '*') {
				int next1 = next;

				if (dir == 0) {
					if (i == 1) {
						continue;
					}
					else if (dir != i) {
						next1 += 1;

					}


				}
				if (dir == 1) {
					if (i == 0) {
						continue;
					}
					else if (dir != i) {
						next1 += 1;
					}

				}
				if (dir == 2) {
					if (i == 3) {
						continue;
					}
					else if (dir != i) {
						next1 += 1;

					}


				}
				if (dir == 3) {
					if (i == 2) {
						continue;
					}
					else if (dir != i) {
						next1 += 1;
					}


				}


				if (dist[ny][nx] >= next1) {
					dist[ny][nx] = next1;
					q.push(make_pair(make_pair(ny, nx), make_pair(i, next1)));
					//	cout << "dd: " << ny << " " << nx << " " << i << " " << next << ": " <<dir<<" "<<next1<<"\n";

				}

			}
		}
	}


}
int main(void) {
	string s;
	cin >> w >> h;

	for (int i = 0; i < h; i++) {
		cin >> s;
		for (int j = 0; j < w; j++) {
			map[i][j] = s[j];
			if (map[i][j] == 'C') {
				people.push_back(make_pair(i, j));
			}
		}
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			dist[i][j] = 10001;
		}
	}

	bfs(people[0].first, people[0].second);

	/*for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cout << dist[i][j] << " ";
		}
		cout << "\n";
	}*/

	cout << dist[people[1].first][people[1].second];
}


/*
  4 4
C.**
..**
....
...C

답: 1


4 4
C...
....
**..
**.C

답: 1

4 4
**.C
**..
....
C...

답: 1



4 4
...C
....
..**
C.**

답: 1

4 7
....
..*.
C.*.
..*C
..*.
..*.
....

답: 2

4 7
....
.*..
.*.C
C*..
.*..
.*..
....

답: 2

*/