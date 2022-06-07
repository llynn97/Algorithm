#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>


using namespace std;

bool memo[201][201];

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, loop = 1;
	cin >> n;
	while (n--) {
		string a, b, c;
		cin >> a >> b >> c;
		int lLen = a.length();
		int rLen = b.length();
		
		memo[0][0] = true;
		for (int i = 1; i <= lLen; ++i)	 memo[i][0] = (a[i - 1] == c[i - 1]) ? memo[i - 1][0] : false;
		for (int i = 1; i <= rLen; ++i)	 memo[0][i] = (b[i - 1] == c[i - 1]) ? memo[0][i - 1] : false;
		for (int i = 1; i <= lLen; ++i) {
			for (int j = 1; j <= rLen; ++j) {
				char curA = a[i - 1], curB = b[j - 1], curC = c[i + j - 1];
				if (curA != curC && curB != curC) memo[i][j] = false;
				else if (curA == curC && curB != curC) memo[i][j] = memo[i - 1][j];
				else if (curA != curC && curB == curC) memo[i][j] = memo[i][j - 1];
				else memo[i][j] = memo[i - 1][j] || memo[i][j - 1];
			}
		}
		cout << "Data set " << loop++ << ": ";
		(memo[lLen][rLen]) ? cout << "yes\n" : cout << "no\n";
	}
}