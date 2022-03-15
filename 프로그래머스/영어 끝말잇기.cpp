#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int n;
vector<string> words;
char str;
vector <string>  v;
int ans1;
int ans2;
bool check2;

vector<int> solution(int n, vector<string> words) {
	vector<int> answer;

	// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다. 
	cout << "Hello Cpp" << endl;

	return answer;
}

int main(void) {
	words = {
		"land","dream","mom","mom","ror"
	};
	int n = 2;
	str = words[0][words[0].length() - 1];
	v.push_back(words[0]);

	for (int i = 1; i < words.size(); i++) {
		int x = (i % n) + 1; //번호
		int num = i / n + 1; //몇번째인지
		bool check = false;
		bool check2 = false;  //에 끝이 첫 시작인지
		if (str != words[i][0]) {
			check2 = true;
		}
		str = words[i][words[i].length() - 1];


		for (int j = 0; j < v.size(); j++) {
			if (words[i] == v[j]) {
				check = true;
			}
		}
		
		if (check == true || check2 == true) {
			ans1 = x;
			ans2 = num;
			cout << ans1 << " " << ans2;
			check2 = true;

			return 0;
		}
                           v.push_back(words[i]);

	}

	if (check2 == false) {
		cout << 0 << " " << 0;
	}


}