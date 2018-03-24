
#include<stdio.h>
void printTheSortedArray(int array[],int size) {
int i;
printf("\nthe sorted array is  : ");
for(i=0;i<size;i++) {
printf("%d ",array[i]);
}
}

void swap(int *x, int *y) {
int temp = *x;
*x=*y;
*y=temp;
}

void recursiveBubbleSort(int array[],int size) {
    int j;
    if(size==0)
    return;

for(j=0;j<size-1;j++) {
        if(array[j] > array[j+1]) {
            swap(&array[j],&array[j+1]);
        }
    }
    bubbleSort(array,size-1);
}

void bubbleSort(int array[],int size) {
int i,j;
int swapped;
for(i=0;i<size-1;i++) {
    swapped=0;
    for(j=0;j<size-i-1;j++) {
        if(array[j] > array[j+1]) {
            swap(&array[j],&array[j+1]);
            swapped=1;
        }
    }
    if(swapped==0)
    break;
}
}

int main(void) {
int i,j;
int array[5]={8,54,76,15,2};
printf("The array is : ");
for(i=0;i<5;i++) {
printf("%d ",array[i]);
}
//bubbleSort(array,5);
//printTheSortedArray(array,5);
recursiveBubbleSort(array,5);
printTheSortedArray(array,5);
return 0;}
