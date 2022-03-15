#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <string>



using namespace std;

bool check[10001];

vector<pair<string, int>> v; //µµÂøÁö, ÇØ´ç ÀÎµ¦½º
vector <string> ans;

vector <vector <string>> answer;

void dfs(string start, vector<vector<string>> tickets) {
	
	

	for (int i = 0; i < tickets.size(); i++) {
		if (tickets[i][0] == start&&!check[i]) {
			v.push_back(make_pair(tickets[i][1], i));
		}
	}
	if (v.size() != 0) {
		sort(v.begin(), v.end());
		int idx = v[0].second;
		string s = v[0].first;
		while (v.size() != 0) {
			v.pop_back();
		}
		if (!check[idx]) {
			check[idx] = true;
			ans.push_back(s);
			dfs(s, tickets);
		}
	}
	
}

void dfs2(string start, vector<vector<string>> tickets,int cnt) {
	if (cnt == tickets.size()) {
		answer.push_back(ans);
		return;
	}

	for (int i = 0; i < tickets.size(); i++) {
		if (tickets[i][0] == start && !check[i]) {
			check[i] = true;
			ans.push_back(tickets[i][1]);
			dfs2(tickets[i][1], tickets, cnt + 1);
			check[i] = false;
			ans.pop_back();

		}
	}
	
	
}






vector<string> solution(vector<vector<string>> tickets) {
	vector<string> answer;
	return answer;
}

 
int main(void) {
	vector<vector<string>> tickets = {
		{"ICN", "SFO"} ,{"ICN", "ATL"},{"SFO", "ATL"},{"ATL", "ICN"},{"ATL","SFO"}
	};
	ans.push_back("ICN");
	dfs2("ICN",tickets,0);
	sort(answer.begin(), answer.end());
	for (int i = 0; i < answer[0].size(); i++) {
		cout << answer[0][i] << " ";
	}
	


	
	

	
	


	
	

}