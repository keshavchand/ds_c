#pragma once

int LinearSearch(int *a, int size, int s) {
	for (int i = 0; i < size; i++) {
		if (a[i] == s) return i;
	}

	return -1;
}
