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
    
    if (upperbound > v.size() - 1)
    {
        upperbound = v.size() - 1;
    }
    if (lowerbound < 0)
    {
        lowerbound = 0;
    }

    // deleting loop
    int j = 0;
    for (int i = upperbound; i >= lowerbound; i--)
    {
        v.erase(v.begin() + i);
    }
    
    
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

