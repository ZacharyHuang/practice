#include <stdio.h>
#include <stdlib.h>

typedef struct tree_node_struct
{
	int m;
	char s[51];
	struct tree_node_struct *lchild;
	struct tree_node_struct *rchild;
} tree_node_t;
tree_node_t *new_tree_node(int len)
{
	tree_node_t *new = (tree_node_t *)calloc(1, sizeof(tree_node_t));
	new->lchild = new->rchild = NULL;
	scanf("%s", new->s);
	int i;
	int count = 0;
	int c[3] = {0};
	for (i = len - 1; i >= 0; i --) {
		switch (new->s[i]) {
		case 'A':
			c[0]++;
			break;
		case 'C':
			c[1]++;
			count += c[0];
			break;
		case 'G':
			c[2]++;
			count += c[0] + c[1];
			break;
		case 'T':
			count += c[0] + c[1] + c[2];
			break;
		default:
			printf("wrong dna!\n");
			break;
		}
	}
	new->m = count;
	return new;
}
void insert_tree(tree_node_t *root, tree_node_t *p)
{
	while (1) {
		if (root->m > p->m) {
			if (root->lchild != NULL) {
				root = root->lchild;
			}
			else {
				root->lchild = p;
				break;
			}
		}
		else {
			if (root->rchild != NULL) {
				root = root->rchild;
			}
			else {
				root->rchild = p;
				break;
			}
		}
	}
}
void print_tree_lmr(tree_node_t *p)
{
	if (p == NULL) {
		return;
	}
	print_tree_lmr(p->lchild);
	printf("%s\n", p->s);
	print_tree_lmr(p->rchild);
}
void free_tree(tree_node_t* p)
{
	if (p == NULL) {
		return;
	}
	free_tree(p->lchild);
	free_tree(p->rchild);
	free(p);
}
int main (int argc, char *argv[])
{
	int m, n;
	scanf("%d %d", &n, &m);
	int i = 0;
	tree_node_t *root = new_tree_node(n);
	for (i = 1; i < m; i ++) {
		insert_tree(root, new_tree_node(n));
	}
	print_tree_lmr(root);
	free_tree(root);
	return 0;
}
















