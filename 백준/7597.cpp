#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
int n, m;
int app[101]; //메모리 크기
int memory[101];
int dist[101][10001];
int answer = 0;
bool check = false;
int sum = 0;
int main(void) {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> app[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> memory[i];
		sum += memory[i];
	}
	
	/*for (int j = 1; j <= m; j++) {
		cout << dist[1][j] << " ";
	}
	cout << "\n";*/
	
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= sum; j++) {
			if (j >= memory[i]) {
				
				
						dist[i][j] = max(dist[i - 1][j], dist[i - 1][j - memory[i]] + app[i]);

					
				
			}
			else {
				dist[i][j] = dist[i - 1][j];
			}
			
		}
		
		/*for (int j = 1; j <= m; j++) {
			cout << dist[i][j] << " ";
		}
		cout << "\n";*/
	}
	for (int i = 0; i <= sum; i++) {
		if (dist[n][i] >= m) {
			cout << i << "\n";
			break;
		}
	}

	
}