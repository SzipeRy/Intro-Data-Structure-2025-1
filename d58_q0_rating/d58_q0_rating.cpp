#include <iomanip>
#include <iostream>
#include <map>

int main(void)
{
    std::cout << std::fixed << std::setprecision(2);
    // receive input of n
    int n, score;
    std::string course, prof;
    std::map<std::string, int> courseScore;
    std::map<std::string, int> profScore;
    std::map<std::string, int> count;

    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        std::cin >> course;
        if (courseScore.find(course) == courseScore.end())
        {
            courseScore.insert({course, 0});
            count.insert({course, 0});
        }
        std::cin >> prof;
        if (profScore.find(prof) == profScore.end())
        {
            profScore.insert({prof, 0});
            count.insert({prof, 0});
        }
        std::cin >> score;
        courseScore.at(course) += score;
        profScore.at(prof) += score;
        count.at(course)++;
        count.at(prof)++;
    }

    // change course score
    for (auto x: courseScore)
    {
        std::cout << x.first << ' ' << (x.second + 0.0)/count[x.first] << '\n';
    }
    for (auto x: profScore)
    {
        std::cout << x.first << ' ' << (x.second + 0.0)/count[x.first] << '\n';
    }
}