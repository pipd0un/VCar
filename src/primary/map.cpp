#include "primary/map.h"
#include <iostream>
#include <fstream>
#include <time.h>
#include "primary/car.h"

// private
int Map::cross_dig2closer(int y, int x)
{
    int diff;
    int length = 1000;
    int holes = 0;
    for (int i = 0; i < size[0]; i++)
    {
        if (xwall[y][i] == ' ')
        {
            holes++; // it counts ' ' in laby
        };
    }
    if (holes >= 1)
    {
        for (int i = 0; i < size[0]; i++)
        {
            if (xwall[y][i] == ' ')
            {
                if (m_end[1] > m_start[1])
                {
                    if (abs(x - i) <= length)
                    {
                        diff = x - i;
                        length = abs(x - i);
                    }
                }
                else
                {
                    if (abs(x - i) < length)
                    {
                        diff = x - i;
                        length = abs(x - i);
                    }
                }
            };
        }
    }
    else
    {
        xwall[y][x] = ' ';
        return x;
    }
    if (diff > 0)
    {
        for (int i = x; i >= x - (diff); i--)
        {
            xwall[y + 1][i] = ' ';
            //std::cout << "xwall[" << y + 1 << "][" << i << "] digged \n";
        }
    }
    else if (diff < 0)
    {
        for (int i = x; i <= x - (diff); i++)
        {
            xwall[y + 1][i] = ' ';
            //std::cout << "xwall[" << y + 1 << "][" << i << "] digged \n";
        }
    }
    return x - diff;
}
int Map::dig2closer(int y, int x)
{
    int diff;
    int length = 1000;
    int holes = 0;
    for (int i = 0; i < size[0]; i++)
    {
        if (xwall[y][i] == ' ')
        {
            holes++;
        };
    }
    if (holes >= 1)
    {
        for (int i = 0; i < size[0]; i++)
        {
            if (xwall[y][i] == ' ')
            {
                if (m_end[1] > m_start[1])
                {
                    if (abs(x - i) < length)
                    {
                        diff = x - i;
                        length = abs(x - i);
                    }
                }
                else
                {
                    if (abs(x - i) <= length)
                    {
                        diff = x - i;
                        length = abs(x - i);
                    }
                }
            };
        }
    }
    else
    {
        xwall[y][x] = ' ';
        return x;
    }
    if (diff > 0)
    {
        for (int i = x; i >= x - (diff); i--)
        {
            xwall[y - 1][i] = ' ';
            //std::cout << "xwall[" << y - 1 << "][" << i << "] digged \n";
        }
    }
    else if (diff < 0)
    {
        for (int i = x; i <= x - (diff); i++)
        {
            xwall[y - 1][i] = ' ';
            //std::cout << "xwall[" << y - 1 << "][" << i << "] digged \n";
        }
    }
    return x - diff;
};
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
void Map::auto_config()
{
    int x, y;
    x = m_end[1];
    y = m_end[0];

    // config
    // first way digging.
    xwall[m_end[0] + 1][m_end[1]] = ' ';
    xwall[m_start[0] - 1][m_start[1]] = ' ';

    while (y != m_start[0] - 2)
    {
        if (xwall[y + 2][x] == ' ')
        {
            //std::cout << "xwall[" << y + 2 << "][" << x << "] : clean ..\n";
            y++;
        }
        else if (xwall[y + 2][x] == '*')
        {
            //std::cout << "xwall[" << y + 2 << "][" << x << "] : should be dig ..\n";
            x = dig2closer(y + 2, x);
            //std::cout << "new x : " << x << "\n";
        }
    }
    // checking way to dig
    // cross digging
    std::cout << "started to cross digging ..."
              << "\n";

    x = m_start[1];
    y = m_start[0];

    while (y != m_end[0] + 2)
    {
        if (xwall[y - 2][x] == ' ')
        {
            //std::cout << "xwall[" << y - 2 << "][" << x << "] : clean ..\n";
            y--;
        }
        else if (xwall[y - 2][x] == '*')
        {
            //std::cout << "xwall[" << y - 2 << "][" << x << "] : should be dig ..\n";
            x = cross_dig2closer(y - 2, x);
            //std::cout << "new x : " << x << "\n";
        }
    }
    system("cls");
}

// public
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
int *Map::get_start_loc()
{
    return m_start;
}
int *Map::get_end_loc()
{
    return m_end;
}

//redesigneds also public
void Map::generateLabyFromScheme()
{
    map_deAlloc();
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
    anyOneFinishes = false;
    srand(time(0));
    //int randNum = rand()%(max-min + 1) + min;
    size = (int *)malloc(2 * sizeof(int));
    size[0] = rand() % (25 - 10 + 1) + 10;
    size[1] = rand() % (25 - 10 + 1) + 10;
    map_safeAlloc();
    m_end[0] = 0;                                        //y
    m_end[1] = rand() % ((size[1] - 1 - 1) - 1 + 1) + 1; //x
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
    auto_config();
}
void Map::show_race(Car *c[], int ct)
{

    int i, j;
    int count = 0;
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
            for (int count = 0; count < ct; count++)
            {
                if (i == c[count]->getLocale()[0] && j == c[count]->getLocale()[1])
                {
                    std::cout << c[count]->getShape() << "  ";
                }
                else
                {
                    std::cout << xwall[i][j] << "  ";
                }
            }
        }
        std::cout << "|" << i << "\n";
    }
    for (int count = 0; count < ct; count++)
    {
        if (c[count]->getLocale()[0] == m_end[0] && c[count]->getLocale()[1] == m_end[1])
        {
            std::cout << "Winner : " << c[count]->getName() << "\n";
            anyOneFinishes = true;
        }
        else
        {
            anyOneFinishes = false;
        }
    }
}
void Map::show_map(Car c)
{
    int i, j;
    int count = 0;
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
            if (i == c.getLocale()[0] && j == c.getLocale()[1])
            {
                std::cout << c.getShape() << "  ";
            }
            else
            {
                std::cout << xwall[i][j] << "  ";
            }
        }
        std::cout << "|" << i << "\n";
    }
}
void Map::show_map()
{
    int i, j;
    int count = 0;
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
bool Map::isAnyOneFinishes()
{
    return anyOneFinishes;
}
inline Map *Map::Laby;
