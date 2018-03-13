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

void delete(struct node** head, int position,int key)
{
    int i;
    struct node* temp=*head;
    struct node* prev=NULL;
    if(*head==NULL) {
    printf("\nthere is nothing to delete\n");
    return;
    }
    //passed -1 so that i dont have to make 2 methods for 2 type of deletes
    if(position!=-1) {
    if(position == 0) {
        struct node* temp=*head;
        *head=temp->next;
        free(temp);
    }
    if(position>0) {
    for(i=0;temp!=NULL && i<=position-1;i++) {
    prev=temp;
    temp=temp->next;
    }
    if(temp==NULL){
    printf("\ninvalid position !!\n");
    return;
    } else {
    prev->next=temp->next;
    free(temp);
    }
    }
    } else {
    while(temp->data!=key) {
    prev=temp;
    temp=temp->next;
    }
    if(temp==NULL){
    printf("\nthere is no data like this \n");
    return;
    } else {
        //if first node
        if(prev==NULL) {
        *head=temp->next;
        free(temp);
        return;
        }
    prev->next=temp->next;
    free(temp);
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
int numberToEnter,positionToEnterAT,lengthOfLinkedList,i,positionToDeleteAt,nodeToDelete;
struct node* head=NULL;
//creating the list
push(&head,1,0);
push(&head,2,1);
push(&head,3,2);
push(&head,4,3);
push(&head,5,4);
printTheList(head);
//deletion logic starts here
printf("\nplease enter the position of the node you want to delete at.. \n");
scanf("%d",&positionToDeleteAt);
delete(&head,positionToDeleteAt,-1);
printTheList(head);
printf("\nEnter the node that you want to delete. \n");
scanf("%d",&nodeToDelete);
delete(&head,-1,nodeToDelete);
printTheList(head);
return 0;
}
