#include <string>
#include <vector>
#include <queue>
#include <iostream>


using namespace std;

int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };
long long mini = 500 * 25 * 25 + 100 * 25 * 25;

int n;
// 0:-> 1: <- 2: 위 3: 아래
//100원 500원
long long map[26][26];
int check[26][26];

void init() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			map[i][j] = -1;
		}
	}
}

void bfs(int x, int y, int dist, vector<vector<int>> board) {
	queue < pair<pair<int, int>, pair<int, long long>>>q; //방향
	q.push(make_pair(make_pair(x, y), make_pair(dist, 0)));
	map[x][y] = 0;
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int dist = q.front().second.first;
		long long next = q.front().second.second;

		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= 0 && nx >= 0 && nx < n && ny < n && board[nx][ny] == 0) {
				long long next1 = next;
				int coin = 100;
				if (dist == 0) {
					if (i == 1) {
						continue;
					}
					else {
						if (i == 2 || i == 3) {
							coin = 600;
							next1 += coin;
						}
						else {
							coin = 100;
							next1 += coin;
						}
					}
				}
				if (dist == 1) {
					if (i == 0) {
						continue;
					}
					else {
						if (i == 2 || i == 3) {
							coin = 600;
							next1 += coin;
						}
						else {
							coin = 100;
							next1 += coin;
						}
					}
				}
				if (dist == 2) {
					if (i == 3) {
						continue;
					}
					else {
						if (i == 0 || i == 1) {
							coin = 600;
							next1 += coin;
						}
						else {
							coin = 100;
							next1 += coin;
						}
					}
				}
				if (dist == 3) {
					if (i == 2) {
						continue;
					}
					else {
						if (i == 0 || i == 1) {
							coin = 600;
							next1 += coin;
						}
						else {
							coin = 100;
							next1 += coin;
						}
					}
				}
				if (map[nx][ny] == -1) {

					map[nx][ny] = next + coin;
					//cout << "mdf: " << map[nx][ny] << "\n";
					q.push(make_pair(make_pair(nx, ny), make_pair(i, next + coin)));
				}
				else if (next1 <= map[nx][ny]) {
					map[nx][ny] = next1;
					q.push(make_pair(make_pair(nx, ny), make_pair(i, next1)));
				}

			}
		}
	}
}

int solution(vector<vector<int>> board) {
	int answer = 0;
	n = board.size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			map[i][j] = -1;
		}

	}
	bfs(0, 0, 0, board);
	mini = map[n - 1][n - 1];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			map[i][j] = -1;
		}

	}
	bfs(0, 0, 2, board);
	if (mini > map[n - 1][n - 1]) {
		mini = map[n - 1][n - 1];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
	answer = mini;
	return answer;
}