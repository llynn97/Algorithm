#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>


using namespace std;
stack <char> st;

int solution(string s)
{
	int answer = -1;

	
	return answer;
}





int main(void) {
	string s;
	s = "baabaa";
	for (int i = 0; i < s.length(); i++) {
		if (st.size() != 0 && s[i] == st.top()) {
			st.pop();
		}
		else {
			st.push(s[i]);
		}
	
	}

	if (st.size() == 0) {
		cout << 1;
	}
	else {
		cout << 0;
	}

	
	
	
	
	

}