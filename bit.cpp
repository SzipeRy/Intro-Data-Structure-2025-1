#include <bits/stdc++.h>

using namespace std;
int main()
{
    vector<int> vec = {0,1,2,3,4,5};

    auto pos = vec.begin() + 2;
    pos = vec.begin() - 2;

    cout << *pos << '\n';
    return 0;
}