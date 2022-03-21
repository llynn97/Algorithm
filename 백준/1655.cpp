#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>


using namespace std;

int n;
int x;
vector <int> v;
vector <int> map;
priority_queue <int> maxheap; //root가 최대 
priority_queue <int> minheap; //root가 최소 -

int main(void) {

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		map.push_back(x);
	}
	
	for (int i = 0; i < n; i++) {
		
		if (maxheap.size() == 0 ) {
			maxheap.push(map[i]);
			cout << maxheap.top()<<" ";
		}
		else if (minheap.size() == 0) {
			minheap.push(-map[i]);
			if (maxheap.top() > -minheap.top()) {
				int tmp1 = maxheap.top();
				int tmp2 = -minheap.top();
				maxheap.pop();
				minheap.pop();
				minheap.push(-tmp1);
				maxheap.push(tmp2);
				
			}
			cout << maxheap.top() << " ";
		}
		else {
			if (maxheap.size() == minheap.size()) {
				maxheap.push(map[i]);
			}
			else {
				minheap.push(-map[i]);
			}
			if (maxheap.top() > -minheap.top()) {
				int tmp1 = maxheap.top();
				int tmp2 = -minheap.top();
				maxheap.pop();
				minheap.pop();
				minheap.push(-tmp1);
				maxheap.push(tmp2);

			}
			cout << maxheap.top() << " ";
		}
		
	}

}