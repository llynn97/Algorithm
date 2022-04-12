#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

int r, c;
char map[101][101];
char map2[101][101];
int n; //던진 횟수
int high[101]; //던진 높이
int count1;
int count2;
bool check[101][101];
bool check5[101][101];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };


int check1[101][101]; //부수기전 클러스터 번호
int check2[101][101]; //부순 후 클러스터 번호

void init() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			check[i][j] = false;
			check1[i][j] = 0;
			check2[i][j] = 0;
		}
	}
}

void init2() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			check[i][j] = false;
			
		}
	}

}
void dfs(int x, int y, int cnt) {
	queue < pair<int, int>> q;
	check[x][y] = true;
	check1[x][y] = cnt;
	q.push(make_pair(x, y));
	while (!q.empty()) {
		int x = q.front().second;
		int y = q.front().first;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < c && ny < r) {
				if (!check[ny][nx] && map[ny][nx] == 'x') {
					check[ny][nx] = true;
					check1[ny][nx] = cnt;
					q.push(make_pair(ny, nx));
				}
			}
		}
	}

}

void dfs2(int x, int y, int cnt) {
	queue < pair<int, int>> q;
	check[x][y] = true;
	check2[x][y] = cnt;
	q.push(make_pair(x, y));
	while (!q.empty()) {
		int x = q.front().second;
		int y = q.front().first;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < c && ny < r) {
				if (!check[ny][nx] && map[ny][nx] == 'x') {
					check[ny][nx] = true;
					check2[ny][nx] = cnt;
					q.push(make_pair(ny, nx));
				}
			}
		}
	}

}

bool bottomCheck(int x, int y, int cnt) {
	queue < pair<int, int>> q;
	check[x][y] = true;
	q.push(make_pair(x, y));
	while (!q.empty()) {
		int x = q.front().second;
		int y = q.front().first;
		if (y == r - 1) {
			return true;
			break;
		}
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < c && ny < r) {
				if (check2[ny][nx] == cnt && !check[ny][nx]) {
					check[ny][nx] = true;

					q.push(make_pair(ny, nx));
				}
			}
		}
	}
	return false;
}
void clusterUnder(int cnt) {//클러스터 바닥으로 내리기
	int dif = 101;
	for (int i = 0; i < c; i++) {
		int idx = -1;
		int dif2 = 0;
		for (int j = 0; j < r; j++) {
			if (check2[j][i] == cnt) {
				idx = j;
			}
		}
		int idx2 = -1;
		bool check4 = false;
		if (idx != -1 && idx != r - 1) {
			for (int j = idx+1; j < r ; j++) {
				if (check2[j][i] != cnt && check2[j][i] != 0 && !check4) {
					idx2 = j-1;
					check4 = true;
				}
			}
			if (idx2 == -1) {
				dif2 = r - 1-idx;
				
			}
			else {
				dif2 = idx2 - idx;
			}
			dif = min(dif, dif2);
		}
		
		
	}
	//cout << "dif: " << dif << "\n";
	for (int i = 0; i < c; i++) {
		for (int j = r - 1; j >= 0; j--) {
			if (check2[j][i] == cnt) {

				map[j + dif][i] = 'x';
				map[j][i] = '.';
			}
		}
	}
}
int main(void) {
	cin >> r >> c;
	string s;
	for (int i = 0; i < r; i++) {
		cin >> s;
		for (int j = 0; j < c; j++) {
			map[i][j] = s[j];
		}
	}
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> high[i];
	}

	for (int t = 1; t <= n; t++) {
		int height = high[t - 1]; //던진 높이
		count1 = 0; //부수기전 클러스터 개수
		count2 = 0; //부순후 클러스터 개수
		init();
		int cnt = 1;
		for (int i = 0; i < r; i++) {  //부수기전 클러스터 번호 붙이기
			for (int j = 0; j < c; j++) {
				if (map[i][j] == 'x' && !check[i][j]) {
					
					dfs(i, j, cnt);
					cnt++;
					count1++;
				}
			}
		}
	
		bool flag = false;
		if (t % 2 != 0) { //왼쪽에서 부터 부술때
			for (int i = 0; i < c; i++) {
				if (map[r - height][i] == 'x' && !flag) {
					map[r - height][i] = '.';
					flag = true;
				}
			}
		}
		else {
			for (int i = c - 1; i >= 0; i--) {
				if (map[r - height][i] == 'x' && !flag) {
					map[r - height][i] = '.';
					flag = true;
				}
			}

		}
		cnt = 1;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				check[i][j] = false;

			}
		}
		


		for (int i = 0; i < r; i++) {  //부순 후 클러스터 번호 붙이기
			for (int j = 0; j < c; j++) {
				if (map[i][j] == 'x' && !check[i][j]) {
					dfs2(i, j, cnt);
					cnt++;
					count2++;
				}
			}
		}


		if (count1 != count2) { //클러스터 변화 시켜줘야 함
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					check5[i][j] = false;

				}
			}
			init2();
			for (int i = 1; i <= count2; i++) {
				bool ss = false;
				for (int j = 0; j < r; j++) {
					for (int k = 0; k < c; k++) {
						
						if (check2[j][k] == i && !ss) {
							bool check3 = bottomCheck(j, k, i);
							ss = true;
							//cout << "check3: " << check3 << "\n";
							if (!check3) { //클러스터가 바닥에 닿지 않으면 
								clusterUnder(i);
							}
						}
					}

				}
			}
		}
		

	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << map[i][j];
		}
		cout << "\n";
	}


}