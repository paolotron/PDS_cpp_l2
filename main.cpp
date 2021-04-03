
#include <iostream>
#include "pList.h"
#include "vector.h"
#include "Directory.h"

void testList(){
    auto list = pList<int>();
    list.insertIncOrderedNode(3);
    list.insertIncOrderedNode(6);
    list.insertIncOrderedNode(1);
    list.insertIncOrderedNode(10);
    list.insertIncOrderedNode(10);
    list.insertIncOrderedNode(1);
    list.insertIncOrderedNode(5);
    list.insertIncOrderedNode(10);
    list.swapNodes(1,3);
    list.insertNode(21, 0);
    std::cout << list.findNodeByPos(2) << "\n";
    std::cout << list.findNodeByVal(10) << "\n";

}

void busort(Vector<int>v, int dim){
    for (int i = 0; i < dim; ++i) {
        for (int j = i; j < dim; ++j) {
            if(v[j]<=v[i])
                std::swap(v[i],v[j]);
        }
    }
}

void sort(){
    Vector<int> v = Vector<int>();
    for(int i=99,j=0; i>=0; i--,j++)
        v[j] = i;
    v.print(100);
    busort(v,100);
    std::cout << "\n";
    v.print(100);
}



int main (){
    shared_ptr<Directory> roota = Directory::getroot();
    roota->addDirectory("dir1");
    roota->addDirectory("dir2");
    roota->getDir("dir1")->addDirectory("dir4");
    roota->addFile("filone",100);
    std::cout<<roota->getFile("filone")->getSize()<<"\n";
    roota->remove("filone");
    roota->ls(0);
}