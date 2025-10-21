#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>

using namespace std;



class Comp {
    public:
    bool operator() (vector<int> &left, vector<int> &right)
    {
        cout << *left << " " << *right << endl;
        if (left.size() > right.size()) return true;
        return left > right;
    }
};

int main(void)
{
    priority_queue<vector<int>, vector<vector<int>>, Comp> pq;
    pq.push({1,2,3,5});
    pq.push({1,2,3,4});
    pq.push({1,2,3});
    pq.push({1,2,3,4,5});
    pq.push({2,2,3,4,5});
    pq.push({1,9,3,4,5});
    pq.pop();
    auto tmp = pq.top();
    for(auto &x : tmp) cout << x << " ";
}