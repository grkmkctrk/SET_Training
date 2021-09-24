/*
    /EX1


#include "utilityClass.hpp"

using namespace std;

int main(){

    // set<int, greater<int>> iSet;
    // set<type, functionalOperand, allocator> iSet
    // greater is a class -> lambda statement

    set<string> sSet;

    Randomize();

    cfill(sSet, 10);
    // We con not add same values so if next value come randomly
    // is same with ones before, it won't added.
    cdisplay(sSet);

    cout << "size : " << sSet.size() << '\n';

    set<int> iSet;

    for (
        int i = 0; 
        i != 10; 
        iSet.insert(i*i-7),
        i++);

    cdisplay(iSet);
    cout << "size : " << iSet.size() << '\n';
    

    return 0;
}
    /EX1
*/

/*
    /EX2

    /EX2
*/

#include "utilityClass.hpp"

using namespace std;

int main(){

    Randomize();

    set<string> sSet1; // smaller to bigger independence from size of word 
    set<string, greater<string>> sSet2; // bigger to smaller independence from size of word
    set<string, less<string>, allocator<string>> sSet3; // smaller to bigger independence from size of word
 
    // sSet1 is equal to sSet3

    cfill(sSet1, 10);
    cfill(sSet2, 10);
    cfill(sSet3, 10);

    cdisplay(sSet1);
    cdisplay(sSet2);
    cdisplay(sSet3);

    return 0;
}