#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

// ASCII for a = 97, z = 122
int main(void)
{
    // std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int n, m, l;
    std::vector<int> decode;
    std::vector<std::string> encrypted;

    std::cin >> n >> m >> l;
    while (l--)
    {
        int k;
        std::cin >> k;
        k %= 26;
        decode.push_back(k);
    }

    for (int i = 0; i < n; i++)
    {
        std::string passEncrypted;
        std::cin >> passEncrypted;
        std::string clear = "";
        
        // Encrypted back the password
        for (int j = 0; j < passEncrypted.size(); j++)
        {
            char x = passEncrypted[j];
            x -= decode[j];
            if (x < 97)
            {
                x += 26;
            }
            std::cout << (int) x << '\n';
            clear += x;
        }
        std::cout << clear << '\n';
        // encrypted.push_back(clear);
    }

    for (int i = 0; i < m; i++)
    {
        std::string input;
        std::cin >> input;
        if (std::find(encrypted.begin(), encrypted.end(), input) != encrypted.end())
        {
            std::cout << "Match" << '\n';
        }
        else 
        {
            std::cout << "Unknown" << '\n';
        }
    }
    return 0;
}