#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;


vector<int> solution(int brown, int yellow) {
	vector<int> answer;
	return answer;
}


int main(void) {
	int brown = 24;
	int yellow = 24;
	int total = brown + yellow;
	int x = yellow; //가로
	int y = 1; //세로
	while (true) {
		if (x >= y && x*y==yellow && (x + 2) * (y + 2) == total) {
			break;
		}
		if (y >= total) {
			break;
		}
		y++;
		x = yellow / y;
	
	}
	cout << x+2 <<" "<<y+2;
}