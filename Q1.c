#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
	char name[30];
	int roll;
	char branch[5];
	struct node *next;	
};
struct node *head,*temp,*newnode;
void create();
void display();
void insert_begin(struct node *);
void insert_end(struct node *);

void main(){
	create();
	display();
}

void create(){
	char flag;
	do{
		
		newnode=(struct node *)malloc(sizeof(struct node));
		
		printf("Enter Name of Student: ");
		gets(newnode->name);
		
		printf("Enter Branch of Student: ");
		gets(newnode->branch);
	
		printf("Enter Roll No. of Student: ");
		scanf("%d", &newnode->roll);
	
		int compare=strcmp(newnode->branch,"CSCE");
		if(compare==0){
			insert_begin(newnode);
		}	
		else{
			insert_end(newnode);
		}
		
		printf("Do you want to continue(y/n)? ");
		scanf(" %c",&flag);
		getchar();
			
	}while(flag='y' && flag!='n');
}

void insert_begin(struct node *temp1){
	if(head==NULL){
		head=temp1;
		temp1->next=NULL;
	}
	else{
		temp1->next=head;
		head=temp1;	
	}	
}

void insert_end(struct node *temp2){
	if(head==NULL){
		head=temp2;
		temp2->next=NULL;
	}
	else{
		temp=head;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=temp2;
		temp2->next=NULL;
	}
}

void display(){
	temp=head;
	while(temp!=NULL){
		printf("\n\n");
		printf("Student's Name: ");
		puts(temp->name);
		printf("Student's Branch: ");
		puts(temp->branch);
		printf("Student's Roll No: %d",temp->roll);
		
		temp=temp->next;
	}
}
