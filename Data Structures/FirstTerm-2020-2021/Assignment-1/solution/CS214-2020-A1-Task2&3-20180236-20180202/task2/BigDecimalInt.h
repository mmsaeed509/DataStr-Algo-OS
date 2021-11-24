
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>
#include <algorithm>


using namespace std;

class BigDecimalInt
{
private:
    vector<int>vec;
    vector <int> add(vector<int>one, vector<int>two);
    vector <int> subtract(vector<int>one, vector<int>two);
    string NumberToString(int Number);


public:


    BigDecimalInt()=default;
    BigDecimalInt(std::string decstr);
    BigDecimalInt(int decint);
    BigDecimalInt operator+(const BigDecimalInt& obj2);
    BigDecimalInt operator-(const BigDecimalInt& obj2);
    BigDecimalInt& operator=(const BigDecimalInt &obj);


    friend std::ostream& operator<<(std::ostream& output, BigDecimalInt& obj);
};



