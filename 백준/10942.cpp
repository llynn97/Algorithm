#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
int n,m,s,e;
int num[2001];
int idx = 0;
int dp[2001][2001];


int main(void) {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> num[i];
	
	}
	for (int i = 1; i <= n; i++) {
		dp[i][i] = 1;
	}
	for (int i = 1; i <= n - 1; i++) {
		if (num[i] == num[i + 1]) {
			dp[i][i + 1] = 1;
		}
	}
	for (int i = n-1; i >= 1; i--) {
		for (int j = i+2; j <= n; j++) {
			
				if (num[i] == num[j] && dp[i + 1][j - 1] == 1) {
					dp[i][j] = 1;
				}
				else {
					dp[i][j] = 0;
				}
			
		}
	}
	/*for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << dp[i][j] << " ";
		}
		cout << "\n";
	}*/
	cin >> m;
	for (int i = 1; i <= m; i++) {
		cin >> s >> e;
		cout << dp[s][e] << "\n";


	}
}