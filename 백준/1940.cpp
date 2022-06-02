#include <iostream>
#include <vector>
#include <algorithm>
#include <string>


using namespace std;
int ans = 0;
int m, n;
int map[15001];
int main(void) {

	cin >> n;
	cin >> m;
	for (int i = 0; i < n; i++) {
		cin >> map[i];
		
	}
	int l=0;
	int r = n - 1;
	sort(map, map + n);
	while (l < r) {
		if (map[l] + map[r] == m) {
			ans++;
			r--;
			l++;
		}
		if (map[l] + map[r] > m) {
			r--;
		}
		if (map[l] + map[r] < m) {
			l++;
		}
	}
	cout << ans;



}