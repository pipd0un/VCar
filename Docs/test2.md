- If you want to create labyrinth handmade
** then you should create a file  :
``` Data/LabScheme.txt ```
- and put inside like       <br/>
``` ***************0****``` <br/>
``` *0*00000*000**00*00*``` <br/>
``` *0**0000*0000000****``` <br/>
``` *00***00000*0***000*``` <br/>
``` *0**000*0**0***0****``` <br/>
``` *0000***0*000*0***0*``` <br/>
``` ***0000000000000*0**``` <br/>
``` **00000000**00**0***``` <br/>
``` **0*0****000**00****``` <br/>
``` **********0*********``` 

** zeros are roads that makes available to go for your car
** asterics are walls

- Creating a rotation within a travel ;
** You should create Io reminder
``` Io::File::getFile()->set_path( car1.getName() ); ```
** then can seek the moves
``` int counter = 0; ```
``` while ( Map::getLaby()->isAnyOneFinishes()){ ```
``` SetCursorPosition(0, 0); ``` 
``` car._push(Map::getLaby()); ```
``` counter++; ```
``` Map::getLaby()->show_map(car1); ```
``` Io::File::getFile()->seek( ct , car1->getLocale() , car1->getName()  ); ```
```} ```

- after all the turn comes optimisation
** You can optimise the rotation with a couple lines
``` Memory::Rotation rotation = Memory::Rotation( Io::File::getFile()->howManyMovesInFile() , car1->getName() ); ```
``` rotation.optimise(); ```

- All done
- A trick : 
** If you want to make your own labyrinth but want it fast
** you can generate and config by yourself;
``` Map::getLaby()->generateLab(); ```
```	Io::File::getFile()->generateScheme(Map::getLaby()->get_map(),Map::getLaby()->getSize()); ```
** generating scheme will paste labyrinth to Data/LabScheme.txt as zeros and asterics
** then you can change it as you wish

