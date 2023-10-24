#ifndef DATASET_HH
#define DATASET_HH

#include "Multimedia.h"
#include <map>
#include <memory>

class dataset {

    private:
    std::map<std::string , shared_ptr<Multimedia> > datasetMultimedia ;
    std::map<std::string , shared_ptr<Multimedia> > datasetGroup;


    
};


#endif