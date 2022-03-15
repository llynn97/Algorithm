#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

string skill;
vector<string> skill_trees;
int answer = 0;
vector <int> v;

int solution(string skill, vector<string> skill_trees) {
	int answer = -1;
	return answer;
}

int main(void) {
	skill = "CBD";
	skill_trees = {
		"BACDE", "CBADF", "AECB", "BDA"

	};

	for (int i = 0; i < skill_trees.size(); i++) {
		v.clear();
		int k = 1;
		string s = skill_trees[i];
		int ans = 0;
		for (int j = 0; j< skill.length(); j++) {
			
			if (s.find(skill[j]) != string::npos) {
				
				v.push_back(s.find(skill[j]));
			}
			
		}
		if (v.size() == 0 ) {
			answer++;
			cout << skill_trees[i]<<"\n";
		}
		else {

			if (v.size() == skill.length()) {
				for (int j = 0; j < v.size() - 1; j++) {
					if (v[j] < v[j + 1]) {
						k++;
					}
				}
				if (k == v.size()) {
					answer++;
					cout << skill_trees[i] << "\n";
				}
			}
			else {
				if (v.size() == 1) {
					int idx=skill.find(s[v[0]]);
					if (idx == 0) {
						answer++;
						cout << skill_trees[i] << "\n";
					}
				}
				else {
					for (int j = 0; j < v.size() - 1; j++) {
						if (v[j] < v[j + 1]) {
							k++;
						}
					}
					if (k == v.size()) {
						int count = 0;
						for (int j = 0; j < v.size(); j++) {
							if (s.find(skill[j]) != string::npos) {
								count++;
							}
						}
						if (count == v.size()) {
							answer++;
							cout << skill_trees[i] << "\n";
						}
					}
				}
				

			}

		}
		
	}

	cout << answer;
}