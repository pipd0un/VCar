#include "main/map.h"
#include <iostream>
#include <fstream>
#include <time.h>

// private
void Map::map_safeAlloc()
{
    xwall = (char **)malloc(size[0] * sizeof(char *));
    if (!xwall)
    {
        std::cerr << "Error alloca , bailing out ..\n";
        exit(-1);
    }

    for (int i = 0; i < size[0]; i++)
    {
        xwall[i] = (char *)malloc(size[1] * sizeof(char));
        if (!xwall[i]) /* If `malloc` failed */
        {
            for (int j = 0; j < i; j++) /* free previously allocated memory */
            {
                free(xwall[j]);
            }
            free(xwall);

            std::cerr << "Error, alloca couldnt completed, bailing out ..\n";
            exit(-1);
        }
    }
}
void Map::map_deAlloc()
{
    if (!xwall)
    {
        for (int i = 0; i < size[0]; i++)
        {
            if (!xwall[i])
            {
                free(xwall[i]);
            }
        }
        free(xwall);
    }
}

// public
void Map::config_manual(int ans)
{
    int term = 0;
    int points;
    int edge = size[0] * size[1];
    if (ans == 1)
    {
        while (1)
        {
            std::cout << "how many points you wanna change ? : ";
            std::cin >> points;
            if (ans >= edge || ans <= 0)
            {
                std::cout << "\nWrong input ..\n";
                std::cout << "> ";
            }
            else
            {
                break;
            }
        }
        while (term < points)
        {
            int i, j;
            std::cout << "Location[ ][ ] : ";
            std::cin >> i;
            std::cout << ",";
            std::cin >> j;
            std::cout << "\n";
            if (xwall[i][j] == ' ')
            {
                xwall[i][j] = '*';
            }
            else
            {
                xwall[i][j] = ' ';
            }

            term++;
        }
    }
    else if (ans == -1)
    {
        std::cout << "Okay, I wont config your map !\n";
    }
    std::cout << "Successfully configurated !\n";
}
int *Map::getSize()
{
    return size;
};
char **Map::get_map()
{
    return xwall;
}
Map *Map::getLaby()
{
    if (Laby == nullptr)
    {
        Laby = new Map();
    }
    return Laby;
};
void Map::setLaby()
{
    m_end[0] = 0;
    m_end[1] = 7;
    m_start[0] = 16;
    m_start[1] = 9;
    for (int i = 0; i < 17; i++)
    {
        for (int j = 0; j < 17; j++)
        {
            wall[i][j] = '*';
            if (i == 0)
            {
                if (j == 7)
                {
                    wall[i][j] = ' ';
                }
            }
            if (i == 1)
            {
                if (j != 8 && j != 0 && j != 16)
                {
                    wall[i][j] = ' ';
                }
            }
            if (i == 2)
            {
                if (j == 1 || j == 5 || j == 9 || j == 15)
                {
                    wall[i][j] = ' ';
                }
            }
            if (i == 3)
            {
                if (j != 0 && j != 2 && j != 6 && j != 10 && j != 16)
                {
                    wall[i][j] = ' ';
                }
            }
            if (i == 4)
            {
                if (j == 1 || j == 3 || j == 7 || j == 11)
                {
                    wall[i][j] = ' ';
                }
            }
            if (i == 5)
            {
                if (j != 0 && j != 2 && j != 8 && j != 10 && j != 12 && j != 16)
                {
                    wall[i][j] = ' ';
                }
            }
            if (i == 6)
            {
                if (j == 3 || j == 9 || j == 11 || j == 13 || j == 15)
                {
                    wall[i][j] = ' ';
                }
            }
            if (i == 7)
            {
                if (j != 0 && j != 8 && j != 10 && j != 12 && j != 14 && j != 16)
                {
                    wall[i][j] = ' ';
                }
            }
            if (i == 8)
            {
                if (j == 1 || j == 5 || j == 9 || j == 11 || j == 15)
                {
                    wall[i][j] = ' ';
                }
            }
            if (i == 9)
            {
                if (j != 0 && j != 4 && j != 16 && j != 10)
                {
                    wall[i][j] = ' ';
                }
            }
            if (i == 10)
            {
                if (j == 1 || j == 3 || j == 5 || j == 11 || j == 13)
                {
                    wall[i][j] = ' ';
                }
            }
            if (i == 11)
            {
                if (j != 0 && j != 2 && j != 4 && j != 6 && j != 12 && j != 16)
                {
                    wall[i][j] = ' ';
                }
            }
            if (i == 12)
            {
                if (j == 5 || j == 3 || j == 15)
                {
                    wall[i][j] = ' ';
                }
            }
            if (i == 13)
            {
                if (j != 0 && j != 14 && j != 4 && j != 6 && j != 12 && j != 16)
                {
                    wall[i][j] = ' ';
                }
            }
            if (i == 14)
            {
                if (j == 1 || j == 7 || j == 15 || j == 11 || j == 13)
                {
                    wall[i][j] = ' ';
                }
            }
            if (i == 15)
            {
                if (j != 0 && j != 8 && j != 16 && j != 12)
                {
                    wall[i][j] = ' ';
                }
            }
            if (i == 16)
            {
                if (j == 9)
                {
                    wall[i][j] = ' ';
                }
            }
        }
    }
};
Map *Map::show_map()
{
    int i, j;
    for (i = 0; i < 17; i++)
    {
        std::cout << "|  ";
        for (j = 0; j < 17; j++)
        {
            std::cout << wall[i][j] << "  ";
        }
        std::cout << "|" << i << "\n";
    }
    return this;
};
int *Map::get_start_loc()
{
    return m_start;
}
Map *Map::Render(int location[])
{
    wall[location[0]][location[1]] = 'V';
    return this;
}
int *Map::get_end_loc()
{
    return m_end;
}
char Map::getBlocks(int i, int j)
{
    return wall[i][j];
}
void Map::clean_map()
{
    for (int i = 0; i < 17; i++)
    {
        for (int j = 0; j < 17; j++)
        {
            if (wall[i][j] == 'V')
            {
                wall[i][j] = ' ';
            }
        }
    }
}

//redesigneds
void Map::setLabyFromScheme()
{
    // size[2] = {i,j};
    char ch;
    int row = 0;
    int col = 0;

    std::ifstream in;
    in.open("Data/LabScheme.txt");
    while (in.get(ch))
    {
        col++;
        if (ch == '\n')
        {
            row++;
            col--;
        }
    };
    col = col / row;
    in.close();
    size = (int *)malloc(2 * sizeof(int));
    size[0] = row;
    size[1] = col;
    map_safeAlloc();
    in.open("Data/LabScheme.txt");
    if (in.is_open())
    {
        for (int i = 0; i < size[0]; i++)
        {
            for (int j = 0; j < size[1]; j++)
            {
                in >> xwall[i][j];
                if (xwall[i][j] == '0')
                {
                    xwall[i][j] = ' ';
                }
                if (i == 0 && xwall[i][j] == ' ')
                {
                    m_end[0] = i;
                    m_end[1] = j;
                }
                if (i == size[0] - 1 && xwall[i][j] == ' ')
                {
                    m_start[0] = i;
                    m_start[1] = j;
                }
            }
        }
    }
    else
    {
        std::cout << "Folder can not open...";
        std::cin.get();
    }
    in.close();
}
char Map::_getBlocks(int i, int j)
{
    //std::cout << "istenen : " << i << "ve " << j << "\n";
    if (i < 0 || i >= size[0] || j < 0 || j >= size[1])
    {
        return '*';
    }
    else
    {
        return xwall[i][j];
    }
}
void Map::generateLab()
{
    srand(time(0));
    //int randNum = rand()%(max-min + 1) + min;
    size = (int *)malloc(2 * sizeof(int));
    size[0] = rand() % (25 - 10 + 1) + 10;
    size[1] = rand() % (25 - 10 + 1) + 10;
    map_safeAlloc();
    m_end[0] = 0;
    m_end[1] = rand() % ((size[1] - 1 - 1) - 1 + 1) + 1;
    m_start[0] = size[0] - 1;
    m_start[1] = rand() % ((size[1] - 1 - 1) - 1 + 1) + 1;

    // first randomizing ..
    for (int i = 0; i < size[0]; i++)
    {
        for (int j = 0; j < size[1]; j++)
        {
            rand() % 2 == 0 ? xwall[i][j] = ' ' : xwall[i][j] = '*';
            if (i == 0 || j == 0 || i == size[0] - 1 || j == size[1] - 1)
            {
                xwall[i][j] = '*';
            }
        }
    }
    xwall[m_end[0]][m_end[1]] = ' ';
    xwall[m_start[0]][m_start[1]] = ' ';
}
void Map::show_xmap(int *loc)
{
    int i, j;
    std::cout << "\n   ";
    for (int l = 0; l < size[1]; l++)
    {
        if (l >= 9)
        {
            std::cout << l << " ";
        }
        else
        {
            std::cout << l << "  ";
        }
    }
    std::cout << "\n";
    // 24 + 25*3 +
    // 12 + 11*2 + 6
    for (int l = 0; l < (size[1] + (size[1] - 1) * 2 + 6); l++)
    {
        std::cout << "_";
    }
    std::cout << "\n";

    for (i = 0; i < size[0]; i++)
    {
        std::cout << "\n|  ";
        for (j = 0; j < size[1]; j++)
        {
            if (i == loc[0] && j == loc[1])
            {
                std::cout << "V  ";
            }
            else
            {
                std::cout << xwall[i][j] << "  ";
            }
        }
        std::cout << "|" << i << "\n";
    }
};
void Map::show_xmap()
{
    int i, j;
    std::cout << "\n   ";
    for (int l = 0; l < size[1]; l++)
    {
        if (l >= 9)
        {
            std::cout << l << " ";
        }
        else
        {
            std::cout << l << "  ";
        }
    }
    std::cout << "\n";
    // 24 + 25*3 +
    // 12 + 11*2 + 6
    for (int l = 0; l < (size[1] + (size[1] - 1) * 2 + 6); l++)
    {
        std::cout << "_";
    }
    std::cout << "\n";

    for (i = 0; i < size[0]; i++)
    {
        std::cout << "\n|  ";
        for (j = 0; j < size[1]; j++)
        {
            std::cout << xwall[i][j] << "  ";
        }
        std::cout << "|" << i << "\n";
    }
}
inline Map *Map::Laby;
