#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>


using namespace std;

int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };

int r, c;
char map[1501][1501];
bool check[1501][1501];
queue < pair<int, int>> q;
queue <pair<int, int>> q2;
queue <pair<int, int>> q1;
queue <pair<int, int>> nq;

vector <pair<int, int>> v;
int xL1, yL1  = 0;
int xL2, yL2 = 0;
bool finded = false;
int answer = 0;

void ice() {
	
	while (!q2.empty()) {
		int i = q2.front().first;
		int j = q2.front().second;
		q2.pop();
		for (int k = 0; k < 4; k++) {
			int nx = i + dx[k];
			int ny = j + dy[k];
			if (nx >= 0 && ny >= 0 && nx < r && ny < c) {
				if (map[nx][ny] == 'X') {
					map[nx][ny] = '.';
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
	
	
}


void bfs() {
	
	
	
	while (!q1.empty()) {
		int x = q1.front().second;
		int y = q1.front().first;
		q1.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= 0 && nx >= 0 && ny < r && nx < c) {
				if (!check[ny][nx]) {
					if (map[ny][nx] == '.') {
						
							check[ny][nx] = true;
							q1.push(make_pair(ny, nx));
						

					}
					else if (map[ny][nx] == 'L' ) {
						finded = true;
						break;
					}
					else if (map[ny][nx] == 'X') {
						check[ny][nx] = true;
						nq.push(make_pair(ny, nx));

					}
				}
				
			}
		}
	}

}

int main(void) {
	string s;
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		cin >> s;
		for (int j = 0; j <c; j++) {
			map[i][j] = s[j];
			if (s[j] == 'L') {
				v.push_back(make_pair(i, j));
			}
			if (s[j] != 'X') {
				q2.push(make_pair(i, j));
			}
			
		}
	}

	xL1 = v[0].first;
	yL1 = v[0].second;
	xL2 = v[1].first;
	yL2 = v[1].second;
	check[xL1][yL1] = true;
	q1.push(make_pair(xL1, yL1));

	while (!finded) {
		bfs();
		if (finded) {
			break;
			
		}
		ice();
		q1 = nq;
		q2 = q;
		while (!nq.empty()) {
			nq.pop();
		}
		while (!q.empty()) {
			q.pop();
		}
		
		answer++;


	}
	cout << answer;
	


}