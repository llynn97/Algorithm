#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;


vector<string> files;
vector<string> files2;

vector<string> answer;
vector <pair<pair<string, int>, int>> v;

vector<string> solution(vector<string> files) {
	vector<string> answer;
	return answer;
}


bool cmp(pair<pair<string, int>, int> a, pair<pair<string, int>, int> b) {
	
	
	if (a.first.first == b.first.first) {
		if (a.first.second == b.first.second) {
			return a.second < b.second;
		}
		else {
			return a.first.second < b.first.second;
		}
	}
	else {
	       return a.first.first < b.first.first;
	}
	
	
}


int main(void) {
	files = { "F-5 Freedom Fighter", "B-50 Superfortress", "A-10 Thunderbolt II", "F-14 Tomcat" };
	for (int i = 0; i < files.size(); i++) {
		files2.push_back(files[i]);
		for (int j = 0; j < files[i].length(); j++) {
			files[i][j] = toupper(files[i][j]);
		}
	}
	string head, number, tail;

	for (int i = 0; i < files.size(); i++) {
		string s = files[i];
		head = "";
		number = "";
		tail = "";
		int idx = 0;
		while (true) {
			if (s[idx] >= '0' && s[idx] <= '9') {
				break;
			}
			idx++;

		}
		head = s.substr(0, idx);
		//cout << head << "\n";
		s = s.substr(idx, s.length());
		//cout << s << "\n";
		idx = 0;
		while (true) {
			if (idx >= s.length() || s[idx] == ' ' || s[idx] == '.' || s[idx] == '-' || (s[idx] >= 'A' && s[idx] <= 'Z')) {
				break;
			}
			idx++;
		}
		tail = s.substr(0, idx);
		//cout << tail << "\n";
		v.push_back(make_pair(make_pair(head, stoi(tail)), i));
	}


	sort(v.begin(), v.end(),cmp);
	for (int i = 0; i < v.size(); i++) {
		//cout << files2[v[i].second] << " ";
		answer.push_back(files2[v[i].second]);

	}
}