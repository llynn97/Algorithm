#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

string dartResult;
int answer = 0;
int map1[3]; // *
int map2[3]; //#
int num[3];
int solution(string dartResult) {
	int answer = 0;
	return answer;
}

int main(void) {
	dartResult = "1T2D3D#";  //10이 있으면 t로 바꾸기
	
	while(true){
		if (dartResult.find("10") == string::npos) {
			break;
		}
		dartResult.replace(dartResult.find("10"), 2, "t");
	}
	int idx = 0;
	int number = 0;
	for (int i = 0; i < dartResult.size(); i++) {
		
		if ((dartResult[i] >= '0' && dartResult[i] <= '9') || dartResult[i] == 't') {
			if (dartResult[i] == 't') {
				number = 10;
			}
			else {
				number = dartResult[i]-'0';
				
			}
			

		}
		else if (dartResult[i] == 'S' || dartResult[i] == 'D' || dartResult[i] == 'T') {
			if (dartResult[i] == 'S') {
				num[idx] = pow(number, 1);
			}
			else if (dartResult[i] == 'D') {
				num[idx] = pow(number, 2);
			}
			else {
				num[idx] = pow(number, 3);
			}

			if (i + 1 < dartResult.length()) {
				if (dartResult[i + 1] == '*') {
					if (idx != 0) {
						map1[idx - 1]++;
					}
					map1[idx]++;
				}
				if (dartResult[i + 1] == '#') {
					map2[idx]++;
				}
			}
			idx++;
		}
		
	}
	
	for (int i = 0; i < 3; i++) {
		int number = 1;
		if (map1[i] != 0) {
			number = 2 * map1[i];
		}
		if (map2[i] != 0) {
			number *= -1;
		}
		answer += number * num[i];
	}

	cout << answer;
	

}