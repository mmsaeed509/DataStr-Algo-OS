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

int main(){

    int studNum , deskNum, input;
    int minDist= INT16_MAX;
    int maxDist = -1;
    int maxIndex=-1;
    int fin;
    vector<int >vec ;
    vector<int> vec2;
    cin>>studNum>>deskNum;
    for (int i = 0; i <deskNum ; ++i) {
        cin>>input;
        vec.push_back(input);
    }
    sort(vec.begin(),vec.end());
    vec2.push_back(vec.at(0));
    vec.at(0)=-1;

    for (int i = 0; i <studNum-1 ; ++i) {
        for (int k = 0; k <vec.size() ; ++k) {
            if (vec.at(k)!=-1){
                for (int j = 0; j < vec2.size(); ++j) {

                    if (abs(vec2.at(j) - vec.at(k))<minDist)
                        minDist = abs(vec2.at(j) - vec.at(k));
                }
                if (minDist>maxDist){
                    maxDist = minDist;
                    maxIndex=k;

                }
                minDist= INT16_MAX;

            }
        }
        vec2.push_back(vec.at(maxIndex));
        vec.at(maxIndex)=-1;
        fin = maxDist;
        maxDist = -1;

    }
    cout<<fin;

    return 0;
}
