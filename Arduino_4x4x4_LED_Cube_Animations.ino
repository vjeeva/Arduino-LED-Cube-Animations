/*
  4x4x4 LED Cube
  Connection Setup: 
  Columns
  [(x,y)-Pin]
  (1,1)-13
  (1,2)-12
  (1,3)-11
  (1,4)-10
  (2,1)-9
  (2,2)-8
  (2,3)-7
  (2,4)-6
  (3,1)-5
  (3-2)-4
  (3-3)-3
  (3,4)-2
  (4,1)-1
  (4,2)-0
  (4,3)-A5
  (4,4)-A4
  Layers
  [layer-Pin]
  a-A0
  b-A1
  c-A2
  d-A3

  Animations made by Varjitt Jeeva
*/

int column[16]={13,12,11,10,9,8,7,6,5,4,3,2,1,0,A5,A4};
int layer[4]={A3,A2,A1,A0};

void setup() {
  // put your setup code here, to run once:
  //setting rows to ouput
  for(int i = 0; i<16; i++)
  {
    pinMode(column[i], OUTPUT);
  }
  //setting layers to output
  for(int i = 0; i<4; i++)
  {
    pinMode(layer[i], OUTPUT);
  }
  //seeding random for random pattern
  randomSeed(analogRead(10));
}

void loop() {
  // put your main code here, to run repeatedly:
  //cornerCubeCycle();
  railgun();
  cornerCubeCycle(90);
}


//Arrow

void arrow_tip(){
  
}

void arrow_end(){
  
}

//RailGun Mode
void railgun(){
  allOff();
  for (int i = 0; i < 150; i++){
    int layerR = (int)random(1,5);
    int rowR = (int)random(1,5);
    rg_layerXrowX(layerR,rowR,35); 
  }
}

void rg_layerXrowX(int layerI, int rowI, int time){
  int columnSS[4] = {0,0,0,0};
  switch(rowI){
    case 1:
      columnSS[0] = 0;
      columnSS[1] = 4;
      columnSS[2] = 8;
      columnSS[3] = 12;
      break;
    case 2:
      columnSS[0] = 1;
      columnSS[1] = 5;
      columnSS[2] = 9;
      columnSS[3] = 13;
      break;
    case 3:
      columnSS[0] = 2;
      columnSS[1] = 6;
      columnSS[2] = 10;
      columnSS[3] = 14;
      break;
    default:
      columnSS[0] = 3;
      columnSS[1] = 7;
      columnSS[2] = 11;
      columnSS[3] = 15;
      break;
  }
    
  digitalWrite(layer[layerI-1],1);
  digitalWrite(column[columnSS[0]],0);
  delay(time);
  allOff();
  digitalWrite(layer[layerI-1],1);
  digitalWrite(column[columnSS[1]],0);
  delay(time);
  allOff();
  digitalWrite(layer[layerI-1],1);
  digitalWrite(column[columnSS[2]],0);
  delay(time);
  allOff();
  digitalWrite(layer[layerI-1],1);
  digitalWrite(column[columnSS[3]],0);
  delay(time);
  allOff();
}
  
void centerCube(){
  digitalWrite(layer[3], 0);
  digitalWrite(layer[2], 1);
  digitalWrite(layer[1], 1);
  digitalWrite(layer[0], 0);
  
  for (int i = 0; i < 16; i++){
    digitalWrite(column[i], 1);
  }
  digitalWrite(column[5],0);
  digitalWrite(column[6],0);
  digitalWrite(column[9],0);
  digitalWrite(column[10],0); 
}

void centerCubeOnly(){
  digitalWrite(layer[2], 1);
  digitalWrite(layer[1], 1);
  digitalWrite(column[5],0);
  digitalWrite(column[6],0);
  digitalWrite(column[9],0);
  digitalWrite(column[10],0); 
}

//CORNER CUBE CODE
void cornerCubeCycle(int time){
  allOff();

  for (int i = 0; i < 24; i++){
    cube11_grow(time);
    cube14_grow(time);
    cube44_grow(time);
    cube41_grow(time); 
  }
}

void cube11_grow(int time){
  cube11_1_ON();
  delay(time);
  allOff();
  cube11_4_ON();
  delay(time);
  allOff();
  cube11_9_ON();
  delay(time);
  allOff();
  allOn();
  delay(time);
  allOff();
}

void cube14_grow(int time){
  cube14_1_ON();
  delay(time);
  allOff();
  cube14_4_ON();
  delay(time);
  allOff();
  cube14_9_ON();
  delay(time);
  allOff();
  allOn();
  delay(time);
  allOff();
}

void cube44_grow(int time){
  cube44_1_ON();
  delay(time);
  allOff();
  cube44_4_ON();
  delay(time);
  allOff();
  cube44_9_ON();
  delay(time);
  allOff();
  allOn();
  delay(time);
  allOff();  
}

void cube41_grow(int time){
  cube41_1_ON();
  delay(time);
  allOff();
  cube41_4_ON();
  delay(time);
  allOff();
  cube41_9_ON();
  delay(time);
  allOff();
  allOn();
  delay(time);
  allOff();
}

void cube11_1_ON() {
  digitalWrite(layer[3], 1);
  for (int i = 0; i < 2; i++){
    digitalWrite(layer[i], 0);
  }
  digitalWrite(column[0],0); 
  for (int i = 1; i < 16; i++){
    digitalWrite(column[i], 1);
  }
}

void cube14_1_ON() {
  digitalWrite(layer[3], 1);
  for (int i = 0; i < 2; i++){
    digitalWrite(layer[i], 0);
  }
  for (int i = 0; i < 16; i++){
    digitalWrite(column[i], 1);
  }
  digitalWrite(column[3],0); 
}

void cube44_1_ON() {
  digitalWrite(layer[3], 1);
  for (int i = 0; i < 2; i++){
    digitalWrite(layer[i], 0);
  }
  for (int i = 0; i < 16; i++){
    digitalWrite(column[i], 1);
  }
  digitalWrite(column[15],0); 
}

void cube41_1_ON() {
  digitalWrite(layer[3], 1);
  for (int i = 0; i < 2; i++){
    digitalWrite(layer[i], 0);
  }
  for (int i = 0; i < 16; i++){
    digitalWrite(column[i], 1);
  }
  digitalWrite(column[12],0); 
}

void cube11_4_ON() {
  digitalWrite(layer[3], 1);
  digitalWrite(layer[2], 1);
  digitalWrite(layer[1], 0);
  digitalWrite(layer[0], 0);
  
  for (int i = 0; i < 16; i++){
    digitalWrite(column[i], 1);
  }
  digitalWrite(column[0],0);
  digitalWrite(column[1],0);
  digitalWrite(column[4],0);
  digitalWrite(column[5],0); 
}

void cube14_4_ON() {
  digitalWrite(layer[3], 1);
  digitalWrite(layer[2], 1);
  digitalWrite(layer[1], 0);
  digitalWrite(layer[0], 0);
  
  for (int i = 0; i < 16; i++){
    digitalWrite(column[i], 1);
  }
  digitalWrite(column[2],0);
  digitalWrite(column[3],0);
  digitalWrite(column[6],0);
  digitalWrite(column[7],0); 
}

void cube44_4_ON() {
  digitalWrite(layer[3], 1);
  digitalWrite(layer[2], 1);
  digitalWrite(layer[1], 0);
  digitalWrite(layer[0], 0);
  
  for (int i = 0; i < 16; i++){
    digitalWrite(column[i], 1);
  }
  digitalWrite(column[10],0);
  digitalWrite(column[11],0);
  digitalWrite(column[14],0);
  digitalWrite(column[15],0); 
}

void cube41_4_ON() {
  digitalWrite(layer[3], 1);
  digitalWrite(layer[2], 1);
  digitalWrite(layer[1], 0);
  digitalWrite(layer[0], 0);
  
  for (int i = 0; i < 16; i++){
    digitalWrite(column[i], 1);
  }
  digitalWrite(column[8],0);
  digitalWrite(column[9],0);
  digitalWrite(column[12],0);
  digitalWrite(column[13],0); 
}

void cube11_9_ON() {
  digitalWrite(layer[3], 1);
  digitalWrite(layer[2], 1);
  digitalWrite(layer[1], 1);
  digitalWrite(layer[0], 0);
  
  for (int i = 0; i < 16; i++){
    digitalWrite(column[i], 1);
  }
  digitalWrite(column[0],0);
  digitalWrite(column[1],0);
  digitalWrite(column[2],0);
  digitalWrite(column[4],0);
  digitalWrite(column[5],0);
  digitalWrite(column[6],0); 
  digitalWrite(column[8],0);
  digitalWrite(column[9],0);
  digitalWrite(column[10],0);
}

void cube14_9_ON() {
  digitalWrite(layer[3], 1);
  digitalWrite(layer[2], 1);
  digitalWrite(layer[1], 1);
  digitalWrite(layer[0], 0);
  
  for (int i = 0; i < 16; i++){
    digitalWrite(column[i], 1);
  }
  digitalWrite(column[1],0);
  digitalWrite(column[2],0);
  digitalWrite(column[3],0);
  digitalWrite(column[5],0);
  digitalWrite(column[6],0);
  digitalWrite(column[7],0); 
  digitalWrite(column[9],0);
  digitalWrite(column[10],0);
  digitalWrite(column[11],0);
}

void cube44_9_ON() {
  digitalWrite(layer[3], 1);
  digitalWrite(layer[2], 1);
  digitalWrite(layer[1], 1);
  digitalWrite(layer[0], 0);
  
  for (int i = 0; i < 16; i++){
    digitalWrite(column[i], 1);
  }
  digitalWrite(column[5],0);
  digitalWrite(column[6],0);
  digitalWrite(column[7],0); 
  digitalWrite(column[9],0);
  digitalWrite(column[10],0);
  digitalWrite(column[11],0);
  digitalWrite(column[13],0);
  digitalWrite(column[14],0);
  digitalWrite(column[15],0);
}

void cube41_9_ON() {
  digitalWrite(layer[3], 1);
  digitalWrite(layer[2], 1);
  digitalWrite(layer[1], 1);
  digitalWrite(layer[0], 0);
  
  for (int i = 0; i < 16; i++){
    digitalWrite(column[i], 1);
  }
  digitalWrite(column[4],0);
  digitalWrite(column[5],0);
  digitalWrite(column[6],0); 
  digitalWrite(column[8],0);
  digitalWrite(column[9],0);
  digitalWrite(column[10],0);
  digitalWrite(column[12],0);
  digitalWrite(column[13],0);
  digitalWrite(column[14],0);
}

void allOff(){
   for(int i = 0; i < 16; i++)
   {
     digitalWrite(column[i], 1);
   }
   for(int i = 0; i < 4; i++)
   {
     digitalWrite(layer[i], 0);
   }
}

void allOn() {
  for(int i = 0; i < 16; i++)
  {
    digitalWrite(column[i], 0);
  }
  for(int i = 0; i < 4; i++)
  {
    digitalWrite(layer[i], 1);
  } 
}

