#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int cases,towers;
    printf("Enter the number of testcases:");
    scanf("%d",&cases);

    for(int i =1;i<=cases;i++)
    {
        printf("\nEnter the details of testcases %d:- \n",i);
        printf("Enter the number of towers:");
        scanf("%d",&towers);
        int arr[towers];

        for (int i=0;i<towers;i++)
        {
            printf("Enter the nunber of bricks in the tower %d: ",i+1);
            scanf("%d",&arr[i]);
        }
        sort(arr+1,arr+towers);
        for (int i =1;i<towers;i++)
        {
            if(arr[i]>arr[0])
            {
                if((arr[0]+arr[i])%2==0)
                {
                    arr[0]=(arr[i]+arr[0])/2;

                }
                else
                {
                    arr[0]=(arr[i]+arr[0])/2 +1;
                }

            }
        }

        printf("The number of brickes in the tower 1: %d\n",arr[0]);
    }
    return 0;

}