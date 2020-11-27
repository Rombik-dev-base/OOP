//
// Created by 1285166 on 27.11.2020.
//

#include "point.h"

const std::string Point :: currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y:%m:%d:%X", &tstruct);
    return buf;
}

Create_time Point :: return_create_time(){
    return {};
}

std :: string Point :: point_type() {
    return "none";
}

std :: string Point :: point_info(){
    return "none";
}

std :: string Point :: add_child(Point *file) {
    return "none";
}

std :: string Point :: add_parrent(Point *file) {
    return "none";
}

Point* Point :: return_child() {
    return nullptr;
}

Point* Point :: return_parrent() {
    return nullptr;
}

std :: vector<File> Point :: return_storage(){
    return {};
}

unsigned long long Point :: return_point_size() {
    return 0;
}
