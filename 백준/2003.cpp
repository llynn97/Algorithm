#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

int n, m;
int map[10001];
int s, e;

int main(void) {
	cin >> n >> m;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}
	s = 0;
	e = 0;
	int result = 0;
	while ( e <= n) {
		if (result >= m) {
			result -= map[s++];
			
		}else if (result < m) {
			result += map[e++];
		}
		if (result == m) {
			ans++;
			
		}

	}

	cout << ans;

}