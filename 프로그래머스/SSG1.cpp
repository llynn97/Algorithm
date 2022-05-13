#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;


bool cmp(int a, int b) {
	return a > b;
}

int main(void) {

	vector<int> v = { 4,5,5 };
	int a = 2;
	int b = 1;
	int cnt = 0;
	
	if (v.size() == 1) {
		cnt = v[0] / 2;
	}
	else {
		sort(v.begin(), v.end(), cmp);
		bool check = false;
		while (true) {
			if (v[0] < a) {
				break;
			}
			for (int i = 0; i < v.size(); i++) {
				if (v[i] < b) {
					break;
				}
			}
			cnt++;

			v[0] -= 2;
			for (int i = 0; i < v.size(); i++) {
				v[i] -= 1;
			}
			sort(v.begin(), v.end(), cmp);


		}

		cout << cnt;
	}
	
	

}