#include <iostream>
#include <sstream>  
#include <iterator>
#include <vector>
#include <map>
#include "parse.h"
#include "vectr.h"

using namespace std;

map<string,Vectr> split(string &str){
    for (int i = 0; i < str.size(); i++){
        if (str[i] == ':' /*|| str[i] == ','*/){
            str[i] = ',';
        }       
    }
    map<string,Vectr> output;
    stringstream ss(str);//用str构造新的ss，丢弃旧的
    string line;   
    while(getline(ss,line,'\n')){
        stringstream s(line);
        string sub;
        vector<string> cord;
        while(getline(s,sub,',')){
            cord.push_back(sub);
        }
        int x = stoi(cord.at(1));
        int y = stoi(cord.at(2));
        auto p = make_pair(cord.at(0),Vectr(x,y));
        output.insert(p);
    }
    return output;
}

vector<shared_ptr<Vectr>> circle_dance(int a, int b,int r){
    if(a<r || b< r){
        cout << "invalid circle center." << endl;
        exit(-1);
    }else{
    vector<shared_ptr<Vectr>>circle;
        int x = a-r;
        int y = b;
        for(x=a-r;x<a+r;x=x+10){
            y=b+sqrt(r*r-pow(a-x,2));
            circle.push_back(make_shared<Vectr>(x,y));
        }
        for(x=a+r;x>a-r;x=x-10){
            y=b-sqrt(r*r-pow(a-x,2));
            circle.push_back(make_shared<Vectr>(x,y));
        }
     return circle;
    }
}


    
