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

void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);

#endif
