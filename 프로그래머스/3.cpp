#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <queue>

using namespace std;
int map1[4][151]; //alp
int map2[4][151]; //cop
int time[10001];
int alpMax = 0;
int copMax = 0;
int cnt = 0;

int solution(int alp, int cop, vector<vector<int>> problems) {
	int answer = 0;
	return answer;
}

int main(void) {
	int alp = 10;
	int cop = 10;
	vector<vector<int>> problems = { {10,15,2,1,2} ,{20,20,3,3,4} };
	for (int i = 0; i < problems.size(); i++) {
		alpMax = max(alpMax, problems[i][0]);
		copMax = max(copMax, problems[i][1]);

	}
	for (int i = 0; i < 4; i++) {
		map1[i][0] = alp;
		map2[i][4] = cop;
	}
	int idx = 1;
	while (true) {
		int num2 = 0; //alp
		int num3 = 0; //cop
		for (int i = 0; i < 4; i++) {
			num2 = max(num2, map1[i][idx]);
			num3 = max(num3, map2[i][idx]);
				
		}
		if (num2 >= alpMax && num3 >= copMax) {
			cnt = idx;
			break;
		}
		for (int i = 0; i < problems.size(); i++) {

		}

		idx++;
	}

}