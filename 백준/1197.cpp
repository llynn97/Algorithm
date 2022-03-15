
#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int v, e, a, b, c;
int ans = 0;
vector <pair<int, pair<int, int>>> node; //가중치, 시작점, 끝점
int parent[10001];

int find(int x) {
	if (parent[x] == x) {
		return x;
	}
	else {
		
		return parent[x] = find(parent[x]);

	}
}
void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) {
		return;
	}
	parent[y] = x;
}


int main(void) {
	cin >> v >> e;
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		node.push_back(make_pair(c, make_pair(a, b)));
	}
	sort(node.begin(), node.end());
	
	for (int i = 1; i <= v; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < node.size(); i++) {
		int start = node[i].second.first;
		int end = node[i].second.second;
		int num = node[i].first;
		if (find(start) != find(end)) {
			ans += num;
		}
		merge(start, end);
		
	}

	cout << ans;


}