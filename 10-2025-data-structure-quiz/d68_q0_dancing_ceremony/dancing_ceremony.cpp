#include <algorithm>
#include <iostream>
#include <vector>

int main(void)
{
    std::vector<long long> leader;
    std::vector<long long> follower;
    std::vector<long long> result;

    int n;
    long long a, b; // a is leader, b is leader
    long long perfect = 0;
    std::cin >> n;

    // receive leader
    for (int i = 0 ; i < n; i++)
    {
        std::cin >> a;
        leader.push_back(a);
    }
    // receive follower
    for (int i = 0; i < n; i++)
    {
        std::cin >> b;
        follower.push_back(b);
    }

    // make vector from the - result
    for (int i = 0; i < n; i++)
    {
        result.push_back(leader[i] - follower[i]);
    }
    std::sort(result.begin(), result.end());

    std::vector<long long>::iterator firstPositiveInt;
    firstPositiveInt = std::upper_bound(result.begin(), result.end(), 0);

    long long t = 1;
    for (auto it = firstPositiveInt; it < result.end(); it++)
    {
        perfect += result.end() - firstPositiveInt;
        perfect -= t;
        t++;
    }
    std::vector<long long>::iterator find;
  
    for (auto it = result.begin(); it < firstPositiveInt; it++)
    {
        find = std::upper_bound(firstPositiveInt, result.end(), abs(*it));
        if (*find == 0)
        {
            continue;
        }
        else
        {
            for (auto y = find; y < result.end(); y++)
            perfect++;
        }
    }
    std::cout << perfect;
}