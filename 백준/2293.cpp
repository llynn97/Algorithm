#include <iostream>
#include <vector>



using namespace std;
int n, k;


int coin[101];
int dp[10001];

int main(void) {
	cin >> n >> k;
	
	for (int i = 1; i <= n; i++) {
		cin >> coin[i];
	}
	//dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = coin[i]; j <= k; j++) {
			dp[j] = dp[j] + dp[j - coin[i]];
		}
	}

	cout << dp[k];
}