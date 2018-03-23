
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

int abs(int number) {
if(number<0)
return -number;
else return 0;
}

int compare(struct node*head1, struct node* head2){
while(head1!=NULL) {
if(head1->next==head2->next)
return head1->next->data;
else{
head1=head1->next;
head2=head2->next;
}
}
return -1;
}



int getInterSectionPoint(struct node*head1 , struct node* head2) {
int firstListLength=0;
int secListLength=0;
struct node* temp1=head1;
struct node* temp2=head2;
while(temp1!=NULL || temp2!=NULL) {
if(temp1!=NULL) {
temp1=temp1->next;
firstListLength++;
}
if(temp2!=NULL) {
temp2=temp2->next;
secListLength++;
}
}
printf("\n the length of the lists are : %d and %d ",firstListLength,secListLength);
if(firstListLength==0 || secListLength==0) {
printf("there is no intersection point in the lists \n");
return;
}
int difference= abs(firstListLength-secListLength);
printf("\n the difference is %d ",difference);
struct node* temp;
int intersectionPoint;
if(firstListLength>secListLength) {
temp=head1;
int count=0;
while(firstListLength!=secListLength && count!= difference) {
temp=temp->next;
count++;
}
 intersectionPoint=compare(temp,head2);
}else {
    temp=head2;
int count=0;
while(firstListLength!=secListLength && count!= difference) {
temp=temp->next;
count++;
}
 intersectionPoint=compare(head1,temp);
}
return intersectionPoint;
}
int main(void) {
int numberToEnter,positionToEnterAT,lengthOfLinkedList,i,positionToDeleteAt,nodeToDelete;
  struct node* newNode;
  struct node* head1 =(struct node*) malloc(sizeof(head1));
  head1->data  = 10;

  struct node* head2 =(struct node*) malloc(sizeof(head2));
  head2->data  = 3;

  newNode = (struct node*) malloc (sizeof(newNode));
  newNode->data = 6;
  head2->next = newNode;

  newNode = (struct node*) malloc (sizeof(newNode));
  newNode->data = 9;
  head2->next->next = newNode;

  newNode = (struct node*) malloc (sizeof(newNode));
  newNode->data = 15;
  head1->next = newNode;
  head2->next->next->next  = newNode;

  newNode = (struct Node*) malloc (sizeof(newNode));
  newNode->data = 30;
  head1->next->next= newNode;

  head1->next->next->next = NULL;
printTheList(head1);
printTheList(head2);
int intersectionData=getInterSectionPoint(head1,head2);
if(intersectionData!=-1)
printf("\nThe intersection point in the list is : %d",intersectionData);
else printf("lists dont interset anywhere");
return 0;
}
