//
// Created by paolo on 31/03/2021.
//

#include <new>
#include <unordered_set>
#include "pList.h"

template<typename T>
typename pList<T>::nodes *pList<T>::_new_node() {
    nodes* nn = new (std::nothrow) nodes() ;
    return nn;
}


template<typename T>
pList<T>::pList() {
    _head = nullptr;
    _tail = nullptr;
    _current_el = nullptr;
}

template<typename T>
void pList<T>::push_front(const T &val) {
    nodes* _nnode = _new_node();
    _nnode->value = val;
    if (_head == nullptr){
        _head = _nnode;
        _tail = _nnode;
        _current_el = _nnode;
    }
    else{
        _nnode->next = _head;
        _head = _nnode;
    }
}


template<typename T>
T pList<T>::popNode() {
    T _val = _head->value;
    nodes* _old = _head;
    _head = _head->next;
    _current_el = _head;
    delete _old;
    return _val;
}

template<typename T>
void pList<T>::push_back(const T &val) {
    nodes* nnode = _new_node();
    if(_head != nullptr) {
        nnode->value = val;
        _tail->next = nnode;
        _tail = nnode;
        _current_el = _tail;
    }
    else{
        _tail = nnode;
        _head = nnode;
        _current_el = nnode;
    }
}

template<typename T>
void pList<T>::insertNode(const T &val, int pos) {
    nodes* el1 = nullptr;
    nodes* el2 = nullptr;
    nodes* el3 = _new_node();
    el3->value = val;
    int i;
    if(pos!=0) {
        for (i = 0, el1 = _head; i < pos - 1; i++, el1 = el1->next);
        if(el1 != _tail) {
            el2 = el1->next;
            el1->next = el3;
            el3->next = el2;
            _current_el = el2;
        }
        else{
            _tail->next = el3;
            _tail = el3;
        }
    }
    else{
        el3->next = _head;
        _head = el3;
        _current_el = el3;
    }
}

template<typename T>
void pList<T>::insertIncOrderedNode(const T &val) {
    if(_head == nullptr)
        push_front(val);
    else{
        nodes* nnode = _new_node();
        nnode->value = val;
        _current_el = nnode;
        if(_head->value > val){
            nnode->next = _head;
            _head = nnode;
            return;
        }
        if(_tail->value < val){
            nnode->next = nullptr;
            _tail->next = nnode;
            _tail = nnode;
            return;
        }
        for(nodes* n = _head;n->next != nullptr;n=n->next){
            if(n->value <= val && val <= n->next->value) {
                nnode->next = n->next;
                n->next = nnode;
                return;
            }
        }
    }
}

template<typename T>
void pList<T>::insertDecOrderedNode(const T &val) {
    if(_head == nullptr)
        push_front(val);
    else{
        nodes* nnode = _new_node();
        nnode->value = val;
        _current_el = nnode;
        if(_head->value < val){
            nnode->next = _head;
            _head = nnode;
            return;
        }
        if(_tail->value > val){
            nnode->next = nullptr;
            _tail->next = nnode;
            _tail = nnode;
            return;
        }
        for(nodes* n = _head;n->next != nullptr;n=n->next){
            if(n->value >= val && val >= n->next->value) {
                nnode->next = n->next;
                n->next = nnode;
                return;
            }
        }
    }
}

template<typename T>
void pList<T>::deleteNodeByPos(const int &pos) {
    if(pos==0){
        nodes* el = _head->next;
        delete &(_head->value);
        delete _head;
        _head = el;
        _current_el = _head;
        return;
    }
    nodes* n = _head;
    for(int i=0; i<pos-1; i++, n=n->next);
    nodes* del = n->next;
    n->next = n->next->next;
    delete &(del->value);
    delete del;
    _current_el = n;
}

template<typename T>
void pList<T>::deleteNodeByVal(const T &val) {
    for (nodes* n = _head; n != nullptr; n=n->next){
        if(n->next->value == val){
            nodes* old = n->next;
            n->next = n->next->next;
            _current_el = n;
            delete &(old->value);
            delete old;
        }
    }
    if(_head->value == val){
        nodes* next = _head->next;
        delete &(_head->value);
        delete _head;
        _head = next;
    }
}

template<typename T>
pList<T>::~pList() {
    while (_head != nullptr){
        nodes *n = _head->next;
        delete &_head->value;
        delete _head;
        _head = n;
    }
}

template<typename T>
void pList<T>::swapNodes(const int &pos0, const int &pos1) {
    nodes *el1=_head;
    nodes *el2=_head;
    for(int i=0;i<pos0;i++,el1=el1->next);
    for(int i=0;i<pos1;i++,el2=el2->next);
    std::swap(el1->value, el2->value);
}

template<typename T>
T pList<T>::findNodeByPos(const int &pos) const {
    nodes *el1=_head;
    for(int i=0;i<pos;i++,el1=el1->next);
    return el1->value;
}

template<typename T>
int pList<T>::findNodeByVal(const char &val) const {
    nodes *el1=_head;
    int i = 0;
    for(;el1!= nullptr && el1->value != val;el1=el1->next, i++);
    return i;
}


template class pList<int>;