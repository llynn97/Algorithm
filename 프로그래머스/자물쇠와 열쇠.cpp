#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
vector<vector<int>> key;
vector<vector<int>> lock;
int map[61][61];
int tmp[22][22];
int map2[61][61];
int young = 0;

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	bool answer = true;
	return answer;
}

int check(int m, int mapsize) {
	int cnt = 0;
	for (int k = m - 1; k <= mapsize - m; k++) {
		for (int p = m - 1; p <= mapsize - m; p++) {
			if (map[k][p] == 1 && map2[k][p] == 1) {
				return -1;
			}
			if (map[k][p] == 0 && map2[k][p] == 0) {
				return -1;
			}
			if (map[k][p] == 0 && map2[k][p] == 1) {
				cnt++;
			}
		}

	}
	return cnt;
}

int main(void) {
	key = { {0, 0, 0} ,{1, 0, 0},{0, 1, 1} };
    lock = { {1, 1, 1} ,{1, 1, 0},{1, 0, 1} };
	int m = key.size();
	int n = lock.size();
	int mapsize = n + 2*m - 2;

	for (int i = 0; i < mapsize; i++) {
		for (int j = 0; j < mapsize; j++) {
			map[i][j] = 2;
		}
	}
	int nx = 0;
	int ny = 0;
	
	for (int i = m - 1; i <= mapsize - m; i++ ,nx++) {
		for (int j = m - 1; j <= mapsize - m; j++, ny++) {
			map[i][j] = lock[nx][ny];
			if (map[i][j] == 0) {
				young++;
			}
		}
		ny = 0;
	}
	/*for (int i = 0; i < mapsize; i++) {
		for (int j = 0; j < mapsize; j++) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}*/

	for (int r = 0; r < 4; r++) {
		
		for (int i = 0; i < n + m - 1; i++) {
			for (int j = 0; j < n + m - 1; j++) {
				for (int k = 0; k < mapsize; k++) {
					for (int p = 0; p < mapsize; p++) {
						map2[k][p] = 2;
					}
				}
				for (int k = 0; k < key.size(); k++) {
					for (int p = 0; p < key.size(); p++) {
						map2[k+i][p+j] = key[k][p];
					}
				}
				/*for (int k = 0; k < mapsize; k++) {
					for (int p = 0; p < mapsize; p++) {
						cout<< map2[k][p]<<" ";
					}
					cout << "\n";
				}
				cout << "---------------------\n";*/
				
				int cnt = 0;
				int result=check(m, mapsize);
				if (result == young) {
					return true;
				}
				
			}
			
		
		}
		for (int i = 0; i < key.size(); i++) {
			for (int j = 0; j < key.size(); j++) {
				tmp[i][j] = key[m - 1 - j][i];
			}
		}
		for (int i = 0; i < key.size(); i++) {
			for (int j = 0; j < key.size(); j++) {
				key[i][j] = tmp[i][j];
			}
		}
	}
}
