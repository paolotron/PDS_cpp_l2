//
// Created by paolo on 31/03/2021.
//

#ifndef LAB2_DIRECTORY_H
#define LAB2_DIRECTORY_H


#include <string>
#include <list>
#include <iostream>
#include <memory>
#include <map>
#include <tuple>
#include <vector>
#include "File.h"
#include "Base.h"
#include <memory>
#include <utility>

using namespace std;
class Directory : public std::enable_shared_from_this <Directory>, public Base {
private:

    weak_ptr<Directory> parent;
    weak_ptr<Directory> self;
    std::map<string, shared_ptr<Base>> child_list;
    string name;

    static shared_ptr<struct Directory> makeDirectory(const std::string& name, weak_ptr<Directory> parent);
    shared_ptr<struct Directory> addChild(const string& name);
    Directory(string , shared_ptr<Directory>);
    int n_childs;

public:

    ~Directory();
    static shared_ptr<Directory> getroot();
    shared_ptr<Base> get(const string& name);
    shared_ptr<Directory> getDir(const string &name);
    shared_ptr<File> getFile(const string& name);
    shared_ptr<File> addFile(const string& name, uintmax_t size);
    shared_ptr<Directory> addDirectory(const std::string &nome);
    bool remove(const string& name);
    void ls(int indent) const override;
    int mType() const;


};
static shared_ptr<Directory> root;

#endif //LAB2_DIRECTORY_H
