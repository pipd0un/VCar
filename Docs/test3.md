- Wanna watch a couple of stupid cars race ?
** then you should create a your car objects  :
``` Car *car1 = new Car(Map::getLaby(), "car1", 'K'); ```
``` Car *car2 = new Car(Map::getLaby(), "car1", 'L'); ```
** need to take it on heap sorry dude.
``` Car *cars[2]; ```
``` cars[0] = car1; ```
``` cars[1] = car2; ```
** Of course you can write it with your style 
** In the end of coding you need a object array do not forget !

- Now lets create main racing loop :
``` while ( Map::getLaby()->isAnyOneFinishes()){ ```
``` SetCursorPosition(0, 0); ``` 
``` car1->_push(Map::getLaby()); ```
``` car2->_push(Map::getLaby()); ```
``` Map::getLaby()->show_race(cars); ```
```} ```

- Only thing that missing is ;
** You can not seek or optimize rotation or create rotation while racing 
** It is allowed for single cars

- All done
- A trick : 
** Do not forget freeing heap :)
** you can generate and config by yourself;
``` delete car1; ```
``` delete car2; ```
- THANKS FOR ALL

