``` #include "init.h" ```
- If you want to just create labyrinth 
** then call :
``` Map::getLaby()->generateLab(); ```

- now you can move around your car in this labyrinth with
``` Car car = Car(Map::getLaby(), "car1", 'K')); ```
** These parameters are :
- 1) Its place which car move around
- 2) Car's name that you give is needed for file I/o 
-    and rotation optimization
- 3) A special char which will be shown on map in console

- now we should create main loop of our program like
``` while ( Map::getLaby()->isAnyOneFinishes()){ ```
``` SetCursorPosition(0, 0); ``` 
``` car._push(Map::getLaby()); ```
``` Map::getLaby()->show_map(car1); ```
```} ```
** if anyone finishes the race loop gonna break
** setting cursor position is not necessary its needed for 
** good console view
** _push() is our main running method
** and last show_map() is renderer of events to console 

