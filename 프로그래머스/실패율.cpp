#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
int N;
vector<int> stages;
vector<int> answer;
bool check[501];
vector <pair<double, int>> v;
vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;
	return answer;
}

bool cmp(pair <double, int> a, pair <double, int> b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	else {
		return a.first > b.first;
	}
}


int main(void) {
	
	N = 5;
	stages = { 2, 1, 2, 6, 2, 4, 3, 3 };
	int num = stages.size();
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		cnt = 0;
		for (int j = 0; j < stages.size(); j++) {
			//cout << "i: " << i << "\n";
			//cout << "j: " << stages[j] << "\n";
			if ((stages[j] < (i + 1)) && !check[j]) {
				cnt += 1;
				check[j] = true;
			}
		}
		cout << "num: " << num << "\n";
		cout << "cnt: " << cnt << "\n";
		if (num == 0 || cnt==0) {
			v.push_back(make_pair(0, i));
		}
		else {
			double per = (double)cnt / (double)num;
			v.push_back(make_pair(per, i));
		}
		
		

			
		num = num - cnt;
	}
	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << " " << v[i].second << "\n";
	}

	for (int i = 0; i < v.size(); i++) {
		answer.push_back(v[i].second);
	}

	for (int i = 0; i < v.size(); i++) {
		cout << answer[i] << " \n";
	}


}