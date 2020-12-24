#ifndef MAP_H
#define MAP_H

class Map
{
public:
    void setLabyFromScheme();
    void map_safeAlloc(int*);
    void show_xmap(int*);
    void show_xmap();
    void generateLab();
    int *getSize();
    void config_manual(int);

    static Map *getLaby();
    char **get_map();
    void setLaby();
    Map *show_map();
    int *get_start_loc();
    Map *Render(int location[]);
    int *get_end_loc();
    char getBlocks(int i, int j);
    void clean_map();
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

private:
    Map(){};
    static Map *Laby;
    char wall[17][17];
    char **xwall; // xwall[size[0]][size[1]];
    int *size;
    int m_start[2];
    int m_end[2];
};

#endif