#include <iostream>

#include <vector>

#include <string>

#include <cstring>

using namespace std;



vector <string> st;

string t;

char alpa[26];    //알파벳

vector <char> v; //가르친 알파벳 

bool check[26];

int n, k; //n=단어 개수 k=가르칠 글자수

int maxi = 0;

void go(int num, int cnt) {  //cnt=(k-5)만큼 알파벳 고른 개수 



	if (cnt == (k - 5)) {

		int result = 0;

		for (int i = 0; i < 5; i++) {     //v에 antic넣어줌



			v.push_back(t[i]);

		}



		for (int i = 0; i < st.size(); i++) {   //단어 읽을 수 있는 개수 세기
			bool flag = false;
			int count = 0;

			int len = st[i].length();

			string m = st[i];

			for (int k = 0; k < len; k++) {

				if (!check[m[k] - 'a']) {

					flag = true;
					break;

				}

			}

			if (flag == false) {

				result++;

			}







		}

		maxi = max(maxi, result);

		for (int i = 0; i < 5; i++) {

			v.pop_back();

		}

		return;



	}

	for (int i = num; i < 26; i++) {

		if (check[i] == true) {

			continue;

		}

		v.push_back(alpa[i]);

		check[i] = true;

		go(i, cnt + 1);

		if (alpa[i] != 'a' || alpa[i] != 'n' || alpa[i] != 't' || alpa[i] != 'i' || alpa[i] != 'c') {

			check[i] = false;

		}

		v.pop_back();

	}

}



int main() {

	ios::sync_with_stdio(false);

	cin.tie(NULL);

	cout.tie(NULL);

	string s;

	t = "antic";

	cin >> n >> k;

	string u = "abcdefghigklmnopqrstuvwxyz";

	for (int i = 0; i < 26; i++) {

		alpa[i] = u[i];

	}

	for (int i = 0; i < n; i++) {

		cin >> s;

		st.push_back(s);

	}

	if (k < 5) {

		cout << "0";

	}

	else {

		for (int i = 0; i < 5; i++) {  //antic check=true로 만들어주기

			int p = t[i] - 97;

			check[p] = true;

		}

		go(0, 0);

		cout << maxi;

	}





	return 0;

}