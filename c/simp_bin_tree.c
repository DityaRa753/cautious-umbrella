#include<stdio.h>

struct node {
  int val;
  struct node *left, *right;
} *tree;

void int_bin_tree_print_rec(struct node *r) {
  if(!r)
    return;
  int_bin_tree_print_rec(r->left);
  printf("%d ", r->val);
  int_bin_tree_print_rec(r->right);
}

void int_bin_tree_fill_rec(struct node *r) {
  for(int i = 1; i <= 20; i++) {
    int_bin_tree_fill_rec(r->left);
    r->val = i;
    int_bin_tree_fill_rec(r->right);
  }
}

int main()
{
  int_bin_tree_fill_rec(tree);
  int_bin_tree_print_rec(tree);
  return 0;
}
