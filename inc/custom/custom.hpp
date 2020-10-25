#ifndef CUSTOM_HPP
#define CUSTOM_HPP

#include <fstream>
namespace Lub{
    namespace Io{
        class CSV {
            public :
                void seek(int&,int[2],int);
                static CSV* create();
                void clean();
                void create_stack_buff(int);
                ~CSV();
            protected :
                CSV();
                static CSV* creator; 
                std::fstream fout;
        };
    }
}


#endif //:
