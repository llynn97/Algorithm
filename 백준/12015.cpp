#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

int n;
int map[1000001];
int map2[1000001];
int answer = 0;
vector <int> sequence;
set <string> s;

void binary_search(int num) {
	int start = 0; 
	int end = sequence.size() - 1;
	int ret = end;
	while (start <= end) {
		int mid = (start + end) / 2;
		int num1 = sequence[mid];
		if (num1 >= num) {
			if (ret > mid) {
				ret = mid;
			}
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}
	sequence[ret] = num;
}
int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}
	sequence.push_back(map[0]);
	for (int i = 1; i < n; i++) {
		if (sequence.back() < map[i]) {
			sequence.push_back(map[i]);
		}
		else {
			binary_search(map[i]);
		}
	}
	
	
	cout << sequence.size();

}