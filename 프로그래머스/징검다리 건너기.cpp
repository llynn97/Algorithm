#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
int big = 1;
int smallIdx;
int answer = 0;
int solution(vector<int> stones, int k) {
	int answer = 0;
	return answer;
}

bool check(vector<int> stones,int mid, int k) {
	int count = 0;
	for (int i = 0; i < stones.size(); i++) {
		if (stones[i] - mid <= 0) {
			count++;
		}
		else {
			count = 0;
		}
		if (count >= k) {
			return true;
		}
	}
	return false;
}

int main(void) {
	vector<int> stones = { 2, 4, 5, 3, 2, 1, 4, 2, 5, 1 };
	int k = 3;

	for (int i = 0; i < stones.size(); i++) {
		if (big < stones[i]) {
			big = stones[i];
		}

	}

	int front = 1; 
	int back = big;
	while (front <= back) {
		int mid = (front + back) / 2;
		if (check(stones, mid, k)) {
			back = mid - 1;
		}
		else {
			front = mid + 1;
		}
	}

	cout << front;
	
}