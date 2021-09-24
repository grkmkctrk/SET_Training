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


#endif