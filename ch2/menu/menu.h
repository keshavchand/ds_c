#pragma once

void InsertAt(int *a, int size, int idx, int s) {
	if (idx >= size) return ; // Buffer Overflow
	int item = a[idx];
	a[idx] = s;

	for (int i = idx + 1; i < size; i++) {
		int newItem = a[i];
		a[i] = item;
		item = newItem;
	}
}

void DeleteAt(int *a, int size, int idx) {
	if (idx >= size) return;
	for (int i = idx; i < size - 1; i++) {
		a[i] = a[i + 1];
	}

	a[size - 1] = 0;
}

int SearchElement(int *a, int size, int e) {
	for (int i = 0; i < size; i++) {
		if (a[i] == e) return i;
	}	
	return -1;
}

int ReverseList(int *a, int size) {
	int start = 0, end = size - 1;
	for (int i = 0; i < size / 2; i++) {
		int temp = a[start];
		a[start] = a[end];
		a[end] = temp;

		start ++;
		end --;
	}
}

int ZeroToBottom(int *a, int size) {
	int writer = size - 1;
	for (int i = size - 1; i >= 0; i--) {
		if (a[i] == 0) continue;
		a[writer--] = a[i];
	}

	while (writer >= 0) a[writer--] = 0;
}
