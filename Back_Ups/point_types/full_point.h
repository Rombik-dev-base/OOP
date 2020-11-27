//
// Created by 1285166 on 27.11.2020.
//

#ifndef BACK_UPS_FULL_POINT_H
#define BACK_UPS_FULL_POINT_H
#include "point.h"

class Full_point : public Point{
public:
    Full_point(std :: vector <File> &files);
    std :: string point_type() override;
    std :: string point_info() override;
    std :: string add_child(Point *file) override;
    Point* return_child() override;
    unsigned long long return_point_size() override;
    std :: vector<File> return_storage() override;
    Create_time return_create_time() override;
private:
    std :: vector<File> storage;
    Point *child = nullptr;
    Create_time cur_time;
};
#endif //BACK_UPS_FULL_POINT_H
