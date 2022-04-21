#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
vector <string> v[9];
map <string, int> m;
set <string> s1;
vector <int> v3[9]; // user_id 인덱스 넣어주기
vector <string> str;
int bsize, usize;
bool check[9];
int answer = 1;

int solution(vector<string> user_id, vector<string> banned_id) {
	int answer = 0;
	return answer;
}
void dfs(int idx, string s , vector<string> user_id, vector<string> banned_id) {
	if (idx == bsize) {
		sort(s.begin(), s.end());
		cout << "s: "<<s << "\n";
		s1.insert(s);

		return;
	}

	for (int i = 0; i < user_id.size(); i++) {
		string a = banned_id[idx];
		if (check[i]) {
			continue;
		}
		bool flag = false;
		if (user_id[i].length() == a.length()) {
			int num = 0;
			for (int k = 0; k < a.length(); k++) {
				if (a[k] == '*') {
					num++;
				}
				else if (a[k] == user_id[i][k]) {
					num++;
				}
			}
			if (num == a.length()) {

				flag = true;

			}
			if (flag && !check[i]) {
				check[i] = true;
				dfs(idx + 1, s + to_string(i), user_id, banned_id);
				check[i] = false;
			}
		}

	}


}
int main(void) {

	vector<string> user_id = { "frodo", "fradi", "crodo", "abc123", "frodoc" };
	vector<string> banned_id = { "fr*d*", "abc1**" };
	bsize = banned_id.size();
	dfs(0, "", user_id, banned_id);
	cout << s1.size();


}
	