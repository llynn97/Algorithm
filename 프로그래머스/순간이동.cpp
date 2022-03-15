#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

int n, k;
int dp[100001];

int ans = 10001;

int solution(int n)
{
	int ans = 0;

	// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
	cout << "Hello Cpp" << endl;

	return ans;
}




int main(void) {

	n = 5000;
	dp[0] = 0;
	for (int i= 1; i <= n; i++) {  // 1,2,3,4,5,6,7,8
		
		
		if (i %2 != 0) {
			dp[i] = dp[i - 1] + 1;
		}
		else {
			int ans2 = min(dp[i - 1] + 1, dp[i/2]);
			dp[i] = ans2;
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << dp[i] << " ";
	}
	cout << "\n";

	
	cout <<dp[n];
}

