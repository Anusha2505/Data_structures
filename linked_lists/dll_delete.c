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
} struct node *temp = NULL;

int main(int argc, char *argv[]) {
	struct node *head = NULL;
	struct node *new_node = NULL;
	struct node *current = NULL;
	struct node *tail = NULL;
	struct node *temp = NULL;
	struct node *delete = NULL;

	int number, position,input;
	int i = 0;
	int n ;
	printf("\nEnter number of nodes to be created :");
	scanf("%d",&n);
	printf("\n");
	while (i < n) {
		printf("enter data for node %d :",i+1);
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
	current= temp;
	tail = temp->next ;
	printf("\nEnter 1 to delete node at the beginning\n");
	printf("Enter 2 to delete node in the middle\n");
	printf("Enter 3 to delete node at the end\n");
	scanf("%d",&number);

	switch(number){

		case 1 :                                                   // starting
			printf("You have chosen to delete 1st node \n");
			delete = head;
			head = delete->next;
			head->prev = NULL;
			free(delete);
			break;

		case 2  :
			// middle node

			printf("\nEnter position of node to be deleted from 2 - %d :",n-1);
			scanf("%d",&position);
			if(position <2  && position < n-1){
				printf("INVALID .... TRY AGAIN \n");
			}
			else if(position >= n){
			printf("INVALID... TRY AGAIN\n");
			}
			else{
				printf("You have chosen to delete node %d\n",position);
				i=0;
				delete = head;
				current    = head;  
				while(i<position-1){
					current = delete;
					delete = delete->next;

					i++; 
				} 
				temp= delete->next;
				current->next = temp;
				temp->prev = current;
				delete = NULL;
				free(delete);
			}
			break;

		case 3 :
			// end node
			printf("You have chosen to delete the last node\n");
			delete = tail;
			tail = current;
			tail->next = NULL;
			delete->prev = NULL;
			free(delete);                                      
			break;
		default :
			printf("invalid number....please try and enter numbers between 1-3\n");
			break; 
	}
	if(number>3){
		printf("\nTRY AGAIN....\n");
	}
	else{

		current = head;
		printf("\nprinting forward of your current data :");
		while (current != NULL) {
			printf("%d ->", current->data);
			current = current->next;
		}
		printf("\n");
		printf("printing backward of your current data :");
		while(tail != NULL){
			printf("%d <- ",tail->data);
			tail = tail->prev;
		}
		printf("\n\n");
	}

	return EXIT_SUCCESS;
}
