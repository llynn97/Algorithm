#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>


using namespace std;

char chess[8][8]; //진짜 체스
char chess2[8][8];
bool check[8][8];
int dy[9] = { 0,1,0,-1,0,1,-1,-1,1 };
int dx[9] = { 1,0,-1,0,0,-1,1,-1,1 };

void moveWall() {
	vector <char> v;
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 8; j++) {
			chess2[i + 1][j] = chess[i][j];
		}
	}
	for (int i = 0; i < 8; i++) {
		chess2[0][i] = '.';
	}
}

void copy() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			chess[i][j] = chess2[i][j];
		}
	}
}

bool bfs(int x, int y) {
	queue <pair<int, int>> q;
	q.push(make_pair(x, y));
	//check[x][y] = true;
	
	while (!q.empty()) {
		int x = q.front().second;
		int y = q.front().first;
		q.pop();
		if (y == 0 && x == 7) {
			return true;
		}
		moveWall();
		for (int i = 0; i < 9; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (nx >= 0 && ny >= 0 && nx < 8 && nx < 8 && chess[ny][nx]=='.'&&!check[ny][nx]) {
				if (chess2[ny][nx] == '.') {
					check[ny][nx] = true;
					q.push(make_pair(ny, nx));
				}
			}
		}
		copy();
	}
	return false;

}



int main() {
	string s;
	for (int i = 0; i < 8; i++) {
		cin >> s;
		for (int j = 0; j < 8; j++) {
			chess[i][j] = s[j];
		}
	}
	if (bfs(7, 0)) {
		cout << "1";
	}
	else {
		cout << "0";
	}
	
}