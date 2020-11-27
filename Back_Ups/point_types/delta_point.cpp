//
// Created by 1285166 on 27.11.2020.
//

#include "delta_point.h"


Delta_point :: Delta_point(std :: vector <File> &files){
    storage = files;
    std :: string date = currentDateTime();
    std :: replace(date.begin(),date.end(),':',' ');
    std :: wstring new_date = std :: wstring(date.begin(),date.end());
    const wchar_t* date_c = new_date.c_str();
    std :: swscanf(date_c,L"%i %i %i %i %i %i", &cur_time.year, &cur_time.month, &cur_time.day, &cur_time.hour,&cur_time.minute,&cur_time.second);
}

std :: string Delta_point :: point_type() {
    return "delta";
}

std :: string Delta_point :: point_info() {
    unsigned long long size = 0;
    std :: string returned;
    returned += "Number of files: " + std :: to_string (storage.size()) + ' ';
    for(int i = 0 ; i < storage.size(); i++){
        size += storage[i].file_size;
    }
    returned += "Summary size of files: "  + std :: to_string(size) + '\n';
    return returned;
}

Create_time Delta_point :: return_create_time(){
    return cur_time;
}

unsigned long long Delta_point :: return_point_size() {
    unsigned  long long size = 0;
    for(int i = 0 ; i < storage.size(); i++){
        size += storage[i].file_size;
    }
    return size;
}

std :: string Delta_point :: add_parrent(Point *file) {
    parrent = file;
    return "done";
}

Point* Delta_point :: return_parrent() {
    return parrent;
}
