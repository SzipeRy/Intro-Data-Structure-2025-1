#include <algorithm>
#include <iostream>
#include <vector>

int main(void)
{
    int floor, g, room, gp;
    std::vector<int> roomAvailable;
    std::vector<int> group;

    std::cin >> floor >> g;

    for (int i = 0; i < floor; i++)
    {
        std::cin >> room;
        roomAvailable.push_back(room);
    }
    
    for (int i = 0; i < g; i++)
    {
        std::cin >> gp;
        group.push_back(gp);
    }
    std::cout << "Input Accepted" << '\n';

    for (auto itGroup = group.begin(); itGroup < group.end(); itGroup++)
    {
        for (auto itRoom = roomAvailable.end() - 1; itRoom >= roomAvailable.begin(); itRoom--)
        {
            if (*itGroup > *itRoom)
            {
                std::cout << -1 << '\n';
                break;
            }
        }
    }
}