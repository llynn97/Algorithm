#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

vector <string> v[50001];
map <string,vector<int>> m;
vector <int> answer;


//[조건]은 "개발언어 and 직군 and 경력 and 소울푸드

vector<int> solution(vector<string> info, vector<string> query) {
	vector<int> answer;
	return answer;
}


void infoIntoMap(string info) {

}

int main() {
	vector<string> info;
	vector<string> query;
	info = { "java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50" };
	query = { "java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150" };


	for (int i = 0; i < info.size(); i++) {

		string infoArr[4][2] = {
		{"-"},
		{"-"},
		{"-"},
		{"-"}
		};

		string s = info[i];
		int idx = s.find(' ');
		string a = s.substr(0, idx); //언어

		s = s.substr(idx + 1, s.length());
		idx = s.find(' ');

		string b = s.substr(0, idx); //직군

		s = s.substr(idx + 1, s.length());
		idx = s.find(' ');
		string c = s.substr(0, idx); // 경력

		s = s.substr(idx + 1, s.length());
		idx = s.find(' ');
		string d = s.substr(0, idx); //소울푸드

		s = s.substr(idx + 1, s.length());
		string e = s;  //직군
		infoArr[0][1] = a;
		infoArr[1][1] = b;
		infoArr[2][1] = c;
		infoArr[3][1] = d;
		int num = stoi(e);

		for (int t = 0; t < 2; t++) {
			for (int j = 0; j < 2; j++) {
				for (int k = 0; k < 2; k++) {
					for (int l = 0; l < 2; l++) {
						string s1 = infoArr[0][t] + infoArr[1][j] + infoArr[2][k] + infoArr[3][l];
						m[s1].push_back(num);
					}

				}
			}
		}

	}
		for (int i = 0; i < query.size(); i++) {
			string str = query[i];
			int idx = str.find(' ');
			string a = str.substr(0, idx);

			str = str.substr(idx + 1, str.length());

			idx = str.find(' ');
			str = str.substr(idx + 1, str.length());

			idx = str.find(' ');
			string b = str.substr(0, idx);

			str = str.substr(idx + 1, str.length());

			idx = str.find(' ');
			str = str.substr(idx + 1, str.length());

			idx = str.find(' ');
			string c = str.substr(0, idx);

			str = str.substr(idx + 1, str.length());

			idx = str.find(' ');
			str = str.substr(idx + 1, str.length());

			idx = str.find(' ');
			string d = str.substr(0, idx);

			str = str.substr(idx + 1, str.length());

			string e = str;
			string str2 = "";
			str2 += a;
			str2 += b;
			str2 += c;
			str2 += d;
			auto iter = m.begin();
			while (iter != m.end()) {

				sort(iter->second.begin(), iter->second.end());
				iter++;
			}
			vector<int> scores = m[str2];
			int ans = scores.end() - lower_bound(scores.begin(), scores.end(), stoi(e));
			answer.push_back(ans);
		}

		for (int i = 0; i < answer.size(); i++) {
			cout << answer[i] << " ";
		}
	}
