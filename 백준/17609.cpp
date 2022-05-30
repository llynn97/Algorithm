#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

int t;
string s;
vector <string> v;

int pelindrom(int left , int right, string str,int check) {
	while(left <= right) {
		if (str[left] != str[right]) {
			if (check == 0) {
				if (pelindrom(left + 1, right, str,0) == 0 || pelindrom(left, right - 1, str,0) == 0) {
					return 1;
				}
				else return 2;

			}
			
			return 2;
		}

		left++;
		right--;
	}

	return 0;
}

int main(void) {
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> s;
		v.push_back(s);
	}
	for (int i = 0; i < v.size(); i++) {
		string s1 = v[i];
		cout << pelindrom(0, s1.length() - 1, s1,0)<<"\n";
	}

}