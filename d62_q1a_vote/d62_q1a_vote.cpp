#include <iostream>
#include <map>

void debuging(std::map<std::string, int> map);

int main(void)
{
    int n, k;
    std::string name;
    std::map<std::string, int> candidate;
    std::cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        std::cin >> name;

        if (candidate.find(name) == candidate.end())
        {
            candidate[name] = 0;
        }

        candidate[name] += 1;
    }
    debuging(candidate);
    // Find max vote
    int max;
    int min; 
    bool firstMax = false;
    for (auto &x: candidate)
    {
        if (!firstMax)
        {
            max = x.second;
            min = x.second;
            firstMax = true;
            continue;
        }
        if (x.second > max)
        {
            min = max;
            max = x.second;
        }
    }
    std::cout << min << '\n';
}   

void debuging(std::map<std::string, int> map)
{
    for (auto &x : map)
    {
        std::cout << x.first << ' ' << x.second << '\n';
    }
}