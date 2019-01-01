typedef struct {
	char* key;
	char* value;
}ht_item;

typedef struct {
	int size;
	int base_size;
	int count;
	ht_item** items;
}ht_hash_table;