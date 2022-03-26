#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>


using namespace std;

int t, K;
int map[501];
int dp[501][501];
int sum[501];
int INF = 1000000000;

int main(void) {
	int answer = 0;
	cin >> t;

	while (t--) {
		cin >> K;
		for (int i = 1; i <= K; i++) {
			cin >> map[i];
			sum[i] = sum[i - 1] + map[i];
		}

		for (int i = 1; i <= K; i++) {
			for (int j = 1; j <= K-i; j++) {
				dp[j][j+i] = INF;
				for (int k = j; k < i+j; k++) {
					dp[j][i + j] = min(dp[j][i+j], dp[j][k] + dp[k + 1][i + j] + sum[i + j] - sum[j - 1]);
				}
			}
		}
		cout << dp[1][K] << "\n";
	}


}