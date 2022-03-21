#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
using namespace std;
vector<int> a;
map <int, int> visited;
int answer = -1;
int len = 0;

int solution(std::vector<int> a) {
	int answer = -1;
	return answer;
}


int main(void) {
	a = { 0,3,3,0,7,2,0,2,2,0 };
	for (int i = 0; i < a.size(); i++) {
		int num = a[i];
		visited[num]++;
	}
	for (auto u : visited) {// 0: 4
		if (u.second * 2 <= answer) {
			continue;
		}
		len = 0;
		for (int i = 0; i < a.size()-1; i++) {
			if (a[i] != a[i + 1] && a[i] == u.first) {
				i += 1;
				len += 2;
			}
			/*if (a[i] == a[i + 1]) {
				continue;
			}
			if (a[i] != u.first && a[i + 1] != u.first) {
				continue;
			}
			len += 2;
			i++;*/
		}
		answer =max(answer,len);
	}

	cout << answer;
}