//
// Created by andre on 10/10/2021.
//

#ifndef TAREA_MY_HEADER_H
#define TAREA_MY_HEADER_H

#include <iostream>
#include <vector>
using namespace std;

struct Activity{
    string name;
    short start;
    short finish;

    Activity(string _name, short _start, short _finish){
        name = _name;
        start = _start;
        finish = _finish;
    }
};

vector<vector<Activity>> voracious_activities(vector<Activity> list_activities, short amount_activities);

#endif //TAREA_MY_HEADER_H
