#include <iostream>
#include <map>
#include <unordered_map>
#include <set>
#include <string>
#include <sstream>      // std::stringstream

/*
void print_map(std::map<int,int>&m){
    for(std::map<int,int>::iterator it = m.behin();it != m.end(); it++){
        std::cout << "Key = " << (*it).first << "value = " << it->second << std::endl;
    }
    std::cout << std::endl;
}

map.size();
map.empty();
map.swap(map2);

m.insert(std::make_pair(10,string("hello")));


*/


void display(const std::map<std::string, std::set<int>> &m) {
    std::cout << "[ ";
    for (const auto &elem: m) {
        std::cout << elem.first << ": [ " ;
            for (const auto &set_elem : elem.second)
                 std::cout << set_elem <<  " ";
            std::cout << "] " ;
    }
    std::cout << "]  " << std::endl;
}

template <typename T1, typename T2>
void display(const std::map<T1, T2> &l) {
    std::cout << "[ ";
    for (const auto &elem: l) { // auto here replace the pair
        std::cout << elem.first << ":" << elem.second << " ";
    }
    std::cout << "]  " << std::endl;
}

void test1() {
    // Maps:key and value pairs
    std::cout << "\nTest1 =========================" << std::endl;
    std::map<std::string, int> m {
        {"Larry", 3},
        {"Moe", 1},
        {"Curly", 2}
    };
    display(m);      
    
    m.insert( std::pair<std::string, int>("Anna", 10));
    display(m);
    
    m.insert(std::make_pair("Joe", 5));//same as line 36, simple version
    display(m);
    
    m["Frank"] = 18;
    display(m);
    
    m["Frank"] += 10;               
    display(m);
    
    m.erase("Frank");
    display(m);
    
    std::cout << "Count for Joe: " << m.count("Joe") << std::endl;
    std::cout << "Count for Frank: " << m.count("Frank") << std::endl;
    
    auto it = m.find("Larry");
    if (it != m.end())
        std::cout << "Found: " << it->first << " : " << it->second << std::endl;    
        
    m.clear();
    
    display(m);

}

void test2() {
    std::cout << "\nTest2 =========================" << std::endl;
    
    std::map<std::string, std::set<int>> grades  {
        {"Larry", {100, 90} },
        {"Moe",  {94} },
        {"Curly", {80, 90, 100} }
    };
    
    display(grades);
    
    grades["Larry"].insert(95);                 // insert 95 into the set of grades for "Larry"
    
    display(grades);
    
    auto it = grades.find("Moe");
    if (it != grades.end())                         // found "Moe"
    {
            it->second.insert(1000);  // insert 1000 into Moe's set of grades
    }                                  // it->first is the key, it->second is the value (set)
    display(grades);
}




int main() {
    //test1();
    //test2();
    // unordered map is faster
    /*
    std::unordered_map<std::string,double> um;

    um.insert(std::make_pair("e",2.718));
    um["PI"]=3.14;

    std::string key = "PI";

    if(um.find(key)==um.end()){ // find() return a pointer
        std::cout << key << "not found" << std::endl; //if no else, it will cause segment fault
    }else{
        std::cout << "found" << std::endl;
    }
    */

    std::unordered_map<std::string, int> words;
    std::stringstream ss;
    std::string line;
    std::string word;



    



    return 0;
}
