#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct bstree {
	char *key;
	char *value;
	
	struct  bstree *left;
	struct bsrtree *right;
} bstree;


struct bstree *bstree_create(char *key, char *value);
void bstree_add(struct bstree *tree, char *key, char* value);
struct bstree *bstree_lookup(struct bstree *tree, char *key);
struct bstree *bstree_delete(struct bstree *tree, char *key);
struct bstree *bstree_min(struct bstree *tree);
struct bstree *bstree_max(struct bstree *tree);

