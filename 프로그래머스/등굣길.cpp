#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

//오른쪽 or 아래쪽 -> (+1,0) or (0,+1)
int dy[2] = {0,1};
int dx[2] = { 1,0 };

vector<vector<int>> puddles;

int ans = 9876432; //최단 경로 cnt

int dp[101][101];

int n, m;








int solution(int m, int n, vector<vector<int>> puddles) {
	int answer = 0;
	return answer;
}

int main(void) {
	//(3,4)
	int m = 4;  //열 (m,n)
	int n = 3;  //행
	puddles = {
		{2,2},
	};
	int s = 0;
	s = puddles.size();
	
	for (int i = 0; i < s; i++) {

		int p = puddles[i][1] ;
		int t = puddles[i][0] ;

	
		dp[p][t] = -1;
	}


	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int a = 0;
			int b = 0;
			if (i == 1 && j == 1) {
				dp[i][j] = 1;
			}
			else {
				if (dp[i - 1][j] != -1) {
					a = dp[i - 1][j];
				}
				if (dp[i][j - 1] != -1) {
					b = dp[i][j - 1];
				}
				if (dp[i][j] != -1) {
					int k = (a + b) % 1000000007;
					dp[i][j] = k;
				}
			}
			
		}
	}

	/*for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << dp[i][j] << " ";
		}
		cout << "\n";
	}*/
	cout << dp[n][m];

}