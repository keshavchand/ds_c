#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float randf() {
	return (float)rand() / (float)RAND_MAX;
}

void CreateRandomArray(int *a, int size) {
	for (int i = 0; i < size; i++) {
		a[i] = randf() * 200;
	}
}

int SearchArray(int *a, int size, int item) {
	for (int i = 0; i < size; i++) {
		if (a[i] == item) return i;
	}

	return -1;
}

int main() {
	const int size = 100;
	const int numOfSearches = 100;
	int a[size];
	srand(time(NULL));	

	CreateRandomArray(a, size);
	int foundCount = 0, notFoundCount = 0;

	for (int i = 0; i < numOfSearches; i++) {
		int num = randf() * 200;
		int idx = SearchArray(a, size, num);

		if (idx == -1) notFoundCount++;
		else foundCount++;
	}

	printf("No Of Searches: %d\n", numOfSearches);
	printf("No Of Searches Successful: %d\n", foundCount);
	printf("No Of Searches Unsuccessful: %d\n", notFoundCount);
	printf("Success %%age: %f\n", (float) foundCount * 100.0f / (float) numOfSearches);
}
