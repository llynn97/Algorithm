#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;
string ans = "";
vector <string> v = { "RT","CF","JM","AN" };
map <char, int > m;
string solution(vector<string> survey, vector<int> choices) {
	string answer = "";
	return answer;
}

int score(int num) {
	int sc = 0;
	if (num == 1 || num == 7) {
		sc = 3;
	}
	if (num == 2 || num == 6) {
		sc = 2;
	}
	if (num == 3 || num == 5) {
		sc = 1;
	}
	return sc;
}


int main(void) {

	vector<string> survey = { "AN", "CF", "MJ", "RT", "NA" };
	vector<int> choices = { 5, 3, 2, 7, 5 };
	for (int i = 0; i < survey.size(); i++) {  //int c : a의 점수  d: b의 점수
		char a = survey[i][0];
		char b = survey[i][1];
		int c = 0;
		int d = 0;
		if (choices[i] >= 1 && choices[i] <= 3) {
			c += score(choices[i]);
			if (m.find(a) == m.end()) {
				m[a] = c;
			}
			else {
				m[a] += c;
			}
		}
		else {
			d += score(choices[i]);
			
			if (m.find(b) == m.end()) {
				m[b] = d;
			}
			else {
				m[b] += d;
			}
		}
		


	}
	for (int i = 0; i < v.size(); i++) {
		char a = v[i][0];
		char b = v[i][1];
		int c = 0;
		int d = 0;
		if (m.find(a) == m.end()) {
			c = 0;
		}
		else {
			c = m[a];
		}
		if (m.find(b) == m.end()) {
			d = 0;
		}
		else {
			d= m[b];
		}
		if (c > d) {
			ans += a;
		}
		else if (c == d) {
			ans += a;
		}
		else {
			ans += b;
		}
	}

	

	

	cout << ans;

}