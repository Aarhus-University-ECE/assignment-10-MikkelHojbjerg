#include "btree.h"

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void placeItem(int x, struct tree_node *t){


	if(t == NULL){
		t = (malloc(sizeof(struct tree_node)));
		t->item = x;
		t->left = NULL;
		t->right = NULL;
	}

	if(t->left == NULL && t->right == NULL){

		if(x <= t->item){
			t->left = (malloc(sizeof(struct tree_node)));
			t->left->item = x;

			printf("left: %d\n",t->left->item);
			t->left->left = NULL;
			t->left->right = NULL;
		}else if(x > t->item){
			t->right = (malloc(sizeof(struct tree_node)));
			t->right->item = x;

			printf("right: %d\n", t->right->item);
			t->right->left = NULL;
			t->right->right = NULL;

		}
	}else if(t->left != NULL && x <= t->item){
		placeItem(x, t->left);
	}else if(t->right != NULL && x > t->item){
		placeItem(x, t->right);
	}
}

struct tree_node *Insert(int x, struct tree_node *t) {

	if(t == NULL){
		t = (malloc(sizeof(struct tree_node)));
		t->item = x;
		t->left = NULL;
		t->right = NULL;
		printf("Root: %d\n", t->item);
		return t;
	}

		placeItem(x, t);

	return t;

}

struct tree_node *Remove(int x, struct tree_node *t) {
  // Remove one item from the tree t

  return NULL;
}

int Contains(int x, struct tree_node *t) {

	if(x == t->item){
		printf("x = %d, item = %d\n", x, t->item);
		return true;
	}else if(x <= t->item && t->left != NULL){
		printf("x is t->left\n");
		Contains(x, t->left);
	}else if(x > t->item && t->right != NULL){
		printf("x is t->right\n");
		Contains(x, t->right);
	}else{
		return false;
	}

}

struct tree_node *Initialize(struct tree_node *t) {

	t = NULL;

}

int Empty(struct tree_node *t) {
  // Test if empty
  return 0;
}

int Full(struct tree_node *t) {
  // Test if full
  return 0;
}
