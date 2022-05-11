#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;
int T;
int n, m, t, s, g, h;
int a, b, d,c;
int INF = 987654321;
vector <int> ans;
vector <int> v2; //목적지 후보
vector <pair<int, int>> v[2001]; //끝 가중치 , [시작]
int dist[2001]; //s의 최단거리
int dist2[2001]; //h의 최단거리
int dist3[2001]; //g의 최단거리
bool check[2001];
//s+g+h+목적지 , s+h+g+목

void init(int n) {
	for (int i = 0; i <= n; i++) {
		dist[i] = INF;
		dist2[i] = INF;
		dist3[i] = INF;

   }
}
void init2(int n) {
	for (int i = 0; i <= n; i++) {
		
		dist2[i] = INF;
	}
}
void init3(int n) {
	for (int i = 0; i <= n; i++) {
		check[i] = false;
	}
}
void dijkstra(int s1) {
	priority_queue <pair<int, int>> pq; //가중치, 끝
	dist[s1] = 0;
	pq.push(make_pair(0, s1));
	while (!pq.empty()) {
		int start = pq.top().second;
		int di = -pq.top().first;
		pq.pop();
		if (di > dist[start]) {
			continue;
		}
		for (int i = 0; i < v[start].size(); i++) {
			int end2 = v[start][i].first;
			int num3 = v[start][i].second;
			
			if (num3 + di < dist[end2]) {
				dist[end2] = num3 + di;
				pq.push(make_pair(-dist[end2], end2));
			}

		}
	}

}
void dijkstra2(int h1) {
	priority_queue <pair<int, int>> pq; //가중치, 끝
	dist2[h1] = 0;
	pq.push(make_pair(0, h1));
	while (!pq.empty()) {
		int start = pq.top().second;
		int di = -pq.top().first;
		pq.pop();
		if (di > dist2[start]) {
			continue;
		}
		for (int i = 0; i < v[start].size(); i++) {
			int end = v[start][i].first;
			int num3 = v[start][i].second;
			
			if (num3 + di< dist2[end]) {
				dist2[end] = num3 + di;
				pq.push(make_pair(-dist2[end], end));
			}

		}
	}

}
void dijkstra3(int h2) {
	priority_queue <pair<int, int>> pq; //가중치, 끝
	dist3[h2] = 0;
	pq.push(make_pair(0, h2));
	while (!pq.empty()) {
		int start = pq.top().second;
		int di = -pq.top().first;
		pq.pop();
		if (di > dist3[start]) {
			continue;
		}
		for (int i = 0; i < v[start].size(); i++) {
			int end = v[start][i].first;
			int num3 = v[start][i].second;

			if (num3 + di < dist3[end]) {
				dist3[end] = num3 + di;
				pq.push(make_pair(-dist3[end], end));
			}

		}
	}

}

int main(void) {
	cin >> T;
	while (T--) {
		cin >> n >> m >> t;
		cin >> s >> g >> h;
		ans.clear();
		init3(n);
		v2.clear();
		for (int i = 0; i < m; i++) {
			cin >> a >> b >> d;
			v[a].push_back(make_pair(b, d));
			v[b].push_back(make_pair(a, d));
		}
		for (int i = 0; i < t; i++) {
			cin >> c;
			v2.push_back(c);
		}
		init(n);
		dijkstra(s);
		dijkstra2(h);
		dijkstra3(g);
		//s->g->h->end or s->h->g->end
		
		for (int i = 0; i < v2.size(); i++) {
			int end = v2[i];
			if (dist[end] != INF ) {
				if (dist[end] == (dist[h] + dist2[g] + dist3[end])|| dist[end] == (dist[g] + dist2[end] + dist3[h])) {
					if (!check[end]) {
						ans.push_back(end);
						check[end] = true;
					}
				}
			}
			
		

			
			


		}
		if (ans.size() != 0) {
			sort(ans.begin(), ans.end());
			
			for (int j = 0; j < ans.size(); j++) {
				cout << ans[j]<< " ";
			}
			cout << "\n";
		}

		for (int i = 0; i <= n; i++) {
			v[i].clear();

		}
		



		
	}
}