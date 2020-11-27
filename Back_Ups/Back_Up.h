//
// Created by 1285166 on 27.11.2020.
//

#ifndef BACK_UPS_BACK_UP_H
#define BACK_UPS_BACK_UP_H
#include "point_types/full_point.h"
#include "point_types/delta_point.h"

class Back_Up{
public:
    Back_Up(const std :: vector <std :: string> &path);
    unsigned long long fileSize(const char *add);
    std :: string create_point(const std :: string &type);
    void print_point_info(const unsigned long &num);
    int print_amount_of_points();
    void update_file_info();
    void delete_by_amount(const int &num);
    void delete_by_size(const unsigned long long &num);
    void delete_by_date(const std :: string &date);
    void hybrid_delete(const int &amount = -1, const long long &size = -1, const std :: string &date = "none", const bool &one_of_any = false, const bool &by_max = false);

private:
    int check_by_size(const long long &size);
    int check_by_date(std :: string &date);
    bool for_delete_by_date(const Create_time &first, const Create_time &second);
    std :: vector<std :: string> paths;
    std :: vector<File> files;
    std :: vector<Point*> back_up_points;
};

#endif //BACK_UPS_BACK_UP_H
