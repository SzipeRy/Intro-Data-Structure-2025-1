#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <set>

//case 1 : before first publish year

//case 2 : same year but before first publish month

//case 3 : on hiatus year / month
    // if the year is match but month doesn't match
        // find the latest month in the same year
    // else if the year is not match
        // look back at last year and find the last month in that year

//case 4 : on the publish year / month

int main(void)
{
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int n, m;
    int year, month;
    int minYear, minMonth;
    std::map<int, std::set<int>> publish;
    std::cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        std::cin >> year >> month;
        publish[year].insert(month);
    }
    minYear = publish.begin()->first;
    minMonth = *(publish[minYear]).begin();
    // std::cout << minYear << ' ' << minMonth << '\n';

    // for (auto x : publish)
    // {
    //     std::cout << '[' << x.first << " : ";
    //     for (auto y : x.second)
    //     {
    //         std::cout << y << ' ';
    //     }
    //     std::cout << ']' << '\n';
    // }
    
    for (int i = 0; i < m; i++)
    {
        std::cin >> year >> month;
        // case 1
        if (year < minYear)
        {
            std::cout << -1 << ' ' << -1 << ' ';
            continue;
        }
        // case 2
        else if (year == minYear && month < minMonth)
        {
            std::cout << -1 << ' ' << -1 << ' ';
            continue;
        }

        auto itYear = publish.lower_bound(year);
        // std::cout << itYear->first << '\n';
        // lower_bound return .end()
        if (itYear == publish.end())
        {
            itYear--;
            std::cout << itYear->first << ' ' << *itYear->second.rbegin() << ' ';
            continue;
        }
        // lower_bound found the same input year
        if (itYear->first == year)
        {
            //case 4
            if (itYear->second.find(month) != itYear->second.end())
            {
                std::cout << 0 << ' ' << 0 << ' ';
                continue;
            }
            else 
            {
                auto itMonth = itYear->second.lower_bound(month);
                if (itMonth == itYear->second.begin())
                {
                    itYear--;
                    std::cout << itYear->first << ' ' << *itYear->second.rbegin() << ' ';
                }
                else
                {
                    itMonth--;
                    std::cout << itYear->first << ' ' << *itMonth << ' ';
                }
            }
        }
        else if(itYear->first > year)
        {
            itYear--;
            auto itMonth = itYear->second.rbegin();

            std::cout << itYear->first << ' ' << *itMonth << ' ';
        }


    }
}
