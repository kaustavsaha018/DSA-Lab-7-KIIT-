#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node *head,*temp,*newnode;

void create();
void display();
void search(int);

int main(){
	create();
	display();
	int n;
	printf("\nEnter the an element to be searched: ");
	scanf("%d", &n);
	search(n);
	display();
}

void create(){
	char flag;
	printf("Enter the elements of the Linked List:\n\n");
	do{
		newnode = (struct node *)malloc(sizeof(struct node));
		if(head==NULL){
			printf("Enter data: ");	
			scanf("%d", &newnode->data);
			head=newnode;
			temp=newnode;
			temp->next=NULL;
			
		}
		else{	
			printf("Enter data: ");	
			scanf("%d", &newnode->data);
			temp->next=newnode;
			temp=newnode;
			temp->next=NULL;
		
		}
		printf("Do you want to continue(y/n)? ");
		scanf(" %c",&flag);
		getchar();
		
	}while(flag='y' && flag!='n');
}

void display(){
	printf("\nThe List is Diplaying...\n");
	temp=head;
	while(temp!=NULL){
		printf(" %d ", temp->data);
		temp=temp->next;
	}	
}

void search(int n){
	temp=head;
	struct node *req=NULL,*prev=NULL; 
	while(temp!=NULL){
		
		if(n==temp->data){
			req=temp;
			break;
		}
		prev=temp;
		temp=temp->next;
	}
	if(req==NULL){
		printf("\nEntered element is not found in the list!");
		exit(0);
	}
	else{
		prev->next=req->next;
		req->next=head;
		head=req;
	}	
}
