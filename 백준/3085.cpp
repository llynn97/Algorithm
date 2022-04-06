#include <iostream>
#include <algorithm>
#include <string>
#include <vector>


using namespace std;

int n; 
char map[51][51];
char map2[51][51]; //map¿ª ∫πªÁ
int dy[4] = {1,-1,0,0};
int dx[4] = { 0,0,1,-1 };
int answer = 0;
int count2 = 1;

void copy() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			map2[i][j] = map[i][j];
		}
	}
}

void cnt() {
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			int t = j;
			while (true) {
				if (t >= n - 1 || map2[i][j]!=map2[i][t+1]) {
					break;
				}
				else {
					count2++;
					t++;
				}
			}
			answer = max(answer, count2);
			count2 = 1;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int t = j;
			while (true) {
				if (t >= n - 1 || map2[t][i] != map2[t+1][i]) {
					break;
				}
				else {
					count2++;
					t++;
				}
			}
			answer = max(answer, count2);
			count2 = 1;
		}
	}
	
}

void func(int x, int y) {
	for (int i = 0; i < 4; i++) {
		copy();
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && ny >= 0 && nx < n && ny < n && (map2[nx][ny] != map2[x][y])) {
			int tmp = map2[nx][ny];
			map2[nx][ny] = map2[x][y];
			map2[x][y] = tmp;
			/*for (int k = 0; k < n; k++) {
				for(int p = 0; p < n; p++) {
					cout << map2[k][p];
				}
				cout << "\n";
			}
			cout << "--------------\n";*/
			cnt();
			
			
			
		}
	}
}

int main(void) {

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			func(i, j);
		}
	}

	cout << answer;

}