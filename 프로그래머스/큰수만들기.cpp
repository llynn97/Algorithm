#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
char map[1000001];

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* number, int k) {
	// return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
	char* answer = (char*)malloc(1);
	return answer;
}




int main(void) {
	string number = "4177252841";
	int k = 4;
	string s = "";
	int idx = 0;
	int num = number.length() - k;
	for (int i = 0; i < num; i++) {
		char maxi = number[idx];
		int maxidx = idx;
		for (int j = idx; j <= k + i; j++) {
			if (maxi < number[j]) {
				maxi = number[j];
				maxidx = j;
			}
		}
		idx = maxidx + 1;
		s += maxi;
	}
      


	cout << s;
}