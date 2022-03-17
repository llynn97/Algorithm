#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> sticker;

int dp1[100002];
int dp2[100002];
int answer = 0;

int solution(vector<int> sticker)
{
	int answer = 0;
    
	return answer;
}




int main(void) {

	sticker = { 1};  // 0 1 2 3 4 5 6 7   8->0   -1-> 7
	if (sticker.size() == 1) {
		answer = sticker[0];
	}
	else {
		dp1[0] = sticker[0];
		dp1[1] = sticker[0];
		dp2[0] = 0;
		dp2[1] = sticker[1];
		for (int i = 2; i < sticker.size(); i++) {
			if (i != sticker.size() - 1) {
				dp1[i] = max(dp1[i - 1], dp1[i - 2] + sticker[i]);
				answer = dp1[i];
			}
			dp2[i] = max(dp2[i - 2] + sticker[i], dp2[i - 1]);

		}
		answer = max(answer, dp2[sticker.size() - 1]);
	}
	
	
	cout << answer;

}