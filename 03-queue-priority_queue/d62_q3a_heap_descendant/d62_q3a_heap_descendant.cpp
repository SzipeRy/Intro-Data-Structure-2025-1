#include <algorithm>
#include <iostream>
#include <vector>

void checkChild(int p);

int count = 0;
int n, target;

std::vector<int> node;

int main(void)
{
    std::cin >> n >> target;

    node.push_back(target);
    count++;

    checkChild((target * 2) + 1);
    checkChild((target * 2) + 2);

    std::sort(node.begin(), node.end());

    // =========== Output =============
    std::cout << count << '\n';
    for (auto x : node)
    {
        std::cout << x << " ";
    }
}

void checkChild(int p)
{
    if (p >= n)
    {
        return;
    }

    count++;
    node.push_back(p);

    checkChild((p * 2) + 1);
    checkChild((p * 2) + 2);
}