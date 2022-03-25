#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;
int cacheSize;
vector<string> cities;
priority_queue <pair<int, string>> pq;
vector <pair<int, string>> v;
int answer = 0;

int solution(int cacheSize, vector<string> cities) {
	int answer = 0;
	return answer;
}

int main(void) {
	cacheSize = 0;
	cities = { "LA", "LA" };
	for (int i = 0; i < cities.size(); i++) {
		for (int j = 0; j < cities[i].size(); j++) {
			cities[i][j] = toupper(cities[i][j]);
		}
	}
	pq.push(make_pair(1, cities[0]));
	
	answer = 5;
	for (int i = 1; i < cities.size(); i++) {
		bool check = false;
		while (!pq.empty()) {
		  int time=	pq.top().first+1;
		  string str = pq.top().second;
		  pq.pop();
		  if (cities[i] == str && cacheSize!=0) {
			  time = 1;
			  check = true;
			  answer += 1;
		  }
		  v.push_back(make_pair(time, str));
		}
		/*for (int j = 0; j < v.size(); j++) {
			cout << v[j].first << " " << v[j].second << "\n";
		}*/
		for (int j = 0; j < v.size(); j++) {
			pq.push(make_pair(v[j].first, v[j].second));
		}
		v.clear();
		if (check == false) {
			if (pq.size() >= cacheSize) {
				pq.pop();
				

			}
			pq.push(make_pair(1, cities[i]));
			answer += 5;
		}
	}

	cout << answer;

}