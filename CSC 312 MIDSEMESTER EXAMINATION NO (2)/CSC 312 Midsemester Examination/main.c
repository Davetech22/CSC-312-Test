#include <stdio.h>
#include <stdlib.h>

int main()
// CSC312 Mid Semester Ouestion NO3
struct node {
double data;
struct node* next;
};
struct node* top = NULL;
int push(double x) {
 struct node* new_node = (struct node*)malloc(sizeof(struct node));
if (new_node == NULL) {
printf("Stack overflow\n");
return 0;
}
new_node->data = x;
new_node->next = top;
top = new_node;
return 1;
}

