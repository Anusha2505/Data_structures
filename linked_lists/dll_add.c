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
	struct node *temp = NULL;

	int number,new_data,position;
	int i = 0;
	int n ,input;
	printf("number of new nodes to be created: ");
	scanf("%d",&n);
	while (i < n) {
		printf("data to be inserted in node %d :",i+1);
		scanf("%d",&input);
		new_node = create_node(input);
		if (head == NULL) {
			head = new_node ;
		} else {
			temp = head;
			while (temp->next != NULL) {
				temp = temp->next;
			}
			temp->next = new_node ;
			new_node -> prev = temp;

		}

		i++;
	}
	tail = temp->next ;
	printf("\n");
	printf("Enter 1 to add node at the beginning\n");
	printf("Enter 2 to add node at middle\n");
	printf("Enter 3 to add node at the end\n");
	scanf("%d",&number);

	printf("Enter new data to add ....\n");
	scanf("%d",&new_data);

	switch(number){

		case 1 :                                                   // starting

			new_node = create_node(new_data);
			head -> prev = new_node;
			new_node->next = head;
			head = new_node;
			break;

		case 2  :
			// middle node
			printf("Enter node position to be added\n");
			scanf("%d",&position);
			new_node = create_node(new_data);
			i=0;
			current = head;
			temp = head;
			while(i<position-1){
				current = temp;
				temp = temp->next;
				i++;
			}
			current->next = new_node;
			new_node -> next = temp;
			temp->prev = new_node;
			new_node->prev = current;
			break;

		case 3 :
			// end node
			new_node = create_node(new_data);
			tail->next = new_node;
			new_node->prev = tail;
			tail = new_node;                                    
			break;
		default :
			printf("invalid number....Enter number between 1 - 3"); 
	}



	current = head;
	printf("printing forward\n");
	while (current != NULL) {
		printf("%d ->", current->data);
		current = current->next;
	}
	printf("\n\n");
	printf("printing backward\n");
	while(tail != NULL){
		printf("%d <- ",tail->data);
		tail = tail->prev;
	}
	printf("\n");

	return EXIT_SUCCESS;
}
