#include <iostream>

#include <vector>

#include <cstring>

#include <queue>

using namespace std;

int dy[4] = { 0,0,1,-1 };

int dx[4] = { 1,-1,0,0 };
int r, c, t;
int map[1000][1000];
int ans[1000][1000];
int change[1000][1000];

void go() {

	queue <pair<int, int>> v;

	memset(ans, 0, sizeof(ans));

	for (int i = 0; i < r; i++) {

		for (int j = 0; j < c; j++) {

			if (map[i][j] > 0) {

				v.push(make_pair(i, j));

			}

		}

	}

	while (!v.empty()) {

		int cnt = 0;

		int x = v.front().first;

		int y = v.front().second;



		v.pop();



		for (int j = 0; j < 4; j++) {

			int ny = y + dy[j];

			int nx = x + dx[j];

			if (ny >= 0 && nx >= 0 && nx < r && ny < c) {

				if (map[nx][ny] != -1) {

					cnt++;

					//map[ny][nx] = map[ny][nx] + map[y][x] / 5;

					ans[nx][ny] = map[x][y] / 5 + ans[nx][ny];

				}

			}

		}

		map[x][y] = map[x][y] - (map[x][y] / 5) * cnt;



	}

	for (int i = 0; i < r; i++) {

		for (int j = 0; j < c; j++) {

			map[i][j] = map[i][j] + ans[i][j];

		}

	}



}





int main() {

	int sum = 0;
	int s1, s2;
	int k = 0;
	int x1, x2, y1, y2;
	queue <pair<int, int>> da;

	cin >> r >> c >> t;

	for (int i = 0; i < r; i++) {

		for (int j = 0; j < c; j++) {

			cin >> map[i][j];
			if (k == 0 & map[i][j] == -1) {
				s1 = i;
				s2 = j;
				k = 1;
			}


		}

	}
	x1 = s1;
	y1 = s2;
	x2 = x1 + 1;
	y1 = s2;
	int temp;
	for (int j = 0; j < t; j++) {
		memset(change, 0, sizeof(change));
		go();
		for (int i = 1; i < c; i++) {
			if (i == 1) {
				change[x1][i] = 0;
				da.push(make_pair(x1, i));
			}
			else {



				change[x1][i] = map[x1][i - 1];
				da.push(make_pair(x1, i));
			}
		}
		for (int i = x1 - 1; i >= 0; i--) {
			change[i][c - 1] = map[i + 1][c - 1];
			da.push(make_pair(i, c - 1));
		}
		for (int i = c - 2; i >= 0; i--) {
			change[0][i] = map[0][i + 1];
			da.push(make_pair(0, i));
		}
		for (int i = 1; i <= x1; i++) {
			if (map[i][0] == -1) {
				change[i][0] = -1;
				da.push(make_pair(i, 0));
			}
			else {
				change[i][0] = map[i - 1][0];
				da.push(make_pair(i, 0));
			}
		}
		for (int i = 1; i < c; i++) {
			if (i == 1) {
				change[x2][i] = 0;
				da.push(make_pair(x2, i));
			}
			else {
				change[x2][i] = map[x2][i - 1];
				da.push(make_pair(x2, i));
			}

		}
		for (int i = x2 + 1; i < r; i++) {
			change[i][c - 1] = map[i - 1][c - 1];
			da.push(make_pair(i, c - 1));
		}
		for (int i = c - 2; i >= 0; i--) {
			change[r - 1][i] = map[r - 1][i + 1];
			da.push(make_pair(r - 1, i));
		}
		for (int i = r - 2; i >= x2; i--) {
			if (map[i][0] == -1) {
				change[i][0] = -1;
				da.push(make_pair(i, 0));
			}
			else {
				change[i][0] = map[i + 1][0];
				da.push(make_pair(i, 0));
			}
		}
		while (!da.empty()) {
			map[da.front().first][da.front().second] = change[da.front().first][da.front().second];
			da.pop();
		}

	}












	for (int i = 0; i < r; i++) {

		for (int j = 0; j < c; j++) {

			if (map[i][j] != -1) {

				sum = sum + map[i][j];

			}

		}

	}







	cout << sum;

	return 0;

}