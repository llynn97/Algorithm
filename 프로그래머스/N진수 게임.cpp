#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <iostream>

using namespace std;
int n;
int t;
int m;
int p;
char map[1001];
string answer;
string solution(int n, int t, int m, int p) {
	string answer = "";
	return answer;
}

char alpha[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };

int main(void) {
	n = 16;
	t = 16;
	m = 2;
	p = 1;
	string str = "";
	/*for (int i = 0; i <= n - 1; i++) {
		map[i] = (char)(i + 48);
		str += map[i];
	}*/
	/*for (int i = 0; i < n; i++) {
		cout << map[i];
	}*/
	int cnt = str.length();
	int num = 0;
	int number = num;
	vector <char> v;
	
	while (true) {
		if (cnt >= t * m) {
			break;
		}
		int number = num;
		cout << "num " << number << "\n";
		while (true) {
			if (number <n) {
				v.push_back(alpha[number]);
				break;
			}
			v.push_back(alpha[number % n]);
			number /= n;
		}
		cnt += v.size();
		for (int j = v.size() - 1; j >= 0; j--) {
			str += v[j];
				
		}

		v.clear();
		
		num++;
	}
	cout << str<<"\n";
	int k = 0;
	while (t--) {
		answer += str[p + k * m-1];
		k++;
	}

	cout << answer;
	


}