#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


int n;
int t;
int m;
vector<string> timetable;
vector <pair<int, int>> v;
string answer;
vector <pair<int, int>> bus;
int bus2[11];

string solution(int n, int t, int m, vector<string> timetable) {
	string answer = "";
	return answer;
}

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	else {
		return a.first < b.first;
	}
}

int main(void) {
	n = 1; // n회
	t = 1; //t분 간격
	m = 5;  // 1번에 m명씩
	timetable = { "00:01", "00:01", "00:01","00:01", "00:01", "00:02", "00:03", "00:04" };
	for (int i = 0; i < timetable.size(); i++) {
		string s = timetable[i];
		int a = s.find(":");
		string hou = s.substr(0, a);
		int hou1 = stoi(hou);
		cout << "hou: "<<hou << "\n";
		s = s.substr(a+1, s.length());
		string min = s;
		int min1 = stoi(min);
		cout << "min: " << min << "\n";
		v.push_back(make_pair(hou1, min1));
	
		
	}

	for (int i = 0; i < n; i++) {
		int hou2 = 540;
		int min2 = t * i;
		hou2 += min2;
		int hou1 = hou2 / 60;
		int min1 = hou2 % 60;
		bus.push_back(make_pair(hou1, min1));
		
	}
	for (int i = 0; i < bus.size(); i++) {
		cout << bus[i].first << ":" << bus[i].second << "\n";
	}
	
	sort(v.begin(), v.end(), cmp);
	int idx = 0;
	int p = 0;
	for (int i = 0; i < v.size(); i++) {
		if (idx<=bus.size()-1&&bus2[idx] < m) {
			int sum = v[i].first * 60 + v[i].second; //동료 도착 시간
			int sum2 = bus[idx].first * 60 + bus[idx].second; //버스 도착 시간
			if (sum<=sum2) {
				p = i;
				bus2[idx]++;
				
			}
			else {
				idx++;
				if (idx <= bus.size() - 1) {
					int sum = v[i].first * 60 + v[i].second; //동료 도착 시간
					int sum2 = bus[idx].first * 60 + bus[idx].second; //버스 도착 시간
					if (sum <= sum2) {
						bus2[idx]++;
						p = i;

					}
				}
				
			}
		}
		else {
			idx++;
			if (idx <= bus.size() - 1) {
				int sum = v[i].first * 60 + v[i].second; //동료 도착 시간
				int sum2 = bus[idx].first * 60 + bus[idx].second; //버스 도착 시간
				if (sum <= sum2) {
					bus2[idx]++;
					p = i;
				}
			}
		}
	}
	
	for (int i = 0; i < bus.size(); i++) {
		cout << "bus2 :" << bus2[i] << "\n";
	}
	int a1 = 0;
	int b1 = 0;
	if (bus2[bus.size() - 1] < m) {
		a1 = bus[bus.size() - 1].first;
		b1 = bus[bus.size() - 1].second;
		
	}
	else {
		a1 =v[p].first;
		b1 =v[p].second-1;
		if (b1 < 0) {
			b1 += 60;
			a1 -= 1;
		}

	}
	if (a1 < 10) {
		answer += "0";
		answer += to_string(a1);
	}
	else {
		answer += to_string(a1);

	}
	answer += ":";
	if (b1 < 10) {
		answer += "0";
		answer += to_string(b1);

	}
	else {
		answer += to_string(b1);

	}


	/*for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << ":" << v[i].second << "\n";
	}*/


	cout << answer;

	
}