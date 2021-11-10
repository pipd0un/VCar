``` #include "init.h" ```
- If you want to just create labyrinth  <br/>
** then call : <br/>
``` Map::getLaby()->generateLab(); ```

- now you can move around your car in this labyrinth with <br/>
``` Car car = Car(Map::getLaby(), "car1", 'K')); ```
** These parameters are : <br/>
- 1) Its place which car move around
- 2) Car's name that you give is needed for file I/o  <br/>
  and rotation optimization
- 3) A special char which will be shown on map in console

- now we should create main loop of our program like <br/>
``` while ( Map::getLaby()->isAnyOneFinishes()){ ``` <br/>
``` SetCursorPosition(0, 0); ```                     <br/>
``` car._push(Map::getLaby()); ```                   <br/>
``` Map::getLaby()->show_map(car1); ```              <br/>
```} ```                                             <br/>
** if anyone finishes the race loop gonna break <br/>
** setting cursor position is not necessary its needed for  <br/>
** good console view <br/>
** _push() is our main running method <br/>
** and last show_map() is renderer of events to console 

