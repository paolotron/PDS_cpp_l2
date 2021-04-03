//
// Created by paolo on 03/04/2021.
//

#ifndef LAB2_BASE_H
#define LAB2_BASE_H

class Base{
public:
    Base(){};
    std::string getName()const;
    virtual int mType() const = 0;
    virtual void ls(int indent)const = 0;
};
#endif //LAB2_BASE_H
