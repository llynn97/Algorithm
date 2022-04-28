#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>


using namespace std;

bool check[10];
char alphas[8] = { 'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T' };
int ans = 0;
vector <char> v;

int solution(int n, vector<string> data) {
	int answer = 0;
	return answer;
}
//A C F J M N R T

//NF   R  T


//1 2 3 4 5   3차이 -> 4    1 2  0 차이->1


void dfs( vector<string> data,int cnt) {
	if (cnt == 8) {
		for (int i = 0; i < data.size(); i++) {

			string s = data[i];

			char one = s[0];
			char two = s[2];
			char giho = s[3];

			int num = int(s[4] - '0');
			int idx1 = -1;
			int idx2 = -1;
			for (int j = 0; j < v.size(); j++) {
				if (v[j] == one) {
					idx1 = j;
				}
				if (v[j] == two) {
					idx2 = j;
				}
				if (idx1 != -1 && idx2 != -1) {
					break;
				}
			}
			if (giho == '=') {
				if (abs(idx1 - idx2) != num + 1) {
					return;
				}
			}
			if (giho == '>') {
				if (abs(idx1 - idx2) <= num + 1) {
					return;
				}
			}
			if (giho == '<') {
				if (abs(idx1 - idx2) >= num + 1) {
					return;
				}
			}


		}
		
		ans++;
		return;
	}

	for (int i = 0; i < 8; i++) {
		if (!check[i]) {
			check[i] = true;
			v.push_back(alphas[i]);
			dfs(data,cnt + 1);
			check[i] = false;
			v.pop_back();


		}
	}

}
int main(void) {
	int n = 2;
	ans = 0;
	for (int i = 0; i <= 8; i++) {
		check[i] = false;
	}
	vector<string> data={ "N~F=0", "R~T>2" };
	dfs( data, 0);
	cout << ans;
		


	
}