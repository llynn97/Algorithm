#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;
int map[101][101];
vector <pair<int, int>> v;
vector <int> node[101];
bool check[101];
int idx;
int solution(int n, vector<vector<int>> results) {
	int answer = 0;
	return answer;
}

void dfs(int x) {
	
	for (int i = 0; i < node[x].size(); i++) {
		if (!check[node[x][i]]) {
			check[node[x][i]] = true;
			map[idx][node[x][i]] = 1;
			dfs(node[x][i]);
		}
	}

}

void init(int n) {
	for (int i = 1; i <= n; i++) {
		check[i] = false;
	}
}


int main(void) {
	int n;
	vector<vector<int>> results;
	n = 5;
	results = { {4, 3} ,{4, 2},{3, 2},{1, 2},{2, 5} };
	for (int i = 0; i < results.size(); i++) {
		int a = results[i][0];
		int b = results[i][1];
		node[a].push_back(b);
		map[a][b] = 1;

	}
	for (int i = 1; i <= n; i++) {
		idx = i;
		init(n);
		dfs(i);

	}
	/*for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout <<  map[i][j] << " ";
		}
		cout << "\n";
	}*/
	for (int i = 1; i <= n; i++) {
		int win = 0;
		int lose = 0;
		for (int j = 1; j <= n; j++) {
			if (map[i][j] == 1) {
				win++;
			}
			if (map[j][i] == 1) {
				lose++;
			}
		}
		if ((win + lose) == n - 1) {
			v.push_back(make_pair(i, n - win));
		}
	}
	cout << v.size();
}