0x1A. C - Hash tables

0. >>> ht = {}
Write a function that creates a hash table.

1. djb2
Write a hash function implementing the djb2 algorithm.

2. key -> index
Write a function that gives you the index of a key.

3. >>> ht['betty'] = 'cool'
Write a function that adds an element to the hash table.

4. >>> ht['betty']
Write a function that retrieves a value associated with a key.

5. >>> print(ht)
Write a function that prints a hash table.

6. >>> del ht
Write a function that deletes a hash tablei.

Rewrite the previous functions using these data structures:

shash_table_t *shash_table_create(unsigned long int size);
int shash_table_set(shash_table_t *ht, const char *key, const char *value);
The key/value pair should be inserted in the sorted list at the right place
Note that here we do not want to do exactly like PHP: we want to create a sorted linked list, by key (sorted on ASCII value), that we can print by traversing it. See example.
char *shash_table_get(const shash_table_t *ht, const char *key);
void shash_table_print(const shash_table_t *ht);
Should print the hash table using the sorted linked list
void shash_table_print_rev(const shash_table_t *ht);
Should print the hash tables key/value pairs in reverse order using the sorted linked list
void shash_table_delete(shash_table_t *ht);
You are allowed to have more than 5 functions in your file
