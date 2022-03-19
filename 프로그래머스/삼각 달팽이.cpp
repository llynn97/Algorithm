#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int map[1001][1001];
vector<int> answer;
int num = 0;
int x, y = 0;
int number = 1;
vector<int> solution(int n) {
	vector<int> answer;
	return answer;
}

int main(void) {

	n = 6;
	for (int i = 0; i < n; i++) {
		switch (num) {
		   case 0: //아래로 내려갈때
			   for (int j = i; j < n; j++) {
				   map[x++][y] = number;
				   number++;
			   }
			   x--;
			   y++;
			   num = 1;
			   break;
			  




		   case 1: //옆으로 이동
			   for (int j = i; j < n; j++) {
				   map[x][y++] = number;
				   number++;
			   }
			   x--;
			   y -= 2;
			   num = 2;
			   break;


		   case 2: //위로 이동
			   for (int j = i; j < n; j++) {
				   map[x--][y--] = number;
				   number++;
			   }
			   x += 2;
			   y++;
			   num = 0;
			   break;


		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {

		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			answer.push_back(map[i][j]);
		}
	}

	for
	
}