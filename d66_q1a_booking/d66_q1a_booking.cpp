#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <set>

int main(void)
{
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    
    int n, m;
    std::map<std::string, std::vector<std::string>> flightSeat;
    std::set<std::string> flightSet;
    // {flight : [seat, available?]}

    std::cin >> n >> m;
    
    for (int i = 0 ; i < n ; i++)
    {
        std::string flight, seat;
        std::cin >> flight >> seat;
        flightSeat[flight].push_back(seat);
    }
    
    for (int i = 0; i < m; i++)
    {
        int k;
        bool searching = true;
        std::map<std::string, std::vector<int>> toRemove;
        
        std::cin >> k;
        
        for (int j = 0; j < k; j++)
        {
            std::string flight, seat;
            std::cin >> flight >> seat;
            // if the booking has been cancelled.
            if (!searching)
            {
                continue;
            }

            if (flightSeat.find(flight) != flightSeat.end())
            {
                auto it = std::find(flightSeat[flight].begin(), flightSeat[flight].end(), seat);
                if (it != flightSeat[flight].end())
                {   
                    toRemove[flight].push_back(it - flightSeat[flight].begin());
                }
                else
                {
                    searching = false;
                    continue;
                }
            }
            else
            {
                searching = false;
                continue;
            }
        }

        if (searching)
        {
            std::cout << "YES" << '\n';
            // More code to be write here
            for (auto x : toRemove)
            {
                for (int h = 0; h < toRemove[x.first].size(); h++)
                {
                    flightSeat[x.first][toRemove[x.first][h]] = "NIGGA";
                }
            }
        }
        else
        {
            std::cout << "NO" << '\n';
        }
    }

    std::cout << "CODE END :D" << '\n';
}
