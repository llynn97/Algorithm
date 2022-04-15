#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <map>


using namespace std;
bool check[11];
vector <char> s;
map <int,int> m;
int k;
int answer = 0;

int solution(string numbers) {
	int answer = 0;
	return answer;
}
//1=>x
void init() {
	for (int i = 0; i < 11; i++) {
		check[i] = false;
	}
}


bool numCheck(int num) { //true:¼Ò¼ö
	int cnt = 0;
	int idx = 2;
	int check2 = false;
	while (true) {
		if (idx >= num) {
			break;
		}
		if (num % idx == 0) {
			check2 = true;
			cnt++;
			break;
		}
		idx++;
	}
	if (cnt == 0) {
		return true;
	}
	else {
		return false;
	}
}

void dfs(int cnt, string numbers) {
	if (cnt == k) {
		string str = "";
		for (int i = 0; i < s.size(); i++) {
			str += s[i];
		}
		int a = stoi(str);
		if (a > 1) {
			if (numCheck(a)) {
				if (m.find(a) == m.end()) {
					m[a] = 1;
					cout << a << "\n";
					answer++;
				}
			}
		}
		
				
	}
	for (int i = 0; i < numbers.length(); i++) {
		if (!check[i]) {
			s.push_back(numbers[i]);
			check[i] = true;
			dfs(cnt + 1, numbers);
			check[i] = false;
			s.pop_back();
		}
	}

}

int main(void) {

	string numbers = "17";
	
	for (int i = 1; i <= numbers.size(); i++) {
		k = i;
		init();
		dfs(0, numbers);
		
	}
	
	cout << answer;

}