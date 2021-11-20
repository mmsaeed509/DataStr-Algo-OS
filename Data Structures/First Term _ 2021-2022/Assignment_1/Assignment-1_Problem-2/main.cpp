/*
 * Name :- Mahmoud Mohamed Said Ahmed
 *
 * ID :- 20180261
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    vector<int>vec;
    int size ,total, total_temp,input;
    cin>>size;
    cin>>total;
    for (int i = 0; i < size; ++i) {
        cin>>input;
        vec.push_back(input);
    }
    sort(vec.begin(),vec.end());

    for (int i = 0; i <size ; ++i) {
        for (int j = 0; j < size; ++j) {

            if (vec.at(i)+vec.at(j)<6){
                total_temp= vec.at(i)+vec.at(j);
                for (int k = 0; k < size; ++k) {
                    if (total_temp+vec.at(k)==total){
                        cout<<vec.at(i)<<" "<<vec.at(j)<<" "<<vec.at(k)<<endl;
                        return  0 ;
                    }
                }

            }else{
                break;
            }
        }
    }

    return 0;
}
