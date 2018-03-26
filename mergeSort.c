#include<stdio.h>
void merge(int array[], int size,int l,int m, int r) {
int length1=m-l+1;
int length2=r-m;
int left[length1];
int right[length2];
int i,j,k=0;
//fill left and right array
for(i=0;i<length1;i++){
left[i]=array[i+l];
}
for(i=0;i<length2;i++){
right[i]=array[i+m+1];
}

//compare left and right array
i=0;j=0;k=l;
while(i<length1 && j<length2) {
if(left[i] <= right[j]){
array[k]=left[i];
i++;
}
else{
array[k]=right[j];
j++;
}
k++;
}

//if while loop exited and some elements are remaining
while(i<length1){
array[k]=left[i];
i++;
k++;
}
while(j<length2) {
array[k]= right[j];
j++;
k++;
}
}
void mergeSort(int arr[],int size,int l,int r) {
if(l<r) {
 int m = (l+r)/2;
mergeSort(arr,size,l,m);
mergeSort(arr,size,m+1,r);
merge(arr,size,l,m,r);
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
int arr[8]= {25,2,42,54,5,98,1,74};
printf("The array is : ");
for(i=0;i<8;i++) {
printf("%d ",arr[i]);
}
mergeSort(arr,8,0,7);
printTheSortedArray(arr,8);
return 0;
}
