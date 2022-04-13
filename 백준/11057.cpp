#include <vector>
#include <string>
#include <algorithm>
#include <iostream>


using namespace std;

int ans = 0;
int n;
int dp[1001][10];
int main(void) {
	cin >> n;
	for (int i = 0; i <= 9; i++) {
		dp[1][i] = 1;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			int num = 0;
			for (int k = 0; k <= j; k++) {
				num += dp[i- 1][k];
			}
			dp[i][j] = num % 10007;
		}
	}

	for (int i = 0; i <= 9; i++) {
		ans += dp[n][i];
	}

	cout << ans;

}