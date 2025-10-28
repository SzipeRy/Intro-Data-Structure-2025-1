#include <iostream>

using namespace std;

void convertToString(int time);

const int MAXMINUTE = 60;
const int MAXHOUR = 24;

int main(void)
{
    string h,m,x;
    cin >> h >> m;
    cin >> x;
    int p = stoi(x);
    // turn string into int
    int hour = stoi(h);
    int min = stoi(m);
    
    int addHour = p / 60;
    int addMin = p % 60;
    
    hour += addHour;
    min += addMin;

    if (min >= MAXMINUTE)
    {
        int n = min/MAXMINUTE;
        min -= n*MAXMINUTE;
        hour += n;
    }
    if (hour >= MAXHOUR)
    {
        hour -= MAXHOUR;
    }

    convertToString(hour);
    cout << ' ';
    convertToString(min);
}

void convertToString(int time)
{
    if (time < 10)
    {
        cout << '0';
        cout << to_string(time);
    }
    else
    {
        cout << to_string(time);
    }
}