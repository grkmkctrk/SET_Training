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
    /EX2
*/

/*
    /EX3


#include "utilityClass.hpp"

using namespace std;

int main(){

    Randomize();
    // / Smaller 
    // set<string, myLess<string>> sSet1;
    // set<string, less<string>> sSet2;

    // / Greater
    // set<string, myGreater<string>> sSet1;
    // set<string, greater<string>> sSet2;

    // / Sizes
    // set<string, myLessSize<string>> sSet1;
    // set<string, myGreaterSize<string>> sSet1;
    set<string, myEqualSize<string>> sSet1;


    cfill(sSet1, 100);
    // cfill(sSet2, 100);

    cdisplay(sSet1);
    // cdisplay(sSet2);

    return 0;
}
    /EX3
*/

/*
    /EX4

#include "utilityClass.hpp"

using namespace std;

int main(){

    set<string> sSet1; // default
    
    Randomize();

    cfill(sSet1, 10);
    cdisplay(sSet1);

    cout << sSet1.size() << endl; // unique elements number

    // if(sSet1.count("Gorkem"))
    //     cout << "There is Gorkem\n";
    // else
    //     cout << "There is no Gorkem\n";


    // sSet1.erase("Gorkem");
    // cout << "After erasing" << endl;
    // cdisplay(sSet1);

    auto pos = sSet1.find("Gorkem");
    cout << "found : " << *pos << endl;

    return 0;
}

    /EX4
*/


/*
    /EX5


#include "utilityClass.hpp"

using namespace std;

int main(){

    set<int> sSet1; // default
    
    Randomize();

    for (size_t i = 0; i < 10; i++)
    {
        sSet1.insert(i);
    }

    cdisplay(sSet1);

    // if(sSet1.count(3)) cout << "There is 3" << endl;
    // else cout << "There is no 3" << endl;

    // if(sSet1.count(3)) sSet1.erase(3);
    // else sSet1.insert(3);

    // cdisplay(sSet1);

    auto pos = sSet1.find(4);
    set<int>::iterator iter1 = sSet1.find(4);
    set<int>::const_iterator iter2 = sSet1.find(4);
    // set<int>::reverse_iterator iter3 = sSet1.find(4); // error


    cout << "auto : " << *pos << endl;
    cout << "iterator : " << *iter1 << endl;
    cout << "iterator : " << *iter2 << endl;
    // cout << "iterator : " << *iter3 << endl;

    
    return 0;
}
    /EX5
*/



/*
    /EX6




#include "utilityClass.hpp"

using namespace std;

int main(){

    set<string> sSet1;

    Randomize();

    if(sSet1.insert("gorkem").second)
        cout << "there is gorkem s" << endl;
    // if(sSet1.insert("gorkem").first)
    //     cout << "there is mehmet f" << endl;

    cout << *(sSet1.insert("alican").first) << endl;



    return 0;
}
    /EX6
*/


/*
    /EX7

    /EX7
*/



#include "utilityClass.hpp"

using namespace std;

int main(){

    set<string> sSet1;

    Randomize();

    // pair<set<string>::iterator, bool> result = sSet1.insert("gorkem");
    pair<set<string>::const_iterator, bool> result = sSet1.insert("gorkem");

    if(result.second){
        cout << "there is gorkem in here" << endl;
    }else{
        cout << "there is not gorkem in here" << endl;
    }

    cout << *result.first << '\n';

    return 0;
}