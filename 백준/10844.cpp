#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

#define mod 1000000000

int n;
int dp[101][10];
int ans;

int main(void) {
	cin >> n;
	dp[1][0] = 0;
	for (int i = 1; i <= 9; i++) {
		dp[1][i] = 1;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j == 0) {
				dp[i][j] = dp[i-1][j + 1];
			}
			else if (j == 9) {
				dp[i][j] = dp[i - 1][j - 1];
			}
			else {
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]);
			}

			dp[i][j] %= 1000000000;
		}
	}

	for (int i = 0; i <= 9; i++) {
		ans = (ans + dp[n][i]) % 1000000000;
	}

	cout << ans;


}