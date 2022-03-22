#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

vector<int> a; //2<=a<=300000
vector<vector<int>> edges;
vector <int> v[300001];
long long answer;



long long solution(vector<int> a, vector<vector<int>> edges) {
	long long answer = -2;
	return answer;
}


void dfs(int parent,int now,vector<long long> &sum) {
	for (int i = 0; i < v[now].size(); i++) {
		if (v[now][i]!=parent) {
			dfs(now, v[now][i], sum);
		}
		sum[parent] += sum[now];
		answer += abs(sum[now]);
		

	}
	
}

int main(void) {
	
	a = { -5,0,2,1,2 }; //°¡ÁßÄ¡
	vector<long long> sum(a.size());
	edges = { {0,1} ,{3,4},{2,3},{0,3} };
	for (int i = 0; i < a.size(); i++) {
		sum[i] = a[i];
	}

	for (int i = 0; i < edges.size(); i++) {
		v[edges[i][0]].push_back(edges[i][1]);
		v[edges[i][1]].push_back(edges[i][0]);
	}


	dfs(0, 0, sum);
	if (sum[0] == 0) {
		cout<< answer;

	}
	else {
		cout<< -1;
	}





}