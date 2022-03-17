#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int w;
int h;
long long answer = 0;

int gcd(int x, int y) {
	if (x %y==0) {
		return y;
	}
	else {
		return gcd(y, x % y);
	}
}

long long solution(int w, int h) {//가로 , 세로
	long long answer = 1;
	return answer;
}

int main(void) {
	w = 8;
	h = 12; 
	// 4(최대공약수) * (w/4+h/4-1) => -w-h+4(최대공약수)
	answer = (long long)w * (long long)h - (long long)w - (long long)h+ gcd(w, h);
	cout << answer;

}