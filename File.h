//
// Created by paolo on 03/04/2021.
//

#ifndef LAB2_FILE_H
#define LAB2_FILE_H


#include "Base.h"

class File: public std::enable_shared_from_this <File>, public Base  {
private:
    std::string name;
    uintmax_t size;
public:
    File(std::string name,uintmax_t size){
        this->name = name;
        this->size = size;
    }


    uintmax_t getSize() const{
        return size;
    }

    int mType() const{
        return 1;
    }

    void ls(int indent)const override{
        std::string tabs="\t";
        if(indent==0)
            tabs="";
        else
            for(int i=0; i<indent; i++, tabs+=tabs);
        std::cout << "    " << tabs+name << "\n";
    }
};


#endif //LAB2_FILE_H
