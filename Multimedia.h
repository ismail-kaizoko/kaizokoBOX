#ifndef MULTIMEDIA_HH
#define MULTIMEDIA_HH
#include <iostream>
#include <string> 



using namespace std;
 
class Multimedia {
    friend class MediaMaster;



    private:
    string name{};
    string pathName{};

    protected:
    //constructors and destructor declaration
    Multimedia();
    Multimedia(string name, string pathName);
    virtual ~Multimedia();  //necessity of virtual to activate the dynamic linking
    // They are in private in order to give Access rights to the class : Dataset 

    public:
    //setters and getters declaration
    void setName(string name);
    void setPathName(string pathName);
    string getName() const;
    string getPathName() const;

    //other methods declaration
    virtual void display(ostream &out) const;

    virtual void play() const = 0;  //méthode abstraite (car elle n'est pas défnie dans Multimedia.cpp)

};

#endif // MULTIMEDIA_HH