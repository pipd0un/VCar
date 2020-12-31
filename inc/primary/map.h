#ifndef MAP_H
#define MAP_H

class Car;
class Map
{
public:
    bool isAnyOneFinishes();
    void show_race(Car*[],int);
    void show_map(Car);
    void show_map();
    void generateLabyFromScheme();
    void generateLab();
    int *getSize();

    static Map *getLaby();
    char **get_map();
    int *get_start_loc();
    int *get_end_loc();
    ~Map()
    {
        delete Laby;
        map_deAlloc();
        delete size;
    };
    char _getBlocks(int, int);
private:
    void map_safeAlloc();
    void map_deAlloc();
    int dig2closer(int,int);
    int cross_dig2closer(int,int);
    void auto_config();

private:
    Map(){};
    static Map *Laby;
    char **xwall; // xwall[size[0]][size[1]];
    int *size;
    int m_start[2];
    int m_end[2];
    bool anyOneFinishes;
};

#endif