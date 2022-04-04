#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

int n;
int map[10001];
int dp[10001];
int main(void) {

	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		cin >> map[i];
	}
	dp[0] = 0;
	dp[1] = map[1];
	dp[2] = map[1] + map[2];
	for (int i = 3; i <= n; i++) {
		int k = 0;
		k = max(dp[i - 1], dp[i - 2] + map[i]);
		k = max(k, dp[i - 3] + map[i - 1] + map[i]);
		dp[i] = k;

	}
	cout << dp[n];
}