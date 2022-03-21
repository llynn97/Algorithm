#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int cnt = 0;

int dp[100001];
int dp2[100001];

vector<int> a;
bool check[10001];
int solution(vector<int> a) {
	int answer = 0;
	return answer;
}




int main(void) {
	a = { -16,27,65,-2,58,-92,-71,-68,-61,-33 };
	dp[0] = a[0];
	for (int i = 1; i < a.size(); i++) {
		if (dp[i - 1] > a[i]) {
			dp[i] = a[i];
		}
		else {
			dp[i] = dp[i - 1];
		}
	}
	dp2[a.size() - 1] = a[a.size() - 1];
	for (int i = a.size() - 2; i >= 0; i--) {
		if (dp2[i + 1] > a[i]) {
			dp2[i] = a[i];
		}
		else {
			dp2[i] = dp2[i + 1];
		}
	}
	for (int i = 0; i < a.size(); i++) {
		if (a[i] <= dp[i] || a[i] <= dp2[i]) {
			cnt++;
		}
	}

	cout << cnt;

	
}