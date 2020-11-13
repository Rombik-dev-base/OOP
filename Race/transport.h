//
// Created by 1285166 on 31.10.2020.
//

#ifndef RACE_TRANSPORT_H
#define RACE_TRANSPORT_H

#include <string>

#define LL long long

class Transport{
public:
    Transport() = default;
    ~Transport() = default;
    virtual LL get_speed() = 0;
    virtual std :: string get_my_class() = 0;
    virtual LL get_special();
    virtual std :: string get_my_name() = 0;
private:
    std :: string my_class = "";
};

class land_transport : public Transport{
public:
    land_transport() = default;
    land_transport(LL const &speed, LL const &rest, std :: string const &name);
    virtual LL get_speed() override;
    virtual std :: string get_my_class() override;
    virtual LL get_special() override;
    virtual std :: string get_my_name() override;
private:
    LL rest_time;
    LL my_speed;
    std :: string my_class = "land_transport";
    std :: string my_name;
};

class flying_transport : public Transport{
public:
    flying_transport() = default;
    flying_transport(LL const &speed,LL const &slow, std :: string const &name);
    virtual std :: string get_my_class() override;
    virtual LL get_speed() override;
    virtual LL get_special() override;
    virtual std :: string get_my_name() override;
private :
    LL my_speed;
    std :: string my_class = "flying_transport";
    LL slower;
    std :: string my_name;
};

class Magic_carpet : public flying_transport{
    Magic_carpet();
    Magic_carpet(LL const &speed,LL const &slow, std :: string const &name);
    virtual std :: string get_my_class() override;
    virtual LL get_speed() override;
    virtual LL get_special() override;
    virtual std :: string get_my_name() override;
private :
    LL my_speed;
    std :: string my_class = "flying_transport";
    LL slower;
    std :: string my_name;
};

class Bactrian : public land_transport{
    Bactrian();
    Bactrian(LL const &speed,LL const &slow, std :: string const &name);
    virtual LL get_speed() override;
    virtual std :: string get_my_class() override;
    virtual LL get_special() override;
    virtual std :: string get_my_name() override;
private:
    LL rest_time;
    LL my_speed;
    std :: string my_class = "land_transport";
    std :: string my_name;
};



#endif //RACE_TRANSPORT_H
