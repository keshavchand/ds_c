#include <stdio.h>
#include <stdlib.h>

int main() {
	int compactMatrix[][3] = {
		{6, 6, 8}, // no of cols, no of rows, no of nums in compact matrix
		{0,3,-2},
		{0,5,1},
		{1,5,5},
		{2,4,-2},
		{4,3,1},
		{5,0,1},
		{5,4,4},
		{5,5,-6},
	};

	int cols = compactMatrix[0][0];
	int rows = compactMatrix[0][1];
	int nos  = compactMatrix[0][2];

	int* matrix = (int *) malloc(rows * cols * sizeof(int));
	for (int i = 0; i < rows * cols; i++) {
		matrix[i] = 0;
	}

	for (int i = 1; i < nos + 1; i++) {
		int x = compactMatrix[i][0];
		int y = compactMatrix[i][1];
		int num = compactMatrix[i][2];

		matrix[x * rows + y] = num;
	}

	for (int i = 0; i < cols; i++) {
		for (int j = 0; j < rows; j++) {
			printf("%d ", matrix[i * rows + j]);
		}
		printf("\n");
	}

	free(matrix);
}
