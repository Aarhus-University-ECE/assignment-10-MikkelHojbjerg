#include "btree.h"
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void printTree(struct tree_node *t){

	if(t == NULL){
		printf("NULL\n");
	}else{
		printf("%d\n", t->item);
	}

	if(t->left){
		printTree(t->left);
	}

	if(t->right){
		printTree(t->right);
	}

}

/*
void placeItem(int x, struct tree_node *t){


	if(t == NULL){
		t = (malloc(sizeof(struct tree_node)));
		t->item = x;
		t->left = NULL;
		t->right = NULL;
	}

	if(x <= t->item){
		if(t->left == NULL){
			t->left = (malloc(sizeof(struct tree_node)));
			t->left->item = x;
			t->left->left = NULL;
			t->left->right = NULL;
		}else if(t->left != NULL){
			placeItem(x, t->left);
		}
	}else if(x > t->item){
		if(t->right == NULL){
			t->right = (malloc(sizeof(struct tree_node)));
			t->right->item = x;
			t->right->left = NULL;
			t->right->right = NULL;
		}else if(t->right != NULL){
			placeItem(x, t->right);
		}
	}


/*
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
*/
struct tree_node *Insert(int x, struct tree_node *t) {

	if(t == NULL){
		t = (malloc(sizeof(struct tree_node)));
		t->item = x;
		t->left = NULL;
		t->right = NULL;
	}else if(x <= t->item){
		/*if(t->left == NULL){
			t->left = (malloc(sizeof(struct tree_node)));
			t->left->item = x;
			t->left->left = NULL;
			t->left->right = NULL;
			printf("t->left = %d\n", x);
			return t->left;
		}else if(t->left != NULL){
			*/t->left = Insert(x, t->left);
		//}
	}else if(x > t->item){
		/*if(t->right == NULL){
			t->right = (malloc(sizeof(struct tree_node)));
			t->right->item = x;
			t->right->left = NULL;
			t->right->right = NULL;
			printf("t->right = %d\n", x);
			return t->right;
		}else if(t->right != NULL){
			*/t->right = Insert(x, t->right);
		//}
	}

	return t;

}

struct tree_node *removeLeaf(int x, struct tree_node *t){

	//Base case: x er ikke i træ
	if(t == NULL){
		return NULL;
	}

	//Base case: x er fundet
	if(t->item == x){
		//Hvis t er en leaf-node
		if(t->left == NULL && t->right == NULL){
			free(t);
			return NULL;
		}
		//Hvis t har venstre barn
		if(t->left != NULL){
			struct tree_node *temp = t->left;
			free(t);
			return temp;
		//Hvis t har højre barn
		}else if(t->right != NULL){
			struct tree_node *temp = t->right;
			free(t);
			return temp;
		//Hvis t har både venstre og højre barn
		}else{
			struct tree_node *r = t->right;
			struct tree_node *rParrent = t->right;
			//Finder mindste node hvis t har et højre barn
			while(r != NULL){
				rParrent = r;
				r = r->left;
			}
			//Hvis r har et højre barn, bliver temp sat til r->right og t->right->left bliver sat til temp
			if(r->right != NULL){
				struct tree_node *temp = r->right;
				rParrent->left = temp;
			}
			r->right = t->right;
			r->left = t->left;
			free(t);
			return r;
		}
	}

	//recursive steps
	if(x <= t->item){
		t->left = removeLeaf(x, t->left);
	}else if(x > t->item){
		t->right = removeLeaf(x, t->right);
	}


}

struct tree_node *Remove(int x, struct tree_node *t) {

//	struct tree_node *temp = t;

/*	if(t->item == x && t->left == NULL && t->right == NULL){
		free(t);
		printf("t->item blev fjernet\n");
		return NULL;
	}

	removeLeaf(x, t);

	return t;
*/

	//Base case: der er ikke noget træ
	if(t == NULL){
		return NULL;
	}

	//Base case: x er fundet
	if(t->item == x){
		//Hvis t er en leaf-node
		if(t->left == NULL && t->right == NULL){
			printf("item: %d\n", x);
			free(t);
			return NULL;
		}
		//Hvis t har venstre barn
		if(t->left != NULL){
			struct tree_node *temp = t->left;
			free(t);
			t = NULL;
			return temp;
		//Hvis t har højre barn
		}else if(t->right != NULL){
			struct tree_node *temp = t->right;
			free(t);
			t = NULL;
			return temp;
		//Hvis t har både venstre og højre barn
		}else{
			struct tree_node *r = t->right;
			struct tree_node *rParrent = t->right;
			//Finder mindste node hvis t har et højre barn
			while(r->left != NULL){
				rParrent = r;
				r = r->left;
			}
			//Hvis r har et højre barn, bliver temp sat til r->right og t->right->left bliver sat til temp
			if(r->right != NULL){
				struct tree_node *temp = r->right;
				rParrent->left = temp;
			}
			t->item = r->item;
			free(r);
			r = NULL;
			return t;
		}
	}

	//recursive steps
	if(x <= t->item){
		t->left = Remove(x, t->left);
		return t;
	}else if(x > t->item){
		t->right = Remove(x, t->right);
		return t;
	}



}

int Contains(int x, struct tree_node *t) {

	printf("x: %d, item: %d\n", x, t->item);

	if(x == t->item){
		printf("Træet indeholder %d\n", x);
		return 1;
	}else if(x <= t->item && t->left != NULL){
		Contains(x, t->left);
	}else if(x > t->item && t->right != NULL){
		Contains(x, t->right);
	}else{
		printf("Træet indeholder ikke %d\n", x);
		return 0;
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
