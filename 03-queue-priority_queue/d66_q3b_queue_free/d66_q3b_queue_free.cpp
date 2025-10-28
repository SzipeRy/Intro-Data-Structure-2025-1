#include <iostream>

#define ll unsigned long long

int main(void)
{
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    ll n, a, k;
    ll mSize = 0, mCap = 1;
    std::cin >> n;

    while(n--)
    {
        std::cin >> a >> k;
        
        // push into queue
        if (a == 0)
        {
            mSize += k;
            while (mSize > mCap)
            {
                mCap *= 2;
            }
        }

        // pop from queue
        else if (a == 1)
        {
            if (mSize - k >= 0)
            {
                mSize -= k;
            }
            else
            {
                mSize = 0;
            }
        }
    }
    std::cout << mCap - mSize << '\n';
}