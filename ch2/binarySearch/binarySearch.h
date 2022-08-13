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
