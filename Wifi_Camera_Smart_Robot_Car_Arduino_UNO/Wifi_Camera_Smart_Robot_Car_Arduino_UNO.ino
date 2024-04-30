#include "IR_remote.h"
#include "keymap.h"
#include <DHT.h>
#include <DHT_U.h>

#include <DHT.h>
#define DHTTYPE DHT11
#define DHTPIN 9

DHT dht(DHTPIN, DHTTYPE);

IRremote ir(3);




volatile char BLE_bit_temp;
String BLE_value;
String BLE_value_temp;
String G_Bluetooth_value;
volatile int G_degree;
volatile int re_string_len;
volatile float Left_photosensitive;
volatile float Right_photosensitive;
volatile int Lightseeking_Degree;
volatile float f;
volatile int speed_value;
volatile int D_mix;
volatile int D_mid;
volatile int D_max;
volatile boolean Funtion_FLag;
volatile int G_string_len;
volatile int BLE_Change_SPEED;

volatile int Left_Tra_Value;
volatile int Center_Tra_Value;
volatile int Right_Tra_Value;
volatile int Black;
volatile int white;
volatile int Front_Distance;
volatile char IR_Car_Mode;
volatile boolean IR_Mode_Flag;



void Move_Forward(int car_speed) {
  digitalWrite(2,HIGH);
  analogWrite(5,car_speed);
  digitalWrite(4,LOW);
  analogWrite(6,car_speed);
}

void Move_Backward(int car_speed) {
  digitalWrite(2,LOW);
  analogWrite(5,car_speed);
  digitalWrite(4,HIGH);
  analogWrite(6,car_speed);
}

void Rotate_Left(int car_speed) {
  digitalWrite(2,LOW);
  analogWrite(5,car_speed);
  digitalWrite(4,LOW);
  analogWrite(6,car_speed);
}

void Rotate_Right(int car_speed) {
  digitalWrite(2 ,HIGH);
  analogWrite(5,car_speed);
  digitalWrite(4,HIGH);
  analogWrite(6,car_speed);
}

void STOP() {
  digitalWrite(2,LOW);
  analogWrite(5,0);
  digitalWrite(4,HIGH);
  analogWrite(6,0);
}

void temperaturaaa() {
  delay(2000);
    
    //Paso 5
    float h = dht.readHumidity();
    
    //Paso 6
    float t = dht.readTemperature();
    
    //Paso 7
    float f = dht.readTemperature(true);

    //Paso 8
    if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
    }

    //Paso 9
    float hif = dht.computeHeatIndex(f, h);
    float hic = dht.computeHeatIndex(t, h, false);

    //Paso 10
    Serial.print("Humidity: ");
    Serial.print(h);
    Serial.print(" %\t");
    Serial.print("Temperature: ");
    Serial.print(t);
    Serial.print(" *C ");
    Serial.print(f);
    Serial.print(" *F\t");
    Serial.print("Heat index: ");
    Serial.print(hic);
    Serial.print(" *C ");
    Serial.print(hif);
    Serial.println(" *F");
}







/*
    IR_KEYCODE_1->Button 1
    IR_KEYCODE_2->Button 2
    IR_KEYCODE_3->Button 3
    IR_KEYCODE_4->Button 4
    IR_KEYCODE_5->Button 5
    IR_KEYCODE_6->Button 6
    IR_KEYCODE_7->Button 7
    IR_KEYCODE_8->Button 8
    IR_KEYCODE_9->Button 9
    IR_KEYCODE_0->Button 0
    IR_KEYCODE_STAR->Button *
    IR_KEYCODE_POUND->Button #
    IR_KEYCODE_UP->Button UP
    IR_KEYCODE_DOWN->Button DOWN
    IR_KEYCODE_OK->Button OK
    IR_KEYCODE_LEFT->Button LEFT
    IR_KEYCODE_RIGHT->Button RIGHT
*/
void IR_remote_control() {
  switch (IR_Car_Mode) {
   case 'b':
    Move_Backward(110);
    delay(300);
    STOP();
    IR_Car_Mode = ' ';
    break;
   case 'f':
    Move_Forward(110);
    delay(300);
    STOP();
    IR_Car_Mode = ' ';
    break;
   case 'l':
    Rotate_Left(110);
    delay(300);
    STOP();
    IR_Car_Mode = ' ';
    break;
   case 'r':
    Rotate_Right(110);
    delay(300);
    STOP();
    IR_Car_Mode = ' ';
    break;
   case 's':
    STOP();
    IR_Car_Mode = ' ';
    break;
    case 'x':
    Move_Forward(130);
    delay(30000);
    STOP();
    temperaturaaa();
    temperaturaaa();
    temperaturaaa();
    Rotate_Right(67);
    delay(3000);
    Move_Forward(100);
    delay(30000);
    STOP();
    IR_Car_Mode = ' ';
    break;
   
   
     

   


  }
  if (ir.getIrKey(ir.getCode(),1) == IR_KEYCODE_UP) {
    IR_Car_Mode = 'f';
    IR_Mode_Flag = true;

  } else if (ir.getIrKey(ir.getCode(),1) == IR_KEYCODE_LEFT) {
    IR_Car_Mode = 'l';
    IR_Mode_Flag = true;
  } else if (ir.getIrKey(ir.getCode(),1) == IR_KEYCODE_DOWN) {
    IR_Car_Mode = 'b';
    IR_Mode_Flag = true;
  } else if (ir.getIrKey(ir.getCode(),1) == IR_KEYCODE_RIGHT) {
    IR_Car_Mode = 'r';
    IR_Mode_Flag = true;
  } else if (ir.getIrKey(ir.getCode(),1) == IR_KEYCODE_OK) {
    IR_Car_Mode = 's';
    IR_Mode_Flag = true;
  } else if (ir.getIrKey(ir.getCode(),1) == IR_KEYCODE_2) {
    IR_Car_Mode = 'x';
    IR_Mode_Flag = true;
  } else if (ir.getIrKey(ir.getCode(),1) == IR_KEYCODE_8) {
    IR_Car_Mode = 'm';
    IR_Mode_Flag = true;
  }
}

void setup(){
  Serial.begin(9600);
  dht.begin();
  

  delay(0);
  pinMode(2, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, INPUT);
}

void loop(){
  IR_remote_control();

  
    }

  


