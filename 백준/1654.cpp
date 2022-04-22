#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <set>
#include <map>
#include <queue>

using namespace std;
int n, k;
long long lamp[10001];
long long answer = 0;
int main(void) {
	cin >> k >> n;
	for (int i = 0; i < k; i++) {
		cin >> lamp[i];
	}
	sort(lamp, lamp + k);
	long long start = 1;
	long long end = lamp[k - 1];
	while (start <= end) {
		long long mid = (start + end) / 2;
		long long cnt = 0;
		for (int i = 0; i < k; i++) {
			cnt += (lamp[i] / mid);
		}
		if (cnt >= n) {
			answer = max(answer, mid);
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}

	cout << answer;

}