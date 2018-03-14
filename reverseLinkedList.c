
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
void reverse(struct node** head) {
struct node* prev=NULL;
struct node* current=*head;
struct node* nextNode=*head;
if(*head==NULL){
printf("\n List is empty\n");
return;
}
while(current!=NULL) {
nextNode=current->next;
current->next=prev;
prev=current;
current=nextNode;
}
*head=prev;
}
void mainMethod(struct node** head,struct node* prev,struct node* current,struct node* nextNode) {
if(current==NULL) {
*head=prev;
return;
}
nextNode=current->next;
current->next=prev;
prev=current;
current=nextNode;
mainMethod(head,prev,current,nextNode);

}

void recursiveReverse(struct node** head) {
if(*head==NULL){
printf("\n the lis tis empty\n");
return;
}
mainMethod(head,NULL,*head,*head);
}

void printTheList(struct node* head) {
printf("the list is ");
while(head!=NULL) {
printf(" %d ",head->data);
head=head->next;
}
printf("\n");
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
//reversing the list
reverse(&head);
printTheList(head);
recursiveReverse(&head);
printTheList(head);
return 0;
}
