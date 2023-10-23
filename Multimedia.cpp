#ifndef MULTIMEDIA
#define MULTIMEDIA


#include "Multimedia.h"

#endif

Multimedia::Multimedia(){};

Multimedia::Multimedia(string name, string pathName){
    this->name = name;
    this->pathName = pathName;
}

Multimedia::~Multimedia(){cout << "I will die now :' . " ;};



void Multimedia::setName(string name){
    this->name = name;
}

void Multimedia::setPathName(string pathName){
    this->pathName = pathName;
}

string Multimedia::getName() const{
    return name;
}

string Multimedia::getPathName() const{
    return pathName;
}

void Multimedia::display(ostream &out) const{
    out << "File name :" << this->name <<  endl << "File Path  :" << this->pathName << endl ;
}
