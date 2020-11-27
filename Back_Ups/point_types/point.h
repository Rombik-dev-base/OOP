//
// Created by 1285166 on 27.11.2020.
//

#ifndef BACK_UPS_POINT_H
#define BACK_UPS_POINT_H
#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <fstream>
#include <algorithm>
#include <vector>

struct Create_time{
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
};

struct File{
    File(std :: string path, unsigned long long size){
        file_path = path;
        file_size = size;
    }
    std :: string file_path;
    unsigned long long file_size;
};

class Point{
public:
    Point() = default;
    const std :: string currentDateTime();
    virtual unsigned long long return_point_size();
    virtual std :: string point_type();
    virtual std :: string point_info();
    virtual std :: string add_child(Point *file);
    virtual std :: string add_parrent(Point *file);
    virtual Point* return_child();
    virtual Point* return_parrent();
    virtual std :: vector<File> return_storage();
    virtual Create_time return_create_time();
};

#endif //BACK_UPS_POINT_H
