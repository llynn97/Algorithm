#include <iostream>
#include <string>
#include <vector>
#include <algorithm>



using namespace std;

int n, m;
int ans = 0;

int func(int a, int b) {
	if (a == 1 && b!=1) {
		return b;
	}
	 if (a == b) {
		 return 1;
	}
	 int num2 = 0;
	for (int i = a - 1; i <= b - 1; i++) {
		
		num2 += func(a - 1, i);
	}

	return num2;
	
}


int main(void) {

	int nn = func(5, 8);
	cout << nn;

}