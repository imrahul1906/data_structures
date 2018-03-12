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

void printTheList(struct node* head) {
printf("the list is ");
while(head!=NULL) {
printf(" %d ",head->data);
head=head->next;
}
}
int main(void) {
int numberToEnter,positionToEnterAT,lengthOfLinkedList,i;
struct node* head=NULL;
printf("Enter the length of the link list\n");
scanf("%d",&lengthOfLinkedList);
for(i=1;i<=lengthOfLinkedList;i++) {
printf("\nPlease enter the number and postion of the number ..\n");
scanf("%d%d",&numberToEnter,&positionToEnterAT);
push(&head,numberToEnter,positionToEnterAT);
printTheList(head);
}
return 0;
}
