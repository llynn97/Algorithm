#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
long long answer = 0;
int n, m;
vector<int> times;


int main(void) {
	int a = 0;
	cin>>m >> n;
	for (int i = 0; i < m; i++) {
		cin >> a;
		times.push_back(a);
	}
	sort(times.begin(), times.end());
	long long start = 1;
	long long end = (long long)times[times.size() - 1] * n;
	long long mid;
	while (start <= end) {
		mid = (start + end) / 2;
		long long cnt = 0;
		for (int i = 0; i < times.size(); i++) {
			cnt += mid / times[i];
		}
		if (cnt < n) {
			start = mid + 1;
		}
		else {
			if (mid <= end) {
				answer = mid;
			}
			end = mid - 1;
		}

	}
	cout << answer;
	
}