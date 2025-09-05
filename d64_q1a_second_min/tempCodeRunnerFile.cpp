#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <list>

int get_second_min(std::stack<int> &s);

int main(void)
{
    std::ios_base::sync_with_stdio(false);std::cin.tie(0);
    int n;
    std::cin >> n;
    std::vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> v[i];
    }

    //repeat n - 1 times
    for (int last = 1; last < n; last += 1)
    {
        std::stack<int> s;
        //build s;
        bool distinct = false;
        for (int i = last; i >= 0; i--)
        {
            s.push(v[i]);
            if (v[i] != v[0])
            {
                distinct = true;
            }
        }
        std::cout << "--use v[" << last << "] to v[0] --" << '\n';
        if (distinct)
        {
            // call get_second_min if we have at least 2 distinct value
            int answer = get_second_min(s);

            //print result and s
            std::cout << "result is " << answer << '\n';
            std::cout << "size of s is " << s.size() << '\n' << "member of s are ";
            while(s.size() > 0)
            {
                std::cout << s.top() << " ";
                s.pop();
            }
            std::cout << '\n';
        }
        else
        {
            std::cout << "skip because s has only one value\n\n\n";
        }
    }
    return 0;
}

int get_second_min(std::stack<int> &s)
{
    std::stack<int> s2;
    std::vector<int> sorting;
    int secondMin;
    int size = s.size();

    for (int i = 0; i < size; i++)
    {
        int x = s.top();
        sorting.push_back(x);
        s2.push(x);
        s.pop();
    }
    std::sort(sorting.begin(), sorting.end());
    int min = sorting[0];
    auto x = std::upper_bound(sorting.begin(), sorting.end(), min);
    for (int i = 0; i < size; i++)
    {
        int x = s2.top();
        s.push(x);
        s2.pop();
    }
 
    return *x;
}