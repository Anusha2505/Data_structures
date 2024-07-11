#include <stdio.h>
#include <stdlib.h>

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
	struct node *current = NULL;
	struct node *tail = NULL;


	int i = 0;
	int n,input;
	printf("enter number of nodes to be created : ");
	scanf("%d",&n);
	while (i < n) {
		printf("enter data in node %d :",i+1);
		scanf("%d",&input);
		new_node = create_node(input);
		if (head == NULL) {
			head = new_node ;	
		} else {
			struct node *temp = head;
			while (temp->next != NULL) {
				temp = temp->next;
			}
			temp->next = new_node ;
			new_node -> prev = temp;

		}

		i++;
	}
	tail = new_node;
	current = head;
	printf("printing forward\n");
	while (current != NULL) {
		printf("%d ->", current->data);
		current = current->next;
	}
	printf("\n");
	printf("printing backward\n");
	while(tail != NULL){
		printf("%d <- ",tail->data);
		tail = tail->prev;
	}
	return EXIT_SUCCESS;
}
