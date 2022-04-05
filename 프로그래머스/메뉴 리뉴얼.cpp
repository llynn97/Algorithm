#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
int num = 0;
vector <char> v;
vector <string> v1; //dfs에서 cnt==num일때 string 모두 넣음
vector <string> v2;
vector <string> answer;
vector <pair<int, string>> v3;

bool check[11];
vector<string> solution(vector<string> orders, vector<int> course) {
	vector<string> answer;
	return answer;
}

bool cmp(pair<int, string> a, pair<int, string> b) {
	return a.first > b.first;
}

void init() {
	for (int i = 0; i < 11; i++) {
		check[i] = false;
	}
}
void per(string s,int cnt) {
	if (cnt == num) {
		string str = "";
		for (int j = 0; j < v.size(); j++) {
			str += v[j];
		}
	
		
		v1.push_back(str);

		return;
	}
	for (int i = 0; i < s.length(); i++) {
		if (!check[i] && (v.size()==0||v.back()<s[i])) {
			check[i] = true;
			v.push_back(s[i]);
			per(s, cnt + 1);
			check[i] = false;
			v.pop_back();
		}
	}
}

int main(void) {
	vector<string> orders;
	vector<int> course;
	orders = { "ABCDE", "AB", "CD", "ADE", "XYZ", "XYZ", "ACD" };
	course = { 2,3,5 };
	for (int i = 0; i < orders.size(); i++) {
		sort(orders[i].begin(), orders[i].end());
	}
	for (int i = 0; i < course.size(); i++) {
		num = course[i];
		v3.clear();
		//check배열 초기화
		for (int j = 0; j < orders.size(); j++) {
			v1.clear();
			v.clear();
			init();
			per(orders[j], 0);
			for (int k = 0; k < v1.size(); k++) {
				cout << v1[k] << " ";
			}
			cout << "\n";
			for (int k = 0; k < v1.size(); k++) { //order[i]의 string조합 ab ac
				bool check2 = false;
				for (int p = 0; p < v2.size(); p++) {
					if (v2[p] == v1[k]) {
						check2 = true;
					}
				}
				if (!check2) {//아직 ac 조합이 없을때
					int cnt2 = 1;
					for (int p = 0; p < orders.size(); p++) {
						if (p != j) {
							int cnt3 = 0;
							for (int s = 0; s < v1[k].length(); s++) {
								for (int t = 0; t < orders[p].size(); t++) {
									if (v1[k][s] == orders[p][t]) {
										cnt3++;
									}
								}
							}
							if (cnt3 == v1[k].length()) {
								cnt2++;
							}
							
						}
					}
					if (cnt2 >= 2) {
						v2.push_back(v1[k]);
						v3.push_back(make_pair(cnt2, v1[k]));
						//answer.push_back(make_pair(cnt2,v1[k]));
					}

				}
			}
		}
		sort(v3.begin(), v3.end(), cmp);
		if (v3.size() == 1) {
			answer.push_back(v3[0].second);
		}
		else if (v3.size() > 1) {
			int num4 = 0;
			for (int t = 1; t < v3.size(); t++) {
				if (v3[0].first == v3[t].first) {
					num4++;
				}
			}
			if (num4 == 0) {
				answer.push_back(v3[0].second);
			}
			else {
				for (int t =0; t < v3.size(); t++) {
					if (v3[0].first == v3[t].first) {
						answer.push_back(v3[t].second);
					}
				}
			}
		}
		
		
	}
	sort(answer.begin(), answer.end());
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << "\n";
	}
	
}