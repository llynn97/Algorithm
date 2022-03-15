#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
int answer = 0;
int aNum = 0;

int solution(string name) {
	int answer = 0;
	return answer;
}

int alpha(char end) { // ¾ËÆÄºª ¸¸µå´Â È½¼ö ½ÃÀÛ => 'A'
	int num1 = end - 'A';
	int num2 = ('Z' - end )+ 1;
	int ans = min(num1, num2);
	return ans;
  }

int main(void) {
	string name = "JEROEN";
	string s = "";
	
	for (int i = 0; i < name.length(); i++) {
		s += "A";
		
	}
	for (int i = 0; i < name.length(); i++) {
		answer += alpha(name[i]);
	}
	int idx = 0;
	
	while (true) {
		s[idx] = name[idx];
		if (name == s) {
			return answer;
		}
		int left = idx;
		int leftCnt = 0;
		while (s[left] == name[left]) {
			left--;
			leftCnt++;
			if (left == -1) {
				left = name.size() - 1;
			}
		}

		int right = idx;
		int rightCnt = 0;
		while (s[right] == name[right]) {
			right++;
			rightCnt++;
			if (right == name.size()) {
				right = 0;
			}
		}
		if (leftCnt < rightCnt) {
			answer += leftCnt;
			idx = left;
		}
		else {
			answer += rightCnt;
			idx = right;
		}
	}
	
}