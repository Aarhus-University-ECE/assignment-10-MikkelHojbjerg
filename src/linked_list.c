#include <assert.h> /* assert */
#include <stdio.h>  /* printf */
#include <stdlib.h> /* malloc, free */
#include <math.h>   /* pow */

#include "linked_list.h"

/* functions to create lists */
node *make_node(int v, node *q) {
  node *p = malloc(sizeof(node));
  p->value = v;
  p->next = q;
  return p;
}

/* free all nodes in the list p */
void free_list(node *p) {
  node *q;
  while (p != NULL) {
    q = p->next;
    free(p);
    p = q;
  }
}

/* print list to console */
void print_list(node *p) {

	while(p->next != NULL){
		printf("Data: %d\n", p->value);
		p = p->next;
	}

	printf("Data: %d\n", p->next->value);

}

int sum_squares(node *p) {

	int sum;

	//Hvis p er NULL, er der ingen værdier og der kan returnes 0
	if(p == NULL){
		return 0;
	}

	//Hvis p->next == NULL, er p den sidste list og kan derfor returnes på følgende måde
	if(p->next == NULL){
		return pow(p->value, 2);
	}else{
		//Hvis ikke bliver sum_squares kørt igen med p->next
		sum = pow(p->value,2) + sum_squares(p->next);
		return sum;
	}
}

typedef int (*fn_int_to_int)(int);

node *map(node *p, fn_int_to_int f) {
  // Add your code for excercise 3

	//Alloker plads til en temp node, da den skal bruges til at lave en ny liste
	node *temp = (malloc(sizeof(node)));

	//Hvis p->next er NULL, skal der ikke er listen kørt igennem
	if(p->next == NULL){
		temp->value = square(p->value);
		temp->next = NULL;
		return temp;
	}

	//map kører igennem med p->next
	temp->next = map(p->next, f);
	//f får værdien af p-> value
	temp->value = f(p->value);

	return temp;
}

int square(int x) { return x * x; }

// example of another function that can be passed to map
// returns the sign of the number
// -1 if negative, 0 if zero, 1 if positive
int sign(int x) { return x == 0 ? 0 : (x < 0 ? -1 : 1); }
