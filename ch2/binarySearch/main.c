#include <stdio.h>

#include "binarySearch.h"

int main() {
	const int size = 10;
	int arr[size];

	printf("Enter the numbers:\n");
	for (int i = 0; i < size; i++) {
		scanf("%d", &arr[i]);
	}

	int search;
	printf("Enter number to search: ");
	scanf("%d", &search);

	int idx = BinarySearch(arr, size, search);
	if (idx != -1) printf("Item is at %d\n", idx);
	else printf("Item not present in list\n");
}
