#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node *head,*temp,*newnode;

void create();
void display();
void compute(int, int);

int main(){
	create();
	display();
	int K,L;
	printf("\n\nEnter the value of K: ");
	scanf("%d", &K);
	printf("Enter the value of L: ");
	scanf("%d", &L);
	compute(K,L);
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

void compute(int k, int l){
	temp=head;
	while(temp!=NULL){
		if(temp->data%2==0){
			temp->data=temp->data-l;
		}
		else{
			temp->data=temp->data+k;
		}
		temp=temp->next;
	}
}
