#ifndef MAP_H
#define MAP_H

class Map
{
public:
    void generateLab(); // working on this ..
    static Map *getLaby();
    void setLaby();
    Map *show_map();
    int *get_start_loc();
    Map *Render(int location[]);
    int *get_end_loc();
    char getBlocks(int i, int j);
    void clean_map();
    ~Map(){ delete Laby; };

private:
    Map(){};
    static Map *Laby;
    char wall[17][17];
    int m_start[2];
    int m_end[2];
};

#endif