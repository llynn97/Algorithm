#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int dp[501][501];
int INF = 10000000;
int main(void) {

	int n;
	int r, c;
	cin >> n;
	vector <pair<int, int>> v;
	v.push_back(make_pair(0, 0));
	for (int i = 1; i <= n; i++) {
		cin >> r >> c;
		v.push_back(make_pair(r, c));
	}


	for (int i = 1; i < n; i++) {
		for (int j = 1; j+i <= n; j++) {
			dp[j][i + j] = INF;
			for (int k = j; k <= i + j; k++) {
				dp[j][i + j] = min(dp[j][i + j], dp[j][k] + dp[k + 1][i + j] + v[j].first * v[k].second * v[i+j].second);
			}
		}
	}

	cout << dp[1][n];

}