//
// Created by paolo on 31/03/2021.
//

#ifndef LAB2_PLIST_H
#define LAB2_PLIST_H



template<typename T>
class pList {

public:
    pList();
    ~pList();
    void push_front(const T &val);
    T popNode();
    void push_back(const T &val);
    void insertNode(const T &val, int pos);
    void insertIncOrderedNode(const T &val);
    void insertDecOrderedNode(const T &val);
    void deleteNodeByPos(const int &pos);
    void deleteNodeByVal(const T &val);
    void swapNodes(const int &pos0, const int &pos1);
    T findNodeByPos(const int &pos) const;
    int findNodeByVal(const char &val) const;

private:
    typedef struct listNode
    {
        T value;
        struct listNode *next;
    } nodes;

    nodes *_head, *_tail, *_current_el;

    nodes *_new_node();
};




#endif //LAB2_PLIST_H
