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
        std::cin >> k;
        std::map<std::string, std::vector<int>> toRemove;
        for (int j = 0; j < k; j++)
        {
            std::string flight, seat;
            std::cin >> flight >> seat;
            flightSet.insert(flight);

            if (flightSeat.find(flight) != flightSeat.end())
            {
                auto tmpFlightSeat = flightSeat[flight];
                auto it = std::find(tmpFlightSeat.begin(), tmpFlightSeat.end(), seat);
                if (it != tmpFlightSeat.end())
                {
                    int position = it - tmpFlightSeat.begin();
                    toRemove[flight].push_back(position);
                }
                else
                {
                    std::cout << "NO" << '\n';
                    std::map<std::string, std::vector<int>> toRemove;
                    break;
                }
            }
            else
            {
                std::cout << "NO" << '\n';
                std::map<std::string, std::vector<int>> toRemove;
                break;
            }
            if (j == k-1)
            {
                for (auto x : flightSet)
                {
                    for (int g = 0; g < toRemove[flight].size(); g++)
                    {
                        flightSeat[x][g] = "GARBAGE";
                    }
                }
                std::cout << "YES" << '\n';
                std::map<std::string, std::vector<int>> toRemove;
            }
            
        }
    }
}
