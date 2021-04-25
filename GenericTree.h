//
// Created by paolo on 21/04/2021.
//

#ifndef LAB2_GENERICTREE_H
#define LAB2_GENERICTREE_H

template <typename key, typename T>
class GenericTree{
private:
    string name;
    GenericTree<key, T> *parent;
    std::map<key, GenericTree<key, T>*> child_map;
    T body;

    GenericTree(GenericTree *par,const key& name, T body){
        child_map = map<key ,GenericTree<key, T>*>();
        this->name = name;
        this->body = body;
        this->parent = par;
    }

public:
    GenericTree(){
        child_map = map<string ,GenericTree<key, T>*>();
    }

    GenericTree(const key& name, T body){
        child_map = map<key ,GenericTree<key, T>*>();
        this->name = name;
        this->body = body;
        this->parent = nullptr;
    }

    GenericTree(const GenericTree<key, T> &g1){
        this->child_map = g1.child_map;
        this->parent = g1.parent;
        this->body = g1.body;
    }

    GenericTree& operator=(GenericTree const &g1){
        this->child_map = g1.child_map;
        this->body = g1.body;
        this->parent = g1.parent;
        return *this;
    }

    GenericTree<key, T>& operator[](key k){
        return get_child(k);
    }

    T operator*(){
        return this->get_body();
    }

    GenericTree<key, T>& add_child(key id,T elem){
        child_map[id] = new GenericTree<T, key>(this, id, elem);
        return *this;
    }

    GenericTree<key, T>& get_child(key id){
        return *child_map[id];
    }

    T get_body(){
        return body;
    }

    string get_id(){
        return this->name;
    }

    ~GenericTree(){
        for(std::pair<key, GenericTree<key,T>*> element: this->child_map){
            delete element.second;
            element.second = nullptr;
        }
    }
};


#endif //LAB2_GENERICTREE_H
