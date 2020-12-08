#include "custom/custom.hpp"
#include "car.h"
#include <fstream>
#include <cstdlib>

namespace Io
{
    int File::bring_line2mem()
    {
        // open the doc and count lines
        std::ifstream in;
        std::string line;
        int ct = 0; // line count;

        in.open(m_path);
        while (getline(in, line))
        {
            ct++;
        };
        in.close();
        return ct;
    }
    void File::set_path(std::string name)
    {
        m_path = "bin/" + name + ".txt";
    }
    File *File::getFile()
    {
        if (!creator)
        {
            creator = new File();
        }
        return creator;
    }
    void File::seek(int &ct, int locale[2], int way)
    {
        std::ofstream fout;
        // opens an existing csv file or creates a new file.

        fout.open(m_path, std::ofstream::app);
        if (fout.is_open())
        {
            // Insert the data to file
            fout << ct << " "
                 << locale[0] << " "
                 << locale[1] << " "
                 << way << "\n";
        }
        else
        {
            std::cout << "Folder can not open...";
            std::cin.get();
        }
        fout.close();
    };
    inline File *File::creator;
}; // namespace Io
namespace Memory
{
    Rotation::~Rotation()
    {
        clean_rot();
        if (remove(m_path.c_str()) != 0)
            std::cerr << "File deletion failed";
        else
            std::cout << "Resource cleaned successfully";
    };
    void Rotation::create()
    {
        rot_safeAlloc();
        // read line by line and save values to mem;
        std::ifstream in;
        in.open(m_path);
        if (!in.is_open())
        {
            std::cerr << "error to open reading\n";
            std::cin.get();
        }
        else
        {
            for (int i = 0; i < m_mov; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    in >> m_rot[i][j];
                }
            }
        }
        in.close();
        std::cout << "Rotation is ready to optimise now !\n";
    };
    void Rotation::get()
    {
        for (int i = 0; i < m_mov; i++)
        {
            std::cout << "Line : ";
            std::cout << m_rot[i][0] << ", " << m_rot[i][1] << ", " << m_rot[i][2] << ", " << m_rot[i][3];
            std::cout << "\n";
        }
    };
    bool Rotation::is_optimised()
    {
        if (isOptimised == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // private funcs
    void Rotation::rot_safeAlloc()
    {
        m_rot = (int **)malloc(m_mov * sizeof(int *));
        if (!m_rot)
        {
            std::cerr << "Error alloca , bailing out ..\n";
            exit(-1);
        }

        for (int i = 0; i < m_mov; i++)
        {
            m_rot[i] = (int *)malloc(4 * sizeof(int));
            if (!m_rot[i]) /* If `malloc` failed */
            {
                for (int j = 0; j < i; j++) /* free previously allocated memory */
                {
                    free(m_rot[j]);
                }
                free(m_rot);

                std::cerr << "Error, alloca couldnt completed, bailing out ..\n";
                exit(-1);
            }
        }
    }
    int **Rotation::any_safeAlloc(int size)
    {
        // ..
        int **anyRot;
        int alloc_mem = 0;
        anyRot = (int **)malloc(size * sizeof(int *));
        if (!anyRot)
        {
            std::cerr << "Error alloca of any rotation, bailing out ..\n";
            exit(-1);
        }

        for (int i = 0; i < size; i++)
        {
            anyRot[i] = (int *)malloc(4 * sizeof(int));
            alloc_mem += sizeof(anyRot[i]);
            if (!anyRot[i]) /* If `malloc` failed */
            {
                for (int j = 0; j < i; j++) /* free previously allocated memory */
                {
                    free(anyRot[j]);
                }
                free(anyRot);

                std::cerr << "Error, alloca couldnt completed for any rotation, bailing out ..\n";
                exit(-1);
            }
        }
        std::cout << "size of buff : " << alloc_mem << "\n";
        return anyRot;
    };
    void Rotation::clean_rot()
    {
        if (!m_rot)
        {
            for (int i = 0; i < m_mov; i++)
            {
                if (!m_rot[i])
                {
                    free(m_rot[i]);
                }
            }
            free(m_rot);
        }
    }
    void Rotation::clean_rot(int **buff, int size)
    {
        for (int i = 0; i < size; i++)
        {
            if (!buff[i])
            {
                free(buff[i]);
            }
        }
        free(buff);
    }
    int **Rotation::fill_rot_buffer(int **buff, int size, int part1, int part2)
    {
        // part1 -> i , part2 -> j+1
        for (int i = 0; i < part1; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                buff[i][j] = m_rot[i][j];
            }
        };
        for (int i = part1; i < size; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                buff[i][j] = m_rot[part2][j];
            }
            part2++;
        }
        for (int i = 0; i < size; i++)
        {
            buff[i][0] = i + 1;
        }
        return buff;
    }
    void Rotation::rot_fillBack(int **buff, int size)
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                m_rot[i][j] = buff[i][j];
            }
        }
    };
    void Rotation::semi_optimise()
    {
        int i, j, newSize = 0, broken = 0;
        int **buff_mov = nullptr;
        for (i = 0; i < m_mov; i++)
        {
            for (j = m_mov - 1; j >= i; j--)
            {
                if (m_rot[i][1] == m_rot[j][1] && m_rot[i][2] == m_rot[j][2])
                {
                    if (i != j)
                    {
                        std::cout << "\n"  << m_rot[i][0] << "," << m_rot[i][1] << "," << m_rot[i][2] << "," << m_rot[i][3]
                                  << " = " << m_rot[j][0] << "," << m_rot[j][1] << "," << m_rot[j][2] << "," << m_rot[j][3] << "\n";
                        std::cout << "Reduced move counts : " << j - i << "\n";
                        newSize = m_mov - (j - i);
                        std::cout << "new Move count : " << newSize << "\n";
                        buff_mov = any_safeAlloc(newSize);                   // alloca mem
                        buff_mov = fill_rot_buffer(buff_mov, newSize, i, j); //// main factor . It filles buffer with reduced moves
                        broken = 1;
                    }
                    break;
                }
            }
            if (broken)
            {
                break;
            }
        }
        clean_rot();
        rot_safeAlloc();
        rot_fillBack(buff_mov, newSize);
        if (buff_mov != nullptr)
        {
            clean_rot(buff_mov, newSize);
        }
        std::cout << "semi optimise done!\n\n";
        if (newSize == m_mov)
        {
            isOptimised = 1;
        }
        m_mov = newSize;
    }; // on here..
};     // namespace Memory
