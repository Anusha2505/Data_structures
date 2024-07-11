#include <stdio.h>
#include<stdlib.h>

struct node {
	int id;
	char name[64];
	int class;
	char gender;

	struct node *link;
};

struct node *create_node(int n) {
	struct node *new_node = (struct node *)malloc(1 * sizeof(struct node));
	if (new_node == NULL) {
		return NULL;
	}
	new_node->link = NULL;

	return new_node;

}


int main(int argc, char *argv[]) {
	struct node *head = NULL;
	struct node *new_node = NULL;


	int number,givenid;
	printf("Enter 1 to insert a node\n");
	printf("Enter 2 to delete a node\n");
	printf("Enter 3 to print the nodes\n");

	scanf("%d",&number);
	printf("\n");
	int i = 0;
	int n;
	printf("number of nodes to be created to store student details: ");
	scanf("%d",&n);

	while (i < n) {
		new_node = create_node(i);
		printf("enter student %d details id,name,class,gender\n",i+1);
		scanf(" %d %s %d %c",&new_node->id,new_node->name,&new_node->class,&new_node->gender);
		if (head == NULL) {
			head = new_node;
		} else {
			struct node *temp = head;
			while (temp->link != NULL) {
				temp = temp->link;
			}
			temp->link = new_node;
		}
		i++;
		printf("\n");
	}

	struct node *current = NULL;
	struct node *temp = NULL;

	int idnumber;
	switch (number){


		case 1 :        
			new_node = create_node(i);
			printf("enter new student details to be added id,name,class,gender\n");
			scanf(" %d %s %d %c",&new_node->id,new_node->name,&new_node->class,&new_node->gender);
			if (head == NULL) {
				head = new_node;
			} else {
				struct node *temp = head;
				while (temp->link != NULL) {
					temp = temp->link;
				}
				temp->link = new_node;
			}


			break;
		case 2 :

			temp = head;
			new_node= head;
			printf("Enter ID number to be deleted\n");
			scanf("%d",&idnumber);
			while(temp != NULL){
				if( temp!=NULL && head->id == idnumber && temp->link !=NULL){
					temp = head;
					head = head->link; // deleting 1st node
					free(temp);
					break; 
				}  
				if(temp!=NULL && temp->id == idnumber && temp->link !=NULL){
					// deleting middle node
					new_node->link = temp->link;
					free(temp);
					break;

				}
				if(temp ->link == NULL && temp != NULL){
					new_node->link = NULL; 
					free(temp);    // deleting last node
					break;
				}
				new_node=temp;
				temp = temp->link;
			}
			printf("After deleting.....\n");
			new_node = head;
			while (new_node != NULL) {
				printf("Id -%d\nName-%s\nClass-%d\nGender-%c\n",new_node->id,new_node->name,new_node->class,new_node->gender);

				new_node = new_node->link;
				printf("\n");
			} 
			break;
		case 3 :

			current = head;

			printf("Enter student id to be printed\n");
			scanf(" %d",&givenid);
			while(current!=NULL && current->id != givenid && current->link !=NULL){
				current = current->link;
			}
			printf("Id -%d\nName-%s\nClass-%d\nGender-%c\n",current->id,current->name,current->class,current->gender);             
			break;

		default : 
			printf("Enter valid number\n");            
	}
	return EXIT_SUCCESS;
}
