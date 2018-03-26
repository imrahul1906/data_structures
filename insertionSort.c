#include<stdio.h>
void insertionSort(int arr[], int size) {
int i,j;
for(i=1;i<size;i++) {
    int key=arr[i];
    j=i-1;
    while(j>=0 && arr[j] > key) {
     arr[j+1]=arr[j]   ;
    j--;
    }
    arr[j+1]=key;
}
}
void printTheSortedArray(int array[],int size) {
int i;
printf("\nthe sorted array is  : ");
for(i=0;i<size;i++) {
printf("%d ",array[i]);
}
}
int main(void) {
    int i;
int arr[5]= {25,2,42,54,5};
printf("The array is : ");
for(i=0;i<5;i++) {
printf("%d ",arr[i]);
}
insertionSort(arr,5);
printTheSortedArray(arr,5);
return 0;
}
