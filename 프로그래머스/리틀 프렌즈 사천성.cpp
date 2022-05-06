#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <queue>


using namespace std;
int cnt = 0;
string ans;
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };
map <char, int>  ma;
map <char, int>  mb;
vector <char> chara; // 돌아야 할알파벳들
bool check3[101][101];
int check4[101][101];
vector <pair<int, int >> v3; //빈칸으로 나타내야될 칸
bool check7 = false;
priority_queue < pair<char,pair<int,int>>,vector<pair<char, pair<int, int>>>,greater<pair<char, pair<int, int>>> >q;

bool check[101];

string solution(int m, int n, vector<string> board) { //m: 행 n:열
	string answer = "";
	return answer;
}

void init(int m, int n) {
	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			check3[i][j] = false;
			check4[i][j] = -1;
		}
	}
}




string bfs(int m,int n, vector<string> board) {
	string str = "";
	queue < pair<pair<int, int>, pair<int, int>>> q1;

	while (!q.empty()) {
		int x1 = q.top().second.second;
		int y1 = q.top().second.first;
		int dir1 = -1;
		int num1 = 0;
		if (check7) {
			break;
		}
		cout << "x1 y1 dir1 num1 : " << x1 << " " << y1 << " " << dir1 << " " << num1 <<" "<<board[y1][x1]<<"\n";
		
		init(m, n);
		q.pop();
		q1.push(make_pair(make_pair(y1, x1), make_pair(dir1, num1)));
		check3[y1][x1] = true;
		check4[y1][x1] = 0;
		while (!q1.empty()) {
			int x = q1.front().first.second;
			int y = q1.front().first.first;
			int dir = q1.front().second.first;
			int num= q1.front().second.second;
			cout << "x y dir num : " << x << " " << y<< " " << dir << " " << num << " "<<board[y][x]<<"\n";
			q1.pop();
			for (int i = 0; i < 4; i++) {
				int ny = y+ dy[i];
				int nx = x + dx[i];
				cout << "왔어---\n";
				if (ny >= 0 && nx >= 0 && ny < m && nx < n) {
					if (!check3[ny][nx]) {
						cout << "왔어2=----\n";
						check3[ny][nx] = true;
						cout << "dddddd: " << board[y1][x1] << ":" << board[ny][nx] << "\n";
						if (board[y1][x1] == board[ny][nx]) {
							cout << "같음 ok====" << num<<"\n";
							bool check6 = false;
							if (num >= 2) {
								check6 = true;
							}
							if (num == 1) {
								if (dir != -1 && dir != i) {
									
										
										check6 = true;
									
								}
							}
							if (!check6) {

								if (!check[ma[board[y1][x1]]]) {
									cout << "ma[board[y1][x1]: " << board[y1][x1] << ": " << ma[board[y1][x1]] << "\n";
									cnt += 1;
									check[ma[board[y1][x1]]] = true;
									str+= board[y1][x1];
									v3.push_back(make_pair(y1, x1));
									v3.push_back(make_pair(ny, nx));
									check7 = true;
									break;
									
									
								}
							}
							
						}
						else if (board[ny][nx]=='.') {
							if (dir == -1) {
								q1.push(make_pair(make_pair(ny, nx), make_pair(i, num)));
							}
							else {
								if (dir != i) {
									q1.push(make_pair(make_pair(ny, nx), make_pair(i, num + 1)));
								}
								else {
									q1.push(make_pair(make_pair(ny, nx), make_pair(i, num)));

								}
							}
							
						}
					}
					else if (check3[ny][nx]) {
						cout << "왔어2=----\n";
						
						cout << "dddddd: " << board[y1][x1] << ":" << board[ny][nx] << "\n";
						if (board[y1][x1] == board[ny][nx]) {
							cout << "같음 ok====" << num << "\n";
							bool check6 = false;
							if (num >= 2) {
								check6 = true;
							}
							if (num == 1) {
								if (dir != -1 && dir != i) {


									check6 = true;

								}
							}
							if (!check6) {

								if (!check[ma[board[y1][x1]]]) {
									cout << "ma[board[y1][x1]: " << board[y1][x1] << ": " << ma[board[y1][x1]] << "\n";
									cnt += 1;
									check[ma[board[y1][x1]]] = true;
									str += board[y1][x1];
									v3.push_back(make_pair(y1, x1));
									v3.push_back(make_pair(ny, nx));
									check7 = true;
									break;


								}
							}

						}
						else if (board[ny][nx] == '.') {
							int num7 = num;
							if (dir != -1 && dir != i) {
								num7 += 1;
							}
							
							if (check4[ny][nx]>=num7) {
								check4[ny][nx] = num7;
								q1.push(make_pair(make_pair(ny, nx), make_pair(i, num7)));
							}
							

						}
					}
				}
			}
		}
		while(!q1.empty()){
			q1.pop();
		}
	  
		
	}
	while (!q1.empty()) {
		q1.pop();
	}
	while (!q.empty()) {
		q.pop();
	}

	
	return str;
	

}

int main(void) {

	int m = 5;
	int n = 5;
	vector<string> board = { "FGHEI", "BAB..", "D.C*.", "CA..I", "DFHGE" };
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
			if (board[i][j]>='A' && board[i][j]<='Z'&& (ma.find(board[i][j]) == ma.end())) {
				chara.push_back(board[i][j]);
				cout << "처음: " << board[i][j] << "\n";
				ma[board[i][j]] = chara.size() - 1;

			}
		}
	}
	cout << "chara.size(): " << chara.size() << "\n";

	
	
	while (true) {
		mb.clear();
		v3.clear();
		
		check7 = false;
		cnt = 0;
		

		for (int i = 0; i< board.size(); i++) {
			for (int j = 0; j < board[i].size(); j++) {
				cout << board[i][j] << " ";
			}
			cout << "\n";
		}
		cout << "=============================\n";
		
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[i].size(); j++) {
				if (board[i][j] >= 'A' && board[i][j] <= 'Z'&&(mb.find(board[i][j]) == mb.end())) {
					mb[board[i][j]] = 1;
					if (!check[ma[board[i][j]]]) {
						cout << "그다음: " << board[i][j] << "\n";
						
						q.push(make_pair(board[i][j],make_pair(i,j)));
						
					}
				}
			}
		}
		
		string str2= bfs(m, n, board);
		
		ans+=str2;
		for (int i = 0; i < v3.size(); i++) {
			cout << "v3" << v3[i].first << " " << v3[i].second << "\n";
			board[v3[i].first][v3[i].second] = '.';
		}
		
		if (cnt == 0 || ans.size()==chara.size()) {
			break;
		}
		
		cout << "answer은==========================================: " << ans << "\n";
		//bfs후 v3. 빈칸으로 만들어주기
	}

	if (ans.size() != chara.size()) {
		cout << "impossible";
	}
	else {
		cout << ans;
	}


}