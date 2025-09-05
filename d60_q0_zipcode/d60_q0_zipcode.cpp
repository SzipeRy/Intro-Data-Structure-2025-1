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
    bool operator < (const Letter& other) const 
    {
        //**Begin Insert**
        if (zip != other.zip)
        {
            return zip < other.zip;
        }
        else
        {

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
    // Correcting Letter
    for (int i = 0; i < letters.size(); i++)
    {
        // tmp is for letters.zip
        int tmpZipLetter = letters[i].zip;
        std::string tmpDistrictLetter = letters[i].district;
        std::string tmpProvinceLetter = letters[i].province;
        std::vector<int>::iterator it;
        
        for (int j = 0; j < zipinfo.size(); j++)
        {
            int tmpZipInfo = zipinfo[j].zip;
            std::string tmpDistrictInfo = zipinfo[j].district;
            std::string tmpProvinceInfo = zipinfo[j].province;
            if (tmpDistrictInfo == tmpDistrictLetter && tmpProvinceInfo == tmpProvinceLetter)
            {
                if (tmpZipInfo == tmpZipLetter)
                {
                    break;
                }
                else
                {
                    letters[i].zip = tmpZipInfo;
                    break;
                }
            }
        }
    }
    // Sorting Letter
    // MUST USE SAME VECTOR (letters)



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
    for (auto & l : letters)
    {
        std::cout << l.name << " " << l.address << " " << l.district << " " << l.province << " " << l.zip << '\n';
    }
}