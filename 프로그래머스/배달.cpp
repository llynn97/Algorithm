#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;
vector<vector<int> > road;
vector <pair<int, int>> v[51];   //끝 시간, [시작]

int N, K;  //n: 마을 개수  k:가능한 시간
int answer = 0;
bool check2; //
int map[51];
int INF = 500001;

int solution(int N, vector<vector<int> > road, int K) {
	int answer = 0;

	// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
	cout << "Hello Cpp" << endl;

	return answer;
}

void dikstra( int x ) {
	map[x] = 0;
	priority_queue <pair<int, int>> pq; //가중치, 시작
	pq.push(make_pair(0, x));
	while(!pq.empty()) {
		int start = pq.top().second;
		int num =- pq.top().first;
		pq.pop();
		if (map[start] < num) {
			continue;
		}
		for (int i = 0; i < v[start].size(); i++) {
		
			if (map[v[start][i].first] > num + v[start][i].second) {
				map[v[start][i].first] = num + v[start][i].second;
				pq.push(make_pair(-map[v[start][i].first], v[start][i].first));

			}
			
		}
	}




 }




int main(void) {

	road = {
		{1,2,1} ,{1,3,2},{2,3,2},{3,4,3},{3,5,2},{3,5,3},{5,6,1}
	};
	N = 6;
	K = 4;
	for (int i = 0; i < road.size(); i++) {
		int x = road[i][0];
		int y = road[i][1];
		int z = road[i][2];
		v[x].push_back(make_pair(y, z));
		v[y].push_back(make_pair(x, z));

	}
	for (int i = 0; i <= N; i++) {
		map[i] = INF;
	}
	
	dikstra(1);
	for (int i = 1; i <= N; i++) {
		if (map[i] <= K) {
			answer++;
		 }
	}






}
