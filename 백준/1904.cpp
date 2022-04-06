#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
int dp1[1000001];
int dp2[1000001];
int dp3[1000001];

int main(void) {

	int n;
	cin >> n;
	dp1[1] = 1;
	dp2[1] = 1;
	dp3[1] = 0; //두번째 0인경우
	for (int i = 2; i <= n; i++) {
		dp2[i] = (dp2[i - 1] + dp3[i - 1])%15746;
		dp1[i] = (dp2[i - 1] + dp3[i - 1])%15746;
		dp3[i] = dp1[i - 1];
	}

	cout << (dp3[n] + dp2[n])%15746;

}