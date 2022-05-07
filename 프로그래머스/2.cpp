#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <queue>

using namespace std;

long long total = 0;
vector<int> queue3;
queue <int> queue4;
queue<int> queue5;

long long cnt2 = 100000;




int solution(vector<int> queue1, vector<int> queue2) {
	int answer = -2;
	return answer;
}

int main(void) {

	vector<int> queue1 = { 3, 2, 7, 2 };
	vector<int> queue2 = { 4, 6, 5, 1 };
	for (int i = 0; i < queue1.size(); i++) {
		total += queue1[i];
	}
	for (int i = 0; i < queue2.size(); i++) {
		total += queue2[i];
	}
	cout << total << "\n";
	for (int i = 0; i < queue1.size(); i++) {
		queue3.push_back(queue1[i]);
	}
	for (int i = 0; i < queue2.size(); i++) {
		queue3.push_back(queue2[i]);
	}
	
	if (total % 2 != 0) {
		cout << "-1";
	}
	else {
		long long start = 0;
		for (int k = 0; k < queue3.size() - 1; k++) {
			start = k;
			long long end = queue3.size() - 1;
			while (start <= end) {
				long long mid = (start + end) / 2;
				long long que1 = 0;

				for (long long i = start; i <= mid; i++) {
					que1 += queue3[i];
				}
				cout << "que1 : " << que1 << "\n";
				if (que1 == (total / 2)) {
					cout << "들어왔음====\n";
					long long cnt3 = 0;
					for (long long i = 0; i < queue1.size(); i++) {
						queue4.push(queue1[i]);
					}
					for (long long i = 0; i < queue2.size(); i++) {
						queue4.push(queue2[i]);
					}
					cout << "DDDDd\n";
					while (true) {
						if ((queue4.front() == queue3[start])){
							if (mid-queue1.size()+1>=1) {
								
							}
							else {

							}
							if (mid != queue3.size() - 1 && mid-queue1.size()!=queue1.size()-1) {
								
							}
							"ok====\n";
							cnt2 = min(cnt3, cnt2);
							break;
						}
						
						int num7 = queue4.front();
						queue4.pop();

						queue4.push(num7);
						cnt3++;
					}
					while (!queue4.empty()) {
						queue4.pop();
					}
					while (!queue5.empty()) {
						queue5.pop();
					}
					for (long long i = 0; i < queue1.size(); i++) {
						queue4.push(queue1[i]);
					}
					for (long long i = 0; i < queue2.size(); i++) {
						queue5.push(queue2[i]);
					}
					cnt3 = 0;
					while (true) {
						if ((queue4.front() == queue3[start] && queue4.back() == queue3[mid]) || (queue5.front() == queue3[start] && queue5.back() == queue3[mid])) {
							cnt2 = min(cnt3, cnt2);
							break;
						}
						int num7 = queue5.front();
						queue5.pop();

						queue4.push(num7);
						cnt3++;
					}
					while (!queue4.empty()) {
						queue4.pop();
					}
					while (!queue5.empty()) {
						queue5.pop();
					}


				}
				if (que1 > (total / 2)) {
					start = mid + 1;
				}
				if (que1 < (total / 2)) {
					end = mid - 1;
				}

			}

		}
		
		/*long long end = queue3.size() - 1;
		while (start<=end) {
			long long mid = (start + end) / 2;
			long long que1 = 0;
			
			for (long long i = start; i <= mid; i++) {
				que1 += queue3[i];
			}
			cout << "que1 : " << que1 << "\n";
			if (que1 == (total / 2)) {
				cout << "들어왔음====\n";
				long long cnt3 = 0;
				for (long long i = 0; i < queue1.size(); i++) {
					queue4.push(queue1[i]);
				}
				for (long long i = 0; i < queue2.size(); i++) {
					queue5.push(queue2[i]);
				}
				while (true) {
					if ((queue4.front() == queue3[start] && queue4.back() == queue3[mid])|| (queue5.front() == queue3[start] && queue5.back() == queue3[mid]))  {
						cnt2 = min(cnt3, cnt2);
						break;
					}
					int num7 = queue4.front();
					queue4.pop();
					
					queue5.push(num7);
					cnt3++;
				}
				while (!queue4.empty()) {
					queue4.pop();
				}
				while (!queue5.empty()) {
					queue5.pop();
				}
				for (long long i = 0; i < queue1.size(); i++) {
					queue4.push(queue1[i]);
				}
				for (long long i = 0; i < queue2.size(); i++) {
					queue5.push(queue2[i]);
				}
				cnt3 = 0;
				while (true) {
					if ((queue4.front() == queue3[start] && queue4.back() == queue3[mid]) || (queue5.front() == queue3[start] && queue5.back() == queue3[mid])) {
						cnt2 = min(cnt3, cnt2);
						break;
					}
					int num7 = queue5.front();
					queue5.pop();

					queue4.push(num7);
					cnt3++;
				}
				while (!queue4.empty()) {
					queue4.pop();
				}
				while (!queue5.empty()) {
					queue5.pop();
				}


			}
			if (que1 > (total / 2)) {
				start = mid + 1;
			}
			if (que1 < (total / 2)) {
				end = mid - 1;
			}
			
		}*/


	}

	cout << cnt2;
}