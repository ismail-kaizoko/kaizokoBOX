
#include "Film.h"
#include "Picture.h"
#include "Group.h"

#include <iostream>

using VideoSmartSPtr   = std::shared_ptr<Video>;
using PictureSmartSPtr = std::shared_ptr<Picture>;
using FilmSmartSPtr    =std::shared_ptr<Film>;



void display(int n, const int * tab);


int main(int argc, const char* argv[])
{
    std::cout << "Hello brave new world" << std::endl;

    //tester le polymorphisme
    /* 
    Multimedia ** medias = new Multimedia * [3];
    medias[0] = new Picture("cpp_pic", "/home/ismail/Pictures/cpp_pic.png", 256, 256);
    medias[1] = new Video("lana", "/home/ismail/Videos/video.mp4", 30);
    medias[2] = new Picture("pic2", "/home/ismail/Pictures/lana.jpg", 255, 255);

    for (int i =0; i<3; i++){

        medias[i]->play();
        
    }

    */

    // tester le copyage
    /*
    int duration[5] = {0,7,10,15,20};
    int * duration2 = new int[5]{0,1,4,7,15};

    Film * film = new Film("x", "/homr/x.mkv", 20, 5, duration );

    const int * copy = film->getChapters();
    int durationCopy = film->getChapterNumber();

    display(durationCopy, copy);
    film->setChapters(durationCopy, duration2);
    display(durationCopy, copy);
    delete[] duration2;
    delete[] film;
    display(durationCopy, copy);
*/

    int duration[5] = {0,7,10,15,20};
    FilmSmartSPtr film(new Film("movie", "/home/movie.mkv", 20, 5, duration) ) ;

    PictureSmartSPtr pic1(new Picture("cpp_pic", "/home/ismail/Pictures/cpp_pic.png", 256, 256) );
    PictureSmartSPtr pic2(new Picture("pic2", "/home/ismail/Pictures/lana.jpg", 255, 255) ); 
    VideoSmartSPtr   vid(new Video("lana", "/home/ismail/Videos/video.mp4", 30) ); 

    Group * videos = new Group();
    videos->push_back(film);
    videos->push_back(vid);

    Group * dataset = new Group();
    dataset->push_back(film);
    dataset->push_back(pic1);
    dataset->push_back(pic2);
    dataset->push_back(vid);

    Group * pics = new Group();
    pics->push_back(pic1);
    pics->push_back(pic2);


    videos->display(cout);
    dataset->display(cout);
    pics->display(cout);

    // test the smart pointer. 

    videos->pop_back();
    dataset->pop_back();

    //At this stage: the object 'vid' is pointed with no smartpointer, he must have been died then (verified with the destructor)





    


    




    
    return 0;

}


void displayTab(int n, const int * tab){

    for(int i = 0; i<n; i++){
        cout << tab[i] << " - ";
    } 
    cout << "fin";
    cout << endl;
    cout << endl;
    

}