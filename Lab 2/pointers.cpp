#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int power(int* num,int* size){     //function to find power
    int* num2=(int*)malloc(sizeof(int));
    int* i=(int*)malloc(sizeof(int));
    *num2=1;
    for((*i)=0;(*i)<((*size));(*i)++){
            *(num2)*=(*num);
    }
    return *num2;
    free(num2);
    free(i);
}  
void palindrome(int* num)    //palindrome function
{
    int *temp=(int *) malloc (sizeof(int));
    int *rem=(int *) malloc (sizeof(int));
    int *num2=(int *) malloc (sizeof(int));

    *rem=0;
    *temp=*num;
    *num2=0;
    while(*temp!=0)
    {
        *rem=(*temp)%10;
        *num2=(*num2)*10+(*rem);
        *temp=(*temp)/10;
    }
    if(*num2==*num)
    {
        printf("It is an Palidrome.\n");
    }
    else
    {
        printf("It is not an Polidrome.\n");
    }
    free(temp);
    free(rem);
    free(num2);
}

void armstrong(int * num)   //armstrong number function
{
    int *temp=(int *) malloc(sizeof(int));
    int *rem=(int *)malloc (sizeof(int));
    int *num2=(int *)malloc(sizeof(int));
    int *count=(int *)malloc(sizeof(int));
    *temp=*num;
    *rem=0;
    *num2=0;
    *count=0;
    while(*temp!=0)
    {
        (*count)++;
        *temp=(*temp)/10;
    }
    *temp=*num;
    while(*temp!=0)
    {
        *rem=(*temp)%10;
        *num2=(*num2)+ power(rem,count);
        *temp=(*temp)/10;
    }
    if(*num2==*num)
    {
        printf("It is a armstrong number\n");
    }
    else
    {
        printf("It is not an armstrong number\n");
    }
    free(temp);
    free(rem);
    free(count);
    free(num2);
}
void perfect(int *num)   //perfect number function
{
    int *i=(int *)malloc(sizeof(int));
    int *sum=(int *)malloc(sizeof(int));
    *i=1;
    *sum=0;
    while(*i<*num)
    {
        if((*num)%(*i)==0)
        {
            *sum+=*i;
        }
        (*i)++;
    }
    if(*sum==*num)
    {
        printf("It is a perfect number\n");
    }
    else
    {
        printf("It is not a perfect number\n");
    }
    free(i);
    free(sum);
}
int main()
{
    int *choice=(int *)malloc(sizeof(int));
    int *num=(int *)malloc(sizeof(int));

    while(*choice!=4)
    {
        printf("1:Palindrome\n2:Armstrong number\n3:Perfect number\nEnter your choice: ");
        scanf("%d",choice);

        switch(*choice)
        {
            case 1:  //Palindrome
                printf("Enter the number: ");
                scanf("%d",num);
                if(*num<0)
                {
                    printf("Invalid number\n");
                }
                else
                {
                    palindrome(num);
                }
                break;
            case 2:  //armstrong number
                printf("Enter the number: ");
                scanf("%d",num);
                if(*num<0)
                {
                    printf("Invalid number\n");
                }
                else
                {
                    armstrong(num);
                }
                break;
            case 3:  //perfect number
                printf("Enter the number: ");
                scanf("%d",num);
                if(*num<0)
                {
                    printf("Invalid number\n");
                }
                else
                {
                    perfect(num);
                }
                break;
            case 4:  //exit program
                printf("Exiting program\n");
                break;
            default:
                printf("Invalid option\n");

        }
        
    }
    free(num);
    free(choice);
}