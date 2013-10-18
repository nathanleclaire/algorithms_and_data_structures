#include <iostream>
#include <assert.h>
#include <time.h>

using namespace std;

int search_iterative(int arr[], int n, int desired)
{
	/* precondition: must be sorted */
	bool done = false;
	int i = (n / 2);
	int k = i;
	while (!done) {
		cout << "i is " << i << ", arr[i] is " << arr[i] << endl;
		usleep(500 * 1000);
		if (i == 0 || i == n-1) {
			done = true;
		}
		if (arr[i] == desired) {
			return i;
		} else {
			if (k > 1) k /= 2;
			if (arr[i] > desired) {
				i -= k;
			} else {
				i += k;
			}
		}
	}
	return -1;
}

int main(int argc, char* argv[])
{
	int haystack[] = {-10, -9, -8, -7, -6, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int n = sizeof haystack / sizeof haystack[0];
	cout << "n = " << n << endl;
	assert ( search_iterative(haystack, n, 10)  == 20 );
	cout << "assertion 1 complete" << endl;
	assert ( search_iterative(haystack, n, -10) == 0  );
	cout << "assertion 2 complete" << endl;
	assert ( search_iterative(haystack, n, -3)  == 7  );
	cout << "assertion 3 complete" << endl;
	assert ( search_iterative(haystack, n, 6)   == 16 );
	cout << "assertion 4 complete" << endl;
	assert ( search_iterative(haystack, n, -20)   == -1 );
	cout << "assertion 5 complete" << endl;
	return 0;
}
