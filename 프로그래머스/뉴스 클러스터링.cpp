#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
string str1;
string str2;
vector <string> v1;
vector <string> v2;
bool check[1001];
int count1 = 0; //±³ÁýÇÕ

int solution(string str1, string str2) {
	int answer = 0;
	return answer;
}

int main(void) {
	str1 = "aa1+aa2";
	str2 = "AAAA12";

	for (int i = 0; i < str1.length() - 1; i++) {
		string s = str1.substr(i, 2);
		
		int cnt = 0;
		for (int j = 0; j < s.length(); j++) {
			if ((s[j] >= 'a' && s[j] <= 'z') ||( s[j] >= 'A' && s[j] <= 'Z')) {
				if ((s[j] >= 'a' && s[j] <= 'z')) {
					s[j] = toupper(s[j]);
				}
				cnt++;
			}
		}
		if (cnt == 2) {
			
			v1.push_back(s);
		}
	}
	for (int i = 0; i < str2.length() - 1; i++) {
		string s = str2.substr(i, 2);
		
		int cnt = 0;
		for (int j = 0; j < s.length(); j++) {
			if ((s[j] >= 'a' && s[j] <= 'z') || (s[j] >= 'A' && s[j] <= 'Z')) {
				if ((s[j] >= 'a' && s[j] <= 'z')) {
					s[j] = toupper(s[j]);
				}
				cnt++;
			}
		}
		if (cnt == 2) {
			
			v2.push_back(s);
		}
	}
	for (int i = 0; i < v1.size(); i++) {
		cout << v1[i]<< " ";
	}
	cout << "\n";

	for (int i = 0; i < v2.size(); i++) {
		cout << v2[i] << " ";
	}
	int check2 = 0;
	for (int i = 0; i<v1.size(); i++) {
		
		for (int j = 0; j < v2.size(); j++) {
			if (!check[j]&&check2==0&& (v1[i]==v2[j] )) {
				check[j] = true;
				count1++;
				check2 += 1;
			}
		}
		check2 = 0;
	}
	int n = v1.size();
	int m = v2.size();
	cout << count1 << "\n";
	double p = 0;
	if (count1 == 0) {
		if (n + m == 0) {
			p = 1;
		}
		else {
			p = (double)(count1) / (double)(n + m - count1);
		}
	}else{
		p = (double)(count1) / (double)(n + m - count1);
	}
	
	int answer = p * 65536;
	cout << answer;
}