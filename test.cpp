#include <iostream>
#include <string>

int main(void)
{
    std::string x = "ABCDE";
    std::string y = "ABCDE";
    
    if (x == y)
    {
        std::cout << "TRUE" << '\n';
    }
    else
    {
        std::cout << "FALSE" << '\n';
    }
}