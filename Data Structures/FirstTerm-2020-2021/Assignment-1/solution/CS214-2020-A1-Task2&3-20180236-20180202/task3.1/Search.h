//
// Created by moham on 10/27/2020.
//

#ifndef TASK3_CODE_SEARCH_H
#define TASK3_CODE_SEARCH_H
#include <algorithm>
#include <vector>
#include <fstream>
#include <chrono>
#include <list>



using namespace std::chrono;
using string = std::string;
template<class T>
class Search {
private:
    static  Search<T> search;
    std::vector<T> data ;
    std::list<T> list_data;
    Search()= default;

    int binarySearchNumberOfComp(T key, int elementNum);

    std::vector<int> generateRandInRange(int min,int max, int size=10);

    int linearSearchNumberOfComp(T key, int elementNum);



public:
    static Search<T>& getInstance();

    Search(const Search<T>& rhs)= delete;

     Search &operator=(const Search<T>&)= delete;

    bool loadData(std::ifstream &file);

    void sortData(std::ifstream &file);

    std::vector<T> getData();

    int binarySearch(T key);

    int linearSearch(T key);

    std::pair<long double ,long double> testPerformance( const int &wordsNumber,const string &algo,const string &performance,int X=0, int Y=0 );












};



#endif //TASK3_CODE_SEARCH_H
