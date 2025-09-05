#include <bits/stdc++.h>

// Initialize Vector
std::vector<int> v;


void reverse(void);
void sortAscending(void);
void sortDescending(void);
void doom(int i);
void push(int i);

int main(void)
{
    // get the Q input
    int q;
    std::cin >> q;

    for (int i = 0; i < q; i++)
    {
        // get the command q time
        std::string command;
        int index;
        std::cin >> command;
        

        // check reverse ("r")
        if (command == "r")
        {
            reverse();
        }

        // check sort ascending ("sa")
        if (command == "sa")
        {
            sortAscending();
        }

        // check sort descending ("sd")
        if (command == "sd")
        {
            sortDescending();
        }
        if (command == "d")
        {
            std::cin >> index;
            doom(index);
        }
        if (command == "pb")
        {
            std::cin >> index;
            push(index);
        }
    }
    

    // printing output
    for (int j = 0; j < size(v); j++)
    {
        std::cout << v[j] << " ";
    }
    return 0;
}

//------------------------------------------------------------------------------------

void reverse(void)
{
    std::reverse(v.begin(), v.end());
    // std::cout << "reverse completed" << '\n';
    return;
}

void sortAscending(void)
{
    std::sort(v.begin(), v.end());
    // std::cout << "Sort Ascending completed" << '\n';
    return;
}

void sortDescending(void)
{
    sortAscending();
    reverse();
    return;
}

void doom(int i)
{
    v.erase(v.begin() + i);
    return;
}

void push(int i)
{
    v.push_back(i);
    return;
}