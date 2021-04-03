//
// Created by paolo on 31/03/2021.
//

#include "Directory.h"



Directory::Directory(string name, shared_ptr<Directory> par):name(std::move(name)){
    child_list =  map<string ,shared_ptr<Base>>();
    parent = par;
}


void Directory::ls(int indent) const{
    string tabs="\t";
    if(indent==0)
        tabs="";
    else
        for(int i=0; i<indent; i++, tabs+=tabs);
    std::cout << "    " << tabs+name << "\n";
    for(auto el: child_list){
        std::get<1>(el)->ls(indent+1);
    }
}
int Directory::mType() const{
    return 1;
}

shared_ptr<Directory> Directory::addChild(const string& c_name) {
    auto child = shared_ptr<Directory>(new Directory(c_name, this->shared_from_this()));
    this->child_list[c_name] = child;
    n_childs++;
    return child;
}

shared_ptr<Base> Directory::get(const string& address){
    int i = 0;
    int j = 0;
    string subname;
    shared_ptr<Directory> current = dynamic_pointer_cast<Directory>(this->shared_from_this());
    shared_ptr<Base> temp;
    while(true){
        j++;
        if(address[j] == '/'|| i+j==address.length()){
            subname = address.substr(i, j);
            if(subname == "..")
                temp = dynamic_pointer_cast<Base>(shared_ptr<Directory>(current->parent));
            else{
                for(tuple<string,shared_ptr<Base>> c : child_list){
                    if(std::get<0>(c)==subname)
                        temp = std::get<1>(c);
                }
            }
            if(i+j==address.length()){
                return temp;
            }
            else{
                current = dynamic_pointer_cast<Directory>(temp);
            }
            i = j+1;
            j = 0;

        }
    }
}



shared_ptr<Directory> Directory::getroot() {
    if(root == nullptr)
        root = shared_ptr<Directory>(new Directory("/", nullptr));
    return root;
}

shared_ptr<Directory> Directory::addDirectory(const string &nome) {
    return makeDirectory(nome, this->shared_from_this());
}

shared_ptr<Directory> Directory::makeDirectory(const string &name, weak_ptr<Directory> parent) {
    auto par = shared_ptr<Directory>(parent);
    auto ch = par->addChild(name);
    par->self = par;
    return ch;
}

Directory::~Directory() {

}

shared_ptr<Directory> Directory::getDir(const string &name) {
    shared_ptr<Base> dir = get(name);
    shared_ptr<Directory> real_dir = dynamic_pointer_cast<Directory>(dir);
    return real_dir;
}

shared_ptr<File> Directory::getFile(const string &name) {
    shared_ptr<Base> dir = get(name);
    shared_ptr<File> real_dir = dynamic_pointer_cast<File>(dir);
    return real_dir;
}

shared_ptr<File> Directory::addFile(const string &name, uintmax_t size) {
    if(child_list.find(name) != child_list.end())
        return shared_ptr<File>(nullptr);
    auto ch = make_shared<File>(name, size);
    child_list[name] = ch;
    return ch;
}

bool Directory::remove(const string &name) {
    if(child_list.find(name) != child_list.end() && name != "." && name != ".."){
        child_list.erase(name);
        return true;
    }
    return false;
}




