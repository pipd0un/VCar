- Wanna watch a couple of stupid cars race ? <br/>
** then you should create your car objects  : <br/>
``` Car *car1 = new Car(Map::getLaby(), "car1", 'K'); ``` <br/>
``` Car *car2 = new Car(Map::getLaby(), "car1", 'L'); ``` <br/>
** need to take it on heap sorry dude. <br/>
``` Car *cars[2]; ``` <br/>
``` cars[0] = car1; ``` <br/>
``` cars[1] = car2; ``` <br/>
** Of course you can write it with your style 
** In the end of coding you need a object array do not forget !

- Now lets create main racing loop : <br/>
``` while ( Map::getLaby()->isAnyOneFinishes()){ ``` <br/>
``` SetCursorPosition(0, 0); ```                     <br/>
``` car1->_push(Map::getLaby()); ```                  <br/>
``` car2->_push(Map::getLaby()); ```                  <br/>
``` Map::getLaby()->show_race(cars); ```              <br/>
```} ```

- Only thing that missing is ;
** You can not seek or optimize rotation or create rotation while racing 
** It is allowed for single cars

- All done
- A trick : 
** Do not forget freeing heap :)
** you can generate and config by yourself; <br/>
``` delete car1; ```                        <br/>
``` delete car2; ```                        <br/>
- THANKS FOR ALL

