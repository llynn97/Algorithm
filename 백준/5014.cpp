#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n;
int map[21][21];
bool check[21]; //링크팀이면 true
int person;
vector <int> v;
int ans = 101;

void dfs(int cnt) {
	if (person == cnt) {
		int rink = 0;
		int start = 0;
		vector <int> k; //스타트 
		//능력치 차이 구해서 최솟값과 비교
		for (int i = 0; i < v.size(); i++) {
			for (int j = i + 1; j < v.size(); j++) {
				rink =rink+ map[v[i]][v[j]] + map[v[j]][v[i]];

			}
			
		  
		}
		for (int i = 0; i < n; i++) {
			if (!check[i]) {
				k.push_back(i);
			}
		}
		for (int i = 0; i < k.size(); i++) {
			for (int j = i + 1; j < k.size(); j++) {
				start = start + map[k[i]][k[j]] + map[k[j]][k[i]];

			}


		}
		k.clear();
		ans = min(ans, abs(rink - start));
		
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!check[i]) {
			

            v.push_back(i);
			check[i] = true;
			dfs(cnt + 1);
			check[i] = false;
			v.pop_back();
			
		  
			
			

			

		}
	}
}


int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	person = n / 2;
	dfs(0);
	cout << ans;
}