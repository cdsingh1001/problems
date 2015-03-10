/* Write a program to delete duplicates from a sorted array.
 * For eg:- if A = {2,3,5,5,7,11,11,11,13}
 * then after deletion, A = {2,3,5,7,11,13,0,0,0}
 * */

#include "stdio.h"

/* Input Data */
void inputData(int arr[], int *len)
{
    int i;
    printf("Enter size of array: ");
    scanf("%d",len);

    for (i=0; i< *len; i++) {
        printf("Enter number: ");
        scanf("%d",&arr[i]);
    }
    printf("\n");
}

/* Print Data */
void printData(int arr[], int len)
{
    int i;

    for (i=0;i<len;i++) {
        printf("\t%d",arr[i]);
    }
    printf("\n");
}

/* Function to remove duplicates from a sorted array */
void removeDuplicates(int arr[], int len)
{
    int i,j;

    if (len == 1) {
        return;
    }

    i = j = 0;
    j = i+1;
    for (i=0; i<len; i++) {
        if (j == len) {
            arr[i] = 0;
        }
        else {
            while (j < len && arr[j] == arr[i]) {
                j++;
            }
            if (i != j+1) {
                arr[i+1] = arr[j];
            }
        }
    }
}

/* Driver function */
int main()
{
    int len;
    int data[100];

    inputData(data, &len);
    printData(data,len);
    removeDuplicates(data,len);
    printData(data,len);
}
