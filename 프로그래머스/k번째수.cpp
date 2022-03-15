#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

vector<int> arrays;
vector<vector<int>> commands;
vector<int> answer;
vector <int> num;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;
	return answer;
}


int main(void) {
	arrays = {
		1, 5, 2, 6, 3, 7, 4
	};

	commands = {
		{2, 5, 3} ,{4, 4, 1},{1, 7, 3}
	};

	for (int i = 0; i < commands.size(); i++) {
		int start = commands[i][0]-1;
		int end = commands[i][1]-1;
		int k = commands[i][2]-1;
		for (int j = start; j <= end; j++) {
			num.push_back(arrays[j]);
		}
		sort(num.begin(), num.end());
		answer.push_back(num[k]);
		num.clear();

	}

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
	}

}