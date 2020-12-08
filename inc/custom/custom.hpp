#include <iostream>
#ifndef CUSTOM_HPP
#define CUSTOM_HPP

namespace Io
{
    class File
    {
    public:
        ~File() { delete creator; };
        void seek(int &, int[2], int);
        static File *getFile();
        int bring_line2mem();
        void set_path(std::string);

    protected:
        File(){};
        std::string m_path;
        static File *creator;
    };
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
        bool is_optimised();  // (D) ...
        void semi_optimise(); // (D) ...
        void create();        // (D)
        void get();           // (D)
    private:                  // private functions
        void rot_safeAlloc(); // (D)
        int **any_safeAlloc(int);
        void clean_rot();
        void clean_rot(int **, int);
        int **fill_rot_buffer(int **buff, int size, int part1, int part2);
        void rot_fillBack(int **, int);

    private:
        int m_mov;
        std::string m_path;
        int **m_rot;
        bool isOptimised = 0;
    };
}; // namespace Memory

#endif //:
