#include<stdio.h>
#include<malloc.h>
struct node {
int data;
struct node* next;
};
void push(struct node** head,int number, int position) {
    struct node* newNode = (struct node*)malloc(sizeof(newNode));
    struct node* temp=*head;
    newNode->data=number;
    if(*head==NULL ) {
        if(position>0)
        {
            printf("invalid position !!");
            return;
        }
        newNode->next=NULL;
        *head=newNode;
        return;
    }
    if(position==0) {
    newNode->next=*head;
    *head=newNode;
    return;
    }
    if(position>0) {
    int i;
    for(i=0;i<=position-2;i++) {
    temp=temp->next;
    }
    if(temp==NULL) {
    printf("invalid position !! ");
    return;
    }
    else {
    newNode->next=temp->next;
    temp->next=newNode;
    }

    }
}

void deleteTheList(struct node** head) {
struct node* temp=*head;
struct node* next;
while(temp!=NULL) {
next=temp->next;
free(temp);
temp=next;
}
*head=NULL;
}

void printTheList(struct node* head) {
if(head==NULL) {
printf("\nThere is no list to print");
return;
}
printf("the list is ");
while(head!=NULL) {
printf(" %d ",head->data);
head=head->next;
}
}
int main(void) {
int numberToEnter,positionToEnterAT,lengthOfLinkedList,number;
struct node* head=NULL;
//creating the list
push(&head,1,0);
push(&head,2,1);
push(&head,3,2);
push(&head,4,3);
push(&head,5,4);
printTheList(head);
printf("\n Lets delete the list. Please input 1 to continue or 0 ...\n");
scanf("%d",&number);
if(number==1)
deleteTheList(&head);
else
printf("\nThe list deletion operation is cancelled.");

printTheList(head);
return 0;
}
