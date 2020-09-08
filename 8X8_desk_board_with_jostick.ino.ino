int VRx = A0; // joistick pin for x axis
int VRy = A1; // joistick pin for y axis

const int row[8] = {
  2, 7, 19, 5, 13, 18, 12, 16 //pins for rows
};

// 2-dimensional array of column pin numbers:
const int col[8] = {
  6, 11, 10, 3, 17, 4, 8, 9 //pins for colloms 
};

int R = 16; // hight of matrix
int S = 16; // lenght of matrix

  // test level
//  {0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1},
  //{0,0,0,1,0,0,0,0,6,0,0,0,0,0,0,1},
//  {0,0,0,1,0,0,0,1,1,0,0,0,0,0,0,1},
  //{0,0,0,1,0,4,0,1,0,0,0,0,0,0,0,1},
//  {0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,1},
  //{0,8,0,1,1,1,1,1,0,1,1,1,1,1,1,1},
//  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  //{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//  {0,0,0,1,1,1,1,1,0,1,0,0,0,0,0,0},
  //{0,0,0,2,0,0,0,1,0,1,0,0,1,3,1,0},
//  {0,0,0,1,0,7,0,1,0,1,0,0,1,3,1,0},
  //{0,0,0,1,0,0,0,1,0,1,0,0,1,1,1,0},
//  {0,0,0,1,1,1,1,1,0,1,0,0,0,0,0,0},
  //{0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0},
//  {0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0},
  //{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},

// levels
int pixels[3][16][16] = {{
  {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0},
  {0,0,0,0,0,0,1,0,0,1,0,0,1,0,0,0},
  {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,1,0,8,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0},
  {3,1,1,1,1,1,1,1,1,1,1,1,1,1,6,1},
  {0,0,0,0,0,0,2,0,1,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,0,1,1,1,1,0,1,1,1},
  {3,3,3,3,3,1,0,0,0,1,0,0,0,0,0,1},
  {3,3,3,3,3,1,0,7,0,1,0,0,0,0,0,1},
  {4,1,1,3,1,1,0,0,0,1,0,0,0,0,0,1},
  {1,0,0,0,0,0,1,1,1,1,1,1,0,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},  
  },{
  {1,1,1,1,1,1,1,3,3,3,3,3,3,3,3,3},
  {1,0,0,0,1,1,3,3,1,1,1,1,1,1,1,3},
  {1,0,0,0,0,3,2,1,0,0,0,0,0,0,1,3},
  {1,0,0,0,1,3,1,3,1,1,1,1,1,0,1,3},
  {1,1,0,1,1,3,1,3,1,1,1,1,1,0,1,3},
  {3,3,3,3,1,3,1,3,1,0,0,0,1,0,1,3},
  {3,1,1,1,1,3,1,3,1,0,8,0,0,0,3,3},
  {3,1,3,3,3,3,1,1,1,0,0,0,1,0,1,1},
  {4,1,3,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,0,1,0,0,0,0,0,0,1},
  {1,0,0,0,1,0,0,0,1,0,0,0,0,0,0,1},
  {1,0,8,0,1,1,1,0,1,0,0,0,0,0,0,1},
  {1,0,0,0,1,3,3,0,1,0,0,0,0,0,0,1},
  {1,0,0,0,1,3,1,0,1,0,0,0,0,0,2,6},
  {1,1,1,1,3,3,1,3,6,3,1,1,1,1,6,7},
  },{
  {0,0,0,0,0,1,1,1,1,1,1,3,3,3,3,3},
  {0,0,0,0,0,1,3,3,3,3,3,1,1,1,1,3},
  {0,0,6,6,6,1,4,1,1,1,3,3,3,1,1,3},
  {0,0,6,2,2,1,3,3,3,1,1,1,3,3,3,3},
  {0,0,6,2,7,1,1,1,3,1,1,1,3,1,1,3},
  {0,1,1,1,1,1,1,1,3,1,3,3,3,1,1,3},
  {0,0,0,0,0,0,0,1,3,1,1,1,3,1,3,3},
  {0,0,0,0,0,0,0,1,3,1,1,3,3,1,1,1},
  {0,0,0,0,0,0,0,1,3,1,1,3,1,1,1,1},
  {1,1,3,1,1,1,1,1,3,1,1,3,3,1,1,1},
  {1,1,3,3,3,3,3,3,3,1,1,1,3,3,3,3},
  {3,1,1,1,3,1,1,1,3,3,3,3,3,1,1,3},
  {3,3,3,3,3,3,1,1,1,3,1,1,1,1,1,3},
  {3,1,3,3,1,3,1,3,3,3,1,3,3,3,3,1},
  {2,1,3,1,3,3,3,1,1,1,1,3,1,1,3,1},
  {8,1,3,1,1,1,3,3,3,3,3,3,1,3,3,1},  
  }};

int xPosition = 0; // position of x on joistick
int yPosition = 0; // position of y on joistick
int mapX = 0;  //map xPosition on joistick
int mapY = 0;  //map yPosition on joistick
int r = 0; // x position of the screen
int s = 0; // y position of the screen
int xM = 7; //  max length of the screen
int yM = 7; //  max hight of the screen
int xm = 0; //  min length of the screen
int ym = 0; //  min hight of the screen
int counter = 0; // timer for hero
int runN = 5; //time how much hero need to wait to move
int SW = 0; // pin for joistick bottom 
int SW_state = 0; // state of joistick bottom
int inV = 0; // inventory
int counterV = 0; // timer for inventory
int VM = 200; // time how much inventory need to wait to take item
int onoff = 1; // on/off bottom
int state = 0; // state of on/off bottom
int game = -1; // mode of game -1 = off, 1 = on
int counterG = 0; // timer for game
int waitG = 100; // time how much programm need to wait to take turn off or on the game
int L = 0; // level

boolean opendoor2 = false; // open or closed the door 2
boolean opendoor6 = false; // open or closed the door 6

// cursor position:
int x = 0; // x position of hero
int y = 0; // y position of hero

void setup() { 
  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);
  pinMode(onoff, INPUT_PULLUP);
  pinMode(SW, INPUT_PULLUP); 
  
  // initialize the I/O pins as outputs iterate over the pins:
  for (int thisPin = 0; thisPin < 8; thisPin++) {
    // initialize the output pins:
    pinMode(col[thisPin], OUTPUT);
    pinMode(row[thisPin], OUTPUT);
    // take the col pins (i.e. the cathodes) high to ensure that the LEDS are off:
    digitalWrite(col[thisPin], HIGH);
    digitalWrite(row[thisPin], LOW);
  }
}
void loop() {
  // turns off the hero pos
  digitalWrite(col[x - r], HIGH);
  digitalWrite(row[y - s], LOW);

  // check if the onoff bottom is pressed
  state = digitalRead(onoff);
  if(state == LOW ){
      game = 0 - game;
      delay(1000);
      counterG += 1;
  }
  if(game == 1){
    xPosition = analogRead(VRx);
    yPosition = analogRead(VRy);
    SW_state = digitalRead(SW);
    mapX = map(xPosition, 0, 1023, -512, 512);
    mapY = map(yPosition, 0, 1023, -512, 512);
    
    //digitalWrite(col[x - r], HIGH);
    //digitalWrite(row[y - s], LOW);

    // draw world
    for (int i = r; i < 8 + r; i++) {
      for (int l = s ; l < 8 + s; l++) {
        if (pixels[L][i][l] == 1 or pixels[L][i][l] == 4 or pixels[L][i][l] == 5 or pixels[L][i][l] == 8 or pixels[L][i][l] == 9 or pixels[L][i][l] == 3 or pixels[L][i][l] == 7){
          digitalWrite(col[i - r], LOW);
          digitalWrite(row[l - s], HIGH);
          delayMicroseconds(100);
          //delay(50);
        }
        if (pixels[L][i][l] == 2 and opendoor2 == false){
          digitalWrite(col[i - r], LOW);
          digitalWrite(row[l - s], HIGH);
          delayMicroseconds(100);
          //delay(50);
        }
        if (pixels[L][i][l] == 6 and opendoor6 == false){
          digitalWrite(col[i - r], LOW);
          digitalWrite(row[l - s], HIGH);
          delayMicroseconds(100);
          //delay(50);
        }
      }
      for (int l = s; l < 8 + s; l++) {
        digitalWrite(col[i - r], HIGH);
        digitalWrite(row[l - s], LOW);
       
      }
    }
    //check status of the hero
    if (SW_state == HIGH){
      if(0 <= x <= 8 and 0 <= y <= 8 and counter == runN){
        if(mapX < -250){
          if(x < 7 + r){
            if((pixels[L][x + 1][y] != 1 and pixels[L][x + 1][y] != 2 and pixels[L][x + 1][y] != 6) or (pixels[L][x + 1][y] == 2 and opendoor2 == true) or (pixels[L][x + 1][y] == 6 and opendoor6 == true)){
              x += 1;
            }
          }
        }
        if(mapY < -250){
          if(y < 7 + s){
            if((pixels[L][x][y + 1] != 1 and pixels[L][x][y + 1] != 2 and pixels[L][x][y + 1] != 6) or (pixels[L][x][y + 1] == 2 and opendoor2 == true) or (pixels[L][x][y + 1] == 6 and opendoor6 == true)){
              y += 1;
            }
          }
        }
        if(mapX > 250){
          if(x > 0 + r){
            if((pixels[L][x - 1][y] != 1 and pixels[L][x - 1][y] != 2 and pixels[L][x - 1][y] != 6) or (pixels[L][x - 1][y] == 2 and opendoor2 == true) or (pixels[L][x - 1][y] == 6 and opendoor6 == true)){
              x -= 1;
            }
          }
        }
        if(mapY > 250){
          if(y > 0 + s){
            if((pixels[L][x][y - 1] != 1 and pixels[L][x][y - 1] != 2 and pixels[L][x][y - 1] != 6) or (pixels[L][x][y - 1] == 2 and opendoor2 == true) or (pixels[L][x][y - 1] == 6 and opendoor6 == true)){
              y -= 1;
            }
          }
        }
      }
    
      // check the hero timer
      if (counter < runN){
        counter += 1;
        }
      else{
          counter = 0;
        }
    
        // move screen
        if(mapX < -250){
          if(x == xM + r and r != R/2){
              r += 1;
          }
        }
        if(mapY < -250){
          if(y == yM + s and s != S/2){
              s += 1;
          }
        }
        if(mapX > 250){
          if(x == xm + r and r != 0){
              r -= 1;
          }
        }
        if(mapY > 250 and s != 0){
          if(y == ym + s){
              s -= 1;
          }
        }
    }
    // check inventory, bottoms, doors, and boxes
    else{
      if(pixels[L][x][y] == 3 and inV == 0 and counterV == 0){
        inV += 1;
        pixels[L][x][y] = 0;
        //delay(1000);
        counterV += 1;
      }
      else if(inV != 0 and counterV == 0 and pixels[L][x][y] == 0){
        pixels[L][x][y] = 3;
        inV -= 1;
        //delay(1000);
        counterV += 1;
      }
      else if(pixels[L][x][y] == 5 and inV == 0 and counterV == 0){
          pixels[L][x][y] = 4;
          inV += 1;
          opendoor2 = false;
          counterV += 1;
      }
      else if(pixels[L][x][y] == 4 and inV == 1 and counterV == 0){
          pixels[L][x][y] = 5;
          inV -= 1;
          opendoor2 = true;
          counterV += 1;
      }
      else if(pixels[L][x][y] == 9 and inV == 0 and counterV == 0){
          pixels[L][x][y] = 8;
          inV += 1;
          opendoor6 = false;
          counterV += 1;
      }
      else if(pixels[L][x][y] == 8 and inV == 1 and counterV == 0){
          pixels[L][x][y] = 9;
          inV -= 1;
          opendoor6 = true;
          counterV += 1;
      }
      // check for exit
      else if(pixels[L][x][y] == 7 and counterV == 0){
        L += 1;
        x = 1;
        y = 1;
        r = 0;
        s = 0;
        opendoor2 = false;
        opendoor6 = false;
        inV = 0;
        counterV += 1;
        //for (int i = 0; i < 16; i++) {
          //for (int l = 0 ; l < 16; l++) {
            // pixels[L][i][l] = levels[L][i][l];
          //}
        //}                      
      }
    }
    // check inventory timer
    if(counterV != 0 and counterV != VM){
      counterV += 1;  
    }
    else if(counterV == VM){
      counterV = 0;  
    }
    
    // turn on hero
    digitalWrite(col[x - r], LOW);
    digitalWrite(row[y - s], HIGH);
    
    delay(10);
  }
  // check game timer
  if(counterG != 0){
    if(counterG < waitG){
      counterG += 1;  
    }
    else if(counterG == waitG){
      counterG = 0; 
    }
  }
}
