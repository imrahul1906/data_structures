
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

int lengthOfLinkedList(struct node* head) {
    int count=0;
while(head!=NULL) {
head=head->next;
count++;
}
return count;
}

void find(struct node** head, int position) {
int i;
if(*head==NULL) {
printf("\nlist is empty. \n");
return;
}
struct node* temp=*head;
int count=lengthOfLinkedList(*head);
for(i=1;i<=count-position;i++) {
temp=temp->next;
}
if(temp==NULL  || position>count) {
printf("\nthere is no node at this position \n");
return;
}
else {
printf("\n the node is : %d",temp->data);
}
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
int numberToEnter,positionToEnterAT,lengthOfLinkedList,nodeToFind;
struct node* head=NULL;
//creating the list
push(&head,1,0);
push(&head,2,1);
push(&head,3,2);
push(&head,4,3);
push(&head,5,4);
printTheList(head);
printf("\n enter the node number from end you want to find\n");
scanf("%d",&nodeToFind);
find(&head,nodeToFind);
return 0;
}
