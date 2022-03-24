#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>



using namespace std;

int m;
int n;
vector<string> board;
bool check[31][31];
queue <pair<int, int>> q;
vector <pair<int,int>> v;
int answer = 0;

int solution(int m, int n, vector<string> board) {
	int answer = 0;
	return answer;
}

void init() {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			check[i][j] = false;
		}
	}
}

int main(void) {
	m = 4; //За
	n = 5; //ї­
	board = { "CCBDE", "AAADE", "AAABF", "CCBBF" };
	while (true) {
		for (int i = 0; i < m-1; i++) {
			
			for (int j = 0; j < n - 1; j++) {
				int cnt = 0;
				if (board[i][j]>='A' && board[i][j]<='Z') {
					char s = board[i][j];
					if (s == board[i][j+1]) {
						cnt++;
					}
					if (s == board[i+1][j]) {
						cnt++;
					}
					if (s == board[i+1][j+1]) {
						cnt++;
					}
					if (cnt==3) {
						{
							
								q.push(make_pair(i, j));
								q.push(make_pair(i, j + 1));
								q.push(make_pair(i + 1, j));
								q.push(make_pair(i + 1, j + 1));
							
						}
					
						
					}
				}
			
					
			}
			
		}
		
		if (q.empty()) {
			break;
		}
		init();

		while (!q.empty()) {
			int x = q.front().second;
			int y = q.front().first;
		//	cout << x << " " << y << "\n";
			q.pop();
			if (!check[y][x]) {
				board[y][x] = '0';
				check[y][x] = true;
				answer++;
			}

		}
	/*	cout << "------------------------" << "\n";
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cout << board[i][j] << " ";
			}
			cout << " \n";
		}*/

		for (int i = 0; i < n ; i++) {
			
			for (int j = m - 1; j >= 0; j--) {
				if (board[j][i] != '0') {
					v.push_back(make_pair(j,board[j][i]));
				}
			}
			/*for (int j = 0; j < v.size(); j++) {
				cout << v[j].first << " "<<i<<"\n";
			}*/
			int idx = m - 1;
			for (int j = 0; j < v.size(); j++) {
				board[idx][i] = v[j].second;
				idx--;
			}
			for (int j = 0; j <= idx; j++) {
				board[j][i] = '0';
			}
			v.clear();
		}


		
	}

	cout << answer;
	
}