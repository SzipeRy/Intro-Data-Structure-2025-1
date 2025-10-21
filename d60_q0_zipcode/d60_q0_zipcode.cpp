#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

class Letter
{
public:
    // is 10120 < 10330?
    std::string name; std::string address; std::string province; std::string district; int zip;
    bool operator< (const Letter& other) const 
    {
        //**Begin Insert**
        if (zip < other.zip)
        {
            return true;
        }
        else if (province < other.province)
        {
            return true;
        }
        else if (district < other.district)
        {
            return true;
        }
        else
        {
            return name < other.name;
        }
        //**End Insert**
    }
};

class ZipInfo
{
public:
    int zip;
    std::string province;
    std::string district;
};
void correctZipAndSortLetters(std::vector<ZipInfo> &zipinfo, std::vector<Letter> &letters) 
{
//**Begin Insert**

// There is a chance that different province and district could end up in same zipcode
// I guess only zipcode is wrong and province and district is correct
    std::map<std::pair<std::string, std::string>, int> zipinfo_map;
    for (int i = 0; i < zipinfo.size(); i++)
    {
        zipinfo_map[{zipinfo[i].province, zipinfo[i].district}] = zipinfo[i].zip;
    }

    for (int i = 0; i < letters.size(); i++)
    {
        auto it = zipinfo_map.find({letters[i].province, letters[i].district});
        if (letters[i].zip != it->second)
        {
            letters[i].zip = it->second;
        }
    }


    std::sort(letters.begin(), letters.end());
    
    return;
//**End Insert**
}

int main(void)
{
    int nzip;
    std::cin >> nzip;
    std::vector<ZipInfo> zipinfo;
    for (int i = 0; i < nzip; i++)
    {
        ZipInfo z;
        std::cin >> z.zip >> z.district >> z.province;
        zipinfo.push_back(z);
    }
    int n;
    std::cin >> n;
    std::vector<Letter> letters;
    for (int i = 0; i < n; i++)
    {
        Letter l;
        std::cin >> l.name >> l.address >> l.district >> l.province >> l.zip;
        letters.push_back(l);
    }
    correctZipAndSortLetters(zipinfo, letters);
    // std::cout << "-----------------------------" << '\n';
    for (auto & l : letters)
    {
        std::cout << l.name << " " << l.address << " " << l.district << " " << l.province << " " << l.zip << '\n';
    }
}