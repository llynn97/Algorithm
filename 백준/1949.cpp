#include <iostream>
#include <vector>
#include <algorithm>



using namespace std;
int n;
int a, b;
int num[10001];
bool check[10001];
vector <int> v[10001];
int dp[10001][2];

void dfs(int x) {

	dp[x][0] = 0;
	dp[x][1] = num[x];
	check[x] = true;
	
	for (int i = 0; i < v[x].size(); i++) {
		if (!check[v[x][i]]) {
			check[v[x][i]] = true;
			dfs(v[x][i]);
			dp[x][0] += max(dp[v[x][i]][0], dp[v[x][i]][1]);
			dp[x][1] += dp[v[x][i]][0];
		}
	}
}

int main(void) {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> num[i];
	}
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	dfs(1);
	cout << max(dp[1][0], dp[1][1]);

}