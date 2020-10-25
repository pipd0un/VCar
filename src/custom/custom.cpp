#include "custom/custom.hpp"
#include "car.h"
#include <iostream>


namespace Lub {
    namespace Io {
        CSV::CSV(){};
        CSV::~CSV(){};
        void CSV::clean(){
            delete creator;
        }
        CSV* CSV::create(){
            if(!creator){
                creator = new CSV();
            }
            return creator;
        }
        void CSV::seek(int &ct,int locale[2],int way){

            // opens an existing csv file or creates a new file. 
            fout.open("bin/Resource/route.csv", std::ios::out | std::ios::app);
    
            // Insert the data to file 
            fout    << ct        << ", "
                    << locale[0] << ", "
                    << locale[1] << ", "
                    << way      << "\n";
            fout.close();
        }
        CSV* CSV::creator;
    }
}

