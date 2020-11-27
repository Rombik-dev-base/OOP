//
// Created by 1285166 on 27.11.2020.
//

#include "Back_Up.h"
#include <string>
#include <bits/stdc++.h>



Back_Up :: Back_Up(const std :: vector <std :: string> &path){
    paths = path;
    update_file_info();
}

int Back_Up ::check_by_size(const long long &size) {
    unsigned long long summary_size = 0;
    int n = 0;
    for(int i = back_up_points.size() - 1; i >= 0; i--){
        unsigned long long size = back_up_points[i]->return_point_size();
        if(back_up_points[i]->point_type() == "delta"){
            if(summary_size + back_up_points[i]->return_point_size() + back_up_points[i-1]->return_point_size() > size){
                n+=2;
                i-=1;
                continue;
            }
        }
        else if(summary_size + size > size){
            n+=1;
        }
        summary_size += size;
    }
    return n;
}

int Back_Up :: check_by_date(std :: string &date){
    std :: replace(date.begin(),date.end(),':',' ');
    std :: wstring new_date = std :: wstring(date.begin(),date.end());
    const wchar_t* date_c = new_date.c_str();
    Create_time cur_time{};
    int n = 0;
    std :: swscanf(date_c,L"%i %i %i %i %i %i", &cur_time.year, &cur_time.month, &cur_time.day, &cur_time.hour,&cur_time.minute,&cur_time.second);
    for(int i = back_up_points.size() - 1; i >= 0; i--){
        if(back_up_points[i]->point_type() == "delta"){
            if(for_delete_by_date(back_up_points[i]->return_create_time(),cur_time)){
                n+=1;
            }
            else if(for_delete_by_date(back_up_points[i-1]->return_create_time(),cur_time)){
                n+=2;
                i-=1;
            }
        }
        else{
            if(for_delete_by_date(back_up_points[i]->return_create_time(),cur_time)){
                n+=1;
            }
        }
    }
    return n;
}

void Back_Up :: hybrid_delete(const int &amount, const long long &size,const std::string &date, const bool &one_of_any, const bool &by_max) {
    std :: string date_1 = date;
    int balance_by_amount = -1  ;
    int balance_by_size = -1;
    int balance_by_date = -1;
    if(size > -1 && amount > -1 && date == "none"){
        if(amount < back_up_points.size())
            balance_by_amount = amount;
        else
            balance_by_amount = back_up_points.size();
        balance_by_size = back_up_points.size() - check_by_size(size);
        if(one_of_any && (balance_by_size != back_up_points.size() || balance_by_amount != back_up_points.size())){
            if(by_max){
                if(balance_by_amount > balance_by_size){
                    delete_by_amount(amount);
                }
                else{
                    delete_by_size(size);
                }
            }
            else{
                if(balance_by_amount < balance_by_size){
                    delete_by_amount(amount);
                }
                else{
                    delete_by_size(size);
                }
            }
        }
        else if(balance_by_size != back_up_points.size() && balance_by_amount != back_up_points.size()){
            if(by_max){
                if(balance_by_amount > balance_by_date){
                    delete_by_amount(amount);
                }
                else{
                    delete_by_date(date_1);
                }
            }
            else{
                if(balance_by_amount < balance_by_date){
                    delete_by_amount(amount);
                }
                else{
                    delete_by_date(date_1);
                }
            }
        }
    }
    else if(size == -1 && amount > -1 && date != "none"){
        if(amount < back_up_points.size())
            balance_by_amount = amount;
        else
            balance_by_amount = back_up_points.size();
        balance_by_date = back_up_points.size() - check_by_date(date_1);
        if(one_of_any && (balance_by_date != back_up_points.size() || balance_by_amount != back_up_points.size())){
            if(by_max){
                if(balance_by_amount > balance_by_date){
                    delete_by_amount(amount);
                }
                else{
                    delete_by_date(date_1);
                }
            }
            else{
                if(balance_by_amount > balance_by_date){
                    delete_by_date(date_1);
                }
                else{
                    delete_by_amount(amount);
                }
            }
        }
        else if(balance_by_date != back_up_points.size() && balance_by_amount != back_up_points.size()){
            if(by_max){
                if(balance_by_amount > balance_by_date){
                    delete_by_amount(amount);
                }
                else{
                    delete_by_date(date_1);
                }
            }
            else{
                if(balance_by_amount < balance_by_date){
                    delete_by_amount(amount);
                }
                else{
                    delete_by_date(date_1);
                }
            }
        }
    }
    else if(size > -1 && amount == -1 && date != "none"){
        balance_by_size = back_up_points.size() - check_by_size(size);
        balance_by_date = back_up_points.size() - check_by_date(date_1);
        if(one_of_any && (balance_by_date != back_up_points.size() || balance_by_size != back_up_points.size())){
            if(by_max){
                if(balance_by_size > balance_by_date){
                    delete_by_size(size);
                }
                else{
                    delete_by_date(date);
                }
            }
            else{
                if(balance_by_size < balance_by_date){
                    delete_by_amount(size);
                }
                else{
                    delete_by_date(date);
                }
            }
        }
        else if(balance_by_date != back_up_points.size() && balance_by_size != back_up_points.size()){
            if(by_max){
                if(balance_by_size > balance_by_date){
                    delete_by_size(size);
                }
                else{
                    delete_by_date(date);
                }
            }
            else{
                if(balance_by_size < balance_by_date){
                    delete_by_size(size);
                }
                else{
                    delete_by_date(date);
                }
            }
        }
    }
}

void Back_Up :: update_file_info() {
    files.clear();
    for(int i = 0; i < paths.size();i++){
        unsigned long long size = fileSize(paths[i].c_str());
        File new_file(paths[i], size);
        files.push_back(new_file);
    }
}

std :: string Back_Up :: create_point(const std::string &type) {
    update_file_info();
    if(type == "full"){
        Full_point *me = new Full_point(files);
        back_up_points.push_back(me);
    }
    else{
        if(back_up_points[back_up_points.size() - 1]->point_type() != "full"){
            std :: cout << "Can't create new delta";
        }
        else{
            std :: vector<File> storage = back_up_points[back_up_points.size() - 1]->return_storage();
            int i = 0;
            int j = 0;
            while(i != storage.size()){
                if(storage[i].file_size == files[j].file_size){
                    storage.erase(storage.begin() + i);
                    j++;
                }
                else{
                    i++;j++;
                }
            }
            if(storage.size() != 0) {
                Delta_point *me = new Delta_point(storage);
                back_up_points.push_back(me);
                back_up_points[back_up_points.size()-1]->add_parrent(back_up_points[back_up_points.size() - 2]);
                back_up_points[back_up_points.size()-2]->add_child(back_up_points[back_up_points.size() - 1]);
            }
            else{
                std :: cout << "\nCan't create delta\n";
            }
        }
    }
    return "done";
}

void Back_Up :: print_point_info(const unsigned long &num) {
    if(num < back_up_points.size() && num >= 0) {
        std::cout << back_up_points[num]->point_info() << '\n';
    }
    else{
        std :: cout << "\nBack up with that num is didn't created\n";
    }
}

unsigned long long Back_Up :: fileSize(const char *add){
    FILE *p_file = NULL;
    p_file = fopen(add,"rb");
    fseek(p_file,0,SEEK_END);
    unsigned long long size = ftell(p_file);
    fclose(p_file);
    return size;
}

void Back_Up :: delete_by_amount(const int &num) {
    while(back_up_points.size() != num){
        if(back_up_points[0]->point_info() == "full"){
            if(back_up_points[back_up_points.size()]->return_child() != nullptr) {
                back_up_points.erase(back_up_points.begin() + 1);
                back_up_points[0]->add_child(nullptr);
            }
        }
        else{
            back_up_points.erase(back_up_points.begin());
        }
    }
}

void Back_Up :: delete_by_size(const unsigned long long &num) {
    unsigned long long summary_size = 0;
    for(int i = back_up_points.size() - 1; i >= 0; i--){
        unsigned long long size = back_up_points[i]->return_point_size();
        if(back_up_points[i]->point_type() == "delta"){
            if(summary_size + back_up_points[i]->return_point_size() + back_up_points[i-1]->return_point_size() > num){
                back_up_points.erase(back_up_points.begin()+i);
                back_up_points[i-1]->add_child(nullptr);
                continue;
            }
        }
        else if(summary_size + size > num){
            back_up_points.erase(back_up_points.begin()+i);
            continue;
        }
        summary_size += size;
    }
}

int Back_Up :: print_amount_of_points() {
    return back_up_points.size();
}

bool Back_Up ::for_delete_by_date(const Create_time &first, const Create_time &second) {
    return first.second < second.second || first.minute < second.minute || first.hour< second.hour
           || first.day < second.day ||  first.month < second.month ||  first.year < second.year;
}

void Back_Up :: delete_by_date(const std::string &date) {
    std :: string date_1 = date;
    std :: replace(date_1.begin(),date_1.end(),':',' ');
    std :: wstring new_date = std :: wstring(date.begin(),date.end());
    const wchar_t* date_c = new_date.c_str();
    Create_time cur_time{};
    std :: swscanf(date_c,L"%i %i %i %i %i %i", &cur_time.year, &cur_time.month, &cur_time.day, &cur_time.hour,&cur_time.minute,&cur_time.second);
    for(int i = back_up_points.size() - 1; i >= 0; i--){
        if(back_up_points[i]->point_type() == "delta"){
            if(for_delete_by_date(back_up_points[i]->return_create_time(),cur_time)){
                back_up_points.erase(back_up_points.begin() + i);
            }
            else if(for_delete_by_date(back_up_points[i-1]->return_create_time(),cur_time)){
                back_up_points.erase(back_up_points.begin()+i);
                i-=1;
                back_up_points.erase(back_up_points.begin()+i);
            }
        }
        else{
            if(for_delete_by_date(back_up_points[i]->return_create_time(),cur_time)){
                back_up_points.erase(back_up_points.begin()+i);
            }
        }
    }
}

