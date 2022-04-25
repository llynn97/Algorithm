#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <set>
#include <map>


using namespace std;
map <string, int> m;
map <string, int> m2;
vector <string> car;
vector<pair<int, int>> ans;



vector<int> solution(vector<int> fees, vector<string> records) {
	vector<int> answer;
	return answer;
}

bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.first < b.first;
}



int main(void) {
	vector<int> fees = { 180, 5000, 10, 600 }; //기본시간 기본요금 단위 시간 단위 요금 
	vector<string> records = { "05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT" };

	

	for (int i = 0; i < records.size(); i++) {
		string s = records[i];
		int idx = s.find(' ');
		string a = s.substr(0, idx);
		s = s.substr(idx + 1, s.length() - 1);
		idx = s.find(' ');
		string b = s.substr(0, idx);
		s = s.substr(idx + 1, s.length() - 1);
		string c = s;
		idx = a.find(':');
		string hour = a.substr(0, idx);
		a = a.substr(idx + 1, a.length() - 1);
		string minute = a;
		int time = stoi(hour) * 60 + stoi(minute);
		//cout << c<< "\n";
		
		if (c == "IN") {
			m[b + "IN"] = time;
			if (m2.find(b) == m2.end()) {
				car.push_back(b);
				m2[b] = 0;
			}
		}
		if (c == "OUT") {
			m[b + "OUT"] = time;
			m2[b] = m2[b]+m[b + "OUT"] - m[b + "IN"];
			m.erase(b + "IN");
			m.erase(b + "OUT");
		}

		

	}
	/*for (int i = 0; i < car.size(); i++) {
		cout << car[i] << " ";
	}*/
	for (int i = 0; i < car.size(); i++) {
		int fee = 0;

		string carNum = car[i];
		int end = 0;
		int total = 0;

		if (m2[carNum] == 0) {
			int start = m[carNum + "IN"];
			total = 23 * 60 + 59 - start;

		}
		else {
			if (m.find(carNum + "IN") != m.end()) {
				int start = m[carNum + "IN"];
				total = 23 * 60 +59- start + m2[carNum];
			}
			else {
				total = m2[carNum];
			}

		}
		//cout << "total: " << total << "\n";
		if (total <= fees[0]) {
			fee = fees[1];
		}
		else {
			fee += fees[1];
			total -= fees[0];
			if (total % fees[2] != 0) {
				fee += (total / fees[2] + 1) * fees[3];
			}
			else {
				fee += (total / fees[2]) * fees[3];
			}
		}

		ans.push_back(make_pair(stoi(carNum), fee));

		
	}

	sort(ans.begin(), ans.end(), cmp);
	for (int i = 0; i < ans.size(); i++) {
			cout << ans[i].first << " " << ans[i].second << "\n";



		}
}