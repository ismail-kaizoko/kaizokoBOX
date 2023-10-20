#ifndef PICTURE_HH
#define PICTURE_HH
#include "Multimedia.h"

class Picture : public Multimedia {
    private:
    float length{}, width{};

    public:
    Picture() : Multimedia(),length(0),width(0) {};
    Picture(string name, string pathName, int l, int w) : Multimedia(name, pathName),length(l),width(w){}

    void setLength(int l)  {length = l;}
    void setWidth(int w)   {width = w;}
    float getLength()      const {return length;}
    float getWidth()       const {return width;}

    void play() const override { 
        string path = this->getPathName();
        system( ("imagej " + path + " &").data()  );
        } 
     
    //It's not necessary to override the getters and setters of name,pathName variables since no modification Polymorphime is guaranteed
    void display(ostream & out) const {
        Multimedia::display(out);
        out << "length:" << length <<  endl << "width" << width << endl ;
    }
};

#endif

