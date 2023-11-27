#ifndef MEDIAMASTER_HH
#define MEDIAMASTER_HH

#include "Picture.h"
#include "Video.h"
#include "Picture.h"
#include "Film.h"
#include "Group.h"

#include <map>
#include <memory>

class MediaMaster {

    private:
    std::map<std::string , shared_ptr<Multimedia> > datasetMultimedia ;
    std::map<std::string , shared_ptr<Group> > datasetGroup;


    public:
    MediaMaster(){}


    bool isExistMultimedia(std::string name){
        auto check = this->datasetMultimedia.find(name);
        if ( check != this->datasetMultimedia.end() ){ 
            return true;
        }
        return false;




    }

    bool isExistGroup(std::string name){
        auto check = this->datasetGroup.find(name);
        if ( check != this->datasetGroup.end() ){ 
            return true;
        }
        return false;

        

    } 


    std::shared_ptr<Picture> createPicture(std::string name, std::string pathName, int l, int w){
        
        if (isExistMultimedia(name) == true){
            std::cerr << "This name already exists" ;
            return nullptr;
        } 

        else{ 
        std::shared_ptr<Picture> pic( new Picture( name, pathName, l, w) );
        this->datasetMultimedia[name] = pic ;
        return pic;
        }
    }  

    
    std::shared_ptr<Video> createVideo(std::string name, std::string pathName, int d){

        if (isExistMultimedia(name) == true){
            std::cerr << "This name already exists" ;
            return nullptr;
        } 

        else{   
            std::shared_ptr<Video> vid(new Video(name, pathName, d));
            this->datasetMultimedia[name] = vid;
            return vid;  
        } 

    }


        std::shared_ptr<Film> createFilm(std::string name, std::string pathName, float duration, int n, int * tab ){

        if (isExistMultimedia(name) == true){
            std::cerr << "This name already exists" ;
            return nullptr;
        } 

        else{   
            std::shared_ptr<Film> film( new Film(name, pathName, duration,  n, tab ));
            this->datasetMultimedia[name] = film;
            return film;  
        } 
    }

    std::shared_ptr<Group> createGroup(std::string name) {

        if (isExistGroup(name) == true){
            std::cerr << "This name already exists" ;
            return nullptr;
        } 

        else{ 
            std::shared_ptr<Group> group(new Group()) ;
            this->datasetGroup[name] = group;
            return group;
        }  
    }
 
    
    void displayMultimedia(std::string name, ostream & out){
        auto check = this->datasetMultimedia.find(name);
        if ( check != this->datasetMultimedia.end() ){ 
            std::cerr << "No such Multimedia object registered under this name!" ;
        } 
        else{
            check->second->display(out);
        } 

    }

    void displayGroup(std::string name , ostream & out){
        auto check = this->datasetGroup.find(name);
        if ( check != this->datasetGroup.end() ){ 
            std::cerr << "No such Multimedia object registered under this name!" ;
        } 
        else{
            check->second->display(out);
        } 
    } 

    void playMultimedia(std::string name){
        auto check = this->datasetMultimedia.find(name);
        if ( check != this->datasetMultimedia.end() ){ 
            std::cerr << "No such Multimedia object registered under this name!" ;
        } 
        else{
            std::cout << "PLaying ...";
            check->second->play();
        } 

    }

    bool addMultimediaToGroup(std::string nameMultimedia, std::string nameGroup){
        auto it1 = datasetMultimedia.find(nameMultimedia);
        if ( it1 == this->datasetMultimedia.end() ){ 
            std::cerr << "No such Multimedia object registered under this name!" ;
            return false;
        } 
        
        auto it2      = datasetGroup.find(nameGroup);
        if ( it2 == this->datasetGroup.end() ){ 
            std::cerr << "No such Multimedia object registered under this name!" ;
            return false;
        }

        auto MultimediaObject = it1->second ;
        auto GroupObject = it2->second ;

        GroupObject->push_back(MultimediaObject) ;
        return true;




        
    }  
};


#endif