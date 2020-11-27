//
// Created by 1285166 on 27.11.2020.
//

#ifndef BACK_UPS_DELTA_POINT_H
#define BACK_UPS_DELTA_POINT_H

#include "point.h"

class Delta_point : public Point{
public:
    Delta_point(std :: vector <File> &files);
    std :: string point_type() override;
    std :: string point_info() override;
    std :: string add_parrent(Point *file) override;
    Point* return_parrent() override;
    unsigned long long return_point_size() override;
    Create_time return_create_time() override;
private:
    std :: vector<File> storage;
    Point *parrent = nullptr;
    Create_time cur_time;
};

#endif //BACK_UPS_DELTA_POINT_H
