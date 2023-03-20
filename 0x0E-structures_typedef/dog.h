#ifndef DOG_H
#define DOG_H

/**
 * struct dog - New type.
 * @name: first member.
 * @age: Second member.
 * @owner: Thrid member.
 *
 * Description: Define a new type struct dog.
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};

typedef struct dog dog_t;

void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);
dog_t *new_dog(char *name, float age, char *owner);
void free_dog(dog_t *d);
#endif
