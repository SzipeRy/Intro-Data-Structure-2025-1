#include <algorithm>
#include <iostream>
#include <vector>

void checkChild(int p);

std::vector<int> node;
int n, target;

int main(void)
{
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    std::cin >> n >> target;

    if (target == 0)
    {
        std::cout << 0;
        return 0;
    }
    node.push_back(target);

    checkChild((2*target) + 1);
    checkChild((2*target) + 2);

    std::sort(node.begin(), node.end());

    // ========Output==========
    std::cout << n - node.size() << '\n';
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (i == node[j])
        {
            j++;
            continue;
        }
        std::cout << i << " ";
    }
}

void checkChild(int p)
{
    if (p >= n)
    {
        return;
    }
    node.push_back(p);
    checkChild((2*p) + 1);

    checkChild((2*p) + 2);
}