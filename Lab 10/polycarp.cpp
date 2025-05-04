//Program to eliminate to make unique sequence
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int main() 
{
    int t;
    cout<<"Enter no. of testcases: ";
    cin >> t;

    while (t--) 
    {
        int n;
        cout<<"Enter the length of sequence: " ;
        cin >> n;
        vector<int> a(n);

        for (int i = 0; i < n; ++i) 
        {
            cin >> a[i];
        }

        unordered_set<int> seen;
        int count = 0;

        for (int i = n - 1; i >= 0; --i) 
        {
            if (seen.count(a[i])) 
            {
                break;
            }
            seen.insert(a[i]);
            ++count;
        }

        cout <<"No. of removals: "<< n - count <<"\n";
    }

    return 0;
}
