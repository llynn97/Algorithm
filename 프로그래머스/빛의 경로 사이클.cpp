#include <iostream>
#include <algorithm>
#include <vector>
#include <string>


using namespace std;

vector<string> grid;
vector<string> grid2;
vector <int> answer;
vector <pair<int, int>> v;
bool check[501][501][4];
int cnt = 0;
int dx, dy, num;
int m, n;
//0: -> , 1: <- , 2: 아래 3:위

void init() {
	for (int i = 0; i < grid.size(); i++) {
		grid2.push_back(grid[i]);
	}
}

vector<int> straight(int a) { //a: 방향
	vector <int> v;
	if (a == 0) {
		v.push_back(1);
		v.push_back(0);
		v.push_back(a);

	}
	else if (a == 1) {
		v.push_back(-1);
		v.push_back(0);
		v.push_back(a);

	}
	else if (a == 2) {
		v.push_back(0);
		v.push_back(1);
		v.push_back(a);

	}
	else if (a == 3) {
		v.push_back(0);
		v.push_back(-1);
		v.push_back(a);

	}
	return v;
}
vector<int> left(int a) { //a: 방향
	vector <int> v;
	if (a == 0) {
		v.push_back(0);
		v.push_back(-1);
		v.push_back(3);

	}
	else if (a == 1) {
		v.push_back(0);
		v.push_back(1);
		v.push_back(2);

	}
	else if (a == 2) {
		v.push_back(1);
		v.push_back(0);
		v.push_back(0);

	}
	else if (a == 3) {
		v.push_back(-1);
		v.push_back(0);
		v.push_back(1);

	}
	return v;
}
vector<int> right(int a) { //a: 방향
	vector <int> v;
	if (a == 0) {
		v.push_back(0);
		v.push_back(1);
		v.push_back(2);
	}
	else if (a == 1) {
		v.push_back(0);
		v.push_back(-1);
		v.push_back(3);
	}
	else if (a == 2) {
		v.push_back(-1);
		v.push_back(0);
		v.push_back(1);

	}
	else if (a == 3) {
		v.push_back(1);
		v.push_back(0);
		v.push_back(0);
	}
	return v;
}


int dfs(int y, int x, int start,int ans) { // y,x: 현재 좌표 start: 전에서 온 방향



	if (grid[y][x] == 'S') {

		dx = x + straight(start)[0];
		dy = y + straight(start)[1];
		num = straight(start)[2];
	}
	else if (grid[y][x] == 'R') {

		dx = x + right(start)[0];
		dy = y + right(start)[1];
		num = right(start)[2];
	}
	else if (grid[y][x] == 'L') {
		dx = x + left(start)[0];
		dy = y + left(start)[1];
		num = left(start)[2];
	}
	

	//cout << dy << " " << dx << " " << num << "\n";

	if (dx < n && dx >= 0 && dy >= 0 && dy < m) {
		if (check[y][x][num]) {
			return ans;
		}

		if (!check[y][x][num]) {
			check[y][x][num] = true;
			
			return dfs(dy, dx, num,ans+1);

		}
	}
	else {


		int ny = 0;
		int nx = 0;
		if (num == 0) {
			ny = y;
			nx = 0;
			//dfs(y, 0, num);
		}
		if (num == 1) {
			ny = y;
			nx = n - 1;
			//dfs(y, n - 1, num);
		}
		if (num == 2) {
			ny = 0;
			nx = x;
			//dfs(0, x, num);
		}
		if (num == 3) {
			ny = m - 1;
			nx = x;
			//dfs(m - 1, x, num);
		}
		if (check[y][x][num]) {
			return ans;
		}
		
		if (!check[y][x][num]) {
			check[y][x][num] = true;
			
		 return	dfs(ny, nx, num,ans+1);

		}



	}


}

vector<int> solution(vector<string> grid) {
	vector<int> answer;
	return answer;
}

int main(void) {
	grid = { "R","R" };
	m = grid.size();
	n = grid[0].size();
	init();
	
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < 4; k++) {
				int result = dfs(i, j, k, 0);
				if (result != 0) {
					answer.push_back(result);
				}
			}
		}
	}
	

	//dfs(0, 0, 2);

	sort(answer.begin(), answer.end());

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
	}


}