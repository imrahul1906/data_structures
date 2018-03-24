#include<stdio.h>
void printTheSortedArray(int array[],int size) {
int i;
printf("\nthe sorted array is  : ");
for(i=0;i<size;i++) {
printf("%d ",array[i]);
}
}

void selectionSort(int array[],int size) {
int i,j;
int index;
for(i=0;i<size-1;i++) {
    index=i;
    for(j=i;j<size;j++) {
        if(array[j] < array[index]) {
            index=j;
        }
    }
    //swapping the numbers
    int temp=array[i];
    array[i]=array[index];
    array[index]=temp;
}
}

int main(void) {
int i,j;
int array[5]={8,54,76,15,2};
printf("The array is : ");
for(i=0;i<5;i++) {
printf("%d ",array[i]);
}
selectionSort(array,5);
printTheSortedArray(array,5);
return 0;}
