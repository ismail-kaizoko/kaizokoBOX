#ifndef VIDEO_HH
#define VIDEO_HH
#include "Multimedia.h"


class Video: public Multimedia{
    friend class MediaMaster;

    
    private:
    float duration;

    protected:
    //Constructors are set preotected to be private outside,in order to enable access rights outside the class Dataset, but be able to be implemented by subclasses
    Video() : Multimedia(), duration(0) {}
    Video(string name, string pathName, int d) : Multimedia(name, pathName),duration(d) {}

    public:

    void setDuration(float duration) {this->duration = duration;}
    float getDuration()  const {return duration;}

    void play() const override { 
        string path = this->getPathName();
        system( ("mpv " + path + " &").data() );
        }
    
    void diplay(ostream & out) const{
        Multimedia::display(out);
        out << "duration : " << duration << endl ;

    }

    
};

#endif
