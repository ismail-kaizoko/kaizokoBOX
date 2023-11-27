#ifndef FILM_HH
#define FILM_HH

#include "Video.h"

class Film : public Video{
    friend class MediaMaster;

    private:
    int chapterNumber{};   //  we store the array length to make implementations easier
    int *chapters{} ;


    protected:
    //constructor and destructor implementation 
    //Constructors are set preotected to be private outside,in order to enable access rights outside the class Dataset, but be able to be implemented by subclasses
    Film() : Video(), chapterNumber(0), chapters(nullptr){};
    Film(string name, string pathName, float duration, int n, int * tab ): 
                Video(name, pathName, duration) {setChapters(n, tab);}


    
    public:
    ~Film() {delete[] chapters;}  // necessity to implement the destructor since the instance variable is allocated in the heap

    //getters and setters implementation
    void setChapters(int n, const int * tab){
        //Check the preconditions
        if (n<=0){
            cerr << "impossible to set an array with null elements" ;
        }

        if ( tab == nullptr){
            cerr << "impossible to set an array with null elements" ;
        }

        delete[] chapters;      //it's necessary to delete the previous chapter dynamically since it is no longer used
        chapterNumber = n;
        chapters = new int[n];

        for (int i=0; i<n; i++){
            chapters[i] = tab[i];
        }


    }

    int getChapterNumber()      const {return chapterNumber;}
    const int * getChapters()   const {return chapters;}    //return a constant pointer to prevent modification outside the class, while the copy is always is up to date 

    void display(ostream & out) const {
        Video::display(out) ;
        out << "chapter number" << chapterNumber << endl ;
    }



};




#endif