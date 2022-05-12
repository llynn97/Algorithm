#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;


char ch[7] = { '|','-','+','1','2','3','4' };
int r, c;
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };
char map[26][26];
char map2[26][26];
bool check[26][26];
int mx, my, zx, zy;
int ans = 0;
int cnt = 0;
bool check6 = false;
void copy() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			map2[i][j] = map[i][j];
		}
	}
}
void init() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			check[i][j] = false;
		}
	}
}

int bfs(char map3[26][26]) {
	queue <pair<pair<int, int>, pair<int,int>> >q;
	//q.push(make_pair(make_pair(mx, my),-1));

	check[mx][my] = true;
	for (int i = 0; i < 4; i++) {
		int ny = mx + dy[i];
		int nx = my + dx[i];
		if (ny >= 0 && nx >= 0 && ny < r && nx < c) {
			if (map3[ny][nx] != '.') {
				q.push(make_pair(make_pair(ny, nx), make_pair(i,0)));
				check[ny][nx] = true;
				check6 = true;
				break;

			}
		}
	}
	if (!check6) {
		return -1;
	}
	check6 = false;

	while (!q.empty()) {
		int x = q.front().first.second;
		int y = q.front().first.first;
		int dir = q.front().second.first;
		int num6 = q.front().second.second;
		//cout << "dd: " << y << " " << x << " " << dir<<"\n";
		if (map3[y][x] == 'Z') {
			check6 = true;
			//cout << "z¸¸³µÀ½============\n";
			return num6;

		}
		int ny = y;
		int nx = x;
		q.pop();
		bool check7 = false;
		if (map3[y][x] == '|') {
			if (dir == 1 || dir == 0) {
				check7 = true;
			}
			if (dir == 2) {
				ny += 1;
				dir = 2;
			}
			if (dir == 3) {
				ny -= 1;
				dir = 3;
			}


		}
		if (map3[y][x] == '-') {
			if (dir == 2 || dir == 3) {
				check7 = true;
			}
			if (dir == 0) {
				nx += 1;
				dir = 0;
			}
			if (dir == 1) {
				nx -= 1;
				dir = 1;
			}


		}
		if (map3[y][x] == '1') {
			if (dir == 2 || dir == 0) {
				check7 = true;
			}
			if (dir == 1) {

				ny += 1;
				dir = 2;
			}
			if (dir == 3) {

				nx += 1;
				dir = 0;
			}



		}
		if (map3[y][x] == '2') {
			if (dir == 3 || dir == 0) {
				check7 = true;
			}
			if (dir == 2) {

				nx += 1;
				dir = 0;
			}
			if (dir == 1) {

				ny -= 1;
				dir = 3;
			}
		}
		if (map3[y][x] == '3') {
			if (dir == 1 || dir == 3) {
				check7 = true;
			}
			if (dir == 0) {

				ny -= 1;
				dir = 3;
			}
			if (dir == 2) {

				nx -= 1;
				dir = 1;
			}


		}
		if (map3[y][x] == '4') {
			if (dir == 2 || dir == 1) {
				check7 = true;
			}
			if (dir == 0) {

				ny += 1;
				dir = 2;

			}
			if (dir == 3) {

				nx -= 1;
				dir = 1;
			}
		}
		if (map3[y][x] == '+') {
			if (dir == 3) {
				ny -= 1;
				dir = 3;
			}
			if (dir == 2) {
				ny += 1;
				dir = 2;
			}
			if (dir == 1) {
				nx -= 1;
				dir = 1;
			}
			if (dir == 0) {
				nx += 1;
				dir = 0;
			}
		}
		if (ny >= 0 && nx >= 0 && ny < r && nx < c) {
			if (!check7 && map3[ny][nx] != '.') {
				check[ny][nx] = true;
				q.push(make_pair(make_pair(ny, nx), make_pair(dir,num6+1)));
			}
		}


	}
	return -1;

}


int main(void) {
	string str = "";
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		cin >> str;
		for (int j = 0; j < c; j++) {
			map[i][j] = str[j];
			if (map[i][j] == 'M') {
				mx = i;
				my = j;
			}
			else if (map[i][j] == 'Z') {
				zx = i;
				zy = j;
			}
			else if (map[i][j] != '.') {
				cnt++;
			}
		}
	}

	//	cout << mx << " " << my << " " << zx << " " << zy << "\n";
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j] == '.') {

				for (int k = 0; k < 7; k++) {
					check6 = false;
					init();
					copy();
					map2[i][j] = ch[k];
					//cout << "zzzzzzzz\n";
					/*for (int p = 0; p < r; p++) {
						for (int v = 0; v < c; v++) {
							cout << map2[p][v];
						}
						cout << "\n";
					}*/
					//	cout<<"---------------------\n";
					int ss = bfs(map2);
					if (ss!=-1 && cnt==ss) {
						cout << i + 1 << " " << j + 1 << " " << ch[k];
						return 0;
					}
					//cout << "-----------------------\n";
				}
			}
		}
	}

	return 0;
}