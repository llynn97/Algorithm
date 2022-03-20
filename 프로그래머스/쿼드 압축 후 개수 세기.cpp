#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<vector<int>> arr;
vector<vector<int>> map;
vector<int> answer;
int x = 0; //0
int y = 0; //1
vector<int> solution(vector<vector<int>> arr) {
	vector<int> answer;
	return answer;
}
void func(int n,int x1,int y1) { //
	int cnt0 = 0;
	int cnt1 = 0;
	for (int i = x1; i <x1+n; i++) {
		for (int j = y1; j <y1+n; j++) {
			if (map[i][j] == 0) {
				cnt0++;
			}
			if (map[i][j] == 1) {
				cnt1++;
			}
		}
	}
	if (cnt0 == n * n) {
		x++;
		return;
	}
	if (cnt1 == n * n) {
		y++;
		return;
	}
	func(n / 2, x1, y1);
	func(n / 2, x1 + n / 2, y1);
	func(n / 2, x1, y1+n/2);
	func(n / 2, x1+n/2, y1+n/2);

}

int main(void) {

	arr = { {1,1,1,1,1,1,1,1} ,{0,1,1,1,1,1,1,1},{0,0,0,0,1,1,1,1},{0,1,0,0,1,1,1,1},{0,0,0,0,0,0,1,1},{0,0,0,0,0,0,0,1},{0,0,0,0,1,0,0,1},{0,0,0,0,1,1,1,1} };

	int size=arr.size();
	map = arr;
	func(size, 0, 0);
	answer.push_back(x);
	answer.push_back(y);
	cout << answer[0] << " " << answer[1];

}