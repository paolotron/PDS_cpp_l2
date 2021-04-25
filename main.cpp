
#include <iostream>
#include "pList.h"
#include "vector.h"
#include "Directory.h"
#include "matrix.h"
#include "GenericTree.h"

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
    Vector<int> v = Vector<int>(100);
    for(int i=99,j=0; i>=0; i--,j++)
        v[j] = i;
    v.print(100);
    busort(v,100);
    std::cout << "\n";
    v.print(100);
}

void testdir(){
    shared_ptr<Directory> roota = Directory::getroot();
    roota->addDirectory("dir1");
    roota->addDirectory("dir2");
    roota->getDir("dir1")->addDirectory("dir4");
    roota->addFile("filone",100);
    std::cout<<roota->getFile("filone")->getSize()<<"\n";
    roota->remove("filone");
    roota->ls(0);
}

void testmatrix(){
    Matrix<int> m = Matrix<int>(10,10);
    for(int i=0; i<10; i++)
        for(int j=0; j<10; j++)
            m[i][j] = i*j;
    for(int i=0; i<10; i++) {
        for (int j = 0; j < 10; j++)
            cout << m[i][j] % 10 << " ";
        cout << "\n";
    }
}


int main (){
    GenericTree<int, int> rt(2, 3);
    rt.add_child(1, 2).add_child(2, 9).add_child(0, 10);
    cout <<  *rt[2] << "\n";

}