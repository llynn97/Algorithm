#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

int map[100001];
int dp[100001];
int dp2[100001];
using namespace std;

int main(void) {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> map[i];
	}
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		int num = max(dp[i - 1] + map[i], map[i]);
		dp[i] = num;
	}
	dp2[1] = dp[1];
	for (int i = 2; i <= n; i++) {
		dp2[i] = max(dp[i], dp2[i - 1]);
	}
	
	cout << dp2[n];
	


}