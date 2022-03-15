#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>
using namespace std;

int map[32001]; 

unordered_set<int> uset[8]; //중복제거 user.insert

int solution(int N, int number) {
	int answer = 0;
	return answer;
}

int main(void) {
	// 3-> 1, 2
	int answer;
	int number = 12;
	int n = 5;
	string s = "";
	for (int i = 0; i < 8; i++) {
		s += to_string(n);
		int n = stoi(s);
		uset[i].insert(n);
	}
	//dp[0] == 1  , 0     / dp[1]= 1,1 2.0  dp[2] = dp[1] dp[1] dp[3] = dp[2] dp[1] d[4] 
	for (int i = 1; i < 8; i++) {
		for (int j = 0; j < i; j++) {
			for (int a : uset[j]) {
				for (int b : uset[i - j - 1]) {
					uset[i].insert(a + b);
					uset[i].insert(a - b);
					uset[i].insert(a * b);
					if (b != 0) {
						uset[i].insert(a / b);
					}
				}

			}
		}
	}

	for (int i = 0; i < 8; i++) {
		if (uset[i].find(number) != uset[i].end()) {
			answer = i + 1;
			break;
		}
	}


	
	
	
	
	
	
	
	
	


}