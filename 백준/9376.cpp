#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int tc;
int h, w;
int m;
char map[102][102];
bool check[102][102];
vector <int> v;
vector <pair<int, int>> sins; //ÁË¼ö ÁÂÇ¥

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int dist[102][102][3]; // 0: ÁË¼ö1 1: ÁË¼ö2 3: t: »ó±ÙÀÌ ÁÂÇ¥±îÁö¿¬ ¹® ¿¬ È½¼ö
int ans = 0;






void init() {
	for (int i = 0; i <= h+1; i++) {
		for (int j = 0; j <= w+1;  j++ ) {
			check[i][j] = false;
		}
	}
}

void init2() {
	for (int i = 0; i <= h + 1; i++) {
		for (int j = 0; j <= w + 1; j++) {
			dist[i][j][0] = -1;
			dist[i][j][1] = -1;
			dist[i][j][2] = -1;
		}
	}
}



void bfs(int x, int y,int k) { //ÁË¼ö°¡ Å»ÃâÇÒ¼ö ÀÖ´ÂÁö È®ÀÎ
	deque<pair<int, int>> q;
	check[x][y] = true;
	dist[x][y][k] = 0;
	q.push_back(make_pair(x, y));
	while (!q.empty()) {
		int x = q.front().second;
		int y = q.front().first;
		q.pop_front();
		
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= 0 && nx >= 0 && ny <= h+1 && nx <=w+1) {
				if (!check[ny][nx] && map[ny][nx]!='*') {
					check[ny][nx] = true;
					if (map[ny][nx] == '#') {
						dist[ny][nx][k] = dist[y][x][k] + 1;
						q.push_back(make_pair(ny, nx));
					}
					else if(map[ny][nx]=='.') {
						dist[ny][nx][k] = dist[y][x][k];
						q.push_front(make_pair(ny, nx));
					}
					

				}
			}
		}
	}
	
}



int main(void) {
	string s;

	
	cin >> tc;
	while (tc--) {
		cin >> h >> w;
		ans = 987654321;
		sins.clear();
		init2();
		for (int i = 0; i < h; i++) {
			cin >> s;
			for (int j = 0; j < w; j++) {
				map[i + 1][j + 1] = s[j];
				if (map[i + 1][j + 1] == '$') {
					sins.push_back(make_pair(i + 1, j + 1));
					map[i + 1][j + 1] = '.';
				}

			}
		}
		for (int i = 0; i <= w + 1; i++) {
			map[0][i] = '.';

		}
		for (int i = 0; i <= w + 1; i++) {
			map[h + 1][i] = '.';
		}
		for (int i = 0; i <= h + 1; i++) {
			map[i][0] = '.';
		}
		for (int i = 0; i <= h + 1; i++) {
			map[i][w + 1] = '.';
		}
		init();
		bfs(sins[0].first, sins[0].second, 0);
		init();
		bfs(sins[1].first, sins[1].second, 1);
		init();
		bfs(0, 0, 2);

		/*for (int i = 0; i <= h+1; i++) {
			for (int j = 0; j <= w+1; j++) {
				cout << dist[i][j][0]<<" ";
			}
			cout << "\n";
		}
		cout << "========================\n";
		for (int i = 0; i <= h+1; i++) {
			for (int j = 0; j <= w+1; j++) {
				cout << dist[i][j][1]<<" ";
			}
			cout << "\n";
		}
		cout << "========================\n";
		for (int i = 0; i <= h+1; i++) {
			for (int j = 0; j <= w+1; j++) {
				cout << dist[i][j][2]<<" ";
			}
			cout << "\n";
		}
		cout << "========================\n";*/

		for (int i = 0; i <= h+1; i++) {
			for (int j = 0; j <= w+1; j++) {
				if (map[i][j] != '*' && dist[i][j][0]!=-1 && dist[i][j][1]!=-1 && dist[i][j][2]!=-1) {
					int num = dist[i][j][0] + dist[i][j][1] + dist[i][j][2];
					if (map[i][j] == '#') {
						num -= 2;
					}
					
						ans = min(ans, num);
					
					
				}

			}
		}
	
		
		
		cout << ans << "\n";
	}
	

}