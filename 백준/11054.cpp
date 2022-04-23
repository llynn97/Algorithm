#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

int n;
int map[1001];
int dp1[1001]; //증가
int dp2[1001]; //감소
int answer = 0;
int main(void) {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> map[i];
	}
	for (int i = 1; i <= n; i++) {
		int max = 1;
		for (int j = 1; j <=i-1; j++) {
			if (map[i] > map[j]) {
				if (max < (dp1[j]+1)) {
					max = dp1[j]+1;
				}
			}
		}
		dp1[i] = max;
	}
	/*for (int i = 1; i <= n; i++) {
		cout << dp1[i] << " ";
	}
	cout << "\n";*/
	for (int i = n ; i >= 1; i--) {
		int max = 1;
		for (int j = i; j <= n; j++) {
			if (map[i] > map[j]) {
				if (max < (dp2[j] + 1)) {
					max = dp2[j] + 1;
				}
			}
		}
		dp2[i] = max;
	}
	/*for (int i = 1; i <= n; i++) {
		cout << dp2[i] << " ";
	}*/
	for (int i = 1; i <= n; i++) {
		answer = max(answer, dp1[i] + dp2[i]);
	}
	cout << answer-1;

}