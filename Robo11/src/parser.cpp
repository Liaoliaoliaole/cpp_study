#include <bits/stdc++.h> 
#include <cmath>
#include <memory>
#include "parser.h"
#include "player.h"
#include "opponent.h"

using namespace std;

vector<shared_ptr<Object>> Parser::initObjects()
{
    vector<shared_ptr<Object>> os;
    os.push_back(make_shared<Ball>());
    for (int x{1}; x<6; ++x)
    {
        string str = "R" + to_string(x);
        os.push_back(make_shared<Player>(str));;
    }
        for (int x{1}; x<6; ++x)
    {
        string str_o = "O" + to_string(x);
        os.push_back(make_shared<Opponent>(str_o));
    }
    return os;
}

void Parser::parse(string &str,vector<shared_ptr<Object>> &os)
{
    stringstream ss(str);
    string line;
    while(getline(ss,line))
    {
        char key[20];
        float x,y;
        sscanf(line.c_str(),"%[B-R,1-5]: %f,%f",key,&x,&y);
        string s = key;
        for(auto &ob: os)
        {
            if(s==(ob->getID()))
            {
                ob->setX(round(x));
                ob->setY(round(y));
            }
        }
    } 
}

string Parser::concatenate(vector<shared_ptr<Object>> &os)
{
    string ts;
    for(int i{1};i<6;++i)
    { 
        if(os.at(i)->getType()==objectTypes::Player)
        {
            shared_ptr<Player> p = dynamic_pointer_cast<Player>(os.at(i));
            ts += p->getID().substr(1) + "," + to_string(p->getTarget().x) + "," + to_string(p->getTarget().y) + "\n";
            
        }
    }
    //out << "--------------------TARGETS SENT: " << endl;
    //cout << ts << endl;
    return ts;    
}


    
