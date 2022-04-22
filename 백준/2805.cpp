#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <set>
#include <map>
#include <queue>

using namespace std;

int n, m;
int h;
int tree[1000001];

int main(void) {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> tree[i];
	}
	sort(tree, tree + n);
	int start = 0;
	int end = tree[n - 1];
	//cout << end << "\n";
	while (start <= end) {
		int mid = (start + end) / 2;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			
			if (tree[i] >= mid) {
				cnt += (tree[i] - mid);
			}
		}
		if (cnt >= m) {
			//cout << "cnt: " << cnt << "\n";
			h = max(mid, h);
			start = mid + 1;
			

		}
		else {
			end = mid - 1;
			
		}
	}

	cout << h;
}