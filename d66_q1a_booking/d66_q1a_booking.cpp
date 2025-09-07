#include <iostream>
#include <map>
#include <vector>

int main(void)
{
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);

    int n, m;
    std::map<std::string, std::vector<std::string>> flightSeat;
    

    std::cin >> n >> m;

    for (int i = 0 ; i < n ; i++)
    {
        std::string flight, seat;
        std::cin >> flight >> seat;
        flightSeat[flight].push_back(seat);
    }

    for (auto x : flightSeat)
    {
        for (int i = 0; i < x.second.size(); i++)
        {
            std::cout << x.first << ' ' << x.second[i] << '\n';
    
        }

    }
}