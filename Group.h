#ifndef GROUP_HH
#define GROUP_HH

#include "Multimedia.h" // is it necessary if we include its subclasses ?

#include "Picture.h"
#include "Video.h"
#include "Film.h"
#include<iostream>

#include <list>
#include <memory>

using MultimediaPtr = std::shared_ptr<Multimedia>;



class Group : public std::list<MultimediaPtr> {
    friend class MediaMaster;

    
    private:
    std::string name{};

    protected:
    Group(): std::list<MultimediaPtr>(){}

    public:
    std::string getGroupName() const {return name;}
    
    void display(ostream & out) const {
        int i = 0;
        for (auto & it : *this) {
            std::string groupName = this->getGroupName();
            out << "This is the Group : " <<  groupName<< endl;
            out << "Information about element : " << i <<endl;
            it->display(out); 
            i++;
        }
            out << endl << endl ;
    }




};



#endif