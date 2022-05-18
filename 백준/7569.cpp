#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, h;
int map[101][101][101];
int check[101][101][101];

int dy[] = { 1,0,-1,0,0,0 };
int dx[] = { 0,1,0,-1,0,0 };
int dz[] = { 0,0,0,0,1,-1 };
//queue <pair<pair<int,int>,int>> q;

/*int bfs(){


	while(!q.empty()){
		int x=q.front().first.first;
		int y=q.front().first.second;
		int z=q.front().second;
		q.pop();
		for(int i=0; i<6; i++){
			int ny=y+dy[i];
			int nx=x+dx[i];
			int nz=z+dz[i];
			if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if(nz < 0 || nz >= h) continue;
			 if(map[nx][ny][nz] == 0 && check[nx][ny][nz] == -1) {
				q.push(make_pair(make_pair(nx,ny),nz));
				check[nx][ny][nz] = check[x][y][z] + 1;
			}


			if(map[nx][ny][nz]==0&&check[nx][ny][nz]==-1){
				if(ny>=0&&nx>=0&&nz>=0&&nx<n&&ny<m&&nz<h){
					check[nx][ny][nz]=check[x][y][z]+1;
					map[ny][nx][nz]=1;
					q.push(make_pair(make_pair(nx,ny),nz));
				}


			}



		}

	}
}*/


int main() {
	cin >> m >> n >> h;
	int ans = 0;
	queue <pair<pair<int, int>, int>> q;

	int num = 0; // 저 장 될 때 익 어 있 는 상 태 확 인
	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> map[i][j][k];
				check[i][j][k] = -1;
				if (map[i][j][k] == 1) {
					q.push(make_pair(make_pair(i, j), k));
					check[i][j][k] = 0;
				}

			}
		}
	}
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int z = q.front().second;
		q.pop();
		for (int i = 0; i < 6; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			int nz = z + dz[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (nz < 0 || nz >= h) continue;
			if (map[nx][ny][nz] == 0 && check[nx][ny][nz] == -1) {
				q.push(make_pair(make_pair(nx, ny), nz));
				check[nx][ny][nz] = check[x][y][z] + 1;
				map[nx][ny][nz] = 1;
			}
		}
	}

	//bfs();
	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j][k] == 0 && check[i][j][k] == -1) {
					ans = -1;
					break;


				}
				if (check[i][j][k] > ans) {
					ans = check[i][j][k];
				}

			}
			if (ans == -1) {
				break;
			}
		}
		if (ans == -1) {
			break;
		}
	}

	cout << ans;




	/*	for(int k=0; k<h; k++){
		  for(int i=0; i<n; i++){
			  for(int j=0; j<m; j++){
				  cout<<map[i][j][k]<<" ";
			  }
			  cout<<"\n";

		  }
		  cout<<"\n";
	  }*/
	return 0;
}