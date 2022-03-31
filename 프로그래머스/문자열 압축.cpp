#include <iostream>
#include <vector>
#include <algorithm>
#include <string>


using namespace std;

string s = "";
int result = 1001;
string answer = "";


int solution(string s) {
	int answer = 0;
	return answer;
}

int main(void) {
	s = "aaaaaaaaaaaabcd";
	int num = s.length();

	
	if (num == 1) {
		result = 1;
	}
	else {
		for (int i = 1; i <= num; i++) { //i:자르는 문자열 단위 길이
			answer = "";
			bool check = false;
			bool check2 = false;
			int idx = 0;
			string str = s.substr(idx, i);
			//cout << "Str: " << str << "\n";
			
			int cnt = 0;
			while (idx+i<=num) {
				if (!check2) {
					idx = idx + i;
					check2 = true;
				}
				
				if (check) {//
					//cout << "dmd"<<"\n";
					str = s.substr(idx,i);
					idx = idx + i;
				}
				check = false;
				string p = s.substr(idx, i);
				//cout << "p: " << p << "\n";
				if (p == str) {
					cnt++;
					idx += i;
				}
				else {
					if (cnt >= 1) {
						answer += to_string(cnt + 1);
						answer += str;
						
					}
					
					else {
						answer += str;
					}
					cnt = 0;
					check = true;
				}

			}
		      
			
				if (cnt >= 1) {
					answer += to_string(cnt + 1);
					answer += str;
					cout << i << " 번째 idx: " << idx << "\n";
					if (num-idx< i) {

						answer += s.substr(idx , num-idx);
					}
				}
				else {
					answer += s.substr(idx, num - idx);
				}

			
			
			cout <<"answer: "<< answer << "\n";
			int t = answer.length();
			result = min(result, t);
		}
	}

	cout << result;
	
}