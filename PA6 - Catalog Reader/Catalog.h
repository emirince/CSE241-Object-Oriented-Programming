#ifndef CATALOG_H
#define CATALOG_H

#include <vector>

namespace PA6{

template<class T>
class Catalog{

private: 

std::vector<T> objectList;      //It holds Template objects

public:

Catalog(){}     //constructor

~Catalog(){}    //destructor

std::vector<T> getObjects() const{      //object getters
    return objectList;
}

void removeObject(int removeIndex){     //removes specific object from index
    std::vector<T> temp;
    for (int i = 0 ; i < objectList.size() ; i++)
    {
        if (i != removeIndex)
        {
            temp.push_back(objectList[i]);
        }
    }
    objectList = temp;
}

void addObject(T& objectToBeAdded){     //addes object to objectList
    objectList.push_back(objectToBeAdded);
}

};
}
#endif