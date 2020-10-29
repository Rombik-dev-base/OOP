//
// Created by 1285166 on 29.10.2020.
//

#include "pars.h"


Parser :: Parser(std :: string InpFileName){
    if(InpFileName.substr(InpFileName.size() - 4,4) == ".ini" && InpFileName.size() > 4) {
        fileName = InpFileName;
        file.open(InpFileName);
        if(file.is_open()) {
            file_is_open = 1;
        }
        else
            throw myexception("No file in such directory");
    }
    else{
        throw myexception("Incorrect filename");
    }
    read_sort();
}
Parser :: ~Parser(){
    if(file_is_open){
        file.close();
        file_is_open = false;
    }
    fileName.clear();
    container.clear();
}


void Parser :: read_sort() {
    std :: string contain;
    std :: string cur_key;
    int found_pos = -1;
    while(std :: getline(file, contain)){
        if(contain[0] == '['){
            cur_key = contain;
            continue;
        }
        found_pos = contain.find(';');
        if(found_pos != -1){
            contain.erase(contain.begin() + found_pos, contain.end());
        }
        if(contain.size() == 0)
            continue;
        space_deleter(contain);
        std :: string second_part_of_string;
        found_pos = contain.find('=');
        second_part_of_string = contain.substr(found_pos + 1,contain.size() - found_pos);
        contain.erase(contain.begin() + found_pos, contain.end());
        std :: string type_of_value;
        std :: regex reg_float("[\\-\\+]?[1-9]+[0-9]+.[0-9]+");
        std :: regex reg_int("[\\-\\+]?[1-9]+[0-9]+");
        space_deleter(contain);
        space_deleter(second_part_of_string);
        if(std :: regex_match(second_part_of_string.begin(),second_part_of_string.end(),reg_int)) {
            container.insert(std :: pair < std :: string, std :: pair < std :: string , std  :: pair < std :: string , std :: string >  > >(cur_key,std ::
            make_pair(contain, std :: make_pair ( second_part_of_string, "integer"))));
            continue;
            }

        if(std :: regex_match(second_part_of_string.begin(),second_part_of_string.end(),reg_float)) {
            container.insert(std :: pair < std :: string, std :: pair < std :: string , std  :: pair < std :: string , std :: string >  > >(cur_key,std ::
            make_pair(contain, std :: make_pair ( second_part_of_string, "float"))));
            continue;
            }
        container.insert(std :: pair < std :: string, std :: pair < std :: string , std  :: pair < std :: string , std :: string >  > >(cur_key,std ::
        make_pair(contain, std :: make_pair ( second_part_of_string, "string"))));
    }
    std :: cout << '\n' <<  container.size() << ' ';
}



void Parser :: space_deleter(std :: string cur_str) {
    while(cur_str[0] == ' ' || cur_str[cur_str.size() - 1] == ' '){
        if(cur_str[0] == ' '){
            cur_str.erase(0,1);
        }
        if(cur_str[cur_str.size() - 1] == ' ')
            cur_str.erase(cur_str.size() - 1 , 1);
    }
}

void Parser :: find(std :: string el_type, std :: string type_name, std :: string section){
    auto eq = container.equal_range(section);
    for(auto it = eq.first; it != eq.second; it++){
        if(it->second.first == type_name){
            if(it->second.second.second == el_type || el_type == "string") {
                std::cout << '\n' << it->second.second.first << '\n';
                return;
            }
            else{
                throw myexception("Type casting is not possible");
            }
        }
    }
    throw myexception("The specified pair SECTION - PARAMETER is not in the configuration file");
}