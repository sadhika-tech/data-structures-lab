//Program on difference between the strongest and each player's strength
#include<iostream>
using namespace std;

void solve();

int main()
{
    int cases;
    cout<<"Enter the number of cases: ";
    cin>>cases;

    for(int i=1;i<=cases;i++)
    {
        cout<<"\nEnter the detail for testcase "<<i<<":-";
        solve();
        cout<<"\n";
    }

}

//Defining solve function

void solve()
{
    int n;
    cout<<"\nEnter n (length of the array): ";
    cin>>n;

    cout<<"Enter the strengths: ";
    int s[n];
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
    }

    int max1=-1;
    int max2=-1;

    for(int i=0; i<n;i++)
    {
        if(s[i]>max1)
        {
            max2=max1;
            max1=s[i];
        }
        else if(s[i]>max2)
        {
            max2=s[i];
        }
    }

    //Calculating difference

    cout <<"Difference: ";
    for(int i=0;i<n;i++)
    {
        int max=(s[i]==max1?max2:max1);
        int diff=s[i]-max;

        cout<<diff<<" ";
    }

}