#ifndef PICTURE_HH
#define PICTURE_HH

#include "Multimedia.h"




class Picture : public Multimedia {
    friend class MediaMaster;

    
    private:
    float length{}, width{};

    protected:
    //Constructors are set preotected to be private outside,in order to enable access rights outside the class Dataset, but be able to be implemented by subclasses
    Picture() : Multimedia(),length(0),width(0) {};
    Picture(string name, string pathName, int l, int w) : Multimedia(name, pathName),length(l),width(w){}

    public:

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

