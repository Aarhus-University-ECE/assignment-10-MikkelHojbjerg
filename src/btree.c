#include "btree.h"

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct tree_node *Insert(int x, struct tree_node *t) {

	t = (malloc(sizeof(tree_node)));
	t->left = (malloc(sizeof(tree_node)));
	t->right = (malloc(sizeof(tree_node)));

	if(t == NULL){
		t->item = x;
	}

	printf("Root: %d\n", t->item);
	sleep(2);

	if(x <= t->item && t->left == NULL){
		t->left->item = x;

		printf("left: %d\n",t->left->item);
		sleep(2);

		t->left->left = NULL;
		t->left->right = NULL;
	}else{
		Insert(x, t->left);
	}

	if(x > t->item && t->right == NULL){
		t->right->item = x;

		printf("right: %d\n", t->right->item);
		sleep(2);

		t->right->left = NULL;
		t->right->right = NULL;
	}else{
		Insert(x, t->right);
	}

}

struct tree_node *Remove(int x, struct tree_node *t) {
  // Remove one item from the tree t

  return NULL;
}

int Contains(int x, struct tree_node *t) {

  // Return true if the tree t contains item x. Return false otherwise.

  return 0;
}

struct tree_node *Initialize(struct tree_node *t) {

	//Alloker plads til hele lortet
	t = (malloc(sizeof(tree_node)));
	t->left = (malloc(sizeof(tree_node)));
	t->right = (malloc(sizeof(tree_node)));

	t->left = NULL;
	t->right = NULL;
	t->item = 0;

}

int Empty(struct tree_node *t) {
  // Test if empty
  return 0;
}

int Full(struct tree_node *t) {
  // Test if full
  return 0;
}
