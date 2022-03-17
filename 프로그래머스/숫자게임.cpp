#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> A;
vector<int> B;
int answer = 0;
int idx = 0;


int solution(vector<int> A, vector<int> B) {
	int answer = -1;
	return answer;
}

bool cmp(int a, int b) {
	return a > b;
}

int main(void) {
	A = { 2,2,2,2 };  // 7 5 3 1           7 5 3 1
	B = { 1,1,1,1 }; // 8 6 2 2            6 5 2 2
	sort(A.begin(), A.end(), cmp);
	sort(B.begin(), B.end(), cmp);
	int k = 0;
	int j = 0;
	for (int i = 0; i < A.size(); i++) {
		
		k = j;
		while (k<B.size()) {
			if (A[i] < B[k]) {
				answer++;
				k = k + 1;
				j = k;
				break;
			}
			k = k + 1;
		}
		
		
	}
	cout << answer;
}


