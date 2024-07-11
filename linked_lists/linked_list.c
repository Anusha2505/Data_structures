#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *link;
};

int main(int argc, char *argv[]) {
  struct node *head = NULL;
  struct node *current = NULL;
  int n;
  printf("Enter number of nodes :");
  scanf("%d",&n);

    for(int i =0;i<n;i++){
        
         struct node *new_node = (struct node *)malloc(1 * sizeof(struct node));
         printf("Enter node %d data :",i+1);
         scanf("%d",&new_node -> data);
         new_node -> link = NULL;

                if(i == 0){
                    head = new_node;
                    current = head;
                }
     
       current->link = new_node;
       current = new_node;
       
    }

  current = head;
  while (current != NULL) {
    printf("%d ->", current->data);
    current = current->link;
  }
  printf("\n");
  return EXIT_SUCCESS;
}
