#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int n, k, w, v;
int weight[102];
int value[102];
int dp[102][100100];


int main(void) {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> weight[i] >> value[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (j >= weight[i]) {
				dp[i][j] = max(dp[i - 1][j], dp[i-1][j-weight[i]] + value[i]);
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	cout << dp[n][k];




}