//Program on eliminating the players from the game upon the number given
#include<iostream>
using namespace std;

void solve();


int main()
{
    int cases;
    cout<<"Enter number of testcases: ";
    cin>>cases;
    for(int i=1;i<=cases;i++)
    {
        cout<<"\nEnter the details for testcase "<<i<<":-";
        solve();
    }
}

//Defining solve function

void solve()
{
    int k,q;
    cout<<"\nEnter k (length of sequence)= ";
    cin>>k;

    cout<<"Enter q (number of values)= ";
    cin>>q;

    int ks[100];
    cout<<"Enter the k sequence: ";
    for(int i=0;i<k;i++)
    {
        cin>>ks[i];
    }

    int qs[100];
    cout<<"Enter the q sequence: ";
    for(int i=0;i<q;i++)
    {
        cin>>qs[i];
    }

    cout<<"Winners: ";
    for(int i=0;i<q;i++)
    {
        int current=qs[i];
        bool changed;
        for(int i=0;i<k;i++)
        {
            do
            {
                //Eliminating participants
                
                changed=false;
                if(ks[i]<=current)
                {
                    current--;
                    changed=true;
                }
                else
                {
                    break;
                }
            }while(changed);
        }

        cout<<current<<" ";
    }
    cout<<"\n";

}
