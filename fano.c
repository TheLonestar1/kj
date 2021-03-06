#include"fano.h"
struct bstree *bstree_create(char *key, int value) {
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
int lenstr(char *text){
	int summ = 0;
	for(int i = 0; (i < 256) && (text[i] != 0); i++){
		summ = summ + 1 ;
	}
    return summ;
}

void  bstree_add(struct bstree *tree, char *key, int value) {
if (tree == NULL)
return;
struct bstree *parent, *node;
while (tree != NULL) {
parent = tree;
if ((lenstr(key) == 1) && (tree->left == NULL))
tree = tree->left;
else
tree = tree->right;
}

node = bstree_create(key, value);
if (lenstr(key) == 1)
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

void obnul(struct kluch *counter) {
	for(int i = 0; i < 10;i++){
		counter[i].counter = 0;		
	}	
	
}

void count(char *text, int len, struct kluch *counter){
  	obnul(counter);
	for(int i = 0; i < len; i++){
		char buf  = text[i];
		
		for(int j = 0; j < 4; j++){
			if(buf == counter[j].word){
				counter[j].counter++;
				break;			
			} else if(counter[j].counter == 0){
			  	counter[j].word = buf;
				counter[j].counter++;
				break;		
			}
		}
	}
	for(int j = 0; j < 4; j++){
		
		for(int i = 0; i < 3; i++) {
			if(counter[i].counter < counter[i+1].counter){
				int buf_num = counter[i].counter;
				char buf_char= counter[i].word;
				counter[i].counter = counter[i + 1].counter;
				counter[i].word =counter[i+1]. word;
				counter[i+1].counter = buf_num;
				counter[i+1].word = buf_char;
			}
		}
	}
	
}

void sfcompress(struct kluch *counter, int start, int end,struct bstree *tree){
	int index = start - end;
	char buffer[2] = {0};
	if((index - start) > 1) sfcompress(counter,start,index,tree);
	else {
		buffer[0] = counter[index].word;
		bstree_add(tree, buffer,1);
	}
	if((end - index) > 1){
		char words[100] = {0};
		int j = 0;
		for(int i = index + 1; i < 4; i++){
			words[j] = counter[i].word;
			j++;
		}
		bstree_add(tree, words, 0);
		sfcompress(counter,start + 1,end,tree);
	} 
	else {
		
		buffer[0] = counter[index].word;
		bstree_add(tree, buffer,1);
   } 
}

