#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int i;
	struct Node* next;
	struct Node* prev;
} Node;

typedef struct {
	Node* head;	
} LinkedList;

void 
InsertAtBeginning(LinkedList* ll, int i) {
	Node* n = malloc( sizeof(*n) );
	n->i = i;
	if (ll->head) ll->head->prev = n;
	n->next = ll->head;
	n->prev = NULL;

	ll->head = n;
}

void 
InsertAtEnd(LinkedList* ll, int i) {
	Node* n = malloc( sizeof(*n) );
	n->i = i;
	n->next = NULL;

	Node *h = ll->head;
	while (h->next) h = h->next;
	h->next = n;
	n->prev = h;
}

void
InsertAt(LinkedList* ll, int loc, int i) {
	if (loc == 0) return InsertAtBeginning(ll, i);

	Node* h = ll->head;
	while (loc--) {
		if (loc == 0) break;
		else if (h->next) {
			h = h->next;
		}
		else break;
	}

	Node* n = malloc( sizeof(*n) );
	if (h->next) h->next->prev = n;
	n->i = i;
	n->next = h->next;
	n->prev = h;
	h->next = n;
}

void
DeleteFromBeginning(LinkedList *ll) {
	Node* n = ll->head;
	if (!n) {
		printf("No Element in List\n");
		return;
	}
	ll->head = n->next;
	n->prev = NULL;
	free(n);
}

void
DeleteFromEnd(LinkedList *ll) {
	Node* last = ll->head;
	if (!last) {
		printf("No Element in List\n");
		return;
	}

	Node* next = last->next;
	while (next->next) {
		last = next;
		next = next->next; 
	}

	free(next);
	last->next = NULL;
}

void
DeleteFrom(LinkedList *ll, int pos) {
	if (pos == 0) return DeleteFromBeginning(ll);

	Node *h = ll->head;
	while (pos--) {
		if (pos == 0) break;
		else if (h->next) h = h->next;
		else break;
	}

	if (h->next) {
		Node *deleted = h->next;
		Node *next = NULL;
		if (deleted->next) {
			next = deleted->next;
			next->prev = h;
		}
		h->next = next;

		free(deleted);
	}
}

void 
DebugPrintList(LinkedList *ll, int d) {
	Node* n = ll->head;
	while (n) {
		printf("{%p: %p %d %p} \n", n, n->prev, n->i, n->next);
		Node* t = n->next;
		if (d) free(n);
		n = t;
	}
	printf("\n");
	printf("\n");
	return;
}

int main() {
	LinkedList ll = {};
	InsertAt(&ll, 0, 1);
	InsertAt(&ll, 0, 2);
	InsertAt(&ll, 1, 3);
	InsertAt(&ll, 1, 4);
	InsertAt(&ll, 1, 5);
	DebugPrintList(&ll, 0);

	DeleteFrom(&ll, 1);
	DeleteFrom(&ll, 3);
	DebugPrintList(&ll, 0);

	DeleteFromEnd(&ll);
	DeleteFromBeginning(&ll);
	DebugPrintList(&ll, 1);

}
