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
			printf("t->left: %d\n", x);
			t->left->left = NULL;
			t->left->right = NULL;
		}else if(x > t->item){
			t->right = (malloc(sizeof(struct tree_node)));
			t->right->item = x;
			printf("t->right: %d\n", x);
			t->right->left = NULL;
			t->right->right = NULL;
		}

	}else if(t->left != NULL && x <= t->item){
		placeItem(x, t->left);

	}else if(t->left == NULL && x <= t->item){
		t->left = (malloc(sizeof(struct tree_node)));

		t->left->left = NULL;
		t->left->right = NULL;
		t->left->item = x;

		printf("t->left: %d\n", x);

	}else if(t->right != NULL && x > t->item){
		placeItem(x, t->right);
	}else if(t->right == NULL && x > t->item){
		t->right = (malloc(sizeof(struct tree_node)));

		t->right->left = NULL;
		t->right->right = NULL;
		t->right->item = x;

		printf("t->right: %d\n", x);

	}
}

struct tree_node *Insert(int x, struct tree_node *t) {

	if(t == NULL){
		t = (malloc(sizeof(struct tree_node)));
		t->item = x;
		printf("root: %d\n", x);
		t->left = NULL;
		t->right = NULL;
		return t;
	}

	placeItem(x, t);

	return t;

}

struct tree_node *Remove(int x, struct tree_node *t) {

	struct tree_node *temp = t;

	if(temp->item == x && temp->left == NULL && temp->right == NULL){
		free(temp);
		printf("t->item blev fjernet\n");
		return true;
	}else if(x <= temp->item && temp->left != NULL){
		Remove(x, t->left);
	}else if(x > temp->item && temp->right != NULL){
		Remove(x, t->right);
	}else{
		printf("Tallet er ikke i træet\n");
		return true;
	}

}

int Contains(int x, struct tree_node *t) {

	printf("x: %d, item: %d\n", x, t->item);

	if(x == t->item){
		printf("Træet indeholder %d\n", x);
		return true;
	}else if(x <= t->item && t->left != NULL){
		Contains(x, t->left);
	}else if(x > t->item && t->right != NULL){
		Contains(x, t->right);
	}else{
		return false;
	}

}

struct tree_node *Initialize(struct tree_node *t) {

	t = NULL;

	return t;

}

int Empty(struct tree_node *t) {

	if(t == NULL){
		return true;
	}else{
		return false;
	}

}

int Full(struct tree_node *t) {
  // Test if full
  return 0;
}
