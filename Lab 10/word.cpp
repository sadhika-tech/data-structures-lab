//Program on calculating score of three player word game

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

void solve() 
{
    int t;
    cout<<"Enter the number of testcases: ";
    cin>>t;
    
    while (t--) 
    {
        int n;
        cout<<"Enter no. of words: ";
        cin >> n;
        
        vector<vector<string>> words(3, vector<string>(n));
        unordered_map<string, int> word_counts;
        
        for (int i = 0; i < 3; ++i) 
        {
            for (int j = 0; j < n; ++j) 
            {
                cin >> words[i][j];
                word_counts[words[i][j]]++;
            }
        }
        
        vector<int> scores(3, 0);
    
        for (int i = 0; i < 3; ++i) 
        {
            for (const string& word : words[i]) 
            {
                int count = word_counts[word];
                if (count == 1) 
                {
                    scores[i] += 3;
                } else if (count == 2) 
                {
                    scores[i] += 1;
                }
                
            }
        }
        
        cout<<"Player 1: "<<scores[0]<<"\n";
        cout<<"Player 2:"<< scores[1] << "\n"; 
        cout<< "Player 3:"<<scores[2] << "\n";
    }
}

int main() 
{
    solve();
    return 0;
}