/*
 * Name :- Mahmoud Mohamed Said Ahmed
 *
 * ID :- 20180261
 *
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void Sort(vector<int>*vec){

    int temp;
    for (int i = 0; i < vec->size(); ++i) {
        for (int j = i+1; j < vec->size(); ++j) {

            if (vec->at(i)>vec->at(j)){

                temp=vec->at(i);
                vec->at(i)=vec->at(j);
                vec->at(j)=temp;

            }

        }
    }

}

int main() {

    string choice ("");
    while (true){

        cout<<"1 _ Problem 1 \n2 _ Problem 2 \n3 _ Exit \n";
        cin>>choice;cin.ignore();

        if (choice=="1"){

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
            Sort(&vec);
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
            cout<<fin<<endl<<endl;

        } else if (choice=="2"){

            vector<int>vec;
            int size ,total, total_temp,input;
            cin>>size;
            cin>>total;
            for (int i = 0; i < size; ++i) {
                cin>>input;
                vec.push_back(input);
            }
            Sort(&vec);

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

            cout<<endl<<endl;

        } else if (choice=="3"){

            cout<<"Good Bye ^_^\n";
            return 0;

        } else cout<<"Wrong Choice \n";

    }


    return 0;
}
