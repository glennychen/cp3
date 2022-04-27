#include <iostream>
#include <string>
#include <utility>
#include <thread>
#include <mutex> 
#include <vector>
#include <algorithm>

struct a{
    virtual int foo(int) {return 7;}
};

struct b: a{
    int foo(float){return 6;}
};

void declaration_of_foo_string(){
    std::string(foo); //the same as std::string foo
}

void no_lock_bug(){
    std::mutex mtx; 
    // std::unique_lock<std::mutex>(mtx); //sample problem as the above.
    //                                    //you declare mtx (again) shadowing your mtx above
    //                                    //cause double-declarating error
    
}

void most_vexign_parse(){
    //https://stackoverflow.com/questions/7007817/a-confusing-detail-about-the-most-vexing-parse
    //https://en.wikipedia.org/wiki/Most_vexing_parse
    //https://stackoverflow.com/questions/2308646/different-ways-of-constructing-an-object-in-c
    //https://stackoverflow.com/questions/38951362/most-vexing-parse
    //https://www.fluentcpp.com/2018/01/30/most-vexing-parse/
    //https://stackoverflow.com/questions/16189742/how-to-avoid-c-anonymous-objects
    
    std::vector<int> v{1,2,3};
    std::sort(v.begin(), v.end(), std::greater<int>{});      
    v={1,2,3};
    std::sort(v.begin(), v.end(), std::greater<int>());  
    std::cout << v[1];
}

void ostream_stuff(){
    //https://stackoverflow.com/questions/7179161/create-a-print-function-that-takes-an-ostream-as-an-argument-and-writes-to-that
    //https://stackoverflow.com/questions/9658720/ofstream-as-function-argument
}

void empty_container_stuff(){
    //https://stackoverflow.com/questions/10097772/c-stl-container-clear-swap
    //vector<myStruct>().swap( vecs );
}  

void initialize_stuff(){
    
}

int main(int, char**) {
    int c = b().foo(0);

    // std::string s1="hi", s2="bye";
    // swap(s1,s2);

    // int a=3, b=7;
    // swap(a,b);
    most_vexign_parse();
    return 0;
}
