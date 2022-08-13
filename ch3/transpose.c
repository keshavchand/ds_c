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

	{ // transpose
		int temp = compactMatrix[0][0];
		compactMatrix[0][0] = compactMatrix[0][1];
		compactMatrix[0][1] = temp;
	}

	int nos = compactMatrix[0][2];
	for (int i = 0; i < nos + 1; i++) {
		int temp = compactMatrix[i][0];
		compactMatrix[i][0] = compactMatrix[i][1];
		compactMatrix[i][1] = temp;
	}
	
	for (int i = 0; i < nos + 1; i++) {
		int *a = compactMatrix[i];
		printf("%d %d %d\n", a[0], a[1], a[2]);
	}
}
