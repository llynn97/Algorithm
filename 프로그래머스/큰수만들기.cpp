#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
char map[1000001];

// �Ķ���ͷ� �־����� ���ڿ��� const�� �־����ϴ�. �����Ϸ��� ���ڿ��� �����ؼ� ����ϼ���.
char* solution(const char* number, int k) {
	// return ���� malloc �� ���� �Ҵ��� ������ּ���. �Ҵ� ���̴� ��Ȳ�� �°� �������ּ���.
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