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

	if(p == NULL){
		return 0;
	}

	if(p->next == NULL){
		return pow(p->value, 2);
	}else{
		printf("val: %d\n", p->value);

		sum = pow(p->value,2) + sum_squares(p->next);

		printf("sum: %d\n", sum);
		return sum;
	}
}

typedef int (*fn_int_to_int)(int);

node *map(node *p, fn_int_to_int f) { 
  // Add your code for excercise 3
  
  return NULL; 
}

int square(int x) { return x * x; }

// example of another function that can be passed to map
// returns the sign of the number
// -1 if negative, 0 if zero, 1 if positive
int sign(int x) { return x == 0 ? 0 : (x < 0 ? -1 : 1); }
