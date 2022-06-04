#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


int l, c;
char map[16];
bool check[16];
vector <char> v;
int j = 0; //자음 개수
int m = 0; //모음 개수

bool alpacheck(char k) {  //모음일때 false 리턴
	if (k == 'a' || k == 'e' || k == 'i' || k == 'o' || k == 'u') {
		return false;
	}
	else {
		return true;
	}
}

void dfs(int cnt) {
	if (cnt == l) {
		if (j >= 2 && m >= 1) {
			for (int i = 0; i < v.size(); i++) {
				cout << v[i];
			}
			cout << "\n";
			return;
		}
		else {
			return;
		}
	}
	for (int i = 0; i < c; i++) {
		if (!check[i] && (v.size() == 0 || map[i] > v.back())) {
			bool p = alpacheck(map[i]);
			if (p == false) {
				m++;
			}
			else {
				j++;
			}
			v.push_back(map[i]);
			check[i] = true;
			dfs(cnt + 1);
			bool t = alpacheck(map[i]);
			if (t == false) {
				m--;
			}
			else {
				j--;
			}
			v.pop_back();
			check[i] = false;
		}
	}

}

int main(void) {
	cin >> l >> c;
	for (int i = 0; i < c; i++) {
		cin >> map[i];
	}
	sort(map, map + c);
	/*for (int i = 0; i < c; i++) {
		cout << map[i]<<" ";
	}*/
	dfs(0);
}