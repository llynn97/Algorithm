#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

int v, e;
int a, b, c;
int map[401][401];
int INF = 987654321;
int ans = 987654321;
int main(void) {
	
	cin >> v >> e;
	for (int i = 1; i <= v; i++) {
		for (int j = 1; j <= v; j++) {
			if (i != j) {
				map[i][j] = INF;
			}
		}
	}
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		map[a][b] = c;
	}
	for (int i = 1; i <= v; i++) {
		for (int j = 1; j <= v; j++) {
			for (int k = 1; k <= v; k++) {
				if (map[j][k] > map[j][i] + map[i][k]) {
					map[j][k] = map[j][i] + map[i][k];
				}
			}
		}
	}

	for (int i = 1; i <= v; i++) {
		for (int j = 1; j <= v; j++) {
			cout << map[i][j]<<" ";
		}
		cout << "\n";
	}
	for (int i = 1; i <= v; i++) {
		for (int j = 1; j <= v; j++) {
			if (i != j && map[i][j]!=INF && map[j][i]!=INF) {
				int sum = map[i][j] + map[j][i];
				ans = min(ans, sum);
			}
			
			
		
		}
	}

	if (ans >= INF) {
		cout << "-1";
	}
	else {
		cout << ans;
	}

}