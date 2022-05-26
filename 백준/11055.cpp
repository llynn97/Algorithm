#include <iostream>
#include <string>
#include <algorithm>
#include <vector>


using namespace std;



int n;
int map[1001];
int dp[1001];

int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}
	for (int i = 0; i < n; i++) {
		dp[i] = map[i];
		for (int j = 0; j < i; j++) {
			if (map[i] > map[j]) {
				dp[i] = max(dp[j] + map[i], dp[i]);
			}
		}
	}
	int maxi = 0;

	for (int i = 0; i < n; i++) {
		if (maxi < dp[i]) {
			maxi = dp[i];
		}
	}

	cout << maxi;
	
}