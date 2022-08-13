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

/*edit by rimjhim
here's a recursive approach for binary search
during function call in main(), pass arguments as endindex = size-1*/
int BinarySearchRecursive(int *arr, int endindex, int search_element, int startindex = 0)
{
    int mid = (startindex + endindex) / 2;
    if (arr[mid] == search_element)
    {
        return mid;
    }
    if (startindex == endindex)
    {
        return -1;
    }
    if (arr[mid] > search_element)
    {
        return BinarySearchRecursive(arr, mid - 1, search_element, startindex);
    }
    if (arr[mid] < search_element)
    {
        return BinarySearchRecursive(arr, endindex, search_element, mid + 1);
    }
}
