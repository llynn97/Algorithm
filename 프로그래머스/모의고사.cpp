#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

vector<int> answers;
vector<int> answer;
int one[] = { 1,2,3,4,5 }; //5
int two[] = { 2,1,2,3,2,4,2,5 }; //8
int three[] = { 3,3,1,1,2,2,4,4,5,5 }; //10
int ans[4];
int maxi = -1;

vector<int> solution(vector<int> answers) {
	vector<int> answer;
	return answer;
}

 // 1-> 1,2,3,4,5   2-> 2,1,2,3,2,4,2,5  3-> 3,3,1,1,2,2,4,4,5,5
int main(void) {
	answers = {
		1,3,2,4,2
	};
	                                           // 0 1 2 3 4
	for (int i = 0; i < answers.size(); i++) { // 1,2,3,4,5
		int num = answers[i];
		if (one[i % 5] == num) {
			ans[1] ++;
		}
		if (two[i % 8] == num) {
			ans[2]++;
		}
		if (three[i % 10] == num) {
			ans[3]++;
		}

	}
	/*for (int i = 1; i <= 3; i++) {
		cout << ans[i]<<" ";
	}
	cout << "\n";*/
	maxi = max(ans[1], ans[2]);
	maxi = max(maxi, ans[3]);
	cout << maxi << "\n";
	for (int i = 1; i <= 3; i++) {
		if (maxi == ans[i]) {
			answer.push_back(i);
		}
	}

		sort(answer.begin(), answer.end());
		for (int i = 0; i < answer.size(); i++) {
			cout << answer[i] << " ";
		}
	


}