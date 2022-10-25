#ifndef POINT_H
#define POINT_H
#include<iostream>
#include<cmath>
#include"socket.h"

class Point
{
private:
    int x, y;
public:
    Point(int i = 0, int j = 0) {
        x = i;  y = j;
    }

    Point(shared_ptr<Point> &maali, shared_ptr<Point> &ball){   
        int d_x = maali->x - ball->x;
        int d_y = maali->y - ball->y;
        double distance_ball_to_maali 
            = sqrt(pow(d_x,2) + pow(d_y,2));

        x = ball->x - 250*d_x/distance_ball_to_maali;
        y = ball->y - 250*d_y/distance_ball_to_maali;
    }

    int get_x(){
        return x;
    }

    int get_y(){
        return y;
    }
    
    string display()
    {
    return to_string(x) + "," + to_string(y) + "\n";
    }

}; 
#endif

