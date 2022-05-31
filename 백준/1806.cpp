#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

int n, s;
int l, r;
int map[10001];


int main(void) {
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}
	l = 0;
	r = 0;
	int result = 0;
	bool check = false;
	int mini = 100001;
	while ( r<=n ) {
		if (result >= s) {
			
			result -= map[l++];
			mini = min(mini, r - l + 1);
			check = true;
		}
		else if (result < s) {
			
			result += map[r++];
			
			
			
		}
	}

	if (!check) {
		cout << 0;
	}
	else {
		cout << mini;
	}

}