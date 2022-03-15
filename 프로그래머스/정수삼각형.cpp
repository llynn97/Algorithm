#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


vector <int> v[50];
vector <int> v2[501];

bool compare(int a, int b) {
	return a > b;
}

int solution(vector<vector<int>> triangle) {
	int answer = 0;
	return answer;
}


int main(void) {

	vector<vector<int>> triangle = {
		{7} ,{3, 8},{8, 1, 0},{2, 7, 4, 4},{4, 5, 2, 6, 5}
	};
	int n = 0;
	n = triangle.size();
	int am = 0;
	
	v[0].push_back(triangle[0][0]);
	v[1].push_back(triangle[0][0] + triangle[1][0]);
	v[1].push_back(triangle[0][0] + triangle[1][1]);

	v2[0].push_back(triangle[0][0]);
	v2[1].push_back(triangle[0][0] + triangle[1][0] + triangle[1][1]);
	v2[1].push_back(triangle[0][0] + triangle[1][1] + triangle[1][0]);


	
	
/*	for (int i = 0; i <n; i++) {
		for (int j = 0; j < triangle[i].size(); j++) {
			cout << triangle[i][j] << " ";

		}
		cout << "\n";
	}*/
	

	for (int i = 2; i < triangle.size(); i++) {
		for (int j = 0; j < triangle[i].size(); j++) {
			if (j == 0) {
				
				v[i].push_back(v[i - 1][j] + triangle[i][j]);
			}
			else if (j == (triangle[i].size() - 1)) {
				
				v[i].push_back(v[i - 1][j - 1]+triangle[i][j]);
			}
			else {
				int a=max(v[i - 1][j] + triangle[i][j], v[i - 1][j - 1] + triangle[i][j]);
				
				v[i].push_back(a);
			}
		}
		/*for (int j = 0; j < triangle[i].size(); j++) {
			if (j == 0) {
				int a = max(v[i][j], v[i][j + 1] + triangle[i][j]);
				v2[i].push_back(a);
			}
			else if (j == (triangle[i].size() - 1)) {
				int a = max(v[i][j], v[i][j - 1] + triangle[i][j]);
				v2[i].push_back(a);
			}
			else {
				int a = max(v[i][j - 1] + triangle[i][j], v[i][j + 1] + triangle[i][j]);
				int b = max(a, v[i][j]);
				v2[i].push_back(b);
			}
		}*/
	}

	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < v[i].size(); j++) {
			cout << v[i][j] << " ";
		}
		cout << "\n";
	}*/
	/*for (int i = 0; i < v2[n - 1].size(); i++) {
		cout << v2[n - 1][i]<<" " ;
	}*/
	sort(v[n - 1].begin(), v[n - 1].end(),compare);
	

    	cout << v[n - 1][0];

	//높이 1일때 잡아주기

}