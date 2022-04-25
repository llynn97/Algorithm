#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <set>
using namespace std;
stack <string> st;
vector <long long> ans;
set <string> s3;
int solution(int n, int k) {
	int answer = -1;
	return answer;
}

bool checkPrime(string str) {//소수인지 확인
	long long n = stol(str);
	if (n <= 1) {
		return false;
	}
	else if (n == 2) {
		return true;
	}
	long long i = 2;
	while (i * i <= n) {
		if (n % i == 0) {
			return false;
		}
		i++;
	}
	return true;

}

string changeK(long long k,long long n) { // n->k진수로 바꾸기
	string s = "";
	while (n>0) {
		s += to_string(n % k);
		n /= k;
	}
	reverse(s.begin(), s.end());
	return s;
}

bool checkYoung(string str) {
	int cnt = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '0') {
			return false;
		}
	}
	return true;  //0이 하나도 없을때
}

int main(void) {
	long long n = 110011;
	long long k = 10;
	
	string s1 = changeK(k, n);
	cout << s1 << "\n";
	string s2 = "";
	
	bool flag1 = false; //뒤0
	
	
	for (int i = 0; i < s1.length(); i++) {
		if (s1[i] != '0' ) {

			s2 += s1[i];
			flag1 = false;
		}
		if (s1[i] == '0') {
			if (s2.length() != 0 && checkYoung(s2)) {
				if (checkPrime(s2)) {
					
						
						ans.push_back(stol(s2));
					
					
				}
				s2 = "";
			}
			flag1 = true;
			
			
		}
	}
	if (s2.length() != 0) {
		if (checkPrime(s2)) {
			
				
				ans.push_back(stol(s2));
			

		}
	}

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}


}