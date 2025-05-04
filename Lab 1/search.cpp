#include<stdio.h>
#include<stdlib.h>
#include"sorting.h" //sorting header file
//binary search function
int binarysearch(int arr[],int left,int right,int key)
{
    while(left<=right)
    {
        int mid=left+(right-left)/2;
        if(arr[mid]==key)
        {
            return mid;
        }
        else if(arr[mid]<key)
        {
            left=mid+1;
        }
        else
        {
            right=mid-1;
        }
    }
    return -1;
}
//linear search function
int linearsearch(int arr[],int key,int size)
{
    int found=0;
    for(int i=0;i<size;i++)
    {
        if(arr[i]==key)
        {
            return i;
            found=1;
        }
    }
    return -1;
}

int main()
{
    int key,size,count=0,num,n;
    printf("Enter the array size: ");
    scanf("%d",&size);
    int arr[size];
    //input array
    while(count<size)
    {
        printf("Enter no. %d: ",count+1);
        scanf("%d",&num);
        arr[count]=num;
        count++;
    }

    //printing the unsorted array
    printf("The unsorted array: ");
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    //sorting condition
    while(1)
    {
        printf("Enter a number(1-linear search, 2-binary search, 3-exit): ");
        scanf("%d",&n);
        switch (n)
        {
            case 1:
            {
                printf("Enter the integer to search: ");
                scanf("%d",&key);//key required to search
                // Linear search
                int linearIndex = linearsearch(arr, key, size);
                if (linearIndex != -1) 
                {
                    printf("Linear search: %d found at index %d\n", key, linearIndex);
                } 
                else 
                {
                    printf("Linear search: %d not found\n", key);
                }
                break;
            }
            case 2:
            {
                printf("Enter the key to search: ");
                scanf("%d",&key);//key required to search
                //sorting the array
                bubblesort(arr,size);
                printf("The ascending order: ");
                for(int i=0;i<size;i++)
                {
                    printf("%d ",arr[i]);
                }
                printf("\n");
            
                // Binary search
                int binaryIndex = binarysearch(arr, 0, size-1, key);
                if (binaryIndex != -1) 
                {
                    printf("Binary search: %d found at index %d\n", key, binaryIndex);
                } 
                else 
                {
                    printf("Binary search: %d not found\n", key);
                }
            
                break;
            }
            case 3:
            {
                exit(0);
            }
            default:
            {
                printf("Invalid number");
            }
        }
    }
   return 0; 
}
