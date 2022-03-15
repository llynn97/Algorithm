#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

string dirs;
int answer = 0;
int x, y;
int v[12][12][12][12];
int solution(string dirs) {
	int answer = 0;
	return answer;
}


int main() {
	
	dirs = "LULLLLLLU";
	x = 5;
	y = 5;
	for (int i = 0; i < dirs.size(); i++) {
		int nx = 0;
		int ny = 0;
		

		if (dirs[i] == 'L') {
			nx = x - 1;
			ny = y;
			
		}
		else if (dirs[i] == 'R') {
			nx = x + 1;
			ny = y;
			
		}
		else if (dirs[i] == 'U') {
			nx = x;
			ny = y + 1;
			
		}
		else if (dirs[i] == 'D') {
			nx = x;
			ny = y - 1;
			
		}
		if (nx >=0&& nx <= 10 && ny >= 0 && ny <= 10) {
			if (v[x][y][nx][ny] == 0 && v[nx][ny][x][y] == 0) {
				v[x][y][nx][ny] = 1;
				v[nx][ny][x][y] = 1;
				answer++;
			}
			x = nx;
			y = ny;
		}
	}

	cout << answer;

}