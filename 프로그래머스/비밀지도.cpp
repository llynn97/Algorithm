#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

int n;
vector<int> arr1;
vector<int> arr2;
vector <int> v;
char map[17][17];
vector<string> answer;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> answer;
	return answer;
}

int main(void) {
	n = 5;
	arr1 = { 9, 20, 28, 18, 11 };
	arr2 = { 30, 1, 21, 17, 28 };
	for (int i = 0; i < arr1.size(); i++) {
		int num = arr1[i];
		while (true) {
			if (num <= 1) {
				v.push_back(num);
				break;
			}
			v.push_back(num % 2);
			num /= 2;
		}
		/*for (int j = v.size()-1; j>=0; j--) {
			cout << v[j];
		}
		cout << "\n";*/
		int idx = n - 1;
		for (int j = 0; j <v.size(); j++) {
			if (v[j] == 1) {
				map[i][idx] = '#';
			}
		
			idx--;
		}
		v.clear();
	}
	for (int i = 0; i < arr2.size(); i++) {
		int num = arr2[i];
		while (true) {
			if (num <= 1) {
				v.push_back(num);
				break;
			}
			v.push_back(num % 2);
			num /= 2;
		}
		/*for (int j = v.size()-1; j>=0; j--) {
			cout << v[j];
		}
		cout << "\n";*/
		int idx = n - 1;
		for (int j = 0; j < v.size(); j++) {
			if (v[j] == 1) {
				map[i][idx] = '#';
			}
		
			idx--;
		}
		v.clear();
	}
	string s = "";
	for (int i = 0; i < n; i++) {
		s = "";
		for (int j = 0; j < n; j++) {
			if (map[i][j] == '#') {
				s += map[i][j];
			}
			else {
				s += ' ';
			}
		}
		answer.push_back(s);
		
	}
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << "\n";
	}

}