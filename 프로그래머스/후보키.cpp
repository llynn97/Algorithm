#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>


using namespace std;
vector<vector<string>> relation;
vector <int> num;
vector <int> v;
vector <string> finds; 
int answer = 0;

vector <string> str; //후보키 인덱스 문자열

bool check[9];
int n;
int solution(vector<vector<string>> relation) {
	int answer = 0;
	return answer;
}

void dfs(int cnt) {
	if (cnt == n) {
		string s = "";
		for (int i = 0; i < v.size(); i++) {
			s += to_string(v[i]);
		}
		
		
		int t = str.size();
		int cnt3 = 0;
		int idx = 0;
		int check1 = 0;
		for (int i = 0; i < str.size(); i++) {
			int check5 = 0;
			for (int j = 0; j < s.size(); j++) {
				for (int k = 0; k < str[i].size(); k++) {
					if (s[j]==str[i][k]) {
						check5++;
					}
				}
			 }
			if (check5 == str[i].size()) {
				check1++;
			}
			
		}
		
		if (check1==0) {
			int num4 = 0;
			for (int i = 0; i < relation.size(); i++) {
				string aa = "";
				for (int j = 0; j < v.size(); j++) {
					aa += relation[i][v[j]];
				}
				int num3 = 0;
				for (int j = 0; j < finds.size(); j++) {
					if (finds[j] == aa) {
						num3++;
					}
				}
				if (num3 == 0) {
					finds.push_back(aa);
					num4++;
				}
			}
			if (num4 == relation.size()) {
				str.push_back(s);
				answer++;

			}
			
			finds.clear();
		}
		return;
	}
	for (int i = 0; i < num.size(); i++) {
		if (!check[num[i]]&& (v.size()==0 || v.back()<num[i])) {
			check[num[i]] = true;
			v.push_back(num[i]);
			dfs(cnt + 1);
			check[num[i]] = false;
			v.pop_back();
		}
	}

}


int main(void) {
	relation = { {"a","1","aaa","c","ng"},
{"a","1","bbb","e","g"},
{"c","1","aaa","d","ng"},
{"d","2","bbb","d","ng"}};
	int r = relation.size(); //행
	int c = relation[0].size(); //열
	for (int i = 0; i < c; i++) {
		num.push_back(i);
	}
	for (int k = 1; k <= c; k++) {
		n = k;
		dfs(0);
	}
	for (int i = 0; i < str.size(); i++) {
		cout << str[i] << " ";
	}

	cout << answer;
	
}