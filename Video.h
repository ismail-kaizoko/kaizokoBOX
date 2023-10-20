#ifndef VIDEO_HH
#define VIDEO_HH
#include "Multimedia.h"


class Video: public Multimedia{
    private:
    float duration;

    public:
    Video() : Multimedia(), duration(0) {}
    Video(string name, string pathName, int d) : Multimedia(name, pathName),duration(d) {}
    
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
