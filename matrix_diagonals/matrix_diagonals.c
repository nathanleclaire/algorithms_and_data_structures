#include <stdio.h>

#define N 5

int main() {
	int matrix[N][N] = {
		{1, 0, 0, 0, 1},
		{0, 1, 0, 1, 0},
		{0, 0, 1, 0, 0},
		{0, 1, 0, 1, 0},
		{1, 0, 0, 0, 1},
	};
	int i, j;
	for (i=0; i < N; i++) {
		for (j=0; j < N; j++) {
			if (j==i || j == N-i-1)
				printf("%d", matrix[i][j]);
		}
	}
	printf("\n");
	return 0;
}
