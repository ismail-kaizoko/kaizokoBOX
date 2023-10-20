#ifndef GROUP_HH
#define GROUP_HH

#include "Multimedia.h" // is it necessary if we its subclasses ?

#include "Picture.h"
#include "Video.h"
#include "Film.h"

#include <iostream>


// using TrucPtr = std::shared_ptr<Truc> ;

class Group : public std::lisp< Multimedia *> {
    private:
    std::string name{};
    
    public:
    
    void display(ostream & out) const {
        int i = 0;
        for (auto & it : *this) {
            cout << "Information about element" << i;
            it->display(out); 
            out << endl << endl ;
            i++;
        }
    }

    std::string getGroupName() const {return name;}


};





#endif