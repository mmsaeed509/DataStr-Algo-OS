//
// Created by moham on 10/26/2020.
//

#include "BigDecimalInt.h"


BigDecimalInt::BigDecimalInt(string decstr) {
    vec.push_back(0);
    int converter, i;;
    if (decstr.at(0) == '-')
        i = 1;
    else
        i = 0;
    for (i; i < decstr.size(); i++)
    {
        if (decstr.at(i) > 58 || decstr.at(i) < 48)
        {
            cerr << "wrong input (integers only) \n";
            break;
        }
        converter = (int)decstr.at(i) - 48;//to change all charcters in string to int
        vec.push_back(converter);

    }

}

BigDecimalInt::BigDecimalInt(int decint) {
    int converter;
    vec.push_back(0);
    string word = NumberToString(decint);//change paramter of constructor from int to string
    for (int i = 0; i < word.size(); i++)//do all steps in last constructor
    {
        converter = (int)word.at(i) - 48;
        vec.push_back(converter);

    }
}


vector<int> BigDecimalInt::add(vector<int> one, vector<int> two){
if (one.size() > two.size())
{
int b = one.size() - two.size();
for (int i = 0; i < b; i++)
{
two.insert(two.begin() + i, 0);
}
}
else if (one.size() < two.size())
{
int b = two.size() - one.size();
for (int i = 0; i < b; i++)
{
one.insert(one.begin() + i, 0);
}
}
vector<int>three;
for (int i = one.size() - 1; i >= 0; i--)
{
if (one.at(i) + two.at(i) >= 10)
{
one.at(i - 1)++;
three.push_back(one.at(i) + two.at(i) - 10);
}
else
three.push_back(one.at(i) + two.at(i));
}

reverse(three.begin(), three.end());
return three;

}

vector<int> BigDecimalInt::subtract(vector<int> one, vector<int> two) {
    if (one.size() > two.size())
    {
        int b = one.size() - two.size();
        for (int i = 0; i < b; i++)
        {
            two.insert(two.begin() + i, 0);
        }
    }
    else if (one.size() < two.size())
    {
        int b = two.size() - one.size();
        for (int i = 0; i < b; i++)
        {
            one.insert(one.begin() + i, 0);
        }
    }
    vector<int>three;
    for (int i = one.size() - 1; i >= 0; i--)
    {    if(i==1)
            three.push_back(one.at(1) - two.at(1));
        else if (one.at(i) < two.at(i))
        {
            one.at(i) = one.at(i) + 10;
            one.at(i - 1)--;
            three.push_back(one.at(i) - two.at(i));
        }
        else
            three.push_back(one.at(i) - two.at(i));
    }

    reverse(three.begin(), three.end());
    return three;

}

string BigDecimalInt::NumberToString(int Number) {
    ostringstream ss;
    ss << Number;
    return ss.str();
}


BigDecimalInt BigDecimalInt::operator+(const BigDecimalInt &obj2) {
    BigDecimalInt obj3;
    obj3.vec = add(this->vec, obj2.vec);
    return obj3;

}

BigDecimalInt BigDecimalInt::operator-(const BigDecimalInt &obj2)  {
    BigDecimalInt obj3;
    obj3.vec = subtract(this->vec, obj2.vec);
    return obj3;

}

ostream& operator<<(ostream& output, BigDecimalInt& obj)
{
    for (int i : obj.vec)
    {
        output << i;
    }
    return output;
}

BigDecimalInt &BigDecimalInt::operator=(const BigDecimalInt &obj) {
//    for(const auto &i: obj.vec ){
//        vec.push_back(i);

vec = obj.vec;
}



