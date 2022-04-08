#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

bool map[3]; //+,-,*
int k; // 연산자 개수
vector <long long> number;
vector <char> ch;
vector <char> ch2; // 식에 존재하는 연산자
vector <int> st;
vector<char> st2;
vector <string> s3;

vector <string> ch4;

stack <string> st3;

vector <long long> answer;
vector <pair<pair<char, char>, char>> v2;

bool cmp(long long a, long long b) {
	return a > b;
}


long long solution(string expression) {
	long long answer = 0;
	return answer;
}

int main(void) {
	string expression = "100-200*300-500+20";
	
	int idx = 0;
	string a = "";
	while (true) {
		if (idx == expression.length() - 1) {
			a += expression[idx];
			number.push_back(stol(a));
			ch4.push_back(a);
			break;
		}
		if (expression[idx] == '-' || expression[idx] == '*' || expression[idx] == '+') {
			number.push_back(stol(a));
			ch4.push_back(a);
			ch.push_back(expression[idx]);
			string p = "";
			p += expression[idx];
			ch4.push_back(p);
			
			
			a = "";

		}
		else {
			a += expression[idx];
		}
		
		idx++;

	}
	k = ch.size();


	for (int i = 0; i < ch4.size(); i++) {
		s3.push_back(ch4[i]);
	}
	ch2.push_back('*');
	ch2.push_back('-');
	ch2.push_back('+');
	do {
		
		v2.push_back(make_pair(make_pair(ch2[0], ch2[1]), ch2[2]));
		
		
	} while (next_permutation(ch2.begin(), ch2.end()));
	v2.push_back(make_pair(make_pair(ch2[0], ch2[1]), ch2[2]));
	ch2.clear();

	for (int j = 0; j < v2.size(); j++) {
		int a = v2[j].first.first;
		int b = v2[j].first.second;
		int c = v2[j].second;
		ch2.push_back(a);
		ch2.push_back(b);
		ch2.push_back(c);
		int idx2 = 0;
	

		while (true) {
			if (idx2 == ch2.size()) {

				long long nn = stol(ch4[0]);
				answer.push_back(abs(nn));
				ch4.clear();

				break;
			}
			int k = 0;

			for (int i = 0; i < ch4.size(); i++) {
				string p = "";
				p += ch2[idx2];
				if (ch4[i] == p) {
					if (p == "+") {
						long long n3 = stol(st3.top()) + stol(ch4[i + 1]);
						st3.pop();
						st3.push(to_string(n3));

					}
					else if (p == "-") {
						long long n3 = stol(st3.top()) - stol(ch4[i + 1]);
						st3.pop();
						st3.push(to_string(n3));
					}
					else if (p == "*") {
						long long n3 = stol(st3.top()) * stol(ch4[i + 1]);
						st3.pop();
						st3.push(to_string(n3));
					}
					i++;
				}
				else {
					st3.push(ch4[i]);
				}


			}
			ch4.clear();
			while (!st3.empty()) {
				ch4.push_back(st3.top());
				st3.pop();
			}
			reverse(ch4.begin(), ch4.end());
		


			idx2++;
		}
		for (int i = 0; i < s3.size(); i++) {
			ch4.push_back(s3[i]);
		}
		ch2.clear();
	}
	

	
	

	sort(answer.begin(), answer.end(),cmp);
	cout << answer[0];
	
}