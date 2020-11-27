//
// Created by 1285166 on 27.11.2020.
//

#include "full_point.h"
Full_point :: Full_point(std :: vector <File> &files){
    storage = files;
    std :: string date = currentDateTime();
    std :: replace(date.begin(),date.end(),':',' ');
    std :: wstring new_date = std :: wstring(date.begin(),date.end());
    const wchar_t* date_c = new_date.c_str();
    std :: swscanf(date_c,L"%i %i %i %i %i %i", &cur_time.year, &cur_time.month, &cur_time.day, &cur_time.hour,&cur_time.minute,&cur_time.second);
}

std :: string Full_point :: point_type() {
    return "full";
}

std :: string Full_point :: point_info() {
    unsigned long long size = 0;
    std :: string returned;
    returned += "Number of files: " + std :: to_string (storage.size()) + ' ';
    for(int i = 0 ; i < storage.size(); i++){
        size += storage[i].file_size;
    }
    returned += "Summary size of files: "  + std :: to_string(size) + '\n';
    return returned;
}

unsigned long long Full_point :: return_point_size() {
    unsigned  long long size = 0;
    for(int i = 0 ; i < storage.size(); i++){
        size += storage[i].file_size;
    }
    return size;
}

std :: string Full_point :: add_child(Point *file) {
    child = file;
    return "done";
}

Create_time Full_point :: return_create_time(){
    return cur_time;
}


Point* Full_point :: return_child() {
    return child;
}

std :: vector<File> Full_point ::  return_storage(){
    return storage;
}