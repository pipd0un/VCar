#ifndef MAP_H
#define MAP_H

#include <stdio.h>

class Map {
    public :
        static Map& getLaby(){
            return Laby ;
        };
        void setLaby(){
            m_end[0] = 0;
            m_end[1] = 7;
            m_start[0] = 15;
            m_start[1] = 9;
            for(int i=0;i<17;i++){
                for(int j=0;j<17;j++){
                    wall[i][j] = '*';
                    if(i==0){
                        if(j==7){
                            wall[i][j] = ' ';
                        }
                    }
                    if(i==1){
                        if(j!=8 && j!=0 && j!=16){
                            wall[i][j] = ' ';
                        }
                    }
                    if(i==2){
                        if(j==1 || j==5 || j==9 || j==15){
                            wall[i][j] = ' ';
                        }
                    }
                    if(i==3){
                        if(j!=0 && j!=2 && j!=6 && j!=10 && j!=16){
                            wall[i][j] = ' ';
                        }
                    }
                    if(i==4){
                        if(j==1 || j==3 || j==7 || j==11){
                            wall[i][j] = ' ';
                        }
                    }
                    if(i==5){
                        if(j!=0 && j!=2 && j!=8 && j!=10 && j!=12 && j!=16){
                            wall[i][j] = ' ';
                        }
                    }
                    if(i==6){
                        if(j==3 || j==9 || j==11 || j==13 || j==15){
                            wall[i][j] = ' ';
                        }
                    }
                    if(i==7){
                        if(j!=0 && j!=8 && j!=10 && j!=12 && j!=14 && j!=16){
                            wall[i][j] = ' ';
                        }
                    }
                    if(i==8){
                        if(j==1 || j==5 || j==9 || j==11 || j==15){
                            wall[i][j] = ' ';
                        }
                    }
                    if(i==9){
                        if(j!=0 && j!=4 && j!=16 && j!=10){
                            wall[i][j] = ' ';
                        }
                    }
                    if(i==10){
                        if(j==1 || j==3 || j==5 || j==11 || j==13){
                            wall[i][j] = ' ';
                        }
                    }
                    if(i==11){
                        if(j!=0 && j!=2 && j!=4 && j!=6 && j!=12 && j!=16){
                            wall[i][j] = ' ';
                        }
                    }
                    if(i==12){
                        if(j==5 || j==3 || j==15){
                            wall[i][j] = ' ';
                        }
                    }
                    if(i==13){
                        if(j!=0 && j!=14 && j!=4 && j!=6 && j!=12 && j!=16){
                            wall[i][j] = ' ';
                        }
                    }
                    if(i==14){
                        if(j==1 || j==7 || j==15 || j==11 || j==13){
                            wall[i][j] = ' ';
                        }
                    }
                    if(i==15){
                        if(j!=0 && j!=8 && j!=16 && j!=12){
                            wall[i][j] = ' ';
                        }
                    }
                    if(i==16){
                        if(j==9){
                            wall[i][j] = ' ';
                        }
                    }
                }
            }
        };
        Map& show_map(){
            int i,j;
            printf("----------------------------------------------------\n");
            for(i=0;i<17;i++){
                printf("|  ");
                for(j=0;j<17;j++){
                    printf("%c  ",wall[i][j]);
                }
                printf("|%d\n",i);
            }
            printf("----------------------------------------------------\n");
            return *this;
        };
        int* get_start_loc(){
            return m_start;
        }
        void Render(int location[]){
            int car_point[2];
            car_point[0] = location[0];
            car_point[1] = location[1];
            wall[car_point[0]][car_point[1]] = 'V';
        }
        int* get_end_loc(){
            return m_end;
        }
        char getBlocks(int i ,int j){
            return wall[i][j];
        }
        void clean_map(){
            for(int i=0;i<17;i++){
                for(int j=0;j<17;j++){
                    if(wall[i][j] == 'V'){
                        wall[i][j] = ' ';
                    }
                }
            }
        }
    private :
        Map(){};
        static Map Laby;
        char wall[17][17];
        int m_start[2];
        int m_end[2];
};

inline Map Map::Laby;
#endif 