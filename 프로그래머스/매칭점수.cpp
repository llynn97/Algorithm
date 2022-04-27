#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

map <string, int> m;  // url 이랑 index매칭
map <string, int> m2; //외부링크 개수
map <string, int> m4; //찾은 단어 개수
map <string, vector<string>> m3;

vector <pair<float, int>> ans;

vector <string> v;
int solution(string word, vector<string> pages) {
	int answer = 0;
	return answer;
}

bool cmp(pair<float, int> a, pair<float,int> b) {
	if (a.first== b.first) {
		return a.second < b.second;
	}
	else {
		return a.first > b.first;
	}
}

int main(void) {
	string word="blind";
	for (int i = 0; i < word.length(); i++) {
		word[i] = tolower(word[i]);
	}

	vector<string> pages = { "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://a.com\"/>\n</head>  \n<body>\nBlind Lorem Blind ipsum dolor Blind test sit amet, consectetur adipiscing elit. \n<a href=\"https://b.com\"> Link to b </a>\n</body>\n</html>"
		, "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://b.com\"/>\n</head>  \n<body>\nSuspendisse potenti. Vivamus venenatis tellus non turpis bibendum, \n<a href=\"https://a.com\"> Link to a </a>\nblind sed congue urna varius. Suspendisse feugiat nisl ligula, quis malesuada felis hendrerit ut.\n<a href=\"https://c.com\"> Link to c </a>\n</body>\n</html>", 
		"<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://c.com\"/>\n</head>  \n<body>\nUt condimentum urna at felis sodales rutrum. Sed dapibus cursus diam, non interdum nulla tempor nec. Phasellus rutrum enim at orci consectetu blind\n<a href=\"https://a.com\"> Link to a </a>\n</body>\n</html>" };
	
	for (int i = 0; i < pages.size(); i++) {
		for (int j = 0; j < pages[i].length(); j++) {
			pages[i][j] = tolower(pages[i][j]);
		}
	}





	for (int i = 0; i < pages.size(); i++) {
		string s = pages[i];
		v.clear();
		int idx = s.find("<meta property");
		int idx2 = 0;
		int idx3 = idx;
		while (true) {
			if (s[idx3] == '>') {
				idx2 = idx3;
				break;
			}
			idx3++;

		}
		string a = s.substr(idx, idx2 - idx + 1);    //<meta property=    > 찾기
		cout << a << "\n";
		idx = a.find("content=");
		string str = "";
		int cnt = 0;
		for (int j = idx; j < a.length(); j++) {
			if (cnt == 2) {
				break;
			}
			if (a[j] == '"') {
				cnt++;
				continue;
			}
			if (cnt == 1) {
				str += a[j];
			}
		}
		string b = str; //url 구하기
		m[b] = i; //index넣어야함 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

		cout << b << "\n";
		string str2 = s;
		while (true) {
			if (str2.find("<a href=") == string::npos) {
				break;
			}

			idx = str2.find("<a href=");
			while (true) {
				if (str2[idx] == '"') {
					idx2 = idx + 1;
					break;

				}
				idx++;
			}

			str = "";
			while (true) {

				if (str2[idx2] == '"') {
					break;
				}
				str += str2[idx2];
				idx2++;
			}
			if (str.find("https://") != string::npos) {
				v.push_back(str);
				cout << "str: " << str << "\n";
				if (m3.find(str) == m3.end()) {
					m3[str].push_back(b);
				}
				else {
					m3[str].push_back(b);
				}
			}
			
			idx = str2.find("</a>");
			idx = idx + 4;
			str2 = str2.substr(idx, str2.length() - 1);
			


			cout << "Str2: " << str2 << "\n";  //외부링크 한번 구하고 남은 문자열

		}
		m2[b] = v.size();
		idx = 0;
		str = "";
		cnt = 0;
		while (true) {
			if (idx >= s.length()) {
				break;
			}
			if (s[idx] >= 'a' && s[idx] <= 'z') {
				str += s[idx];
			}
			else {
				if (str == word) {
					cnt++;
				}
				str = "";
			}

			idx++;
		}
		cout << "cnt: " << cnt << "\n";
		m4[b] = cnt;
	}

	cout << "======================================================================\n";
	auto iter = m.begin();
	while (iter != m.end()) {
		int idx3 = iter->second;
		string str3 = iter->first;
		int wordNum = m4[str3];
		int linkNum = m2[str3];
		cout << "wordNum+linkNum: " << wordNum << " " << linkNum << "\n";
		float total = wordNum;
		if (m3.find(str3) != m3.end()) {
			for (int j = 0; j < m3[str3].size(); j++) {
				string f = m3[str3][j];
				if (m2[f] == 0) {
					continue;
				}
				else {
					float num5 = (float)m4[f] / (float)m2[f];
					total += num5;
				}
			}
		}
		cout << "total: " << total << "\n";

		ans.push_back(make_pair(total, idx3));

		iter++;
		
	}
	sort(ans.begin(), ans.end(), cmp);
	/*for (int i = 0; i < ans.size(); i++) {
		cout << "ss: " << ans[i].first << " " << ans[i].second << "\n";
	}*/
	cout << ans[0].first;
	

	
	
}