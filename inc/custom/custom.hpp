#ifndef CUSTOM_HPP
#define CUSTOM_HPP

#include <iostream>

namespace Io
{
    class File
    {
    public:
        void generateScheme(char **, int *);
        void cleanScheme();
        ~File() { delete creator; };
        void seek(int &, int[2], int,std::string);
        static File *getFile();
        int howManyMovesInFile(std::string);
        void set_path(std::string);

    protected:
        File(){};
        std::string m_path;
        static File *creator;
    };

    int ask_config();
}; // namespace Io
namespace Memory
{
    class Rotation
    {
    public:
        Rotation(int mov, std::string name)
            : m_mov(mov)
        {
            m_path = "bin/" + name + ".txt";
        };
        ~Rotation();
        
        void get();    // (D)
        void optimise();

    private:                  // private functions
        void create(); // (D)
        void rot_safeAlloc(); // (D)
        int **any_safeAlloc(int);
        void clean_rot();
        void clean_rot(int **, int);
        int **fill_rot_buffer(int **buff, int size, int part1, int part2);
        void rot_fillBack(int **, int);
        bool is_optimised();  // (D) ...
        void semi_optimise(); // (D) ...

    private:
        int m_mov;
        std::string m_path;
        int **m_rot;
        bool isOptimised = 0;
    };
}; // namespace Memory

#endif //:
