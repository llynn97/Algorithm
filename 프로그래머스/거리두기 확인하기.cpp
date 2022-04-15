#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>



using namespace std;
vector <pair<int, int>> v;
vector <int> v3;
bool check[26];
int check3[6][6]; //의자
int check2[6][6]; //bfs 에서 체크
vector <pair<int, int>> v2; //조합 만들기
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };

void init() {
	for (int i = 0; i <= 5; i++) {
		for (int j = 0; j <= 5; j++) {
			check2[i][j] = -1;
			check3[i][j] = -1;
		}
	}
}
void init2() {
	for (int i = 0; i <= 25; i++) {
		check[i] = false;
	}
}
void dfs(int cnt) {
	if (cnt == 2) {
		v2.push_back(make_pair(v3[0], v3[1]));
		return;
	}
	for (int i = 0; i < v.size(); i++) {
		if (!check[i] && (v3.size() == 0 || v3.back() < i)) {
			check[i] = true;
			v3.push_back(i);
			dfs(cnt + 1);
			check[i] = false;
			v3.pop_back();


		}
	}
}

void bfs(int x1, int y1, vector<vector<string>> places, int n) {
	queue <pair<int, int>> q;
	check2[x1][y1] = 0;
	q.push(make_pair(x1, y1));
	while (!q.empty()) {
		int x = q.front().second;
		int y = q.front().first;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= 0 && nx >= 0 && nx < 5 && ny < 5 && check2[ny][nx] < 0) {
				if (places[n][ny][nx] == 'X') {
					check2[ny][nx] = check2[y][x] + 1;
				}
				else {
					check2[ny][nx] = check2[y][x];
				}
				q.push(make_pair(ny, nx));
			}
		}
	}


}

void bfs2(int x1, int y1, vector<vector<string>> places, int n) {
	queue <pair<int, int>> q;
	check3[x1][y1] = 0;
	q.push(make_pair(x1, y1));
	while (!q.empty()) {
		int x = q.front().second;
		int y = q.front().first;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= 0 && nx >= 0 && nx < 5 && ny < 5 && check3[ny][nx] < 0) {
				if (places[n][ny][nx] == 'O') {
					check3[ny][nx] = check3[y][x] + 1;
				}
				else {
					check3[ny][nx] = check3[y][x];
				}
				q.push(make_pair(ny, nx));
			}
		}
	}


}

vector<int> solution(vector<vector<string>> places) {
	vector<int> answer;
	for (int i = 0; i < places.size(); i++) {
		v3.clear();
		v.clear();
		v2.clear();
		for (int j = 0; j < places[i].size(); j++) {
			string s = places[i][j];
			for (int k = 0; k < s.length(); k++) {
				if (places[i][j][k] == 'P') {
					v.push_back(make_pair(j, k));
				}
			}
		}
		//cout << "v.size(): " << v.size() << "\n";
		/*for (int j = 0; j < places[i].size(); j++) {
			string s = places[i][j];
			for (int k = 0; k < s.length(); k++) {
				cout << places[i][j][k] << " ";
			}
			cout << "\n";
		}*/
		init2();
		dfs(0);
		/*for (int j = 0; j < v2.size(); j++) {
			cout << v2[j].first <<" "<<v2[j].second<<"\n";
		}*/
		int idx = 0;
		bool ans1 = false;
		while (true) {
			if (idx >= v2.size()) {
				break;
			}

			int people1 = v2[idx].first; //인덱스
			int people2 = v2[idx].second; //인덱스
			int x1 = v[people1].first; //행
			int y1 = v[people1].second; //열
			int x2 = v[people2].first;
			int y2 = v[people2].second;
			if (abs(x1 - x2) + abs(y1 - y2) <= 2) {
				cout << "x2 x2: " << x1 << " " << y1 << " " << x2 << " " << y2 << "\n";
				init();
				bfs(x1, y1, places, i);
				bfs2(x1, y1, places, i);

				for (int j = 0; j < 5; j++) {
					for (int k = 0; k < 5; k++) {
						cout << check2[j][k] << " ";
					}
					cout << "\n";
				}
				cout << "============\n";
				if (check2[x2][y2] <= 0) {
					ans1 = true;
					break;
				}
				if (abs(x1 - x2) + abs(y1 - y2) == 2) {
					if (y1 < y2) {
						if (check3[x1][y1 + 1] > 0 || check3[x2][y2 - 1] > 0) {
							ans1 = true;
							break;
						}
					}
					if (y1 > y2) {
						if (check3[x1][y1 - 1] > 0 || check3[x2][y2 + 1] > 0) {
							ans1 = true;
							break;
						}
					}

				}
			}


			idx++;
		}
		if (!ans1) {
			answer.push_back(1);
		}
		else {
			answer.push_back(0);
		}
		cout << "ans1: " << ans1 << "\n";


	}
	return answer;
}