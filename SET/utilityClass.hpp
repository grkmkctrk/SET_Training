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

template<class T>
int myDistanceIt(T first, T last){
    int dist = 0;
    for (
        ; 
        *first != *last; 
        first++, dist++);
    return dist;
}

template<class Con, class U>
int myDistanceCon(Con& con, U str){
    return myDistanceIt(
        con.lower_bound(str), 
        con.upper_bound(str));
}

template<class input1, class input2, class resultCon>
void mySetIntersectionIT(
    input1 beg1, input1 end1, 
    input2 beg2, input2 end2, 
    resultCon& out){

        while(beg1 != end1 && beg2 != end2){
            if(*beg1 < *beg2){
                beg1++;
            }else if(*beg2 < *beg1){
                ++beg2;
            }else{
                out.push_back(*beg1);
                ++beg1;++beg2;
            }
        }

        /* ** to understand this, run code below ** 
      
            string ss1 = "Ahmetcan", ss2 = "Berathan";
            cout << (ss1 < ss2) << endl;
            cout << (ss2 < ss1) << endl;
      
        *******************************************/
}

template<class gConI1, class gConI2, class gConO>
void mySetIntersectionCon(gConI1& conI1, gConI2& conI2, gConO& conO){

    auto first1 = conI1.begin();
    auto first2 = conI2.begin();

    // mySetIntersectionIT(first1, last1, first2, last2, conO);

    while(first1 != conI1.end() && first2 != conI2.end()){
        std::cout << *first1 << std::endl;
        if(*first1 < *first2) first1++;
        else if(*first1 > *first2) first2++;
        else{
            conO.push_back(*first1);
            first1++;first2++;
        }
    }

}

template<class input1, class input2, class resultCon>
void mySetUnionIT(
    input1 beg1, input1 end1, 
    input2 beg2, input2 end2, 
    resultCon& out){

        while(beg1 != end1 && beg2 != end2){
            if(*beg1 < *beg2) out.push_back(*beg1++);
            else if(*beg2 < *beg1) out.push_back(*beg2++);
            else{
                out.push_back(*beg1);
                ++beg1;++beg2;
            }
        }

    }

template<class gConI1, class gConI2, class gConO>
void mySetUnionCon(gConI1& conI1, gConI2& conI2, gConO& conO){

    auto beg1 = conI1.begin();
    auto beg2 = conI2.begin();

    // mySetUnionIT(first1, last1, first2, last2, conO);

    while(beg1 != conI1.end() && beg2 != conI2.end()){
        if(*beg1 < *beg2) conO.push_back(*beg1++);
        else if(*beg2 < *beg1) conO.push_back(*beg2++);
        else{
            conO.push_back(*beg1);
            ++beg1;++beg2;
        }
    }
}

#endif