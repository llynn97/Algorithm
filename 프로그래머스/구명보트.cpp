#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> people;
int limit;

int solution(vector<int> people, int limit) {
	int answer = 0;
	return answer;
}


int main(void) {
	int answer = 0;
	people = {
	  70, 50, 80, 50
	};
	limit = 100;
	int start = 0;
	int end = people.size() - 1;
	sort(people.begin(), people.end());
	while (start <= end) {
		if (people[end] + people[start] <= limit) {
			end--;
			start++;
		}
		else {
			end--;

		}
		answer++;

	}

}