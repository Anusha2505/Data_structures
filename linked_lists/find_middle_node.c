#include <stdio.h>
#include <stdlib.h>          // printing middle node using count

struct node {
	int data;
	struct node *prev;
	struct node *next;
};

struct node *create_node(int data) {
	struct node *new_node = (struct node *)malloc(1 * sizeof(struct node));
	if (new_node == NULL) {
		return NULL;
	}
	new_node->data = data;
	new_node->prev = NULL;
	new_node->next = NULL;


	return new_node;
}

int main(int argc, char *argv[]) {
	struct node *head = NULL;
	struct node *new_node = NULL;
	struct node *temp = NULL;

	int i = 0;
	int n,input ;
	printf("\nEnter number of nodes to be created :");
	scanf("%d",&n);
	int count = 0;
	printf("\n");
	while (i < n) {
		printf("Enter data to be stored in node %d :",i+1);
		scanf("%d",&input);
		new_node = create_node(input);
		count++;
		if (head == NULL) {
			head = new_node ;
		} else {
			//  struct node * 
			temp = head;
			while (temp->next != NULL) {
				temp = temp->next;
			}
			temp->next = new_node ;
			new_node -> prev = temp;

		}

		i++;
	} 
	temp = head;
	i=0; 
	while(i<count/2){

		temp = temp->next;

		i++;
	}
	printf("\nMiddle node is %d and the data within is %d\n\n",i+1,temp->data);  

	return EXIT_SUCCESS;
}
