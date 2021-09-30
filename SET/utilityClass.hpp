#ifndef __UTILITY_CLASS_HPP_
#define __UTILITY_CLASS_HPP_

#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <deque>

#include <string>
#include <algorithm>
#include <iterator>
#include <functional>

#include <ctime>
#include <cstdlib>

////////////////////////////////
/// begin Decleration

void Randomize();
std::string srandom();

/// end  Decleration
////////////////////////////////

////////////////////////////////////////////////////////
/// Templates

template<class Con>
void cfill(Con& con, int size){
    // generate algorithm
    std::generate_n(std::inserter(con, con.begin()), size, srandom);
}

template<class Con>
void cdisplay(Con& con){
    auto beg = con.begin();
    auto end = con.end();
    while(
        beg != end && 
        std::cout << *beg++ << " "
        );std::cout << "\n";
}

/////////////////////////////////////////////////////////
// Preds

template<class T>
class myLess{
private:
public:
    constexpr bool operator()(const T& r1, const T& r2) const{
        return r1 < r2;
    }
};

template<class T>
class myGreater{
private:
public:
    constexpr bool operator()(const T& r1, const T& r2) const{
        return r1 > r2;
    }
};

template<class T>
class myLessSize{
private:
public:
    constexpr bool operator()(const T& r1, const T& r2) const{
        return r1.size() < r2.size();
    }
};

template<class T>
class myGreaterSize{
private:
public:
    constexpr bool operator()(const T& r1, const T& r2) const{
        return r1.size() > r2.size();
    }
};

template<class T>
class myEqualSize{
private:
public:
    constexpr bool operator()(const T& r1, const T& r2) const{
        return r1.size() == r2.size();
    }
};


template<class T, class Con>
void myCopyIT(T beg, T end, Con& con){

    for (
        ; 
        beg != end; 
        con.insert(*beg++)
        );
}

template<class Con1, class Con2>
void myCopyCon(Con1& con1, Con2& con2){
    auto beg = con1.begin();

    for (
        ;
        beg != con1.end();
        con2.insert(*beg++)
        );
}

template<class T, class U>
T myFindCon(T beg, T end, U searchVar){
    while(*beg != searchVar && beg++ != end );
    return beg;
}   

template<class Gcon, class U>
typename Gcon::iterator  myFindCon(Gcon& con, U searchVar){
    auto beg = con.begin();
    while(
        *beg != searchVar 
        && beg++ != con.end());
    return beg;
}  
#endif