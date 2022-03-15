#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, ans;
int parent[100001];
vector <pair<int, pair<int, int>>> edge;
vector <int> v;

int find_parent(int x) {
	if (x == parent[x]) {
		return x;
	}
	else {
		return parent[x] = find_parent(parent[x]);
	}
}

void Union(int x, int y) {
	x = find_parent(x);
	y = find_parent(y);
	if (x == y) {
		return;
	}
	parent[y] = x;
	
}


int main(void) {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edge.push_back(make_pair(c, make_pair(a, b)));
	}
	sort(edge.begin(), edge.end());
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < edge.size(); i++) {
		int start = edge[i].second.first;
		int end = edge[i].second.second;
		int num = edge[i].first;
		if (find_parent(start) != find_parent(end)) {
			Union(start, end);
			v.push_back(num);
		}

		
	}

	for (int i = 0; i < v.size() - 1; i++) {
		ans += v[i];
	}
	cout << ans;
}