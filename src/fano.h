#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct kluch {
	int counter;
	char word;
}kluch;

typedef struct bstree {
	char *key;
	char *value;
	
	struct  bstree *left;
	struct bstree *right;
} bstree;


struct bstree *bstree_create(char key, char *value);
void bstree_add(struct bstree *tree, char *key, char* value);
struct bstree *bstree_lookup(struct bstree *tree, char *key);
struct bstree *bstree_delete(struct bstree *tree, char *key);
struct bstree *bstree_min(struct bstree *tree);
struct bstree *bstree_max(struct bstree *tree);
void sfcompress(struct kluch *counter, int start, int end,struct bstree *tree);
int set_bit(char *text, int begin, int end);
int get_bits(char *text, int begin);
void count(char *text, int len, struct kluch *counter);

