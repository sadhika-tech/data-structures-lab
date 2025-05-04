#include<stdio.h>
#include<stdlib.h>
//swap function for required sorting
int swap(int *elt1ptr,int *elt2ptr)
{
    int temp=*elt1ptr;
    *elt1ptr=*elt2ptr;
    *elt2ptr=temp;
}
//bubblesort function 
void bubblesort(int array[],int size )
{
    for(int pass=0;pass<size-1;pass++)
    {
        for(int i=0;i<size-1;i++)
        {
            if(array[i]>array[i+1])
            {
                swap(&array[i],&array[i+1]);
            }
        }
    }
}
//insertion sort function
void insertionsort(int arr[],int n)
{
    for (int i=1;i<n;i++)
    {
        int key =arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}
//selection sort function
int selectionsort(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        int min=i;
        for(int j=i+1;j<size;j++)
        {
            if(arr[j]<arr[min])
            {
                min=j;
            }
        }
        swap(&arr[min],&arr[i]);
    }
}
//display ascending array
void print(int n,int arr[],int size)
{
    printf("The ascending order: ");
        for(int i=0;i<size;i++)
        {
            printf("%d ",arr[i]);
        }
        printf("\n");
        printf("Enter a number(1-bubble sort, 2-insertion sort, 3-selection sort, 4-exit): ");
        scanf("%d",&n);
}
int main()
{
    //user input array
    int count=0,num,size;
    printf("Enter the array size: ");
    scanf("%d",&size);
    int arr[size];
    while(count<size)
    {
        printf("Enter no. %d: ",count+1);
        scanf("%d",&num);
        arr[count]=num;
        count++;
    }
    int n;
    printf("Enter a number(1-bubble sort, 2-insertion sort, 3-selection sort, 4-exit): ");
    scanf("%d",&n);
    //sorting condition
    switch (n)
    {
        case 1:
        bubblesort(arr,size);
        print(n,arr,size);
        case 2:
        insertionsort(arr,size);
        print(n,arr,size);
        case 3:
        selectionsort(arr,size);
        print(n,arr,size);
        case 4:
        exit(0);
        default:
        printf("Invalid number");
    }
}