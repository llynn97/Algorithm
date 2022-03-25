#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

string m;
vector<string> musicinfos;
vector<pair<pair<int,string>,int>> v;
vector<pair<int, string>> v2;

string solution(string m, vector<string> musicinfos) {//m:기억한 멜로디 music: 방송된 곡의 정보
	string answer = "";
	return answer;
}
//musocinfo = 시작시각, 끝난시각, 음악 제목 , 악보 


int main(void) {
	m = "ABCDEFG";
	musicinfos = { "12:00,12:14,HELLO,CDEFGAB", "13:00,13:05,WORLD,ABCDEF" };
	while (true) {
		if (m.find("C#") == string::npos) {
			break;
		}
		m.replace(m.find("C#"), 2, "c");
	}
	while (true) {
		if (m.find("D#") == string::npos) {
			break;
		}
		m.replace(m.find("D#"), 2, "d");
	}
	while (true) {
		if (m.find("F#") == string::npos) {
			break;
		}
		m.replace(m.find("F#"), 2, "f");
	}
	while (true) {
		if (m.find("G#") == string::npos) {
			break;
		}
		m.replace(m.find("G#"), 2, "g");
	}
	while (true) {
		if (m.find("A#") == string::npos) {
			break;
		}
		m.replace(m.find("A#"), 2, "a");
	}
	
	for (int i = 0; i < musicinfos.size(); i++) {
		while (true) {
			if (musicinfos[i].find("C#") == string::npos) {
				break;
			}
			musicinfos[i].replace(musicinfos[i].find("C#"), 2, "c");
		}
		while (true) {
			if (musicinfos[i].find("D#") == string::npos) {
				break;
			}
			musicinfos[i].replace(musicinfos[i].find("D#"), 2, "d");
		}
		while (true) {
			if (musicinfos[i].find("F#") == string::npos) {
				break;
			}
			musicinfos[i].replace(musicinfos[i].find("F#"), 2, "f");
		}
		while (true) {
			if (musicinfos[i].find("G#") == string::npos) {
				break;
			}
			musicinfos[i].replace(musicinfos[i].find("G#"), 2, "g");
		}
		while (true) {
			if (musicinfos[i].find("A#") == string::npos) {
				break;
			}
			musicinfos[i].replace(musicinfos[i].find("A#"), 2, "a");
		}
	

	}
	for (int i = 0; i < musicinfos.size(); i++) {
		cout << musicinfos[i] << " ";
	}
	cout << "\n";
	
	string a, b, c, d;
	int time = 0;
	for (int i = 0; i < musicinfos.size(); i++) {
		string s = musicinfos[i];
		int idx = s.find(',');
		a = s.substr(0, idx); //12:00
		//cout << a << "\n";
		s = s.substr(idx + 1, s.length() - 1);
		idx = s.find(',');
		b = s.substr(0, idx);
		//cout << b << "\n";
		s = s.substr(idx + 1, s.length() - 1);
		idx = s.find(',');
		c = s.substr(0, idx);
		//cout << c << "\n";
		s = s.substr(idx + 1, s.length() - 1);
		d = s;
		//cout << d << "\n";
		int idx2=a.find(':');
		int idx3 = b.find(':');
		string hour3 = b.substr(0, idx3);
		string hour2 = a.substr(0, idx2);
		int hour = stoi(hour3) - stoi(hour2);
		//cout << hour << "\n";
		a = a.substr(idx2 + 1, a.length() - 1);
		b = b.substr(idx3 + 1, b.length() - 1);
		int minute = stoi(b) - stoi(a);
		//cout << minute << "\n";
		if (minute < 0) {
			minute += 60;
			hour -= 1;

		}
		int num = hour * 60 + minute;
		//cout << num<<"\n";
		string ss = "";
		int count = 0;
		int count2 = 0;
		int idx5 = 0; 
		while (true) {
			if (count == num) {
				break;
			}
			if (idx5 > d.length() - 1) {
				idx5 = 0;
			}
			ss += d[idx5];
			idx5++;
			count++;

		}

		cout << ss << "\n";
		if (ss.find(m) != string::npos) {
			v.push_back(make_pair(make_pair(num, c),i));
		}

	}
	
	if (v.size() == 0) {
		cout << "(None)";
	}
	if (v.size() == 1) {
		cout << v[0].first.second;
	}
	if (v.size() > 1) {
		sort(v.begin(), v.end());
		int num = v[v.size()-1].first.first;
		for (int i = 0; i < v.size(); i++) {
			if (num == v[i].first.first) {
				v2.push_back(make_pair(v[i].second, v[i].first.second));
			}
		}
		if (v2.size() == 1) {
			cout << v2[0].second;
		}
		else {
			sort(v2.begin(), v2.end());
			cout << v2[0].second;
		}
	}


}