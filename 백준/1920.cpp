#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <set>
#include <map>
#include <queue>

using namespace std;
int n, m;
int a[100001];



int main(void) {
	int c = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> c;
		bool flag = false;
		int start = 0;
		int end = n - 1;
		while (start <= end) {
			int mid = (start + end) / 2;
			if (a[mid] == c) {
				flag = true;
				break;
			}
			else if (a[mid] > c) {
				end = mid - 1;
			}
			else {
				start = mid + 1;
			}
			
		}
		if (flag) {
			cout << "1" << "\n";
		}
		else {
			cout << "0" << "\n";
		}
	}
}