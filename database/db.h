#include <stdlib.h>

struct Node{
	int exist;
	char* key;
	char* value;
	struct Node* next;
};

struct HashTable{
	int size;
	int count;
	struct Node items[10000];
};

