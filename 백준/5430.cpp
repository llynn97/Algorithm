#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <deque>

using namespace std;
int t;
int n;
deque <int> v;
//R->순서 뒤집기  D->첫번째수 버림
int main(void) {
	string s;
	string arr;
   
	cin >> t;
	
	

	
	while (t--) {
		cin >> s;
		cin >> n;
		cin >> arr;
		int dir = 0; //0-> 앞부터 1-> 뒤부터
		bool check = false;
		arr = arr.substr(1, arr.length() - 2);
		string s2 = "";
		for (int j = 0; j < arr.length(); j++) {
			
			if (isdigit(arr[j])) {
				s2 += arr[j];
			}
			else {
				if (s2.length() != 0) {
					v.push_back(stoi(s2));
					s2 = "";
				}
				
			}
			
		}
		if (s2.length() != 0) {
			v.push_back(stoi(s2));
		}
		
	
		for (int i = 0; i < s.length(); i++) {
			char str = s[i];
			if (str == 'R') {
				int n2 = 0;
				if (dir == 1) {
					n2 = 0;
			    }
				if (dir == 0) {
					n2 = 1;
				}
				dir = n2;
			}
			if (str == 'D') {
				if (v.size() == 0) {
					cout << "error" << "\n";
					check = true;
					break;
				}
				else {
					if (dir == 1) {
						v.pop_back();
					}
					if (dir == 0) {
						
						v.pop_front();

					}
				}
				

				
			}
		}
		
		if (!check) {
			if (v.size() == 0) {
				cout << "[]" << "\n";
			}
			else if (v.size() == 1) {
				cout << "[" << v[0] << "]" << "\n";
			}
			else {
				cout << "[";
				if (dir == 0) {
					for (int i = 0; i < v.size() - 1; i++) {
						cout << v[i] << ",";
					}
					cout << v[v.size() - 1];
				}
				if (dir == 1) {
					for (int i = v.size() - 1; i >= 1; i--) {
						cout << v[i] << ",";
					}
					cout << v[0];
				}
				cout << "]\n";
			}
		}
		
		
		v.clear();
	}

}
