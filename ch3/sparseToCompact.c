#include <stdio.h>

int main() {
	int matrix[][6] = {
		{0,0,0,-2,0,1},
		{0,0,0,0,0,5},
		{6,0,0,0,-2,1},
		{0,0,0,0,0,0},
		{0,0,0,-1,0,0},
		{1,0,0,0,4,-6}
	};

	// Allocating max just in case if the matrix is all full
	int compactForm[sizeof(matrix) / sizeof(int) + 1][3]; 

	compactForm[0][0] = sizeof(matrix) / sizeof(matrix[0]);
	compactForm[0][1] = sizeof(matrix[0]) / sizeof(int);

	int k = 1;
	
	for (int i = 0; i < compactForm[0][0]; i++) {
		for (int j = 0; j < compactForm[0][1]; j++) {
			if (matrix[i][j] == 0) continue;
			compactForm[k][0] = i;
			compactForm[k][1] = j;
			compactForm[k][2] = matrix[i][j];
			k++;
		}
	}

	compactForm[0][2] = k-1;

	for (int i = 1; i < k; i++) {
		int* a = compactForm[i];
		printf("%d %d %d\n", a[0], a[1], a[2]);
	}
}
