#include <iostream>
#include <algorithm>
#include <vector>
#include <string>


using namespace std;

vector<string> s;
bool check;
string st1;
vector<string> answer;

vector<string> solution(vector<string> s) {
	vector<string> answer;
	return answer;
}

int findLastZero(string str) {
	for (int i = str.length() - 1; i >= 0; i--) {
		if (str[i] == '0') {
			return i;
		}
		
	}
	return -1;
}



int main(void) {
	s = { "1110","100111100","0111111010" };
	check = true;

	for (int i = 0; i < s.size(); i++) {
		string str = "";
		int cnt = 0;
	
		
	
		
			for (int j = 0; j < s[i].length(); j++) {
				str += s[i][j];
				if (str.length() >= 3) {
					if (str.substr(str.length() - 3, 3) == "110") {
						cnt++;
						str.erase(str.length() - 3, str.length());
					}
				}
			}
			int last = findLastZero(str);
			if (last == -1) {
				string result = "";
				while (cnt--) {
					result += "110";
					
					
				}
				result += str;
				answer.push_back(result);
			}
			else {
				string result = "";
				for (int j = 0; j < str.length(); j++) {
					if (j == last) {
						result += str[j];
						while(cnt--) {
							result += "110";
						}
					}
					else {
						result += str[j];
					}
				}
				answer.push_back(result);
			}
			
			

		
	}
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
	}
	
	
}

/*
#include <string>
#include <vector>

using namespace std;
string st1;
int findLastZero(string str) {
	for (int i = str.length() - 1; i >= 0; i--) {
		if (str[i] == '0') {
			return i;
		}

	}
	return -1;
}

vector<string> solution(vector<string> s) {
	vector<string> answer;
	for (int i = 0; i < s.size(); i++) {
		string str = "";
		int cnt = 0;
		int length = s[i].length();

		st1 = "";

			for (int j = 0; j < length; j++) {
				str += s[i][j];
				if (str.length() >= 3) {
					if (str.substr(str.length() - 3, 3) == "110") {
						cnt++;
						str.erase(str.length() - 3, str.length());
					}
				}
			}
			int last = findLastZero(str);
			if (last == -1) {
				string result = "";
				while (cnt--) {
					result += "110";
					result += str;
					answer.push_back(result);

				}
			}
			else {
				string result = "";
				for (int j = 0; j < str.length(); j++) {
					if (j == last) {
						result += str[j];
						while(cnt--) {
							result += "110";
						}
					}
					else {
						result += str[j];
					}
				}
				answer.push_back(result);
			}




	}
	return answer;
}*/