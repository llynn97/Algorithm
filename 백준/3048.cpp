#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

int main() {
	int n1, n2, t;   //n1은 방향 1 n2는 0
	cin >> n1 >> n2;
	string s1, s2;
	char temp1;
	int temp2;
	vector <pair<char, int>> v;
	vector <int> idx;
	bool visit[51];
	cin >> s1;
	cin >> s2;
	cin >> t;
	for (int i = n1 - 1; i >= 0; i--) {
		v.push_back(make_pair(s1[i], 1));
	}
	for (int i = 0; i < n2; i++) {
		v.push_back(make_pair(s2[i], 0));
	}

	/*for(int i=0; i<t; i++){
		memset(visit,false,sizeof(visit));
		idx.clear();
		for(int j=1; j<n1+n2; j++){
				if(v[j].second!=v[j-1].second&&!visit[j]&&!visit[j-1]){
					idx.push_back(j);
					visit[j]=true;
					visit[j-1]=true;
				}
		}
		for(int j=0; j<idx.size(); j++){
			temp1=v[idx[j]].first;
			temp2=v[idx[j]].second;
				 v[idx[j]].first=v[idx[j]-1].first;
				 v[idx[j]].second=v[idx[j]-1].second;
				 v[idx[j]-1].first=temp1;
				 v[idx[j]-1].second=temp2;
		}
	}*/
	for (int i = 0; i < t; i++) {
		for (int j = 0; j < n1 + n2 - 1; j++) {
			if (v[j].second == 1 && v[j + 1].second == 0) {
				temp1 = v[j].first;
				temp2 = v[j].second;
				v[j].first = v[j + 1].first;
				v[j].second = v[j + 1].second;
				v[j + 1].first = temp1;
				v[j + 1].second = temp2;
				j++;
			}
		}
	}
	for (int i = 0; i < n1 + n2; i++) {
		cout << v[i].first;
	}
	return 0;
}