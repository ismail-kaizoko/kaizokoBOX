#define SERVER_VERSION

#include <iostream>

#ifdef STANDARD_VERSION

#include "Film.h"
#include "Picture.h"
#include "Group.h"
#include "MediaMaster.h"

using VideoSmartSPtr = std::shared_ptr<Video>;
using PictureSmartSPtr = std::shared_ptr<Picture>;
using FilmSmartSPtr = std::shared_ptr<Film>;

void displayTab(int n, const int *tab);

int main(int argc, const char *argv[])
{
    std::cout << "Hello brave new world" << std::endl;

    // tester le polymorphisme
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

    */

    return 0;
}

void displayTab(int n, const int *tab)
{

    for (int i = 0; i < n; i++)
    {
        cout << tab[i] << " - ";
    }
    cout << "fin";
    cout << endl;
    cout << endl;
}
#endif

#ifdef SERVER_VERSION

#include <memory>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include "tcpserver.h"
#include "ccsocket.h"
#include "MediaMaster.h"

const int PORT = 3331;

enum Commands
{
    SEARCH_OBJECT,
    SEARCH_GROUP,
    PLAY_OBJECT,
    NOT_FOUND,
    QUIT
};

map<std::string, Commands> Possible_commands = {
    {"search_object", Commands::SEARCH_OBJECT},
    {"search_group", Commands::SEARCH_GROUP},
    {"play_object", Commands::PLAY_OBJECT},
    {"quit", Commands::QUIT},
};

Commands mapCommandRequests(std::string command)
{
    if (Possible_commands.find(command) != Possible_commands.end())
    {
        return Possible_commands[command];
    }
    else
    {
        return Commands::NOT_FOUND;
    }
}

/*

Think how to map the resuests and strings


*/

/*
....
....
Create your Dataset
...
...

*/

int main(int argc, char *argv[])
{

    MediaMaster *dataset = new MediaMaster();

    shared_ptr<Picture> pic1 = dataset->createPicture("Cpp", "../Cpp.png", 256, 256);
    shared_ptr<Picture> pic2 = dataset->createPicture("segFault", "../segFault.png", 256, 256);
 
    shared_ptr<Video> vid1 = dataset->createVideo("ocean", "../ocean.mp4", 30);
    shared_ptr<Video> vid2 = dataset->createVideo("nature", "/../nature.mp4", 30);
    
    int duration[5] = {0, 7, 10, 15, 20};
    shared_ptr<Film> film = dataset->createFilm("ocean", "../ocean.mp4", 20, 5, duration);
    shared_ptr<Group> group = dataset->createGroup("group");
    dataset->addMultimediaToGroup("Cpp" , "group");

    auto *server = new TCPServer([&](std::string const &request, std::string &response)
                                 {
            // the request sent by the client to the server
        std::cout << "request: " << request << std::endl ;

        std::istringstream iss(request);
        std::vector<std::string> words;
        std::string word;

        while(iss >> word){
            words.push_back(word);
        } 

        if(words.size() != 2){
            response = "Invalid Request format: PLease check the Guide Book!";
            return true;}

        std::string command = words[0] ;
        std::string object  = words[1] ;

        if( dataset->isExistGroup(object) == false && dataset->isExistMultimedia(object)== false ){
            response = "There is no such Multimedia object nor a Group registered under this name !";
            return true;
        } 
        


        std::stringstream stream = stringstream();


        switch (mapCommandRequests(command)){

            case Commands::SEARCH_OBJECT:{
                dataset->displayMultimedia(object, stream);
                response = stream.str();
                break; 
                }
            case Commands::SEARCH_GROUP : {
                dataset->displayGroup(object, stream);
                response = stream.str();
                break;
            }

            case Commands::PLAY_OBJECT :{
                response = "Playing...";
                dataset->playMultimedia(object);
                break;
            }  

            case Commands::QUIT : {
                response  = "Quitting ...";
                return false;

            } 
            default:
                response = "Command not found among possible commands, please check the Guide Book!";
                break;
        } } );

    int status = server->run(PORT);

    // en cas d'erreur
    if (status < 0)
    {
        std::cerr << "Could not start Server on port " << PORT << std::endl;
        return 1;
    }

    return 0;
}
#endif
