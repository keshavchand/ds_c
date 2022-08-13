#pragma once

int BinarySearch(int *a, int size, int s) {
	int start = 0, end = size - 1;

	while (start <= end) {
		int mid = (start + end) / 2;
		int item = a[mid];
		if (item == s) return mid;
		if (item < s) start = mid + 1;
		if (item > s) end = mid - 1;
	}

	return -1;
}

int BinarySearchRec(int *a, int size, int s) {
	
	if (size <= 0) return -1;
	printf("%d\n", size);

	int start = 0, end = size - 1;
	int mid = (start + end) / 2;
	int item = a[mid];
	if (item == s) return mid;
	if (item < s) BinarySearchRec(a + mid + 1, size - mid - 1, s);
	if (item > s) BinarySearchRec(a, size - mid - 1, s);
	return -1;
}
