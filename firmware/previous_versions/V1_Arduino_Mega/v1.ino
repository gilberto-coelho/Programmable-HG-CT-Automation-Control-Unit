//      CREATED BY GILBERTO COELHO - SEPTEMBER OF 2022

//#include <LiquidCrystal.h>
//LiquidCrystal lcd (12, 11, 5, 4, 3, 2);
//#include <Adafruit_LiquidCrystal.h>
//Adafruit_LiquidCrystal lcd(0);

#include <Wire.h>
#include <EEPROM.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//TIME - "0" means the step will be skipped
byte time1 = 0;  
byte time2 = 0;  
byte time3 = 0;  
byte time4 = 0;  
byte time5 = 0;  
byte time6 = 0;  
byte time7 = 0;  
byte time8 = 0;  
byte time9 = 0;  
byte time10 = 0;  
byte time11 = 0;  
byte time12 = 0;  


//RELAYS - "0" means OFF; "1" means ON
byte relay1_1 = 0;  
byte relay2_1 = 0;  
byte relay3_1 = 0;  
byte relay4_1 = 0;
byte relay5_1 = 0;
byte relay6_1 = 0;

byte relay1_2 = 0;  
byte relay2_2 = 0;  
byte relay3_2 = 0;  
byte relay4_2 = 0;
byte relay5_2 = 0;
byte relay6_2 = 0;

byte relay1_3 = 0;  
byte relay2_3 = 0;  
byte relay3_3 = 0;  
byte relay4_3 = 0;
byte relay5_3 = 0;
byte relay6_3 = 0;

byte relay1_4 = 0;  
byte relay2_4 = 0;  
byte relay3_4 = 0;  
byte relay4_4 = 0;
byte relay5_4 = 0;
byte relay6_4 = 0;

byte relay1_5 = 0;  
byte relay2_5 = 0;  
byte relay3_5 = 0;  
byte relay4_5 = 0;
byte relay5_5 = 0;
byte relay6_5 = 0;

byte relay1_6 = 0;  
byte relay2_6 = 0;  
byte relay3_6 = 0;  
byte relay4_6 = 0;
byte relay5_6 = 0;
byte relay6_6 = 0;

byte relay1_7 = 0;  
byte relay2_7 = 0;  
byte relay3_7 = 0;  
byte relay4_7 = 0;
byte relay5_7 = 0;
byte relay6_7 = 0;

byte relay1_8 = 0;  
byte relay2_8 = 0;  
byte relay3_8 = 0;  
byte relay4_8 = 0;
byte relay5_8 = 0;
byte relay6_8 = 0;

byte relay1_9 = 0;  
byte relay2_9 = 0;  
byte relay3_9 = 0;  
byte relay4_9 = 0;
byte relay5_9 = 0;
byte relay6_9 = 0;

byte relay1_10 = 0;  
byte relay2_10 = 0;  
byte relay3_10 = 0;  
byte relay4_10 = 0;
byte relay5_10 = 0;
byte relay6_10 = 0;

byte relay1_11 = 0;  
byte relay2_11 = 0;  
byte relay3_11 = 0;  
byte relay4_11 = 0;
byte relay5_11 = 0;
byte relay6_11 = 0;

byte relay1_12 = 0;  
byte relay2_12 = 0;  
byte relay3_12 = 0;  
byte relay4_12 = 0;
byte relay5_12 = 0;
byte relay6_12 = 0;

//////////////////////////////////////////

byte rpm1_1 = 0;  
byte rpm2_1 = 0;  
byte rpm3_1 = 0;  
byte rpm4_1 = 0;
 
byte rpm1_2 = 0;  
byte rpm2_2 = 0;  
byte rpm3_2 = 0;  
byte rpm4_2 = 0;

byte rpm1_3 = 0;  
byte rpm2_3 = 0;  
byte rpm3_3 = 0;  
byte rpm4_3 = 0;

byte rpm1_4 = 0;  
byte rpm2_4 = 0;  
byte rpm3_4 = 0;  
byte rpm4_4 = 0;

byte rpm1_5 = 0;  
byte rpm2_5 = 0;  
byte rpm3_5 = 0;  
byte rpm4_5 = 0;

byte rpm1_6 = 0;  
byte rpm2_6 = 0;  
byte rpm3_6 = 0;  
byte rpm4_6 = 0;

byte rpm1_7 = 0;  
byte rpm2_7 = 0;  
byte rpm3_7 = 0;  
byte rpm4_7 = 0;
byte rpm5_7 = 0;

byte rpm1_8 = 0;  
byte rpm2_8 = 0;  
byte rpm3_8 = 0;  
byte rpm4_8 = 0;

byte rpm1_9 = 0;  
byte rpm2_9 = 0;  
byte rpm3_9 = 0;  
byte rpm4_9 = 0;

byte rpm1_10 = 0;  
byte rpm2_10 = 0;  
byte rpm3_10 = 0;  
byte rpm4_10 = 0;

byte rpm1_11 = 0;  
byte rpm2_11 = 0;  
byte rpm3_11 = 0;  
byte rpm4_11 = 0;

byte rpm1_12 = 0;  
byte rpm2_12 = 0;  
byte rpm3_12 = 0;  
byte rpm4_12 = 0;

///////////////////////////////////////////////

byte way1_1 = 0;  
byte way2_1 = 0;  
byte way3_1 = 0;  
byte way4_1 = 0;
 
byte way1_2 = 0;  
byte way2_2 = 0;  
byte way3_2 = 0;  
byte way4_2 = 0;

byte way1_3 = 0;  
byte way2_3 = 0;  
byte way3_3 = 0;  
byte way4_3 = 0;

byte way1_4 = 0;  
byte way2_4 = 0;  
byte way3_4 = 0;  
byte way4_4 = 0;

byte way1_5 = 0;  
byte way2_5 = 0;  
byte way3_5 = 0;  
byte way4_5 = 0;

byte way1_6 = 0;  
byte way2_6 = 0;  
byte way3_6 = 0;  
byte way4_6 = 0;

byte way1_7 = 0;  
byte way2_7 = 0;  
byte way3_7 = 0;  
byte way4_7 = 0;

byte way1_8 = 0;  
byte way2_8 = 0;  
byte way3_8 = 0;  
byte way4_8 = 0;

byte way1_9 = 0;  
byte way2_9 = 0;  
byte way3_9 = 0;  
byte way4_9 = 0;

byte way1_10 = 0;  
byte way2_10 = 0;  
byte way3_10 = 0;  
byte way4_10 = 0;

byte way1_11 = 0;  
byte way2_11 = 0;  
byte way3_11 = 0;  
byte way4_11 = 0;

byte way1_12 = 0;  
byte way2_12 = 0;  
byte way3_12 = 0;  
byte way4_12 = 0;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

byte memoriatime1 = 1;  
byte memoriatime2 = 2;  
byte memoriatime3 = 3;  
byte memoriatime4 = 4;  
byte memoriatime5 = 5;  
byte memoriatime6 = 6;  
byte memoriatime7 = 7;  
byte memoriatime8 = 8;  
byte memoriatime9 = 9;  
byte memoriatime10 = 10;  
byte memoriatime11 = 11;  
byte memoriatime12 = 12;

byte memoriarelay1_1 = 13;  
byte memoriarelay2_1 = 14;  
byte memoriarelay3_1 = 15;  
byte memoriarelay4_1 = 16;
byte memoriarelay5_1 = 17;
byte memoriarelay6_1 = 18;

byte memoriarelay1_2 = 19;  
byte memoriarelay2_2 = 20;  
byte memoriarelay3_2 = 21;  
byte memoriarelay4_2 = 22;
byte memoriarelay5_2 = 23;
byte memoriarelay6_2 = 24;

byte memoriarelay1_3 = 25;  
byte memoriarelay2_3 = 26;  
byte memoriarelay3_3 = 27;  
byte memoriarelay4_3 = 28;
byte memoriarelay5_3 = 29;
byte memoriarelay6_3 = 30;

byte memoriarelay1_4 = 31;  
byte memoriarelay2_4 = 32;  
byte memoriarelay3_4 = 33;  
byte memoriarelay4_4 = 34;
byte memoriarelay5_4 = 35;
byte memoriarelay6_4 = 36;

byte memoriarelay1_5 = 37;  
byte memoriarelay2_5 = 38;  
byte memoriarelay3_5 = 39;  
byte memoriarelay4_5 = 40;
byte memoriarelay5_5 = 41;
byte memoriarelay6_5 = 42;

byte memoriarelay1_6 = 43;  
byte memoriarelay2_6 = 44;  
byte memoriarelay3_6 = 45;  
byte memoriarelay4_6 = 46;
byte memoriarelay5_6 = 47;
byte memoriarelay6_6 = 48;

byte memoriarelay1_7 = 49;  
byte memoriarelay2_7 = 50;  
byte memoriarelay3_7 = 51;  
byte memoriarelay4_7 = 52;
byte memoriarelay5_7 = 53;
byte memoriarelay6_7 = 54;

byte memoriarelay1_8 = 55;  
byte memoriarelay2_8 = 56;  
byte memoriarelay3_8 = 57;  
byte memoriarelay4_8 = 58;
byte memoriarelay5_8 = 59;
byte memoriarelay6_8 = 60;

byte memoriarelay1_9 = 61;  
byte memoriarelay2_9 = 62;  
byte memoriarelay3_9 = 63;  
byte memoriarelay4_9 = 64;
byte memoriarelay5_9 = 65;
byte memoriarelay6_9 = 66;

byte memoriarelay1_10 = 67;  
byte memoriarelay2_10 = 68;  
byte memoriarelay3_10 = 69;  
byte memoriarelay4_10 = 70;
byte memoriarelay5_10 = 71;
byte memoriarelay6_10 = 72;

byte memoriarelay1_11 = 73;  
byte memoriarelay2_11 = 74;  
byte memoriarelay3_11 = 75;  
byte memoriarelay4_11 = 76;
byte memoriarelay5_11 = 77;
byte memoriarelay6_11 = 78;

byte memoriarelay1_12 = 79;  
byte memoriarelay2_12 = 80;  
byte memoriarelay3_12 = 81;  
byte memoriarelay4_12 = 82;
byte memoriarelay5_12 = 83;
byte memoriarelay6_12 = 84;

////////////////////////////////////////////////////////////////////

byte memoriaway1_1 = 85;  
byte memoriaway2_1 = 86;  
byte memoriaway3_1 = 87; 
byte memoriaway4_1 = 88;

byte memoriaway1_2 = 89;  
byte memoriaway2_2 = 90;  
byte memoriaway3_2 = 91;  
byte memoriaway4_2 = 92;

byte memoriaway1_3 = 93;  
byte memoriaway2_3 = 94;  
byte memoriaway3_3 = 95;  
byte memoriaway4_3 = 96;

byte memoriaway1_4 = 97;  
byte memoriaway2_4 = 98;  
byte memoriaway3_4 = 99;  
byte memoriaway4_4 = 100;

byte memoriaway1_5 = 101;  
byte memoriaway2_5 = 102;  
byte memoriaway3_5 = 103;  
byte memoriaway4_5 = 104;

byte memoriaway1_6 = 105;  
byte memoriaway2_6 = 106;  
byte memoriaway3_6 = 107;  
byte memoriaway4_6 = 108;

byte memoriaway1_7 = 109;  
byte memoriaway2_7 = 110;  
byte memoriaway3_7 = 111;  
byte memoriaway4_7 = 112;

byte memoriaway1_8 = 113;  
byte memoriaway2_8 = 114;  
byte memoriaway3_8 = 115;  
byte memoriaway4_8 = 116;

byte memoriaway1_9 = 117;  
byte memoriaway2_9 = 118;  
byte memoriaway3_9 = 119;  
byte memoriaway4_9 = 120;

byte memoriaway1_10 = 121;  
byte memoriaway2_10 = 122;  
byte memoriaway3_10 = 123;  
byte memoriaway4_10 = 124;

byte memoriaway1_11 = 125;  
byte memoriaway2_11 = 126;  
byte memoriaway3_11 = 127;  
byte memoriaway4_11 = 128;

byte memoriaway1_12 = 129;  
byte memoriaway2_12 = 130;  
byte memoriaway3_12 = 131;  
byte memoriaway4_12 = 132;

///////////////////////////////////////////////

byte memoriarpm1_1 = 133;  
byte memoriarpm2_1 = 134;  
byte memoriarpm3_1 = 135;  
byte memoriarpm4_1 = 136;
 
byte memoriarpm1_2 = 137;  
byte memoriarpm2_2 = 138;  
byte memoriarpm3_2 = 139;  
byte memoriarpm4_2 = 140;

byte memoriarpm1_3 = 141;  
byte memoriarpm2_3 = 142;  
byte memoriarpm3_3 = 143;  
byte memoriarpm4_3 = 144;

byte memoriarpm1_4 = 145;  
byte memoriarpm2_4 = 146;  
byte memoriarpm3_4 = 147;  
byte memoriarpm4_4 = 148;

byte memoriarpm1_5 = 149;  
byte memoriarpm2_5 = 150;  
byte memoriarpm3_5 = 151;  
byte memoriarpm4_5 = 152;

byte memoriarpm1_6 = 153;  
byte memoriarpm2_6 = 154;  
byte memoriarpm3_6 = 155;  
byte memoriarpm4_6 = 156;

byte memoriarpm1_7 = 157; 
byte memoriarpm2_7 = 158;  
byte memoriarpm3_7 = 159;  
byte memoriarpm4_7 = 160;
byte memoriarpm5_7 = 161;

byte memoriarpm1_8 = 162;  
byte memoriarpm2_8 = 163;  
byte memoriarpm3_8 = 164;  
byte memoriarpm4_8 = 165;

byte memoriarpm1_9 = 166;  
byte memoriarpm2_9 = 167;  
byte memoriarpm3_9 = 168;  
byte memoriarpm4_9 = 169;

byte memoriarpm1_10 = 170;  
byte memoriarpm2_10 = 171;  
byte memoriarpm3_10 = 172;  
byte memoriarpm4_10 = 173;

byte memoriarpm1_11 = 174;  
byte memoriarpm2_11 = 175;  
byte memoriarpm3_11 = 176;  
byte memoriarpm4_11 = 177;

byte memoriarpm1_12 = 178;  
byte memoriarpm2_12 = 179;  
byte memoriarpm3_12 = 180;  
byte memoriarpm4_12 = 181;

////////////////////////////////////////////////

const int Button1 = 13;
const int Button2 = 12;
const int Button3 = 11;
const int Button4 = 10;

int statebutton1 = 0;
int statebutton2 = 0;
int statebutton3 = 0;
int statebutton4 = 0;

int cont = 0;

bool L_botao_MAIS,  LA_botao_MAIS,  L_botao_MENOS,  LA_botao_MENOS  = 1;               
bool L_botao_ENTER, LA_botao_ENTER, L_botao_VOLTAR, LA_botao_VOLTAR = 1;

int  tela = 1;

int RESET = 9;

char *x = {"0"};
char *xx = {"00"};
char *xxx = {"000"};

int q = 0;

//void (*funcReset)() = 0;

void setup() { 

    digitalWrite(RESET, HIGH); delay (200); pinMode(RESET, OUTPUT);

    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
  
    
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(7, OUTPUT); 
    pinMode(8, OUTPUT);

    pinMode(22, OUTPUT);
    pinMode(24, OUTPUT);
    pinMode(26, OUTPUT);
    pinMode(28, OUTPUT);
    pinMode(30, OUTPUT);
    pinMode(32, OUTPUT);
   
    pinMode(Button1, INPUT_PULLUP);
    pinMode(Button2, INPUT_PULLUP);
    pinMode(Button3, INPUT_PULLUP);
    pinMode(Button4, INPUT_PULLUP);
    
      
    lcd.begin();
    lcd.backlight();
  
    digitalWrite(8, LOW); delay(100); digitalWrite(8, HIGH); delay(100); digitalWrite(8, LOW); delay(100); digitalWrite(8, HIGH);
  
    lcd.setCursor(0, 0); lcd.print("By");
    lcd.setCursor(0, 1); lcd.print("Gilberto Coelho");

    delay(3000);
  
time1 = EEPROM.read(memoriatime1);    
time2 = EEPROM.read(memoriatime2);
time3 = EEPROM.read(memoriatime3);
time4 = EEPROM.read(memoriatime4);
time5 = EEPROM.read(memoriatime5);
time6 = EEPROM.read(memoriatime6);    
time7 = EEPROM.read(memoriatime7);
time8 = EEPROM.read(memoriatime8);
time9 = EEPROM.read(memoriatime9);
time10 = EEPROM.read(memoriatime10);
time11 = EEPROM.read(memoriatime11);    
time12 = EEPROM.read(memoriatime12);
     
 
relay1_1 = EEPROM.read(memoriarelay1_1);  
relay2_1 = EEPROM.read(memoriarelay2_1);
relay3_1 = EEPROM.read(memoriarelay3_1);  
relay4_1 = EEPROM.read(memoriarelay4_1);
relay5_1 = EEPROM.read(memoriarelay5_1);
relay6_1 = EEPROM.read(memoriarelay6_1);

relay1_2 = EEPROM.read(memoriarelay1_2);  
relay2_2 = EEPROM.read(memoriarelay2_2);  
relay3_2 = EEPROM.read(memoriarelay3_2);  
relay4_2 = EEPROM.read(memoriarelay4_2);
relay5_2 = EEPROM.read(memoriarelay5_2);
relay6_2 = EEPROM.read(memoriarelay6_2);

relay1_3 = EEPROM.read(memoriarelay1_3);  
relay2_3 = EEPROM.read(memoriarelay2_3);  
relay3_3 = EEPROM.read(memoriarelay3_3);  
relay4_3 = EEPROM.read(memoriarelay4_3);
relay5_3 = EEPROM.read(memoriarelay5_3);
relay6_3 = EEPROM.read(memoriarelay6_3);

relay1_4 = EEPROM.read(memoriarelay1_4);  
relay2_4 = EEPROM.read(memoriarelay2_4);  
relay3_4 = EEPROM.read(memoriarelay3_4);  
relay4_4 = EEPROM.read(memoriarelay4_4);
relay5_4 = EEPROM.read(memoriarelay5_4);
relay6_4 = EEPROM.read(memoriarelay6_4);

relay1_5 = EEPROM.read(memoriarelay1_5);  
relay2_5 = EEPROM.read(memoriarelay2_5);  
relay3_5 = EEPROM.read(memoriarelay3_5);  
relay4_5 = EEPROM.read(memoriarelay4_5);
relay5_5 = EEPROM.read(memoriarelay5_5);
relay6_5 = EEPROM.read(memoriarelay6_5);

relay1_6 = EEPROM.read(memoriarelay1_6);  
relay2_6 = EEPROM.read(memoriarelay2_6);  
relay3_6 = EEPROM.read(memoriarelay3_6);  
relay4_6 = EEPROM.read(memoriarelay4_6);
relay5_6 = EEPROM.read(memoriarelay5_6);
relay6_6 = EEPROM.read(memoriarelay6_6);

relay1_7 = EEPROM.read(memoriarelay1_7);  
relay2_7 = EEPROM.read(memoriarelay2_7);  
relay3_7 = EEPROM.read(memoriarelay3_7);  
relay4_7 = EEPROM.read(memoriarelay4_7);
relay5_7 = EEPROM.read(memoriarelay5_7);
relay6_7 = EEPROM.read(memoriarelay6_7);

relay1_8 = EEPROM.read(memoriarelay1_8);  
relay2_8 = EEPROM.read(memoriarelay2_8);  
relay3_8 = EEPROM.read(memoriarelay3_8);  
relay4_8 = EEPROM.read(memoriarelay4_8);
relay5_8 = EEPROM.read(memoriarelay5_8);
relay6_8 = EEPROM.read(memoriarelay6_8);

relay1_9 = EEPROM.read(memoriarelay1_9);  
relay2_9 = EEPROM.read(memoriarelay2_9);  
relay3_9 = EEPROM.read(memoriarelay3_9);  
relay4_9 = EEPROM.read(memoriarelay4_9);
relay5_9 = EEPROM.read(memoriarelay5_9);
relay6_9 = EEPROM.read(memoriarelay6_9);

relay1_10 = EEPROM.read(memoriarelay1_10);  
relay2_10 = EEPROM.read(memoriarelay2_10);  
relay3_10 = EEPROM.read(memoriarelay3_10);  
relay4_10 = EEPROM.read(memoriarelay4_10);
relay5_10 = EEPROM.read(memoriarelay5_10);
relay6_10 = EEPROM.read(memoriarelay6_10);

relay1_11 = EEPROM.read(memoriarelay1_11);  
relay2_11 = EEPROM.read(memoriarelay2_11);  
relay3_11 = EEPROM.read(memoriarelay3_11);  
relay4_11 = EEPROM.read(memoriarelay4_11);
relay5_11 = EEPROM.read(memoriarelay5_11);
relay6_11 = EEPROM.read(memoriarelay6_11);

relay1_12 = EEPROM.read(memoriarelay1_12);  
relay2_12 = EEPROM.read(memoriarelay2_12);  
relay3_12 = EEPROM.read(memoriarelay3_12);  
relay4_12 = EEPROM.read(memoriarelay4_12);
relay5_12 = EEPROM.read(memoriarelay5_12);
relay6_12 = EEPROM.read(memoriarelay6_12);
  
way1_1 = EEPROM.read(memoriaway1_1);  
way2_1 = EEPROM.read(memoriaway2_1);
way3_1 = EEPROM.read(memoriaway3_1);  
way4_1 = EEPROM.read(memoriaway4_1);

way1_2 = EEPROM.read(memoriaway1_2);  
way2_2 = EEPROM.read(memoriaway2_2);  
way3_2 = EEPROM.read(memoriaway3_2);  
way4_2 = EEPROM.read(memoriaway4_2);

way1_3 = EEPROM.read(memoriaway1_3);  
way2_3 = EEPROM.read(memoriaway2_3);  
way3_3 = EEPROM.read(memoriaway3_3);  
way4_3 = EEPROM.read(memoriaway4_3);

way1_4 = EEPROM.read(memoriaway1_4);  
way2_4 = EEPROM.read(memoriaway2_4);  
way3_4 = EEPROM.read(memoriaway3_4);  
way4_4 = EEPROM.read(memoriaway4_4);

way1_5 = EEPROM.read(memoriaway1_5);  
way2_5 = EEPROM.read(memoriaway2_5);  
way3_5 = EEPROM.read(memoriaway3_5);  
way4_5 = EEPROM.read(memoriaway4_5);

way1_6 = EEPROM.read(memoriaway1_6);  
way2_6 = EEPROM.read(memoriaway2_6);  
way3_6 = EEPROM.read(memoriaway3_6);  
way4_6 = EEPROM.read(memoriaway4_6);

way1_7 = EEPROM.read(memoriaway1_7);  
way2_7 = EEPROM.read(memoriaway2_7);  
way3_7 = EEPROM.read(memoriaway3_7);  
way4_7 = EEPROM.read(memoriaway4_7);

way1_8 = EEPROM.read(memoriaway1_8);  
way2_8 = EEPROM.read(memoriaway2_8);  
way3_8 = EEPROM.read(memoriaway3_8);  
way4_8 = EEPROM.read(memoriaway4_8);

way1_9 = EEPROM.read(memoriaway1_9);  
way2_9 = EEPROM.read(memoriaway2_9);  
way3_9 = EEPROM.read(memoriaway3_9);  
way4_9 = EEPROM.read(memoriaway4_9);

way1_10 = EEPROM.read(memoriaway1_10);  
way2_10 = EEPROM.read(memoriaway2_10);  
way3_10 = EEPROM.read(memoriaway3_10);  
way4_10 = EEPROM.read(memoriaway4_10);

way1_11 = EEPROM.read(memoriaway1_11);  
way2_11 = EEPROM.read(memoriaway2_11);  
way3_11 = EEPROM.read(memoriaway3_11);  
way4_11 = EEPROM.read(memoriaway4_11);

way1_12 = EEPROM.read(memoriaway1_12);  
way2_12 = EEPROM.read(memoriaway2_12);  
way3_12 = EEPROM.read(memoriaway3_12);  
way4_12 = EEPROM.read(memoriaway4_12);
  
rpm1_1 = EEPROM.read(memoriarpm1_1);  
rpm2_1 = EEPROM.read(memoriarpm2_1);
rpm3_1 = EEPROM.read(memoriarpm3_1);  
rpm4_1 = EEPROM.read(memoriarpm4_1);

rpm1_2 = EEPROM.read(memoriarpm1_2);  
rpm2_2 = EEPROM.read(memoriarpm2_2);  
rpm3_2 = EEPROM.read(memoriarpm3_2);  
rpm4_2 = EEPROM.read(memoriarpm4_2);

rpm1_3 = EEPROM.read(memoriarpm1_3);  
rpm2_3 = EEPROM.read(memoriarpm2_3);  
rpm3_3 = EEPROM.read(memoriarpm3_3);  
rpm4_3 = EEPROM.read(memoriarpm4_3);

rpm1_4 = EEPROM.read(memoriarpm1_4);  
rpm2_4 = EEPROM.read(memoriarpm2_4);  
rpm3_4 = EEPROM.read(memoriarpm3_4);  
rpm4_4 = EEPROM.read(memoriarpm4_4);

rpm1_5 = EEPROM.read(memoriarpm1_5);  
rpm2_5 = EEPROM.read(memoriarpm2_5);  
rpm3_5 = EEPROM.read(memoriarpm3_5);  
rpm4_5 = EEPROM.read(memoriarpm4_5);

rpm1_6 = EEPROM.read(memoriarpm1_6);  
rpm2_6 = EEPROM.read(memoriarpm2_6);  
rpm3_6 = EEPROM.read(memoriarpm3_6);  
rpm4_6 = EEPROM.read(memoriarpm4_6);

rpm1_7 = EEPROM.read(memoriarpm1_7);  
rpm2_7 = EEPROM.read(memoriarpm2_7);  
rpm3_7 = EEPROM.read(memoriarpm3_7);  
rpm4_7 = EEPROM.read(memoriarpm4_7);

rpm1_8 = EEPROM.read(memoriarpm1_8);  
rpm2_8 = EEPROM.read(memoriarpm2_8);  
rpm3_8 = EEPROM.read(memoriarpm3_8);  
rpm4_8 = EEPROM.read(memoriarpm4_8);

rpm1_9 = EEPROM.read(memoriarpm1_9);  
rpm2_9 = EEPROM.read(memoriarpm2_9);  
rpm3_9 = EEPROM.read(memoriarpm3_9);  
rpm4_9 = EEPROM.read(memoriarpm4_9);

rpm1_10 = EEPROM.read(memoriarpm1_10);  
rpm2_10 = EEPROM.read(memoriarpm2_10);  
rpm3_10 = EEPROM.read(memoriarpm3_10);  
rpm4_10 = EEPROM.read(memoriarpm4_10);

rpm1_11 = EEPROM.read(memoriarpm1_11);  
rpm2_11 = EEPROM.read(memoriarpm2_11);  
rpm3_11 = EEPROM.read(memoriarpm3_11);  
rpm4_11 = EEPROM.read(memoriarpm4_11);

rpm1_12 = EEPROM.read(memoriarpm1_12);  
rpm2_12 = EEPROM.read(memoriarpm2_12);  
rpm3_12 = EEPROM.read(memoriarpm3_12);  
rpm4_12 = EEPROM.read(memoriarpm4_12);
    
Serial.begin(9600);
Serial.print("1~1"); Serial.print('\r'); delay(50);

lcd.clear();

}

void loop() {

     if (digitalRead(Button4) == LOW && tela > 1) { 
     while (digitalRead(Button4) == LOW) { lcd.setCursor(0,0); lcd.print(F("Push START      ")); lcd.setCursor(0,1); lcd.print(F("to return       "));
     if (digitalRead(Button4) == HIGH) { lcd.clear(); break; }
     if (digitalRead(Button1) == LOW) { tela=1; lcd.clear(); delay(500); break; }
     }}
          
     if (tela==1){
     lcd.setCursor(0,0);                                
     lcd.print(F("Waiting"));     
       
    if (digitalRead(Button1) == LOW) { delay(500);
    if (digitalRead(Button1) == HIGH) { digitalWrite(8, LOW); delay(200); digitalWrite(8, HIGH);
        

    // Step 1 
    if (time1 > 0){
    if (rpm1_1 > 0){ if (rpm1_1 < 10) {Serial.print("1SS1"+(String)xxx+(String)rpm1_1); Serial.print('\r'); delay(50);} else if (rpm1_1 > 9 && rpm1_1 <= 99) {Serial.print("1SS1"+(String)xx+(String)rpm1_1); Serial.print('\r'); delay(50);} else if (rpm1_1 == 100) {Serial.print("1SS1"+(String)x+(String)rpm1_1); Serial.print('\r'); delay(50);} if (way1_1 == 0){Serial.print("1J1"); Serial.print('\r'); delay(50);} else if (way1_1 == 1){Serial.print("1K1"); Serial.print('\r'); delay(50);} Serial.print("1H1"); Serial.print('\r'); delay(50);}
    if (rpm2_1 > 0){ if (rpm2_1 < 10) {Serial.print("2SS1"+(String)xxx+(String)rpm2_1); Serial.print('\r'); delay(50);} else if (rpm2_1 > 9 && rpm2_1 <= 99) {Serial.print("2SS1"+(String)xx+(String)rpm2_1); Serial.print('\r'); delay(50);} else if (rpm2_1 == 100) {Serial.print("2SS1"+(String)x+(String)rpm2_1); Serial.print('\r'); delay(50);} if (way2_1 == 0){Serial.print("2J1"); Serial.print('\r'); delay(50);} else if (way2_1 == 1){Serial.print("2K1"); Serial.print('\r'); delay(50);} Serial.print("2H1"); Serial.print('\r'); delay(50);}
    if (rpm3_1 > 0){ if (rpm3_1 < 10) {Serial.print("3SS1"+(String)xxx+(String)rpm3_1); Serial.print('\r'); delay(50);} else if (rpm3_1 > 9 && rpm3_1 <= 99) {Serial.print("3SS1"+(String)xx+(String)rpm3_1); Serial.print('\r'); delay(50);} else if (rpm3_1 == 100) {Serial.print("3SS1"+(String)x+(String)rpm3_1); Serial.print('\r'); delay(50);} if (way3_1 == 0){Serial.print("3J1"); Serial.print('\r'); delay(50);} else if (way3_1 == 1){Serial.print("3K1"); Serial.print('\r'); delay(50);} Serial.print("3H1"); Serial.print('\r'); delay(50);}
    if (rpm4_1 > 0){ if (rpm4_1 < 10) {Serial.print("4SS1"+(String)xxx+(String)rpm4_1); Serial.print('\r'); delay(50);} else if (rpm4_1 > 9 && rpm4_1 <= 99) {Serial.print("4SS1"+(String)xx+(String)rpm4_1); Serial.print('\r'); delay(50);} else if (rpm4_1 == 100) {Serial.print("4SS1"+(String)x+(String)rpm4_1); Serial.print('\r'); delay(50);} if (way4_1 == 0){Serial.print("4J1"); Serial.print('\r'); delay(50);} else if (way4_1 == 1){Serial.print("4K1"); Serial.print('\r'); delay(50);} Serial.print("4H1"); Serial.print('\r'); delay(50);}
    
    if (relay1_1 == 1){digitalWrite(22, HIGH);} if (relay2_1 == 1){digitalWrite(24, HIGH);} if (relay3_1 == 1){digitalWrite(26, HIGH);} if (relay4_1 == 1){digitalWrite(28, HIGH);} if (relay5_1 == 1){digitalWrite(30, HIGH);} if (relay6_1 == 1){digitalWrite(32, HIGH);}
    
    lcd.setCursor(0, 0); lcd.print(F("==== Step 1 ====")); digitalWrite(2, !relay1_1); digitalWrite(3, !relay2_1); digitalWrite(4, !relay3_1); digitalWrite(5, !relay4_1); digitalWrite(6, !relay5_1); digitalWrite(7, !relay6_1);

    for (int i = 0; i <= 255; i++){                        
                            
    statebutton2 = digitalRead(Button2); if (statebutton2 == LOW){}  else { if ((i+1) <= time1) { lcd.setCursor(0, 1); lcd.print("Time: "); lcd.print(time1 - i); lcd.print("  "); delay(1000); } }
          
    }} lcd.clear();         

    // Step 2
    if (digitalRead(Button2) == HIGH && time2 > 0){
    if (rpm1_2 == 0){Serial.print("1I1"); Serial.print('\r'); delay(50);} 
    if (rpm2_2 == 0){Serial.print("2I1"); Serial.print('\r'); delay(50);} 
    if (rpm3_2 == 0){Serial.print("3I1"); Serial.print('\r'); delay(50);} 
    if (rpm4_2 == 0){Serial.print("4I1"); Serial.print('\r'); delay(50);}
    if (rpm1_2 > 0){ if (rpm1_2 < 10) {Serial.print("1SS1"+(String)xxx+(String)rpm1_2); Serial.print('\r'); delay(50);} else if (rpm1_2 > 9 && rpm1_2 <= 99) {Serial.print("1SS1"+(String)xx+(String)rpm1_2); Serial.print('\r'); delay(50);} else if (rpm1_2 == 100) {Serial.print("1SS1"+(String)x+(String)rpm1_2); Serial.print('\r'); delay(50);} if (way1_2 == 0){Serial.print("1J1"); Serial.print('\r'); delay(50);} else if (way1_2 == 1){Serial.print("1K1"); Serial.print('\r'); delay(50);} Serial.print("1H1"); Serial.print('\r'); delay(50);}
    if (rpm2_2 > 0){ if (rpm2_2 < 10) {Serial.print("2SS1"+(String)xxx+(String)rpm2_2); Serial.print('\r'); delay(50);} else if (rpm2_2 > 9 && rpm2_2 <= 99) {Serial.print("2SS1"+(String)xx+(String)rpm2_2); Serial.print('\r'); delay(50);} else if (rpm2_2 == 100) {Serial.print("2SS1"+(String)x+(String)rpm2_2); Serial.print('\r'); delay(50);} if (way2_2 == 0){Serial.print("2J1"); Serial.print('\r'); delay(50);} else if (way2_2 == 1){Serial.print("2K1"); Serial.print('\r'); delay(50);} Serial.print("2H1"); Serial.print('\r'); delay(50);}
    if (rpm3_2 > 0){ if (rpm3_2 < 10) {Serial.print("3SS1"+(String)xxx+(String)rpm3_2); Serial.print('\r'); delay(50);} else if (rpm3_2 > 9 && rpm3_2 <= 99) {Serial.print("3SS1"+(String)xx+(String)rpm3_2); Serial.print('\r'); delay(50);} else if (rpm3_2 == 100) {Serial.print("3SS1"+(String)x+(String)rpm3_2); Serial.print('\r'); delay(50);} if (way3_2 == 0){Serial.print("3J1"); Serial.print('\r'); delay(50);} else if (way3_2 == 1){Serial.print("3K1"); Serial.print('\r'); delay(50);} Serial.print("3H1"); Serial.print('\r'); delay(50);}
    if (rpm4_2 > 0){ if (rpm4_2 < 10) {Serial.print("4SS1"+(String)xxx+(String)rpm4_2); Serial.print('\r'); delay(50);} else if (rpm4_2 > 9 && rpm4_2 <= 99) {Serial.print("4SS1"+(String)xx+(String)rpm4_2); Serial.print('\r'); delay(50);} else if (rpm4_2 == 100) {Serial.print("4SS1"+(String)x+(String)rpm4_2); Serial.print('\r'); delay(50);} if (way4_2 == 0){Serial.print("4J1"); Serial.print('\r'); delay(50);} else if (way4_2 == 1){Serial.print("4K1"); Serial.print('\r'); delay(50);} Serial.print("4H1"); Serial.print('\r'); delay(50);} 
        
    digitalWrite(22, LOW); digitalWrite(24, LOW); digitalWrite(26, LOW); digitalWrite(28, LOW); digitalWrite(30, LOW); digitalWrite(32, LOW);
    if (relay1_2 == 1){digitalWrite(22, HIGH);} if (relay2_2 == 1){digitalWrite(24, HIGH);} if (relay3_2 == 1){digitalWrite(26, HIGH);} if (relay4_2 == 1){digitalWrite(28, HIGH);} if (relay5_2 == 1){digitalWrite(30, HIGH);} if (relay6_2 == 1){digitalWrite(32, HIGH);}
    
    lcd.setCursor(0, 0); lcd.print(F("==== Step 2 ====")); digitalWrite(2, !relay1_2); digitalWrite(3, !relay2_2); digitalWrite(4, !relay3_2); digitalWrite(5, !relay4_2); digitalWrite(6, !relay5_2); digitalWrite(7, !relay6_2);

    for (int i = 0; i <= 255; i++){                        
                            
    statebutton2 = digitalRead(Button2); if (statebutton2 == LOW){}  else { if ((i+1) <= time2) { lcd.setCursor(0, 1); lcd.print("Time: "); lcd.print(time2 - i); lcd.print("  "); delay(1000); } }
          
    }} lcd.clear();                                         

    // Step 3
    if (digitalRead(Button2) == HIGH && time3 > 0){ 
    if (rpm1_3 == 0){Serial.print("1I1"); Serial.print('\r'); delay(50);} 
    if (rpm2_3 == 0){Serial.print("2I1"); Serial.print('\r'); delay(50);} 
    if (rpm3_3 == 0){Serial.print("3I1"); Serial.print('\r'); delay(50);} 
    if (rpm4_3 == 0){Serial.print("4I1"); Serial.print('\r'); delay(50);}
    if (rpm1_3 > 0){ if (rpm1_3 < 10) {Serial.print("1SS1"+(String)xxx+(String)rpm1_3); Serial.print('\r'); delay(50);} else if (rpm1_3 > 9 && rpm1_3 <= 99) {Serial.print("1SS1"+(String)xx+(String)rpm1_3); Serial.print('\r'); delay(50);} else if (rpm1_3 == 100) {Serial.print("1SS1"+(String)x+(String)rpm1_3); Serial.print('\r'); delay(50);} if (way1_3 == 0){Serial.print("1J1"); Serial.print('\r'); delay(50);} else if (way1_3 == 1){Serial.print("1K1"); Serial.print('\r'); delay(50);} Serial.print("1H1"); Serial.print('\r'); delay(50);}
    if (rpm2_3 > 0){ if (rpm2_3 < 10) {Serial.print("2SS1"+(String)xxx+(String)rpm2_3); Serial.print('\r'); delay(50);} else if (rpm2_3 > 9 && rpm2_3 <= 99) {Serial.print("2SS1"+(String)xx+(String)rpm2_3); Serial.print('\r'); delay(50);} else if (rpm2_3 == 100) {Serial.print("2SS1"+(String)x+(String)rpm2_3); Serial.print('\r'); delay(50);} if (way2_3 == 0){Serial.print("2J1"); Serial.print('\r'); delay(50);} else if (way2_3 == 1){Serial.print("2K1"); Serial.print('\r'); delay(50);} Serial.print("2H1"); Serial.print('\r'); delay(50);}
    if (rpm3_3 > 0){ if (rpm3_3 < 10) {Serial.print("3SS1"+(String)xxx+(String)rpm3_3); Serial.print('\r'); delay(50);} else if (rpm3_3 > 9 && rpm3_3 <= 99) {Serial.print("3SS1"+(String)xx+(String)rpm3_3); Serial.print('\r'); delay(50);} else if (rpm3_3 == 100) {Serial.print("3SS1"+(String)x+(String)rpm3_3); Serial.print('\r'); delay(50);} if (way3_3 == 0){Serial.print("3J1"); Serial.print('\r'); delay(50);} else if (way3_3 == 1){Serial.print("3K1"); Serial.print('\r'); delay(50);} Serial.print("3H1"); Serial.print('\r'); delay(50);}
    if (rpm4_3 > 0){ if (rpm4_3 < 10) {Serial.print("4SS1"+(String)xxx+(String)rpm4_3); Serial.print('\r'); delay(50);} else if (rpm4_3 > 9 && rpm4_3 <= 99) {Serial.print("4SS1"+(String)xx+(String)rpm4_3); Serial.print('\r'); delay(50);} else if (rpm4_3 == 100) {Serial.print("4SS1"+(String)x+(String)rpm4_3); Serial.print('\r'); delay(50);} if (way4_3 == 0){Serial.print("4J1"); Serial.print('\r'); delay(50);} else if (way4_3 == 1){Serial.print("4K1"); Serial.print('\r'); delay(50);} Serial.print("4H1"); Serial.print('\r'); delay(50);}                                    
            
    digitalWrite(22, LOW); digitalWrite(24, LOW); digitalWrite(26, LOW); digitalWrite(28, LOW); digitalWrite(30, LOW); digitalWrite(32, LOW);
    if (relay1_3 == 1){digitalWrite(22, HIGH);} if (relay2_3 == 1){digitalWrite(24, HIGH);} if (relay3_3 == 1){digitalWrite(26, HIGH);} if (relay4_3 == 1){digitalWrite(28, HIGH);} if (relay5_3 == 1){digitalWrite(30, HIGH);} if (relay6_3 == 1){digitalWrite(32, HIGH);}
    
    lcd.setCursor(0, 0); lcd.print(F("==== Step 3 ====")); digitalWrite(2, !relay1_3); digitalWrite(3, !relay2_3); digitalWrite(4, !relay3_3); digitalWrite(5, !relay4_3); digitalWrite(6, !relay5_3); digitalWrite(7, !relay6_3);

    for (int i = 0; i <= 255; i++){                        
                            
    statebutton2 = digitalRead(Button2); if (statebutton2 == LOW){}  else { if ((i+1) <= time3) { lcd.setCursor(0, 1); lcd.print("Time: "); lcd.print(time3 - i); lcd.print("  "); delay(1000); } }
          
    }} lcd.clear();    
      
    // Step 4
    if (digitalRead(Button2) == HIGH && time4 > 0){
    if (rpm1_4 == 0){Serial.print("1I1"); Serial.print('\r'); delay(50);} 
    if (rpm2_4 == 0){Serial.print("2I1"); Serial.print('\r'); delay(50);} 
    if (rpm3_4 == 0){Serial.print("3I1"); Serial.print('\r'); delay(50);} 
    if (rpm4_4 == 0){Serial.print("4I1"); Serial.print('\r'); delay(50);}
    if (rpm1_4 > 0){ if (rpm1_4 < 10) {Serial.print("1SS1"+(String)xxx+(String)rpm1_4); Serial.print('\r'); delay(50);} else if (rpm1_4 > 9 && rpm1_4 <= 99) {Serial.print("1SS1"+(String)xx+(String)rpm1_4); Serial.print('\r'); delay(50);} else if (rpm1_4 == 100) {Serial.print("1SS1"+(String)x+(String)rpm1_4); Serial.print('\r'); delay(50);} if (way1_4 == 0){Serial.print("1J1"); Serial.print('\r'); delay(50);} else if (way1_4 == 1){Serial.print("1K1"); Serial.print('\r'); delay(50);} Serial.print("1H1"); Serial.print('\r'); delay(50);}
    if (rpm2_4 > 0){ if (rpm2_4 < 10) {Serial.print("2SS1"+(String)xxx+(String)rpm2_4); Serial.print('\r'); delay(50);} else if (rpm2_4 > 9 && rpm2_4 <= 99) {Serial.print("2SS1"+(String)xx+(String)rpm2_4); Serial.print('\r'); delay(50);} else if (rpm2_4 == 100) {Serial.print("2SS1"+(String)x+(String)rpm2_4); Serial.print('\r'); delay(50);} if (way2_4 == 0){Serial.print("2J1"); Serial.print('\r'); delay(50);} else if (way2_4 == 1){Serial.print("2K1"); Serial.print('\r'); delay(50);} Serial.print("2H1"); Serial.print('\r'); delay(50);}
    if (rpm3_4 > 0){ if (rpm3_4 < 10) {Serial.print("3SS1"+(String)xxx+(String)rpm3_4); Serial.print('\r'); delay(50);} else if (rpm3_4 > 9 && rpm3_4 <= 99) {Serial.print("3SS1"+(String)xx+(String)rpm3_4); Serial.print('\r'); delay(50);} else if (rpm3_4 == 100) {Serial.print("3SS1"+(String)x+(String)rpm3_4); Serial.print('\r'); delay(50);} if (way3_4 == 0){Serial.print("3J1"); Serial.print('\r'); delay(50);} else if (way3_4 == 1){Serial.print("3K1"); Serial.print('\r'); delay(50);} Serial.print("3H1"); Serial.print('\r'); delay(50);}
    if (rpm4_4 > 0){ if (rpm4_4 < 10) {Serial.print("4SS1"+(String)xxx+(String)rpm4_4); Serial.print('\r'); delay(50);} else if (rpm4_4 > 9 && rpm4_4 <= 99) {Serial.print("4SS1"+(String)xx+(String)rpm4_4); Serial.print('\r'); delay(50);} else if (rpm4_4 == 100) {Serial.print("4SS1"+(String)x+(String)rpm4_4); Serial.print('\r'); delay(50);} if (way4_4 == 0){Serial.print("4J1"); Serial.print('\r'); delay(50);} else if (way4_4 == 1){Serial.print("4K1"); Serial.print('\r'); delay(50);} Serial.print("4H1"); Serial.print('\r'); delay(50);}                                     
                
    digitalWrite(22, LOW); digitalWrite(24, LOW); digitalWrite(26, LOW); digitalWrite(28, LOW); digitalWrite(30, LOW); digitalWrite(32, LOW);
    if (relay1_4 == 1){digitalWrite(22, HIGH);} if (relay2_4 == 1){digitalWrite(24, HIGH);} if (relay3_4 == 1){digitalWrite(26, HIGH);} if (relay4_4 == 1){digitalWrite(28, HIGH);} if (relay5_4 == 1){digitalWrite(30, HIGH);} if (relay6_4 == 1){digitalWrite(32, HIGH);}
    
    lcd.setCursor(0, 0); lcd.print(F("==== Step 4 ====")); digitalWrite(2, !relay1_4); digitalWrite(3, !relay2_4); digitalWrite(4, !relay3_4); digitalWrite(5, !relay4_4); digitalWrite(6, !relay5_4); digitalWrite(7, !relay6_4);

    for (int i = 0; i <= 255; i++){                        
                            
    statebutton2 = digitalRead(Button2); if (statebutton2 == LOW){}  else { if ((i+1) <= time4) { lcd.setCursor(0, 1); lcd.print("Time: "); lcd.print(time4 - i); lcd.print("  "); delay(1000); } }
          
    }} lcd.clear();                                      
        
    // Step 5
    if (digitalRead(Button2) == HIGH && time5 > 0){
    if (rpm1_5 == 0){Serial.print("1I1"); Serial.print('\r'); delay(50);} 
    if (rpm2_5 == 0){Serial.print("2I1"); Serial.print('\r'); delay(50);} 
    if (rpm3_5 == 0){Serial.print("3I1"); Serial.print('\r'); delay(50);} 
    if (rpm4_5 == 0){Serial.print("4I1"); Serial.print('\r'); delay(50);}
    if (rpm1_5 > 0){ if (rpm1_5 < 10) {Serial.print("1SS1"+(String)xxx+(String)rpm1_5); Serial.print('\r'); delay(50);} else if (rpm1_5 > 9 && rpm1_5 <= 99) {Serial.print("1SS1"+(String)xx+(String)rpm1_5); Serial.print('\r'); delay(50);} else if (rpm1_5 == 100) {Serial.print("1SS1"+(String)x+(String)rpm1_5); Serial.print('\r'); delay(50);} if (way1_5 == 0){Serial.print("1J1"); Serial.print('\r'); delay(50);} else if (way1_5 == 1){Serial.print("1K1"); Serial.print('\r'); delay(50);} Serial.print("1H1"); Serial.print('\r'); delay(50);}
    if (rpm2_5 > 0){ if (rpm2_5 < 10) {Serial.print("2SS1"+(String)xxx+(String)rpm2_5); Serial.print('\r'); delay(50);} else if (rpm2_5 > 9 && rpm2_5 <= 99) {Serial.print("2SS1"+(String)xx+(String)rpm2_5); Serial.print('\r'); delay(50);} else if (rpm2_5 == 100) {Serial.print("2SS1"+(String)x+(String)rpm2_5); Serial.print('\r'); delay(50);} if (way2_5 == 0){Serial.print("2J1"); Serial.print('\r'); delay(50);} else if (way2_5 == 1){Serial.print("2K1"); Serial.print('\r'); delay(50);} Serial.print("2H1"); Serial.print('\r'); delay(50);}
    if (rpm3_5 > 0){ if (rpm3_5 < 10) {Serial.print("3SS1"+(String)xxx+(String)rpm3_5); Serial.print('\r'); delay(50);} else if (rpm3_5 > 9 && rpm3_5 <= 99) {Serial.print("3SS1"+(String)xx+(String)rpm3_5); Serial.print('\r'); delay(50);} else if (rpm3_5 == 100) {Serial.print("3SS1"+(String)x+(String)rpm3_5); Serial.print('\r'); delay(50);} if (way3_5 == 0){Serial.print("3J1"); Serial.print('\r'); delay(50);} else if (way3_5 == 1){Serial.print("3K1"); Serial.print('\r'); delay(50);} Serial.print("3H1"); Serial.print('\r'); delay(50);}
    if (rpm4_5 > 0){ if (rpm4_5 < 10) {Serial.print("4SS1"+(String)xxx+(String)rpm4_5); Serial.print('\r'); delay(50);} else if (rpm4_5 > 9 && rpm4_5 <= 99) {Serial.print("4SS1"+(String)xx+(String)rpm4_5); Serial.print('\r'); delay(50);} else if (rpm4_5 == 100) {Serial.print("4SS1"+(String)x+(String)rpm4_5); Serial.print('\r'); delay(50);} if (way4_5 == 0){Serial.print("4J1"); Serial.print('\r'); delay(50);} else if (way4_5 == 1){Serial.print("4K1"); Serial.print('\r'); delay(50);} Serial.print("4H1"); Serial.print('\r'); delay(50);}                                     
                    
    digitalWrite(22, LOW); digitalWrite(24, LOW); digitalWrite(26, LOW); digitalWrite(28, LOW); digitalWrite(30, LOW); digitalWrite(32, LOW);
    if (relay1_5 == 1){digitalWrite(22, HIGH);} if (relay2_5 == 1){digitalWrite(24, HIGH);} if (relay3_5 == 1){digitalWrite(26, HIGH);} if (relay4_5 == 1){digitalWrite(28, HIGH);} if (relay5_5 == 1){digitalWrite(30, HIGH);} if (relay6_5 == 1){digitalWrite(32, HIGH);}
    
    lcd.setCursor(0, 0); lcd.print(F("==== Step 5 ====")); digitalWrite(2, !relay1_5); digitalWrite(3, !relay2_5); digitalWrite(4, !relay3_5); digitalWrite(5, !relay4_5); digitalWrite(6, !relay5_5); digitalWrite(7, !relay6_5);

    for (int i = 0; i <= 255; i++){                        
                            
    statebutton2 = digitalRead(Button2); if (statebutton2 == LOW){}  else { if ((i+1) <= time5) { lcd.setCursor(0, 1); lcd.print("Time: "); lcd.print(time5 - i); lcd.print("  "); delay(1000); } }
          
    }} lcd.clear();     
                      
    // Step 6
    if (digitalRead(Button2) == HIGH && time6 > 0){  
    if (rpm1_6 == 0){Serial.print("1I1"); Serial.print('\r'); delay(50);} 
    if (rpm2_6 == 0){Serial.print("2I1"); Serial.print('\r'); delay(50);} 
    if (rpm3_6 == 0){Serial.print("3I1"); Serial.print('\r'); delay(50);} 
    if (rpm4_6 == 0){Serial.print("4I1"); Serial.print('\r'); delay(50);}
    if (rpm1_6 > 0){ if (rpm1_6 < 10) {Serial.print("1SS1"+(String)xxx+(String)rpm1_6); Serial.print('\r'); delay(50);} else if (rpm1_6 > 9 && rpm1_6 <= 99) {Serial.print("1SS1"+(String)xx+(String)rpm1_6); Serial.print('\r'); delay(50);} else if (rpm1_6 == 100) {Serial.print("1SS1"+(String)x+(String)rpm1_6); Serial.print('\r'); delay(50);} if (way1_6 == 0){Serial.print("1J1"); Serial.print('\r'); delay(50);} else if (way1_6 == 1){Serial.print("1K1"); Serial.print('\r'); delay(50);} Serial.print("1H1"); Serial.print('\r'); delay(50);}
    if (rpm2_6 > 0){ if (rpm2_6 < 10) {Serial.print("2SS1"+(String)xxx+(String)rpm2_6); Serial.print('\r'); delay(50);} else if (rpm2_6 > 9 && rpm2_6 <= 99) {Serial.print("2SS1"+(String)xx+(String)rpm2_6); Serial.print('\r'); delay(50);} else if (rpm2_6 == 100) {Serial.print("2SS1"+(String)x+(String)rpm2_6); Serial.print('\r'); delay(50);} if (way2_6 == 0){Serial.print("2J1"); Serial.print('\r'); delay(50);} else if (way2_6 == 1){Serial.print("2K1"); Serial.print('\r'); delay(50);} Serial.print("2H1"); Serial.print('\r'); delay(50);}
    if (rpm3_6 > 0){ if (rpm3_6 < 10) {Serial.print("3SS1"+(String)xxx+(String)rpm3_6); Serial.print('\r'); delay(50);} else if (rpm3_6 > 9 && rpm3_6 <= 99) {Serial.print("3SS1"+(String)xx+(String)rpm3_6); Serial.print('\r'); delay(50);} else if (rpm3_6 == 100) {Serial.print("3SS1"+(String)x+(String)rpm3_6); Serial.print('\r'); delay(50);} if (way3_6 == 0){Serial.print("3J1"); Serial.print('\r'); delay(50);} else if (way3_6 == 1){Serial.print("3K1"); Serial.print('\r'); delay(50);} Serial.print("3H1"); Serial.print('\r'); delay(50);}
    if (rpm4_6 > 0){ if (rpm4_6 < 10) {Serial.print("4SS1"+(String)xxx+(String)rpm4_6); Serial.print('\r'); delay(50);} else if (rpm4_6 > 9 && rpm4_6 <= 99) {Serial.print("4SS1"+(String)xx+(String)rpm4_6); Serial.print('\r'); delay(50);} else if (rpm4_6 == 100) {Serial.print("4SS1"+(String)x+(String)rpm4_6); Serial.print('\r'); delay(50);} if (way4_6 == 0){Serial.print("4J1"); Serial.print('\r'); delay(50);} else if (way4_6 == 1){Serial.print("4K1"); Serial.print('\r'); delay(50);} Serial.print("4H1"); Serial.print('\r'); delay(50);}                                   
                        
    digitalWrite(22, LOW); digitalWrite(24, LOW); digitalWrite(26, LOW); digitalWrite(28, LOW); digitalWrite(30, LOW); digitalWrite(32, LOW);
    if (relay1_6 == 1){digitalWrite(22, HIGH);} if (relay2_6 == 1){digitalWrite(24, HIGH);} if (relay3_6 == 1){digitalWrite(26, HIGH);} if (relay4_6 == 1){digitalWrite(28, HIGH);} if (relay5_6 == 1){digitalWrite(30, HIGH);} if (relay6_6 == 1){digitalWrite(32, HIGH);}
    
    lcd.setCursor(0, 0); lcd.print(F("==== Step 6 ====")); digitalWrite(2, !relay1_6); digitalWrite(3, !relay2_6); digitalWrite(4, !relay3_6); digitalWrite(5, !relay4_6); digitalWrite(6, !relay5_6); digitalWrite(7, !relay6_6);

    for (int i = 0; i <= 255; i++){                        
                            
    statebutton2 = digitalRead(Button2); if (statebutton2 == LOW){}  else { if ((i+1) <= time6) { lcd.setCursor(0, 1); lcd.print("Time: "); lcd.print(time6 - i); lcd.print("  "); delay(1000); } }
          
    }} lcd.clear();                        
                            
    // Step 7
    if (digitalRead(Button2) == HIGH && time7 > 0){ 
    if (rpm1_7 == 0){Serial.print("1I1"); Serial.print('\r'); delay(50);} 
    if (rpm2_7 == 0){Serial.print("2I1"); Serial.print('\r'); delay(50);} 
    if (rpm3_7 == 0){Serial.print("3I1"); Serial.print('\r'); delay(50);} 
    if (rpm4_7 == 0){Serial.print("4I1"); Serial.print('\r'); delay(50);}
    if (rpm1_7 > 0){ if (rpm1_7 < 10) {Serial.print("1SS1"+(String)xxx+(String)rpm1_7); Serial.print('\r'); delay(50);} else if (rpm1_7 > 9 && rpm1_7 <= 99) {Serial.print("1SS1"+(String)xx+(String)rpm1_7); Serial.print('\r'); delay(50);} else if (rpm1_7 == 100) {Serial.print("1SS1"+(String)x+(String)rpm1_7); Serial.print('\r'); delay(50);} if (way1_7 == 0){Serial.print("1J1"); Serial.print('\r'); delay(50);} else if (way1_7 == 1){Serial.print("1K1"); Serial.print('\r'); delay(50);} Serial.print("1H1"); Serial.print('\r'); delay(50);}
    if (rpm2_7 > 0){ if (rpm2_7 < 10) {Serial.print("2SS1"+(String)xxx+(String)rpm2_7); Serial.print('\r'); delay(50);} else if (rpm2_7 > 9 && rpm2_7 <= 99) {Serial.print("2SS1"+(String)xx+(String)rpm2_7); Serial.print('\r'); delay(50);} else if (rpm2_7 == 100) {Serial.print("2SS1"+(String)x+(String)rpm2_7); Serial.print('\r'); delay(50);} if (way2_7 == 0){Serial.print("2J1"); Serial.print('\r'); delay(50);} else if (way2_7 == 1){Serial.print("2K1"); Serial.print('\r'); delay(50);} Serial.print("2H1"); Serial.print('\r'); delay(50);}
    if (rpm3_7 > 0){ if (rpm3_7 < 10) {Serial.print("3SS1"+(String)xxx+(String)rpm3_7); Serial.print('\r'); delay(50);} else if (rpm3_7 > 9 && rpm3_7 <= 99) {Serial.print("3SS1"+(String)xx+(String)rpm3_7); Serial.print('\r'); delay(50);} else if (rpm3_7 == 100) {Serial.print("3SS1"+(String)x+(String)rpm3_7); Serial.print('\r'); delay(50);} if (way3_7 == 0){Serial.print("3J1"); Serial.print('\r'); delay(50);} else if (way3_7 == 1){Serial.print("3K1"); Serial.print('\r'); delay(50);} Serial.print("3H1"); Serial.print('\r'); delay(50);}
    if (rpm4_7 > 0){ if (rpm4_7 < 10) {Serial.print("4SS1"+(String)xxx+(String)rpm4_7); Serial.print('\r'); delay(50);} else if (rpm4_7 > 9 && rpm4_7 <= 99) {Serial.print("4SS1"+(String)xx+(String)rpm4_7); Serial.print('\r'); delay(50);} else if (rpm4_7 == 100) {Serial.print("4SS1"+(String)x+(String)rpm4_7); Serial.print('\r'); delay(50);} if (way4_7 == 0){Serial.print("4J1"); Serial.print('\r'); delay(50);} else if (way4_7 == 1){Serial.print("4K1"); Serial.print('\r'); delay(50);} Serial.print("4H1"); Serial.print('\r'); delay(50);}                                    
                            
    digitalWrite(22, LOW); digitalWrite(24, LOW); digitalWrite(26, LOW); digitalWrite(28, LOW); digitalWrite(30, LOW); digitalWrite(32, LOW);
    if (relay1_7 == 1){digitalWrite(22, HIGH);} if (relay2_7 == 1){digitalWrite(24, HIGH);} if (relay3_7 == 1){digitalWrite(26, HIGH);} if (relay4_7 == 1){digitalWrite(28, HIGH);} if (relay5_7 == 1){digitalWrite(30, HIGH);} if (relay6_7 == 1){digitalWrite(32, HIGH);}
    
    lcd.setCursor(0, 0); lcd.print(F("==== Step 7 ====")); digitalWrite(2, !relay1_7); digitalWrite(3, !relay2_7); digitalWrite(4, !relay3_7); digitalWrite(5, !relay4_7); digitalWrite(6, !relay5_7); digitalWrite(7, !relay6_7);

    for (int i = 0; i <= 255; i++){                        
                            
    statebutton2 = digitalRead(Button2); if (statebutton2 == LOW){}  else { if ((i+1) <= time7) { lcd.setCursor(0, 1); lcd.print("Time: "); lcd.print(time7 - i); lcd.print("  "); delay(1000); } }
          
    }} lcd.clear();
                                         
    // Step 8
    if (digitalRead(Button2) == HIGH && time8 > 0){
    if (rpm1_8 == 0){Serial.print("1I1"); Serial.print('\r'); delay(50);} 
    if (rpm2_8 == 0){Serial.print("2I1"); Serial.print('\r'); delay(50);} 
    if (rpm3_8 == 0){Serial.print("3I1"); Serial.print('\r'); delay(50);} 
    if (rpm4_8 == 0){Serial.print("4I1"); Serial.print('\r'); delay(50);}
    if (rpm1_8 > 0){ if (rpm1_8 < 10) {Serial.print("1SS1"+(String)xxx+(String)rpm1_8); Serial.print('\r'); delay(50);} else if (rpm1_8 > 9 && rpm1_8 <= 99) {Serial.print("1SS1"+(String)xx+(String)rpm1_8); Serial.print('\r'); delay(50);} else if (rpm1_8 == 100) {Serial.print("1SS1"+(String)x+(String)rpm1_8); Serial.print('\r'); delay(50);} if (way1_8 == 0){Serial.print("1J1"); Serial.print('\r'); delay(50);} else if (way1_8 == 1){Serial.print("1K1"); Serial.print('\r'); delay(50);} Serial.print("1H1"); Serial.print('\r'); delay(50);}
    if (rpm2_8 > 0){ if (rpm2_8 < 10) {Serial.print("2SS1"+(String)xxx+(String)rpm2_8); Serial.print('\r'); delay(50);} else if (rpm2_8 > 9 && rpm2_8 <= 99) {Serial.print("2SS1"+(String)xx+(String)rpm2_8); Serial.print('\r'); delay(50);} else if (rpm2_8 == 100) {Serial.print("2SS1"+(String)x+(String)rpm2_8); Serial.print('\r'); delay(50);} if (way2_8 == 0){Serial.print("2J1"); Serial.print('\r'); delay(50);} else if (way2_8 == 1){Serial.print("2K1"); Serial.print('\r'); delay(50);} Serial.print("2H1"); Serial.print('\r'); delay(50);}
    if (rpm3_8 > 0){ if (rpm3_8 < 10) {Serial.print("3SS1"+(String)xxx+(String)rpm3_8); Serial.print('\r'); delay(50);} else if (rpm3_8 > 9 && rpm3_8 <= 99) {Serial.print("3SS1"+(String)xx+(String)rpm3_8); Serial.print('\r'); delay(50);} else if (rpm3_8 == 100) {Serial.print("3SS1"+(String)x+(String)rpm3_8); Serial.print('\r'); delay(50);} if (way3_8 == 0){Serial.print("3J1"); Serial.print('\r'); delay(50);} else if (way3_8 == 1){Serial.print("3K1"); Serial.print('\r'); delay(50);} Serial.print("3H1"); Serial.print('\r'); delay(50);}
    if (rpm4_8 > 0){ if (rpm4_8 < 10) {Serial.print("4SS1"+(String)xxx+(String)rpm4_8); Serial.print('\r'); delay(50);} else if (rpm4_8 > 9 && rpm4_8 <= 99) {Serial.print("4SS1"+(String)xx+(String)rpm4_8); Serial.print('\r'); delay(50);} else if (rpm4_8 == 100) {Serial.print("4SS1"+(String)x+(String)rpm4_8); Serial.print('\r'); delay(50);} if (way4_8 == 0){Serial.print("4J1"); Serial.print('\r'); delay(50);} else if (way4_8 == 1){Serial.print("4K1"); Serial.print('\r'); delay(50);} Serial.print("4H1"); Serial.print('\r'); delay(50);}                                     
                                
    digitalWrite(22, LOW); digitalWrite(24, LOW); digitalWrite(26, LOW); digitalWrite(28, LOW); digitalWrite(30, LOW); digitalWrite(32, LOW);
    if (relay1_8 == 1){digitalWrite(22, HIGH);} if (relay2_8 == 1){digitalWrite(24, HIGH);} if (relay3_8 == 1){digitalWrite(26, HIGH);} if (relay4_8 == 1){digitalWrite(28, HIGH);} if (relay5_8 == 1){digitalWrite(30, HIGH);} if (relay6_8 == 1){digitalWrite(32, HIGH);}
    
    lcd.setCursor(0, 0); lcd.print(F("==== Step 8 ====")); digitalWrite(2, !relay1_8); digitalWrite(3, !relay2_8); digitalWrite(4, !relay3_8); digitalWrite(5, !relay4_8); digitalWrite(6, !relay5_8); digitalWrite(7, !relay6_8);

    for (int i = 0; i <= 255; i++){                        
                            
    statebutton2 = digitalRead(Button2); if (statebutton2 == LOW){}  else { if ((i+1) <= time8) { lcd.setCursor(0, 1); lcd.print("Time: "); lcd.print(time8 - i); lcd.print("  "); delay(1000); } }
          
    }} lcd.clear();                                     
                                         
    // Step 9
    if (digitalRead(Button2) == HIGH && time9 > 0){
    if (rpm1_9 == 0){Serial.print("1I1"); Serial.print('\r'); delay(50);} 
    if (rpm2_9 == 0){Serial.print("2I1"); Serial.print('\r'); delay(50);} 
    if (rpm3_9 == 0){Serial.print("3I1"); Serial.print('\r'); delay(50);} 
    if (rpm4_9 == 0){Serial.print("4I1"); Serial.print('\r'); delay(50);}
    if (rpm1_9 > 0){ if (rpm1_9 < 10) {Serial.print("1SS1"+(String)xxx+(String)rpm1_9); Serial.print('\r'); delay(50);} else if (rpm1_9 > 9 && rpm1_9 <= 99) {Serial.print("1SS1"+(String)xx+(String)rpm1_9); Serial.print('\r'); delay(50);} else if (rpm1_9 == 100) {Serial.print("1SS1"+(String)x+(String)rpm1_9); Serial.print('\r'); delay(50);} if (way1_9 == 0){Serial.print("1J1"); Serial.print('\r'); delay(50);} else if (way1_9 == 1){Serial.print("1K1"); Serial.print('\r'); delay(50);} Serial.print("1H1"); Serial.print('\r'); delay(50);}
    if (rpm2_9 > 0){ if (rpm2_9 < 10) {Serial.print("2SS1"+(String)xxx+(String)rpm2_9); Serial.print('\r'); delay(50);} else if (rpm2_9 > 9 && rpm2_9 <= 99) {Serial.print("2SS1"+(String)xx+(String)rpm2_9); Serial.print('\r'); delay(50);} else if (rpm2_9 == 100) {Serial.print("2SS1"+(String)x+(String)rpm2_9); Serial.print('\r'); delay(50);} if (way2_9 == 0){Serial.print("2J1"); Serial.print('\r'); delay(50);} else if (way2_9 == 1){Serial.print("2K1"); Serial.print('\r'); delay(50);} Serial.print("2H1"); Serial.print('\r'); delay(50);}
    if (rpm3_9 > 0){ if (rpm3_9 < 10) {Serial.print("3SS1"+(String)xxx+(String)rpm3_9); Serial.print('\r'); delay(50);} else if (rpm3_9 > 9 && rpm3_9 <= 99) {Serial.print("3SS1"+(String)xx+(String)rpm3_9); Serial.print('\r'); delay(50);} else if (rpm3_9 == 100) {Serial.print("3SS1"+(String)x+(String)rpm3_9); Serial.print('\r'); delay(50);} if (way3_9 == 0){Serial.print("3J1"); Serial.print('\r'); delay(50);} else if (way3_9 == 1){Serial.print("3K1"); Serial.print('\r'); delay(50);} Serial.print("3H1"); Serial.print('\r'); delay(50);}
    if (rpm4_9 > 0){ if (rpm4_9 < 10) {Serial.print("4SS1"+(String)xxx+(String)rpm4_9); Serial.print('\r'); delay(50);} else if (rpm4_9 > 9 && rpm4_9 <= 99) {Serial.print("4SS1"+(String)xx+(String)rpm4_9); Serial.print('\r'); delay(50);} else if (rpm4_9 == 100) {Serial.print("4SS1"+(String)x+(String)rpm4_9); Serial.print('\r'); delay(50);} if (way4_9 == 0){Serial.print("4J1"); Serial.print('\r'); delay(50);} else if (way4_9 == 1){Serial.print("4K1"); Serial.print('\r'); delay(50);} Serial.print("4H1"); Serial.print('\r'); delay(50);}                                     
                                    
    digitalWrite(22, LOW); digitalWrite(24, LOW); digitalWrite(26, LOW); digitalWrite(28, LOW); digitalWrite(30, LOW); digitalWrite(32, LOW);
    if (relay1_9 == 1){digitalWrite(22, HIGH);} if (relay2_9 == 1){digitalWrite(24, HIGH);} if (relay3_9 == 1){digitalWrite(26, HIGH);} if (relay4_9 == 1){digitalWrite(28, HIGH);} if (relay5_9 == 1){digitalWrite(30, HIGH);} if (relay6_9 == 1){digitalWrite(32, HIGH);}
    
    lcd.setCursor(0, 0); lcd.print(F("==== Step 9 ====")); digitalWrite(2, !relay1_9); digitalWrite(3, !relay2_9); digitalWrite(4, !relay3_9); digitalWrite(5, !relay4_9); digitalWrite(6, !relay5_9); digitalWrite(7, !relay6_9);

    for (int i = 0; i <= 255; i++){                        
                            
    statebutton2 = digitalRead(Button2); if (statebutton2 == LOW){}  else { if ((i+1) <= time9) { lcd.setCursor(0, 1); lcd.print("Time: "); lcd.print(time9 - i); lcd.print("  "); delay(1000); } }
          
    }} lcd.clear();  
                                         
    // Step 10
    if (digitalRead(Button2) == HIGH && time10 > 0){
    if (rpm1_10 == 0){Serial.print("1I1"); Serial.print('\r'); delay(50);} 
    if (rpm2_10 == 0){Serial.print("2I1"); Serial.print('\r'); delay(50);} 
    if (rpm3_10 == 0){Serial.print("3I1"); Serial.print('\r'); delay(50);} 
    if (rpm4_10 == 0){Serial.print("4I1"); Serial.print('\r'); delay(50);}
    if (rpm1_10 > 0){ if (rpm1_10 < 10) {Serial.print("1SS1"+(String)xxx+(String)rpm1_10); Serial.print('\r'); delay(50);} else if (rpm1_10 > 9 && rpm1_10 <= 99) {Serial.print("1SS1"+(String)xx+(String)rpm1_10); Serial.print('\r'); delay(50);} else if (rpm1_10 == 100) {Serial.print("1SS1"+(String)x+(String)rpm1_10); Serial.print('\r'); delay(50);} if (way1_10 == 0){Serial.print("1J1"); Serial.print('\r'); delay(50);} else if (way1_10 == 1){Serial.print("1K1"); Serial.print('\r'); delay(50);} Serial.print("1H1"); Serial.print('\r'); delay(50);}
    if (rpm2_10 > 0){ if (rpm2_10 < 10) {Serial.print("2SS1"+(String)xxx+(String)rpm2_10); Serial.print('\r'); delay(50);} else if (rpm2_10 > 9 && rpm2_10 <= 99) {Serial.print("2SS1"+(String)xx+(String)rpm2_10); Serial.print('\r'); delay(50);} else if (rpm2_10 == 100) {Serial.print("2SS1"+(String)x+(String)rpm2_10); Serial.print('\r'); delay(50);} if (way2_10 == 0){Serial.print("2J1"); Serial.print('\r'); delay(50);} else if (way2_10 == 1){Serial.print("2K1"); Serial.print('\r'); delay(50);} Serial.print("2H1"); Serial.print('\r'); delay(50);}
    if (rpm3_10 > 0){ if (rpm3_10 < 10) {Serial.print("3SS1"+(String)xxx+(String)rpm3_10); Serial.print('\r'); delay(50);} else if (rpm3_10 > 9 && rpm3_10 <= 99) {Serial.print("3SS1"+(String)xx+(String)rpm3_10); Serial.print('\r'); delay(50);} else if (rpm3_10 == 100) {Serial.print("3SS1"+(String)x+(String)rpm3_10); Serial.print('\r'); delay(50);} if (way3_10 == 0){Serial.print("3J1"); Serial.print('\r'); delay(50);} else if (way3_10 == 1){Serial.print("3K1"); Serial.print('\r'); delay(50);} Serial.print("3H1"); Serial.print('\r'); delay(50);}
    if (rpm4_10 > 0){ if (rpm4_10 < 10) {Serial.print("4SS1"+(String)xxx+(String)rpm4_10); Serial.print('\r'); delay(50);} else if (rpm4_10 > 9 && rpm4_10 <= 99) {Serial.print("4SS1"+(String)xx+(String)rpm4_10); Serial.print('\r'); delay(50);} else if (rpm4_10 == 100) {Serial.print("4SS1"+(String)x+(String)rpm4_10); Serial.print('\r'); delay(50);} if (way4_10 == 0){Serial.print("4J1"); Serial.print('\r'); delay(50);} else if (way4_10 == 1){Serial.print("4K1"); Serial.print('\r'); delay(50);} Serial.print("4H1"); Serial.print('\r'); delay(50);}                                     
                                        
    digitalWrite(22, LOW); digitalWrite(24, LOW); digitalWrite(26, LOW); digitalWrite(28, LOW); digitalWrite(30, LOW); digitalWrite(32, LOW);
    if (relay1_10 == 1){digitalWrite(22, HIGH);} if (relay2_10 == 1){digitalWrite(24, HIGH);} if (relay3_10 == 1){digitalWrite(26, HIGH);} if (relay4_10 == 1){digitalWrite(28, HIGH);} if (relay5_10 == 1){digitalWrite(30, HIGH);} if (relay6_10 == 1){digitalWrite(32, HIGH);}
    
    lcd.setCursor(0, 0); lcd.print(F("==== Step10 ====")); digitalWrite(2, !relay1_10); digitalWrite(3, !relay2_10); digitalWrite(4, !relay3_10); digitalWrite(5, !relay4_10); digitalWrite(6, !relay5_10); digitalWrite(7, !relay6_10);

    for (int i = 0; i <= 255; i++){                        
                            
    statebutton2 = digitalRead(Button2); if (statebutton2 == LOW){}  else { if ((i+1) <= time10) { lcd.setCursor(0, 1); lcd.print("Time: "); lcd.print(time10 - i); lcd.print("  "); delay(1000); } }
          
    }} lcd.clear();
                                         
    // Step 11
    if (digitalRead(Button2) == HIGH && time11 > 0){
    if (rpm1_11 == 0){Serial.print("1I1"); Serial.print('\r'); delay(50);} 
    if (rpm2_11 == 0){Serial.print("2I1"); Serial.print('\r'); delay(50);} 
    if (rpm3_11 == 0){Serial.print("3I1"); Serial.print('\r'); delay(50);} 
    if (rpm4_11 == 0){Serial.print("4I1"); Serial.print('\r'); delay(50);}
    if (rpm1_11 > 0){ if (rpm1_11 < 10) {Serial.print("1SS1"+(String)xxx+(String)rpm1_11); Serial.print('\r'); delay(50);} else if (rpm1_11 > 9 && rpm1_11 <= 99) {Serial.print("1SS1"+(String)xx+(String)rpm1_11); Serial.print('\r'); delay(50);} else if (rpm1_11 == 100) {Serial.print("1SS1"+(String)x+(String)rpm1_11); Serial.print('\r'); delay(50);} if (way1_11 == 0){Serial.print("1J1"); Serial.print('\r'); delay(50);} else if (way1_11 == 1){Serial.print("1K1"); Serial.print('\r'); delay(50);} Serial.print("1H1"); Serial.print('\r'); delay(50);}
    if (rpm2_11 > 0){ if (rpm2_11 < 10) {Serial.print("2SS1"+(String)xxx+(String)rpm2_11); Serial.print('\r'); delay(50);} else if (rpm2_11 > 9 && rpm2_11 <= 99) {Serial.print("2SS1"+(String)xx+(String)rpm2_11); Serial.print('\r'); delay(50);} else if (rpm2_11 == 100) {Serial.print("2SS1"+(String)x+(String)rpm2_11); Serial.print('\r'); delay(50);} if (way2_11 == 0){Serial.print("2J1"); Serial.print('\r'); delay(50);} else if (way2_11 == 1){Serial.print("2K1"); Serial.print('\r'); delay(50);} Serial.print("2H1"); Serial.print('\r'); delay(50);}
    if (rpm3_11 > 0){ if (rpm3_11 < 10) {Serial.print("3SS1"+(String)xxx+(String)rpm3_11); Serial.print('\r'); delay(50);} else if (rpm3_11 > 9 && rpm3_11 <= 99) {Serial.print("3SS1"+(String)xx+(String)rpm3_11); Serial.print('\r'); delay(50);} else if (rpm3_11 == 100) {Serial.print("3SS1"+(String)x+(String)rpm3_11); Serial.print('\r'); delay(50);} if (way3_11 == 0){Serial.print("3J1"); Serial.print('\r'); delay(50);} else if (way3_11 == 1){Serial.print("3K1"); Serial.print('\r'); delay(50);} Serial.print("3H1"); Serial.print('\r'); delay(50);}
    if (rpm4_11 > 0){ if (rpm4_11 < 10) {Serial.print("4SS1"+(String)xxx+(String)rpm4_11); Serial.print('\r'); delay(50);} else if (rpm4_11 > 9 && rpm4_11 <= 99) {Serial.print("4SS1"+(String)xx+(String)rpm4_11); Serial.print('\r'); delay(50);} else if (rpm4_11 == 100) {Serial.print("4SS1"+(String)x+(String)rpm4_11); Serial.print('\r'); delay(50);} if (way4_11 == 0){Serial.print("4J1"); Serial.print('\r'); delay(50);} else if (way4_11 == 1){Serial.print("4K1"); Serial.print('\r'); delay(50);} Serial.print("4H1"); Serial.print('\r'); delay(50);}                                     
                                            
    digitalWrite(22, LOW); digitalWrite(24, LOW); digitalWrite(26, LOW); digitalWrite(28, LOW); digitalWrite(30, LOW); digitalWrite(32, LOW);
    if (relay1_11 == 1){digitalWrite(22, HIGH);} if (relay2_11 == 1){digitalWrite(24, HIGH);} if (relay3_11 == 1){digitalWrite(26, HIGH);} if (relay4_11 == 1){digitalWrite(28, HIGH);} if (relay5_11 == 1){digitalWrite(30, HIGH);} if (relay6_11 == 1){digitalWrite(32, HIGH);}
    
    lcd.setCursor(0, 0); lcd.print(F("==== Step11 ====")); digitalWrite(2, !relay1_11); digitalWrite(3, !relay2_11); digitalWrite(4, !relay3_11); digitalWrite(5, !relay4_11); digitalWrite(6, !relay5_11); digitalWrite(7, !relay6_11);

    for (int i = 0; i <= 255; i++){                        
                            
    statebutton2 = digitalRead(Button2); if (statebutton2 == LOW){}  else { if ((i+1) <= time11) { lcd.setCursor(0, 1); lcd.print("Time: "); lcd.print(time11 - i); lcd.print("  "); delay(1000); } }
          
    }} lcd.clear();                                     
    
    // Step 12
    if (digitalRead(Button2) == HIGH && time12 > 0){
    if (rpm1_12 == 0){Serial.print("1I1"); Serial.print('\r'); delay(50);} 
    if (rpm2_12 == 0){Serial.print("2I1"); Serial.print('\r'); delay(50);} 
    if (rpm3_12 == 0){Serial.print("3I1"); Serial.print('\r'); delay(50);} 
    if (rpm4_12 == 0){Serial.print("4I1"); Serial.print('\r'); delay(50);}
    if (rpm1_12 > 0){ if (rpm1_12 < 10) {Serial.print("1SS1"+(String)xxx+(String)rpm1_12); Serial.print('\r'); delay(50);} else if (rpm1_12 > 9 && rpm1_12 <= 99) {Serial.print("1SS1"+(String)xx+(String)rpm1_12); Serial.print('\r'); delay(50);} else if (rpm1_12 == 100) {Serial.print("1SS1"+(String)x+(String)rpm1_12); Serial.print('\r'); delay(50);} if (way1_12 == 0){Serial.print("1J1"); Serial.print('\r'); delay(50);} else if (way1_12 == 1){Serial.print("1K1"); Serial.print('\r'); delay(50);} Serial.print("1H1"); Serial.print('\r'); delay(50);}
    if (rpm2_12 > 0){ if (rpm2_12 < 10) {Serial.print("2SS1"+(String)xxx+(String)rpm2_12); Serial.print('\r'); delay(50);} else if (rpm2_12 > 9 && rpm2_12 <= 99) {Serial.print("2SS1"+(String)xx+(String)rpm2_12); Serial.print('\r'); delay(50);} else if (rpm2_12 == 100) {Serial.print("2SS1"+(String)x+(String)rpm2_12); Serial.print('\r'); delay(50);} if (way2_12 == 0){Serial.print("2J1"); Serial.print('\r'); delay(50);} else if (way2_12 == 1){Serial.print("2K1"); Serial.print('\r'); delay(50);} Serial.print("2H1"); Serial.print('\r'); delay(50);}
    if (rpm3_12 > 0){ if (rpm3_12 < 10) {Serial.print("3SS1"+(String)xxx+(String)rpm3_12); Serial.print('\r'); delay(50);} else if (rpm3_12 > 9 && rpm3_12 <= 99) {Serial.print("3SS1"+(String)xx+(String)rpm3_12); Serial.print('\r'); delay(50);} else if (rpm3_12 == 100) {Serial.print("3SS1"+(String)x+(String)rpm3_12); Serial.print('\r'); delay(50);} if (way3_12 == 0){Serial.print("3J1"); Serial.print('\r'); delay(50);} else if (way3_12 == 1){Serial.print("3K1"); Serial.print('\r'); delay(50);} Serial.print("3H1"); Serial.print('\r'); delay(50);}
    if (rpm4_12 > 0){ if (rpm4_12 < 10) {Serial.print("4SS1"+(String)xxx+(String)rpm4_12); Serial.print('\r'); delay(50);} else if (rpm4_12 > 9 && rpm4_12 <= 99) {Serial.print("4SS1"+(String)xx+(String)rpm4_12); Serial.print('\r'); delay(50);} else if (rpm4_12 == 100) {Serial.print("4SS1"+(String)x+(String)rpm4_12); Serial.print('\r'); delay(50);} if (way4_12 == 0){Serial.print("4J1"); Serial.print('\r'); delay(50);} else if (way4_12 == 1){Serial.print("4K1"); Serial.print('\r'); delay(50);} Serial.print("4H1"); Serial.print('\r'); delay(50);}                                     
                                                
    digitalWrite(22, LOW); digitalWrite(24, LOW); digitalWrite(26, LOW); digitalWrite(28, LOW); digitalWrite(30, LOW); digitalWrite(32, LOW);
    if (relay1_12 == 1){digitalWrite(22, HIGH);} if (relay2_12 == 1){digitalWrite(24, HIGH);} if (relay3_12 == 1){digitalWrite(26, HIGH);} if (relay4_12 == 1){digitalWrite(28, HIGH);} if (relay5_12 == 1){digitalWrite(30, HIGH);} if (relay6_12 == 1){digitalWrite(32, HIGH);}
    
    lcd.setCursor(0, 0); lcd.print(F("==== Step12 ====")); digitalWrite(2, !relay1_12); digitalWrite(3, !relay2_12); digitalWrite(4, !relay3_12); digitalWrite(5, !relay4_12); digitalWrite(6, !relay5_12); digitalWrite(7, !relay6_12);

    for (int i = 0; i <= 255; i++){                        
                            
    statebutton2 = digitalRead(Button2); if (statebutton2 == LOW){}  else { if ((i+1) <= time12) { lcd.setCursor(0, 1); lcd.print("Time: "); lcd.print(time12 - i); lcd.print("  "); delay(1000); } }
          
    }} lcd.clear();                                     

                                                      
    //Finish of the program

    lcd.setCursor(0, 0); lcd.print("Finished"); cont++; 
    lcd.setCursor(0, 1); lcd.print("Read: "); lcd.print(cont);
    
    digitalWrite(22, LOW); digitalWrite(24, LOW); digitalWrite(26, LOW); digitalWrite(28, LOW); digitalWrite(30, LOW); digitalWrite(32, LOW);
    digitalWrite(2, HIGH); digitalWrite(3, HIGH); digitalWrite(4, HIGH); digitalWrite(5, HIGH); digitalWrite(6, HIGH); digitalWrite(7, HIGH);
    Serial.print("1I1"); Serial.print('\r'); delay(50); Serial.print("2I1"); Serial.print('\r'); delay(50); Serial.print("3I1"); Serial.print('\r'); delay(50); Serial.print("4I1"); Serial.print('\r'); delay(50);
    
    digitalWrite(8, LOW); delay(100); digitalWrite(8, HIGH); delay(100); digitalWrite(8, LOW); delay(100); digitalWrite(8, HIGH);
    
    delay(2000);
    
    lcd.clear();
           
}

    else if (digitalRead(Button1) == LOW && digitalRead(Button2) == LOW){
    while (digitalRead(Button1) == LOW && digitalRead(Button2) == LOW){
    lcd.setCursor(0,0); lcd.print(F("Push button BACK"));
    lcd.setCursor(0,1); lcd.print(F("to RESET memory "));
    if (digitalRead(Button1) == HIGH) {lcd.clear(); delay(500); break;}
    if (digitalRead(Button2) == HIGH) {lcd.clear(); delay(500); break;}
      if (digitalRead(Button1) == LOW && digitalRead(Button2) == LOW && digitalRead(Button4) == LOW){
      for (int r = 1; r <= 181; r++){
    EEPROM.put(r, 0); }
    lcd.clear(); lcd.setCursor(0,0); lcd.print(F("Memory cleaned"));
    delay(3000); lcd.clear(); 
    lcd.setCursor(0,0); lcd.print(F("Resetting: 3")); delay(1000); 
    lcd.setCursor(0,0); lcd.print(F("Resetting: 2")); delay(1000); 
    lcd.setCursor(0,0); lcd.print(F("Resetting: 1")); delay(1000);
    digitalWrite(RESET, LOW); delay(100); }}}
}}   
  
   
     
     else if (tela==2){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step 1 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Time: "));
     lcd.print(time1);
     lcd.print(F("          "));
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }    
     else if (tela==3 && relay1_1==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 1 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Read:   Yes  >No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==3 && relay1_1==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 1 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Read:  >Yes   No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==4 && relay2_1==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 1 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Valve:  Yes  >No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==4 && relay2_1==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 1 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Valve: >Yes   No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==5 && relay3_1==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 1 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Heat1:  Yes  >No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==5 && relay3_1==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 1 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Heat1: >Yes   No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==6 && relay4_1==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 1 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Heat2:  Yes  >No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==6 && relay4_1==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 1 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Heat2: >Yes   No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==7 && relay5_1==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 1 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Relay1: Yes  >No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==7 && relay5_1==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 1 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Relay1:>Yes   No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==8 && relay6_1==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 1 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Relay2: Yes  >No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==8 && relay6_1==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 1 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Relay2:>Yes   No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==9){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step 1 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("RPM CH1: "));
     lcd.print(rpm1_1);
     lcd.print(F("      "));
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==10 && way1_1==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 1 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH1: CCW >CW")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==10 && way1_1==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 1 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH1:>CCW  CW")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==11){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step 1 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("RPM CH2: "));
     lcd.print(rpm2_1);
     lcd.print(F("      "));
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==12 && way2_1==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 1 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH2: CCW >CW")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==12 && way2_1==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 1 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH2:>CCW  CW")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==13){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step 1 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("RPM CH3: "));
     lcd.print(rpm3_1);
     lcd.print(F("      "));
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==14 && way3_1==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 1 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH3: CCW >CW")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==14 && way3_1==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 1 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH3:>CCW  CW")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==15){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step 1 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("RPM CH4: "));
     lcd.print(rpm4_1);
     lcd.print(F("      "));
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==16 && way4_1==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 1 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH4: CCW >CW")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==16 && way4_1==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 1 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH4:>CCW  CW")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
  
     else if (tela==17){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step 2 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Time: "));
     lcd.print(time2);
     lcd.print(F("          "));
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }    
     else if (tela==18 && relay1_2==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 2 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Read:   Yes  >No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==18 && relay1_2==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 2 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Read:  >Yes   No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==19 && relay2_2==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 2 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Valve:  Yes  >No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==19 && relay2_2==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 2 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Valve: >Yes   No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==20 && relay3_2==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 2 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Heat1:  Yes  >No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==20 && relay3_2==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 2 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Heat1: >Yes   No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==21 && relay4_2==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 2 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Heat2:  Yes  >No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==21 && relay4_2==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 2 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Heat2: >Yes   No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==22 && relay5_2==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 2 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Relay1: Yes  >No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==22 && relay5_2==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 2 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Relay1:>Yes   No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==23 && relay6_2==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 2 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Relay2: Yes  >No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==23 && relay6_2==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 2 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Relay2:>Yes   No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==24){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step 2 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("RPM CH1: "));
     lcd.print(rpm1_2);
     lcd.print(F("      "));
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==25 && way1_2==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 2 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH1: CCW >CW")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==25 && way1_2==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 2 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH1:>CCW  CW")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==26){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step 2 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("RPM CH2: "));
     lcd.print(rpm2_2);
     lcd.print(F("      "));
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==27 && way2_2==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 2 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH2: CCW >CW")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==27 && way2_2==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 2 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH2:>CCW  CW")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==28){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step 2 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("RPM CH3: "));
     lcd.print(rpm3_2);
     lcd.print(F("      "));
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==29 && way3_2==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 2 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH3: CCW >CW")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==29 && way3_2==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 2 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH3:>CCW  CW")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==30){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step 2 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("RPM CH4: "));
     lcd.print(rpm4_2);
     lcd.print(F("      "));
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==31 && way4_2==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 2 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH4: CCW >CW")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==31 && way4_2==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 2 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH4:>CCW  CW")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
  
     else if (tela==32){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step 3 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Time: "));
     lcd.print(time3);
     lcd.print(F("          "));
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }    
     else if (tela==33 && relay1_3==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 3 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Read:   Yes  >No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==33 && relay1_3==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 3 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Read:  >Yes   No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==34 && relay2_3==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 3 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Valve:  Yes  >No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==34 && relay2_3==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 3 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Valve: >Yes   No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==35 && relay3_3==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 3 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Heat1:  Yes  >No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==35 && relay3_3==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 3 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Heat1: >Yes   No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==36 && relay4_3==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 3 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Heat2:  Yes  >No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==36 && relay4_3==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 3 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Heat2: >Yes   No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==37 && relay5_3==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 3 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Relay1: Yes  >No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==37 && relay5_3==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 3 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Relay1:>Yes   No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==38 && relay6_3==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 3 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Relay2: Yes  >No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==38 && relay6_3==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 3 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Relay2:>Yes   No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==39){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step 3 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("RPM CH1: "));
     lcd.print(rpm1_3);
     lcd.print(F("      "));
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==40 && way1_3==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 3 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH1: CCW >CW")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==40 && way1_3==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 3 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH1:>CCW  CW")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==41){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step 3 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("RPM CH2: "));
     lcd.print(rpm2_3);
     lcd.print(F("      "));
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==42 && way2_3==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 3 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH2: CCW >CW")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==42 && way2_3==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 3 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH2:>CCW  CW")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==43){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step 3 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("RPM CH3: "));
     lcd.print(rpm3_3);
     lcd.print(F("      "));
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==44 && way3_3==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 3 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH3: CCW >CW")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==44 && way3_3==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 3 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH3:>CCW  CW")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==45){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step 3 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("RPM CH4: "));
     lcd.print(rpm4_3);
     lcd.print(F("      "));
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==46 && way4_3==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 3 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH4: CCW >CW")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==46 && way4_3==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 3 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH4:>CCW  CW")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
  
     else if (tela==47){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step 4 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Time: "));
     lcd.print(time4);
     lcd.print(F("          "));
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }    
     else if (tela==48 && relay1_4==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 4 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Read:   Yes  >No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==48 && relay1_4==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 4 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Read:  >Yes   No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==49 && relay2_4==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 4 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Valve:  Yes  >No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==49 && relay2_4==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 4 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Valve: >Yes   No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==50 && relay3_4==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 4 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Heat1:  Yes  >No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==50 && relay3_4==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 4 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Heat1: >Yes   No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==51 && relay4_4==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 4 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Heat2:  Yes  >No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==51 && relay4_4==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 4 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Heat2: >Yes   No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==52 && relay5_4==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 4 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Relay1: Yes  >No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==52 && relay5_4==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 4 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Relay1:>Yes   No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==53 && relay6_4==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 4 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Relay2: Yes  >No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==53 && relay6_4==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 4 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Relay2:>Yes   No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==54){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step 4 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("RPM CH1: "));
     lcd.print(rpm1_4);
     lcd.print(F("      "));
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==55 && way1_4==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 4 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH1: CCW >CW")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==55 && way1_4==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 4 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH1:>CCW  CW")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==56){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step 4 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("RPM CH2: "));
     lcd.print(rpm2_4);
     lcd.print(F("      "));
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==57 && way2_4==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 4 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH2: CCW >CW")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==57 && way2_4==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 4 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH2:>CCW  CW")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==58){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step 4 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("RPM CH3: "));
     lcd.print(rpm3_4);
     lcd.print(F("      "));
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==59 && way3_4==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 4 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH3: CCW >CW")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==59 && way3_4==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 4 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH3:>CCW  CW")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==60){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step 4 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("RPM CH4: "));
     lcd.print(rpm4_4);
     lcd.print(F("      "));
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==61 && way4_4==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 4 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH4: CCW >CW")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==61 && way4_4==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 4 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH4:>CCW  CW")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
  
     else if (tela==62){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step 5 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Time: "));
     lcd.print(time5);
     lcd.print(F("          "));
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }    
     else if (tela==63 && relay1_5==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 5 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Read:   Yes  >No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==63 && relay1_5==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 5 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Read:  >Yes   No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==64 && relay2_5==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 5 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Valve:  Yes  >No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==64 && relay2_5==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 5 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Valve: >Yes   No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==65 && relay3_5==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 5 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Heat1:  Yes  >No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==65 && relay3_5==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 5 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Heat1: >Yes   No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==66 && relay4_5==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 5 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Heat2:  Yes  >No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==66 && relay4_5==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 5 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Heat2: >Yes   No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==67 && relay5_5==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 5 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Relay1: Yes  >No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==67 && relay5_5==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 5 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Relay1:>Yes   No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==68 && relay6_5==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 5 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Relay2: Yes  >No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==68 && relay6_5==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 5 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Relay2:>Yes   No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==69){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step 5 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("RPM CH1: "));
     lcd.print(rpm1_5);
     lcd.print(F("      "));
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==70 && way1_5==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 5 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH1: CCW >CW")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==70 && way1_5==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 5 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH1:>CCW  CW")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==71){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step 5 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("RPM CH2: "));
     lcd.print(rpm2_5);
     lcd.print(F("      "));
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==72 && way2_5==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 5 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH2: CCW >CW")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==72 && way2_5==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 5 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH2:>CCW  CW")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==73){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step 5 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("RPM CH3: "));
     lcd.print(rpm3_5);
     lcd.print(F("      "));
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==74 && way3_5==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 5 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH3: CCW >CW")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==74 && way3_5==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 5 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH3:>CCW  CW")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==75){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step 5 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("RPM CH4: "));
     lcd.print(rpm4_5);
     lcd.print(F("      "));
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==76 && way4_5==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 5 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH4: CCW >CW")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==76 && way4_5==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 5 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH4:>CCW  CW")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
  
     else if (tela==77){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step 6 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Time: "));
     lcd.print(time6);
     lcd.print(F("          "));
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }    
     else if (tela==78 && relay1_6==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 6 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Read:   Yes  >No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==78 && relay1_6==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 6 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Read:  >Yes   No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==79 && relay2_6==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 6 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Valve:  Yes  >No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==79 && relay2_6==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 6 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Valve: >Yes   No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==80 && relay3_6==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 6 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Heat1:  Yes  >No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==80 && relay3_6==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 6 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Heat1: >Yes   No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==81 && relay4_6==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 6 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Heat2:  Yes  >No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==81 && relay4_6==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 6 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Heat2: >Yes   No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==82 && relay5_6==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 6 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Relay1: Yes  >No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==82 && relay5_6==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 6 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Relay1:>Yes   No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==83 && relay6_6==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 6 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Relay2: Yes  >No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==83 && relay6_6==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 6 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Relay2:>Yes   No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==84){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step 6 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("RPM CH1: "));
     lcd.print(rpm1_6);
     lcd.print(F("      "));
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==85 && way1_6==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 6 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH1: CCW >CW")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==85 && way1_6==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 6 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH1:>CCW  CW")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==86){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step 6 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("RPM CH2: "));
     lcd.print(rpm2_6);
     lcd.print(F("      "));
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==87 && way2_6==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 6 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH2: CCW >CW")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==87 && way2_6==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 6 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH2:>CCW  CW")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==88){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step 6 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("RPM CH3: "));
     lcd.print(rpm3_6);
     lcd.print(F("      "));
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==89 && way3_6==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 6 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH3: CCW >CW")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==89 && way3_6==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 6 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH3:>CCW  CW")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==90){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step 6 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("RPM CH4: "));
     lcd.print(rpm4_6);
     lcd.print(F("      "));
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==91 && way4_6==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 6 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH4: CCW >CW")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==91 && way4_6==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 6 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH4:>CCW  CW")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
  
     else if (tela==92){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step 7 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Time: "));
     lcd.print(time7);
     lcd.print(F("          "));
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }    
     else if (tela==93 && relay1_7==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 7 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Read:   Yes  >No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==93 && relay1_7==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 7 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Read:  >Yes   No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==94 && relay2_7==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 7 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Valve:  Yes  >No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==94 && relay2_7==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 7 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Valve: >Yes   No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==95 && relay3_7==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 7 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Heat1:  Yes  >No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==95 && relay3_7==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 7 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Heat1: >Yes   No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==96 && relay4_7==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 7 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Heat2:  Yes  >No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==96 && relay4_7==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 7 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Heat2: >Yes   No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==97 && relay5_7==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 7 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Relay1: Yes  >No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==97 && relay5_7==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 7 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Relay1:>Yes   No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==98 && relay6_7==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 7 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Relay2: Yes  >No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==98 && relay6_7==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 7 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Relay2:>Yes   No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==99){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step 7 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("RPM CH1: "));
     lcd.print(rpm1_7);
     lcd.print(F("      "));
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==100 && way1_7==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 7 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH1: CCW >CW")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==100 && way1_7==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 7 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH1:>CCW  CW")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==101){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step 7 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("RPM CH2: "));
     lcd.print(rpm2_7);
     lcd.print(F("      "));
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==102 && way2_7==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 7 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH2: CCW >CW")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==102 && way2_7==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 7 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH2:>CCW  CW")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==103){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step 7 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("RPM CH3: "));
     lcd.print(rpm3_7);
     lcd.print(F("      "));
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==104 && way3_7==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 7 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH3: CCW >CW")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==104 && way3_7==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 7 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH3:>CCW  CW")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==105){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step 7 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("RPM CH4: "));
     lcd.print(rpm4_7);
     lcd.print(F("      "));
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==106 && way4_7==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 7 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH4: CCW >CW")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==106 && way4_7==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 7 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH4:>CCW  CW")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
  
     else if (tela==107){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step 8 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Time: "));
     lcd.print(time8);
     lcd.print(F("          "));
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }    
     else if (tela==108 && relay1_8==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 8 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Read:   Yes  >No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==108 && relay1_8==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 8 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Read:  >Yes   No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==109 && relay2_8==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 8 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Valve:  Yes  >No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==109 && relay2_8==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 8 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Valve: >Yes   No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==110 && relay3_8==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 8 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Heat1:  Yes  >No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==110 && relay3_8==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 8 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Heat1: >Yes   No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==111 && relay4_8==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 8 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Heat2:  Yes  >No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==111 && relay4_8==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 8 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Heat2: >Yes   No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==112 && relay5_8==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 8 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Relay1: Yes  >No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==112 && relay5_8==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 8 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Relay1:>Yes   No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==113 && relay6_8==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 8 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Relay2: Yes  >No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==113 && relay6_8==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 8 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Relay2:>Yes   No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==114){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step 8 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("RPM CH1: "));
     lcd.print(rpm1_8);
     lcd.print(F("      "));
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==115 && way1_8==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 8 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH1: CCW >CW")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==115 && way1_8==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 8 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH1:>CCW  CW")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==116){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step 8 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("RPM CH2: "));
     lcd.print(rpm2_8);
     lcd.print(F("      "));
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==117 && way2_8==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 8 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH2: CCW >CW")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==117 && way2_8==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 8 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH2:>CCW  CW")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==118){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step 8 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("RPM CH3: "));
     lcd.print(rpm3_8);
     lcd.print(F("      "));
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==119 && way3_8==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 8 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH3: CCW >CW")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==119 && way3_8==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 8 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH3:>CCW  CW")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==120){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step 8 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("RPM CH4: "));
     lcd.print(rpm4_8);
     lcd.print(F("      "));
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==121 && way4_8==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 8 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH4: CCW >CW")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==121 && way4_8==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 8 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH4:>CCW  CW")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
  
     else if (tela==122){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step 9 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Time: "));
     lcd.print(time9);
     lcd.print(F("          "));
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }    
     else if (tela==123 && relay1_9==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 9 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Read:   Yes  >No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==123 && relay1_9==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 9 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Read:  >Yes   No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==124 && relay2_9==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 9 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Valve:  Yes  >No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==124 && relay2_9==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 9 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Valve: >Yes   No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==125 && relay3_9==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 9 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Heat1:  Yes  >No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==125 && relay3_9==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 9 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Heat1: >Yes   No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==126 && relay4_9==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 9 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Heat2:  Yes  >No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==126 && relay4_9==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 9 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Heat2: >Yes   No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==127 && relay5_9==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 9 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Relay1: Yes  >No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==127 && relay5_9==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 9 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Relay1:>Yes   No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==128 && relay6_9==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 9 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Relay2: Yes  >No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==128 && relay6_9==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 9 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Relay2:>Yes   No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==129){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step 9 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("RPM CH1: "));
     lcd.print(rpm1_9);
     lcd.print(F("      "));
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==130 && way1_9==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 9 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH1: CCW >CW")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==130 && way1_9==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 9 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH1:>CCW  CW")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==131){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step 9 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("RPM CH2: "));
     lcd.print(rpm2_9);
     lcd.print(F("      "));
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==132 && way2_9==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 9 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH2: CCW >CW")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==132 && way2_9==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 9 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH2:>CCW  CW")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==133){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step 9 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("RPM CH3: "));
     lcd.print(rpm3_9);
     lcd.print(F("      "));
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==134 && way3_9==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 9 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH3: CCW >CW")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==134 && way3_9==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 9 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH3:>CCW  CW")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==135){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step 9 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("RPM CH4: "));
     lcd.print(rpm4_9);
     lcd.print(F("      "));
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==136 && way4_9==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 9 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH4: CCW >CW")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==136 && way4_9==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 9 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH4:>CCW  CW")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
  
     else if (tela==137){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step10 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Time: "));
     lcd.print(time10);
     lcd.print(F("          "));
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }    
     else if (tela==138 && relay1_10==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step10 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Read:   Yes  >No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==138 && relay1_10==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step10 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Read:  >Yes   No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==139 && relay2_10==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step10 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Valve:  Yes  >No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==139 && relay2_10==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step10 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Valve: >Yes   No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==140 && relay3_10==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step10 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Heat1:  Yes  >No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==140 && relay3_10==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step10 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Heat1: >Yes   No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==141 && relay4_10==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step10 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Heat2:  Yes  >No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==141 && relay4_10==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step10 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Heat2: >Yes   No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==142 && relay5_10==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step10 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Relay1: Yes  >No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==142 && relay5_10==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step10 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Relay1:>Yes   No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==143 && relay6_10==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step10 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Relay2: Yes  >No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==143 && relay6_10==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step10 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Relay2:>Yes   No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==144){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step10 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("RPM CH1: "));
     lcd.print(rpm1_10);
     lcd.print(F("      "));
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==145 && way1_10==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step10 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH1: CCW >CW")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==145 && way1_10==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step10 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH1:>CCW  CW")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==146){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step10 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("RPM CH2: "));
     lcd.print(rpm2_10);
     lcd.print(F("      "));
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==147 && way2_10==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step10 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH2: CCW >CW")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==147 && way2_10==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step10 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH2:>CCW  CW")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==148){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step10 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("RPM CH3: "));
     lcd.print(rpm3_10);
     lcd.print(F("      "));
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==149 && way3_10==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step10 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH3: CCW >CW")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==149 && way3_10==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step10 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH3:>CCW  CW")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==150){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step10 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("RPM CH4: "));
     lcd.print(rpm4_10);
     lcd.print(F("      "));
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==151 && way4_10==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step10 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH4: CCW >CW")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==151 && way4_10==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step10 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH4:>CCW  CW")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
  
     else if (tela==152){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step11 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Time: "));
     lcd.print(time11);
     lcd.print(F("          "));
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }    
     else if (tela==153 && relay1_11==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step11 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Read:   Yes  >No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==153 && relay1_11==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step11 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Read:  >Yes   No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==154 && relay2_11==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step11 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Valve:  Yes  >No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==154 && relay2_11==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step11 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Valve: >Yes   No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==155 && relay3_11==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step11 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Heat1:  Yes  >No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==155 && relay3_11==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step11 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Heat1: >Yes   No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==156 && relay4_11==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step11 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Heat2:  Yes  >No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==156 && relay4_11==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step11 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Heat2: >Yes   No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==157 && relay5_11==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step11 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Relay1: Yes  >No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==157 && relay5_11==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step11 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Relay1:>Yes   No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==158 && relay6_11==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step11 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Relay2: Yes  >No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==158 && relay6_11==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step11 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Relay2:>Yes   No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==159){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step11 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("RPM CH1: "));
     lcd.print(rpm1_11);
     lcd.print(F("      "));
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==160 && way1_11==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step11 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH1: CCW >CW")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==160 && way1_11==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step11 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH1:>CCW  CW")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==161){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step11 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("RPM CH2: "));
     lcd.print(rpm2_11);
     lcd.print(F("      "));
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==162 && way2_11==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step11 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH2: CCW >CW")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==162 && way2_11==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step11 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH2:>CCW  CW")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==163){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step11 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("RPM CH3: "));
     lcd.print(rpm3_11);
     lcd.print(F("      "));
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==164 && way3_11==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step11 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH3: CCW >CW")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==164 && way3_11==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step11 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH3:>CCW  CW")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==165){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step11 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("RPM CH4: "));
     lcd.print(rpm4_11);
     lcd.print(F("      "));
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==166 && way4_11==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step11 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH4: CCW >CW")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==166   && way4_11==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step11 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH4:>CCW  CW")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
  
     else if (tela==167){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step12 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Time: "));
     lcd.print(time12);
     lcd.print(F("          "));
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }    
     else if (tela==168 && relay1_12==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step12 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Read:   Yes  >No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==168 && relay1_12==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step12 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Read:  >Yes   No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==169 && relay2_12==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step12 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Valve:  Yes  >No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==169 && relay2_12==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step12 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Valve: >Yes   No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==170 && relay3_12==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step12 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Heat1:  Yes  >No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==170 && relay3_12==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step12 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Heat1: >Yes   No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==171 && relay4_12==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step12 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Heat2:  Yes  >No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==171 && relay4_12==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step12 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Heat2: >Yes   No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==172 && relay5_12==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step12 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Relay1: Yes  >No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==172 && relay5_12==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step12 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Relay1:>Yes   No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==173 && relay6_12==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step12 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Relay2: Yes  >No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==173 && relay6_12==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step12 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Relay2:>Yes   No")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==174){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step12 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("RPM CH1: "));
     lcd.print(rpm1_12);
     lcd.print(F("      "));
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==175 && way1_12==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step12 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH1: CCW >CW")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==175 && way1_12==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step12 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH1:>CCW  CW")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==176){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step12 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("RPM CH2: "));
     lcd.print(rpm2_12);
     lcd.print(F("      "));
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==177 && way2_12==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step12 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH2: CCW >CW")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==177 && way2_12==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step12 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH2:>CCW  CW")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==178){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step12 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("RPM CH3: "));
     lcd.print(rpm3_12);
     lcd.print(F("      "));
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==179 && way3_12==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step12 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH3: CCW >CW")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==179 && way3_12==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step12 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH3:>CCW  CW")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==180){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step12 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("RPM CH4: "));
     lcd.print(rpm4_12);
     lcd.print(F("      "));
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==181 && way4_12==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step12 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH4: CCW >CW")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==181 && way4_12==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step12 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH4:>CCW  CW")); 
     L_botao_VOLTAR = digitalRead(Button4); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
  
  
  
  
  // === ACTIONS OF THE BUTTON PLUS === //     
  L_botao_MAIS = digitalRead(Button2);
  if (!L_botao_MAIS && LA_botao_MAIS) {
            if (tela==2){time1++; EEPROM.put(memoriatime1, time1);
       delay(200); 
       while (digitalRead(Button2) == LOW) {
       time1++; q++;    
       lcd.setCursor(6,1); lcd.print(time1); lcd.print(F("  "));
       delay(300); if (digitalRead(Button2) == HIGH){EEPROM.put(memoriatime1, time1); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button2) == LOW) {
       time1++;
       lcd.setCursor(6,1); lcd.print(time1); lcd.print(F("  "));
       delay(100); if (digitalRead(Button2) == HIGH) {EEPROM.put(memoriatime1, time1); q=0; break;}
       }}}}
       else if (tela==3 && relay1_1==1) {relay1_1=0; EEPROM.put(memoriarelay1_1, relay1_1);}
       else if (tela==4 && relay2_1==1) {relay2_1=0; EEPROM.put(memoriarelay2_1, relay2_1);}
       else if (tela==5 && relay3_1==1) {relay3_1=0; EEPROM.put(memoriarelay3_1, relay3_1);}
       else if (tela==6 && relay4_1==1) {relay4_1=0; EEPROM.put(memoriarelay4_1, relay4_1);}
       else if (tela==7 && relay5_1==1) {relay5_1=0; EEPROM.put(memoriarelay5_1, relay5_1);}
       else if (tela==8 && relay6_1==1) {relay6_1=0; EEPROM.put(memoriarelay6_1, relay6_1);}
       else if (tela==9 && rpm1_1 < 100) {rpm1_1++; EEPROM.put(memoriarpm1_1, rpm1_1);
       delay(200); 
       while (digitalRead(Button2) == LOW && rpm1_1 < 100) {
       rpm1_1++; q++;    
       lcd.setCursor(9,1); lcd.print(rpm1_1); lcd.print(F("  "));
       delay(300); if (digitalRead(Button2) == HIGH){EEPROM.put(memoriarpm1_1, rpm1_1); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button2) == LOW && rpm1_1 < 100) {
       rpm1_1++;
       lcd.setCursor(9,1); lcd.print(rpm1_1); lcd.print(F("  "));
       delay(100); if (digitalRead(Button2) == HIGH) {EEPROM.put(memoriarpm1_1, rpm1_1); q=0; break;}
       }}}}
       else if (tela==10 && way1_1==1) {way1_1=0; EEPROM.put(memoriaway1_1, way1_1);}
       else if (tela==11 && rpm2_1 < 100) {rpm2_1++; EEPROM.put(memoriarpm2_1, rpm2_1);
       delay(200); 
       while (digitalRead(Button2) == LOW && rpm2_1 < 100) {
       rpm2_1++; q++;    
       lcd.setCursor(9,1); lcd.print(rpm2_1); lcd.print(F("  "));
       delay(300); if (digitalRead(Button2) == HIGH){EEPROM.put(memoriarpm2_1, rpm2_1); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button2) == LOW && rpm2_1 < 100) {
       rpm2_1++;
       lcd.setCursor(9,1); lcd.print(rpm2_1); lcd.print(F("  "));
       delay(100); if (digitalRead(Button2) == HIGH) {EEPROM.put(memoriarpm2_1, rpm2_1); q=0; break;}
       }}}}
       else if (tela==12 && way2_1==1) {way2_1=0; EEPROM.put(memoriaway2_1, way2_1);}
       else if (tela==13 && rpm3_1 < 100) {rpm3_1++; EEPROM.put(memoriarpm3_1, rpm3_1);
       delay(200); 
       while (digitalRead(Button2) == LOW && rpm3_1 < 100) {
       rpm3_1++; q++;    
       lcd.setCursor(9,1); lcd.print(rpm3_1); lcd.print(F("  "));
       delay(300); if (digitalRead(Button2) == HIGH){EEPROM.put(memoriarpm3_1, rpm3_1); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button2) == LOW && rpm3_1 < 100) {
       rpm3_1++;
       lcd.setCursor(9,1); lcd.print(rpm3_1); lcd.print(F("  "));
       delay(100); if (digitalRead(Button2) == HIGH) {EEPROM.put(memoriarpm3_1, rpm3_1); q=0; break;}
       }}}}
       else if (tela==14 && way3_1==1) {way3_1=0; EEPROM.put(memoriaway3_1, way3_1);}
       else if (tela==15 && rpm4_1 < 100) {rpm4_1++; EEPROM.put(memoriarpm4_1, rpm4_1);
       delay(200); 
       while (digitalRead(Button2) == LOW && rpm4_1 < 100) {
       rpm4_1++; q++;    
       lcd.setCursor(9,1); lcd.print(rpm4_1); lcd.print(F("  "));
       delay(300); if (digitalRead(Button2) == HIGH){EEPROM.put(memoriarpm4_1, rpm4_1); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button2) == LOW && rpm4_1 < 100) {
       rpm4_1++;
       lcd.setCursor(9,1); lcd.print(rpm4_1); lcd.print(F("  "));
       delay(100); if (digitalRead(Button2) == HIGH) {EEPROM.put(memoriarpm4_1, rpm4_1); q=0; break;}
       }}}}
       else if (tela==16 && way4_1==1) {way4_1=0; EEPROM.put(memoriaway4_1, way4_1);}

       else if (tela==17){time2++; EEPROM.put(memoriatime2, time2);
       delay(200); 
       while (digitalRead(Button2) == LOW) {
       time2++; q++;    
       lcd.setCursor(6,1); lcd.print(time2); lcd.print(F("  "));
       delay(300); if (digitalRead(Button2) == HIGH){EEPROM.put(memoriatime2, time2); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button2) == LOW) {
       time2++;
       lcd.setCursor(6,1); lcd.print(time2); lcd.print(F("  "));
       delay(100); if (digitalRead(Button2) == HIGH) {EEPROM.put(memoriatime2, time2); q=0; break;}
       }}}}
       else if (tela==18 && relay1_2==1) {relay1_2=0; EEPROM.put(memoriarelay1_2, relay1_2);}
       else if (tela==19 && relay2_2==1) {relay2_2=0; EEPROM.put(memoriarelay2_2, relay2_2);}
       else if (tela==20 && relay3_2==1) {relay3_2=0; EEPROM.put(memoriarelay3_2, relay3_2);}
       else if (tela==21 && relay4_2==1) {relay4_2=0; EEPROM.put(memoriarelay4_2, relay4_2);}
       else if (tela==22 && relay5_2==1) {relay5_2=0; EEPROM.put(memoriarelay5_2, relay5_2);}
       else if (tela==23 && relay6_2==1) {relay6_2=0; EEPROM.put(memoriarelay6_2, relay6_2);}
       else if (tela==24 && rpm1_2 < 100) {rpm1_2++; EEPROM.put(memoriarpm1_2, rpm1_2);
       delay(200); 
       while (digitalRead(Button2) == LOW && rpm1_2 < 100) {
       rpm1_2++; q++;    
       lcd.setCursor(9,1); lcd.print(rpm1_2); lcd.print(F("  "));
       delay(300); if (digitalRead(Button2) == HIGH){EEPROM.put(memoriarpm1_2, rpm1_2); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button2) == LOW && rpm1_2 < 100) {
       rpm1_2++;
       lcd.setCursor(9,1); lcd.print(rpm1_2); lcd.print(F("  "));
       delay(100); if (digitalRead(Button2) == HIGH) {EEPROM.put(memoriarpm1_2, rpm1_2); q=0; break;}
       }}}}
       else if (tela==25 && way1_2==1) {way1_2=0; EEPROM.put(memoriaway1_2, way1_2);}
       else if (tela==26 && rpm2_2 < 100) {rpm2_2++; EEPROM.put(memoriarpm2_2, rpm2_2);
       delay(200); 
       while (digitalRead(Button2) == LOW && rpm2_2 < 100) {
       rpm2_2++; q++;    
       lcd.setCursor(9,1); lcd.print(rpm2_2); lcd.print(F("  "));
       delay(300); if (digitalRead(Button2) == HIGH){EEPROM.put(memoriarpm2_2, rpm2_2); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button2) == LOW && rpm2_2 < 100) {
       rpm2_2++;
       lcd.setCursor(9,1); lcd.print(rpm2_2); lcd.print(F("  "));
       delay(100); if (digitalRead(Button2) == HIGH) {EEPROM.put(memoriarpm2_2, rpm2_2); q=0; break;}
       }}}}
       else if (tela==27 && way2_2==1) {way2_2=0; EEPROM.put(memoriaway2_2, way2_2);}
       else if (tela==28 && rpm3_2 < 100) {rpm3_2++; EEPROM.put(memoriarpm3_2, rpm3_2);
       delay(200); 
       while (digitalRead(Button2) == LOW && rpm3_2 < 100) {
       rpm3_2++; q++;    
       lcd.setCursor(9,1); lcd.print(rpm3_2); lcd.print(F("  "));
       delay(300); if (digitalRead(Button2) == HIGH){EEPROM.put(memoriarpm3_2, rpm3_2); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button2) == LOW && rpm3_2 < 100) {
       rpm3_2++;
       lcd.setCursor(9,1); lcd.print(rpm3_2); lcd.print(F("  "));
       delay(100); if (digitalRead(Button2) == HIGH) {EEPROM.put(memoriarpm3_2, rpm3_2); q=0; break;}
       }}}}
       else if (tela==29 && way3_2==1) {way3_2=0; EEPROM.put(memoriaway3_2, way3_2);}
       else if (tela==30 && rpm4_2 < 100) {rpm4_2++; EEPROM.put(memoriarpm4_2, rpm4_2);
       delay(200); 
       while (digitalRead(Button2) == LOW && rpm4_2 < 100) {
       rpm4_2++; q++;    
       lcd.setCursor(9,1); lcd.print(rpm4_2); lcd.print(F("  "));
       delay(300); if (digitalRead(Button2) == HIGH){EEPROM.put(memoriarpm4_2, rpm4_2); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button2) == LOW && rpm4_2 < 100) {
       rpm4_2++;
       lcd.setCursor(9,1); lcd.print(rpm4_2); lcd.print(F("  "));
       delay(100); if (digitalRead(Button2) == HIGH) {EEPROM.put(memoriarpm4_2, rpm4_2); q=0; break;}
       }}}}
       else if (tela==31 && way4_2==1) {way4_2=0; EEPROM.put(memoriaway4_2, way4_2);}

       else if (tela==32){time3++; EEPROM.put(memoriatime3, time3);
       delay(200); 
       while (digitalRead(Button2) == LOW) {
       time3++; q++;    
       lcd.setCursor(6,1); lcd.print(time3); lcd.print(F("  "));
       delay(300); if (digitalRead(Button2) == HIGH){EEPROM.put(memoriatime3, time3); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button2) == LOW) {
       time3++;
       lcd.setCursor(6,1); lcd.print(time3); lcd.print(F("  "));
       delay(100); if (digitalRead(Button2) == HIGH) {EEPROM.put(memoriatime3, time3); q=0; break;}
       }}}}
       else if (tela==33 && relay1_3==1) {relay1_3=0; EEPROM.put(memoriarelay1_3, relay1_3);}
       else if (tela==34 && relay2_3==1) {relay2_3=0; EEPROM.put(memoriarelay2_3, relay2_3);}
       else if (tela==35 && relay3_3==1) {relay3_3=0; EEPROM.put(memoriarelay3_3, relay3_3);}
       else if (tela==36 && relay4_3==1) {relay4_3=0; EEPROM.put(memoriarelay4_3, relay4_3);}
       else if (tela==37 && relay5_3==1) {relay5_3=0; EEPROM.put(memoriarelay5_3, relay5_3);}
       else if (tela==38 && relay6_3==1) {relay6_3=0; EEPROM.put(memoriarelay6_3, relay6_3);}
       else if (tela==39 && rpm1_3 < 100) {rpm1_3++; EEPROM.put(memoriarpm1_3, rpm1_3);
       delay(200); 
       while (digitalRead(Button2) == LOW && rpm1_3 < 100) {
       rpm1_3++; q++;    
       lcd.setCursor(9,1); lcd.print(rpm1_3); lcd.print(F("  "));
       delay(300); if (digitalRead(Button2) == HIGH){EEPROM.put(memoriarpm1_3, rpm1_3); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button2) == LOW && rpm1_3 < 100) {
       rpm1_3++;
       lcd.setCursor(9,1); lcd.print(rpm1_3); lcd.print(F("  "));
       delay(100); if (digitalRead(Button2) == HIGH) {EEPROM.put(memoriarpm1_3, rpm1_3); q=0; break;}
       }}}}
       else if (tela==40 && way1_3==1) {way1_3=0; EEPROM.put(memoriaway1_3, way1_3);}
       else if (tela==41 && rpm2_3 < 100) {rpm2_3++; EEPROM.put(memoriarpm2_3, rpm2_3);
       delay(200); 
       while (digitalRead(Button2) == LOW && rpm2_3 < 100) {
       rpm2_3++; q++;    
       lcd.setCursor(9,1); lcd.print(rpm2_3); lcd.print(F("  "));
       delay(300); if (digitalRead(Button2) == HIGH){EEPROM.put(memoriarpm2_3, rpm2_3); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button2) == LOW && rpm2_3 < 100) {
       rpm2_3++;
       lcd.setCursor(9,1); lcd.print(rpm2_3); lcd.print(F("  "));
       delay(100); if (digitalRead(Button2) == HIGH) {EEPROM.put(memoriarpm2_3, rpm2_3); q=0; break;}
       }}}}
       else if (tela==42 && way2_3==1) {way2_3=0; EEPROM.put(memoriaway2_3, way2_3);}
       else if (tela==43 && rpm3_3 < 100) {rpm3_3++; EEPROM.put(memoriarpm3_3, rpm3_3);
       delay(200); 
       while (digitalRead(Button2) == LOW && rpm3_3 < 100) {
       rpm3_3++; q++;    
       lcd.setCursor(9,1); lcd.print(rpm3_3); lcd.print(F("  "));
       delay(300); if (digitalRead(Button2) == HIGH){EEPROM.put(memoriarpm3_3, rpm3_3); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button2) == LOW && rpm3_3 < 100) {
       rpm3_3++;
       lcd.setCursor(9,1); lcd.print(rpm3_3); lcd.print(F("  "));
       delay(100); if (digitalRead(Button2) == HIGH) {EEPROM.put(memoriarpm3_3, rpm3_3); q=0; break;}
       }}}}
       else if (tela==44 && way3_3==1) {way3_3=0; EEPROM.put(memoriaway3_3, way3_3);}
       else if (tela==45 && rpm4_3 < 100) {rpm4_3++; EEPROM.put(memoriarpm4_3, rpm4_3);
       delay(200); 
       while (digitalRead(Button2) == LOW && rpm4_3 < 100) {
       rpm4_3++; q++;    
       lcd.setCursor(9,1); lcd.print(rpm4_3); lcd.print(F("  "));
       delay(300); if (digitalRead(Button2) == HIGH){EEPROM.put(memoriarpm4_3, rpm4_3); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button2) == LOW && rpm4_3 < 100) {
       rpm4_3++;
       lcd.setCursor(9,1); lcd.print(rpm4_3); lcd.print(F("  "));
       delay(100); if (digitalRead(Button2) == HIGH) {EEPROM.put(memoriarpm4_3, rpm4_3); q=0; break;}
       }}}}
       else if (tela==46 && way4_3==1) {way4_3=0; EEPROM.put(memoriaway4_3, way4_3);}

       else if (tela==47){time4++; EEPROM.put(memoriatime4, time4);
       delay(200); 
       while (digitalRead(Button2) == LOW) {
       time4++; q++;    
       lcd.setCursor(6,1); lcd.print(time4); lcd.print(F("  "));
       delay(300); if (digitalRead(Button2) == HIGH){EEPROM.put(memoriatime4, time4); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button2) == LOW) {
       time4++;
       lcd.setCursor(6,1); lcd.print(time4); lcd.print(F("  "));
       delay(100); if (digitalRead(Button2) == HIGH) {EEPROM.put(memoriatime4, time4); q=0; break;}
       }}}}
       else if (tela==48 && relay1_4==1) {relay1_4=0; EEPROM.put(memoriarelay1_4, relay1_4);}
       else if (tela==49 && relay2_4==1) {relay2_4=0; EEPROM.put(memoriarelay2_4, relay2_4);}
       else if (tela==50 && relay3_4==1) {relay3_4=0; EEPROM.put(memoriarelay3_4, relay3_4);}
       else if (tela==51 && relay4_4==1) {relay4_4=0; EEPROM.put(memoriarelay4_4, relay4_4);}
       else if (tela==52 && relay5_4==1) {relay5_4=0; EEPROM.put(memoriarelay5_4, relay5_4);}
       else if (tela==53 && relay6_4==1) {relay6_4=0; EEPROM.put(memoriarelay6_4, relay6_4);}
       else if (tela==54 && rpm1_4 < 100) {rpm1_4++; EEPROM.put(memoriarpm1_4, rpm1_4);
       delay(200); 
       while (digitalRead(Button2) == LOW && rpm1_4 < 100) {
       rpm1_4++; q++;    
       lcd.setCursor(9,1); lcd.print(rpm1_4); lcd.print(F("  "));
       delay(300); if (digitalRead(Button2) == HIGH){EEPROM.put(memoriarpm1_4, rpm1_4); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button2) == LOW && rpm1_4 < 100) {
       rpm1_4++;
       lcd.setCursor(9,1); lcd.print(rpm1_4); lcd.print(F("  "));
       delay(100); if (digitalRead(Button2) == HIGH) {EEPROM.put(memoriarpm1_4, rpm1_4); q=0; break;}
       }}}}
       else if (tela==55 && way1_4==1) {way1_4=0; EEPROM.put(memoriaway1_4, way1_4);}
       else if (tela==56 && rpm2_4 < 100) {rpm2_4++; EEPROM.put(memoriarpm2_4, rpm2_4);
       delay(200); 
       while (digitalRead(Button2) == LOW && rpm2_4 < 100) {
       rpm2_4++; q++;    
       lcd.setCursor(9,1); lcd.print(rpm2_4); lcd.print(F("  "));
       delay(300); if (digitalRead(Button2) == HIGH){EEPROM.put(memoriarpm2_4, rpm2_4); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button2) == LOW && rpm2_4 < 100) {
       rpm2_4++;
       lcd.setCursor(9,1); lcd.print(rpm2_4); lcd.print(F("  "));
       delay(100); if (digitalRead(Button2) == HIGH) {EEPROM.put(memoriarpm2_4, rpm2_4); q=0; break;}
       }}}}
       else if (tela==57 && way2_4==1) {way2_4=0; EEPROM.put(memoriaway2_4, way2_4);}
       else if (tela==58 && rpm3_4 < 100) {rpm3_4++; EEPROM.put(memoriarpm3_4, rpm3_4);
       delay(200); 
       while (digitalRead(Button2) == LOW && rpm3_4 < 100) {
       rpm3_4++; q++;    
       lcd.setCursor(9,1); lcd.print(rpm3_4); lcd.print(F("  "));
       delay(300); if (digitalRead(Button2) == HIGH){EEPROM.put(memoriarpm3_4, rpm3_4); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button2) == LOW && rpm3_4 < 100) {
       rpm3_4++;
       lcd.setCursor(9,1); lcd.print(rpm3_4); lcd.print(F("  "));
       delay(100); if (digitalRead(Button2) == HIGH) {EEPROM.put(memoriarpm3_4, rpm3_4); q=0; break;}
       }}}}
       else if (tela==59 && way3_4==1) {way3_4=0; EEPROM.put(memoriaway3_4, way3_4);}
       else if (tela==60 && rpm4_4 < 100) {rpm4_4++; EEPROM.put(memoriarpm4_4, rpm4_4);
       delay(200); 
       while (digitalRead(Button2) == LOW && rpm4_4 < 100) {
       rpm4_4++; q++;    
       lcd.setCursor(9,1); lcd.print(rpm4_4); lcd.print(F("  "));
       delay(300); if (digitalRead(Button2) == HIGH){EEPROM.put(memoriarpm4_4, rpm4_4); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button2) == LOW && rpm4_4 < 100) {
       rpm4_4++;
       lcd.setCursor(9,1); lcd.print(rpm4_4); lcd.print(F("  "));
       delay(100); if (digitalRead(Button2) == HIGH) {EEPROM.put(memoriarpm4_4, rpm4_4); q=0; break;}
       }}}}
       else if (tela==61 && way4_4==1) {way4_4=0; EEPROM.put(memoriaway4_4, way4_4);}

       else if (tela==62){time5++; EEPROM.put(memoriatime5, time5);
       delay(200); 
       while (digitalRead(Button2) == LOW) {
       time5++; q++;    
       lcd.setCursor(6,1); lcd.print(time5); lcd.print(F("  "));
       delay(300); if (digitalRead(Button2) == HIGH){EEPROM.put(memoriatime5, time5); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button2) == LOW) {
       time5++;
       lcd.setCursor(6,1); lcd.print(time5); lcd.print(F("  "));
       delay(100); if (digitalRead(Button2) == HIGH) {EEPROM.put(memoriatime5, time5); q=0; break;}
       }}}}
       else if (tela==63 && relay1_5==1) {relay1_5=0; EEPROM.put(memoriarelay1_5, relay1_5);}
       else if (tela==64 && relay2_5==1) {relay2_5=0; EEPROM.put(memoriarelay2_5, relay2_5);}
       else if (tela==65 && relay3_5==1) {relay3_5=0; EEPROM.put(memoriarelay3_5, relay3_5);}
       else if (tela==66 && relay4_5==1) {relay4_5=0; EEPROM.put(memoriarelay4_5, relay4_5);}
       else if (tela==67 && relay5_5==1) {relay5_5=0; EEPROM.put(memoriarelay5_5, relay5_5);}
       else if (tela==68 && relay6_5==1) {relay6_5=0; EEPROM.put(memoriarelay6_5, relay6_5);}
       else if (tela==69 && rpm1_5 < 100) {rpm1_5++; EEPROM.put(memoriarpm1_5, rpm1_5);
       delay(200); 
       while (digitalRead(Button2) == LOW && rpm1_5 < 100) {
       rpm1_5++; q++;    
       lcd.setCursor(9,1); lcd.print(rpm1_5); lcd.print(F("  "));
       delay(300); if (digitalRead(Button2) == HIGH){EEPROM.put(memoriarpm1_5, rpm1_5); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button2) == LOW && rpm1_5 < 100) {
       rpm1_5++;
       lcd.setCursor(9,1); lcd.print(rpm1_5); lcd.print(F("  "));
       delay(100); if (digitalRead(Button2) == HIGH) {EEPROM.put(memoriarpm1_5, rpm1_5); q=0; break;}
       }}}}
       else if (tela==70 && way1_5==1) {way1_5=0; EEPROM.put(memoriaway1_5, way1_5);}
       else if (tela==71 && rpm2_5 < 100) {rpm2_5++; EEPROM.put(memoriarpm2_5, rpm2_5);
       delay(200); 
       while (digitalRead(Button2) == LOW && rpm2_5 < 100) {
       rpm2_5++; q++;    
       lcd.setCursor(9,1); lcd.print(rpm2_5); lcd.print(F("  "));
       delay(300); if (digitalRead(Button2) == HIGH){EEPROM.put(memoriarpm2_5, rpm2_5); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button2) == LOW && rpm2_5 < 100) {
       rpm2_5++;
       lcd.setCursor(9,1); lcd.print(rpm2_5); lcd.print(F("  "));
       delay(100); if (digitalRead(Button2) == HIGH) {EEPROM.put(memoriarpm2_5, rpm2_5); q=0; break;}
       }}}}
       else if (tela==72 && way2_5==1) {way2_5=0; EEPROM.put(memoriaway2_5, way2_5);}
       else if (tela==73 && rpm3_5 < 100) {rpm3_5++; EEPROM.put(memoriarpm3_5, rpm3_5);
       delay(200); 
       while (digitalRead(Button2) == LOW && rpm3_5 < 100) {
       rpm3_5++; q++;    
       lcd.setCursor(9,1); lcd.print(rpm3_5); lcd.print(F("  "));
       delay(300); if (digitalRead(Button2) == HIGH){EEPROM.put(memoriarpm3_5, rpm3_5); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button2) == LOW && rpm3_5 < 100) {
       rpm3_5++;
       lcd.setCursor(9,1); lcd.print(rpm3_5); lcd.print(F("  "));
       delay(100); if (digitalRead(Button2) == HIGH) {EEPROM.put(memoriarpm3_5, rpm3_5); q=0; break;}
       }}}}
       else if (tela==74 && way3_5==1) {way3_5=0; EEPROM.put(memoriaway3_5, way3_5);}
       else if (tela==75 && rpm4_5 < 100) {rpm4_5++; EEPROM.put(memoriarpm4_5, rpm4_5);
       delay(200); 
       while (digitalRead(Button2) == LOW && rpm4_5 < 100) {
       rpm4_5++; q++;    
       lcd.setCursor(9,1); lcd.print(rpm4_5); lcd.print(F("  "));
       delay(300); if (digitalRead(Button2) == HIGH){EEPROM.put(memoriarpm4_5, rpm4_5); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button2) == LOW && rpm4_5 < 100) {
       rpm4_5++;
       lcd.setCursor(9,1); lcd.print(rpm4_5); lcd.print(F("  "));
       delay(100); if (digitalRead(Button2) == HIGH) {EEPROM.put(memoriarpm4_5, rpm4_5); q=0; break;}
       }}}}
       else if (tela==76 && way4_5==1) {way4_5=0; EEPROM.put(memoriaway4_5, way4_5);}

       else if (tela==77){time6++; EEPROM.put(memoriatime6, time6);
       delay(200); 
       while (digitalRead(Button2) == LOW) {
       time6++; q++;    
       lcd.setCursor(6,1); lcd.print(time6); lcd.print(F("  "));
       delay(300); if (digitalRead(Button2) == HIGH){EEPROM.put(memoriatime6, time6); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button2) == LOW) {
       time6++;
       lcd.setCursor(6,1); lcd.print(time6); lcd.print(F("  "));
       delay(100); if (digitalRead(Button2) == HIGH) {EEPROM.put(memoriatime6, time6); q=0; break;}
       }}}}
       else if (tela==78 && relay1_6==1) {relay1_6=0; EEPROM.put(memoriarelay1_6, relay1_6);}
       else if (tela==79 && relay2_6==1) {relay2_6=0; EEPROM.put(memoriarelay2_6, relay2_6);}
       else if (tela==80 && relay3_6==1) {relay3_6=0; EEPROM.put(memoriarelay3_6, relay3_6);}
       else if (tela==81 && relay4_6==1) {relay4_6=0; EEPROM.put(memoriarelay4_6, relay4_6);}
       else if (tela==82 && relay5_6==1) {relay5_6=0; EEPROM.put(memoriarelay5_6, relay5_6);}
       else if (tela==83 && relay6_6==1) {relay6_6=0; EEPROM.put(memoriarelay6_6, relay6_6);}
       else if (tela==84 && rpm1_6 < 100) {rpm1_6++; EEPROM.put(memoriarpm1_6, rpm1_6);
       delay(200); 
       while (digitalRead(Button2) == LOW && rpm1_6 < 100) {
       rpm1_6++; q++;    
       lcd.setCursor(9,1); lcd.print(rpm1_6); lcd.print(F("  "));
       delay(300); if (digitalRead(Button2) == HIGH){EEPROM.put(memoriarpm1_6, rpm1_6); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button2) == LOW && rpm1_6 < 100) {
       rpm1_6++;
       lcd.setCursor(9,1); lcd.print(rpm1_6); lcd.print(F("  "));
       delay(100); if (digitalRead(Button2) == HIGH) {EEPROM.put(memoriarpm1_6, rpm1_6); q=0; break;}
       }}}}
       else if (tela==85 && way1_6==1) {way1_6=0; EEPROM.put(memoriaway1_6, way1_6);}
       else if (tela==86 && rpm2_6 < 100) {rpm2_6++; EEPROM.put(memoriarpm2_6, rpm2_6);
       delay(200); 
       while (digitalRead(Button2) == LOW && rpm2_6 < 100) {
       rpm2_6++; q++;    
       lcd.setCursor(9,1); lcd.print(rpm2_6); lcd.print(F("  "));
       delay(300); if (digitalRead(Button2) == HIGH){EEPROM.put(memoriarpm2_6, rpm2_6); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button2) == LOW && rpm2_6 < 100) {
       rpm2_6++;
       lcd.setCursor(9,1); lcd.print(rpm2_6); lcd.print(F("  "));
       delay(100); if (digitalRead(Button2) == HIGH) {EEPROM.put(memoriarpm2_6, rpm2_6); q=0; break;}
       }}}}
       else if (tela==87 && way2_6==1) {way2_6=0; EEPROM.put(memoriaway2_6, way2_6);}
       else if (tela==88 && rpm3_6 < 100) {rpm3_6++; EEPROM.put(memoriarpm3_6, rpm3_6);
       delay(200); 
       while (digitalRead(Button2) == LOW && rpm3_6 < 100) {
       rpm3_6++; q++;    
       lcd.setCursor(9,1); lcd.print(rpm3_6); lcd.print(F("  "));
       delay(300); if (digitalRead(Button2) == HIGH){EEPROM.put(memoriarpm3_6, rpm3_6); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button2) == LOW && rpm3_6 < 100) {
       rpm3_6++;
       lcd.setCursor(9,1); lcd.print(rpm3_6); lcd.print(F("  "));
       delay(100); if (digitalRead(Button2) == HIGH) {EEPROM.put(memoriarpm3_6, rpm3_6); q=0; break;}
       }}}}
       else if (tela==89 && way3_6==1) {way3_6=0; EEPROM.put(memoriaway3_6, way3_6);}
       else if (tela==90 && rpm4_6 < 100) {rpm4_6++; EEPROM.put(memoriarpm4_6, rpm4_6);
       delay(200); 
       while (digitalRead(Button2) == LOW && rpm4_6 < 100) {
       rpm4_6++; q++;    
       lcd.setCursor(9,1); lcd.print(rpm4_6); lcd.print(F("  "));
       delay(300); if (digitalRead(Button2) == HIGH){EEPROM.put(memoriarpm4_6, rpm4_6); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button2) == LOW && rpm4_6 < 100) {
       rpm4_6++;
       lcd.setCursor(9,1); lcd.print(rpm4_6); lcd.print(F("  "));
       delay(100); if (digitalRead(Button2) == HIGH) {EEPROM.put(memoriarpm4_6, rpm4_6); q=0; break;}
       }}}}
       else if (tela==91 && way4_6==1) {way4_6=0; EEPROM.put(memoriaway4_6, way4_6);}

       else if (tela==92){time7++; EEPROM.put(memoriatime7, time7);
       delay(200); 
       while (digitalRead(Button2) == LOW) {
       time7++; q++;    
       lcd.setCursor(6,1); lcd.print(time7); lcd.print(F("  "));
       delay(300); if (digitalRead(Button2) == HIGH){EEPROM.put(memoriatime7, time7); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button2) == LOW) {
       time7++;
       lcd.setCursor(6,1); lcd.print(time7); lcd.print(F("  "));
       delay(100); if (digitalRead(Button2) == HIGH) {EEPROM.put(memoriatime7, time7); q=0; break;}
       }}}}
       else if (tela==93 && relay1_7==1) {relay1_7=0; EEPROM.put(memoriarelay1_7, relay1_7);}
       else if (tela==94 && relay2_7==1) {relay2_7=0; EEPROM.put(memoriarelay2_7, relay2_7);}
       else if (tela==95 && relay3_7==1) {relay3_7=0; EEPROM.put(memoriarelay3_7, relay3_7);}
       else if (tela==96 && relay4_7==1) {relay4_7=0; EEPROM.put(memoriarelay4_7, relay4_7);}
       else if (tela==97 && relay5_7==1) {relay5_7=0; EEPROM.put(memoriarelay5_7, relay5_7);}
       else if (tela==98 && relay6_7==1) {relay6_7=0; EEPROM.put(memoriarelay6_7, relay6_7);}
       else if (tela==99 && rpm1_7 < 100) {rpm1_7++; EEPROM.put(memoriarpm1_7, rpm1_7);
       delay(200); 
       while (digitalRead(Button2) == LOW && rpm1_7 < 100) {
       rpm1_7++; q++;    
       lcd.setCursor(9,1); lcd.print(rpm1_7); lcd.print(F("  "));
       delay(300); if (digitalRead(Button2) == HIGH){EEPROM.put(memoriarpm1_7, rpm1_7); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button2) == LOW && rpm1_7 < 100) {
       rpm1_7++;
       lcd.setCursor(9,1); lcd.print(rpm1_7); lcd.print(F("  "));
       delay(100); if (digitalRead(Button2) == HIGH) {EEPROM.put(memoriarpm1_7, rpm1_7); q=0; break;}
       }}}}
       else if (tela==100 && way1_7==1) {way1_7=0; EEPROM.put(memoriaway1_7, way1_7);}
       else if (tela==101 && rpm2_7 < 100) {rpm2_7++; EEPROM.put(memoriarpm2_7, rpm2_7);
       delay(200); 
       while (digitalRead(Button2) == LOW && rpm2_7 < 100) {
       rpm2_7++; q++;    
       lcd.setCursor(9,1); lcd.print(rpm2_7); lcd.print(F("  "));
       delay(300); if (digitalRead(Button2) == HIGH){EEPROM.put(memoriarpm2_7, rpm2_7); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button2) == LOW && rpm2_7 < 100) {
       rpm2_7++;
       lcd.setCursor(9,1); lcd.print(rpm2_7); lcd.print(F("  "));
       delay(100); if (digitalRead(Button2) == HIGH) {EEPROM.put(memoriarpm2_7, rpm2_7); q=0; break;}
       }}}}
       else if (tela==102 && way2_7==1) {way2_7=0; EEPROM.put(memoriaway2_7, way2_7);}
       else if (tela==103 && rpm3_7 < 100) {rpm3_7++; EEPROM.put(memoriarpm3_7, rpm3_7);
       delay(200); 
       while (digitalRead(Button2) == LOW && rpm3_7 < 100) {
       rpm3_7++; q++;    
       lcd.setCursor(9,1); lcd.print(rpm3_7); lcd.print(F("  "));
       delay(300); if (digitalRead(Button2) == HIGH){EEPROM.put(memoriarpm3_7, rpm3_7); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button2) == LOW && rpm3_7 < 100) {
       rpm3_7++;
       lcd.setCursor(9,1); lcd.print(rpm3_7); lcd.print(F("  "));
       delay(100); if (digitalRead(Button2) == HIGH) {EEPROM.put(memoriarpm3_7, rpm3_7); q=0; break;}
       }}}}
       else if (tela==104 && way3_7==1) {way3_7=0; EEPROM.put(memoriaway3_7, way3_7);}
       else if (tela==105 && rpm4_7 < 100) {rpm4_7++; EEPROM.put(memoriarpm4_7, rpm4_7);
       delay(200); 
       while (digitalRead(Button2) == LOW && rpm4_7 < 100) {
       rpm4_7++; q++;    
       lcd.setCursor(9,1); lcd.print(rpm4_7); lcd.print(F("  "));
       delay(300); if (digitalRead(Button2) == HIGH){EEPROM.put(memoriarpm4_7, rpm4_7); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button2) == LOW && rpm4_7 < 100) {
       rpm4_7++;
       lcd.setCursor(9,1); lcd.print(rpm4_7); lcd.print(F("  "));
       delay(100); if (digitalRead(Button2) == HIGH) {EEPROM.put(memoriarpm4_7, rpm4_7); q=0; break;}
       }}}}
       else if (tela==106 && way4_7==1) {way4_7=0; EEPROM.put(memoriaway4_7, way4_7);}

       else if (tela==107){time8++; EEPROM.put(memoriatime8, time8);
       delay(200); 
       while (digitalRead(Button2) == LOW) {
       time8++; q++;    
       lcd.setCursor(6,1); lcd.print(time8); lcd.print(F("  "));
       delay(300); if (digitalRead(Button2) == HIGH){EEPROM.put(memoriatime8, time8); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button2) == LOW) {
       time8++;
       lcd.setCursor(6,1); lcd.print(time8); lcd.print(F("  "));
       delay(100); if (digitalRead(Button2) == HIGH) {EEPROM.put(memoriatime8, time8); q=0; break;}
       }}}}
       else if (tela==108 && relay1_8==1) {relay1_8=0; EEPROM.put(memoriarelay1_8, relay1_8);}
       else if (tela==109 && relay2_8==1) {relay2_8=0; EEPROM.put(memoriarelay2_8, relay2_8);}
       else if (tela==110 && relay3_8==1) {relay3_8=0; EEPROM.put(memoriarelay3_8, relay3_8);}
       else if (tela==111 && relay4_8==1) {relay4_8=0; EEPROM.put(memoriarelay4_8, relay4_8);}
       else if (tela==112 && relay5_8==1) {relay5_8=0; EEPROM.put(memoriarelay5_8, relay5_8);}
       else if (tela==113 && relay6_8==1) {relay6_8=0; EEPROM.put(memoriarelay6_8, relay6_8);}
       else if (tela==114 && rpm1_8 < 100) {rpm1_8++; EEPROM.put(memoriarpm1_8, rpm1_8);
       delay(200); 
       while (digitalRead(Button2) == LOW && rpm1_8 < 100) {
       rpm1_8++; q++;    
       lcd.setCursor(9,1); lcd.print(rpm1_8); lcd.print(F("  "));
       delay(300); if (digitalRead(Button2) == HIGH){EEPROM.put(memoriarpm1_8, rpm1_8); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button2) == LOW && rpm1_8 < 100) {
       rpm1_8++;
       lcd.setCursor(9,1); lcd.print(rpm1_8); lcd.print(F("  "));
       delay(100); if (digitalRead(Button2) == HIGH) {EEPROM.put(memoriarpm1_8, rpm1_8); q=0; break;}
       }}}}
       else if (tela==115 && way1_8==1) {way1_8=0; EEPROM.put(memoriaway1_8, way1_8);}
       else if (tela==116 && rpm2_8 < 100) {rpm2_8++; EEPROM.put(memoriarpm2_8, rpm2_8);
       delay(200); 
       while (digitalRead(Button2) == LOW && rpm2_8 < 100) {
       rpm2_8++; q++;    
       lcd.setCursor(9,1); lcd.print(rpm2_8); lcd.print(F("  "));
       delay(300); if (digitalRead(Button2) == HIGH){EEPROM.put(memoriarpm2_8, rpm2_8); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button2) == LOW && rpm2_8 < 100) {
       rpm2_8++;
       lcd.setCursor(9,1); lcd.print(rpm2_8); lcd.print(F("  "));
       delay(100); if (digitalRead(Button2) == HIGH) {EEPROM.put(memoriarpm2_8, rpm2_8); q=0; break;}
       }}}}
       else if (tela==117 && way2_8==1) {way2_8=0; EEPROM.put(memoriaway2_8, way2_8);}
       else if (tela==118 && rpm3_8 < 100) {rpm3_8++; EEPROM.put(memoriarpm3_8, rpm3_8);
       delay(200); 
       while (digitalRead(Button2) == LOW && rpm3_8 < 100) {
       rpm3_8++; q++;    
       lcd.setCursor(9,1); lcd.print(rpm3_8); lcd.print(F("  "));
       delay(300); if (digitalRead(Button2) == HIGH){EEPROM.put(memoriarpm3_8, rpm3_8); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button2) == LOW && rpm3_8 < 100) {
       rpm3_8++;
       lcd.setCursor(9,1); lcd.print(rpm3_8); lcd.print(F("  "));
       delay(100); if (digitalRead(Button2) == HIGH) {EEPROM.put(memoriarpm3_8, rpm3_8); q=0; break;}
       }}}}
       else if (tela==119 && way3_8==1) {way3_8=0; EEPROM.put(memoriaway3_8, way3_8);}
       else if (tela==120 && rpm4_8 < 100) {rpm4_8++; EEPROM.put(memoriarpm4_8, rpm4_8);
       delay(200); 
       while (digitalRead(Button2) == LOW && rpm4_8 < 100) {
       rpm4_8++; q++;    
       lcd.setCursor(9,1); lcd.print(rpm4_8); lcd.print(F("  "));
       delay(300); if (digitalRead(Button2) == HIGH){EEPROM.put(memoriarpm4_8, rpm4_8); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button2) == LOW && rpm4_8 < 100) {
       rpm4_8++;
       lcd.setCursor(9,1); lcd.print(rpm4_8); lcd.print(F("  "));
       delay(100); if (digitalRead(Button2) == HIGH) {EEPROM.put(memoriarpm4_8, rpm4_8); q=0; break;}
       }}}}
       else if (tela==121 && way4_8==1) {way4_8=0; EEPROM.put(memoriaway4_8, way4_8);}

       else if (tela==122){time9++; EEPROM.put(memoriatime9, time9);
       delay(200); 
       while (digitalRead(Button2) == LOW) {
       time9++; q++;    
       lcd.setCursor(6,1); lcd.print(time9); lcd.print(F("  "));
       delay(300); if (digitalRead(Button2) == HIGH){EEPROM.put(memoriatime9, time9); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button2) == LOW) {
       time9++;
       lcd.setCursor(6,1); lcd.print(time9); lcd.print(F("  "));
       delay(100); if (digitalRead(Button2) == HIGH) {EEPROM.put(memoriatime9, time9); q=0; break;}
       }}}}
       else if (tela==123 && relay1_9==1) {relay1_9=0; EEPROM.put(memoriarelay1_9, relay1_9);}
       else if (tela==124 && relay2_9==1) {relay2_9=0; EEPROM.put(memoriarelay2_9, relay2_9);}
       else if (tela==125 && relay3_9==1) {relay3_9=0; EEPROM.put(memoriarelay3_9, relay3_9);}
       else if (tela==126 && relay4_9==1) {relay4_9=0; EEPROM.put(memoriarelay4_9, relay4_9);}
       else if (tela==127 && relay5_9==1) {relay5_9=0; EEPROM.put(memoriarelay5_9, relay5_9);}
       else if (tela==128 && relay6_9==1) {relay6_9=0; EEPROM.put(memoriarelay6_9, relay6_9);}
       else if (tela==129 && rpm1_9 < 100) {rpm1_9++; EEPROM.put(memoriarpm1_9, rpm1_9);
       delay(200); 
       while (digitalRead(Button2) == LOW && rpm1_9 < 100) {
       rpm1_9++; q++;    
       lcd.setCursor(9,1); lcd.print(rpm1_9); lcd.print(F("  "));
       delay(300); if (digitalRead(Button2) == HIGH){EEPROM.put(memoriarpm1_9, rpm1_9); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button2) == LOW && rpm1_9 < 100) {
       rpm1_9++;
       lcd.setCursor(9,1); lcd.print(rpm1_9); lcd.print(F("  "));
       delay(100); if (digitalRead(Button2) == HIGH) {EEPROM.put(memoriarpm1_9, rpm1_9); q=0; break;}
       }}}}
       else if (tela==130 && way1_9==1) {way1_9=0; EEPROM.put(memoriaway1_9, way1_9);}
       else if (tela==131 && rpm2_9 < 100) {rpm2_9++; EEPROM.put(memoriarpm2_9, rpm2_9);
       delay(200); 
       while (digitalRead(Button2) == LOW && rpm2_9 < 100) {
       rpm2_9++; q++;    
       lcd.setCursor(9,1); lcd.print(rpm2_9); lcd.print(F("  "));
       delay(300); if (digitalRead(Button2) == HIGH){EEPROM.put(memoriarpm2_9, rpm2_9); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button2) == LOW && rpm2_9 < 100) {
       rpm2_9++;
       lcd.setCursor(9,1); lcd.print(rpm2_9); lcd.print(F("  "));
       delay(100); if (digitalRead(Button2) == HIGH) {EEPROM.put(memoriarpm2_9, rpm2_9); q=0; break;}
       }}}}
       else if (tela==132 && way2_9==1) {way2_9=0; EEPROM.put(memoriaway2_9, way2_9);}
       else if (tela==133 && rpm3_9 < 100) {rpm3_9++; EEPROM.put(memoriarpm3_9, rpm3_9);
       delay(200); 
       while (digitalRead(Button2) == LOW && rpm3_9 < 100) {
       rpm3_9++; q++;    
       lcd.setCursor(9,1); lcd.print(rpm3_9); lcd.print(F("  "));
       delay(300); if (digitalRead(Button2) == HIGH){EEPROM.put(memoriarpm3_9, rpm3_9); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button2) == LOW && rpm3_9 < 100) {
       rpm3_9++;
       lcd.setCursor(9,1); lcd.print(rpm3_9); lcd.print(F("  "));
       delay(100); if (digitalRead(Button2) == HIGH) {EEPROM.put(memoriarpm3_9, rpm3_9); q=0; break;}
       }}}}
       else if (tela==134 && way3_9==1) {way3_9=0; EEPROM.put(memoriaway3_9, way3_9);}
       else if (tela==135 && rpm4_9 < 100) {rpm4_9++; EEPROM.put(memoriarpm4_9, rpm4_9);
       delay(200); 
       while (digitalRead(Button2) == LOW && rpm4_9 < 100) {
       rpm4_9++; q++;    
       lcd.setCursor(9,1); lcd.print(rpm4_9); lcd.print(F("  "));
       delay(300); if (digitalRead(Button2) == HIGH){EEPROM.put(memoriarpm4_9, rpm4_9); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button2) == LOW && rpm4_9 < 100) {
       rpm4_9++;
       lcd.setCursor(9,1); lcd.print(rpm4_9); lcd.print(F("  "));
       delay(100); if (digitalRead(Button2) == HIGH) {EEPROM.put(memoriarpm4_9, rpm4_9); q=0; break;}
       }}}}
       else if (tela==136 && way4_9==1) {way4_9=0; EEPROM.put(memoriaway4_9, way4_9);}

       else if (tela==137){time10++; EEPROM.put(memoriatime10, time10);
       delay(200); 
       while (digitalRead(Button2) == LOW) {
       time10++; q++;    
       lcd.setCursor(6,1); lcd.print(time10); lcd.print(F("  "));
       delay(300); if (digitalRead(Button2) == HIGH){EEPROM.put(memoriatime10, time10); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button2) == LOW) {
       time10++;
       lcd.setCursor(6,1); lcd.print(time10); lcd.print(F("  "));
       delay(100); if (digitalRead(Button2) == HIGH) {EEPROM.put(memoriatime10, time10); q=0; break;}
       }}}}
       else if (tela==138 && relay1_10==1) {relay1_10=0; EEPROM.put(memoriarelay1_10, relay1_10);}
       else if (tela==139 && relay2_10==1) {relay2_10=0; EEPROM.put(memoriarelay2_10, relay2_10);}
       else if (tela==140 && relay3_10==1) {relay3_10=0; EEPROM.put(memoriarelay3_10, relay3_10);}
       else if (tela==141 && relay4_10==1) {relay4_10=0; EEPROM.put(memoriarelay4_10, relay4_10);}
       else if (tela==142 && relay5_10==1) {relay5_10=0; EEPROM.put(memoriarelay5_10, relay5_10);}
       else if (tela==143 && relay6_10==1) {relay6_10=0; EEPROM.put(memoriarelay6_10, relay6_10);}
       else if (tela==144 && rpm1_10 < 100) {rpm1_10++; EEPROM.put(memoriarpm1_10, rpm1_10);
       delay(200); 
       while (digitalRead(Button2) == LOW && rpm1_10 < 100) {
       rpm1_10++; q++;    
       lcd.setCursor(9,1); lcd.print(rpm1_10); lcd.print(F("  "));
       delay(300); if (digitalRead(Button2) == HIGH){EEPROM.put(memoriarpm1_10, rpm1_10); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button2) == LOW && rpm1_10 < 100) {
       rpm1_10++;
       lcd.setCursor(9,1); lcd.print(rpm1_10); lcd.print(F("  "));
       delay(100); if (digitalRead(Button2) == HIGH) {EEPROM.put(memoriarpm1_10, rpm1_10); q=0; break;}
       }}}}
       else if (tela==145 && way1_10==1) {way1_10=0; EEPROM.put(memoriaway1_10, way1_10);}
       else if (tela==146 && rpm2_10 < 100) {rpm2_10++; EEPROM.put(memoriarpm2_10, rpm2_10);
       delay(200); 
       while (digitalRead(Button2) == LOW && rpm2_10 < 100) {
       rpm2_10++; q++;    
       lcd.setCursor(9,1); lcd.print(rpm2_10); lcd.print(F("  "));
       delay(300); if (digitalRead(Button2) == HIGH){EEPROM.put(memoriarpm2_10, rpm2_10); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button2) == LOW && rpm2_10 < 100) {
       rpm2_10++;
       lcd.setCursor(9,1); lcd.print(rpm2_10); lcd.print(F("  "));
       delay(100); if (digitalRead(Button2) == HIGH) {EEPROM.put(memoriarpm2_10, rpm2_10); q=0; break;}
       }}}}
       else if (tela==147 && way2_10==1) {way2_10=0; EEPROM.put(memoriaway2_10, way2_10);}
       else if (tela==148 && rpm3_10 < 100) {rpm3_10++; EEPROM.put(memoriarpm3_10, rpm3_10);
       delay(200); 
       while (digitalRead(Button2) == LOW && rpm3_10 < 100) {
       rpm3_10++; q++;    
       lcd.setCursor(9,1); lcd.print(rpm3_10); lcd.print(F("  "));
       delay(300); if (digitalRead(Button2) == HIGH){EEPROM.put(memoriarpm3_10, rpm3_10); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button2) == LOW && rpm3_10 < 100) {
       rpm3_10++;
       lcd.setCursor(9,1); lcd.print(rpm3_10); lcd.print(F("  "));
       delay(100); if (digitalRead(Button2) == HIGH) {EEPROM.put(memoriarpm3_10, rpm3_10); q=0; break;}
       }}}}
       else if (tela==149 && way3_10==1) {way3_10=0; EEPROM.put(memoriaway3_10, way3_10);}
       else if (tela==150 && rpm4_10 < 100) {rpm4_10++; EEPROM.put(memoriarpm4_10, rpm4_10);
       delay(200); 
       while (digitalRead(Button2) == LOW && rpm4_10 < 100) {
       rpm4_10++; q++;    
       lcd.setCursor(9,1); lcd.print(rpm4_10); lcd.print(F("  "));
       delay(300); if (digitalRead(Button2) == HIGH){EEPROM.put(memoriarpm4_10, rpm4_10); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button2) == LOW && rpm4_10 < 100) {
       rpm4_10++;
       lcd.setCursor(9,1); lcd.print(rpm4_10); lcd.print(F("  "));
       delay(100); if (digitalRead(Button2) == HIGH) {EEPROM.put(memoriarpm4_10, rpm4_10); q=0; break;}
       }}}}
       else if (tela==151 && way4_10==1) {way4_10=0; EEPROM.put(memoriaway4_10, way4_10);}

       else if (tela==152){time11++; EEPROM.put(memoriatime11, time11);
       delay(200); 
       while (digitalRead(Button2) == LOW) {
       time11++; q++;    
       lcd.setCursor(6,1); lcd.print(time11); lcd.print(F("  "));
       delay(300); if (digitalRead(Button2) == HIGH){EEPROM.put(memoriatime11, time11); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button2) == LOW) {
       time11++;
       lcd.setCursor(6,1); lcd.print(time11); lcd.print(F("  "));
       delay(100); if (digitalRead(Button2) == HIGH) {EEPROM.put(memoriatime11, time11); q=0; break;}
       }}}}
       else if (tela==153 && relay1_11==1) {relay1_11=0; EEPROM.put(memoriarelay1_11, relay1_11);}
       else if (tela==154 && relay2_11==1) {relay2_11=0; EEPROM.put(memoriarelay2_11, relay2_11);}
       else if (tela==155 && relay3_11==1) {relay3_11=0; EEPROM.put(memoriarelay3_11, relay3_11);}
       else if (tela==156 && relay4_11==1) {relay4_11=0; EEPROM.put(memoriarelay4_11, relay4_11);}
       else if (tela==157 && relay5_11==1) {relay5_11=0; EEPROM.put(memoriarelay5_11, relay5_11);}
       else if (tela==158 && relay6_11==1) {relay6_11=0; EEPROM.put(memoriarelay6_11, relay6_11);}
       else if (tela==159 && rpm1_11 < 100) {rpm1_11++; EEPROM.put(memoriarpm1_11, rpm1_11);
       delay(200); 
       while (digitalRead(Button2) == LOW && rpm1_11 < 100) {
       rpm1_11++; q++;    
       lcd.setCursor(9,1); lcd.print(rpm1_11); lcd.print(F("  "));
       delay(300); if (digitalRead(Button2) == HIGH){EEPROM.put(memoriarpm1_11, rpm1_11); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button2) == LOW && rpm1_11 < 100) {
       rpm1_11++;
       lcd.setCursor(9,1); lcd.print(rpm1_11); lcd.print(F("  "));
       delay(100); if (digitalRead(Button2) == HIGH) {EEPROM.put(memoriarpm1_11, rpm1_11); q=0; break;}
       }}}}
       else if (tela==160 && way1_11==1) {way1_11=0; EEPROM.put(memoriaway1_11, way1_11);}
       else if (tela==161 && rpm2_11 < 100) {rpm2_11++; EEPROM.put(memoriarpm2_11, rpm2_11);
       delay(200); 
       while (digitalRead(Button2) == LOW && rpm2_11 < 100) {
       rpm2_11++; q++;    
       lcd.setCursor(9,1); lcd.print(rpm2_11); lcd.print(F("  "));
       delay(300); if (digitalRead(Button2) == HIGH){EEPROM.put(memoriarpm2_11, rpm2_11); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button2) == LOW && rpm2_11 < 100) {
       rpm2_11++;
       lcd.setCursor(9,1); lcd.print(rpm2_11); lcd.print(F("  "));
       delay(100); if (digitalRead(Button2) == HIGH) {EEPROM.put(memoriarpm2_11, rpm2_11); q=0; break;}
       }}}}
       else if (tela==162 && way2_11==1) {way2_11=0; EEPROM.put(memoriaway2_11, way2_11);}
       else if (tela==163 && rpm3_11 < 100) {rpm3_11++; EEPROM.put(memoriarpm3_11, rpm3_11);
       delay(200); 
       while (digitalRead(Button2) == LOW && rpm3_11 < 100) {
       rpm3_11++; q++;    
       lcd.setCursor(9,1); lcd.print(rpm3_11); lcd.print(F("  "));
       delay(300); if (digitalRead(Button2) == HIGH){EEPROM.put(memoriarpm3_11, rpm3_11); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button2) == LOW && rpm3_11 < 100) {
       rpm3_11++;
       lcd.setCursor(9,1); lcd.print(rpm3_11); lcd.print(F("  "));
       delay(100); if (digitalRead(Button2) == HIGH) {EEPROM.put(memoriarpm3_11, rpm3_11); q=0; break;}
       }}}}
       else if (tela==164 && way3_11==1) {way3_11=0; EEPROM.put(memoriaway3_11, way3_11);}
       else if (tela==165 && rpm4_11 < 100) {rpm4_11++; EEPROM.put(memoriarpm4_11, rpm4_11);
       delay(200); 
       while (digitalRead(Button2) == LOW && rpm4_11 < 100) {
       rpm4_11++; q++;    
       lcd.setCursor(9,1); lcd.print(rpm4_11); lcd.print(F("  "));
       delay(300); if (digitalRead(Button2) == HIGH){EEPROM.put(memoriarpm4_11, rpm4_11); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button2) == LOW && rpm4_11 < 100) {
       rpm4_11++;
       lcd.setCursor(9,1); lcd.print(rpm4_11); lcd.print(F("  "));
       delay(100); if (digitalRead(Button2) == HIGH) {EEPROM.put(memoriarpm4_11, rpm4_11); q=0; break;}
       }}}}
       else if (tela==166 && way4_11==1) {way4_11=0; EEPROM.put(memoriaway4_11, way4_11);}

       else if (tela==167){time12++; EEPROM.put(memoriatime12, time12);
       delay(200); 
       while (digitalRead(Button2) == LOW) {
       time12++; q++;    
       lcd.setCursor(6,1); lcd.print(time12); lcd.print(F("  "));
       delay(300); if (digitalRead(Button2) == HIGH){EEPROM.put(memoriatime12, time12); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button2) == LOW) {
       time12++;
       lcd.setCursor(6,1); lcd.print(time12); lcd.print(F("  "));
       delay(100); if (digitalRead(Button2) == HIGH) {EEPROM.put(memoriatime12, time12); q=0; break;}
       }}}}
       else if (tela==168 && relay1_12==1) {relay1_12=0; EEPROM.put(memoriarelay1_12, relay1_12);}
       else if (tela==169 && relay2_12==1) {relay2_12=0; EEPROM.put(memoriarelay2_12, relay2_12);}
       else if (tela==170 && relay3_12==1) {relay3_12=0; EEPROM.put(memoriarelay3_12, relay3_12);}
       else if (tela==171 && relay4_12==1) {relay4_12=0; EEPROM.put(memoriarelay4_12, relay4_12);}
       else if (tela==172 && relay5_12==1) {relay5_12=0; EEPROM.put(memoriarelay5_12, relay5_12);}
       else if (tela==173 && relay6_12==1) {relay6_12=0; EEPROM.put(memoriarelay6_12, relay6_12);}
       else if (tela==174 && rpm1_12 < 100) {rpm1_12++; EEPROM.put(memoriarpm1_12, rpm1_12);
       delay(200); 
       while (digitalRead(Button2) == LOW && rpm1_12 < 100) {
       rpm1_12++; q++;    
       lcd.setCursor(9,1); lcd.print(rpm1_12); lcd.print(F("  "));
       delay(300); if (digitalRead(Button2) == HIGH){EEPROM.put(memoriarpm1_12, rpm1_12); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button2) == LOW && rpm1_12 < 100) {
       rpm1_12++;
       lcd.setCursor(9,1); lcd.print(rpm1_12); lcd.print(F("  "));
       delay(100); if (digitalRead(Button2) == HIGH) {EEPROM.put(memoriarpm1_12, rpm1_12); q=0; break;}
       }}}}
       else if (tela==175 && way1_12==1) {way1_12=0; EEPROM.put(memoriaway1_12, way1_12);}
       else if (tela==176 && rpm2_12 < 100) {rpm2_12++; EEPROM.put(memoriarpm2_12, rpm2_12);
       delay(200); 
       while (digitalRead(Button2) == LOW && rpm2_12 < 100) {
       rpm2_12++; q++;    
       lcd.setCursor(9,1); lcd.print(rpm2_12); lcd.print(F("  "));
       delay(300); if (digitalRead(Button2) == HIGH){EEPROM.put(memoriarpm2_12, rpm2_12); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button2) == LOW && rpm2_12 < 100) {
       rpm2_12++;
       lcd.setCursor(9,1); lcd.print(rpm2_12); lcd.print(F("  "));
       delay(100); if (digitalRead(Button2) == HIGH) {EEPROM.put(memoriarpm2_12, rpm2_12); q=0; break;}
       }}}}
       else if (tela==177 && way2_12==1) {way2_12=0; EEPROM.put(memoriaway2_12, way2_12);}
       else if (tela==178 && rpm3_12 < 100) {rpm3_12++; EEPROM.put(memoriarpm3_12, rpm3_12);
       delay(200); 
       while (digitalRead(Button2) == LOW && rpm3_12 < 100) {
       rpm3_12++; q++;    
       lcd.setCursor(9,1); lcd.print(rpm3_12); lcd.print(F("  "));
       delay(300); if (digitalRead(Button2) == HIGH){EEPROM.put(memoriarpm3_12, rpm3_12); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button2) == LOW && rpm3_12 < 100) {
       rpm3_12++;
       lcd.setCursor(9,1); lcd.print(rpm3_12); lcd.print(F("  "));
       delay(100); if (digitalRead(Button2) == HIGH) {EEPROM.put(memoriarpm3_12, rpm3_12); q=0; break;}
       }}}}
       else if (tela==179 && way3_12==1) {way3_12=0; EEPROM.put(memoriaway3_12, way3_12);}
       else if (tela==180 && rpm4_12 < 100) {rpm4_12++; EEPROM.put(memoriarpm4_12, rpm4_12);
       delay(200); 
       while (digitalRead(Button2) == LOW && rpm4_12 < 100) {
       rpm4_12++; q++;    
       lcd.setCursor(9,1); lcd.print(rpm4_12); lcd.print(F("  "));
       delay(300); if (digitalRead(Button2) == HIGH){EEPROM.put(memoriarpm4_12, rpm4_12); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button2) == LOW && rpm4_12 < 100) {
       rpm4_12++;
       lcd.setCursor(9,1); lcd.print(rpm4_12); lcd.print(F("  "));
       delay(100); if (digitalRead(Button2) == HIGH) {EEPROM.put(memoriarpm4_12, rpm4_12); q=0; break;}
       }}}}
       else if (tela==181 && way4_12==1) {way4_12=0; EEPROM.put(memoriaway4_12, way4_12);}

       delay(30);
       } LA_botao_MAIS = L_botao_MAIS ;
       
       

  // ===ACTIONS OF THE BUTTON MINUS === //   
  L_botao_MENOS = digitalRead(Button1);
  if (!L_botao_MENOS && LA_botao_MENOS) {
            if (tela==2){time1--; EEPROM.put(memoriatime1, time1);
       delay(200); 
       while (digitalRead(Button1) == LOW) {
       time1--; q++;    
       lcd.setCursor(6,1); lcd.print(time1); lcd.print(F("  "));
       delay(300); if (digitalRead(Button1) == HIGH){EEPROM.put(memoriatime1, time1); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button1) == LOW) {
       time1--;
       lcd.setCursor(6,1); lcd.print(time1); lcd.print(F("  "));
       delay(100); if (digitalRead(Button1) == HIGH) {EEPROM.put(memoriatime1, time1); q=0; break;}
       }}}}
       else if (tela==3 && relay1_1==0) {relay1_1=1; EEPROM.put(memoriarelay1_1, relay1_1);}
       else if (tela==4 && relay2_1==0) {relay2_1=1; EEPROM.put(memoriarelay2_1, relay2_1);}
       else if (tela==5 && relay3_1==0 && relay4_1==0) {relay3_1=1; EEPROM.put(memoriarelay3_1, relay3_1);}
       else if (tela==6 && relay4_1==0 && relay3_1==0) {relay4_1=1; EEPROM.put(memoriarelay4_1, relay4_1);}
       else if (tela==7 && relay5_1==0) {relay5_1=1; EEPROM.put(memoriarelay5_1, relay5_1);}
       else if (tela==8 && relay6_1==0) {relay6_1=1; EEPROM.put(memoriarelay6_1, relay6_1);}
       else if (tela==9 && rpm1_1 > 0) {rpm1_1--; EEPROM.put(memoriarpm1_1, rpm1_1);
       delay(200); 
       while (digitalRead(Button1) == LOW && rpm1_1 > 0) {
       rpm1_1--; q++;    
       lcd.setCursor(9,1); lcd.print(rpm1_1); lcd.print(F("  "));
       delay(300); if (digitalRead(Button1) == HIGH){EEPROM.put(memoriarpm1_1, rpm1_1); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button1) == LOW && rpm1_1 > 0) {
       rpm1_1--;
       lcd.setCursor(9,1); lcd.print(rpm1_1); lcd.print(F("  "));
       delay(100); if (digitalRead(Button1) == HIGH) {EEPROM.put(memoriarpm1_1, rpm1_1); q=0; break;}
       }}}}
       else if (tela==10 && way1_1==0) {way1_1=1; EEPROM.put(memoriaway1_1, way1_1);}
       else if (tela==11 && rpm2_1 > 0) {rpm2_1--; EEPROM.put(memoriarpm2_1, rpm2_1);
       delay(200); 
       while (digitalRead(Button1) == LOW && rpm2_1 > 0) {
       rpm2_1--; q++;    
       lcd.setCursor(9,1); lcd.print(rpm2_1); lcd.print(F("  "));
       delay(300); if (digitalRead(Button1) == HIGH){EEPROM.put(memoriarpm2_1, rpm2_1); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button1) == LOW && rpm2_1 > 0) {
       rpm2_1--;
       lcd.setCursor(9,1); lcd.print(rpm2_1); lcd.print(F("  "));
       delay(100); if (digitalRead(Button1) == HIGH) {EEPROM.put(memoriarpm2_1, rpm2_1); q=0; break;}
       }}}}
       else if (tela==12 && way2_1==0) {way2_1=1; EEPROM.put(memoriaway2_1, way2_1);}
       else if (tela==13 && rpm3_1 > 0) {rpm3_1--; EEPROM.put(memoriarpm3_1, rpm3_1);
       delay(200); 
       while (digitalRead(Button1) == LOW && rpm3_1 > 0) {
       rpm3_1--; q++;    
       lcd.setCursor(9,1); lcd.print(rpm3_1); lcd.print(F("  "));
       delay(300); if (digitalRead(Button1) == HIGH){EEPROM.put(memoriarpm3_1, rpm3_1); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button1) == LOW && rpm3_1 > 0) {
       rpm3_1--;
       lcd.setCursor(9,1); lcd.print(rpm3_1); lcd.print(F("  "));
       delay(100); if (digitalRead(Button1) == HIGH) {EEPROM.put(memoriarpm3_1, rpm3_1); q=0; break;}
       }}}}
       else if (tela==14 && way3_1==0) {way3_1=1; EEPROM.put(memoriaway3_1, way3_1);}
       else if (tela==15 && rpm4_1 > 0) {rpm4_1--; EEPROM.put(memoriarpm4_1, rpm4_1);
       delay(200); 
       while (digitalRead(Button1) == LOW && rpm4_1 > 0) {
       rpm4_1--; q++;    
       lcd.setCursor(9,1); lcd.print(rpm4_1); lcd.print(F("  "));
       delay(300); if (digitalRead(Button1) == HIGH){EEPROM.put(memoriarpm4_1, rpm4_1); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button1) == LOW && rpm4_1 > 0) {
       rpm4_1--;
       lcd.setCursor(9,1); lcd.print(rpm4_1); lcd.print(F("  "));
       delay(100); if (digitalRead(Button1) == HIGH) {EEPROM.put(memoriarpm4_1, rpm4_1); q=0; break;}
       }}}}
       else if (tela==16 && way4_1==0) {way4_1=1; EEPROM.put(memoriaway4_1, way4_1);}

       else if (tela==17){time2--; EEPROM.put(memoriatime2, time2);
       delay(200); 
       while (digitalRead(Button1) == LOW) {
       time2--; q++;    
       lcd.setCursor(6,1); lcd.print(time2); lcd.print(F("  "));
       delay(300); if (digitalRead(Button1) == HIGH){EEPROM.put(memoriatime2, time2); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button1) == LOW) {
       time2--;
       lcd.setCursor(6,1); lcd.print(time2); lcd.print(F("  "));
       delay(100); if (digitalRead(Button1) == HIGH) {EEPROM.put(memoriatime2, time2); q=0; break;}
       }}}}
       else if (tela==18 && relay1_2==0) {relay1_2=1; EEPROM.put(memoriarelay1_2, relay1_2);}
       else if (tela==19 && relay2_2==0) {relay2_2=1; EEPROM.put(memoriarelay2_2, relay2_2);}
       else if (tela==20 && relay3_2==0 && relay4_2==0) {relay3_2=1; EEPROM.put(memoriarelay3_2, relay3_2);}
       else if (tela==21 && relay4_2==0 && relay3_2==0) {relay4_2=1; EEPROM.put(memoriarelay4_2, relay4_2);}
       else if (tela==22 && relay5_2==0) {relay5_2=1; EEPROM.put(memoriarelay5_2, relay5_2);}
       else if (tela==23 && relay6_2==0) {relay6_2=1; EEPROM.put(memoriarelay6_2, relay6_2);}
       else if (tela==24 && rpm1_2 > 0) {rpm1_2--; EEPROM.put(memoriarpm1_2, rpm1_2);
       delay(200); 
       while (digitalRead(Button1) == LOW && rpm1_2 > 0) {
       rpm1_2--; q++;    
       lcd.setCursor(9,1); lcd.print(rpm1_2); lcd.print(F("  "));
       delay(300); if (digitalRead(Button1) == HIGH){EEPROM.put(memoriarpm1_2, rpm1_2); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button1) == LOW && rpm1_2 > 0) {
       rpm1_2--;
       lcd.setCursor(9,1); lcd.print(rpm1_2); lcd.print(F("  "));
       delay(100); if (digitalRead(Button1) == HIGH) {EEPROM.put(memoriarpm1_2, rpm1_2); q=0; break;}
       }}}}
       else if (tela==25 && way1_2==0) {way1_2=1; EEPROM.put(memoriaway1_2, way1_2);}
       else if (tela==26 && rpm2_2 > 0) {rpm2_2--; EEPROM.put(memoriarpm2_2, rpm2_2);
       delay(200); 
       while (digitalRead(Button1) == LOW && rpm2_2 > 0) {
       rpm2_2--; q++;    
       lcd.setCursor(9,1); lcd.print(rpm2_2); lcd.print(F("  "));
       delay(300); if (digitalRead(Button1) == HIGH){EEPROM.put(memoriarpm2_2, rpm2_2); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button1) == LOW && rpm2_2 > 0) {
       rpm2_2--;
       lcd.setCursor(9,1); lcd.print(rpm2_2); lcd.print(F("  "));
       delay(100); if (digitalRead(Button1) == HIGH) {EEPROM.put(memoriarpm2_2, rpm2_2); q=0; break;}
       }}}}
       else if (tela==27 && way2_2==0) {way2_2=1; EEPROM.put(memoriaway2_2, way2_2);}
       else if (tela==28 && rpm3_2 > 0) {rpm3_2--; EEPROM.put(memoriarpm3_2, rpm3_2);
       delay(200); 
       while (digitalRead(Button1) == LOW && rpm3_2 > 0) {
       rpm3_2--; q++;    
       lcd.setCursor(9,1); lcd.print(rpm3_2); lcd.print(F("  "));
       delay(300); if (digitalRead(Button1) == HIGH){EEPROM.put(memoriarpm3_2, rpm3_2); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button1) == LOW && rpm3_2 > 0) {
       rpm3_2--;
       lcd.setCursor(9,1); lcd.print(rpm3_2); lcd.print(F("  "));
       delay(100); if (digitalRead(Button1) == HIGH) {EEPROM.put(memoriarpm3_2, rpm3_2); q=0; break;}
       }}}}
       else if (tela==29 && way3_2==0) {way3_2=1; EEPROM.put(memoriaway3_2, way3_2);}
       else if (tela==30 && rpm4_2 > 0) {rpm4_2--; EEPROM.put(memoriarpm4_2, rpm4_2);
       delay(200); 
       while (digitalRead(Button1) == LOW && rpm4_2 > 0) {
       rpm4_2--; q++;    
       lcd.setCursor(9,1); lcd.print(rpm4_2); lcd.print(F("  "));
       delay(300); if (digitalRead(Button1) == HIGH){EEPROM.put(memoriarpm4_2, rpm4_2); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button1) == LOW && rpm4_2 > 0) {
       rpm4_2--;
       lcd.setCursor(9,1); lcd.print(rpm4_2); lcd.print(F("  "));
       delay(100); if (digitalRead(Button1) == HIGH) {EEPROM.put(memoriarpm4_2, rpm4_2); q=0; break;}
       }}}}
       else if (tela==31 && way4_2==0) {way4_2=1; EEPROM.put(memoriaway4_2, way4_2);}

       else if (tela==32){time3--; EEPROM.put(memoriatime3, time3);
       delay(200); 
       while (digitalRead(Button1) == LOW) {
       time3--; q++;    
       lcd.setCursor(6,1); lcd.print(time3); lcd.print(F("  "));
       delay(300); if (digitalRead(Button1) == HIGH){EEPROM.put(memoriatime3, time3); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button1) == LOW) {
       time3--;
       lcd.setCursor(6,1); lcd.print(time3); lcd.print(F("  "));
       delay(100); if (digitalRead(Button1) == HIGH) {EEPROM.put(memoriatime3, time3); q=0; break;}
       }}}}
       else if (tela==33 && relay1_3==0) {relay1_3=1; EEPROM.put(memoriarelay1_3, relay1_3);}
       else if (tela==34 && relay2_3==0) {relay2_3=1; EEPROM.put(memoriarelay2_3, relay2_3);}
       else if (tela==35 && relay3_3==0 && relay4_3==0) {relay3_3=1; EEPROM.put(memoriarelay3_3, relay3_3);}
       else if (tela==36 && relay4_3==0 && relay3_3==0) {relay4_3=1; EEPROM.put(memoriarelay4_3, relay4_3);}
       else if (tela==37 && relay5_3==0) {relay5_3=1; EEPROM.put(memoriarelay5_3, relay5_3);}
       else if (tela==38 && relay6_3==0) {relay6_3=1; EEPROM.put(memoriarelay6_3, relay6_3);}
       else if (tela==39 && rpm1_3 > 0) {rpm1_3--; EEPROM.put(memoriarpm1_3, rpm1_3);
       delay(200); 
       while (digitalRead(Button1) == LOW && rpm1_3 > 0) {
       rpm1_3--; q++;    
       lcd.setCursor(9,1); lcd.print(rpm1_3); lcd.print(F("  "));
       delay(300); if (digitalRead(Button1) == HIGH){EEPROM.put(memoriarpm1_3, rpm1_3); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button1) == LOW && rpm1_3 > 0) {
       rpm1_3--;
       lcd.setCursor(9,1); lcd.print(rpm1_3); lcd.print(F("  "));
       delay(100); if (digitalRead(Button1) == HIGH) {EEPROM.put(memoriarpm1_3, rpm1_3); q=0; break;}
       }}}}
       else if (tela==40 && way1_3==0) {way1_3=1; EEPROM.put(memoriaway1_3, way1_3);}
       else if (tela==41 && rpm2_3 > 0) {rpm2_3--; EEPROM.put(memoriarpm2_3, rpm2_3);
       delay(200); 
       while (digitalRead(Button1) == LOW && rpm2_3 > 0) {
       rpm2_3--; q++;    
       lcd.setCursor(9,1); lcd.print(rpm2_3); lcd.print(F("  "));
       delay(300); if (digitalRead(Button1) == HIGH){EEPROM.put(memoriarpm2_3, rpm2_3); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button1) == LOW && rpm2_3 > 0) {
       rpm2_3--;
       lcd.setCursor(9,1); lcd.print(rpm2_3); lcd.print(F("  "));
       delay(100); if (digitalRead(Button1) == HIGH) {EEPROM.put(memoriarpm2_3, rpm2_3); q=0; break;}
       }}}}
       else if (tela==42 && way2_3==0) {way2_3=1; EEPROM.put(memoriaway2_3, way2_3);}
       else if (tela==43 && rpm3_3 > 0) {rpm3_3--; EEPROM.put(memoriarpm3_3, rpm3_3);
       delay(200); 
       while (digitalRead(Button1) == LOW && rpm3_3 > 0) {
       rpm3_3--; q++;    
       lcd.setCursor(9,1); lcd.print(rpm3_3); lcd.print(F("  "));
       delay(300); if (digitalRead(Button1) == HIGH){EEPROM.put(memoriarpm3_3, rpm3_3); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button1) == LOW && rpm3_3 > 0) {
       rpm3_3--;
       lcd.setCursor(9,1); lcd.print(rpm3_3); lcd.print(F("  "));
       delay(100); if (digitalRead(Button1) == HIGH) {EEPROM.put(memoriarpm3_3, rpm3_3); q=0; break;}
       }}}}
       else if (tela==44 && way3_3==0) {way3_3=1; EEPROM.put(memoriaway3_3, way3_3);}
       else if (tela==45 && rpm4_3 > 0) {rpm4_3--; EEPROM.put(memoriarpm4_3, rpm4_3);
       delay(200); 
       while (digitalRead(Button1) == LOW && rpm4_3 > 0) {
       rpm4_3--; q++;    
       lcd.setCursor(9,1); lcd.print(rpm4_3); lcd.print(F("  "));
       delay(300); if (digitalRead(Button1) == HIGH){EEPROM.put(memoriarpm4_3, rpm4_3); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button1) == LOW && rpm4_3 > 0) {
       rpm4_3--;
       lcd.setCursor(9,1); lcd.print(rpm4_3); lcd.print(F("  "));
       delay(100); if (digitalRead(Button1) == HIGH) {EEPROM.put(memoriarpm4_3, rpm4_3); q=0; break;}
       }}}}
       else if (tela==46 && way4_3==0) {way4_3=1; EEPROM.put(memoriaway4_3, way4_3);}

       else if (tela==47){time4--; EEPROM.put(memoriatime4, time4);
       delay(200); 
       while (digitalRead(Button1) == LOW) {
       time4--; q++;    
       lcd.setCursor(6,1); lcd.print(time4); lcd.print(F("  "));
       delay(300); if (digitalRead(Button1) == HIGH){EEPROM.put(memoriatime4, time4); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button1) == LOW) {
       time4--;
       lcd.setCursor(6,1); lcd.print(time4); lcd.print(F("  "));
       delay(100); if (digitalRead(Button1) == HIGH) {EEPROM.put(memoriatime4, time4); q=0; break;}
       }}}}
       else if (tela==48 && relay1_4==0) {relay1_4=1; EEPROM.put(memoriarelay1_4, relay1_4);}
       else if (tela==49 && relay2_4==0) {relay2_4=1; EEPROM.put(memoriarelay2_4, relay2_4);}
       else if (tela==50 && relay3_4==0 && relay4_4==0) {relay3_4=1; EEPROM.put(memoriarelay3_4, relay3_4);}
       else if (tela==51 && relay4_4==0 && relay3_4==0) {relay4_4=1; EEPROM.put(memoriarelay4_4, relay4_4);}
       else if (tela==52 && relay5_4==0) {relay5_4=1; EEPROM.put(memoriarelay5_4, relay5_4);}
       else if (tela==53 && relay6_4==0) {relay6_4=1; EEPROM.put(memoriarelay6_4, relay6_4);}
       else if (tela==54 && rpm1_4 > 0) {rpm1_4--; EEPROM.put(memoriarpm1_4, rpm1_4);
       delay(200); 
       while (digitalRead(Button1) == LOW && rpm1_4 > 0) {
       rpm1_4--; q++;    
       lcd.setCursor(9,1); lcd.print(rpm1_4); lcd.print(F("  "));
       delay(300); if (digitalRead(Button1) == HIGH){EEPROM.put(memoriarpm1_4, rpm1_4); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button1) == LOW && rpm1_4 > 0) {
       rpm1_4--;
       lcd.setCursor(9,1); lcd.print(rpm1_4); lcd.print(F("  "));
       delay(100); if (digitalRead(Button1) == HIGH) {EEPROM.put(memoriarpm1_4, rpm1_4); q=0; break;}
       }}}}
       else if (tela==55 && way1_4==0) {way1_4=1; EEPROM.put(memoriaway1_4, way1_4);}
       else if (tela==56 && rpm2_4 > 0) {rpm2_4--; EEPROM.put(memoriarpm2_4, rpm2_4);
       delay(200); 
       while (digitalRead(Button1) == LOW && rpm2_4 > 0) {
       rpm2_4--; q++;    
       lcd.setCursor(9,1); lcd.print(rpm2_4); lcd.print(F("  "));
       delay(300); if (digitalRead(Button1) == HIGH){EEPROM.put(memoriarpm2_4, rpm2_4); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button1) == LOW && rpm2_4 > 0) {
       rpm2_4--;
       lcd.setCursor(9,1); lcd.print(rpm2_4); lcd.print(F("  "));
       delay(100); if (digitalRead(Button1) == HIGH) {EEPROM.put(memoriarpm2_4, rpm2_4); q=0; break;}
       }}}}
       else if (tela==57 && way2_4==0) {way2_4=1; EEPROM.put(memoriaway2_4, way2_4);}
       else if (tela==58 && rpm3_4 > 0) {rpm3_4--; EEPROM.put(memoriarpm3_4, rpm3_4);
       delay(200); 
       while (digitalRead(Button1) == LOW && rpm3_4 > 0) {
       rpm3_4--; q++;    
       lcd.setCursor(9,1); lcd.print(rpm3_4); lcd.print(F("  "));
       delay(300); if (digitalRead(Button1) == HIGH){EEPROM.put(memoriarpm3_4, rpm3_4); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button1) == LOW && rpm3_4 > 0) {
       rpm3_4--;
       lcd.setCursor(9,1); lcd.print(rpm3_4); lcd.print(F("  "));
       delay(100); if (digitalRead(Button1) == HIGH) {EEPROM.put(memoriarpm3_4, rpm3_4); q=0; break;}
       }}}}
       else if (tela==59 && way3_4==0) {way3_4=1; EEPROM.put(memoriaway3_4, way3_4);}
       else if (tela==60 && rpm4_4 > 0) {rpm4_4--; EEPROM.put(memoriarpm4_4, rpm4_4);
       delay(200); 
       while (digitalRead(Button1) == LOW && rpm4_4 > 0) {
       rpm4_4--; q++;    
       lcd.setCursor(9,1); lcd.print(rpm4_4); lcd.print(F("  "));
       delay(300); if (digitalRead(Button1) == HIGH){EEPROM.put(memoriarpm4_4, rpm4_4); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button1) == LOW && rpm4_4 > 0) {
       rpm4_4--;
       lcd.setCursor(9,1); lcd.print(rpm4_4); lcd.print(F("  "));
       delay(100); if (digitalRead(Button1) == HIGH) {EEPROM.put(memoriarpm4_4, rpm4_4); q=0; break;}
       }}}}
       else if (tela==61 && way4_4==0) {way4_4=1; EEPROM.put(memoriaway4_4, way4_4);}

       else if (tela==62){time5--; EEPROM.put(memoriatime5, time5);
       delay(200); 
       while (digitalRead(Button1) == LOW) {
       time5--; q++;    
       lcd.setCursor(6,1); lcd.print(time5); lcd.print(F("  "));
       delay(300); if (digitalRead(Button1) == HIGH){EEPROM.put(memoriatime5, time5); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button1) == LOW) {
       time5--;
       lcd.setCursor(6,1); lcd.print(time5); lcd.print(F("  "));
       delay(100); if (digitalRead(Button1) == HIGH) {EEPROM.put(memoriatime5, time5); q=0; break;}
       }}}}
       else if (tela==63 && relay1_5==0) {relay1_5=1; EEPROM.put(memoriarelay1_5, relay1_5);}
       else if (tela==64 && relay2_5==0) {relay2_5=1; EEPROM.put(memoriarelay2_5, relay2_5);}
       else if (tela==65 && relay3_5==0 && relay4_5==0) {relay3_5=1; EEPROM.put(memoriarelay3_5, relay3_5);}
       else if (tela==66 && relay4_5==0 && relay3_5==0) {relay4_5=1; EEPROM.put(memoriarelay4_5, relay4_5);}
       else if (tela==67 && relay5_5==0) {relay5_5=1; EEPROM.put(memoriarelay5_5, relay5_5);}
       else if (tela==68 && relay6_5==0) {relay6_5=1; EEPROM.put(memoriarelay6_5, relay6_5);}
       else if (tela==69 && rpm1_5 > 0) {rpm1_5--; EEPROM.put(memoriarpm1_5, rpm1_5);
       delay(200); 
       while (digitalRead(Button1) == LOW && rpm1_5 > 0) {
       rpm1_5--; q++;    
       lcd.setCursor(9,1); lcd.print(rpm1_5); lcd.print(F("  "));
       delay(300); if (digitalRead(Button1) == HIGH){EEPROM.put(memoriarpm1_5, rpm1_5); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button1) == LOW && rpm1_5 > 0) {
       rpm1_5--;
       lcd.setCursor(9,1); lcd.print(rpm1_5); lcd.print(F("  "));
       delay(100); if (digitalRead(Button1) == HIGH) {EEPROM.put(memoriarpm1_5, rpm1_5); q=0; break;}
       }}}}
       else if (tela==70 && way1_5==0) {way1_5=1; EEPROM.put(memoriaway1_5, way1_5);}
       else if (tela==71 && rpm2_5 > 0) {rpm2_5--; EEPROM.put(memoriarpm2_5, rpm2_5);
       delay(200); 
       while (digitalRead(Button1) == LOW && rpm2_5 > 0) {
       rpm2_5--; q++;    
       lcd.setCursor(9,1); lcd.print(rpm2_5); lcd.print(F("  "));
       delay(300); if (digitalRead(Button1) == HIGH){EEPROM.put(memoriarpm2_5, rpm2_5); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button1) == LOW && rpm2_5 > 0) {
       rpm2_5--;
       lcd.setCursor(9,1); lcd.print(rpm2_5); lcd.print(F("  "));
       delay(100); if (digitalRead(Button1) == HIGH) {EEPROM.put(memoriarpm2_5, rpm2_5); q=0; break;}
       }}}}
       else if (tela==72 && way2_5==0) {way2_5=1; EEPROM.put(memoriaway2_5, way2_5);}
       else if (tela==73 && rpm3_5 > 0) {rpm3_5--; EEPROM.put(memoriarpm3_5, rpm3_5);
       delay(200); 
       while (digitalRead(Button1) == LOW && rpm3_5 > 0) {
       rpm3_5--; q++;    
       lcd.setCursor(9,1); lcd.print(rpm3_5); lcd.print(F("  "));
       delay(300); if (digitalRead(Button1) == HIGH){EEPROM.put(memoriarpm3_5, rpm3_5); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button1) == LOW && rpm3_5 > 0) {
       rpm3_5--;
       lcd.setCursor(9,1); lcd.print(rpm3_5); lcd.print(F("  "));
       delay(100); if (digitalRead(Button1) == HIGH) {EEPROM.put(memoriarpm3_5, rpm3_5); q=0; break;}
       }}}}
       else if (tela==74 && way3_5==0) {way3_5=1; EEPROM.put(memoriaway3_5, way3_5);}
       else if (tela==75 && rpm4_5 > 0) {rpm4_5--; EEPROM.put(memoriarpm4_5, rpm4_5);
       delay(200); 
       while (digitalRead(Button1) == LOW && rpm4_5 > 0) {
       rpm4_5--; q++;    
       lcd.setCursor(9,1); lcd.print(rpm4_5); lcd.print(F("  "));
       delay(300); if (digitalRead(Button1) == HIGH){EEPROM.put(memoriarpm4_5, rpm4_5); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button1) == LOW && rpm4_5 > 0) {
       rpm4_5--;
       lcd.setCursor(9,1); lcd.print(rpm4_5); lcd.print(F("  "));
       delay(100); if (digitalRead(Button1) == HIGH) {EEPROM.put(memoriarpm4_5, rpm4_5); q=0; break;}
       }}}}
       else if (tela==76 && way4_5==0) {way4_5=1; EEPROM.put(memoriaway4_5, way4_5);}

       else if (tela==77){time6--; EEPROM.put(memoriatime6, time6);
       delay(200); 
       while (digitalRead(Button1) == LOW) {
       time6--; q++;    
       lcd.setCursor(6,1); lcd.print(time6); lcd.print(F("  "));
       delay(300); if (digitalRead(Button1) == HIGH){EEPROM.put(memoriatime6, time6); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button1) == LOW) {
       time6--;
       lcd.setCursor(6,1); lcd.print(time6); lcd.print(F("  "));
       delay(100); if (digitalRead(Button1) == HIGH) {EEPROM.put(memoriatime6, time6); q=0; break;}
       }}}}
       else if (tela==78 && relay1_6==0) {relay1_6=1; EEPROM.put(memoriarelay1_6, relay1_6);}
       else if (tela==79 && relay2_6==0) {relay2_6=1; EEPROM.put(memoriarelay2_6, relay2_6);}
       else if (tela==80 && relay3_6==0 && relay4_6==0) {relay3_6=1; EEPROM.put(memoriarelay3_6, relay3_6);}
       else if (tela==81 && relay4_6==0 && relay3_6==0) {relay4_6=1; EEPROM.put(memoriarelay4_6, relay4_6);}
       else if (tela==82 && relay5_6==0) {relay5_6=1; EEPROM.put(memoriarelay5_6, relay5_6);}
       else if (tela==83 && relay6_6==0) {relay6_6=1; EEPROM.put(memoriarelay6_6, relay6_6);}
       else if (tela==84 && rpm1_6 > 0) {rpm1_6--; EEPROM.put(memoriarpm1_6, rpm1_6);
       delay(200); 
       while (digitalRead(Button1) == LOW && rpm1_6 > 0) {
       rpm1_6--; q++;    
       lcd.setCursor(9,1); lcd.print(rpm1_6); lcd.print(F("  "));
       delay(300); if (digitalRead(Button1) == HIGH){EEPROM.put(memoriarpm1_6, rpm1_6); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button1) == LOW && rpm1_6 > 0) {
       rpm1_6--;
       lcd.setCursor(9,1); lcd.print(rpm1_6); lcd.print(F("  "));
       delay(100); if (digitalRead(Button1) == HIGH) {EEPROM.put(memoriarpm1_6, rpm1_6); q=0; break;}
       }}}}
       else if (tela==85 && way1_6==0) {way1_6=1; EEPROM.put(memoriaway1_6, way1_6);}
       else if (tela==86 && rpm2_6 > 0) {rpm2_6--; EEPROM.put(memoriarpm2_6, rpm2_6);
       delay(200); 
       while (digitalRead(Button1) == LOW && rpm2_6 > 0) {
       rpm2_6--; q++;    
       lcd.setCursor(9,1); lcd.print(rpm2_6); lcd.print(F("  "));
       delay(300); if (digitalRead(Button1) == HIGH){EEPROM.put(memoriarpm2_6, rpm2_6); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button1) == LOW && rpm2_6 > 0) {
       rpm2_6--;
       lcd.setCursor(9,1); lcd.print(rpm2_6); lcd.print(F("  "));
       delay(100); if (digitalRead(Button1) == HIGH) {EEPROM.put(memoriarpm2_6, rpm2_6); q=0; break;}
       }}}}
       else if (tela==87 && way2_6==0) {way2_6=1; EEPROM.put(memoriaway2_6, way2_6);}
       else if (tela==88 && rpm3_6 > 0) {rpm3_6--; EEPROM.put(memoriarpm3_6, rpm3_6);
       delay(200); 
       while (digitalRead(Button1) == LOW && rpm3_6 > 0) {
       rpm3_6--; q++;    
       lcd.setCursor(9,1); lcd.print(rpm3_6); lcd.print(F("  "));
       delay(300); if (digitalRead(Button1) == HIGH){EEPROM.put(memoriarpm3_6, rpm3_6); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button1) == LOW && rpm3_6 > 0) {
       rpm3_6--;
       lcd.setCursor(9,1); lcd.print(rpm3_6); lcd.print(F("  "));
       delay(100); if (digitalRead(Button1) == HIGH) {EEPROM.put(memoriarpm3_6, rpm3_6); q=0; break;}
       }}}}
       else if (tela==89 && way3_6==0) {way3_6=1; EEPROM.put(memoriaway3_6, way3_6);}
       else if (tela==90 && rpm4_6 > 0) {rpm4_6--; EEPROM.put(memoriarpm4_6, rpm4_6);
       delay(200); 
       while (digitalRead(Button1) == LOW && rpm4_6 > 0) {
       rpm4_6--; q++;    
       lcd.setCursor(9,1); lcd.print(rpm4_6); lcd.print(F("  "));
       delay(300); if (digitalRead(Button1) == HIGH){EEPROM.put(memoriarpm4_6, rpm4_6); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button1) == LOW && rpm4_6 > 0) {
       rpm4_6--;
       lcd.setCursor(9,1); lcd.print(rpm4_6); lcd.print(F("  "));
       delay(100); if (digitalRead(Button1) == HIGH) {EEPROM.put(memoriarpm4_6, rpm4_6); q=0; break;}
       }}}}
       else if (tela==91 && way4_6==0) {way4_6=1; EEPROM.put(memoriaway4_6, way4_6);}

       else if (tela==92){time7--; EEPROM.put(memoriatime7, time7);
       delay(200); 
       while (digitalRead(Button1) == LOW) {
       time7--; q++;    
       lcd.setCursor(6,1); lcd.print(time7); lcd.print(F("  "));
       delay(300); if (digitalRead(Button1) == HIGH){EEPROM.put(memoriatime7, time7); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button1) == LOW) {
       time7--;
       lcd.setCursor(6,1); lcd.print(time7); lcd.print(F("  "));
       delay(100); if (digitalRead(Button1) == HIGH) {EEPROM.put(memoriatime7, time7); q=0; break;}
       }}}}
       else if (tela==93 && relay1_7==0) {relay1_7=1; EEPROM.put(memoriarelay1_7, relay1_7);}
       else if (tela==94 && relay2_7==0) {relay2_7=1; EEPROM.put(memoriarelay2_7, relay2_7);}
       else if (tela==95 && relay3_7==0 && relay4_7==0) {relay3_7=1; EEPROM.put(memoriarelay3_7, relay3_7);}
       else if (tela==96 && relay4_7==0 && relay3_7==0) {relay4_7=1; EEPROM.put(memoriarelay4_7, relay4_7);}
       else if (tela==97 && relay5_7==0) {relay5_7=1; EEPROM.put(memoriarelay5_7, relay5_7);}
       else if (tela==98 && relay6_7==0) {relay6_7=1; EEPROM.put(memoriarelay6_7, relay6_7);}
       else if (tela==99 && rpm1_7 > 0) {rpm1_7--; EEPROM.put(memoriarpm1_7, rpm1_7);
       delay(200); 
       while (digitalRead(Button1) == LOW && rpm1_7 > 0) {
       rpm1_7--; q++;    
       lcd.setCursor(9,1); lcd.print(rpm1_7); lcd.print(F("  "));
       delay(300); if (digitalRead(Button1) == HIGH){EEPROM.put(memoriarpm1_7, rpm1_7); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button1) == LOW && rpm1_7 > 0) {
       rpm1_7--;
       lcd.setCursor(9,1); lcd.print(rpm1_7); lcd.print(F("  "));
       delay(100); if (digitalRead(Button1) == HIGH) {EEPROM.put(memoriarpm1_7, rpm1_7); q=0; break;}
       }}}}
       else if (tela==100 && way1_7==0) {way1_7=1; EEPROM.put(memoriaway1_7, way1_7);}
       else if (tela==101 && rpm2_7 > 0) {rpm2_7--; EEPROM.put(memoriarpm2_7, rpm2_7);
       delay(200); 
       while (digitalRead(Button1) == LOW && rpm2_7 > 0) {
       rpm2_7--; q++;    
       lcd.setCursor(9,1); lcd.print(rpm2_7); lcd.print(F("  "));
       delay(300); if (digitalRead(Button1) == HIGH){EEPROM.put(memoriarpm2_7, rpm2_7); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button1) == LOW && rpm2_7 > 0) {
       rpm2_7--;
       lcd.setCursor(9,1); lcd.print(rpm2_7); lcd.print(F("  "));
       delay(100); if (digitalRead(Button1) == HIGH) {EEPROM.put(memoriarpm2_7, rpm2_7); q=0; break;}
       }}}}
       else if (tela==102 && way2_7==0) {way2_7=1; EEPROM.put(memoriaway2_7, way2_7);}
       else if (tela==103 && rpm3_7 > 0) {rpm3_7--; EEPROM.put(memoriarpm3_7, rpm3_7);
       delay(200); 
       while (digitalRead(Button1) == LOW && rpm3_7 > 0) {
       rpm3_7--; q++;    
       lcd.setCursor(9,1); lcd.print(rpm3_7); lcd.print(F("  "));
       delay(300); if (digitalRead(Button1) == HIGH){EEPROM.put(memoriarpm3_7, rpm3_7); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button1) == LOW && rpm3_7 > 0) {
       rpm3_7--;
       lcd.setCursor(9,1); lcd.print(rpm3_7); lcd.print(F("  "));
       delay(100); if (digitalRead(Button1) == HIGH) {EEPROM.put(memoriarpm3_7, rpm3_7); q=0; break;}
       }}}}
       else if (tela==104 && way3_7==0) {way3_7=1; EEPROM.put(memoriaway3_7, way3_7);}
       else if (tela==105 && rpm4_7 > 0) {rpm4_7--; EEPROM.put(memoriarpm4_7, rpm4_7);
       delay(200); 
       while (digitalRead(Button1) == LOW && rpm4_7 > 0) {
       rpm4_7--; q++;    
       lcd.setCursor(9,1); lcd.print(rpm4_7); lcd.print(F("  "));
       delay(300); if (digitalRead(Button1) == HIGH){EEPROM.put(memoriarpm4_7, rpm4_7); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button1) == LOW && rpm4_7 > 0) {
       rpm4_7--;
       lcd.setCursor(9,1); lcd.print(rpm4_7); lcd.print(F("  "));
       delay(100); if (digitalRead(Button1) == HIGH) {EEPROM.put(memoriarpm4_7, rpm4_7); q=0; break;}
       }}}}
       else if (tela==106 && way4_7==0) {way4_7=1; EEPROM.put(memoriaway4_7, way4_7);}

       else if (tela==107){time8--; EEPROM.put(memoriatime8, time8);
       delay(200); 
       while (digitalRead(Button1) == LOW) {
       time8--; q++;    
       lcd.setCursor(6,1); lcd.print(time8); lcd.print(F("  "));
       delay(300); if (digitalRead(Button1) == HIGH){EEPROM.put(memoriatime8, time8); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button1) == LOW) {
       time8--;
       lcd.setCursor(6,1); lcd.print(time8); lcd.print(F("  "));
       delay(100); if (digitalRead(Button1) == HIGH) {EEPROM.put(memoriatime8, time8); q=0; break;}
       }}}}
       else if (tela==108 && relay1_8==0) {relay1_8=1; EEPROM.put(memoriarelay1_8, relay1_8);}
       else if (tela==109 && relay2_8==0) {relay2_8=1; EEPROM.put(memoriarelay2_8, relay2_8);}
       else if (tela==110 && relay3_8==0 && relay4_8==0) {relay3_8=1; EEPROM.put(memoriarelay3_8, relay3_8);}
       else if (tela==111 && relay4_8==0 && relay3_8==0) {relay4_8=1; EEPROM.put(memoriarelay4_8, relay4_8);}
       else if (tela==112 && relay5_8==0) {relay5_8=1; EEPROM.put(memoriarelay5_8, relay5_8);}
       else if (tela==113 && relay6_8==0) {relay6_8=1; EEPROM.put(memoriarelay6_8, relay6_8);}
       else if (tela==114 && rpm1_8 > 0) {rpm1_8--; EEPROM.put(memoriarpm1_8, rpm1_8);
       delay(200); 
       while (digitalRead(Button1) == LOW && rpm1_8 > 0) {
       rpm1_8--; q++;    
       lcd.setCursor(9,1); lcd.print(rpm1_8); lcd.print(F("  "));
       delay(300); if (digitalRead(Button1) == HIGH){EEPROM.put(memoriarpm1_8, rpm1_8); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button1) == LOW && rpm1_8 > 0) {
       rpm1_8--;
       lcd.setCursor(9,1); lcd.print(rpm1_8); lcd.print(F("  "));
       delay(100); if (digitalRead(Button1) == HIGH) {EEPROM.put(memoriarpm1_8, rpm1_8); q=0; break;}
       }}}}
       else if (tela==115 && way1_8==0) {way1_8=1; EEPROM.put(memoriaway1_8, way1_8);}
       else if (tela==116 && rpm2_8 > 0) {rpm2_8--; EEPROM.put(memoriarpm2_8, rpm2_8);
       delay(200); 
       while (digitalRead(Button1) == LOW && rpm2_8 > 0) {
       rpm2_8--; q++;    
       lcd.setCursor(9,1); lcd.print(rpm2_8); lcd.print(F("  "));
       delay(300); if (digitalRead(Button1) == HIGH){EEPROM.put(memoriarpm2_8, rpm2_8); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button1) == LOW && rpm2_8 > 0) {
       rpm2_8--;
       lcd.setCursor(9,1); lcd.print(rpm2_8); lcd.print(F("  "));
       delay(100); if (digitalRead(Button1) == HIGH) {EEPROM.put(memoriarpm2_8, rpm2_8); q=0; break;}
       }}}}
       else if (tela==117 && way2_8==0) {way2_8=1; EEPROM.put(memoriaway2_8, way2_8);}
       else if (tela==118 && rpm3_8 > 0) {rpm3_8--; EEPROM.put(memoriarpm3_8, rpm3_8);
       delay(200); 
       while (digitalRead(Button1) == LOW && rpm3_8 > 0) {
       rpm3_8--; q++;    
       lcd.setCursor(9,1); lcd.print(rpm3_8); lcd.print(F("  "));
       delay(300); if (digitalRead(Button1) == HIGH){EEPROM.put(memoriarpm3_8, rpm3_8); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button1) == LOW && rpm3_8 > 0) {
       rpm3_8--;
       lcd.setCursor(9,1); lcd.print(rpm3_8); lcd.print(F("  "));
       delay(100); if (digitalRead(Button1) == HIGH) {EEPROM.put(memoriarpm3_8, rpm3_8); q=0; break;}
       }}}}
       else if (tela==119 && way3_8==0) {way3_8=1; EEPROM.put(memoriaway3_8, way3_8);}
       else if (tela==120 && rpm4_8 > 0) {rpm4_8--; EEPROM.put(memoriarpm4_8, rpm4_8);
       delay(200); 
       while (digitalRead(Button1) == LOW && rpm4_8 > 0) {
       rpm4_8--; q++;    
       lcd.setCursor(9,1); lcd.print(rpm4_8); lcd.print(F("  "));
       delay(300); if (digitalRead(Button1) == HIGH){EEPROM.put(memoriarpm4_8, rpm4_8); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button1) == LOW && rpm4_8 > 0) {
       rpm4_8--;
       lcd.setCursor(9,1); lcd.print(rpm4_8); lcd.print(F("  "));
       delay(100); if (digitalRead(Button1) == HIGH) {EEPROM.put(memoriarpm4_8, rpm4_8); q=0; break;}
       }}}}
       else if (tela==121 && way4_8==0) {way4_8=1; EEPROM.put(memoriaway4_8, way4_8);}

       else if (tela==122){time9--; EEPROM.put(memoriatime9, time9);
       delay(200); 
       while (digitalRead(Button1) == LOW) {
       time9--; q++;    
       lcd.setCursor(6,1); lcd.print(time9); lcd.print(F("  "));
       delay(300); if (digitalRead(Button1) == HIGH){EEPROM.put(memoriatime9, time9); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button1) == LOW) {
       time9--;
       lcd.setCursor(6,1); lcd.print(time9); lcd.print(F("  "));
       delay(100); if (digitalRead(Button1) == HIGH) {EEPROM.put(memoriatime9, time9); q=0; break;}
       }}}}
       else if (tela==123 && relay1_9==0) {relay1_9=1; EEPROM.put(memoriarelay1_9, relay1_9);}
       else if (tela==124 && relay2_9==0) {relay2_9=1; EEPROM.put(memoriarelay2_9, relay2_9);}
       else if (tela==125 && relay3_9==0 && relay4_9==0) {relay3_9=1; EEPROM.put(memoriarelay3_9, relay3_9);}
       else if (tela==126 && relay4_9==0 && relay3_9==0) {relay4_9=1; EEPROM.put(memoriarelay4_9, relay4_9);}
       else if (tela==127 && relay5_9==0) {relay5_9=1; EEPROM.put(memoriarelay5_9, relay5_9);}
       else if (tela==128 && relay6_9==0) {relay6_9=1; EEPROM.put(memoriarelay6_9, relay6_9);}
       else if (tela==129 && rpm1_9 > 0) {rpm1_9--; EEPROM.put(memoriarpm1_9, rpm1_9);
       delay(200); 
       while (digitalRead(Button1) == LOW && rpm1_9 > 0) {
       rpm1_9--; q++;    
       lcd.setCursor(9,1); lcd.print(rpm1_9); lcd.print(F("  "));
       delay(300); if (digitalRead(Button1) == HIGH){EEPROM.put(memoriarpm1_9, rpm1_9); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button1) == LOW && rpm1_9 > 0) {
       rpm1_9--;
       lcd.setCursor(9,1); lcd.print(rpm1_9); lcd.print(F("  "));
       delay(100); if (digitalRead(Button1) == HIGH) {EEPROM.put(memoriarpm1_9, rpm1_9); q=0; break;}
       }}}}
       else if (tela==130 && way1_9==0) {way1_9=1; EEPROM.put(memoriaway1_9, way1_9);}
       else if (tela==131 && rpm2_9 > 0) {rpm2_9--; EEPROM.put(memoriarpm2_9, rpm2_9);
       delay(200); 
       while (digitalRead(Button1) == LOW && rpm2_9 > 0) {
       rpm2_9--; q++;    
       lcd.setCursor(9,1); lcd.print(rpm2_9); lcd.print(F("  "));
       delay(300); if (digitalRead(Button1) == HIGH){EEPROM.put(memoriarpm2_9, rpm2_9); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button1) == LOW && rpm2_9 > 0) {
       rpm2_9--;
       lcd.setCursor(9,1); lcd.print(rpm2_9); lcd.print(F("  "));
       delay(100); if (digitalRead(Button1) == HIGH) {EEPROM.put(memoriarpm2_9, rpm2_9); q=0; break;}
       }}}}
       else if (tela==132 && way2_9==0) {way2_9=1; EEPROM.put(memoriaway2_9, way2_9);}
       else if (tela==133 && rpm3_9 > 0) {rpm3_9--; EEPROM.put(memoriarpm3_9, rpm3_9);
       delay(200); 
       while (digitalRead(Button1) == LOW && rpm3_9 > 0) {
       rpm3_9--; q++;    
       lcd.setCursor(9,1); lcd.print(rpm3_9); lcd.print(F("  "));
       delay(300); if (digitalRead(Button1) == HIGH){EEPROM.put(memoriarpm3_9, rpm3_9); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button1) == LOW && rpm3_9 > 0) {
       rpm3_9--;
       lcd.setCursor(9,1); lcd.print(rpm3_9); lcd.print(F("  "));
       delay(100); if (digitalRead(Button1) == HIGH) {EEPROM.put(memoriarpm3_9, rpm3_9); q=0; break;}
       }}}}
       else if (tela==134 && way3_9==0) {way3_9=1; EEPROM.put(memoriaway3_9, way3_9);}
       else if (tela==135 && rpm4_9 > 0) {rpm4_9--; EEPROM.put(memoriarpm4_9, rpm4_9);
       delay(200); 
       while (digitalRead(Button1) == LOW && rpm4_9 > 0) {
       rpm4_9--; q++;    
       lcd.setCursor(9,1); lcd.print(rpm4_9); lcd.print(F("  "));
       delay(300); if (digitalRead(Button1) == HIGH){EEPROM.put(memoriarpm4_9, rpm4_9); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button1) == LOW && rpm4_9 > 0) {
       rpm4_9--;
       lcd.setCursor(9,1); lcd.print(rpm4_9); lcd.print(F("  "));
       delay(100); if (digitalRead(Button1) == HIGH) {EEPROM.put(memoriarpm4_9, rpm4_9); q=0; break;}
       }}}}
       else if (tela==136 && way4_9==0) {way4_9=1; EEPROM.put(memoriaway4_9, way4_9);}

       else if (tela==137){time10--; EEPROM.put(memoriatime10, time10);
       delay(200); 
       while (digitalRead(Button1) == LOW) {
       time10--; q++;    
       lcd.setCursor(6,1); lcd.print(time10); lcd.print(F("  "));
       delay(300); if (digitalRead(Button1) == HIGH){EEPROM.put(memoriatime10, time10); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button1) == LOW) {
       time10--;
       lcd.setCursor(6,1); lcd.print(time10); lcd.print(F("  "));
       delay(100); if (digitalRead(Button1) == HIGH) {EEPROM.put(memoriatime10, time10); q=0; break;}
       }}}}
       else if (tela==138 && relay1_10==0) {relay1_10=1; EEPROM.put(memoriarelay1_10, relay1_10);}
       else if (tela==139 && relay2_10==0) {relay2_10=1; EEPROM.put(memoriarelay2_10, relay2_10);}
       else if (tela==140 && relay3_10==0 && relay4_10==0) {relay3_10=1; EEPROM.put(memoriarelay3_10, relay3_10);}
       else if (tela==141 && relay4_10==0 && relay3_10==0) {relay4_10=1; EEPROM.put(memoriarelay4_10, relay4_10);}
       else if (tela==142 && relay5_10==0) {relay5_10=1; EEPROM.put(memoriarelay5_10, relay5_10);}
       else if (tela==143 && relay6_10==0) {relay6_10=1; EEPROM.put(memoriarelay6_10, relay6_10);}
       else if (tela==144 && rpm1_10 > 0) {rpm1_10--; EEPROM.put(memoriarpm1_10, rpm1_10);
       delay(200); 
       while (digitalRead(Button1) == LOW && rpm1_10 > 0) {
       rpm1_10--; q++;    
       lcd.setCursor(9,1); lcd.print(rpm1_10); lcd.print(F("  "));
       delay(300); if (digitalRead(Button1) == HIGH){EEPROM.put(memoriarpm1_10, rpm1_10); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button1) == LOW && rpm1_10 > 0) {
       rpm1_10--;
       lcd.setCursor(9,1); lcd.print(rpm1_10); lcd.print(F("  "));
       delay(100); if (digitalRead(Button1) == HIGH) {EEPROM.put(memoriarpm1_10, rpm1_10); q=0; break;}
       }}}}
       else if (tela==145 && way1_10==0) {way1_10=1; EEPROM.put(memoriaway1_10, way1_10);}
       else if (tela==146 && rpm2_10 > 0) {rpm2_10--; EEPROM.put(memoriarpm2_10, rpm2_10);
       delay(200); 
       while (digitalRead(Button1) == LOW && rpm2_10 > 0) {
       rpm2_10--; q++;    
       lcd.setCursor(9,1); lcd.print(rpm2_10); lcd.print(F("  "));
       delay(300); if (digitalRead(Button1) == HIGH){EEPROM.put(memoriarpm2_10, rpm2_10); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button1) == LOW && rpm2_10 > 0) {
       rpm2_10--;
       lcd.setCursor(9,1); lcd.print(rpm2_10); lcd.print(F("  "));
       delay(100); if (digitalRead(Button1) == HIGH) {EEPROM.put(memoriarpm2_10, rpm2_10); q=0; break;}
       }}}}
       else if (tela==147 && way2_10==0) {way2_10=1; EEPROM.put(memoriaway2_10, way2_10);}
       else if (tela==148 && rpm3_10 > 0) {rpm3_10--; EEPROM.put(memoriarpm3_10, rpm3_10);
       delay(200); 
       while (digitalRead(Button1) == LOW && rpm3_10 > 0) {
       rpm3_10--; q++;    
       lcd.setCursor(9,1); lcd.print(rpm3_10); lcd.print(F("  "));
       delay(300); if (digitalRead(Button1) == HIGH){EEPROM.put(memoriarpm3_10, rpm3_10); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button1) == LOW && rpm3_10 > 0) {
       rpm3_10--;
       lcd.setCursor(9,1); lcd.print(rpm3_10); lcd.print(F("  "));
       delay(100); if (digitalRead(Button1) == HIGH) {EEPROM.put(memoriarpm3_10, rpm3_10); q=0; break;}
       }}}}
       else if (tela==149 && way3_10==0) {way3_10=1; EEPROM.put(memoriaway3_10, way3_10);}
       else if (tela==150 && rpm4_10 > 0) {rpm4_10--; EEPROM.put(memoriarpm4_10, rpm4_10);
       delay(200); 
       while (digitalRead(Button1) == LOW && rpm4_10 > 0) {
       rpm4_10--; q++;    
       lcd.setCursor(9,1); lcd.print(rpm4_10); lcd.print(F("  "));
       delay(300); if (digitalRead(Button1) == HIGH){EEPROM.put(memoriarpm4_10, rpm4_10); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button1) == LOW && rpm4_10 > 0) {
       rpm4_10--;
       lcd.setCursor(9,1); lcd.print(rpm4_10); lcd.print(F("  "));
       delay(100); if (digitalRead(Button1) == HIGH) {EEPROM.put(memoriarpm4_10, rpm4_10); q=0; break;}
       }}}}
       else if (tela==151 && way4_10==0) {way4_10=1; EEPROM.put(memoriaway4_10, way4_10);}

       else if (tela==152){time11--; EEPROM.put(memoriatime11, time11);
       delay(200); 
       while (digitalRead(Button1) == LOW) {
       time11--; q++;    
       lcd.setCursor(6,1); lcd.print(time11); lcd.print(F("  "));
       delay(300); if (digitalRead(Button1) == HIGH){EEPROM.put(memoriatime11, time11); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button1) == LOW) {
       time11--;
       lcd.setCursor(6,1); lcd.print(time11); lcd.print(F("  "));
       delay(100); if (digitalRead(Button1) == HIGH) {EEPROM.put(memoriatime11, time11); q=0; break;}
       }}}}
       else if (tela==153 && relay1_11==0) {relay1_11=1; EEPROM.put(memoriarelay1_11, relay1_11);}
       else if (tela==154 && relay2_11==0) {relay2_11=1; EEPROM.put(memoriarelay2_11, relay2_11);}
       else if (tela==155 && relay3_11==0 && relay4_11==0) {relay3_11=1; EEPROM.put(memoriarelay3_11, relay3_11);}
       else if (tela==156 && relay4_11==0 && relay3_11==0) {relay4_11=1; EEPROM.put(memoriarelay4_11, relay4_11);}
       else if (tela==157 && relay5_11==0) {relay5_11=1; EEPROM.put(memoriarelay5_11, relay5_11);}
       else if (tela==158 && relay6_11==0) {relay6_11=1; EEPROM.put(memoriarelay6_11, relay6_11);}
       else if (tela==159 && rpm1_11 > 0) {rpm1_11--; EEPROM.put(memoriarpm1_11, rpm1_11);
       delay(200); 
       while (digitalRead(Button1) == LOW && rpm1_11 > 0) {
       rpm1_11--; q++;    
       lcd.setCursor(9,1); lcd.print(rpm1_11); lcd.print(F("  "));
       delay(300); if (digitalRead(Button1) == HIGH){EEPROM.put(memoriarpm1_11, rpm1_11); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button1) == LOW && rpm1_11 > 0) {
       rpm1_11--;
       lcd.setCursor(9,1); lcd.print(rpm1_11); lcd.print(F("  "));
       delay(100); if (digitalRead(Button1) == HIGH) {EEPROM.put(memoriarpm1_11, rpm1_11); q=0; break;}
       }}}}
       else if (tela==160 && way1_11==0) {way1_11=1; EEPROM.put(memoriaway1_11, way1_11);}
       else if (tela==161 && rpm2_11 > 0) {rpm2_11--; EEPROM.put(memoriarpm2_11, rpm2_11);
       delay(200); 
       while (digitalRead(Button1) == LOW && rpm2_11 > 0) {
       rpm2_11--; q++;    
       lcd.setCursor(9,1); lcd.print(rpm2_11); lcd.print(F("  "));
       delay(300); if (digitalRead(Button1) == HIGH){EEPROM.put(memoriarpm2_11, rpm2_11); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button1) == LOW && rpm2_11 > 0) {
       rpm2_11--;
       lcd.setCursor(9,1); lcd.print(rpm2_11); lcd.print(F("  "));
       delay(100); if (digitalRead(Button1) == HIGH) {EEPROM.put(memoriarpm2_11, rpm2_11); q=0; break;}
       }}}}
       else if (tela==162 && way2_11==0) {way2_11=1; EEPROM.put(memoriaway2_11, way2_11);}
       else if (tela==163 && rpm3_11 > 0) {rpm3_11--; EEPROM.put(memoriarpm3_11, rpm3_11);
       delay(200); 
       while (digitalRead(Button1) == LOW && rpm3_11 > 0) {
       rpm3_11--; q++;    
       lcd.setCursor(9,1); lcd.print(rpm3_11); lcd.print(F("  "));
       delay(300); if (digitalRead(Button1) == HIGH){EEPROM.put(memoriarpm3_11, rpm3_11); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button1) == LOW && rpm3_11 > 0) {
       rpm3_11--;
       lcd.setCursor(9,1); lcd.print(rpm3_11); lcd.print(F("  "));
       delay(100); if (digitalRead(Button1) == HIGH) {EEPROM.put(memoriarpm3_11, rpm3_11); q=0; break;}
       }}}}
       else if (tela==164 && way3_11==0) {way3_11=1; EEPROM.put(memoriaway3_11, way3_11);}
       else if (tela==165 && rpm4_11 > 0) {rpm4_11--; EEPROM.put(memoriarpm4_11, rpm4_11);
       delay(200); 
       while (digitalRead(Button1) == LOW && rpm4_11 > 0) {
       rpm4_11--; q++;    
       lcd.setCursor(9,1); lcd.print(rpm4_11); lcd.print(F("  "));
       delay(300); if (digitalRead(Button1) == HIGH){EEPROM.put(memoriarpm4_11, rpm4_11); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button1) == LOW && rpm4_11 > 0) {
       rpm4_11--;
       lcd.setCursor(9,1); lcd.print(rpm4_11); lcd.print(F("  "));
       delay(100); if (digitalRead(Button1) == HIGH) {EEPROM.put(memoriarpm4_11, rpm4_11); q=0; break;}
       }}}}
       else if (tela==166 && way4_11==0) {way4_11=1; EEPROM.put(memoriaway4_11, way4_11);}

       else if (tela==167){time12--; EEPROM.put(memoriatime12, time12);
       delay(200); 
       while (digitalRead(Button1) == LOW) {
       time12--; q++;    
       lcd.setCursor(6,1); lcd.print(time12); lcd.print(F("  "));
       delay(300); if (digitalRead(Button1) == HIGH){EEPROM.put(memoriatime12, time12); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button1) == LOW) {
       time12--;
       lcd.setCursor(6,1); lcd.print(time12); lcd.print(F("  "));
       delay(100); if (digitalRead(Button1) == HIGH) {EEPROM.put(memoriatime12, time12); q=0; break;}
       }}}}
       else if (tela==168 && relay1_12==0) {relay1_12=1; EEPROM.put(memoriarelay1_12, relay1_12);}
       else if (tela==169 && relay2_12==0) {relay2_12=1; EEPROM.put(memoriarelay2_12, relay2_12);}
       else if (tela==170 && relay3_12==0 && relay4_12==0) {relay3_12=1; EEPROM.put(memoriarelay3_12, relay3_12);}
       else if (tela==171 && relay4_12==0 && relay3_12==0) {relay4_12=1; EEPROM.put(memoriarelay4_12, relay4_12);}
       else if (tela==172 && relay5_12==0) {relay5_12=1; EEPROM.put(memoriarelay5_12, relay5_12);}
       else if (tela==173 && relay6_12==0) {relay6_12=1; EEPROM.put(memoriarelay6_12, relay6_12);}
       else if (tela==174 && rpm1_12 > 0) {rpm1_12--; EEPROM.put(memoriarpm1_12, rpm1_12);
       delay(200); 
       while (digitalRead(Button1) == LOW && rpm1_12 > 0) {
       rpm1_12--; q++;    
       lcd.setCursor(9,1); lcd.print(rpm1_12); lcd.print(F("  "));
       delay(300); if (digitalRead(Button1) == HIGH){EEPROM.put(memoriarpm1_12, rpm1_12); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button1) == LOW && rpm1_12 > 0) {
       rpm1_12--;
       lcd.setCursor(9,1); lcd.print(rpm1_12); lcd.print(F("  "));
       delay(100); if (digitalRead(Button1) == HIGH) {EEPROM.put(memoriarpm1_12, rpm1_12); q=0; break;}
       }}}}
       else if (tela==175 && way1_12==0) {way1_12=1; EEPROM.put(memoriaway1_12, way1_12);}
       else if (tela==176 && rpm2_12 > 0) {rpm2_12--; EEPROM.put(memoriarpm2_12, rpm2_12);
       delay(200); 
       while (digitalRead(Button1) == LOW && rpm2_12 > 0) {
       rpm2_12--; q++;    
       lcd.setCursor(9,1); lcd.print(rpm2_12); lcd.print(F("  "));
       delay(300); if (digitalRead(Button1) == HIGH){EEPROM.put(memoriarpm2_12, rpm2_12); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button1) == LOW && rpm2_12 > 0) {
       rpm2_12--;
       lcd.setCursor(9,1); lcd.print(rpm2_12); lcd.print(F("  "));
       delay(100); if (digitalRead(Button1) == HIGH) {EEPROM.put(memoriarpm2_12, rpm2_12); q=0; break;}
       }}}}
       else if (tela==177 && way2_12==0) {way2_12=1; EEPROM.put(memoriaway2_12, way2_12);}
       else if (tela==178 && rpm3_12 > 0) {rpm3_12--; EEPROM.put(memoriarpm3_12, rpm3_12);
       delay(200); 
       while (digitalRead(Button1) == LOW && rpm3_12 > 0) {
       rpm3_12--; q++;    
       lcd.setCursor(9,1); lcd.print(rpm3_12); lcd.print(F("  "));
       delay(300); if (digitalRead(Button1) == HIGH){EEPROM.put(memoriarpm3_12, rpm3_12); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button1) == LOW && rpm3_12 > 0) {
       rpm3_12--;
       lcd.setCursor(9,1); lcd.print(rpm3_12); lcd.print(F("  "));
       delay(100); if (digitalRead(Button1) == HIGH) {EEPROM.put(memoriarpm3_12, rpm3_12); q=0; break;}
       }}}}
       else if (tela==179 && way3_12==0) {way3_12=1; EEPROM.put(memoriaway3_12, way3_12);}
       else if (tela==180 && rpm4_12 > 0) {rpm4_12--; EEPROM.put(memoriarpm4_12, rpm4_12);
       delay(200); 
       while (digitalRead(Button1) == LOW && rpm4_12 > 0) {
       rpm4_12--; q++;    
       lcd.setCursor(9,1); lcd.print(rpm4_12); lcd.print(F("  "));
       delay(300); if (digitalRead(Button1) == HIGH){EEPROM.put(memoriarpm4_12, rpm4_12); q=0; break;}
       if (q == 10) {
       while (digitalRead(Button1) == LOW && rpm4_12 > 0) {
       rpm4_12--;
       lcd.setCursor(9,1); lcd.print(rpm4_12); lcd.print(F("  "));
       delay(100); if (digitalRead(Button1) == HIGH) {EEPROM.put(memoriarpm4_12, rpm4_12); q=0; break;}
       }}}}
       else if (tela==181 && way4_12==0) {way4_12=1; EEPROM.put(memoriaway4_12, way4_12);}
      
       delay(30);
       } LA_botao_MENOS = L_botao_MENOS;



// === ACTION OF THE BUTTON ENTER === // 
  L_botao_ENTER = digitalRead(Button3);
  if (!L_botao_ENTER && LA_botao_ENTER) {
            if (tela==1){tela=2;}
       else if (tela==2){tela=3;}
       else if (tela==3){tela=4;}
       else if (tela==4){tela=5;}
       else if (tela==5){tela=6;}
       else if (tela==6){tela=7;}
       else if (tela==7){tela=8;}
       else if (tela==8){tela=9;}
       else if (tela==9){tela=10;}
       else if (tela==10){tela=11;}
       else if (tela==11){tela=12;}
       else if (tela==12){tela=13;}
       else if (tela==13){tela=14;}
       else if (tela==14){tela=15;}
       else if (tela==15){tela=16;}
       else if (tela==16){tela=17;}
       else if (tela==17){tela=18;}
       else if (tela==18){tela=19;}
       else if (tela==19){tela=20;}
       else if (tela==20){tela=21;}
       else if (tela==21){tela=22;}
       else if (tela==22){tela=23;}
       else if (tela==23){tela=24;}
       else if (tela==24){tela=25;}
       else if (tela==25){tela=26;}
       else if (tela==26){tela=27;}
       else if (tela==27){tela=28;}
       else if (tela==28){tela=29;}
       else if (tela==29){tela=30;}
       else if (tela==30){tela=31;}
       else if (tela==31){tela=32;}
       else if (tela==32){tela=33;}
       else if (tela==33){tela=34;}
       else if (tela==34){tela=35;}
       else if (tela==35){tela=36;}
       else if (tela==36){tela=37;}
       else if (tela==37){tela=38;}
       else if (tela==38){tela=39;}
       else if (tela==39){tela=40;}
       else if (tela==40){tela=41;}
       else if (tela==41){tela=42;}
       else if (tela==42){tela=43;}
       else if (tela==43){tela=44;}
       else if (tela==44){tela=45;}
       else if (tela==45){tela=46;}
       else if (tela==46){tela=47;}
       else if (tela==47){tela=48;}
       else if (tela==48){tela=49;}
       else if (tela==49){tela=50;}
       else if (tela==50){tela=51;}
       else if (tela==51){tela=52;}
       else if (tela==52){tela=53;}
       else if (tela==53){tela=54;}
       else if (tela==54){tela=55;}
       else if (tela==55){tela=56;}
       else if (tela==56){tela=57;}
       else if (tela==57){tela=58;}
       else if (tela==58){tela=59;}
       else if (tela==59){tela=60;}
       else if (tela==60){tela=61;}
       else if (tela==61){tela=62;}
       else if (tela==62){tela=63;}
       else if (tela==63){tela=64;}
       else if (tela==64){tela=65;}
       else if (tela==65){tela=66;}
       else if (tela==66){tela=67;}
       else if (tela==67){tela=68;}
       else if (tela==68){tela=69;}
       else if (tela==69){tela=70;}
       else if (tela==70){tela=71;}
       else if (tela==71){tela=72;}
       else if (tela==72){tela=73;}
       else if (tela==73){tela=74;}
       else if (tela==74){tela=75;}
       else if (tela==75){tela=76;}
       else if (tela==76){tela=77;}
       else if (tela==77){tela=78;}
       else if (tela==78){tela=79;}
       else if (tela==79){tela=80;}
       else if (tela==80){tela=81;}
       else if (tela==81){tela=82;}
       else if (tela==82){tela=83;}
       else if (tela==83){tela=84;}
       else if (tela==84){tela=85;}
       else if (tela==85){tela=86;}
       else if (tela==86){tela=87;}
       else if (tela==87){tela=88;}
       else if (tela==88){tela=89;}
       else if (tela==89){tela=90;}
       else if (tela==90){tela=91;}
       else if (tela==91){tela=92;}
       else if (tela==92){tela=93;}
       else if (tela==93){tela=94;}
       else if (tela==94){tela=95;}
       else if (tela==95){tela=96;}
       else if (tela==96){tela=97;}
       else if (tela==97){tela=98;}
       else if (tela==98){tela=99;}
       else if (tela==99){tela=100;}
       else if (tela==100){tela=101;}
       else if (tela==101){tela=102;}
       else if (tela==102){tela=103;}
       else if (tela==103){tela=104;}
       else if (tela==104){tela=105;}
       else if (tela==105){tela=106;}
       else if (tela==106){tela=107;}
       else if (tela==107){tela=108;}
       else if (tela==108){tela=109;}
       else if (tela==109){tela=110;}
       else if (tela==110){tela=111;}
       else if (tela==111){tela=112;}
       else if (tela==112){tela=113;}
       else if (tela==113){tela=114;}
       else if (tela==114){tela=115;}
       else if (tela==115){tela=116;}
       else if (tela==116){tela=117;}
       else if (tela==117){tela=118;}
       else if (tela==118){tela=119;}
       else if (tela==119){tela=120;}
       else if (tela==120){tela=121;}
       else if (tela==121){tela=122;}
       else if (tela==122){tela=123;}
       else if (tela==123){tela=124;}
       else if (tela==124){tela=125;}
       else if (tela==125){tela=126;}
       else if (tela==126){tela=127;}
       else if (tela==127){tela=128;}
       else if (tela==128){tela=129;}
       else if (tela==129){tela=130;}
       else if (tela==130){tela=131;}
       else if (tela==131){tela=132;}
       else if (tela==132){tela=133;}
       else if (tela==133){tela=134;}
       else if (tela==134){tela=135;}
       else if (tela==135){tela=136;}
       else if (tela==136){tela=137;}
       else if (tela==137){tela=138;}
       else if (tela==138){tela=139;}
       else if (tela==139){tela=140;}
       else if (tela==140){tela=141;}
       else if (tela==141){tela=142;}
       else if (tela==142){tela=143;}
       else if (tela==143){tela=144;}
       else if (tela==144){tela=145;}
       else if (tela==145){tela=146;}
       else if (tela==146){tela=147;}
       else if (tela==147){tela=148;}
       else if (tela==148){tela=149;}
       else if (tela==149){tela=150;}
       else if (tela==150){tela=151;}
       else if (tela==151){tela=152;}
       else if (tela==152){tela=153;}
       else if (tela==153){tela=154;}
       else if (tela==154){tela=155;}
       else if (tela==155){tela=156;}
       else if (tela==156){tela=157;}
       else if (tela==157){tela=158;}
       else if (tela==158){tela=159;}
       else if (tela==159){tela=160;}
       else if (tela==160){tela=161;}
       else if (tela==161){tela=162;}
       else if (tela==162){tela=163;}
       else if (tela==163){tela=164;}
       else if (tela==164){tela=165;}
       else if (tela==165){tela=166;}
       else if (tela==166){tela=167;}
       else if (tela==167){tela=168;}
       else if (tela==168){tela=169;}
       else if (tela==169){tela=170;}
       else if (tela==170){tela=171;}
       else if (tela==171){tela=172;}
       else if (tela==172){tela=173;}
       else if (tela==173){tela=174;}
       else if (tela==174){tela=175;}
       else if (tela==175){tela=176;}
       else if (tela==176){tela=177;}
       else if (tela==177){tela=178;}
       else if (tela==178){tela=179;}
       else if (tela==179){tela=180;}
       else if (tela==180){tela=181;}
       else if (tela==181){tela=1; lcd.clear();}
    
       delay(30);
       } LA_botao_ENTER = L_botao_ENTER;
  
  
}
