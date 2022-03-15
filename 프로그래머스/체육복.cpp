#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> lost;
vector<int> reserve;

int reserves[52];

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;
	return answer;
}


int main(void) {
	int n = 3;
	lost = {
		3
	};

	reserve = {
		1
	};

	int people = 0;
	people = lost.size();

	for (int i = 0; i < reserve.size(); i++) {
		int num = 0;
		num = reserve[i];
		reserves[num] = 1;
	}

	for (int i = 0; i < lost.size(); i++) {
		int a = 0;
		a = lost[i];
		if (reserves[a] == 1) {
			reserves[a] = -1;
		}
	}
	for (int i = 0; i < lost.size(); i++) {
		int num = 0;
		num = lost[i];
		if (reserves[num] == -1) {
			people = people - 1;
		}
		else {
			if (reserves[num + 1] == 1 && reserves[num - 1] == 1) {

				people -= 1;
				reserves[num - 1] = 0;
			}
			else {
				if (reserves[num + 1] == 1) {
					reserves[num + 1] = 0;
					people -= 1;
				}
				if (reserves[num - 1] == 1) {
					reserves[num - 1] = 0;
					people -= 1;
				}
			}
		
		}
	}

	cout << n - people;
}
