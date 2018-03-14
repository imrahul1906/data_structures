
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
void isLoop(struct node** head) {
struct node* fastPointer=*head;
struct node* slowPointer=*head;

if(*head==NULL) {
printf("list is empty !!");
return;
}
while(fastPointer->next!=NULL) {
slowPointer=slowPointer->next;
fastPointer=fastPointer->next->next;
if(slowPointer==fastPointer) {
    break;
    }
}
if(fastPointer->next==NULL) {
printf("\nthere is no loop in the list");
return;
} else {
    int count=0;
slowPointer=slowPointer->next;
count++;
while(slowPointer != fastPointer) {
slowPointer=slowPointer->next;
count++;
}
printf("\nThe length of the loop is : %d", count);
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
//lets create the loop for testing.
head->next->next->next->next->next=head->next;
isLoop(&head);
return 0;
}
