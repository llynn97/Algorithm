#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

int n;
vector<int> stations;
int w;
int start = 0;
int index = 0;
int answer = 0;

int solution(int n, vector<int> stations, int w)
{
	int answer = 0;


	return answer;
}

int main() {

	stations = { 4, 11 };
	n = 11;
	w = 1;
	start = 1;
	index = 0;
	while (start <= n) {
		if (stations[index] - w <= start && stations[index] + w >= start) {
			start = stations[index] + w;
			index++;
		}else{
			start += 2 * w;
			answer++;
		}
		start++;
	}

	cout << answer;

}