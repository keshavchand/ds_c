#include <stdio.h>

#include "menu.h"


void PrintList(int *a, int size) {
	for (int i = 0; i < size; i++) printf("%d ", a[i]);
	printf("\n");
}

int main() {
	  const int size = 10;
		int a[size];

		printf("Enter the list: ");
		for (int i = 0; i < 10; i++) {
			scanf("%d", &a[i]);
		}

		for (;;) {
			int input;
			printf("(1) Insert the number at\n");
			printf("(2) Delete the number at\n");
			printf("(3) Search the number \n");
			printf("(4) Reverse the list\n");
			printf("(5) Move all zero at the bottom of the array\n");
			printf("> ");

			scanf("%d", &input);

			switch (input) {
				case 1: { // Insert
									int item, loc;
									printf("Location and Item: ");
									scanf("%d %d", &loc, &item);
									InsertAt(a, size, loc, item);
								}
					break;
				case 2: { // Delete
									int loc;
									printf("Location: ");
									scanf("%d", &loc);

									DeleteAt(a, size, loc);
								}
					break;
				case 3: { // Search
									int search;
									printf("Item to search: ");
									scanf("%d", &search);

									SearchElement(a, size, search);
								}
					break;
				case 4: { // Reverse
									ReverseList(a, size);
								}
					break;
				case 5: { // Move
									ZeroToBottom(a, size);
								}
					break;
				default:{
									printf("Wrong Choice\n");
									continue;
								}
			}
					PrintList(a, size);
		}
}
