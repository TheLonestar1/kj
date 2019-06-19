#include"bstree.h"

struct bstree *bstree_create(char *key, char *value) {
	struct  bstree *node;
	node = malloc(sizeof(*node));
	if(node != NULL) {
		node->key = key;
		node->value = value;
		node->left = NULL;
		node->right = NULL;
	}
	return node;
}
void  bstree_add(struct bstree *tree, char *key, char *value) {
if (tree == NULL)
return;
struct bstree *parent, *node;
while (tree != NULL) {
parent = tree;
if (strcmp(key,tree->key) < 0)
tree = tree->left;
else if (strcmp(key,tree->key) > 0)
tree = tree->right;
else return;
}

node = bstree_create(key, value);
if (strcmp(key,parent->key) < 0)
parent->left = node;
else
parent->right = node;
}
struct bstree *bstree_lookup(struct bstree *tree, char *key) {
	
	while(tree != NULL){
		if(strcmp(key,tree->key) == 0){
			return tree;
		}
		else if(strcmp(key,tree->key) < 0){
			tree = tree->left;
		}
		else {
			tree = tree->right;
		}
		return tree;
	}
}
struct bstree *bstree_delete(struct bstree *tree, char *key) {
	
	struct bstree *deleter, *changer, *parent;
	parent = tree;
	if(strcmp(key,tree->key) == 0) {
		free(tree);
		return NULL;
	}
	else if(strcmp(key,parent->key) > 0) {
		deleter = parent->right;
		while(deleter != NULL){
			deleter = parent->right;
			
			if(strcmp(key,deleter->key) == 0) {
				if((deleter->right == NULL) && (deleter->left == NULL)){
					parent->right = NULL;
					free(deleter);
					break;
				}
				else if((deleter->right != NULL) && (deleter->left == NULL)){
					parent->right = deleter->right;
					free(deleter);
					break;
				}
				else if((deleter->right == NULL) && (deleter->left != NULL)){
					parent->right = deleter->left;
					free(deleter);
					break;
				}	
				else if((deleter->right != NULL) && (deleter->left != NULL)){
					changer = bstree_min(deleter);
					parent->right = changer;
					free(deleter);
					break;
				}
			} else {
				parent = parent->right;
			}	
		}	
	} else if(strcmp(key,parent->key) < 0) {
		deleter = parent->left;
		while(deleter != NULL){
			deleter = parent->left;
			if(strcmp(key,deleter->key) == 0) {
				if((deleter->right == NULL) && (deleter->left == NULL)){
					parent->left = NULL;
					free(deleter);
				}
				else if((deleter->right != NULL) && (deleter->left == NULL)){
					parent->left = deleter->right;
					free(deleter);
				}
				else if((deleter->right == NULL) && (deleter->left != NULL)){
					parent->left = deleter->left;
					free(deleter);
				}	
				else if((deleter->right != NULL) && (deleter->left != NULL)){
					changer = bstree_min(deleter);
					parent->left = changer;
					free(deleter);
				}
			} else {
				parent = parent->left;
			}	
		}	
	}
	return tree;
} 
	

struct bstree *bstree_min(struct bstree *tree) {
	
	if(tree == NULL) return NULL;
	
	while(tree->left != NULL) 
		tree = tree->left;
	
	return tree;
}
struct bstree *bstree_max(struct bstree *tree) {
	
	if(tree == NULL) return NULL;
	while(tree->right != NULL) 
		tree = tree->right;
	return tree;
}
