#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>

#include "db.h"

typedef struct HashTable* DB;
typedef struct Node* node;

DB InitDB() {
	DB db = (DB)malloc(sizeof(struct HashTable));
	db->size = 100;
	db->count = 0;
	size_t i;
	for (i = 0; i < db->size; i++) {
		db->items[i].exist = 0;
	}
}

int Hash(const char* key, int bucket) {
	size_t i;
	int len = strlen(key);
	long hash = 0;
	for (i = 0; i < len; i++) {
		hash += key[i] * pow(233, len-i-1);
	}
	return (int)(hash % bucket);
}

int Put(DB db, const char* key, const char* value) {
	int index = Hash(key, db->size);
	if (db->items[index].exist == 0) {
		strcpy(db->items[index].key, key);
		strcpy(db->items[index].value, value);
		db->items[index].exist = 1;
		db->items[index].next = NULL;
		return 1;
	}
	else {
		node ele = (node)malloc(sizeof(struct Node));
		strcpy(ele->key, key);
		strcpy(ele->value, value);
		ele->next = NULL;
		node tmp = &db->items[index];
		while(tmp->next != NULL) {
			tmp = tmp->next;
		}
		tmp->next = ele;
	}
}

int Get(DB db, const char* key, char* vbuff) {
	int index = Hash(key, db->size);
	if (db->items[index].exist == 0) {
		return 0;
	}
	else {
		node tmp = &db->items[index];
		while (tmp != NULL) {
			if (strcmp(tmp->key, key) == 0) {
				strcpy(vbuff, tmp->value);
				return 1;
			}
			tmp = tmp->next;
		}
		return 0;
	}
}

int main(int argc, char const *argv[])
{
	DB db = InitDB();
	Put(db, "Mike", "18");
	char value[20];
	Get(db, "Mike", value);
	printf("hahaha\n");
	printf("Mike: %s\n", value);
	return 0;
}
