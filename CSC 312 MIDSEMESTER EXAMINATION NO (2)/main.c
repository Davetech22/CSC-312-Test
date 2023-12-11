#include <stdio.h>
#include <stdlib.h>

int main()
typedef struct node {
  char data;
  struct node *next;
} node;
typedef struct stack {
  node *top;
} stack;
node *create_node(char data) {
  node *new_node = (node *)malloc(sizeof(node));
  if (new_node == NULL) {
    printf("Memory allocation error\n");
    exit(1);
  }
  new_node->data = data;
  new_node->next = NULL;
  return new_node;
}
void init_stack(stack *s) {
  s->top = NULL;
}
bool is_empty(stack *s) {
  return s->top == NULL;
}
void push(stack *s, node *n) {
  n->next = s->top;
  s->top = n;
}
char pop(stack *s) {
  if (is_empty(s)) {
    printf("Stack underflow error\n");
    exit(1);
  }
  node *temp = s->top;
  char data = temp->data;
  s->top = temp->next;
  free(temp);
  return data;
}
bool is_palindrome(char *str) {
  stack s;
  init_stack(&s);
  int len = strlen(str);
  for (int i = 0; i < len; i++) {
    node *n = create_node(str[i]);
    push(&s, n);
  }
    for (int i = 0; i < len; i++) {
    char c = pop(&s);
    if (c != str[i]) {
      return false;
    }
  }
return true;
}
int main() {
  char *str1 = "LAWAL";
 printf("%s is %sa palindrome\n", str1, is_palindrome(str1) ? "" : "not ");
  return 0;
}

