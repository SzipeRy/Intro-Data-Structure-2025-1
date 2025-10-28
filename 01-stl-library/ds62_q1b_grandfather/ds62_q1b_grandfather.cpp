#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>

void debugMap(std::map<std::string, std::string> pedigree);

int main(void)
{
    // find where son located
    // if son has been located
    // find where father located

    std::ios_base::sync_with_stdio(false); std::cin.tie(0);

    int n, m;  // n = line of family pedigree, m = line of a and b
    std::string f, s; // father and son
    std::string a, b; // is a and b related?
    std::map<std::string, std::string> pedigree; // <this guy is son, this guy is father>
    std::string fatherA, fatherB, grandfatherA, grandfatherB;

    std::cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        std::cin >> f >> s;
        pedigree[s] = f;
        if (pedigree.find(f) == pedigree.end())
        {
            pedigree[f] = "NONE";
        }
    }
    //debugMap(pedigree);
    
    for (int i = 0; i < m; i++)
    {
        std::cin >> a >> b;
        if (a == b)
        {
            std::cout << "NO" << '\n';
            continue;
        }
        
        auto itA = pedigree.find(a);
        auto itB = pedigree.find(b);
        if (itA == pedigree.end() || itB == pedigree.end())
        {
            std::cout << "NO" << '\n';
            continue;
        }
        
        else if (pedigree[a] == "NONE" || pedigree[b] == "NONE")
        {
            std::cout << "NO" << '\n';
            continue;
        }
        
        else if (pedigree[pedigree[a]] == pedigree[pedigree[b]])
        {
            std::cout << "YES" << '\n';
            continue;
        }
        else
        {
            std::cout << "NO" << '\n';
        }
    }
    //debugMap(pedigree);
}

void debugMap(std::map<std::string, std::string> pedigree)
{
    for (auto &x : pedigree)
    {
        std::cout << x.first << ' ' << '[';

        for (auto y : x.second)
        {
            std::cout << y << ' ';
        }
        std::cout << ']';
    }
}