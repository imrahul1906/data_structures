


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

//reversing the linked list
struct node* reverse(struct node* head) {
    struct node* current;
    struct node* prev;
    struct node* nextNode;
    current=head->next;
     prev=NULL;
     nextNode=NULL;

    while(current!=NULL) {
    nextNode=current->next;
    current->next=prev;
    prev=current;
    current=nextNode;
    }

return prev;
}

void printTheList(struct node* head) {
printf("the list is ");
while(head!=NULL) {
printf(" %d ",head->data);
head=head->next;
}
printf("\n");
}

//if palindrom
int compare(struct node* slowPointer,struct node* temp) {
while(slowPointer!=NULL) {
if(slowPointer->data!=temp->data){
printf("\nlist is not palindrom");
return 0;
}
slowPointer=slowPointer->next;
temp=temp->next;
}
return 1;
}

int isPalindrome(struct node** head) {
struct node* temp=*head;
struct node* fastPointer=*head;
struct node* slowPointer =*head;
struct node* prevSlow;
//logic to find if list is even or odd
while(fastPointer!=NULL && fastPointer->next!=NULL) {
prevSlow=slowPointer;
slowPointer=slowPointer->next;
fastPointer=fastPointer->next->next;
}
if(fastPointer==NULL) {
printf("\nthe list is even");
//reversing the second half
prevSlow->next=reverse(prevSlow);
printf("\nAfter reversing the second half ");
printTheList(temp);
//checking if palindrome
return compare(prevSlow->next,temp);
}
if(fastPointer->next==NULL) {
printf("\nthe list is odd");
//reversing the second half
slowPointer->next=reverse(slowPointer);
printf("\nAfter reversing the second half ");
printTheList(temp);
//checking if palindrome
return compare(slowPointer->next,temp);
}

}
int main(void) {
int numberToEnter,positionToEnterAT,lengthOfLinkedList,i,number;
struct node* head=NULL;
//creating the list
push(&head,1,0);
push(&head,2,1);
push(&head,3,2);
push(&head,4,3);
push(&head,3,4);
push(&head,2,5);
push(&head,1,6);
//push(&head,8,7);
printTheList(head);
//reversing the list
int value=isPalindrome(&head);
if(value==0)
printf("list is not palindrome");
else printf("list is palindrome");
return 0;
}
