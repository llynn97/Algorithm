#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
int dp[4001][4001];
int dp2[4001];
string ans;
int idx=-1;
int answer = 0;
int main(void) {
	string  a, b;
	cin >> b;
	cin >> a;
	for (int i = 1; i <= a.length(); i++) {
		if (a[i - 1] == b[0]) {
			dp[i][1] = 1;
			answer = max(answer, dp[i][1]);
		}
		else {
			dp[i][1] = 0;
		}
	}
	for (int i = 1; i <= b.length(); i++) {
		if (b[i - 1] == a[0]) {
			dp[1][i] = 1;
			answer = max(answer, dp[1][i]);
		}
		else {
			dp[1][i] = 0;
		}
	}
	for (int i = 2; i <= a.length(); i++) {
		for (int j = 2; j <= b.length(); j++) {
			if (a[i - 1] == b[j - 1]) {
				if (a[i - 2] == b[j - 2]) {
					dp[i][j] = dp[i - 1][j - 1] + 1;
					
				}
				else {
					dp[i][j] = 1;
				}
			}
			else {
				//dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				dp[i][j] = 0;
				
				
			}
			answer = max(answer, dp[i][j]);
		}
	}

	/*for (int i = 0; i <= a.length(); i++) {
		for (int j = 0; j <= b.length(); j++) {
			cout << dp[i][j] << " ";
		}
		cout << "\n";
	}*/

	cout << answer;


	/*
	
	  입력:
PORPOISE
PROPORTION

정답:
3

입력:
ACMICPC
ACMICPCNET

정답:
7
	
	*/

}