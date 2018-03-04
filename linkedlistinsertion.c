#include<stdio.h>
#include<malloc.h>
struct node {
int data;
struct node* next;
};
struct node* head;

void insertInLinkedList(int data){
struct node* newNode=(struct node*)malloc(sizeof(newNode));
newNode->data=data;
newNode->next=head;
head=newNode;
}

void insertAtRandomPosition(int data,int position){
if(position==0){
printf("this is invalid position\n");
return;
}
if(position==1){
insertInLinkedList(data);
return;
}
int i;
struct node * temp;
temp=head;
struct node* newNode=(struct node*)malloc(sizeof(newNode));
for(i=1;i<=position-2;i++){
temp=temp->next;
}
newNode->data=data;
newNode->next=temp->next;
temp->next=newNode;
}

void insertAtLast(int data){
    if(head==NULL){
    insertInLinkedList(data);
return;
    }
struct node* temp=head;
while(temp->next!=NULL){
temp=temp->next;
}
struct node* newNode=(struct node*)malloc(sizeof(newNode));
newNode->data=data;
newNode->next=temp->next;
temp->next=newNode;
}

void deleteFromLinkedList(int position){
struct node* temp=head;
struct node* nextToTemp=NULL;
int i;
if(position==0){
printf("this is invalid position\n");
return;
}
if(position==1){
head=temp->next;
free(temp);
return;
}
for(i=1;i<=position-2;i++){
temp=temp->next;
}
nextToTemp=temp->next;
temp->next=nextToTemp->next;
free(nextToTemp);
}

int lengthOfLinkedList(){
    struct node* temp=head;
    int count=1;
    if(head==NULL)return 0;
    while(temp->next!=NULL){
    count++;
    temp=temp->next;
    }
   return count;
}
int recursiveLenthOfLinkedList(struct node* head,int count)
{
    if(head==NULL)return 0;
    if(head->next==NULL)
    return count;
    else
    recursiveLenthOfLinkedList(head->next,count+1);
}
int findNumber(int number){
struct node* temp=head;

while(temp->data != number && temp->next!=NULL) {
temp=temp->next;
}
if(temp->data==number){
return 1;
}else {
return 0;}
}

int recursiveFindNumber(struct node* head,int number){
    if(head==NULL)
    return 0;
    if(head->data==number)
    return 1;
    else if(head->next!=NULL)
    recursiveFindNumber(head->next,number);
    else return 0;
}

void swap(int posix, int posiy){
struct node* prevx=NULL;
struct node* prevy=NULL;
struct node* tempx=head;
struct node* tempy=head;

while(tempx->data!=posix ){
    prevx=tempx;
tempx=tempx->next;
}
while(tempy->data!=posiy ){
    prevy=tempy;
tempy=tempy->next;
}
if(prevx!=NULL)
prevx->next=tempy;
else
head=tempy;

if(prevy!=NULL)
prevy->next=tempx;
else
head=tempx;

if(tempx==NULL || tempy==NULL)
return;
if(tempx==tempy)
return;
struct node*temp=tempx->next;
tempx->next=tempy->next;
tempy->next=temp;
}

void print(){
    struct node* temp;
    temp=head;
    printf("the list is : ");
while(temp!=NULL)
{
    printf("%d ",temp->data);
    temp=temp->next;
}
}
int main(void){
int num,i,insertednumber,num_p,position,positionToDelete,number_to_find,x,y;
head=NULL;
printf("\nhow many data you want to insert at any random position ?\n");
scanf("%d",&num_p);
for(i=1;i<=num_p;i++)
{
    printf("\nenter the data and postition..\n");
    scanf("%d%d",&insertednumber,&position);
    insertAtRandomPosition(insertednumber,position);
    print();
}
printf("\nenter number to insert at last position in linked list\n");
scanf("%d",&num);
insertAtLast(num);
print();

printf("\n enter the postion you want to delete the node at \n");
scanf("%d",&positionToDelete);
deleteFromLinkedList(positionToDelete);
print();
printf("\nthe length of the list is : %d\n",lengthOfLinkedList());
printf("\n the length of the linked list in recursive method is : %d\n",recursiveLenthOfLinkedList(head,1));
printf("\n if you wanna find the element in linked list please enter the element ..\n");
scanf("%d",&number_to_find);
int isNumber=findNumber(number_to_find);
printf("\nso the number is present .this statement is ");
(isNumber == 0 ? printf("false"): printf("true"));

printf("%recursive solution is number is present or not : %d\n",recursiveFindNumber(head,number_to_find));

printf("please enter the numbers you want to swap.");
scanf("%d%d",&x,&y);
swap(x,y);
print();
return 0;
}
