#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <utility>

// map key is position
// value is the vector with pair
// pair.first is version;
// pair.second is val;


int main(void)
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(NULL);
    std::map<int, std::vector<std::pair<int,int>>> database;
    int n;
    char type;
    int version = 0;

    std::cin >> n;

    for (int i = 0 ; i < n ; i++)
    {
        std::cin >> type;
        if (type == 'U')
        {
            version++;

            int pos, val;
            std::cin >> pos >> val;

            std::pair<int, int> toAdd = {version, val};
            
            database[pos].push_back(toAdd);
            // for (auto x : database[pos])
            // {
            //     // std::cout << x.first << ' ' << x.second << '\n';
            // }
        }
        else if (type == 'A')
        {
            int pos, ver;
            std::cin >> pos >> ver;

            if (ver > version)
            {
                std::cout << -1 << '\n';
                continue;
            }
            if (database.find(pos) == database.end())
            {
                std::cout << -1 << '\n';
                continue;
            }
            auto check = database[pos];

            auto it = std::lower_bound(check.begin(), check.end(), std::make_pair(ver, 0));
            if (it->first != ver)
            {
                if (it == check.begin())
                {
                    std::cout << -1 << '\n';
                    continue;
                }
                it--;
                std::cout << it->second << '\n';
                continue;
            }
            else
            {
                std::cout << it->second << '\n';
                continue;
            }

        }  
    }
}

// U 4 42
// U 2 80
// U 4 99
// A 4 2
// A 4 3
// U 6 15
// A 1 4
// A 2 4

// U 1 40
// U 1 80
// U 2 50
// U 3 60
// U 1 10
// A 1 3 -> 80