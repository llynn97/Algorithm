#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;




vector <pair<string, string>> divnv(string p) {//n,v;
	vector <pair<string, string>> v;
	if (p == "") {
		v.push_back(make_pair("", ""));
		return v;
	}
	int lcnt = 0; //(
	int rcnt = 0; //)
	int idx = 0;
		while (true) {
			if (rcnt>0 && lcnt>0 && rcnt==lcnt ) {
				break;
			}
			if (p[idx] == '(') {
				lcnt++;
			}
			else if (p[idx] == ')') {
				rcnt++;
			}
			idx++;

		}
		v.push_back(make_pair(p.substr(0, idx), p.substr(idx, p.length() - idx)));
		return v;
	
}

bool checku(string p) { //u가 올바른 괄호 문자열인지 확인
	stack <char> st;
	if (p == "") {
		return true;
	}
	for (int i = 0; i < p.length(); i++) {
		if (p[i] == '(') {
			st.push(p[i]);
		}
		if (p[i] == ')') {
			if (st.size() != 0 && st.top() == '(') {
				st.pop();
			}
		}
	}
	if (st.size() == 0) {
		return true;
	}
	else {
		return false;
	}
}

string num3(string p,string answer) {
	vector <pair<string, string >> v1 = divnv(p);
	string u = v1.front().first;
	string v = v1.front().second;
	bool check = checku(u);
	if (check) { //올바른 문자열이면
		answer += u;
		if (v == "") {
			return answer;
		}
		return num3(v,answer);

	}
	else {
		answer += "(";
		answer+=num3(v, "");
		answer += ")";
		u = u.erase(0, 1);
		u = u.substr(0, u.length() - 1);
		for (int i = 0; i < u.length(); i++) {
			if (u[i] == '(') {
				answer += ")";
			}
			if (u[i] == ')') {
				answer += "(";
			}
		}
		return answer;
	
	}
}





int main(void) {
	string p = "()))((()";
	//vector<pair<string,string>> v=divnv(p);
	//cout << v.front().first << " " << v.front().second;
	cout << num3(p, "");

	
}