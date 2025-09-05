#include <iostream>
#include <vector>

using namespace std;

vector<string> punch(vector<string> &v, vector<string>::iterator it,int k)
{
    //write some code here
    //don’t forget to return something
    
    // checking upper and lower bound in case some memory location didn't existed
    int center = it - v.begin();
    int upperbound = center + k;
    int lowerbound = center - k;
    if (upperbound > v.size())
    {
        upperbound = v.size();
    }
    if (lowerbound < 0)
    {
        lowerbound = 0;
    }

    // deleting loop

    // let i for the upperbound, let j for the lowerbound
    //cout << "upperbound\n";
    for (int i = center ; i < upperbound; i++)
    {
        v.erase(v.begin() + center + 1);
        
    }    
    
    // cout << "\nlowerbound\n";
    
    for (int j = center; j > lowerbound; j--)
    {
        v.erase(v.begin() + center - 1);
    }
    v.erase(v.begin() + center - k);
    // cout << "\ncenter\n"; 
            
    //cout << endl;
    
    return v;
}
int main() 
{
    int n,j,k;
    cin >> n >> j >> k;

    vector<string> v(n);
    
    for (int i = 0; i < n; i++) 
    {
        cin >> v[i];
    }
    
    cout << "Result after punch" << endl;
    vector<string> result = punch(v, v.begin() + j, k);
    
    for (auto &x : result) 
    {
        cout << x << endl;
    }
}

