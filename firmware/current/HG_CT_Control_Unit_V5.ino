//      CREATED BY GILBERTO COELHO - MARCH OF 2026 - UPDATED IN MAY 2026

#include <Wire.h>
#include <EEPROM.h>
#include "esp_system.h"
#include <WiFi.h>
#include <WebServer.h>
#include <DNSServer.h>
#include <LiquidCrystal_I2C.h>
#include <ESP32Servo.h>
LiquidCrystal_I2C lcd(0x27,16,2);
Servo servo;

const char* ssid = "STEP MODULE WIFI";
const char* password = "";

IPAddress local_IP(192, 168, 4, 1);
IPAddress gateway(192, 168, 4, 1);
IPAddress subnet(255, 255, 255, 0);

WebServer server(80); 
DNSServer dnsServer;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

byte program = 1;

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

byte beep1 = 0;
byte beep2 = 0;
byte beep3 = 0;
byte beep4 = 0;
byte beep5 = 0;
byte beep6 = 0;
byte beep7 = 0;
byte beep8 = 0;
byte beep9 = 0;
byte beep10 = 0;
byte beep11 = 0;
byte beep12 = 0;

//RELAYS - "0" means OFF; "1" means ON
byte relay1_1 = 0;  
byte relay2_1 = 0;  
byte relay3_1 = 0;  
byte relay4_1 = 0;
byte relay5_1 = 0;

byte relay1_2 = 0;  
byte relay2_2 = 0;  
byte relay3_2 = 0;  
byte relay4_2 = 0;
byte relay5_2 = 0;

byte relay1_3 = 0;  
byte relay2_3 = 0;  
byte relay3_3 = 0;  
byte relay4_3 = 0;
byte relay5_3 = 0;

byte relay1_4 = 0;  
byte relay2_4 = 0;  
byte relay3_4 = 0;  
byte relay4_4 = 0;
byte relay5_4 = 0;

byte relay1_5 = 0;  
byte relay2_5 = 0;  
byte relay3_5 = 0;  
byte relay4_5 = 0;
byte relay5_5 = 0;

byte relay1_6 = 0;  
byte relay2_6 = 0;  
byte relay3_6 = 0;  
byte relay4_6 = 0;
byte relay5_6 = 0;

byte relay1_7 = 0;  
byte relay2_7 = 0;  
byte relay3_7 = 0;  
byte relay4_7 = 0;
byte relay5_7 = 0;

byte relay1_8 = 0;  
byte relay2_8 = 0;  
byte relay3_8 = 0;  
byte relay4_8 = 0;
byte relay5_8 = 0;

byte relay1_9 = 0;  
byte relay2_9 = 0;  
byte relay3_9 = 0;  
byte relay4_9 = 0;
byte relay5_9 = 0;

byte relay1_10 = 0;  
byte relay2_10 = 0;  
byte relay3_10 = 0;  
byte relay4_10 = 0;
byte relay5_10 = 0;

byte relay1_11 = 0;  
byte relay2_11 = 0;  
byte relay3_11 = 0;  
byte relay4_11 = 0;
byte relay5_11 = 0;

byte relay1_12 = 0;  
byte relay2_12 = 0;  
byte relay3_12 = 0;  
byte relay4_12 = 0;
byte relay5_12 = 0;

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

int memoriaprogram = 0; 

// PROGRAM 1 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int memoria1time1 = 1;  
int memoria1time2 = 2;  
int memoria1time3 = 3;  
int memoria1time4 = 4;  
int memoria1time5 = 5;  
int memoria1time6 = 6;  
int memoria1time7 = 7;  
int memoria1time8 = 8;  
int memoria1time9 = 9;  
int memoria1time10 = 10;  
int memoria1time11 = 11;  
int memoria1time12 = 12;

int memoria1relay1_1 = 13;  
int memoria1relay2_1 = 14;  
int memoria1relay3_1 = 15;  
int memoria1relay4_1 = 16;
int memoria1relay5_1 = 17;

int memoria1relay1_2 = 18;  
int memoria1relay2_2 = 19;  
int memoria1relay3_2 = 20;  
int memoria1relay4_2 = 21;
int memoria1relay5_2 = 22;

int memoria1relay1_3 = 23;  
int memoria1relay2_3 = 24;  
int memoria1relay3_3 = 25;  
int memoria1relay4_3 = 26;
int memoria1relay5_3 = 27;

int memoria1relay1_4 = 28;  
int memoria1relay2_4 = 29;  
int memoria1relay3_4 = 30;  
int memoria1relay4_4 = 31;
int memoria1relay5_4 = 32;

int memoria1relay1_5 = 33;  
int memoria1relay2_5 = 34;  
int memoria1relay3_5 = 35;  
int memoria1relay4_5 = 36;
int memoria1relay5_5 = 37;

int memoria1relay1_6 = 38;  
int memoria1relay2_6 = 39;  
int memoria1relay3_6 = 40;  
int memoria1relay4_6 = 41;
int memoria1relay5_6 = 42;

int memoria1relay1_7 = 43;  
int memoria1relay2_7 = 44;  
int memoria1relay3_7 = 45;  
int memoria1relay4_7 = 46;
int memoria1relay5_7 = 47;

int memoria1relay1_8 = 48;  
int memoria1relay2_8 = 49;  
int memoria1relay3_8 = 50;  
int memoria1relay4_8 = 51;
int memoria1relay5_8 = 52;

int memoria1relay1_9 = 53;  
int memoria1relay2_9 = 54;  
int memoria1relay3_9 = 55;  
int memoria1relay4_9 = 56;
int memoria1relay5_9 = 57;

int memoria1relay1_10 = 58;  
int memoria1relay2_10 = 59;  
int memoria1relay3_10 = 60;  
int memoria1relay4_10 = 61;
int memoria1relay5_10 = 62;

int memoria1relay1_11 = 63;  
int memoria1relay2_11 = 64;  
int memoria1relay3_11 = 65;  
int memoria1relay4_11 = 66;
int memoria1relay5_11 = 67;

int memoria1relay1_12 = 68;  
int memoria1relay2_12 = 69;  
int memoria1relay3_12 = 70;  
int memoria1relay4_12 = 71;
int memoria1relay5_12 = 72;

////////////////////////////////////////////////////////////////////

int memoria1way1_1 = 73;  
int memoria1way2_1 = 74;  
int memoria1way3_1 = 75; 
int memoria1way4_1 = 76;

int memoria1way1_2 = 77;  
int memoria1way2_2 = 78;  
int memoria1way3_2 = 79;  
int memoria1way4_2 = 80;

int memoria1way1_3 = 81;  
int memoria1way2_3 = 82;  
int memoria1way3_3 = 83;  
int memoria1way4_3 = 84;

int memoria1way1_4 = 85;  
int memoria1way2_4 = 86;  
int memoria1way3_4 = 87;  
int memoria1way4_4 = 88;

int memoria1way1_5 = 89;  
int memoria1way2_5 = 90;  
int memoria1way3_5 = 91;  
int memoria1way4_5 = 92;

int memoria1way1_6 = 93;  
int memoria1way2_6 = 94;  
int memoria1way3_6 = 95;  
int memoria1way4_6 = 96;

int memoria1way1_7 = 97;  
int memoria1way2_7 = 98;  
int memoria1way3_7 = 99;  
int memoria1way4_7 = 100;

int memoria1way1_8 = 101;  
int memoria1way2_8 = 102;  
int memoria1way3_8 = 103;  
int memoria1way4_8 = 104;

int memoria1way1_9 = 105;  
int memoria1way2_9 = 106;  
int memoria1way3_9 = 107;  
int memoria1way4_9 = 108;

int memoria1way1_10 = 109;  
int memoria1way2_10 = 110;  
int memoria1way3_10 = 111;  
int memoria1way4_10 = 112;

int memoria1way1_11 = 113;  
int memoria1way2_11 = 114;  
int memoria1way3_11 = 115;  
int memoria1way4_11 = 116;

int memoria1way1_12 = 117;  
int memoria1way2_12 = 118;  
int memoria1way3_12 = 119;  
int memoria1way4_12 = 120;

///////////////////////////////////////////////

int memoria1rpm1_1 = 121;  
int memoria1rpm2_1 = 122;  
int memoria1rpm3_1 = 123;  
int memoria1rpm4_1 = 124;
 
int memoria1rpm1_2 = 125;  
int memoria1rpm2_2 = 126;  
int memoria1rpm3_2 = 127;  
int memoria1rpm4_2 = 128;

int memoria1rpm1_3 = 129;  
int memoria1rpm2_3 = 130;  
int memoria1rpm3_3 = 131;  
int memoria1rpm4_3 = 132;

int memoria1rpm1_4 = 133;  
int memoria1rpm2_4 = 134;  
int memoria1rpm3_4 = 135;  
int memoria1rpm4_4 = 136;

int memoria1rpm1_5 = 137;  
int memoria1rpm2_5 = 138;  
int memoria1rpm3_5 = 139;  
int memoria1rpm4_5 = 140;

int memoria1rpm1_6 = 141;  
int memoria1rpm2_6 = 142;  
int memoria1rpm3_6 = 143;  
int memoria1rpm4_6 = 144;

int memoria1rpm1_7 = 145; 
int memoria1rpm2_7 = 146;  
int memoria1rpm3_7 = 147;  
int memoria1rpm4_7 = 148;

int memoria1rpm1_8 = 149;  
int memoria1rpm2_8 = 150;  
int memoria1rpm3_8 = 151;  
int memoria1rpm4_8 = 152;

int memoria1rpm1_9 = 153;  
int memoria1rpm2_9 = 154;  
int memoria1rpm3_9 = 155;  
int memoria1rpm4_9 = 156;

int memoria1rpm1_10 = 157;  
int memoria1rpm2_10 = 158;  
int memoria1rpm3_10 = 159;  
int memoria1rpm4_10 = 160;

int memoria1rpm1_11 = 161;  
int memoria1rpm2_11 = 162;  
int memoria1rpm3_11 = 163;  
int memoria1rpm4_11 = 164;

int memoria1rpm1_12 = 165;  
int memoria1rpm2_12 = 166;  
int memoria1rpm3_12 = 167;  
int memoria1rpm4_12 = 168;



// PROGRAM 2 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int memoria2time1 = 169;  
int memoria2time2 = 170;  
int memoria2time3 = 171;  
int memoria2time4 = 172;  
int memoria2time5 = 173;  
int memoria2time6 = 174;  
int memoria2time7 = 175;  
int memoria2time8 = 176;  
int memoria2time9 = 177;  
int memoria2time10 = 178;  
int memoria2time11 = 179;  
int memoria2time12 = 180;

int memoria2relay1_1 = 181;  
int memoria2relay2_1 = 182;  
int memoria2relay3_1 = 183;  
int memoria2relay4_1 = 184;
int memoria2relay5_1 = 185;

int memoria2relay1_2 = 186;  
int memoria2relay2_2 = 187;  
int memoria2relay3_2 = 188;  
int memoria2relay4_2 = 189;
int memoria2relay5_2 = 190;

int memoria2relay1_3 = 191;  
int memoria2relay2_3 = 192;  
int memoria2relay3_3 = 193;  
int memoria2relay4_3 = 194;
int memoria2relay5_3 = 195;

int memoria2relay1_4 = 196;  
int memoria2relay2_4 = 197;  
int memoria2relay3_4 = 198;  
int memoria2relay4_4 = 199;
int memoria2relay5_4 = 200;

int memoria2relay1_5 = 201;  
int memoria2relay2_5 = 202;  
int memoria2relay3_5 = 203;  
int memoria2relay4_5 = 204;
int memoria2relay5_5 = 205;

int memoria2relay1_6 = 206;  
int memoria2relay2_6 = 207;  
int memoria2relay3_6 = 208;  
int memoria2relay4_6 = 209;
int memoria2relay5_6 = 210;

int memoria2relay1_7 = 211;  
int memoria2relay2_7 = 212;  
int memoria2relay3_7 = 213;  
int memoria2relay4_7 = 214;
int memoria2relay5_7 = 215;

int memoria2relay1_8 = 216;  
int memoria2relay2_8 = 217;  
int memoria2relay3_8 = 218;  
int memoria2relay4_8 = 219;
int memoria2relay5_8 = 220;

int memoria2relay1_9 = 221;  
int memoria2relay2_9 = 222;  
int memoria2relay3_9 = 223;  
int memoria2relay4_9 = 224;
int memoria2relay5_9 = 225;

int memoria2relay1_10 = 226;  
int memoria2relay2_10 = 227;  
int memoria2relay3_10 = 228;  
int memoria2relay4_10 = 229;
int memoria2relay5_10 = 230;

int memoria2relay1_11 = 231;  
int memoria2relay2_11 = 232;  
int memoria2relay3_11 = 233;  
int memoria2relay4_11 = 234;
int memoria2relay5_11 = 235;

int memoria2relay1_12 = 236;  
int memoria2relay2_12 = 237;  
int memoria2relay3_12 = 238;  
int memoria2relay4_12 = 239;
int memoria2relay5_12 = 240;

////////////////////////////////////////////////////////////////////

int memoria2way1_1 = 241;  
int memoria2way2_1 = 242;  
int memoria2way3_1 = 243; 
int memoria2way4_1 = 244;

int memoria2way1_2 = 245;  
int memoria2way2_2 = 246;  
int memoria2way3_2 = 247;  
int memoria2way4_2 = 248;

int memoria2way1_3 = 249;  
int memoria2way2_3 = 250;  
int memoria2way3_3 = 251;  
int memoria2way4_3 = 252;

int memoria2way1_4 = 253;  
int memoria2way2_4 = 254;  
int memoria2way3_4 = 255;  
int memoria2way4_4 = 256;

int memoria2way1_5 = 257;  
int memoria2way2_5 = 258;  
int memoria2way3_5 = 259;  
int memoria2way4_5 = 260;

int memoria2way1_6 = 261;  
int memoria2way2_6 = 262;  
int memoria2way3_6 = 263;  
int memoria2way4_6 = 264;

int memoria2way1_7 = 265;  
int memoria2way2_7 = 266;  
int memoria2way3_7 = 267;  
int memoria2way4_7 = 268;

int memoria2way1_8 = 269;  
int memoria2way2_8 = 270;  
int memoria2way3_8 = 271;  
int memoria2way4_8 = 272;

int memoria2way1_9 = 273;  
int memoria2way2_9 = 274;  
int memoria2way3_9 = 275;  
int memoria2way4_9 = 276;

int memoria2way1_10 = 277;  
int memoria2way2_10 = 278;  
int memoria2way3_10 = 279;  
int memoria2way4_10 = 280;

int memoria2way1_11 = 281;  
int memoria2way2_11 = 282;  
int memoria2way3_11 = 283;  
int memoria2way4_11 = 284;

int memoria2way1_12 = 285;  
int memoria2way2_12 = 286;  
int memoria2way3_12 = 287;  
int memoria2way4_12 = 288;

///////////////////////////////////////////////

int memoria2rpm1_1 = 289;  
int memoria2rpm2_1 = 290;  
int memoria2rpm3_1 = 291;  
int memoria2rpm4_1 = 292;
 
int memoria2rpm1_2 = 293;  
int memoria2rpm2_2 = 294;  
int memoria2rpm3_2 = 295;  
int memoria2rpm4_2 = 296;

int memoria2rpm1_3 = 297;  
int memoria2rpm2_3 = 298;  
int memoria2rpm3_3 = 299;  
int memoria2rpm4_3 = 300;

int memoria2rpm1_4 = 301;  
int memoria2rpm2_4 = 302;  
int memoria2rpm3_4 = 303;  
int memoria2rpm4_4 = 304;

int memoria2rpm1_5 = 305;  
int memoria2rpm2_5 = 306;  
int memoria2rpm3_5 = 307;  
int memoria2rpm4_5 = 308;

int memoria2rpm1_6 = 309;  
int memoria2rpm2_6 = 310;  
int memoria2rpm3_6 = 311;  
int memoria2rpm4_6 = 312;

int memoria2rpm1_7 = 313; 
int memoria2rpm2_7 = 314;  
int memoria2rpm3_7 = 315;  
int memoria2rpm4_7 = 316;

int memoria2rpm1_8 = 317;  
int memoria2rpm2_8 = 318;  
int memoria2rpm3_8 = 319;  
int memoria2rpm4_8 = 320;

int memoria2rpm1_9 = 321;  
int memoria2rpm2_9 = 322;  
int memoria2rpm3_9 = 323;  
int memoria2rpm4_9 = 324;

int memoria2rpm1_10 = 325;  
int memoria2rpm2_10 = 326;  
int memoria2rpm3_10 = 327;  
int memoria2rpm4_10 = 328;

int memoria2rpm1_11 = 329;  
int memoria2rpm2_11 = 330;  
int memoria2rpm3_11 = 331;  
int memoria2rpm4_11 = 332;

int memoria2rpm1_12 = 333;  
int memoria2rpm2_12 = 334;  
int memoria2rpm3_12 = 335;  
int memoria2rpm4_12 = 336;




// PROGRAM 3 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int memoria3time1 = 337;  
int memoria3time2 = 338;  
int memoria3time3 = 339;  
int memoria3time4 = 340;  
int memoria3time5 = 341;  
int memoria3time6 = 342;  
int memoria3time7 = 343;  
int memoria3time8 = 344;  
int memoria3time9 = 345;  
int memoria3time10 = 346;  
int memoria3time11 = 347;  
int memoria3time12 = 348;

int memoria3relay1_1 = 349;  
int memoria3relay2_1 = 350;  
int memoria3relay3_1 = 351;  
int memoria3relay4_1 = 352;
int memoria3relay5_1 = 353;

int memoria3relay1_2 = 354;  
int memoria3relay2_2 = 355;  
int memoria3relay3_2 = 356;  
int memoria3relay4_2 = 357;
int memoria3relay5_2 = 358;

int memoria3relay1_3 = 359;  
int memoria3relay2_3 = 360;  
int memoria3relay3_3 = 361;  
int memoria3relay4_3 = 362;
int memoria3relay5_3 = 363;

int memoria3relay1_4 = 364;  
int memoria3relay2_4 = 365;  
int memoria3relay3_4 = 366;  
int memoria3relay4_4 = 367;
int memoria3relay5_4 = 368;

int memoria3relay1_5 = 369;  
int memoria3relay2_5 = 370;  
int memoria3relay3_5 = 371;  
int memoria3relay4_5 = 372;
int memoria3relay5_5 = 373;

int memoria3relay1_6 = 374;  
int memoria3relay2_6 = 375;  
int memoria3relay3_6 = 376;  
int memoria3relay4_6 = 377;
int memoria3relay5_6 = 378;

int memoria3relay1_7 = 379;  
int memoria3relay2_7 = 380;  
int memoria3relay3_7 = 381;  
int memoria3relay4_7 = 382;
int memoria3relay5_7 = 383;

int memoria3relay1_8 = 384;  
int memoria3relay2_8 = 385;  
int memoria3relay3_8 = 386;  
int memoria3relay4_8 = 387;
int memoria3relay5_8 = 388;

int memoria3relay1_9 = 389;  
int memoria3relay2_9 = 390;  
int memoria3relay3_9 = 391;  
int memoria3relay4_9 = 392;
int memoria3relay5_9 = 393;

int memoria3relay1_10 = 394;  
int memoria3relay2_10 = 395;  
int memoria3relay3_10 = 396;  
int memoria3relay4_10 = 397;
int memoria3relay5_10 = 398;

int memoria3relay1_11 = 399;  
int memoria3relay2_11 = 400;  
int memoria3relay3_11 = 401;  
int memoria3relay4_11 = 402;
int memoria3relay5_11 = 403;

int memoria3relay1_12 = 404;  
int memoria3relay2_12 = 405;  
int memoria3relay3_12 = 406;  
int memoria3relay4_12 = 407;
int memoria3relay5_12 = 408;

////////////////////////////////////////////////////////////////////

int memoria3way1_1 = 409;  
int memoria3way2_1 = 410;  
int memoria3way3_1 = 411; 
int memoria3way4_1 = 412;

int memoria3way1_2 = 413;  
int memoria3way2_2 = 414;  
int memoria3way3_2 = 415;  
int memoria3way4_2 = 416;

int memoria3way1_3 = 417;  
int memoria3way2_3 = 418;  
int memoria3way3_3 = 419;  
int memoria3way4_3 = 420;

int memoria3way1_4 = 421;  
int memoria3way2_4 = 422;  
int memoria3way3_4 = 423;  
int memoria3way4_4 = 424;

int memoria3way1_5 = 425;  
int memoria3way2_5 = 426;  
int memoria3way3_5 = 427;  
int memoria3way4_5 = 428;

int memoria3way1_6 = 429;  
int memoria3way2_6 = 430;  
int memoria3way3_6 = 431;  
int memoria3way4_6 = 432;

int memoria3way1_7 = 433;  
int memoria3way2_7 = 434;  
int memoria3way3_7 = 435;  
int memoria3way4_7 = 436;

int memoria3way1_8 = 437;  
int memoria3way2_8 = 438;  
int memoria3way3_8 = 439;  
int memoria3way4_8 = 440;

int memoria3way1_9 = 441;  
int memoria3way2_9 = 442;  
int memoria3way3_9 = 443;  
int memoria3way4_9 = 444;

int memoria3way1_10 = 445;  
int memoria3way2_10 = 446;  
int memoria3way3_10 = 447;  
int memoria3way4_10 = 448;

int memoria3way1_11 = 449;  
int memoria3way2_11 = 450;  
int memoria3way3_11 = 451;  
int memoria3way4_11 = 452;

int memoria3way1_12 = 453;  
int memoria3way2_12 = 454;  
int memoria3way3_12 = 455;  
int memoria3way4_12 = 456;

///////////////////////////////////////////////

int memoria3rpm1_1 = 457;  
int memoria3rpm2_1 = 458;  
int memoria3rpm3_1 = 459;  
int memoria3rpm4_1 = 460;
 
int memoria3rpm1_2 = 461;  
int memoria3rpm2_2 = 462;  
int memoria3rpm3_2 = 463;  
int memoria3rpm4_2 = 464;

int memoria3rpm1_3 = 465;  
int memoria3rpm2_3 = 466;  
int memoria3rpm3_3 = 467;  
int memoria3rpm4_3 = 468;

int memoria3rpm1_4 = 469;  
int memoria3rpm2_4 = 470;  
int memoria3rpm3_4 = 471;  
int memoria3rpm4_4 = 472;

int memoria3rpm1_5 = 473;  
int memoria3rpm2_5 = 474;  
int memoria3rpm3_5 = 475;  
int memoria3rpm4_5 = 476;

int memoria3rpm1_6 = 477;  
int memoria3rpm2_6 = 478;  
int memoria3rpm3_6 = 479;  
int memoria3rpm4_6 = 480;

int memoria3rpm1_7 = 481; 
int memoria3rpm2_7 = 482;  
int memoria3rpm3_7 = 483;  
int memoria3rpm4_7 = 484;

int memoria3rpm1_8 = 485;  
int memoria3rpm2_8 = 486;  
int memoria3rpm3_8 = 487;  
int memoria3rpm4_8 = 488;

int memoria3rpm1_9 = 489;  
int memoria3rpm2_9 = 490;  
int memoria3rpm3_9 = 491;  
int memoria3rpm4_9 = 492;

int memoria3rpm1_10 = 493;  
int memoria3rpm2_10 = 494;  
int memoria3rpm3_10 = 495;  
int memoria3rpm4_10 = 496;

int memoria3rpm1_11 = 497;  
int memoria3rpm2_11 = 498;  
int memoria3rpm3_11 = 499;  
int memoria3rpm4_11 = 500;

int memoria3rpm1_12 = 501;  
int memoria3rpm2_12 = 502;  
int memoria3rpm3_12 = 503;  
int memoria3rpm4_12 = 504;

///////////////////////////////////////////////

int memoria1beep1 = 988;  
int memoria1beep2 = 989; 
int memoria1beep3 = 990; 
int memoria1beep4 = 991; 
int memoria1beep5 = 992; 
int memoria1beep6 = 993; 
int memoria1beep7 = 994; 
int memoria1beep8 = 995; 
int memoria1beep9 = 996; 
int memoria1beep10 = 997; 
int memoria1beep11 = 998; 
int memoria1beep12 = 999; 

int memoria2beep1 = 1000;  
int memoria2beep2 = 1001; 
int memoria2beep3 = 1002; 
int memoria2beep4 = 1003; 
int memoria2beep5 = 1004; 
int memoria2beep6 = 1005; 
int memoria2beep7 = 1006; 
int memoria2beep8 = 1007; 
int memoria2beep9 = 1008; 
int memoria2beep10 = 1009; 
int memoria2beep11 = 1010; 
int memoria2beep12 = 1011; 

int memoria3beep1 = 1012;  
int memoria3beep2 = 1013; 
int memoria3beep3 = 1014; 
int memoria3beep4 = 1015; 
int memoria3beep5 = 1016; 
int memoria3beep6 = 1017; 
int memoria3beep7 = 1018; 
int memoria3beep8 = 1019; 
int memoria3beep9 = 1020; 
int memoria3beep10 = 1021; 
int memoria3beep11 = 1022; 
int memoria3beep12 = 1023; 



////////////////////////////////////////////////

const int buttonStart = 15;
const int buttonCancel = 4;
const int buttonMenu = 16;
const int buttonBack = 17;

const int buttonLedRead = 5;
const int buttonLedValve = 18;
const int buttonLedHeat = 19;

const int relayRead = 33;
const int relayValve = 14;
const int relayHeat = 27;
const int relayExt1 = 26;
const int relayExt2 = 25;


const int buzzer = 13;

int pinServo = 23;

/////////////////////////////////////////////////

int statebuttonStart = 0;
int statebuttonCancel = 0;
int statebuttonMenu = 0;
int statebuttonBack = 0;

int cont = 0;

bool L_botao_MAIS,  LA_botao_MAIS,  L_botao_MENOS,  LA_botao_MENOS  = 1;               
bool L_botao_ENTER, LA_botao_ENTER, L_botao_VOLTAR, LA_botao_VOLTAR = 1;

int  tela = 1;

byte ajuste = 0;

bool webStart = 0;
bool webSave = 0;

//int RESET = 9;

char *x = {"0"};
char *xx = {"00"};
char *xxx = {"000"};

int q = 0;
int z = 0;
byte parar2 = 0;

String programNames[3]; // nomes dos programas (1,2,3)

int lastProgram = -1;  // variável global

unsigned long timeDetach = 0;

byte positionOne = 8;
byte positionTwo = 103;



void setup() { 
    
    Wire.begin(21, 22);
    lcd.begin();
    lcd.backlight();

    Serial.begin(9600); delay(200);
    Serial.print("1~1"); Serial.print('\r'); delay(200);
    Serial.setTimeout(1000); delay(200);
    
    pinMode(relayRead, OUTPUT); //Relay READ
    pinMode(relayValve, OUTPUT); //Relay VALVE
    pinMode(relayHeat, OUTPUT); //Relay HEAT
    pinMode(relayExt1, OUTPUT); //Relay ext 1    
    pinMode(relayExt2, OUTPUT); //Relay ext 2    
    pinMode(buzzer, OUTPUT); //Buzzer

    pinMode(buttonLedRead, INPUT_PULLUP); //button READ
    pinMode(buttonLedValve, INPUT_PULLUP); //button VALVE
    pinMode(buttonLedHeat, INPUT_PULLUP); //button HEAT
   
    pinMode(buttonStart, INPUT_PULLUP);
    pinMode(buttonCancel, INPUT_PULLUP);
    pinMode(buttonMenu, INPUT_PULLUP);
    pinMode(buttonBack, INPUT_PULLUP);

    digitalWrite(relayRead, HIGH); //Relay READ
    digitalWrite(relayValve, HIGH); //Relay VALVE
    digitalWrite(relayHeat, HIGH); //Relay HEAT
    digitalWrite(relayExt1, HIGH); //Relay ext 1   
    digitalWrite(relayExt2, HIGH); //Relay ext 2  
    digitalWrite(buzzer, LOW);  

    EEPROM.begin(1024);
    loadProgramNames();  // carrega os nomes salvos
  
    program = EEPROM.read(memoriaprogram);

    if (program == 1) {
    
    time1 = EEPROM.read(memoria1time1);    
    time2 = EEPROM.read(memoria1time2);
    time3 = EEPROM.read(memoria1time3);
    time4 = EEPROM.read(memoria1time4);
    time5 = EEPROM.read(memoria1time5);
    time6 = EEPROM.read(memoria1time6);    
    time7 = EEPROM.read(memoria1time7);
    time8 = EEPROM.read(memoria1time8);
    time9 = EEPROM.read(memoria1time9);
    time10 = EEPROM.read(memoria1time10);
    time11 = EEPROM.read(memoria1time11);    
    time12 = EEPROM.read(memoria1time12);

    beep1 = EEPROM.read(memoria1beep1);
    beep2 = EEPROM.read(memoria1beep2);
    beep3 = EEPROM.read(memoria1beep3);
    beep4 = EEPROM.read(memoria1beep4);
    beep5 = EEPROM.read(memoria1beep5);
    beep6 = EEPROM.read(memoria1beep6);
    beep7 = EEPROM.read(memoria1beep7);
    beep8 = EEPROM.read(memoria1beep8);
    beep9 = EEPROM.read(memoria1beep9);
    beep10 = EEPROM.read(memoria1beep10);
    beep11 = EEPROM.read(memoria1beep11);
    beep12 = EEPROM.read(memoria1beep12);
         
    relay1_1 = EEPROM.read(memoria1relay1_1);  
    relay2_1 = EEPROM.read(memoria1relay2_1);
    relay3_1 = EEPROM.read(memoria1relay3_1);  
    relay4_1 = EEPROM.read(memoria1relay4_1);
    relay5_1 = EEPROM.read(memoria1relay5_1);
    
    relay1_2 = EEPROM.read(memoria1relay1_2);  
    relay2_2 = EEPROM.read(memoria1relay2_2);  
    relay3_2 = EEPROM.read(memoria1relay3_2);  
    relay4_2 = EEPROM.read(memoria1relay4_2);
    relay5_2 = EEPROM.read(memoria1relay5_2);
    
    relay1_3 = EEPROM.read(memoria1relay1_3);  
    relay2_3 = EEPROM.read(memoria1relay2_3);  
    relay3_3 = EEPROM.read(memoria1relay3_3);  
    relay4_3 = EEPROM.read(memoria1relay4_3);
    relay5_3 = EEPROM.read(memoria1relay5_3);
    
    relay1_4 = EEPROM.read(memoria1relay1_4);  
    relay2_4 = EEPROM.read(memoria1relay2_4);  
    relay3_4 = EEPROM.read(memoria1relay3_4);  
    relay4_4 = EEPROM.read(memoria1relay4_4);
    relay5_4 = EEPROM.read(memoria1relay5_4);
    
    relay1_5 = EEPROM.read(memoria1relay1_5);  
    relay2_5 = EEPROM.read(memoria1relay2_5);  
    relay3_5 = EEPROM.read(memoria1relay3_5);  
    relay4_5 = EEPROM.read(memoria1relay4_5);
    relay5_5 = EEPROM.read(memoria1relay5_5);
    
    relay1_6 = EEPROM.read(memoria1relay1_6);  
    relay2_6 = EEPROM.read(memoria1relay2_6);  
    relay3_6 = EEPROM.read(memoria1relay3_6);  
    relay4_6 = EEPROM.read(memoria1relay4_6);
    relay5_6 = EEPROM.read(memoria1relay5_6);
    
    relay1_7 = EEPROM.read(memoria1relay1_7);  
    relay2_7 = EEPROM.read(memoria1relay2_7);  
    relay3_7 = EEPROM.read(memoria1relay3_7);  
    relay4_7 = EEPROM.read(memoria1relay4_7);
    relay5_7 = EEPROM.read(memoria1relay5_7);
    
    relay1_8 = EEPROM.read(memoria1relay1_8);  
    relay2_8 = EEPROM.read(memoria1relay2_8);  
    relay3_8 = EEPROM.read(memoria1relay3_8);  
    relay4_8 = EEPROM.read(memoria1relay4_8);
    relay5_8 = EEPROM.read(memoria1relay5_8);
    
    relay1_9 = EEPROM.read(memoria1relay1_9);  
    relay2_9 = EEPROM.read(memoria1relay2_9);  
    relay3_9 = EEPROM.read(memoria1relay3_9);  
    relay4_9 = EEPROM.read(memoria1relay4_9);
    relay5_9 = EEPROM.read(memoria1relay5_9);
    
    relay1_10 = EEPROM.read(memoria1relay1_10);  
    relay2_10 = EEPROM.read(memoria1relay2_10);  
    relay3_10 = EEPROM.read(memoria1relay3_10);  
    relay4_10 = EEPROM.read(memoria1relay4_10);
    relay5_10 = EEPROM.read(memoria1relay5_10);
    
    relay1_11 = EEPROM.read(memoria1relay1_11);  
    relay2_11 = EEPROM.read(memoria1relay2_11);  
    relay3_11 = EEPROM.read(memoria1relay3_11);  
    relay4_11 = EEPROM.read(memoria1relay4_11);
    relay5_11 = EEPROM.read(memoria1relay5_11);
    
    relay1_12 = EEPROM.read(memoria1relay1_12);  
    relay2_12 = EEPROM.read(memoria1relay2_12);  
    relay3_12 = EEPROM.read(memoria1relay3_12);  
    relay4_12 = EEPROM.read(memoria1relay4_12);
    relay5_12 = EEPROM.read(memoria1relay5_12);
      
    way1_1 = EEPROM.read(memoria1way1_1);  
    way2_1 = EEPROM.read(memoria1way2_1);
    way3_1 = EEPROM.read(memoria1way3_1);  
    way4_1 = EEPROM.read(memoria1way4_1);
    
    way1_2 = EEPROM.read(memoria1way1_2);  
    way2_2 = EEPROM.read(memoria1way2_2);  
    way3_2 = EEPROM.read(memoria1way3_2);  
    way4_2 = EEPROM.read(memoria1way4_2);
    
    way1_3 = EEPROM.read(memoria1way1_3);  
    way2_3 = EEPROM.read(memoria1way2_3);  
    way3_3 = EEPROM.read(memoria1way3_3);  
    way4_3 = EEPROM.read(memoria1way4_3);
    
    way1_4 = EEPROM.read(memoria1way1_4);  
    way2_4 = EEPROM.read(memoria1way2_4);  
    way3_4 = EEPROM.read(memoria1way3_4);  
    way4_4 = EEPROM.read(memoria1way4_4);
    
    way1_5 = EEPROM.read(memoria1way1_5);  
    way2_5 = EEPROM.read(memoria1way2_5);  
    way3_5 = EEPROM.read(memoria1way3_5);  
    way4_5 = EEPROM.read(memoria1way4_5);
    
    way1_6 = EEPROM.read(memoria1way1_6);  
    way2_6 = EEPROM.read(memoria1way2_6);  
    way3_6 = EEPROM.read(memoria1way3_6);  
    way4_6 = EEPROM.read(memoria1way4_6);
    
    way1_7 = EEPROM.read(memoria1way1_7);  
    way2_7 = EEPROM.read(memoria1way2_7);  
    way3_7 = EEPROM.read(memoria1way3_7);  
    way4_7 = EEPROM.read(memoria1way4_7);
    
    way1_8 = EEPROM.read(memoria1way1_8);  
    way2_8 = EEPROM.read(memoria1way2_8);  
    way3_8 = EEPROM.read(memoria1way3_8);  
    way4_8 = EEPROM.read(memoria1way4_8);
    
    way1_9 = EEPROM.read(memoria1way1_9);  
    way2_9 = EEPROM.read(memoria1way2_9);  
    way3_9 = EEPROM.read(memoria1way3_9);  
    way4_9 = EEPROM.read(memoria1way4_9);
    
    way1_10 = EEPROM.read(memoria1way1_10);  
    way2_10 = EEPROM.read(memoria1way2_10);  
    way3_10 = EEPROM.read(memoria1way3_10);  
    way4_10 = EEPROM.read(memoria1way4_10);
    
    way1_11 = EEPROM.read(memoria1way1_11);  
    way2_11 = EEPROM.read(memoria1way2_11);  
    way3_11 = EEPROM.read(memoria1way3_11);  
    way4_11 = EEPROM.read(memoria1way4_11);
    
    way1_12 = EEPROM.read(memoria1way1_12);  
    way2_12 = EEPROM.read(memoria1way2_12);  
    way3_12 = EEPROM.read(memoria1way3_12);  
    way4_12 = EEPROM.read(memoria1way4_12);
      
    rpm1_1 = EEPROM.read(memoria1rpm1_1);  
    rpm2_1 = EEPROM.read(memoria1rpm2_1);
    rpm3_1 = EEPROM.read(memoria1rpm3_1);  
    rpm4_1 = EEPROM.read(memoria1rpm4_1);
    
    rpm1_2 = EEPROM.read(memoria1rpm1_2);  
    rpm2_2 = EEPROM.read(memoria1rpm2_2);  
    rpm3_2 = EEPROM.read(memoria1rpm3_2);  
    rpm4_2 = EEPROM.read(memoria1rpm4_2);
    
    rpm1_3 = EEPROM.read(memoria1rpm1_3);  
    rpm2_3 = EEPROM.read(memoria1rpm2_3);  
    rpm3_3 = EEPROM.read(memoria1rpm3_3);  
    rpm4_3 = EEPROM.read(memoria1rpm4_3);
    
    rpm1_4 = EEPROM.read(memoria1rpm1_4);  
    rpm2_4 = EEPROM.read(memoria1rpm2_4);  
    rpm3_4 = EEPROM.read(memoria1rpm3_4);  
    rpm4_4 = EEPROM.read(memoria1rpm4_4);
    
    rpm1_5 = EEPROM.read(memoria1rpm1_5);  
    rpm2_5 = EEPROM.read(memoria1rpm2_5);  
    rpm3_5 = EEPROM.read(memoria1rpm3_5);  
    rpm4_5 = EEPROM.read(memoria1rpm4_5);
    
    rpm1_6 = EEPROM.read(memoria1rpm1_6);  
    rpm2_6 = EEPROM.read(memoria1rpm2_6);  
    rpm3_6 = EEPROM.read(memoria1rpm3_6);  
    rpm4_6 = EEPROM.read(memoria1rpm4_6);
    
    rpm1_7 = EEPROM.read(memoria1rpm1_7);  
    rpm2_7 = EEPROM.read(memoria1rpm2_7);  
    rpm3_7 = EEPROM.read(memoria1rpm3_7);  
    rpm4_7 = EEPROM.read(memoria1rpm4_7);
    
    rpm1_8 = EEPROM.read(memoria1rpm1_8);  
    rpm2_8 = EEPROM.read(memoria1rpm2_8);  
    rpm3_8 = EEPROM.read(memoria1rpm3_8);  
    rpm4_8 = EEPROM.read(memoria1rpm4_8);
    
    rpm1_9 = EEPROM.read(memoria1rpm1_9);  
    rpm2_9 = EEPROM.read(memoria1rpm2_9);  
    rpm3_9 = EEPROM.read(memoria1rpm3_9);  
    rpm4_9 = EEPROM.read(memoria1rpm4_9);
    
    rpm1_10 = EEPROM.read(memoria1rpm1_10);  
    rpm2_10 = EEPROM.read(memoria1rpm2_10);  
    rpm3_10 = EEPROM.read(memoria1rpm3_10);  
    rpm4_10 = EEPROM.read(memoria1rpm4_10);
    
    rpm1_11 = EEPROM.read(memoria1rpm1_11);  
    rpm2_11 = EEPROM.read(memoria1rpm2_11);  
    rpm3_11 = EEPROM.read(memoria1rpm3_11);  
    rpm4_11 = EEPROM.read(memoria1rpm4_11);
    
    rpm1_12 = EEPROM.read(memoria1rpm1_12);  
    rpm2_12 = EEPROM.read(memoria1rpm2_12);  
    rpm3_12 = EEPROM.read(memoria1rpm3_12);  
    rpm4_12 = EEPROM.read(memoria1rpm4_12);
    }







    if (program == 2) {
    
    time1 = EEPROM.read(memoria2time1);    
    time2 = EEPROM.read(memoria2time2);
    time3 = EEPROM.read(memoria2time3);
    time4 = EEPROM.read(memoria2time4);
    time5 = EEPROM.read(memoria2time5);
    time6 = EEPROM.read(memoria2time6);    
    time7 = EEPROM.read(memoria2time7);
    time8 = EEPROM.read(memoria2time8);
    time9 = EEPROM.read(memoria2time9);
    time10 = EEPROM.read(memoria2time10);
    time11 = EEPROM.read(memoria2time11);    
    time12 = EEPROM.read(memoria2time12);

    beep1 = EEPROM.read(memoria2beep1);
    beep2 = EEPROM.read(memoria2beep2);
    beep3 = EEPROM.read(memoria2beep3);
    beep4 = EEPROM.read(memoria2beep4);
    beep5 = EEPROM.read(memoria2beep5);
    beep6 = EEPROM.read(memoria2beep6);
    beep7 = EEPROM.read(memoria2beep7);
    beep8 = EEPROM.read(memoria2beep8);
    beep9 = EEPROM.read(memoria2beep9);
    beep10 = EEPROM.read(memoria2beep10);
    beep11 = EEPROM.read(memoria2beep11);
    beep12 = EEPROM.read(memoria2beep12);
     
    relay1_1 = EEPROM.read(memoria2relay1_1);  
    relay2_1 = EEPROM.read(memoria2relay2_1);
    relay3_1 = EEPROM.read(memoria2relay3_1);  
    relay4_1 = EEPROM.read(memoria2relay4_1);
    relay5_1 = EEPROM.read(memoria2relay5_1);
    
    relay1_2 = EEPROM.read(memoria2relay1_2);  
    relay2_2 = EEPROM.read(memoria2relay2_2);  
    relay3_2 = EEPROM.read(memoria2relay3_2);  
    relay4_2 = EEPROM.read(memoria2relay4_2);
    relay5_2 = EEPROM.read(memoria2relay5_2);
    
    relay1_3 = EEPROM.read(memoria2relay1_3);  
    relay2_3 = EEPROM.read(memoria2relay2_3);  
    relay3_3 = EEPROM.read(memoria2relay3_3);  
    relay4_3 = EEPROM.read(memoria2relay4_3);
    relay5_3 = EEPROM.read(memoria2relay5_3);
    
    relay1_4 = EEPROM.read(memoria2relay1_4);  
    relay2_4 = EEPROM.read(memoria2relay2_4);  
    relay3_4 = EEPROM.read(memoria2relay3_4);  
    relay4_4 = EEPROM.read(memoria2relay4_4);
    relay5_4 = EEPROM.read(memoria2relay5_4);
    
    relay1_5 = EEPROM.read(memoria2relay1_5);  
    relay2_5 = EEPROM.read(memoria2relay2_5);  
    relay3_5 = EEPROM.read(memoria2relay3_5);  
    relay4_5 = EEPROM.read(memoria2relay4_5);
    relay5_5 = EEPROM.read(memoria2relay5_5);
    
    relay1_6 = EEPROM.read(memoria2relay1_6);  
    relay2_6 = EEPROM.read(memoria2relay2_6);  
    relay3_6 = EEPROM.read(memoria2relay3_6);  
    relay4_6 = EEPROM.read(memoria2relay4_6);
    relay5_6 = EEPROM.read(memoria2relay5_6);
    
    relay1_7 = EEPROM.read(memoria2relay1_7);  
    relay2_7 = EEPROM.read(memoria2relay2_7);  
    relay3_7 = EEPROM.read(memoria2relay3_7);  
    relay4_7 = EEPROM.read(memoria2relay4_7);
    relay5_7 = EEPROM.read(memoria2relay5_7);
    
    relay1_8 = EEPROM.read(memoria2relay1_8);  
    relay2_8 = EEPROM.read(memoria2relay2_8);  
    relay3_8 = EEPROM.read(memoria2relay3_8);  
    relay4_8 = EEPROM.read(memoria2relay4_8);
    relay5_8 = EEPROM.read(memoria2relay5_8);
    
    relay1_9 = EEPROM.read(memoria2relay1_9);  
    relay2_9 = EEPROM.read(memoria2relay2_9);  
    relay3_9 = EEPROM.read(memoria2relay3_9);  
    relay4_9 = EEPROM.read(memoria2relay4_9);
    relay5_9 = EEPROM.read(memoria2relay5_9);
    
    relay1_10 = EEPROM.read(memoria2relay1_10);  
    relay2_10 = EEPROM.read(memoria2relay2_10);  
    relay3_10 = EEPROM.read(memoria2relay3_10);  
    relay4_10 = EEPROM.read(memoria2relay4_10);
    relay5_10 = EEPROM.read(memoria2relay5_10);
    
    relay1_11 = EEPROM.read(memoria2relay1_11);  
    relay2_11 = EEPROM.read(memoria2relay2_11);  
    relay3_11 = EEPROM.read(memoria2relay3_11);  
    relay4_11 = EEPROM.read(memoria2relay4_11);
    relay5_11 = EEPROM.read(memoria2relay5_11);
    
    relay1_12 = EEPROM.read(memoria2relay1_12);  
    relay2_12 = EEPROM.read(memoria2relay2_12);  
    relay3_12 = EEPROM.read(memoria2relay3_12);  
    relay4_12 = EEPROM.read(memoria2relay4_12);
    relay5_12 = EEPROM.read(memoria2relay5_12);
      
    way1_1 = EEPROM.read(memoria2way1_1);  
    way2_1 = EEPROM.read(memoria2way2_1);
    way3_1 = EEPROM.read(memoria2way3_1);  
    way4_1 = EEPROM.read(memoria2way4_1);
    
    way1_2 = EEPROM.read(memoria2way1_2);  
    way2_2 = EEPROM.read(memoria2way2_2);  
    way3_2 = EEPROM.read(memoria2way3_2);  
    way4_2 = EEPROM.read(memoria2way4_2);
    
    way1_3 = EEPROM.read(memoria2way1_3);  
    way2_3 = EEPROM.read(memoria2way2_3);  
    way3_3 = EEPROM.read(memoria2way3_3);  
    way4_3 = EEPROM.read(memoria2way4_3);
    
    way1_4 = EEPROM.read(memoria2way1_4);  
    way2_4 = EEPROM.read(memoria2way2_4);  
    way3_4 = EEPROM.read(memoria2way3_4);  
    way4_4 = EEPROM.read(memoria2way4_4);
    
    way1_5 = EEPROM.read(memoria2way1_5);  
    way2_5 = EEPROM.read(memoria2way2_5);  
    way3_5 = EEPROM.read(memoria2way3_5);  
    way4_5 = EEPROM.read(memoria2way4_5);
    
    way1_6 = EEPROM.read(memoria2way1_6);  
    way2_6 = EEPROM.read(memoria2way2_6);  
    way3_6 = EEPROM.read(memoria2way3_6);  
    way4_6 = EEPROM.read(memoria2way4_6);
    
    way1_7 = EEPROM.read(memoria2way1_7);  
    way2_7 = EEPROM.read(memoria2way2_7);  
    way3_7 = EEPROM.read(memoria2way3_7);  
    way4_7 = EEPROM.read(memoria2way4_7);
    
    way1_8 = EEPROM.read(memoria2way1_8);  
    way2_8 = EEPROM.read(memoria2way2_8);  
    way3_8 = EEPROM.read(memoria2way3_8);  
    way4_8 = EEPROM.read(memoria2way4_8);
    
    way1_9 = EEPROM.read(memoria2way1_9);  
    way2_9 = EEPROM.read(memoria2way2_9);  
    way3_9 = EEPROM.read(memoria2way3_9);  
    way4_9 = EEPROM.read(memoria2way4_9);
    
    way1_10 = EEPROM.read(memoria2way1_10);  
    way2_10 = EEPROM.read(memoria2way2_10);  
    way3_10 = EEPROM.read(memoria2way3_10);  
    way4_10 = EEPROM.read(memoria2way4_10);
    
    way1_11 = EEPROM.read(memoria2way1_11);  
    way2_11 = EEPROM.read(memoria2way2_11);  
    way3_11 = EEPROM.read(memoria2way3_11);  
    way4_11 = EEPROM.read(memoria2way4_11);
    
    way1_12 = EEPROM.read(memoria2way1_12);  
    way2_12 = EEPROM.read(memoria2way2_12);  
    way3_12 = EEPROM.read(memoria2way3_12);  
    way4_12 = EEPROM.read(memoria2way4_12);
      
    rpm1_1 = EEPROM.read(memoria2rpm1_1);  
    rpm2_1 = EEPROM.read(memoria2rpm2_1);
    rpm3_1 = EEPROM.read(memoria2rpm3_1);  
    rpm4_1 = EEPROM.read(memoria2rpm4_1);
    
    rpm1_2 = EEPROM.read(memoria2rpm1_2);  
    rpm2_2 = EEPROM.read(memoria2rpm2_2);  
    rpm3_2 = EEPROM.read(memoria2rpm3_2);  
    rpm4_2 = EEPROM.read(memoria2rpm4_2);
    
    rpm1_3 = EEPROM.read(memoria2rpm1_3);  
    rpm2_3 = EEPROM.read(memoria2rpm2_3);  
    rpm3_3 = EEPROM.read(memoria2rpm3_3);  
    rpm4_3 = EEPROM.read(memoria2rpm4_3);
    
    rpm1_4 = EEPROM.read(memoria2rpm1_4);  
    rpm2_4 = EEPROM.read(memoria2rpm2_4);  
    rpm3_4 = EEPROM.read(memoria2rpm3_4);  
    rpm4_4 = EEPROM.read(memoria2rpm4_4);
    
    rpm1_5 = EEPROM.read(memoria2rpm1_5);  
    rpm2_5 = EEPROM.read(memoria2rpm2_5);  
    rpm3_5 = EEPROM.read(memoria2rpm3_5);  
    rpm4_5 = EEPROM.read(memoria2rpm4_5);
    
    rpm1_6 = EEPROM.read(memoria2rpm1_6);  
    rpm2_6 = EEPROM.read(memoria2rpm2_6);  
    rpm3_6 = EEPROM.read(memoria2rpm3_6);  
    rpm4_6 = EEPROM.read(memoria2rpm4_6);
    
    rpm1_7 = EEPROM.read(memoria2rpm1_7);  
    rpm2_7 = EEPROM.read(memoria2rpm2_7);  
    rpm3_7 = EEPROM.read(memoria2rpm3_7);  
    rpm4_7 = EEPROM.read(memoria2rpm4_7);
    
    rpm1_8 = EEPROM.read(memoria2rpm1_8);  
    rpm2_8 = EEPROM.read(memoria2rpm2_8);  
    rpm3_8 = EEPROM.read(memoria2rpm3_8);  
    rpm4_8 = EEPROM.read(memoria2rpm4_8);
    
    rpm1_9 = EEPROM.read(memoria2rpm1_9);  
    rpm2_9 = EEPROM.read(memoria2rpm2_9);  
    rpm3_9 = EEPROM.read(memoria2rpm3_9);  
    rpm4_9 = EEPROM.read(memoria2rpm4_9);
    
    rpm1_10 = EEPROM.read(memoria2rpm1_10);  
    rpm2_10 = EEPROM.read(memoria2rpm2_10);  
    rpm3_10 = EEPROM.read(memoria2rpm3_10);  
    rpm4_10 = EEPROM.read(memoria2rpm4_10);
    
    rpm1_11 = EEPROM.read(memoria2rpm1_11);  
    rpm2_11 = EEPROM.read(memoria2rpm2_11);  
    rpm3_11 = EEPROM.read(memoria2rpm3_11);  
    rpm4_11 = EEPROM.read(memoria2rpm4_11);
    
    rpm1_12 = EEPROM.read(memoria2rpm1_12);  
    rpm2_12 = EEPROM.read(memoria2rpm2_12);  
    rpm3_12 = EEPROM.read(memoria2rpm3_12);  
    rpm4_12 = EEPROM.read(memoria2rpm4_12);
    }






    if (program == 3) {
    
    time1 = EEPROM.read(memoria3time1);    
    time2 = EEPROM.read(memoria3time2);
    time3 = EEPROM.read(memoria3time3);
    time4 = EEPROM.read(memoria3time4);
    time5 = EEPROM.read(memoria3time5);
    time6 = EEPROM.read(memoria3time6);    
    time7 = EEPROM.read(memoria3time7);
    time8 = EEPROM.read(memoria3time8);
    time9 = EEPROM.read(memoria3time9);
    time10 = EEPROM.read(memoria3time10);
    time11 = EEPROM.read(memoria3time11);    
    time12 = EEPROM.read(memoria3time12);

    beep1 = EEPROM.read(memoria3beep1);
    beep2 = EEPROM.read(memoria3beep2);
    beep3 = EEPROM.read(memoria3beep3);
    beep4 = EEPROM.read(memoria3beep4);
    beep5 = EEPROM.read(memoria3beep5);
    beep6 = EEPROM.read(memoria3beep6);
    beep7 = EEPROM.read(memoria3beep7);
    beep8 = EEPROM.read(memoria3beep8);
    beep9 = EEPROM.read(memoria3beep9);
    beep10 = EEPROM.read(memoria3beep10);
    beep11 = EEPROM.read(memoria3beep11);
    beep12 = EEPROM.read(memoria3beep12);         
     
    relay1_1 = EEPROM.read(memoria3relay1_1);  
    relay2_1 = EEPROM.read(memoria3relay2_1);
    relay3_1 = EEPROM.read(memoria3relay3_1);  
    relay4_1 = EEPROM.read(memoria3relay4_1);
    relay5_1 = EEPROM.read(memoria3relay5_1);
    
    relay1_2 = EEPROM.read(memoria3relay1_2);  
    relay2_2 = EEPROM.read(memoria3relay2_2);  
    relay3_2 = EEPROM.read(memoria3relay3_2);  
    relay4_2 = EEPROM.read(memoria3relay4_2);
    relay5_2 = EEPROM.read(memoria3relay5_2);
    
    relay1_3 = EEPROM.read(memoria3relay1_3);  
    relay2_3 = EEPROM.read(memoria3relay2_3);  
    relay3_3 = EEPROM.read(memoria3relay3_3);  
    relay4_3 = EEPROM.read(memoria3relay4_3);
    relay5_3 = EEPROM.read(memoria3relay5_3);
    
    relay1_4 = EEPROM.read(memoria3relay1_4);  
    relay2_4 = EEPROM.read(memoria3relay2_4);  
    relay3_4 = EEPROM.read(memoria3relay3_4);  
    relay4_4 = EEPROM.read(memoria3relay4_4);
    relay5_4 = EEPROM.read(memoria3relay5_4);
    
    relay1_5 = EEPROM.read(memoria3relay1_5);  
    relay2_5 = EEPROM.read(memoria3relay2_5);  
    relay3_5 = EEPROM.read(memoria3relay3_5);  
    relay4_5 = EEPROM.read(memoria3relay4_5);
    relay5_5 = EEPROM.read(memoria3relay5_5);
    
    relay1_6 = EEPROM.read(memoria3relay1_6);  
    relay2_6 = EEPROM.read(memoria3relay2_6);  
    relay3_6 = EEPROM.read(memoria3relay3_6);  
    relay4_6 = EEPROM.read(memoria3relay4_6);
    relay5_6 = EEPROM.read(memoria3relay5_6);
    
    relay1_7 = EEPROM.read(memoria3relay1_7);  
    relay2_7 = EEPROM.read(memoria3relay2_7);  
    relay3_7 = EEPROM.read(memoria3relay3_7);  
    relay4_7 = EEPROM.read(memoria3relay4_7);
    relay5_7 = EEPROM.read(memoria3relay5_7);
    
    relay1_8 = EEPROM.read(memoria3relay1_8);  
    relay2_8 = EEPROM.read(memoria3relay2_8);  
    relay3_8 = EEPROM.read(memoria3relay3_8);  
    relay4_8 = EEPROM.read(memoria3relay4_8);
    relay5_8 = EEPROM.read(memoria3relay5_8);
    
    relay1_9 = EEPROM.read(memoria3relay1_9);  
    relay2_9 = EEPROM.read(memoria3relay2_9);  
    relay3_9 = EEPROM.read(memoria3relay3_9);  
    relay4_9 = EEPROM.read(memoria3relay4_9);
    relay5_9 = EEPROM.read(memoria3relay5_9);
    
    relay1_10 = EEPROM.read(memoria3relay1_10);  
    relay2_10 = EEPROM.read(memoria3relay2_10);  
    relay3_10 = EEPROM.read(memoria3relay3_10);  
    relay4_10 = EEPROM.read(memoria3relay4_10);
    relay5_10 = EEPROM.read(memoria3relay5_10);
    
    relay1_11 = EEPROM.read(memoria3relay1_11);  
    relay2_11 = EEPROM.read(memoria3relay2_11);  
    relay3_11 = EEPROM.read(memoria3relay3_11);  
    relay4_11 = EEPROM.read(memoria3relay4_11);
    relay5_11 = EEPROM.read(memoria3relay5_11);
    
    relay1_12 = EEPROM.read(memoria3relay1_12);  
    relay2_12 = EEPROM.read(memoria3relay2_12);  
    relay3_12 = EEPROM.read(memoria3relay3_12);  
    relay4_12 = EEPROM.read(memoria3relay4_12);
    relay5_12 = EEPROM.read(memoria3relay5_12);
      
    way1_1 = EEPROM.read(memoria3way1_1);  
    way2_1 = EEPROM.read(memoria3way2_1);
    way3_1 = EEPROM.read(memoria3way3_1);  
    way4_1 = EEPROM.read(memoria3way4_1);
    
    way1_2 = EEPROM.read(memoria3way1_2);  
    way2_2 = EEPROM.read(memoria3way2_2);  
    way3_2 = EEPROM.read(memoria3way3_2);  
    way4_2 = EEPROM.read(memoria3way4_2);
    
    way1_3 = EEPROM.read(memoria3way1_3);  
    way2_3 = EEPROM.read(memoria3way2_3);  
    way3_3 = EEPROM.read(memoria3way3_3);  
    way4_3 = EEPROM.read(memoria3way4_3);
    
    way1_4 = EEPROM.read(memoria3way1_4);  
    way2_4 = EEPROM.read(memoria3way2_4);  
    way3_4 = EEPROM.read(memoria3way3_4);  
    way4_4 = EEPROM.read(memoria3way4_4);
    
    way1_5 = EEPROM.read(memoria3way1_5);  
    way2_5 = EEPROM.read(memoria3way2_5);  
    way3_5 = EEPROM.read(memoria3way3_5);  
    way4_5 = EEPROM.read(memoria3way4_5);
    
    way1_6 = EEPROM.read(memoria3way1_6);  
    way2_6 = EEPROM.read(memoria3way2_6);  
    way3_6 = EEPROM.read(memoria3way3_6);  
    way4_6 = EEPROM.read(memoria3way4_6);
    
    way1_7 = EEPROM.read(memoria3way1_7);  
    way2_7 = EEPROM.read(memoria3way2_7);  
    way3_7 = EEPROM.read(memoria3way3_7);  
    way4_7 = EEPROM.read(memoria3way4_7);
    
    way1_8 = EEPROM.read(memoria3way1_8);  
    way2_8 = EEPROM.read(memoria3way2_8);  
    way3_8 = EEPROM.read(memoria3way3_8);  
    way4_8 = EEPROM.read(memoria3way4_8);
    
    way1_9 = EEPROM.read(memoria3way1_9);  
    way2_9 = EEPROM.read(memoria3way2_9);  
    way3_9 = EEPROM.read(memoria3way3_9);  
    way4_9 = EEPROM.read(memoria3way4_9);
    
    way1_10 = EEPROM.read(memoria3way1_10);  
    way2_10 = EEPROM.read(memoria3way2_10);  
    way3_10 = EEPROM.read(memoria3way3_10);  
    way4_10 = EEPROM.read(memoria3way4_10);
    
    way1_11 = EEPROM.read(memoria3way1_11);  
    way2_11 = EEPROM.read(memoria3way2_11);  
    way3_11 = EEPROM.read(memoria3way3_11);  
    way4_11 = EEPROM.read(memoria3way4_11);
    
    way1_12 = EEPROM.read(memoria3way1_12);  
    way2_12 = EEPROM.read(memoria3way2_12);  
    way3_12 = EEPROM.read(memoria3way3_12);  
    way4_12 = EEPROM.read(memoria3way4_12);
      
    rpm1_1 = EEPROM.read(memoria3rpm1_1);  
    rpm2_1 = EEPROM.read(memoria3rpm2_1);
    rpm3_1 = EEPROM.read(memoria3rpm3_1);  
    rpm4_1 = EEPROM.read(memoria3rpm4_1);
    
    rpm1_2 = EEPROM.read(memoria3rpm1_2);  
    rpm2_2 = EEPROM.read(memoria3rpm2_2);  
    rpm3_2 = EEPROM.read(memoria3rpm3_2);  
    rpm4_2 = EEPROM.read(memoria3rpm4_2);
    
    rpm1_3 = EEPROM.read(memoria3rpm1_3);  
    rpm2_3 = EEPROM.read(memoria3rpm2_3);  
    rpm3_3 = EEPROM.read(memoria3rpm3_3);  
    rpm4_3 = EEPROM.read(memoria3rpm4_3);
    
    rpm1_4 = EEPROM.read(memoria3rpm1_4);  
    rpm2_4 = EEPROM.read(memoria3rpm2_4);  
    rpm3_4 = EEPROM.read(memoria3rpm3_4);  
    rpm4_4 = EEPROM.read(memoria3rpm4_4);
    
    rpm1_5 = EEPROM.read(memoria3rpm1_5);  
    rpm2_5 = EEPROM.read(memoria3rpm2_5);  
    rpm3_5 = EEPROM.read(memoria3rpm3_5);  
    rpm4_5 = EEPROM.read(memoria3rpm4_5);
    
    rpm1_6 = EEPROM.read(memoria3rpm1_6);  
    rpm2_6 = EEPROM.read(memoria3rpm2_6);  
    rpm3_6 = EEPROM.read(memoria3rpm3_6);  
    rpm4_6 = EEPROM.read(memoria3rpm4_6);
    
    rpm1_7 = EEPROM.read(memoria3rpm1_7);  
    rpm2_7 = EEPROM.read(memoria3rpm2_7);  
    rpm3_7 = EEPROM.read(memoria3rpm3_7);  
    rpm4_7 = EEPROM.read(memoria3rpm4_7);
    
    rpm1_8 = EEPROM.read(memoria3rpm1_8);  
    rpm2_8 = EEPROM.read(memoria3rpm2_8);  
    rpm3_8 = EEPROM.read(memoria3rpm3_8);  
    rpm4_8 = EEPROM.read(memoria3rpm4_8);
    
    rpm1_9 = EEPROM.read(memoria3rpm1_9);  
    rpm2_9 = EEPROM.read(memoria3rpm2_9);  
    rpm3_9 = EEPROM.read(memoria3rpm3_9);  
    rpm4_9 = EEPROM.read(memoria3rpm4_9);
    
    rpm1_10 = EEPROM.read(memoria3rpm1_10);  
    rpm2_10 = EEPROM.read(memoria3rpm2_10);  
    rpm3_10 = EEPROM.read(memoria3rpm3_10);  
    rpm4_10 = EEPROM.read(memoria3rpm4_10);
    
    rpm1_11 = EEPROM.read(memoria3rpm1_11);  
    rpm2_11 = EEPROM.read(memoria3rpm2_11);  
    rpm3_11 = EEPROM.read(memoria3rpm3_11);  
    rpm4_11 = EEPROM.read(memoria3rpm4_11);
    
    rpm1_12 = EEPROM.read(memoria3rpm1_12);  
    rpm2_12 = EEPROM.read(memoria3rpm2_12);  
    rpm3_12 = EEPROM.read(memoria3rpm3_12);  
    rpm4_12 = EEPROM.read(memoria3rpm4_12);
    }

    
    
    lcd.clear();

    WiFi.softAPConfig(local_IP, gateway, subnet);
    WiFi.softAP(ssid, password);

    dnsServer.start(53, "*", local_IP);

// GET: página principal com valores preenchidos
server.on("/", HTTP_GET, []() {

String html = "<!DOCTYPE html><html><head><meta charset='UTF-8'>"
              "<title>Step Module Page</title>"
              "<style>"
              "/* ===== Tabela ===== */"
              "table{"
              "  border-collapse:collapse;"
              "  width:100%;"
              "  font-size:12px;"
              "}"
              "th, td{"
              "  border:1px solid #000;"
              "  padding:2px;"
              "  text-align:center;"
              "}"
              "th{"
              "  background:#ddd;"
              "}"
              ".highlight{"
              "  background:#ddd;"
              "}"
              
              /* ===== Inputs ===== */
              "input[type=number], input[type=text]{"
              "  border:1px solid #000;"
              "  border-radius:4px;"
              "  padding:2px;"
              "  width:50px;"
              "  box-sizing:border-box;"
              "  font-size:12px;"
              "}"
              
              /* input do nome do programa */
              "input#programName{"
              "  width:200px;"
              "  padding:4px;"
              "  border:1px solid #000;"
              "  border-radius:4px;"
              "  font-size:12px;"
              "}"
              
              /* ===== Inputs RPM ativos ===== */
              ".rpm-active{"
              "  background-color:gold !important;"
              "  border:1px solid #000 !important;"
              "  border-radius:4px !important;"
              "}"
              
              /* ===== Botões ===== */
              "button{"
              "  margin:4px;"
              "  padding:6px 12px;"
              "  font-size:14px;"
              "  border:1px solid #000;"
              "  border-radius:4px;"
              "  background:#eee;"
              "  color:#000;"
              "  cursor:pointer;"
              "  appearance:none;"
              "  -webkit-appearance:none;"
              "}"
              "button:focus{outline:none;}"
              "button:active{transform:none;}"
              
              /* estado Saved */
              "button.saved{"
              "  background-color:green;"
              "  color:white;"
              "}"
              
              /* ===== Destaque do nome do programa ===== */
              ".program-name{"
              "  background:#007bff;"
              "  color:white;"
              "  padding:4px 10px;"
              "  border-radius:8px;"
              "}"
              "</style>"

              
              "</head><body>"
              "<h2>Steps Configuration - Program "
              "<span style='background:#007bff;color:white;padding:4px 10px;border-radius:8px;'>"
              + programNames[program-1] +
              "</span>"
              "</h2>"
              "<p>Created by Gilberto Coelho in March 2026</p><br>"
              "<form method='POST' action='/submit'>"
              "<div style='margin-bottom:10px; display:flex; align-items:center;'>"
              "  <label for='program'><b>Select Program: </b></label> "
              "  <select name='program' id='program'>"
              "    <option value='1'" + String(program==1 ? " selected" : "") + ">" + programNames[0] + "</option>"
              "    <option value='2'" + String(program==2 ? " selected" : "") + ">" + programNames[1] + "</option>"
              "    <option value='3'" + String(program==3 ? " selected" : "") + ">" + programNames[2] + "</option>"
              "  </select>"
              "  <button type='button' style='margin-left:5px;padding:2px 6px;font-size:12px;' "
              "          onclick='updateProgram()'>Update</button>"
              "</div>"
              "<table>";





  // Primeira linha: título dos canais, só na parte dos canais
  html += "<tr>"
          "<th rowspan='2'>Step</th><th rowspan='2'>Time (s)</th>"
          "<th rowspan='2'>Read</th><th rowspan='2'>Valve</th><th rowspan='2'>Heat</th>"
          "<th rowspan='2'>Relay 1</th><th rowspan='2'>Relay 2</th><th rowspan='2'>Beep</th>"
          "<th colspan='8'>Peristaltic Pump Channels</th>"
          "</tr>";
  
  // Segunda linha: subcanais
  html += "<tr>"
          "<th class='highlight'>RPM 1</th><th class='highlight'>Direction 1</th>"
          "<th>RPM 2</th><th>Direction 2</th>"
          "<th class='highlight'>RPM 3</th><th class='highlight'>Direction 3</th>"
          "<th>RPM 4</th><th>Direction 4</th>"
          "</tr>";


  for (int s = 1; s <= 12; s++) {
    // Pega o valor do tempo correspondente
    byte t_val = (s==1)? time1 : (s==2)? time2 : (s==3)? time3 : (s==4)? time4 :
                 (s==5)? time5 : (s==6)? time6 : (s==7)? time7 : (s==8)? time8 :
                 (s==9)? time9 : (s==10)? time10 : (s==11)? time11 : time12;

    html += "<tr>";
    html += "<td>" + String(s) + "</td>";
    html += "<td><input type='number' name='time" + String(s) + "' min='0' max='255' value='" + String(t_val) + "'></td>";

    // Relays
    bool r1 = (s==1)? relay1_1 : (s==2)? relay1_2 : (s==3)? relay1_3 : (s==4)? relay1_4 :
              (s==5)? relay1_5 : (s==6)? relay1_6 : (s==7)? relay1_7 : (s==8)? relay1_8 :
              (s==9)? relay1_9 : (s==10)? relay1_10 : (s==11)? relay1_11 : relay1_12;

    bool r2 = (s==1)? relay2_1 : (s==2)? relay2_2 : (s==3)? relay2_3 : (s==4)? relay2_4 :
              (s==5)? relay2_5 : (s==6)? relay2_6 : (s==7)? relay2_7 : (s==8)? relay2_8 :
              (s==9)? relay2_9 : (s==10)? relay2_10 : (s==11)? relay2_11 : relay2_12;

    bool r3 = (s==1)? relay3_1 : (s==2)? relay3_2 : (s==3)? relay3_3 : (s==4)? relay3_4 :
              (s==5)? relay3_5 : (s==6)? relay3_6 : (s==7)? relay3_7 : (s==8)? relay3_8 :
              (s==9)? relay3_9 : (s==10)? relay3_10 : (s==11)? relay3_11 : relay3_12;

    bool r4 = (s==1)? relay4_1 : (s==2)? relay4_2 : (s==3)? relay4_3 : (s==4)? relay4_4 :
              (s==5)? relay4_5 : (s==6)? relay4_6 : (s==7)? relay4_7 : (s==8)? relay4_8 :
              (s==9)? relay4_9 : (s==10)? relay4_10 : (s==11)? relay4_11 : relay4_12;

    bool r5 = (s==1)? relay5_1 : (s==2)? relay5_2 : (s==3)? relay5_3 : (s==4)? relay5_4 :
              (s==5)? relay5_5 : (s==6)? relay5_6 : (s==7)? relay5_7 : (s==8)? relay5_8 :
              (s==9)? relay5_9 : (s==10)? relay5_10 : (s==11)? relay5_11 : relay5_12;

    bool r6 = (s==1)? beep1 : (s==2)? beep2 : (s==3)? beep3 : (s==4)? beep4 :
              (s==5)? beep5 : (s==6)? beep6 : (s==7)? beep7 : (s==8)? beep8 :
              (s==9)? beep9 : (s==10)? beep10 : (s==11)? beep11 : beep12;

    html += "<td><input type='checkbox' name='relay1_" + String(s) + "' " + (r1?"checked":"") + "></td>";
    html += "<td><input type='checkbox' name='relay2_" + String(s) + "' " + (r2?"checked":"") + "></td>";
    html += "<td><input type='checkbox' name='relay3_" + String(s) + "' " + (r3?"checked":"") + "></td>";
    html += "<td><input type='checkbox' name='relay4_" + String(s) + "' " + (r4?"checked":"") + "></td>";
    html += "<td><input type='checkbox' name='relay5_" + String(s) + "' " + (r5?"checked":"") + "></td>";
    html += "<td><input type='checkbox' name='beep" + String(s) + "' " + (r6?"checked":"") + "></td>";

    // RPMs e Ways
    
    // RPM1 / Way1
    byte rpm1 = (s==1)? rpm1_1 : (s==2)? rpm1_2 : (s==3)? rpm1_3 : (s==4)? rpm1_4 :
                (s==5)? rpm1_5 : (s==6)? rpm1_6 : (s==7)? rpm1_7 : (s==8)? rpm1_8 :
                (s==9)? rpm1_9 : (s==10)? rpm1_10 : (s==11)? rpm1_11 : rpm1_12;
    
    byte way1 = (s==1)? way1_1 : (s==2)? way1_2 : (s==3)? way1_3 : (s==4)? way1_4 :
                (s==5)? way1_5 : (s==6)? way1_6 : (s==7)? way1_7 : (s==8)? way1_8 :
                (s==9)? way1_9 : (s==10)? way1_10 : (s==11)? way1_11 : way1_12;
    
    html += "<td class='highlight'><input class='rpm-input' type='number' name='rpm1_" 
        + String(s) + "' min='0' max='100' value='" + String(rpm1) + "'></td>";

    html += "<td class='highlight'><select name='way1_" + String(s) + "'>"
            "<option value='0'" + String(way1==0?" selected":"") + ">CW</option>"
            "<option value='1'" + String(way1==1?" selected":"") + ">CCW</option></select></td>";
    
    // RPM2 / Way2
    byte rpm2 = (s==1)? rpm2_1 : (s==2)? rpm2_2 : (s==3)? rpm2_3 : (s==4)? rpm2_4 :
                (s==5)? rpm2_5 : (s==6)? rpm2_6 : (s==7)? rpm2_7 : (s==8)? rpm2_8 :
                (s==9)? rpm2_9 : (s==10)? rpm2_10 : (s==11)? rpm2_11 : rpm2_12;
    
    byte way2 = (s==1)? way2_1 : (s==2)? way2_2 : (s==3)? way2_3 : (s==4)? way2_4 :
                (s==5)? way2_5 : (s==6)? way2_6 : (s==7)? way2_7 : (s==8)? way2_8 :
                (s==9)? way2_9 : (s==10)? way2_10 : (s==11)? way2_11 : way2_12;
    
    html += "<td><input class='rpm-input' type='number' name='rpm2_" 
        + String(s) + "' min='0' max='100' value='" + String(rpm2) + "'></td>";

    html += "<td><select name='way2_" + String(s) + "'>"
            "<option value='0'" + String(way2==0?" selected":"") + ">CW</option>"
            "<option value='1'" + String(way2==1?" selected":"") + ">CCW</option></select></td>";
    
    // RPM3 / Way3
    byte rpm3 = (s==1)? rpm3_1 : (s==2)? rpm3_2 : (s==3)? rpm3_3 : (s==4)? rpm3_4 :
                (s==5)? rpm3_5 : (s==6)? rpm3_6 : (s==7)? rpm3_7 : (s==8)? rpm3_8 :
                (s==9)? rpm3_9 : (s==10)? rpm3_10 : (s==11)? rpm3_11 : rpm3_12;
    
    byte way3 = (s==1)? way3_1 : (s==2)? way3_2 : (s==3)? way3_3 : (s==4)? way3_4 :
                (s==5)? way3_5 : (s==6)? way3_6 : (s==7)? way3_7 : (s==8)? way3_8 :
                (s==9)? way3_9 : (s==10)? way3_10 : (s==11)? way3_11 : way3_12;
    
    html += "<td class='highlight'><input class='rpm-input' type='number' name='rpm3_" 
        + String(s) + "' min='0' max='100' value='" + String(rpm3) + "'></td>";

    html += "<td class='highlight'><select name='way3_" + String(s) + "'>"
            "<option value='0'" + String(way3==0?" selected":"") + ">CW</option>"
            "<option value='1'" + String(way3==1?" selected":"") + ">CCW</option></select></td>";
    
    // RPM4 / Way4
    byte rpm4 = (s==1)? rpm4_1 : (s==2)? rpm4_2 : (s==3)? rpm4_3 : (s==4)? rpm4_4 :
                (s==5)? rpm4_5 : (s==6)? rpm4_6 : (s==7)? rpm4_7 : (s==8)? rpm4_8 :
                (s==9)? rpm4_9 : (s==10)? rpm4_10 : (s==11)? rpm4_11 : rpm4_12;
    
    byte way4 = (s==1)? way4_1 : (s==2)? way4_2 : (s==3)? way4_3 : (s==4)? way4_4 :
                (s==5)? way4_5 : (s==6)? way4_6 : (s==7)? way4_7 : (s==8)? way4_8 :
                (s==9)? way4_9 : (s==10)? way4_10 : (s==11)? way4_11 : way4_12;
    
    html += "<td><input class='rpm-input' type='number' name='rpm4_" 
        + String(s) + "' min='0' max='100' value='" + String(rpm4) + "'></td>";

    html += "<td><select name='way4_" + String(s) + "'>"
            "<option value='0'" + String(way4==0?" selected":"") + ">CW</option>"
            "<option value='1'" + String(way4==1?" selected":"") + ">CCW</option></select></td>";

  }

  html += "</table>"
          // Container para o botão Save + mensagem
          "<div style='margin-top:10px; display:flex; align-items:center;'>"
          "<label for='programName'><b>Program name (max. 16 characters):</b></label>"
          "<input type='text' id='programName' name='programName' maxlength='16'"
          "value='" + String(programNames[program-1]) + "'"
          "style='margin-left:5px; width:200px;'>"
          "</div><br>"

          // Save botão          
          "<div style='display:flex;align-items:center;margin-bottom:8px;'>"
          "  <button type='submit' name='action' value='save'>Save</button>"
          "  <span style='margin-left:10px;'>Click to send and save the data</span>"
          "</div>"
          
          // Container para o botão Start + mensagem
          "<div style='display:flex;align-items:center;'>"
          "  <button type='submit' name='action' value='start'>Start</button>"
          "  <span style='margin-left:10px;'>Click to start the measurement</span>"
          "</div>";


          

  html += "<script>"

          // --- BOTÃO SAVE ---
          "const urlParams = new URLSearchParams(window.location.search);"
          "if(urlParams.get('saved') === '1'){"
          "  const btn = document.querySelector('button[name=action][value=save]');"
          "  if(btn){"
          "    btn.textContent = 'Saved!';"
          "    btn.classList.add('saved');"
          "    setTimeout(() => {"
          "      btn.textContent = 'Save';"
          "      btn.classList.remove('saved');"
          "    }, 3000);"
          "  }"
          "}"
          
          // --- UPDATE PROGRAM ---
          "function updateProgram(){"
          "  const prog = document.getElementById('program').value;"
          "  fetch('/programUpdate?program=' + prog)"
          "    .then(response => {"
          "      if(response.ok){"
          "        window.location.replace('/');"
          "      }"
          "    });"
          "}"
          
          // --- RPM HIGHLIGHT AUTOMÁTICO ---
          "function updateRPMHighlight(){"
          "  document.querySelectorAll('.rpm-input').forEach(input => {"
          "    if(parseInt(input.value) > 0){"
          "      input.classList.add('rpm-active');"
          "    }else{"
          "      input.classList.remove('rpm-active');"
          "    }"
          "  });"
          "}"
          
          // Executa ao carregar página
          "window.addEventListener('load', function(){"
          "  updateRPMHighlight();"
          "});"
          
          // Executa quando valor mudar
          "document.addEventListener('input', function(e){"
          "  if(e.target.classList.contains('rpm-input')){"
          "    updateRPMHighlight();"
          "  }"
          "});"
          
          "</script>";


  html +=
          "<hr style='margin:20px 0;'>"
          
          "<br><br><br><h3>Control Buttons</h3>"
          
          "<b>START</b><br>"
          "In <i>Waiting</i> page: Initializes the step sequence.<br>"
          "In <i>Menu</i> page: Decrements values or moves left.<br><br>"
          
          "<b>CANCEL</b><br>"
          "When running: Stops the step sequence.<br>"
          "In <i>Menu</i> page: Increments values or moves right.<br><br>"
          
          "<b>MENU</b><br>"
          "In <i>Waiting</i> page: Enters step configuration mode.<br>"
          "In <i>Menu</i> page: Moves to the next page.<br><br>"
          
          "<b>BACK</b><br>"
          "In <i>Waiting</i> page: Changes the program.<br><br>"
          "In <i>Menu</i> page: Returns one page.<br>"
                    
          "<hr style='margin:20px 0;'>"
          
          "<h3>Utilities</h3>"
          
          "<b>Return to <i>Waiting</i> page:</b><br>"
          "In <i>Menu</i> page, press <b>Back + Start</b>.<br><br>"
          
          "<b>Reset values in memory:</b><br>"
          "In <i>Waiting</i> page, press <b>Start + Cancel + Back</b>.<br><br>"
          
          "<b>Fast values increment/decrement:</b><br>"
          "Keep the respective button pressed to change values faster.<br><br>"
          
          "<hr style='margin:20px 0;'>"
          
          "<h3>Important Information</h3>"
          
          "<b>Read Function:</b><br>"
          "This function activates an internal relay between pins 1 and 3 (RS-232 terminal).<br><br>"
          
          "<b>Startup Procedure:</b><br>"
          "Turn on the REGLO pump first, then power on the module.<br><br>"
          
          "<b>WiFi Setup (Steps and Programs Configuration):</b><br>"
          "1. Connect to: <b>STEP MODULE WIFI</b><br>"
          "2. Open your browser and go to: <b>192.168.4.1</b><br><br>"

          "<b>Beep function:</b><br>"
          "The beep sound will play in the end of the step.<br>";


          
  html += "</form></body></html>";

  server.send(200, "text/html", html);
});




server.on("/running", HTTP_GET, []() {

  String html = "<!DOCTYPE html><html><head><meta charset='UTF-8'>"
                "<title>Running</title>"
                "<style>"
                "body{font-family:Arial;text-align:center;margin-top:80px;}"
                "button{padding:10px 20px;font-size:16px;}"
                "</style>"
                "</head><body>"

                "<h2>Program running…</h2>"
                "<p>Please wait until it finishes to return to the main page and edit the steps.</p>"
                "<br>"
                "<a href='/'><button>Return to main page</button></a>"

                "</body></html>";

  server.send(200, "text/html", html);

  delay(100);
  runSteps();   // roda tudo
});




server.on("/programUpdate", HTTP_GET, [](){
  int newProgram = server.arg("program").toInt();
  program = newProgram;
  programUpdate();  // chama a função
  server.send(200, "text/plain", "OK");
});






// POST: tratar submit da tabela
server.on("/submit", HTTP_POST, []() {

  String name = server.arg("programName");
    if (name.length() > 16) {
      name = name.substring(0,16); // garante limite
    }
    saveProgramName(program-1, name); // program-1 porque array começa em 0



  String action = server.arg("action");

  if (action == "save") {
      
      program = server.arg("program").toInt();
      
      // TIME
      time1  = server.arg("time1").toInt();
      time2  = server.arg("time2").toInt();
      time3  = server.arg("time3").toInt();
      time4  = server.arg("time4").toInt();
      time5  = server.arg("time5").toInt();
      time6  = server.arg("time6").toInt();
      time7  = server.arg("time7").toInt();
      time8  = server.arg("time8").toInt();
      time9  = server.arg("time9").toInt();
      time10 = server.arg("time10").toInt();
      time11 = server.arg("time11").toInt();
      time12 = server.arg("time12").toInt();

      // BEEP
      beep1  = server.hasArg("beep1")  ? 1 : 0;
      beep2  = server.hasArg("beep2")  ? 1 : 0;
      beep3  = server.hasArg("beep3")  ? 1 : 0;
      beep4  = server.hasArg("beep4")  ? 1 : 0;
      beep5  = server.hasArg("beep5")  ? 1 : 0;
      beep6  = server.hasArg("beep6")  ? 1 : 0;
      beep7  = server.hasArg("beep7")  ? 1 : 0;
      beep8  = server.hasArg("beep8")  ? 1 : 0;
      beep9  = server.hasArg("beep9")  ? 1 : 0;
      beep10  = server.hasArg("beep10")  ? 1 : 0;
      beep11  = server.hasArg("beep11")  ? 1 : 0;
      beep12  = server.hasArg("beep12")  ? 1 : 0;

      // RELAYS
      relay1_1  = server.hasArg("relay1_1")  ? 1 : 0;
      relay2_1  = server.hasArg("relay2_1")  ? 1 : 0;
      relay3_1  = server.hasArg("relay3_1")  ? 1 : 0;
      relay4_1  = server.hasArg("relay4_1")  ? 1 : 0;
      relay5_1  = server.hasArg("relay5_1")  ? 1 : 0;
      
      relay1_2  = server.hasArg("relay1_2")  ? 1 : 0;
      relay2_2  = server.hasArg("relay2_2")  ? 1 : 0;
      relay3_2  = server.hasArg("relay3_2")  ? 1 : 0;
      relay4_2  = server.hasArg("relay4_2")  ? 1 : 0;
      relay5_2  = server.hasArg("relay5_2")  ? 1 : 0;
      
      relay1_3  = server.hasArg("relay1_3")  ? 1 : 0;
      relay2_3  = server.hasArg("relay2_3")  ? 1 : 0;
      relay3_3  = server.hasArg("relay3_3")  ? 1 : 0;
      relay4_3  = server.hasArg("relay4_3")  ? 1 : 0;
      relay5_3  = server.hasArg("relay5_3")  ? 1 : 0;
      
      relay1_4  = server.hasArg("relay1_4")  ? 1 : 0;
      relay2_4  = server.hasArg("relay2_4")  ? 1 : 0;
      relay3_4  = server.hasArg("relay3_4")  ? 1 : 0;
      relay4_4  = server.hasArg("relay4_4")  ? 1 : 0;
      relay5_4  = server.hasArg("relay5_4")  ? 1 : 0;
      
      relay1_5  = server.hasArg("relay1_5")  ? 1 : 0;
      relay2_5  = server.hasArg("relay2_5")  ? 1 : 0;
      relay3_5  = server.hasArg("relay3_5")  ? 1 : 0;
      relay4_5  = server.hasArg("relay4_5")  ? 1 : 0;
      relay5_5  = server.hasArg("relay5_5")  ? 1 : 0;
      
      relay1_6  = server.hasArg("relay1_6")  ? 1 : 0;
      relay2_6  = server.hasArg("relay2_6")  ? 1 : 0;
      relay3_6  = server.hasArg("relay3_6")  ? 1 : 0;
      relay4_6  = server.hasArg("relay4_6")  ? 1 : 0;
      relay5_6  = server.hasArg("relay5_6")  ? 1 : 0;
      
      relay1_7  = server.hasArg("relay1_7")  ? 1 : 0;
      relay2_7  = server.hasArg("relay2_7")  ? 1 : 0;
      relay3_7  = server.hasArg("relay3_7")  ? 1 : 0;
      relay4_7  = server.hasArg("relay4_7")  ? 1 : 0;
      relay5_7  = server.hasArg("relay5_7")  ? 1 : 0;
      
      relay1_8  = server.hasArg("relay1_8")  ? 1 : 0;
      relay2_8  = server.hasArg("relay2_8")  ? 1 : 0;
      relay3_8  = server.hasArg("relay3_8")  ? 1 : 0;
      relay4_8  = server.hasArg("relay4_8")  ? 1 : 0;
      relay5_8  = server.hasArg("relay5_8")  ? 1 : 0;
      
      relay1_9  = server.hasArg("relay1_9")  ? 1 : 0;
      relay2_9  = server.hasArg("relay2_9")  ? 1 : 0;
      relay3_9  = server.hasArg("relay3_9")  ? 1 : 0;
      relay4_9  = server.hasArg("relay4_9")  ? 1 : 0;
      relay5_9  = server.hasArg("relay5_9")  ? 1 : 0;
      
      relay1_10 = server.hasArg("relay1_10") ? 1 : 0;
      relay2_10 = server.hasArg("relay2_10") ? 1 : 0;
      relay3_10 = server.hasArg("relay3_10") ? 1 : 0;
      relay4_10 = server.hasArg("relay4_10") ? 1 : 0;
      relay5_10 = server.hasArg("relay5_10") ? 1 : 0;
      
      relay1_11 = server.hasArg("relay1_11") ? 1 : 0;
      relay2_11 = server.hasArg("relay2_11") ? 1 : 0;
      relay3_11 = server.hasArg("relay3_11") ? 1 : 0;
      relay4_11 = server.hasArg("relay4_11") ? 1 : 0;
      relay5_11 = server.hasArg("relay5_11") ? 1 : 0;
      
      relay1_12 = server.hasArg("relay1_12") ? 1 : 0;
      relay2_12 = server.hasArg("relay2_12") ? 1 : 0;
      relay3_12 = server.hasArg("relay3_12") ? 1 : 0;
      relay4_12 = server.hasArg("relay4_12") ? 1 : 0;
      relay5_12 = server.hasArg("relay5_12") ? 1 : 0;

      // RPMs
      rpm1_1 = server.arg("rpm1_1").toInt();
      rpm2_1 = server.arg("rpm2_1").toInt();
      rpm3_1 = server.arg("rpm3_1").toInt();
      rpm4_1 = server.arg("rpm4_1").toInt();
      
      rpm1_2 = server.arg("rpm1_2").toInt();
      rpm2_2 = server.arg("rpm2_2").toInt();
      rpm3_2 = server.arg("rpm3_2").toInt();
      rpm4_2 = server.arg("rpm4_2").toInt();
      
      rpm1_3 = server.arg("rpm1_3").toInt();
      rpm2_3 = server.arg("rpm2_3").toInt();
      rpm3_3 = server.arg("rpm3_3").toInt();
      rpm4_3 = server.arg("rpm4_3").toInt();
      
      rpm1_4 = server.arg("rpm1_4").toInt();
      rpm2_4 = server.arg("rpm2_4").toInt();
      rpm3_4 = server.arg("rpm3_4").toInt();
      rpm4_4 = server.arg("rpm4_4").toInt();
      
      rpm1_5 = server.arg("rpm1_5").toInt();
      rpm2_5 = server.arg("rpm2_5").toInt();
      rpm3_5 = server.arg("rpm3_5").toInt();
      rpm4_5 = server.arg("rpm4_5").toInt();
      
      rpm1_6 = server.arg("rpm1_6").toInt();
      rpm2_6 = server.arg("rpm2_6").toInt();
      rpm3_6 = server.arg("rpm3_6").toInt();
      rpm4_6 = server.arg("rpm4_6").toInt();
      
      rpm1_7 = server.arg("rpm1_7").toInt();
      rpm2_7 = server.arg("rpm2_7").toInt();
      rpm3_7 = server.arg("rpm3_7").toInt();
      rpm4_7 = server.arg("rpm4_7").toInt();
      
      rpm1_8 = server.arg("rpm1_8").toInt();
      rpm2_8 = server.arg("rpm2_8").toInt();
      rpm3_8 = server.arg("rpm3_8").toInt();
      rpm4_8 = server.arg("rpm4_8").toInt();
      
      rpm1_9 = server.arg("rpm1_9").toInt();
      rpm2_9 = server.arg("rpm2_9").toInt();
      rpm3_9 = server.arg("rpm3_9").toInt();
      rpm4_9 = server.arg("rpm4_9").toInt();
      
      rpm1_10 = server.arg("rpm1_10").toInt();
      rpm2_10 = server.arg("rpm2_10").toInt();
      rpm3_10 = server.arg("rpm3_10").toInt();
      rpm4_10 = server.arg("rpm4_10").toInt();
      
      rpm1_11 = server.arg("rpm1_11").toInt();
      rpm2_11 = server.arg("rpm2_11").toInt();
      rpm3_11 = server.arg("rpm3_11").toInt();
      rpm4_11 = server.arg("rpm4_11").toInt();
      
      rpm1_12 = server.arg("rpm1_12").toInt();
      rpm2_12 = server.arg("rpm2_12").toInt();
      rpm3_12 = server.arg("rpm3_12").toInt();
      rpm4_12 = server.arg("rpm4_12").toInt();

      // Ways
      way1_1 = server.arg("way1_1").toInt();
      way2_1 = server.arg("way2_1").toInt();
      way3_1 = server.arg("way3_1").toInt();
      way4_1 = server.arg("way4_1").toInt();
      
      way1_2 = server.arg("way1_2").toInt();
      way2_2 = server.arg("way2_2").toInt();
      way3_2 = server.arg("way3_2").toInt();
      way4_2 = server.arg("way4_2").toInt();
      
      way1_3 = server.arg("way1_3").toInt();
      way2_3 = server.arg("way2_3").toInt();
      way3_3 = server.arg("way3_3").toInt();
      way4_3 = server.arg("way4_3").toInt();
      
      way1_4 = server.arg("way1_4").toInt();
      way2_4 = server.arg("way2_4").toInt();
      way3_4 = server.arg("way3_4").toInt();
      way4_4 = server.arg("way4_4").toInt();
      
      way1_5 = server.arg("way1_5").toInt();
      way2_5 = server.arg("way2_5").toInt();
      way3_5 = server.arg("way3_5").toInt();
      way4_5 = server.arg("way4_5").toInt();
      
      way1_6 = server.arg("way1_6").toInt();
      way2_6 = server.arg("way2_6").toInt();
      way3_6 = server.arg("way3_6").toInt();
      way4_6 = server.arg("way4_6").toInt();
      
      way1_7 = server.arg("way1_7").toInt();
      way2_7 = server.arg("way2_7").toInt();
      way3_7 = server.arg("way3_7").toInt();
      way4_7 = server.arg("way4_7").toInt();
      
      way1_8 = server.arg("way1_8").toInt();
      way2_8 = server.arg("way2_8").toInt();
      way3_8 = server.arg("way3_8").toInt();
      way4_8 = server.arg("way4_8").toInt();
      
      way1_9 = server.arg("way1_9").toInt();
      way2_9 = server.arg("way2_9").toInt();
      way3_9 = server.arg("way3_9").toInt();
      way4_9 = server.arg("way4_9").toInt();
      
      way1_10 = server.arg("way1_10").toInt();
      way2_10 = server.arg("way2_10").toInt();
      way3_10 = server.arg("way3_10").toInt();
      way4_10 = server.arg("way4_10").toInt();
      
      way1_11 = server.arg("way1_11").toInt();
      way2_11 = server.arg("way2_11").toInt();
      way3_11 = server.arg("way3_11").toInt();
      way4_11 = server.arg("way4_11").toInt();
      
      way1_12 = server.arg("way1_12").toInt();
      way2_12 = server.arg("way2_12").toInt();
      way3_12 = server.arg("way3_12").toInt();
      way4_12 = server.arg("way4_12").toInt();

      saveData();      
  }

    if (action == "start") {
      server.sendHeader("Location", "/running");
      server.send(303);
      return;
    }

  server.sendHeader("Location", "/?saved=1");
  server.send(303);
});




server.begin();

  
    lcd.setCursor(0, 0); lcd.print("By");
    lcd.setCursor(0, 1); lcd.print("Gilberto Coelho");
    digitalWrite(buzzer, HIGH); delay(100); digitalWrite(buzzer, LOW); delay(100); digitalWrite(buzzer, HIGH); delay(100); digitalWrite(buzzer, LOW);

    servo.attach(pinServo); 
    servo.write(positionOne);
    
    delay(2000);
    
    servo.detach();
    lcd.clear();
}

void loop() {

    dnsServer.processNextRequest();
    server.handleClient();

     if(digitalRead(buttonBack) == LOW && tela == 1){
      while (digitalRead(buttonBack) == LOW) { delay(50); }
      if (program == 1){
        program = 2;
        programUpdate();
      }
      else if (program == 2){
        program = 3;
        programUpdate();
      }
      else if (program == 3){
        program = 1;
        programUpdate();
      }
     }
     
     if (digitalRead(buttonBack) == LOW && tela > 1) { 
     while (digitalRead(buttonBack) == LOW) { delay(200); lcd.setCursor(0,0); lcd.print(F("Push START to   ")); lcd.setCursor(0,1); lcd.print(F("return main page"));
     if (digitalRead(buttonBack) == HIGH) { lcd.clear(); break; }
     if (digitalRead(buttonStart) == LOW) { 
      saveData();
      tela=1; lcd.clear(); break;}
     }}
          
     if (tela==1){
     lcd.setCursor(0,0);                                
     lcd.print(F("Waiting      P=")); lcd.print(program); 
     lcd.setCursor(0,1);
     lcd.print(programNames[program-1]); 

      if (program != lastProgram) {
          lcd.clear();
          lastProgram = program;
      }


    
    if (digitalRead(buttonLedRead) == LOW){ digitalWrite(relayRead, LOW); } 
    else { digitalWrite(relayRead, HIGH); }

    if (digitalRead(buttonLedValve) == LOW && ajuste == 0){ servo.attach(pinServo); ajuste = 1; }
    if (digitalRead(buttonLedValve) == LOW && ajuste == 1){ servo.write(positionTwo); timeDetach = millis(); digitalWrite(relayValve, LOW);} 
    if (digitalRead(buttonLedValve) == HIGH && ajuste == 1) { servo.write(positionOne); ajuste = 2; digitalWrite(relayValve, HIGH); }
    if (millis() - timeDetach >= 1000 && ajuste == 2){ servo.detach(); ajuste = 0; }
    
    if (digitalRead(buttonLedHeat) == LOW){ digitalWrite(relayHeat, LOW); }
    else { digitalWrite(relayHeat, HIGH); }
       
    if (digitalRead(buttonStart) == LOW) { delay(500);
    if (digitalRead(buttonStart) == HIGH) { runSteps(); }


    else if (digitalRead(buttonStart) == LOW && digitalRead(buttonCancel) == LOW){
    while (digitalRead(buttonStart) == LOW && digitalRead(buttonCancel) == LOW){
    lcd.setCursor(0,0); lcd.print(F("Push button BACK"));
    lcd.setCursor(0,1); lcd.print(F("to RESET prog. ")); lcd.print(program);
    if (digitalRead(buttonStart) == HIGH) {lcd.clear(); delay(500); break;}
    if (digitalRead(buttonCancel) == HIGH) {lcd.clear(); delay(500); break;}
      if (digitalRead(buttonStart) == LOW && digitalRead(buttonCancel) == LOW && digitalRead(buttonBack) == LOW){
      if (program == 1) {
        for (int r = 1; r <= 168; r++){
        EEPROM.write(r, 0);}}
      if (program == 2) {
        for (int r = 169; r <= 336; r++){
        EEPROM.write(r, 0);}}
      if (program == 3) {
        for (int r = 337; r <= 504; r++){
        EEPROM.write(r, 0);}}
        EEPROM.commit();
    lcd.clear(); 
    lcd.setCursor(0,0); lcd.print(F("Memory Program ")); lcd.print(program);
    lcd.setCursor(0,1); lcd.print(F("cleaned!        "));
    delay(3000); lcd.clear(); 
    programUpdate(); }}}
}}
   
  
   
     
     else if (tela==2){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step 1 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Time: "));
     lcd.print(time1);
     lcd.print(F("          "));
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; saveData(); lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }    
     else if (tela==3 && relay1_1==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 1 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Read:   Yes  >No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==3 && relay1_1==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 1 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Read:  >Yes   No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==4 && relay2_1==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 1 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Valve:  Yes  >No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==4 && relay2_1==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 1 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Valve: >Yes   No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==5 && relay3_1==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 1 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Heat:   Yes  >No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==5 && relay3_1==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 1 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Heat:  >Yes   No"));  
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==6 && beep1==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 1 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Beep:   Yes  >No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==6 && beep1==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 1 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Beep:  >Yes   No"));  
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==7 && relay4_1==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 1 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Relay1: Yes  >No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==7 && relay4_1==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 1 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Relay1:>Yes   No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==8 && relay5_1==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 1 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Relay2: Yes  >No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==8 && relay5_1==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 1 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Relay2:>Yes   No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==9){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step 1 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("RPM CH1: "));
     lcd.print(rpm1_1);
     lcd.print(F("      "));
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==10 && way1_1==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 1 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH1: CCW >CW")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==10 && way1_1==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 1 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH1:>CCW  CW")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==11){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step 1 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("RPM CH2: "));
     lcd.print(rpm2_1);
     lcd.print(F("      "));
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==12 && way2_1==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 1 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH2: CCW >CW")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==12 && way2_1==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 1 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH2:>CCW  CW")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==13){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step 1 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("RPM CH3: "));
     lcd.print(rpm3_1);
     lcd.print(F("      "));
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==14 && way3_1==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 1 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH3: CCW >CW")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==14 && way3_1==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 1 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH3:>CCW  CW")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==15){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step 1 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("RPM CH4: "));
     lcd.print(rpm4_1);
     lcd.print(F("      "));
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==16 && way4_1==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 1 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH4: CCW >CW")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==16 && way4_1==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 1 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH4:>CCW  CW")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
  
     else if (tela==17){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step 2 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Time: "));
     lcd.print(time2);
     lcd.print(F("          "));
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }    
     else if (tela==18 && relay1_2==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 2 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Read:   Yes  >No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==18 && relay1_2==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 2 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Read:  >Yes   No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==19 && relay2_2==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 2 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Valve:  Yes  >No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==19 && relay2_2==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 2 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Valve: >Yes   No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==20 && relay3_2==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 2 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Heat:   Yes  >No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==20 && relay3_2==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 2 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Heat:  >Yes   No"));  
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==21 && beep2==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 2 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Beep:   Yes  >No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==21 && beep2==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 2 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Beep:  >Yes   No"));  
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==22 && relay4_2==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 2 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Relay1: Yes  >No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==22 && relay4_2==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 2 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Relay1:>Yes   No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==23 && relay5_2==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 2 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Relay2: Yes  >No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==23 && relay5_2==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 2 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Relay2:>Yes   No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==24){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step 2 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("RPM CH1: "));
     lcd.print(rpm1_2);
     lcd.print(F("      "));
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==25 && way1_2==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 2 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH1: CCW >CW")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==25 && way1_2==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 2 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH1:>CCW  CW")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==26){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step 2 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("RPM CH2: "));
     lcd.print(rpm2_2);
     lcd.print(F("      "));
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==27 && way2_2==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 2 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH2: CCW >CW")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==27 && way2_2==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 2 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH2:>CCW  CW")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==28){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step 2 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("RPM CH3: "));
     lcd.print(rpm3_2);
     lcd.print(F("      "));
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==29 && way3_2==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 2 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH3: CCW >CW")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==29 && way3_2==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 2 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH3:>CCW  CW")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==30){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step 2 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("RPM CH4: "));
     lcd.print(rpm4_2);
     lcd.print(F("      "));
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==31 && way4_2==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 2 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH4: CCW >CW")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==31 && way4_2==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 2 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH4:>CCW  CW")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
  
     else if (tela==32){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step 3 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Time: "));
     lcd.print(time3);
     lcd.print(F("          "));
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }    
     else if (tela==33 && relay1_3==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 3 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Read:   Yes  >No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==33 && relay1_3==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 3 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Read:  >Yes   No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==34 && relay2_3==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 3 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Valve:  Yes  >No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==34 && relay2_3==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 3 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Valve: >Yes   No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==35 && relay3_3==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 3 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Heat:   Yes  >No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==35 && relay3_3==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 3 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Heat:  >Yes   No"));  
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==36 && beep3==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 3 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Beep:   Yes  >No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==36 && beep3==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 3 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Beep:  >Yes   No"));  
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==37 && relay4_3==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 3 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Relay1: Yes  >No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==37 && relay4_3==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 3 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Relay1:>Yes   No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==38 && relay5_3==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 3 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Relay2: Yes  >No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==38 && relay5_3==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 3 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Relay2:>Yes   No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==39){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step 3 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("RPM CH1: "));
     lcd.print(rpm1_3);
     lcd.print(F("      "));
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==40 && way1_3==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 3 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH1: CCW >CW")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==40 && way1_3==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 3 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH1:>CCW  CW")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==41){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step 3 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("RPM CH2: "));
     lcd.print(rpm2_3);
     lcd.print(F("      "));
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==42 && way2_3==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 3 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH2: CCW >CW")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==42 && way2_3==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 3 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH2:>CCW  CW")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==43){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step 3 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("RPM CH3: "));
     lcd.print(rpm3_3);
     lcd.print(F("      "));
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==44 && way3_3==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 3 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH3: CCW >CW")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==44 && way3_3==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 3 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH3:>CCW  CW")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==45){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step 3 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("RPM CH4: "));
     lcd.print(rpm4_3);
     lcd.print(F("      "));
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==46 && way4_3==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 3 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH4: CCW >CW")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==46 && way4_3==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 3 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH4:>CCW  CW")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
  
     else if (tela==47){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step 4 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Time: "));
     lcd.print(time4);
     lcd.print(F("          "));
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }    
     else if (tela==48 && relay1_4==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 4 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Read:   Yes  >No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==48 && relay1_4==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 4 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Read:  >Yes   No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==49 && relay2_4==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 4 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Valve:  Yes  >No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==49 && relay2_4==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 4 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Valve: >Yes   No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==50 && relay3_4==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 4 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Heat:   Yes  >No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==50 && relay3_4==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 4 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Heat:  >Yes   No"));  
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==51 && beep4==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 4 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Beep:   Yes  >No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==51 && beep4==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 4 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Beep:  >Yes   No"));  
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==52 && relay4_4==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 4 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Relay1: Yes  >No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==52 && relay4_4==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 4 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Relay1:>Yes   No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==53 && relay5_4==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 4 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Relay2: Yes  >No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==53 && relay5_4==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 4 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Relay2:>Yes   No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==54){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step 4 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("RPM CH1: "));
     lcd.print(rpm1_4);
     lcd.print(F("      "));
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==55 && way1_4==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 4 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH1: CCW >CW")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==55 && way1_4==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 4 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH1:>CCW  CW")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==56){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step 4 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("RPM CH2: "));
     lcd.print(rpm2_4);
     lcd.print(F("      "));
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==57 && way2_4==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 4 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH2: CCW >CW")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==57 && way2_4==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 4 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH2:>CCW  CW")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==58){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step 4 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("RPM CH3: "));
     lcd.print(rpm3_4);
     lcd.print(F("      "));
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==59 && way3_4==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 4 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH3: CCW >CW")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==59 && way3_4==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 4 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH3:>CCW  CW")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==60){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step 4 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("RPM CH4: "));
     lcd.print(rpm4_4);
     lcd.print(F("      "));
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==61 && way4_4==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 4 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH4: CCW >CW")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==61 && way4_4==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 4 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH4:>CCW  CW")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
  
     else if (tela==62){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step 5 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Time: "));
     lcd.print(time5);
     lcd.print(F("          "));
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }    
     else if (tela==63 && relay1_5==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 5 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Read:   Yes  >No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==63 && relay1_5==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 5 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Read:  >Yes   No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==64 && relay2_5==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 5 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Valve:  Yes  >No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==64 && relay2_5==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 5 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Valve: >Yes   No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==65 && relay3_5==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 5 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Heat:   Yes  >No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==65 && relay3_5==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 5 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Heat:  >Yes   No"));  
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==66 && beep5==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 5 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Beep:   Yes  >No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==66 && beep5==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 5 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Beep:  >Yes   No"));  
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==67 && relay4_5==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 5 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Relay1: Yes  >No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==67 && relay4_5==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 5 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Relay1:>Yes   No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==68 && relay5_5==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 5 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Relay2: Yes  >No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==68 && relay5_5==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 5 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Relay2:>Yes   No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==69){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step 5 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("RPM CH1: "));
     lcd.print(rpm1_5);
     lcd.print(F("      "));
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==70 && way1_5==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 5 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH1: CCW >CW")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==70 && way1_5==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 5 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH1:>CCW  CW")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==71){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step 5 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("RPM CH2: "));
     lcd.print(rpm2_5);
     lcd.print(F("      "));
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==72 && way2_5==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 5 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH2: CCW >CW")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==72 && way2_5==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 5 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH2:>CCW  CW")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==73){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step 5 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("RPM CH3: "));
     lcd.print(rpm3_5);
     lcd.print(F("      "));
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==74 && way3_5==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 5 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH3: CCW >CW")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==74 && way3_5==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 5 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH3:>CCW  CW")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==75){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step 5 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("RPM CH4: "));
     lcd.print(rpm4_5);
     lcd.print(F("      "));
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==76 && way4_5==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 5 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH4: CCW >CW")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==76 && way4_5==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 5 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH4:>CCW  CW")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
  
     else if (tela==77){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step 6 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Time: "));
     lcd.print(time6);
     lcd.print(F("          "));
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }    
     else if (tela==78 && relay1_6==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 6 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Read:   Yes  >No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==78 && relay1_6==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 6 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Read:  >Yes   No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==79 && relay2_6==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 6 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Valve:  Yes  >No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==79 && relay2_6==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 6 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Valve: >Yes   No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==80 && relay3_6==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 6 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Heat:   Yes  >No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==80 && relay3_6==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 6 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Heat:  >Yes   No"));  
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==81 && beep6==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 6 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Beep:   Yes  >No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==81 && beep6==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 6 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Beep:  >Yes   No"));  
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==82 && relay4_6==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 6 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Relay1: Yes  >No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==82 && relay4_6==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 6 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Relay1:>Yes   No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==83 && relay5_6==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 6 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Relay2: Yes  >No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==83 && relay5_6==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 6 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Relay2:>Yes   No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==84){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step 6 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("RPM CH1: "));
     lcd.print(rpm1_6);
     lcd.print(F("      "));
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==85 && way1_6==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 6 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH1: CCW >CW")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==85 && way1_6==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 6 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH1:>CCW  CW")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==86){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step 6 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("RPM CH2: "));
     lcd.print(rpm2_6);
     lcd.print(F("      "));
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==87 && way2_6==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 6 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH2: CCW >CW")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==87 && way2_6==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 6 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH2:>CCW  CW")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==88){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step 6 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("RPM CH3: "));
     lcd.print(rpm3_6);
     lcd.print(F("      "));
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==89 && way3_6==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 6 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH3: CCW >CW")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==89 && way3_6==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 6 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH3:>CCW  CW")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==90){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step 6 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("RPM CH4: "));
     lcd.print(rpm4_6);
     lcd.print(F("      "));
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==91 && way4_6==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 6 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH4: CCW >CW")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==91 && way4_6==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 6 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH4:>CCW  CW")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
  
     else if (tela==92){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step 7 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Time: "));
     lcd.print(time7);
     lcd.print(F("          "));
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }    
     else if (tela==93 && relay1_7==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 7 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Read:   Yes  >No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==93 && relay1_7==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 7 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Read:  >Yes   No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==94 && relay2_7==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 7 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Valve:  Yes  >No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==94 && relay2_7==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 7 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Valve: >Yes   No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==95 && relay3_7==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 7 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Heat:   Yes  >No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==95 && relay3_7==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 7 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Heat:  >Yes   No"));  
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==96 && beep7==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 7 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Beep:   Yes  >No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==96 && beep7==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 7 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Beep:  >Yes   No"));  
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==97 && relay4_7==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 7 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Relay1: Yes  >No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==97 && relay4_7==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 7 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Relay1:>Yes   No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==98 && relay5_7==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 7 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Relay2: Yes  >No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==98 && relay5_7==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 7 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Relay2:>Yes   No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==99){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step 7 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("RPM CH1: "));
     lcd.print(rpm1_7);
     lcd.print(F("      "));
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==100 && way1_7==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 7 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH1: CCW >CW")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==100 && way1_7==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 7 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH1:>CCW  CW")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==101){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step 7 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("RPM CH2: "));
     lcd.print(rpm2_7);
     lcd.print(F("      "));
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==102 && way2_7==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 7 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH2: CCW >CW")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==102 && way2_7==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 7 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH2:>CCW  CW")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==103){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step 7 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("RPM CH3: "));
     lcd.print(rpm3_7);
     lcd.print(F("      "));
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==104 && way3_7==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 7 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH3: CCW >CW")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==104 && way3_7==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 7 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH3:>CCW  CW")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==105){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step 7 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("RPM CH4: "));
     lcd.print(rpm4_7);
     lcd.print(F("      "));
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==106 && way4_7==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 7 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH4: CCW >CW")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==106 && way4_7==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 7 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH4:>CCW  CW")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
  
     else if (tela==107){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step 8 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Time: "));
     lcd.print(time8);
     lcd.print(F("          "));
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }    
     else if (tela==108 && relay1_8==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 8 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Read:   Yes  >No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==108 && relay1_8==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 8 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Read:  >Yes   No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==109 && relay2_8==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 8 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Valve:  Yes  >No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==109 && relay2_8==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 8 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Valve: >Yes   No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==110 && relay3_8==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 8 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Heat:   Yes  >No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==110 && relay3_8==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 8 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Heat:  >Yes   No"));  
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==111 && beep8==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 8 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Beep:   Yes  >No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==111 && beep8==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 8 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Beep:  >Yes   No"));  
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==112 && relay4_8==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 8 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Relay1: Yes  >No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==112 && relay4_8==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 8 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Relay1:>Yes   No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==113 && relay5_8==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 8 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Relay2: Yes  >No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==113 && relay5_8==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 8 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Relay2:>Yes   No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==114){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step 8 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("RPM CH1: "));
     lcd.print(rpm1_8);
     lcd.print(F("      "));
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==115 && way1_8==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 8 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH1: CCW >CW")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==115 && way1_8==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 8 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH1:>CCW  CW")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==116){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step 8 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("RPM CH2: "));
     lcd.print(rpm2_8);
     lcd.print(F("      "));
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==117 && way2_8==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 8 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH2: CCW >CW")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==117 && way2_8==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 8 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH2:>CCW  CW")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==118){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step 8 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("RPM CH3: "));
     lcd.print(rpm3_8);
     lcd.print(F("      "));
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==119 && way3_8==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 8 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH3: CCW >CW")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==119 && way3_8==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 8 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH3:>CCW  CW")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==120){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step 8 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("RPM CH4: "));
     lcd.print(rpm4_8);
     lcd.print(F("      "));
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==121 && way4_8==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 8 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH4: CCW >CW")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==121 && way4_8==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 8 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH4:>CCW  CW")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
  
     else if (tela==122){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step 9 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Time: "));
     lcd.print(time9);
     lcd.print(F("          "));
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }    
     else if (tela==123 && relay1_9==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 9 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Read:   Yes  >No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==123 && relay1_9==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 9 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Read:  >Yes   No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==124 && relay2_9==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 9 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Valve:  Yes  >No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==124 && relay2_9==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 9 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Valve: >Yes   No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==125 && relay3_9==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 9 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Heat:   Yes  >No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==125 && relay3_9==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 9 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Heat:  >Yes   No"));  
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==126 && beep9==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 9 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Beep:   Yes  >No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==126 && beep9==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 9 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Beep:  >Yes   No"));  
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==127 && relay4_9==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 9 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Relay1: Yes  >No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==127 && relay4_9==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 9 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Relay1:>Yes   No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==128 && relay5_9==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 9 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Relay2: Yes  >No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==128 && relay5_9==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 9 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Relay2:>Yes   No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==129){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step 9 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("RPM CH1: "));
     lcd.print(rpm1_9);
     lcd.print(F("      "));
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==130 && way1_9==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 9 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH1: CCW >CW")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==130 && way1_9==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 9 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH1:>CCW  CW")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==131){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step 9 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("RPM CH2: "));
     lcd.print(rpm2_9);
     lcd.print(F("      "));
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==132 && way2_9==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 9 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH2: CCW >CW")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==132 && way2_9==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 9 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH2:>CCW  CW")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==133){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step 9 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("RPM CH3: "));
     lcd.print(rpm3_9);
     lcd.print(F("      "));
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==134 && way3_9==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 9 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH3: CCW >CW")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==134 && way3_9==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 9 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH3:>CCW  CW")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==135){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step 9 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("RPM CH4: "));
     lcd.print(rpm4_9);
     lcd.print(F("      "));
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==136 && way4_9==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 9 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH4: CCW >CW")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==136 && way4_9==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step 9 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH4:>CCW  CW")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
  
     else if (tela==137){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step10 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Time: "));
     lcd.print(time10);
     lcd.print(F("          "));
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }    
     else if (tela==138 && relay1_10==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step10 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Read:   Yes  >No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==138 && relay1_10==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step10 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Read:  >Yes   No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==139 && relay2_10==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step10 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Valve:  Yes  >No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==139 && relay2_10==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step10 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Valve: >Yes   No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==140 && relay3_10==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step10 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Heat:   Yes  >No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==140 && relay3_10==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step10 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Heat:  >Yes   No"));  
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==141 && beep10==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step10 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Beep:   Yes  >No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==141 && beep10==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step10 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Beep:  >Yes   No"));  
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==142 && relay4_10==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step10 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Relay1: Yes  >No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==142 && relay4_10==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step10 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Relay1:>Yes   No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==143 && relay5_10==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step10 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Relay2: Yes  >No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==143 && relay5_10==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step10 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Relay2:>Yes   No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==144){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step10 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("RPM CH1: "));
     lcd.print(rpm1_10);
     lcd.print(F("      "));
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==145 && way1_10==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step10 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH1: CCW >CW")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==145 && way1_10==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step10 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH1:>CCW  CW")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==146){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step10 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("RPM CH2: "));
     lcd.print(rpm2_10);
     lcd.print(F("      "));
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==147 && way2_10==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step10 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH2: CCW >CW")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==147 && way2_10==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step10 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH2:>CCW  CW")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==148){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step10 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("RPM CH3: "));
     lcd.print(rpm3_10);
     lcd.print(F("      "));
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==149 && way3_10==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step10 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH3: CCW >CW")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==149 && way3_10==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step10 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH3:>CCW  CW")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==150){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step10 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("RPM CH4: "));
     lcd.print(rpm4_10);
     lcd.print(F("      "));
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==151 && way4_10==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step10 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH4: CCW >CW")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==151 && way4_10==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step10 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH4:>CCW  CW")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
  
     else if (tela==152){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step11 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Time: "));
     lcd.print(time11);
     lcd.print(F("          "));
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }    
     else if (tela==153 && relay1_11==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step11 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Read:   Yes  >No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==153 && relay1_11==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step11 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Read:  >Yes   No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==154 && relay2_11==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step11 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Valve:  Yes  >No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==154 && relay2_11==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step11 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Valve: >Yes   No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==155 && relay3_11==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step11 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Heat:   Yes  >No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==155 && relay3_11==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step11 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Heat:  >Yes   No"));  
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==156 && beep11==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step11 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Beep:   Yes  >No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==156 && beep11==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step11 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Beep:  >Yes   No"));  
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==157 && relay4_11==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step11 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Relay1: Yes  >No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==157 && relay4_11==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step11 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Relay1:>Yes   No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==158 && relay5_11==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step11 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Relay2: Yes  >No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==158 && relay5_11==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step11 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Relay2:>Yes   No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==159){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step11 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("RPM CH1: "));
     lcd.print(rpm1_11);
     lcd.print(F("      "));
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==160 && way1_11==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step11 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH1: CCW >CW")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==160 && way1_11==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step11 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH1:>CCW  CW")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==161){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step11 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("RPM CH2: "));
     lcd.print(rpm2_11);
     lcd.print(F("      "));
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==162 && way2_11==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step11 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH2: CCW >CW")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==162 && way2_11==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step11 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH2:>CCW  CW")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==163){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step11 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("RPM CH3: "));
     lcd.print(rpm3_11);
     lcd.print(F("      "));
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==164 && way3_11==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step11 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH3: CCW >CW")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==164 && way3_11==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step11 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH3:>CCW  CW")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==165){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step11 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("RPM CH4: "));
     lcd.print(rpm4_11);
     lcd.print(F("      "));
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==166 && way4_11==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step11 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH4: CCW >CW")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==166   && way4_11==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step11 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH4:>CCW  CW")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
  
     else if (tela==167){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step12 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Time: "));
     lcd.print(time12);
     lcd.print(F("          "));
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }    
     else if (tela==168 && relay1_12==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step12 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Read:   Yes  >No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==168 && relay1_12==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step12 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Read:  >Yes   No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==169 && relay2_12==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step12 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Valve:  Yes  >No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==169 && relay2_12==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step12 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Valve: >Yes   No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==170 && relay3_12==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step12 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Heat:   Yes  >No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==170 && relay3_12==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step12 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Heat:  >Yes   No"));  
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==171 && beep12==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step12 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Beep:   Yes  >No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==171 && beep12==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step12 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Beep:  >Yes   No"));  
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==172 && relay4_12==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step12 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Relay1: Yes  >No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==172 && relay4_12==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step12 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Relay1:>Yes   No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==173 && relay5_12==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step12 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Relay2: Yes  >No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==173 && relay5_12==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step12 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Relay2:>Yes   No")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==174){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step12 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("RPM CH1: "));
     lcd.print(rpm1_12);
     lcd.print(F("      "));
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==175 && way1_12==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step12 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH1: CCW >CW")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==175 && way1_12==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step12 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH1:>CCW  CW")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==176){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step12 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("RPM CH2: "));
     lcd.print(rpm2_12);
     lcd.print(F("      "));
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==177 && way2_12==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step12 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH2: CCW >CW")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==177 && way2_12==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step12 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH2:>CCW  CW")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==178){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step12 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("RPM CH3: "));
     lcd.print(rpm3_12);
     lcd.print(F("      "));
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==179 && way3_12==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step12 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH3: CCW >CW")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==179 && way3_12==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step12 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH3:>CCW  CW")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==180){   
     lcd.setCursor(0,0);                                
     lcd.print(F("==== Step12 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("RPM CH4: "));
     lcd.print(rpm4_12);
     lcd.print(F("      "));
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==181 && way4_12==0){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step12 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH4: CCW >CW")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }
     else if (tela==181 && way4_12==1){    
     lcd.setCursor(0,0);                             
     lcd.print(F("==== Step12 ===="));       
     lcd.setCursor(0,1);                    
     lcd.print(F("Way CH4:>CCW  CW")); 
     L_botao_VOLTAR = digitalRead(buttonBack); if (L_botao_VOLTAR && !LA_botao_VOLTAR) { tela--; lcd.clear(); } LA_botao_VOLTAR = L_botao_VOLTAR; }

     
  
  
  
  // === ACTIONS OF THE button PLUS === //     
  L_botao_MAIS = digitalRead(buttonCancel);
  if (!L_botao_MAIS && LA_botao_MAIS) {
            if (tela==2){time1++;
       delay(200); 
       while (digitalRead(buttonCancel) == LOW) {
       time1++; q++;    
       lcd.setCursor(6,1); lcd.print(time1); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonCancel) == HIGH){q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonCancel) == LOW) {
       time1++;
       lcd.setCursor(6,1); lcd.print(time1); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonCancel) == HIGH) {q=0; break;}
       }}}}
       else if (tela==3 && relay1_1==1) {relay1_1=0;}
       else if (tela==4 && relay2_1==1) {relay2_1=0;}
       else if (tela==5 && relay3_1==1) {relay3_1=0;}
       else if (tela==6 && beep1==1) {beep1=0;}
       else if (tela==7 && relay4_1==1) {relay4_1=0;}
       else if (tela==8 && relay5_1==1) {relay5_1=0;}
       else if (tela==9 && rpm1_1 < 100) {rpm1_1++;
       delay(200); 
       while (digitalRead(buttonCancel) == LOW && rpm1_1 < 100) {
       rpm1_1++; q++;    
       lcd.setCursor(9,1); lcd.print(rpm1_1); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonCancel) == HIGH){q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonCancel) == LOW && rpm1_1 < 100) {
       rpm1_1++;
       lcd.setCursor(9,1); lcd.print(rpm1_1); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonCancel) == HIGH) {q=0; break;}
       }}}}
       else if (tela==10 && way1_1==1) {way1_1=0;}
       else if (tela==11 && rpm2_1 < 100) {rpm2_1++;
       delay(200); 
       while (digitalRead(buttonCancel) == LOW && rpm2_1 < 100) {
       rpm2_1++; q++;    
       lcd.setCursor(9,1); lcd.print(rpm2_1); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonCancel) == HIGH){q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonCancel) == LOW && rpm2_1 < 100) {
       rpm2_1++;
       lcd.setCursor(9,1); lcd.print(rpm2_1); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonCancel) == HIGH) {q=0; break;}
       }}}}
       else if (tela==12 && way2_1==1) {way2_1=0;}
       else if (tela==13 && rpm3_1 < 100) {rpm3_1++;
       delay(200); 
       while (digitalRead(buttonCancel) == LOW && rpm3_1 < 100) {
       rpm3_1++; q++;    
       lcd.setCursor(9,1); lcd.print(rpm3_1); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonCancel) == HIGH){q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonCancel) == LOW && rpm3_1 < 100) {
       rpm3_1++;
       lcd.setCursor(9,1); lcd.print(rpm3_1); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonCancel) == HIGH) {q=0; break;}
       }}}}
       else if (tela==14 && way3_1==1) {way3_1=0;}
       else if (tela==15 && rpm4_1 < 100) {rpm4_1++;
       delay(200); 
       while (digitalRead(buttonCancel) == LOW && rpm4_1 < 100) {
       rpm4_1++; q++;    
       lcd.setCursor(9,1); lcd.print(rpm4_1); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonCancel) == HIGH){q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonCancel) == LOW && rpm4_1 < 100) {
       rpm4_1++;
       lcd.setCursor(9,1); lcd.print(rpm4_1); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonCancel) == HIGH) {q=0; break;}
       }}}}
       else if (tela==16 && way4_1==1) {way4_1=0;}

       else if (tela==17){time2++;
       delay(200); 
       while (digitalRead(buttonCancel) == LOW) {
       time2++; q++;    
       lcd.setCursor(6,1); lcd.print(time2); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonCancel) == HIGH){q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonCancel) == LOW) {
       time2++;
       lcd.setCursor(6,1); lcd.print(time2); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonCancel) == HIGH) {q=0; break;}
       }}}}
       else if (tela==18 && relay1_2==1) {relay1_2=0;}
       else if (tela==19 && relay2_2==1) {relay2_2=0;}
       else if (tela==20 && relay3_2==1) {relay3_2=0;}
       else if (tela==21 && beep2==1) {beep2=0;}
       else if (tela==22 && relay4_2==1) {relay4_2=0;}
       else if (tela==23 && relay5_2==1) {relay5_2=0;}
       else if (tela==24 && rpm1_2 < 100) {rpm1_2++;
       delay(200); 
       while (digitalRead(buttonCancel) == LOW && rpm1_2 < 100) {
       rpm1_2++; q++;    
       lcd.setCursor(9,1); lcd.print(rpm1_2); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonCancel) == HIGH){q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonCancel) == LOW && rpm1_2 < 100) {
       rpm1_2++;
       lcd.setCursor(9,1); lcd.print(rpm1_2); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonCancel) == HIGH) {q=0; break;}
       }}}}
       else if (tela==25 && way1_2==1) {way1_2=0;}
       else if (tela==26 && rpm2_2 < 100) {rpm2_2++;
       delay(200); 
       while (digitalRead(buttonCancel) == LOW && rpm2_2 < 100) {
       rpm2_2++; q++;    
       lcd.setCursor(9,1); lcd.print(rpm2_2); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonCancel) == HIGH){q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonCancel) == LOW && rpm2_2 < 100) {
       rpm2_2++;
       lcd.setCursor(9,1); lcd.print(rpm2_2); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonCancel) == HIGH) {q=0; break;}
       }}}}
       else if (tela==27 && way2_2==1) {way2_2=0;}
       else if (tela==28 && rpm3_2 < 100) {rpm3_2++;
       delay(200); 
       while (digitalRead(buttonCancel) == LOW && rpm3_2 < 100) {
       rpm3_2++; q++;    
       lcd.setCursor(9,1); lcd.print(rpm3_2); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonCancel) == HIGH){q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonCancel) == LOW && rpm3_2 < 100) {
       rpm3_2++;
       lcd.setCursor(9,1); lcd.print(rpm3_2); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonCancel) == HIGH) {q=0; break;}
       }}}}
       else if (tela==29 && way3_2==1) {way3_2=0;}
       else if (tela==30 && rpm4_2 < 100) {rpm4_2++;
       delay(200); 
       while (digitalRead(buttonCancel) == LOW && rpm4_2 < 100) {
       rpm4_2++; q++;    
       lcd.setCursor(9,1); lcd.print(rpm4_2); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonCancel) == HIGH){q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonCancel) == LOW && rpm4_2 < 100) {
       rpm4_2++;
       lcd.setCursor(9,1); lcd.print(rpm4_2); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonCancel) == HIGH) {q=0; break;}
       }}}}
       else if (tela==31 && way4_2==1) {way4_2=0;}

       else if (tela==32){time3++;
       delay(200); 
       while (digitalRead(buttonCancel) == LOW) {
       time3++; q++;    
       lcd.setCursor(6,1); lcd.print(time3); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonCancel) == HIGH){q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonCancel) == LOW) {
       time3++;
       lcd.setCursor(6,1); lcd.print(time3); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonCancel) == HIGH) {q=0; break;}
       }}}}
       else if (tela==33 && relay1_3==1) {relay1_3=0;}
       else if (tela==34 && relay2_3==1) {relay2_3=0;}
       else if (tela==35 && relay3_3==1) {relay3_3=0;}
       else if (tela==36 && beep3==1) {beep3=0;}
       else if (tela==37 && relay4_3==1) {relay4_3=0;}
       else if (tela==38 && relay5_3==1) {relay5_3=0;}
       else if (tela==39 && rpm1_3 < 100) {rpm1_3++;
       delay(200); 
       while (digitalRead(buttonCancel) == LOW && rpm1_3 < 100) {
       rpm1_3++; q++;    
       lcd.setCursor(9,1); lcd.print(rpm1_3); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonCancel) == HIGH){q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonCancel) == LOW && rpm1_3 < 100) {
       rpm1_3++;
       lcd.setCursor(9,1); lcd.print(rpm1_3); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonCancel) == HIGH) {q=0; break;}
       }}}}
       else if (tela==40 && way1_3==1) {way1_3=0;}
       else if (tela==41 && rpm2_3 < 100) {rpm2_3++;
       delay(200); 
       while (digitalRead(buttonCancel) == LOW && rpm2_3 < 100) {
       rpm2_3++; q++;    
       lcd.setCursor(9,1); lcd.print(rpm2_3); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonCancel) == HIGH){q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonCancel) == LOW && rpm2_3 < 100) {
       rpm2_3++;
       lcd.setCursor(9,1); lcd.print(rpm2_3); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonCancel) == HIGH) {q=0; break;}
       }}}}
       else if (tela==42 && way2_3==1) {way2_3=0;}
       else if (tela==43 && rpm3_3 < 100) {rpm3_3++;
       delay(200); 
       while (digitalRead(buttonCancel) == LOW && rpm3_3 < 100) {
       rpm3_3++; q++;    
       lcd.setCursor(9,1); lcd.print(rpm3_3); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonCancel) == HIGH){q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonCancel) == LOW && rpm3_3 < 100) {
       rpm3_3++;
       lcd.setCursor(9,1); lcd.print(rpm3_3); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonCancel) == HIGH) {q=0; break;}
       }}}}
       else if (tela==44 && way3_3==1) {way3_3=0;}
       else if (tela==45 && rpm4_3 < 100) {rpm4_3++;
       delay(200); 
       while (digitalRead(buttonCancel) == LOW && rpm4_3 < 100) {
       rpm4_3++; q++;    
       lcd.setCursor(9,1); lcd.print(rpm4_3); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonCancel) == HIGH){q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonCancel) == LOW && rpm4_3 < 100) {
       rpm4_3++;
       lcd.setCursor(9,1); lcd.print(rpm4_3); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonCancel) == HIGH) {q=0; break;}
       }}}}
       else if (tela==46 && way4_3==1) {way4_3=0;}

       else if (tela==47){time4++;
       delay(200); 
       while (digitalRead(buttonCancel) == LOW) {
       time4++; q++;    
       lcd.setCursor(6,1); lcd.print(time4); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonCancel) == HIGH){q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonCancel) == LOW) {
       time4++;
       lcd.setCursor(6,1); lcd.print(time4); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonCancel) == HIGH) {q=0; break;}
       }}}}
       else if (tela==48 && relay1_4==1) {relay1_4=0;}
       else if (tela==49 && relay2_4==1) {relay2_4=0;}
       else if (tela==50 && relay3_4==1) {relay3_4=0;}
       else if (tela==51 && beep4==1) {beep4=0;}
       else if (tela==52 && relay4_4==1) {relay4_4=0;}
       else if (tela==53 && relay5_4==1) {relay5_4=0;}
       else if (tela==54 && rpm1_4 < 100) {rpm1_4++;
       delay(200); 
       while (digitalRead(buttonCancel) == LOW && rpm1_4 < 100) {
       rpm1_4++; q++;    
       lcd.setCursor(9,1); lcd.print(rpm1_4); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonCancel) == HIGH){q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonCancel) == LOW && rpm1_4 < 100) {
       rpm1_4++;
       lcd.setCursor(9,1); lcd.print(rpm1_4); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonCancel) == HIGH) {q=0; break;}
       }}}}
       else if (tela==55 && way1_4==1) {way1_4=0;}
       else if (tela==56 && rpm2_4 < 100) {rpm2_4++;
       delay(200); 
       while (digitalRead(buttonCancel) == LOW && rpm2_4 < 100) {
       rpm2_4++; q++;    
       lcd.setCursor(9,1); lcd.print(rpm2_4); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonCancel) == HIGH){  q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonCancel) == LOW && rpm2_4 < 100) {
       rpm2_4++;
       lcd.setCursor(9,1); lcd.print(rpm2_4); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonCancel) == HIGH) {  q=0; break;}
       }}}}
       else if (tela==57 && way2_4==1) {way2_4=0;  }
       else if (tela==58 && rpm3_4 < 100) {rpm3_4++;  
       delay(200); 
       while (digitalRead(buttonCancel) == LOW && rpm3_4 < 100) {
       rpm3_4++; q++;    
       lcd.setCursor(9,1); lcd.print(rpm3_4); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonCancel) == HIGH){  q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonCancel) == LOW && rpm3_4 < 100) {
       rpm3_4++;
       lcd.setCursor(9,1); lcd.print(rpm3_4); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonCancel) == HIGH) {  q=0; break;}
       }}}}
       else if (tela==59 && way3_4==1) {way3_4=0;  }
       else if (tela==60 && rpm4_4 < 100) {rpm4_4++;  
       delay(200); 
       while (digitalRead(buttonCancel) == LOW && rpm4_4 < 100) {
       rpm4_4++; q++;    
       lcd.setCursor(9,1); lcd.print(rpm4_4); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonCancel) == HIGH){  q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonCancel) == LOW && rpm4_4 < 100) {
       rpm4_4++;
       lcd.setCursor(9,1); lcd.print(rpm4_4); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonCancel) == HIGH) {  q=0; break;}
       }}}}
       else if (tela==61 && way4_4==1) {way4_4=0;  }

       else if (tela==62){time5++;  
       delay(200); 
       while (digitalRead(buttonCancel) == LOW) {
       time5++; q++;    
       lcd.setCursor(6,1); lcd.print(time5); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonCancel) == HIGH){  q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonCancel) == LOW) {
       time5++;
       lcd.setCursor(6,1); lcd.print(time5); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonCancel) == HIGH) {  q=0; break;}
       }}}}
       else if (tela==63 && relay1_5==1) {relay1_5=0;  }
       else if (tela==64 && relay2_5==1) {relay2_5=0;  }
       else if (tela==65 && relay3_5==1) {relay3_5=0;  }
       else if (tela==66 && beep5==1) {beep5=0;}
       else if (tela==67 && relay4_5==1) {relay4_5=0;  }
       else if (tela==68 && relay5_5==1) {relay5_5=0;  }
       else if (tela==69 && rpm1_5 < 100) {rpm1_5++;  
       delay(200); 
       while (digitalRead(buttonCancel) == LOW && rpm1_5 < 100) {
       rpm1_5++; q++;    
       lcd.setCursor(9,1); lcd.print(rpm1_5); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonCancel) == HIGH){  q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonCancel) == LOW && rpm1_5 < 100) {
       rpm1_5++;
       lcd.setCursor(9,1); lcd.print(rpm1_5); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonCancel) == HIGH) {  q=0; break;}
       }}}}
       else if (tela==70 && way1_5==1) {way1_5=0;  }
       else if (tela==71 && rpm2_5 < 100) {rpm2_5++;  
       delay(200); 
       while (digitalRead(buttonCancel) == LOW && rpm2_5 < 100) {
       rpm2_5++; q++;    
       lcd.setCursor(9,1); lcd.print(rpm2_5); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonCancel) == HIGH){  q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonCancel) == LOW && rpm2_5 < 100) {
       rpm2_5++;
       lcd.setCursor(9,1); lcd.print(rpm2_5); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonCancel) == HIGH) {  q=0; break;}
       }}}}
       else if (tela==72 && way2_5==1) {way2_5=0;  }
       else if (tela==73 && rpm3_5 < 100) {rpm3_5++;  
       delay(200); 
       while (digitalRead(buttonCancel) == LOW && rpm3_5 < 100) {
       rpm3_5++; q++;    
       lcd.setCursor(9,1); lcd.print(rpm3_5); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonCancel) == HIGH){  q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonCancel) == LOW && rpm3_5 < 100) {
       rpm3_5++;
       lcd.setCursor(9,1); lcd.print(rpm3_5); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonCancel) == HIGH) {  q=0; break;}
       }}}}
       else if (tela==74 && way3_5==1) {way3_5=0;  }
       else if (tela==75 && rpm4_5 < 100) {rpm4_5++;  
       delay(200); 
       while (digitalRead(buttonCancel) == LOW && rpm4_5 < 100) {
       rpm4_5++; q++;    
       lcd.setCursor(9,1); lcd.print(rpm4_5); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonCancel) == HIGH){  q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonCancel) == LOW && rpm4_5 < 100) {
       rpm4_5++;
       lcd.setCursor(9,1); lcd.print(rpm4_5); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonCancel) == HIGH) {  q=0; break;}
       }}}}
       else if (tela==76 && way4_5==1) {way4_5=0;  }

       else if (tela==77){time6++;  
       delay(200); 
       while (digitalRead(buttonCancel) == LOW) {
       time6++; q++;    
       lcd.setCursor(6,1); lcd.print(time6); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonCancel) == HIGH){  q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonCancel) == LOW) {
       time6++;
       lcd.setCursor(6,1); lcd.print(time6); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonCancel) == HIGH) {  q=0; break;}
       }}}}
       else if (tela==78 && relay1_6==1) {relay1_6=0;  }
       else if (tela==79 && relay2_6==1) {relay2_6=0;  }
       else if (tela==80 && relay3_6==1) {relay3_6=0;  }
       else if (tela==81 && beep6==1) {beep6=0;}
       else if (tela==82 && relay4_6==1) {relay4_6=0;  }
       else if (tela==83 && relay5_6==1) {relay5_6=0;  }
       else if (tela==84 && rpm1_6 < 100) {rpm1_6++;  
       delay(200); 
       while (digitalRead(buttonCancel) == LOW && rpm1_6 < 100) {
       rpm1_6++; q++;    
       lcd.setCursor(9,1); lcd.print(rpm1_6); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonCancel) == HIGH){  q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonCancel) == LOW && rpm1_6 < 100) {
       rpm1_6++;
       lcd.setCursor(9,1); lcd.print(rpm1_6); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonCancel) == HIGH) {  q=0; break;}
       }}}}
       else if (tela==85 && way1_6==1) {way1_6=0;  }
       else if (tela==86 && rpm2_6 < 100) {rpm2_6++;  
       delay(200); 
       while (digitalRead(buttonCancel) == LOW && rpm2_6 < 100) {
       rpm2_6++; q++;    
       lcd.setCursor(9,1); lcd.print(rpm2_6); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonCancel) == HIGH){  q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonCancel) == LOW && rpm2_6 < 100) {
       rpm2_6++;
       lcd.setCursor(9,1); lcd.print(rpm2_6); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonCancel) == HIGH) {  q=0; break;}
       }}}}
       else if (tela==87 && way2_6==1) {way2_6=0;  }
       else if (tela==88 && rpm3_6 < 100) {rpm3_6++;  
       delay(200); 
       while (digitalRead(buttonCancel) == LOW && rpm3_6 < 100) {
       rpm3_6++; q++;    
       lcd.setCursor(9,1); lcd.print(rpm3_6); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonCancel) == HIGH){  q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonCancel) == LOW && rpm3_6 < 100) {
       rpm3_6++;
       lcd.setCursor(9,1); lcd.print(rpm3_6); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonCancel) == HIGH) {  q=0; break;}
       }}}}
       else if (tela==89 && way3_6==1) {way3_6=0;  }
       else if (tela==90 && rpm4_6 < 100) {rpm4_6++;  
       delay(200); 
       while (digitalRead(buttonCancel) == LOW && rpm4_6 < 100) {
       rpm4_6++; q++;    
       lcd.setCursor(9,1); lcd.print(rpm4_6); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonCancel) == HIGH){  q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonCancel) == LOW && rpm4_6 < 100) {
       rpm4_6++;
       lcd.setCursor(9,1); lcd.print(rpm4_6); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonCancel) == HIGH) {  q=0; break;}
       }}}}
       else if (tela==91 && way4_6==1) {way4_6=0;  }

       else if (tela==92){time7++;  
       delay(200); 
       while (digitalRead(buttonCancel) == LOW) {
       time7++; q++;    
       lcd.setCursor(6,1); lcd.print(time7); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonCancel) == HIGH){  q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonCancel) == LOW) {
       time7++;
       lcd.setCursor(6,1); lcd.print(time7); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonCancel) == HIGH) {  q=0; break;}
       }}}}
       else if (tela==93 && relay1_7==1) {relay1_7=0;  }
       else if (tela==94 && relay2_7==1) {relay2_7=0;  }
       else if (tela==95 && relay3_7==1) {relay3_7=0;  }
       else if (tela==96 && beep7==1) {beep7=0;}
       else if (tela==97 && relay4_7==1) {relay4_7=0;  }
       else if (tela==98 && relay5_7==1) {relay5_7=0;  }
       else if (tela==99 && rpm1_7 < 100) {rpm1_7++;  
       delay(200); 
       while (digitalRead(buttonCancel) == LOW && rpm1_7 < 100) {
       rpm1_7++; q++;    
       lcd.setCursor(9,1); lcd.print(rpm1_7); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonCancel) == HIGH){  q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonCancel) == LOW && rpm1_7 < 100) {
       rpm1_7++;
       lcd.setCursor(9,1); lcd.print(rpm1_7); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonCancel) == HIGH) {  q=0; break;}
       }}}}
       else if (tela==100 && way1_7==1) {way1_7=0;  }
       else if (tela==101 && rpm2_7 < 100) {rpm2_7++;  
       delay(200); 
       while (digitalRead(buttonCancel) == LOW && rpm2_7 < 100) {
       rpm2_7++; q++;    
       lcd.setCursor(9,1); lcd.print(rpm2_7); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonCancel) == HIGH){  q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonCancel) == LOW && rpm2_7 < 100) {
       rpm2_7++;
       lcd.setCursor(9,1); lcd.print(rpm2_7); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonCancel) == HIGH) {  q=0; break;}
       }}}}
       else if (tela==102 && way2_7==1) {way2_7=0;  }
       else if (tela==103 && rpm3_7 < 100) {rpm3_7++;  
       delay(200); 
       while (digitalRead(buttonCancel) == LOW && rpm3_7 < 100) {
       rpm3_7++; q++;    
       lcd.setCursor(9,1); lcd.print(rpm3_7); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonCancel) == HIGH){  q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonCancel) == LOW && rpm3_7 < 100) {
       rpm3_7++;
       lcd.setCursor(9,1); lcd.print(rpm3_7); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonCancel) == HIGH) {  q=0; break;}
       }}}}
       else if (tela==104 && way3_7==1) {way3_7=0;  }
       else if (tela==105 && rpm4_7 < 100) {rpm4_7++;  
       delay(200); 
       while (digitalRead(buttonCancel) == LOW && rpm4_7 < 100) {
       rpm4_7++; q++;    
       lcd.setCursor(9,1); lcd.print(rpm4_7); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonCancel) == HIGH){  q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonCancel) == LOW && rpm4_7 < 100) {
       rpm4_7++;
       lcd.setCursor(9,1); lcd.print(rpm4_7); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonCancel) == HIGH) {  q=0; break;}
       }}}}
       else if (tela==106 && way4_7==1) {way4_7=0;  }

       else if (tela==107){time8++;  
       delay(200); 
       while (digitalRead(buttonCancel) == LOW) {
       time8++; q++;    
       lcd.setCursor(6,1); lcd.print(time8); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonCancel) == HIGH){  q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonCancel) == LOW) {
       time8++;
       lcd.setCursor(6,1); lcd.print(time8); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonCancel) == HIGH) {  q=0; break;}
       }}}}
       else if (tela==108 && relay1_8==1) {relay1_8=0;  }
       else if (tela==109 && relay2_8==1) {relay2_8=0;  }
       else if (tela==110 && relay3_8==1) {relay3_8=0;  }
       else if (tela==111 && beep8==1) {beep8=0;}
       else if (tela==112 && relay4_8==1) {relay4_8=0;  }
       else if (tela==113 && relay5_8==1) {relay5_8=0;  }
       else if (tela==114 && rpm1_8 < 100) {rpm1_8++;  
       delay(200); 
       while (digitalRead(buttonCancel) == LOW && rpm1_8 < 100) {
       rpm1_8++; q++;    
       lcd.setCursor(9,1); lcd.print(rpm1_8); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonCancel) == HIGH){  q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonCancel) == LOW && rpm1_8 < 100) {
       rpm1_8++;
       lcd.setCursor(9,1); lcd.print(rpm1_8); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonCancel) == HIGH) {  q=0; break;}
       }}}}
       else if (tela==115 && way1_8==1) {way1_8=0;  }
       else if (tela==116 && rpm2_8 < 100) {rpm2_8++;  
       delay(200); 
       while (digitalRead(buttonCancel) == LOW && rpm2_8 < 100) {
       rpm2_8++; q++;    
       lcd.setCursor(9,1); lcd.print(rpm2_8); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonCancel) == HIGH){  q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonCancel) == LOW && rpm2_8 < 100) {
       rpm2_8++;
       lcd.setCursor(9,1); lcd.print(rpm2_8); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonCancel) == HIGH) {  q=0; break;}
       }}}}
       else if (tela==117 && way2_8==1) {way2_8=0;  }
       else if (tela==118 && rpm3_8 < 100) {rpm3_8++;  
       delay(200); 
       while (digitalRead(buttonCancel) == LOW && rpm3_8 < 100) {
       rpm3_8++; q++;    
       lcd.setCursor(9,1); lcd.print(rpm3_8); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonCancel) == HIGH){  q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonCancel) == LOW && rpm3_8 < 100) {
       rpm3_8++;
       lcd.setCursor(9,1); lcd.print(rpm3_8); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonCancel) == HIGH) {  q=0; break;}
       }}}}
       else if (tela==119 && way3_8==1) {way3_8=0;  }
       else if (tela==120 && rpm4_8 < 100) {rpm4_8++;  
       delay(200); 
       while (digitalRead(buttonCancel) == LOW && rpm4_8 < 100) {
       rpm4_8++; q++;    
       lcd.setCursor(9,1); lcd.print(rpm4_8); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonCancel) == HIGH){  q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonCancel) == LOW && rpm4_8 < 100) {
       rpm4_8++;
       lcd.setCursor(9,1); lcd.print(rpm4_8); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonCancel) == HIGH) {  q=0; break;}
       }}}}
       else if (tela==121 && way4_8==1) {way4_8=0;  }

       else if (tela==122){time9++;  
       delay(200); 
       while (digitalRead(buttonCancel) == LOW) {
       time9++; q++;    
       lcd.setCursor(6,1); lcd.print(time9); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonCancel) == HIGH){q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonCancel) == LOW) {
       time9++;
       lcd.setCursor(6,1); lcd.print(time9); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonCancel) == HIGH) {  q=0; break;}
       }}}}
       else if (tela==123 && relay1_9==1) {relay1_9=0;  }
       else if (tela==124 && relay2_9==1) {relay2_9=0;  }
       else if (tela==125 && relay3_9==1) {relay3_9=0;  }
       else if (tela==126 && beep9==1) {beep9=0;}
       else if (tela==127 && relay4_9==1) {relay4_9=0;  }
       else if (tela==128 && relay5_9==1) {relay5_9=0;  }
       else if (tela==129 && rpm1_9 < 100) {rpm1_9++;  
       delay(200); 
       while (digitalRead(buttonCancel) == LOW && rpm1_9 < 100) {
       rpm1_9++; q++;    
       lcd.setCursor(9,1); lcd.print(rpm1_9); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonCancel) == HIGH){  q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonCancel) == LOW && rpm1_9 < 100) {
       rpm1_9++;
       lcd.setCursor(9,1); lcd.print(rpm1_9); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonCancel) == HIGH) {  q=0; break;}
       }}}}
       else if (tela==130 && way1_9==1) {way1_9=0;  }
       else if (tela==131 && rpm2_9 < 100) {rpm2_9++;  
       delay(200); 
       while (digitalRead(buttonCancel) == LOW && rpm2_9 < 100) {
       rpm2_9++; q++;    
       lcd.setCursor(9,1); lcd.print(rpm2_9); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonCancel) == HIGH){  q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonCancel) == LOW && rpm2_9 < 100) {
       rpm2_9++;
       lcd.setCursor(9,1); lcd.print(rpm2_9); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonCancel) == HIGH) {  q=0; break;}
       }}}}
       else if (tela==132 && way2_9==1) {way2_9=0;  }
       else if (tela==133 && rpm3_9 < 100) {rpm3_9++;  
       delay(200); 
       while (digitalRead(buttonCancel) == LOW && rpm3_9 < 100) {
       rpm3_9++; q++;    
       lcd.setCursor(9,1); lcd.print(rpm3_9); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonCancel) == HIGH){  q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonCancel) == LOW && rpm3_9 < 100) {
       rpm3_9++;
       lcd.setCursor(9,1); lcd.print(rpm3_9); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonCancel) == HIGH) {  q=0; break;}
       }}}}
       else if (tela==134 && way3_9==1) {way3_9=0;  }
       else if (tela==135 && rpm4_9 < 100) {rpm4_9++;  
       delay(200); 
       while (digitalRead(buttonCancel) == LOW && rpm4_9 < 100) {
       rpm4_9++; q++;    
       lcd.setCursor(9,1); lcd.print(rpm4_9); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonCancel) == HIGH){  q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonCancel) == LOW && rpm4_9 < 100) {
       rpm4_9++;
       lcd.setCursor(9,1); lcd.print(rpm4_9); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonCancel) == HIGH) {  q=0; break;}
       }}}}
       else if (tela==136 && way4_9==1) {way4_9=0;  }

       else if (tela==137){time10++;  
       delay(200); 
       while (digitalRead(buttonCancel) == LOW) {
       time10++; q++;    
       lcd.setCursor(6,1); lcd.print(time10); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonCancel) == HIGH){  q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonCancel) == LOW) {
       time10++;
       lcd.setCursor(6,1); lcd.print(time10); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonCancel) == HIGH) {  q=0; break;}
       }}}}
       else if (tela==138 && relay1_10==1) {relay1_10=0;  }
       else if (tela==139 && relay2_10==1) {relay2_10=0;  }
       else if (tela==140 && relay3_10==1) {relay3_10=0;  }
       else if (tela==141 && beep10==1) {beep10=0;}
       else if (tela==142 && relay4_10==1) {relay4_10=0;  }
       else if (tela==143 && relay5_10==1) {relay5_10=0;  }
       else if (tela==144 && rpm1_10 < 100) {rpm1_10++;  
       delay(200); 
       while (digitalRead(buttonCancel) == LOW && rpm1_10 < 100) {
       rpm1_10++; q++;    
       lcd.setCursor(9,1); lcd.print(rpm1_10); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonCancel) == HIGH){  q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonCancel) == LOW && rpm1_10 < 100) {
       rpm1_10++;
       lcd.setCursor(9,1); lcd.print(rpm1_10); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonCancel) == HIGH) {  q=0; break;}
       }}}}
       else if (tela==145 && way1_10==1) {way1_10=0;  }
       else if (tela==146 && rpm2_10 < 100) {rpm2_10++;  
       delay(200); 
       while (digitalRead(buttonCancel) == LOW && rpm2_10 < 100) {
       rpm2_10++; q++;    
       lcd.setCursor(9,1); lcd.print(rpm2_10); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonCancel) == HIGH){  q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonCancel) == LOW && rpm2_10 < 100) {
       rpm2_10++;
       lcd.setCursor(9,1); lcd.print(rpm2_10); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonCancel) == HIGH) {  q=0; break;}
       }}}}
       else if (tela==147 && way2_10==1) {way2_10=0;  }
       else if (tela==148 && rpm3_10 < 100) {rpm3_10++;  
       delay(200); 
       while (digitalRead(buttonCancel) == LOW && rpm3_10 < 100) {
       rpm3_10++; q++;    
       lcd.setCursor(9,1); lcd.print(rpm3_10); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonCancel) == HIGH){  q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonCancel) == LOW && rpm3_10 < 100) {
       rpm3_10++;
       lcd.setCursor(9,1); lcd.print(rpm3_10); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonCancel) == HIGH) {  q=0; break;}
       }}}}
       else if (tela==149 && way3_10==1) {way3_10=0;  }
       else if (tela==150 && rpm4_10 < 100) {rpm4_10++;  
       delay(200); 
       while (digitalRead(buttonCancel) == LOW && rpm4_10 < 100) {
       rpm4_10++; q++;    
       lcd.setCursor(9,1); lcd.print(rpm4_10); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonCancel) == HIGH){  q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonCancel) == LOW && rpm4_10 < 100) {
       rpm4_10++;
       lcd.setCursor(9,1); lcd.print(rpm4_10); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonCancel) == HIGH) {  q=0; break;}
       }}}}
       else if (tela==151 && way4_10==1) {way4_10=0;  }

       else if (tela==152){time11++;  
       delay(200); 
       while (digitalRead(buttonCancel) == LOW) {
       time11++; q++;    
       lcd.setCursor(6,1); lcd.print(time11); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonCancel) == HIGH){  q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonCancel) == LOW) {
       time11++;
       lcd.setCursor(6,1); lcd.print(time11); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonCancel) == HIGH) {  q=0; break;}
       }}}}
       else if (tela==153 && relay1_11==1) {relay1_11=0;  }
       else if (tela==154 && relay2_11==1) {relay2_11=0;  }
       else if (tela==155 && relay3_11==1) {relay3_11=0;  }
       else if (tela==156 && beep11==1) {beep11=0;}
       else if (tela==157 && relay4_11==1) {relay4_11=0;  }
       else if (tela==158 && relay5_11==1) {relay5_11=0;  }
       else if (tela==159 && rpm1_11 < 100) {rpm1_11++;  
       delay(200); 
       while (digitalRead(buttonCancel) == LOW && rpm1_11 < 100) {
       rpm1_11++; q++;    
       lcd.setCursor(9,1); lcd.print(rpm1_11); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonCancel) == HIGH){  q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonCancel) == LOW && rpm1_11 < 100) {
       rpm1_11++;
       lcd.setCursor(9,1); lcd.print(rpm1_11); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonCancel) == HIGH) {  q=0; break;}
       }}}}
       else if (tela==160 && way1_11==1) {way1_11=0;  }
       else if (tela==161 && rpm2_11 < 100) {rpm2_11++;  
       delay(200); 
       while (digitalRead(buttonCancel) == LOW && rpm2_11 < 100) {
       rpm2_11++; q++;    
       lcd.setCursor(9,1); lcd.print(rpm2_11); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonCancel) == HIGH){  q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonCancel) == LOW && rpm2_11 < 100) {
       rpm2_11++;
       lcd.setCursor(9,1); lcd.print(rpm2_11); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonCancel) == HIGH) {  q=0; break;}
       }}}}
       else if (tela==162 && way2_11==1) {way2_11=0;  }
       else if (tela==163 && rpm3_11 < 100) {rpm3_11++;  
       delay(200); 
       while (digitalRead(buttonCancel) == LOW && rpm3_11 < 100) {
       rpm3_11++; q++;    
       lcd.setCursor(9,1); lcd.print(rpm3_11); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonCancel) == HIGH){  q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonCancel) == LOW && rpm3_11 < 100) {
       rpm3_11++;
       lcd.setCursor(9,1); lcd.print(rpm3_11); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonCancel) == HIGH) {  q=0; break;}
       }}}}
       else if (tela==164 && way3_11==1) {way3_11=0;  }
       else if (tela==165 && rpm4_11 < 100) {rpm4_11++;  
       delay(200); 
       while (digitalRead(buttonCancel) == LOW && rpm4_11 < 100) {
       rpm4_11++; q++;    
       lcd.setCursor(9,1); lcd.print(rpm4_11); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonCancel) == HIGH){  q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonCancel) == LOW && rpm4_11 < 100) {
       rpm4_11++;
       lcd.setCursor(9,1); lcd.print(rpm4_11); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonCancel) == HIGH) {  q=0; break;}
       }}}}
       else if (tela==166 && way4_11==1) {way4_11=0;  }

       else if (tela==167){time12++;  
       delay(200); 
       while (digitalRead(buttonCancel) == LOW) {
       time12++; q++;    
       lcd.setCursor(6,1); lcd.print(time12); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonCancel) == HIGH){  q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonCancel) == LOW) {
       time12++;
       lcd.setCursor(6,1); lcd.print(time12); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonCancel) == HIGH) {  q=0; break;}
       }}}}
       else if (tela==168 && relay1_12==1) {relay1_12=0;  }
       else if (tela==169 && relay2_12==1) {relay2_12=0;  }
       else if (tela==170 && relay3_12==1) {relay3_12=0;  }
       else if (tela==171 && beep12==1) {beep12=0;}
       else if (tela==172 && relay4_12==1) {relay4_12=0;  }
       else if (tela==173 && relay5_12==1) {relay5_12=0;  }
       else if (tela==174 && rpm1_12 < 100) {rpm1_12++;  
       delay(200); 
       while (digitalRead(buttonCancel) == LOW && rpm1_12 < 100) {
       rpm1_12++; q++;    
       lcd.setCursor(9,1); lcd.print(rpm1_12); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonCancel) == HIGH){  q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonCancel) == LOW && rpm1_12 < 100) {
       rpm1_12++;
       lcd.setCursor(9,1); lcd.print(rpm1_12); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonCancel) == HIGH) {  q=0; break;}
       }}}}
       else if (tela==175 && way1_12==1) {way1_12=0;  }
       else if (tela==176 && rpm2_12 < 100) {rpm2_12++;  
       delay(200); 
       while (digitalRead(buttonCancel) == LOW && rpm2_12 < 100) {
       rpm2_12++; q++;    
       lcd.setCursor(9,1); lcd.print(rpm2_12); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonCancel) == HIGH){  q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonCancel) == LOW && rpm2_12 < 100) {
       rpm2_12++;
       lcd.setCursor(9,1); lcd.print(rpm2_12); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonCancel) == HIGH) {  q=0; break;}
       }}}}
       else if (tela==177 && way2_12==1) {way2_12=0;  }
       else if (tela==178 && rpm3_12 < 100) {rpm3_12++;  
       delay(200); 
       while (digitalRead(buttonCancel) == LOW && rpm3_12 < 100) {
       rpm3_12++; q++;    
       lcd.setCursor(9,1); lcd.print(rpm3_12); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonCancel) == HIGH){  q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonCancel) == LOW && rpm3_12 < 100) {
       rpm3_12++;
       lcd.setCursor(9,1); lcd.print(rpm3_12); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonCancel) == HIGH) {  q=0; break;}
       }}}}
       else if (tela==179 && way3_12==1) {way3_12=0;  }
       else if (tela==180 && rpm4_12 < 100) {rpm4_12++;  
       delay(200); 
       while (digitalRead(buttonCancel) == LOW && rpm4_12 < 100) {
       rpm4_12++; q++;    
       lcd.setCursor(9,1); lcd.print(rpm4_12); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonCancel) == HIGH){  q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonCancel) == LOW && rpm4_12 < 100) {
       rpm4_12++;
       lcd.setCursor(9,1); lcd.print(rpm4_12); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonCancel) == HIGH) {  q=0; break;}
       }}}}
       else if (tela==181 && way4_12==1) {way4_12=0;  }

       delay(30);
       } LA_botao_MAIS = L_botao_MAIS ;
       
       

  // ===ACTIONS OF THE button MINUS === //   
  L_botao_MENOS = digitalRead(buttonStart);
  if (!L_botao_MENOS && LA_botao_MENOS) {
            if (tela==2){time1--;  
       delay(200); 
       while (digitalRead(buttonStart) == LOW) {
       time1--; q++;    
       lcd.setCursor(6,1); lcd.print(time1); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonStart) == HIGH){  q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonStart) == LOW) {
       time1--;
       lcd.setCursor(6,1); lcd.print(time1); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonStart) == HIGH) {  q=0; break;}
       }}}}
       else if (tela==3 && relay1_1==0) {relay1_1=1;  }
       else if (tela==4 && relay2_1==0) {relay2_1=1;  }
       else if (tela==5 && relay3_1==0) {relay3_1=1;  }
       else if (tela==6 && beep1==0) {beep1=1;  }
       else if (tela==7 && relay4_1==0) {relay4_1=1;  }
       else if (tela==8 && relay5_1==0) {relay5_1=1;  }
       else if (tela==9 && rpm1_1 > 0) {rpm1_1--;  
       delay(200); 
       while (digitalRead(buttonStart) == LOW && rpm1_1 > 0) {
       rpm1_1--; q++;    
       lcd.setCursor(9,1); lcd.print(rpm1_1); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonStart) == HIGH){  q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonStart) == LOW && rpm1_1 > 0) {
       rpm1_1--;
       lcd.setCursor(9,1); lcd.print(rpm1_1); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonStart) == HIGH) {  q=0; break;}
       }}}}
       else if (tela==10 && way1_1==0) {way1_1=1;  }
       else if (tela==11 && rpm2_1 > 0) {rpm2_1--;  
       delay(200); 
       while (digitalRead(buttonStart) == LOW && rpm2_1 > 0) {
       rpm2_1--; q++;    
       lcd.setCursor(9,1); lcd.print(rpm2_1); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonStart) == HIGH){  q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonStart) == LOW && rpm2_1 > 0) {
       rpm2_1--;
       lcd.setCursor(9,1); lcd.print(rpm2_1); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonStart) == HIGH) {  q=0; break;}
       }}}}
       else if (tela==12 && way2_1==0) {way2_1=1;  }
       else if (tela==13 && rpm3_1 > 0) {rpm3_1--;  
       delay(200); 
       while (digitalRead(buttonStart) == LOW && rpm3_1 > 0) {
       rpm3_1--; q++;    
       lcd.setCursor(9,1); lcd.print(rpm3_1); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonStart) == HIGH){  q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonStart) == LOW && rpm3_1 > 0) {
       rpm3_1--;
       lcd.setCursor(9,1); lcd.print(rpm3_1); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonStart) == HIGH) {  q=0; break;}
       }}}}
       else if (tela==14 && way3_1==0) {way3_1=1;  }
       else if (tela==15 && rpm4_1 > 0) {rpm4_1--;  
       delay(200); 
       while (digitalRead(buttonStart) == LOW && rpm4_1 > 0) {
       rpm4_1--; q++;    
       lcd.setCursor(9,1); lcd.print(rpm4_1); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonStart) == HIGH){  q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonStart) == LOW && rpm4_1 > 0) {
       rpm4_1--;
       lcd.setCursor(9,1); lcd.print(rpm4_1); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonStart) == HIGH) {  q=0; break;}
       }}}}
       else if (tela==16 && way4_1==0) {way4_1=1;  }

       else if (tela==17){time2--;  
       delay(200); 
       while (digitalRead(buttonStart) == LOW) {
       time2--; q++;    
       lcd.setCursor(6,1); lcd.print(time2); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonStart) == HIGH){  q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonStart) == LOW) {
       time2--;
       lcd.setCursor(6,1); lcd.print(time2); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonStart) == HIGH) {  q=0; break;}
       }}}}
       else if (tela==18 && relay1_2==0) {relay1_2=1;  }
       else if (tela==19 && relay2_2==0) {relay2_2=1;  }
       else if (tela==20 && relay3_2==0) {relay3_2=1;  }
       else if (tela==21 && beep2==0) {beep2=1;  }
       else if (tela==22 && relay4_2==0) {relay4_2=1;  }
       else if (tela==23 && relay5_2==0) {relay5_2=1;  }
       else if (tela==24 && rpm1_2 > 0) {rpm1_2--;  
       delay(200); 
       while (digitalRead(buttonStart) == LOW && rpm1_2 > 0) {
       rpm1_2--; q++;    
       lcd.setCursor(9,1); lcd.print(rpm1_2); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonStart) == HIGH){  q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonStart) == LOW && rpm1_2 > 0) {
       rpm1_2--;
       lcd.setCursor(9,1); lcd.print(rpm1_2); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonStart) == HIGH) {  q=0; break;}
       }}}}
       else if (tela==25 && way1_2==0) {way1_2=1;  }
       else if (tela==26 && rpm2_2 > 0) {rpm2_2--;  
       delay(200); 
       while (digitalRead(buttonStart) == LOW && rpm2_2 > 0) {
       rpm2_2--; q++;    
       lcd.setCursor(9,1); lcd.print(rpm2_2); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonStart) == HIGH){  q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonStart) == LOW && rpm2_2 > 0) {
       rpm2_2--;
       lcd.setCursor(9,1); lcd.print(rpm2_2); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonStart) == HIGH) {  q=0; break;}
       }}}}
       else if (tela==27 && way2_2==0) {way2_2=1;  }
       else if (tela==28 && rpm3_2 > 0) {rpm3_2--;  
       delay(200); 
       while (digitalRead(buttonStart) == LOW && rpm3_2 > 0) {
       rpm3_2--; q++;    
       lcd.setCursor(9,1); lcd.print(rpm3_2); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonStart) == HIGH){  q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonStart) == LOW && rpm3_2 > 0) {
       rpm3_2--;
       lcd.setCursor(9,1); lcd.print(rpm3_2); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonStart) == HIGH) { q=0; break;}
       }}}}
       else if (tela==29 && way3_2==0) {way3_2=1;  }
       else if (tela==30 && rpm4_2 > 0) {rpm4_2--;  
       delay(200); 
       while (digitalRead(buttonStart) == LOW && rpm4_2 > 0) {
       rpm4_2--; q++;    
       lcd.setCursor(9,1); lcd.print(rpm4_2); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonStart) == HIGH){  q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonStart) == LOW && rpm4_2 > 0) {
       rpm4_2--;
       lcd.setCursor(9,1); lcd.print(rpm4_2); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonStart) == HIGH) {  q=0; break;}
       }}}}
       else if (tela==31 && way4_2==0) {way4_2=1;  }

       else if (tela==32){time3--;  
       delay(200); 
       while (digitalRead(buttonStart) == LOW) {
       time3--; q++;    
       lcd.setCursor(6,1); lcd.print(time3); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonStart) == HIGH){  q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonStart) == LOW) {
       time3--;
       lcd.setCursor(6,1); lcd.print(time3); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonStart) == HIGH) {  q=0; break;}
       }}}}
       else if (tela==33 && relay1_3==0) {relay1_3=1;  }
       else if (tela==34 && relay2_3==0) {relay2_3=1;  }
       else if (tela==35 && relay3_3==0) {relay3_3=1;  }
       else if (tela==36 && beep3==0) {beep3=1;  }
       else if (tela==37 && relay4_3==0) {relay4_3=1;  }
       else if (tela==38 && relay5_3==0) {relay5_3=1;  }
       else if (tela==39 && rpm1_3 > 0) {rpm1_3--;  
       delay(200); 
       while (digitalRead(buttonStart) == LOW && rpm1_3 > 0) {
       rpm1_3--; q++;    
       lcd.setCursor(9,1); lcd.print(rpm1_3); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonStart) == HIGH){  q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonStart) == LOW && rpm1_3 > 0) {
       rpm1_3--;
       lcd.setCursor(9,1); lcd.print(rpm1_3); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonStart) == HIGH) {  q=0; break;}
       }}}}
       else if (tela==40 && way1_3==0) {way1_3=1;  }
       else if (tela==41 && rpm2_3 > 0) {rpm2_3--;  
       delay(200); 
       while (digitalRead(buttonStart) == LOW && rpm2_3 > 0) {
       rpm2_3--; q++;    
       lcd.setCursor(9,1); lcd.print(rpm2_3); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonStart) == HIGH){  q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonStart) == LOW && rpm2_3 > 0) {
       rpm2_3--;
       lcd.setCursor(9,1); lcd.print(rpm2_3); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonStart) == HIGH) {  q=0; break;}
       }}}}
       else if (tela==42 && way2_3==0) {way2_3=1;  }
       else if (tela==43 && rpm3_3 > 0) {rpm3_3--;  
       delay(200); 
       while (digitalRead(buttonStart) == LOW && rpm3_3 > 0) {
       rpm3_3--; q++;    
       lcd.setCursor(9,1); lcd.print(rpm3_3); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonStart) == HIGH){  q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonStart) == LOW && rpm3_3 > 0) {
       rpm3_3--;
       lcd.setCursor(9,1); lcd.print(rpm3_3); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonStart) == HIGH) {  q=0; break;}
       }}}}
       else if (tela==44 && way3_3==0) {way3_3=1;  }
       else if (tela==45 && rpm4_3 > 0) {rpm4_3--;  
       delay(200); 
       while (digitalRead(buttonStart) == LOW && rpm4_3 > 0) {
       rpm4_3--; q++;    
       lcd.setCursor(9,1); lcd.print(rpm4_3); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonStart) == HIGH){  q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonStart) == LOW && rpm4_3 > 0) {
       rpm4_3--;
       lcd.setCursor(9,1); lcd.print(rpm4_3); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonStart) == HIGH) {  q=0; break;}
       }}}}
       else if (tela==46 && way4_3==0) {way4_3=1;  }

       else if (tela==47){time4--;  
       delay(200); 
       while (digitalRead(buttonStart) == LOW) {
       time4--; q++;    
       lcd.setCursor(6,1); lcd.print(time4); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonStart) == HIGH){  q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonStart) == LOW) {
       time4--;
       lcd.setCursor(6,1); lcd.print(time4); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonStart) == HIGH) {  q=0; break;}
       }}}}
       else if (tela==48 && relay1_4==0) {relay1_4=1;  }
       else if (tela==49 && relay2_4==0) {relay2_4=1;  }
       else if (tela==50 && relay3_4==0) {relay3_4=1;  }
       else if (tela==51 && beep4==0) {beep4=1;  }
       else if (tela==52 && relay4_4==0) {relay4_4=1;  }
       else if (tela==53 && relay5_4==0) {relay5_4=1;  }
       else if (tela==54 && rpm1_4 > 0) {rpm1_4--;  
       delay(200); 
       while (digitalRead(buttonStart) == LOW && rpm1_4 > 0) {
       rpm1_4--; q++;    
       lcd.setCursor(9,1); lcd.print(rpm1_4); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonStart) == HIGH){  q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonStart) == LOW && rpm1_4 > 0) {
       rpm1_4--;
       lcd.setCursor(9,1); lcd.print(rpm1_4); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonStart) == HIGH) {  q=0; break;}
       }}}}
       else if (tela==55 && way1_4==0) {way1_4=1;  }
       else if (tela==56 && rpm2_4 > 0) {rpm2_4--;  
       delay(200); 
       while (digitalRead(buttonStart) == LOW && rpm2_4 > 0) {
       rpm2_4--; q++;    
       lcd.setCursor(9,1); lcd.print(rpm2_4); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonStart) == HIGH){  q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonStart) == LOW && rpm2_4 > 0) {
       rpm2_4--;
       lcd.setCursor(9,1); lcd.print(rpm2_4); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonStart) == HIGH) {  q=0; break;}
       }}}}
       else if (tela==57 && way2_4==0) {way2_4=1;  }
       else if (tela==58 && rpm3_4 > 0) {rpm3_4--;  
       delay(200); 
       while (digitalRead(buttonStart) == LOW && rpm3_4 > 0) {
       rpm3_4--; q++;    
       lcd.setCursor(9,1); lcd.print(rpm3_4); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonStart) == HIGH){  q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonStart) == LOW && rpm3_4 > 0) {
       rpm3_4--;
       lcd.setCursor(9,1); lcd.print(rpm3_4); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonStart) == HIGH) {  q=0; break;}
       }}}}
       else if (tela==59 && way3_4==0) {way3_4=1;  }
       else if (tela==60 && rpm4_4 > 0) {rpm4_4--;  
       delay(200); 
       while (digitalRead(buttonStart) == LOW && rpm4_4 > 0) {
       rpm4_4--; q++;    
       lcd.setCursor(9,1); lcd.print(rpm4_4); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonStart) == HIGH){  q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonStart) == LOW && rpm4_4 > 0) {
       rpm4_4--;
       lcd.setCursor(9,1); lcd.print(rpm4_4); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonStart) == HIGH) {  q=0; break;}
       }}}}
       else if (tela==61 && way4_4==0) {way4_4=1;  }

       else if (tela==62){time5--;  
       delay(200); 
       while (digitalRead(buttonStart) == LOW) {
       time5--; q++;    
       lcd.setCursor(6,1); lcd.print(time5); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonStart) == HIGH){  q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonStart) == LOW) {
       time5--;
       lcd.setCursor(6,1); lcd.print(time5); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonStart) == HIGH) {  q=0; break;}
       }}}}
       else if (tela==63 && relay1_5==0) {relay1_5=1;  }
       else if (tela==64 && relay2_5==0) {relay2_5=1;  }
       else if (tela==65 && relay3_5==0) {relay3_5=1;  }
       else if (tela==66 && beep5==0) {beep5=1;  }
       else if (tela==67 && relay4_5==0) {relay4_5=1;  }
       else if (tela==68 && relay5_5==0) {relay5_5=1;  }
       else if (tela==69 && rpm1_5 > 0) {rpm1_5--;  
       delay(200); 
       while (digitalRead(buttonStart) == LOW && rpm1_5 > 0) {
       rpm1_5--; q++;    
       lcd.setCursor(9,1); lcd.print(rpm1_5); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonStart) == HIGH){  q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonStart) == LOW && rpm1_5 > 0) {
       rpm1_5--;
       lcd.setCursor(9,1); lcd.print(rpm1_5); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonStart) == HIGH) {  q=0; break;}
       }}}}
       else if (tela==70 && way1_5==0) {way1_5=1;  }
       else if (tela==71 && rpm2_5 > 0) {rpm2_5--;  
       delay(200); 
       while (digitalRead(buttonStart) == LOW && rpm2_5 > 0) {
       rpm2_5--; q++;    
       lcd.setCursor(9,1); lcd.print(rpm2_5); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonStart) == HIGH){  q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonStart) == LOW && rpm2_5 > 0) {
       rpm2_5--;
       lcd.setCursor(9,1); lcd.print(rpm2_5); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonStart) == HIGH) {  q=0; break;}
       }}}}
       else if (tela==72 && way2_5==0) {way2_5=1;  }
       else if (tela==73 && rpm3_5 > 0) {rpm3_5--;  
       delay(200); 
       while (digitalRead(buttonStart) == LOW && rpm3_5 > 0) {
       rpm3_5--; q++;    
       lcd.setCursor(9,1); lcd.print(rpm3_5); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonStart) == HIGH){  q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonStart) == LOW && rpm3_5 > 0) {
       rpm3_5--;
       lcd.setCursor(9,1); lcd.print(rpm3_5); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonStart) == HIGH) {  q=0; break;}
       }}}}
       else if (tela==74 && way3_5==0) {way3_5=1;  }
       else if (tela==75 && rpm4_5 > 0) {rpm4_5--;  
       delay(200); 
       while (digitalRead(buttonStart) == LOW && rpm4_5 > 0) {
       rpm4_5--; q++;    
       lcd.setCursor(9,1); lcd.print(rpm4_5); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonStart) == HIGH){  q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonStart) == LOW && rpm4_5 > 0) {
       rpm4_5--;
       lcd.setCursor(9,1); lcd.print(rpm4_5); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonStart) == HIGH) {  q=0; break;}
       }}}}
       else if (tela==76 && way4_5==0) {way4_5=1;  }

       else if (tela==77){time6--;  
       delay(200); 
       while (digitalRead(buttonStart) == LOW) {
       time6--; q++;    
       lcd.setCursor(6,1); lcd.print(time6); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonStart) == HIGH){  q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonStart) == LOW) {
       time6--;
       lcd.setCursor(6,1); lcd.print(time6); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonStart) == HIGH) {  q=0; break;}
       }}}}
       else if (tela==78 && relay1_6==0) {relay1_6=1;  }
       else if (tela==79 && relay2_6==0) {relay2_6=1;  }
       else if (tela==80 && relay3_6==0) {relay3_6=1;  }
       else if (tela==81 && beep6==0) {beep6=1;  }
       else if (tela==82 && relay4_6==0) {relay4_6=1;  }
       else if (tela==83 && relay5_6==0) {relay5_6=1;  }
       else if (tela==84 && rpm1_6 > 0) {rpm1_6--;  
       delay(200); 
       while (digitalRead(buttonStart) == LOW && rpm1_6 > 0) {
       rpm1_6--; q++;    
       lcd.setCursor(9,1); lcd.print(rpm1_6); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonStart) == HIGH){  q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonStart) == LOW && rpm1_6 > 0) {
       rpm1_6--;
       lcd.setCursor(9,1); lcd.print(rpm1_6); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonStart) == HIGH) {  q=0; break;}
       }}}}
       else if (tela==85 && way1_6==0) {way1_6=1;  }
       else if (tela==86 && rpm2_6 > 0) {rpm2_6--;  
       delay(200); 
       while (digitalRead(buttonStart) == LOW && rpm2_6 > 0) {
       rpm2_6--; q++;    
       lcd.setCursor(9,1); lcd.print(rpm2_6); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonStart) == HIGH){  q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonStart) == LOW && rpm2_6 > 0) {
       rpm2_6--;
       lcd.setCursor(9,1); lcd.print(rpm2_6); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonStart) == HIGH) {  q=0; break;}
       }}}}
       else if (tela==87 && way2_6==0) {way2_6=1;  }
       else if (tela==88 && rpm3_6 > 0) {rpm3_6--;  
       delay(200); 
       while (digitalRead(buttonStart) == LOW && rpm3_6 > 0) {
       rpm3_6--; q++;    
       lcd.setCursor(9,1); lcd.print(rpm3_6); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonStart) == HIGH){  q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonStart) == LOW && rpm3_6 > 0) {
       rpm3_6--;
       lcd.setCursor(9,1); lcd.print(rpm3_6); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonStart) == HIGH) {  q=0; break;}
       }}}}
       else if (tela==89 && way3_6==0) {way3_6=1;  }
       else if (tela==90 && rpm4_6 > 0) {rpm4_6--;  
       delay(200); 
       while (digitalRead(buttonStart) == LOW && rpm4_6 > 0) {
       rpm4_6--; q++;    
       lcd.setCursor(9,1); lcd.print(rpm4_6); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonStart) == HIGH){  q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonStart) == LOW && rpm4_6 > 0) {
       rpm4_6--;
       lcd.setCursor(9,1); lcd.print(rpm4_6); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonStart) == HIGH) {  q=0; break;}
       }}}}
       else if (tela==91 && way4_6==0) {way4_6=1;  }

       else if (tela==92){time7--;  
       delay(200); 
       while (digitalRead(buttonStart) == LOW) {
       time7--; q++;    
       lcd.setCursor(6,1); lcd.print(time7); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonStart) == HIGH){  q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonStart) == LOW) {
       time7--;
       lcd.setCursor(6,1); lcd.print(time7); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonStart) == HIGH) {  q=0; break;}
       }}}}
       else if (tela==93 && relay1_7==0) {relay1_7=1;  }
       else if (tela==94 && relay2_7==0) {relay2_7=1;  }
       else if (tela==95 && relay3_7==0) {relay3_7=1;  }
       else if (tela==96 && beep7==0) {beep7=1;  }
       else if (tela==97 && relay4_7==0) {relay4_7=1;  }
       else if (tela==98 && relay5_7==0) {relay5_7=1;  }
       else if (tela==99 && rpm1_7 > 0) {rpm1_7--;  
       delay(200); 
       while (digitalRead(buttonStart) == LOW && rpm1_7 > 0) {
       rpm1_7--; q++;    
       lcd.setCursor(9,1); lcd.print(rpm1_7); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonStart) == HIGH){  q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonStart) == LOW && rpm1_7 > 0) {
       rpm1_7--;
       lcd.setCursor(9,1); lcd.print(rpm1_7); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonStart) == HIGH) {  q=0; break;}
       }}}}
       else if (tela==100 && way1_7==0) {way1_7=1;  }
       else if (tela==101 && rpm2_7 > 0) {rpm2_7--;  
       delay(200); 
       while (digitalRead(buttonStart) == LOW && rpm2_7 > 0) {
       rpm2_7--; q++;    
       lcd.setCursor(9,1); lcd.print(rpm2_7); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonStart) == HIGH){  q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonStart) == LOW && rpm2_7 > 0) {
       rpm2_7--;
       lcd.setCursor(9,1); lcd.print(rpm2_7); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonStart) == HIGH) {  q=0; break;}
       }}}}
       else if (tela==102 && way2_7==0) {way2_7=1;  }
       else if (tela==103 && rpm3_7 > 0) {rpm3_7--;  
       delay(200); 
       while (digitalRead(buttonStart) == LOW && rpm3_7 > 0) {
       rpm3_7--; q++;    
       lcd.setCursor(9,1); lcd.print(rpm3_7); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonStart) == HIGH){  q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonStart) == LOW && rpm3_7 > 0) {
       rpm3_7--;
       lcd.setCursor(9,1); lcd.print(rpm3_7); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonStart) == HIGH) {  q=0; break;}
       }}}}
       else if (tela==104 && way3_7==0) {way3_7=1;  }
       else if (tela==105 && rpm4_7 > 0) {rpm4_7--;  
       delay(200); 
       while (digitalRead(buttonStart) == LOW && rpm4_7 > 0) {
       rpm4_7--; q++;    
       lcd.setCursor(9,1); lcd.print(rpm4_7); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonStart) == HIGH){  q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonStart) == LOW && rpm4_7 > 0) {
       rpm4_7--;
       lcd.setCursor(9,1); lcd.print(rpm4_7); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonStart) == HIGH) {  q=0; break;}
       }}}}
       else if (tela==106 && way4_7==0) {way4_7=1;  }

       else if (tela==107){time8--;  
       delay(200); 
       while (digitalRead(buttonStart) == LOW) {
       time8--; q++;    
       lcd.setCursor(6,1); lcd.print(time8); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonStart) == HIGH){  q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonStart) == LOW) {
       time8--;
       lcd.setCursor(6,1); lcd.print(time8); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonStart) == HIGH) {  q=0; break;}
       }}}}
       else if (tela==108 && relay1_8==0) {relay1_8=1;  }
       else if (tela==109 && relay2_8==0) {relay2_8=1;  }
       else if (tela==110 && relay3_8==0) {relay3_8=1;  }
       else if (tela==111 && beep8==0) {beep8=1;  }
       else if (tela==112 && relay4_8==0) {relay4_8=1;  }
       else if (tela==113 && relay5_8==0) {relay5_8=1;  }
       else if (tela==114 && rpm1_8 > 0) {rpm1_8--;  
       delay(200); 
       while (digitalRead(buttonStart) == LOW && rpm1_8 > 0) {
       rpm1_8--; q++;    
       lcd.setCursor(9,1); lcd.print(rpm1_8); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonStart) == HIGH){  q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonStart) == LOW && rpm1_8 > 0) {
       rpm1_8--;
       lcd.setCursor(9,1); lcd.print(rpm1_8); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonStart) == HIGH) {  q=0; break;}
       }}}}
       else if (tela==115 && way1_8==0) {way1_8=1;  }
       else if (tela==116 && rpm2_8 > 0) {rpm2_8--;  
       delay(200); 
       while (digitalRead(buttonStart) == LOW && rpm2_8 > 0) {
       rpm2_8--; q++;    
       lcd.setCursor(9,1); lcd.print(rpm2_8); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonStart) == HIGH){  q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonStart) == LOW && rpm2_8 > 0) {
       rpm2_8--;
       lcd.setCursor(9,1); lcd.print(rpm2_8); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonStart) == HIGH) {  q=0; break;}
       }}}}
       else if (tela==117 && way2_8==0) {way2_8=1;  }
       else if (tela==118 && rpm3_8 > 0) {rpm3_8--;  
       delay(200); 
       while (digitalRead(buttonStart) == LOW && rpm3_8 > 0) {
       rpm3_8--; q++;    
       lcd.setCursor(9,1); lcd.print(rpm3_8); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonStart) == HIGH){  q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonStart) == LOW && rpm3_8 > 0) {
       rpm3_8--;
       lcd.setCursor(9,1); lcd.print(rpm3_8); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonStart) == HIGH) {  q=0; break;}
       }}}}
       else if (tela==119 && way3_8==0) {way3_8=1;  }
       else if (tela==120 && rpm4_8 > 0) {rpm4_8--;  
       delay(200); 
       while (digitalRead(buttonStart) == LOW && rpm4_8 > 0) {
       rpm4_8--; q++;    
       lcd.setCursor(9,1); lcd.print(rpm4_8); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonStart) == HIGH){  q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonStart) == LOW && rpm4_8 > 0) {
       rpm4_8--;
       lcd.setCursor(9,1); lcd.print(rpm4_8); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonStart) == HIGH) {  q=0; break;}
       }}}}
       else if (tela==121 && way4_8==0) {way4_8=1;  }

       else if (tela==122){time9--;  
       delay(200); 
       while (digitalRead(buttonStart) == LOW) {
       time9--; q++;    
       lcd.setCursor(6,1); lcd.print(time9); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonStart) == HIGH){  q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonStart) == LOW) {
       time9--;
       lcd.setCursor(6,1); lcd.print(time9); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonStart) == HIGH) {  q=0; break;}
       }}}}
       else if (tela==123 && relay1_9==0) {relay1_9=1;  }
       else if (tela==124 && relay2_9==0) {relay2_9=1;  }
       else if (tela==125 && relay3_9==0) {relay3_9=1;  }
       else if (tela==126 && beep9==0) {beep9=1;  }
       else if (tela==127 && relay4_9==0) {relay4_9=1;  }
       else if (tela==128 && relay5_9==0) {relay5_9=1;  }
       else if (tela==129 && rpm1_9 > 0) {rpm1_9--;  
       delay(200); 
       while (digitalRead(buttonStart) == LOW && rpm1_9 > 0) {
       rpm1_9--; q++;    
       lcd.setCursor(9,1); lcd.print(rpm1_9); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonStart) == HIGH){  q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonStart) == LOW && rpm1_9 > 0) {
       rpm1_9--;
       lcd.setCursor(9,1); lcd.print(rpm1_9); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonStart) == HIGH) {  q=0; break;}
       }}}}
       else if (tela==130 && way1_9==0) {way1_9=1;  }
       else if (tela==131 && rpm2_9 > 0) {rpm2_9--;  
       delay(200); 
       while (digitalRead(buttonStart) == LOW && rpm2_9 > 0) {
       rpm2_9--; q++;    
       lcd.setCursor(9,1); lcd.print(rpm2_9); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonStart) == HIGH){  q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonStart) == LOW && rpm2_9 > 0) {
       rpm2_9--;
       lcd.setCursor(9,1); lcd.print(rpm2_9); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonStart) == HIGH) {  q=0; break;}
       }}}}
       else if (tela==132 && way2_9==0) {way2_9=1;  }
       else if (tela==133 && rpm3_9 > 0) {rpm3_9--;  
       delay(200); 
       while (digitalRead(buttonStart) == LOW && rpm3_9 > 0) {
       rpm3_9--; q++;    
       lcd.setCursor(9,1); lcd.print(rpm3_9); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonStart) == HIGH){  q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonStart) == LOW && rpm3_9 > 0) {
       rpm3_9--;
       lcd.setCursor(9,1); lcd.print(rpm3_9); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonStart) == HIGH) {  q=0; break;}
       }}}}
       else if (tela==134 && way3_9==0) {way3_9=1;  }
       else if (tela==135 && rpm4_9 > 0) {rpm4_9--;  
       delay(200); 
       while (digitalRead(buttonStart) == LOW && rpm4_9 > 0) {
       rpm4_9--; q++;    
       lcd.setCursor(9,1); lcd.print(rpm4_9); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonStart) == HIGH){  q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonStart) == LOW && rpm4_9 > 0) {
       rpm4_9--;
       lcd.setCursor(9,1); lcd.print(rpm4_9); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonStart) == HIGH) {  q=0; break;}
       }}}}
       else if (tela==136 && way4_9==0) {way4_9=1;  }

       else if (tela==137){time10--;  
       delay(200); 
       while (digitalRead(buttonStart) == LOW) {
       time10--; q++;    
       lcd.setCursor(6,1); lcd.print(time10); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonStart) == HIGH){  q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonStart) == LOW) {
       time10--;
       lcd.setCursor(6,1); lcd.print(time10); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonStart) == HIGH) {  q=0; break;}
       }}}}
       else if (tela==138 && relay1_10==0) {relay1_10=1;  }
       else if (tela==139 && relay2_10==0) {relay2_10=1;  }
       else if (tela==140 && relay3_10==0) {relay3_10=1;  }
       else if (tela==141 && beep10==0) {beep10=1;  }
       else if (tela==142 && relay4_10==0) {relay4_10=1;  }
       else if (tela==143 && relay5_10==0) {relay5_10=1;  }
       else if (tela==144 && rpm1_10 > 0) {rpm1_10--;  
       delay(200); 
       while (digitalRead(buttonStart) == LOW && rpm1_10 > 0) {
       rpm1_10--; q++;    
       lcd.setCursor(9,1); lcd.print(rpm1_10); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonStart) == HIGH){  q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonStart) == LOW && rpm1_10 > 0) {
       rpm1_10--;
       lcd.setCursor(9,1); lcd.print(rpm1_10); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonStart) == HIGH) {  q=0; break;}
       }}}}
       else if (tela==145 && way1_10==0) {way1_10=1;  }
       else if (tela==146 && rpm2_10 > 0) {rpm2_10--;  
       delay(200); 
       while (digitalRead(buttonStart) == LOW && rpm2_10 > 0) {
       rpm2_10--; q++;    
       lcd.setCursor(9,1); lcd.print(rpm2_10); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonStart) == HIGH){  q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonStart) == LOW && rpm2_10 > 0) {
       rpm2_10--;
       lcd.setCursor(9,1); lcd.print(rpm2_10); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonStart) == HIGH) {  q=0; break;}
       }}}}
       else if (tela==147 && way2_10==0) {way2_10=1;  }
       else if (tela==148 && rpm3_10 > 0) {rpm3_10--;  
       delay(200); 
       while (digitalRead(buttonStart) == LOW && rpm3_10 > 0) {
       rpm3_10--; q++;    
       lcd.setCursor(9,1); lcd.print(rpm3_10); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonStart) == HIGH){  q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonStart) == LOW && rpm3_10 > 0) {
       rpm3_10--;
       lcd.setCursor(9,1); lcd.print(rpm3_10); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonStart) == HIGH) {  q=0; break;}
       }}}}
       else if (tela==149 && way3_10==0) {way3_10=1;  }
       else if (tela==150 && rpm4_10 > 0) {rpm4_10--;  
       delay(200); 
       while (digitalRead(buttonStart) == LOW && rpm4_10 > 0) {
       rpm4_10--; q++;    
       lcd.setCursor(9,1); lcd.print(rpm4_10); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonStart) == HIGH){  q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonStart) == LOW && rpm4_10 > 0) {
       rpm4_10--;
       lcd.setCursor(9,1); lcd.print(rpm4_10); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonStart) == HIGH) {  q=0; break;}
       }}}}
       else if (tela==151 && way4_10==0) {way4_10=1;  }

       else if (tela==152){time11--;  
       delay(200); 
       while (digitalRead(buttonStart) == LOW) {
       time11--; q++;    
       lcd.setCursor(6,1); lcd.print(time11); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonStart) == HIGH){  q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonStart) == LOW) {
       time11--;
       lcd.setCursor(6,1); lcd.print(time11); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonStart) == HIGH) {  q=0; break;}
       }}}}
       else if (tela==153 && relay1_11==0) {relay1_11=1;  }
       else if (tela==154 && relay2_11==0) {relay2_11=1;  }
       else if (tela==155 && relay3_11==0) {relay3_11=1;  }
       else if (tela==156 && beep11==0) {beep11=1;  }
       else if (tela==157 && relay4_11==0) {relay4_11=1;  }
       else if (tela==158 && relay5_11==0) {relay5_11=1;  }
       else if (tela==159 && rpm1_11 > 0) {rpm1_11--;  
       delay(200); 
       while (digitalRead(buttonStart) == LOW && rpm1_11 > 0) {
       rpm1_11--; q++;    
       lcd.setCursor(9,1); lcd.print(rpm1_11); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonStart) == HIGH){  q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonStart) == LOW && rpm1_11 > 0) {
       rpm1_11--;
       lcd.setCursor(9,1); lcd.print(rpm1_11); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonStart) == HIGH) {  q=0; break;}
       }}}}
       else if (tela==160 && way1_11==0) {way1_11=1;  }
       else if (tela==161 && rpm2_11 > 0) {rpm2_11--;  
       delay(200); 
       while (digitalRead(buttonStart) == LOW && rpm2_11 > 0) {
       rpm2_11--; q++;    
       lcd.setCursor(9,1); lcd.print(rpm2_11); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonStart) == HIGH){  q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonStart) == LOW && rpm2_11 > 0) {
       rpm2_11--;
       lcd.setCursor(9,1); lcd.print(rpm2_11); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonStart) == HIGH) {  q=0; break;}
       }}}}
       else if (tela==162 && way2_11==0) {way2_11=1;  }
       else if (tela==163 && rpm3_11 > 0) {rpm3_11--;  
       delay(200); 
       while (digitalRead(buttonStart) == LOW && rpm3_11 > 0) {
       rpm3_11--; q++;    
       lcd.setCursor(9,1); lcd.print(rpm3_11); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonStart) == HIGH){  q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonStart) == LOW && rpm3_11 > 0) {
       rpm3_11--;
       lcd.setCursor(9,1); lcd.print(rpm3_11); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonStart) == HIGH) {  q=0; break;}
       }}}}
       else if (tela==164 && way3_11==0) {way3_11=1;  }
       else if (tela==165 && rpm4_11 > 0) {rpm4_11--;  
       delay(200); 
       while (digitalRead(buttonStart) == LOW && rpm4_11 > 0) {
       rpm4_11--; q++;    
       lcd.setCursor(9,1); lcd.print(rpm4_11); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonStart) == HIGH){  q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonStart) == LOW && rpm4_11 > 0) {
       rpm4_11--;
       lcd.setCursor(9,1); lcd.print(rpm4_11); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonStart) == HIGH) {  q=0; break;}
       }}}}
       else if (tela==166 && way4_11==0) {way4_11=1;  }

       else if (tela==167){time12--;  
       delay(200); 
       while (digitalRead(buttonStart) == LOW) {
       time12--; q++;    
       lcd.setCursor(6,1); lcd.print(time12); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonStart) == HIGH){  q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonStart) == LOW) {
       time12--;
       lcd.setCursor(6,1); lcd.print(time12); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonStart) == HIGH) {  q=0; break;}
       }}}}
       else if (tela==168 && relay1_12==0) {relay1_12=1;  }
       else if (tela==169 && relay2_12==0) {relay2_12=1;  }
       else if (tela==170 && relay3_12==0) {relay3_12=1;  }
       else if (tela==171 && beep12==0) {beep12=1;  }
       else if (tela==172 && relay4_12==0) {relay4_12=1;  }
       else if (tela==173 && relay5_12==0) {relay5_12=1;  }
       else if (tela==174 && rpm1_12 > 0) {rpm1_12--;  
       delay(200); 
       while (digitalRead(buttonStart) == LOW && rpm1_12 > 0) {
       rpm1_12--; q++;    
       lcd.setCursor(9,1); lcd.print(rpm1_12); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonStart) == HIGH){  q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonStart) == LOW && rpm1_12 > 0) {
       rpm1_12--;
       lcd.setCursor(9,1); lcd.print(rpm1_12); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonStart) == HIGH) {  q=0; break;}
       }}}}
       else if (tela==175 && way1_12==0) {way1_12=1;  }
       else if (tela==176 && rpm2_12 > 0) {rpm2_12--;  
       delay(200); 
       while (digitalRead(buttonStart) == LOW && rpm2_12 > 0) {
       rpm2_12--; q++;    
       lcd.setCursor(9,1); lcd.print(rpm2_12); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonStart) == HIGH){  q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonStart) == LOW && rpm2_12 > 0) {
       rpm2_12--;
       lcd.setCursor(9,1); lcd.print(rpm2_12); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonStart) == HIGH) {  q=0; break;}
       }}}}
       else if (tela==177 && way2_12==0) {way2_12=1;  }
       else if (tela==178 && rpm3_12 > 0) {rpm3_12--;  
       delay(200); 
       while (digitalRead(buttonStart) == LOW && rpm3_12 > 0) {
       rpm3_12--; q++;    
       lcd.setCursor(9,1); lcd.print(rpm3_12); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonStart) == HIGH){  q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonStart) == LOW && rpm3_12 > 0) {
       rpm3_12--;
       lcd.setCursor(9,1); lcd.print(rpm3_12); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonStart) == HIGH) {  q=0; break;}
       }}}}
       else if (tela==179 && way3_12==0) {way3_12=1;  }
       else if (tela==180 && rpm4_12 > 0) {rpm4_12--;  
       delay(200); 
       while (digitalRead(buttonStart) == LOW && rpm4_12 > 0) {
       rpm4_12--; q++;    
       lcd.setCursor(9,1); lcd.print(rpm4_12); lcd.print(F("  "));
       delay(300); if (digitalRead(buttonStart) == HIGH){  q=0; break;}
       if (q == 10) {
       while (digitalRead(buttonStart) == LOW && rpm4_12 > 0) {
       rpm4_12--;
       lcd.setCursor(9,1); lcd.print(rpm4_12); lcd.print(F("  "));
       delay(100); if (digitalRead(buttonStart) == HIGH) {  q=0; break;}
       }}}}
       else if (tela==181 && way4_12==0) {way4_12=1;  }
      
       delay(30);
       } LA_botao_MENOS = L_botao_MENOS;



// === ACTION OF THE button ENTER === // 
  L_botao_ENTER = digitalRead(buttonMenu);
  if (!L_botao_ENTER && LA_botao_ENTER) {
            if (tela==1){tela=2;}
       else if (tela==2){tela=3;}
       else if (tela==3){tela=4;}
       else if (tela==4){tela=5;}
       else if (tela==5){tela=6;} //modificado
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
       else if (tela==20){tela=21;} //modificado
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
       else if (tela==35){tela=36;} //modificado
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
       else if (tela==50){tela=51;} //modificado
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
       else if (tela==65){tela=66;} //modificado
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
       else if (tela==80){tela=81;} //modificado
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
       else if (tela==95){tela=96;} //modificado
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
       else if (tela==110){tela=111;} //modificado
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
       else if (tela==125){tela=126;} //modificado
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
       else if (tela==140){tela=141;} //modificado
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
       else if (tela==155){tela=156;} //modificado
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
       else if (tela==168){ 
        saveData();
        lcd.clear(); 
        tela=1;}
    
       delay(30);
       } LA_botao_ENTER = L_botao_ENTER;
}



void runSteps(){

    servo.attach(pinServo);

    Serial.print("1~1"); Serial.print('\r'); delay(200);
      
    digitalWrite(buzzer, HIGH); delay(200); digitalWrite(buzzer, LOW);
    
    // Step 1
    if (time1 > 0){
    if (rpm1_1 > 0){ if (rpm1_1 < 10) {Serial.print("1SS1"+(String)xxx+(String)rpm1_1); Serial.print('\r'); delay(50);} else if (rpm1_1 > 9 && rpm1_1 <= 99) {Serial.print("1SS1"+(String)xx+(String)rpm1_1); Serial.print('\r'); delay(50);} else if (rpm1_1 == 100) {Serial.print("1SS1"+(String)x+(String)rpm1_1); Serial.print('\r'); delay(50);} if (way1_1 == 0){Serial.print("1J1"); Serial.print('\r'); delay(50);} else if (way1_1 == 1){Serial.print("1K1"); Serial.print('\r'); delay(50);} Serial.print("1H1"); Serial.print('\r'); delay(50);}
    if (rpm2_1 > 0){ if (rpm2_1 < 10) {Serial.print("2SS1"+(String)xxx+(String)rpm2_1); Serial.print('\r'); delay(50);} else if (rpm2_1 > 9 && rpm2_1 <= 99) {Serial.print("2SS1"+(String)xx+(String)rpm2_1); Serial.print('\r'); delay(50);} else if (rpm2_1 == 100) {Serial.print("2SS1"+(String)x+(String)rpm2_1); Serial.print('\r'); delay(50);} if (way2_1 == 0){Serial.print("2J1"); Serial.print('\r'); delay(50);} else if (way2_1 == 1){Serial.print("2K1"); Serial.print('\r'); delay(50);} Serial.print("2H1"); Serial.print('\r'); delay(50);}
    if (rpm3_1 > 0){ if (rpm3_1 < 10) {Serial.print("3SS1"+(String)xxx+(String)rpm3_1); Serial.print('\r'); delay(50);} else if (rpm3_1 > 9 && rpm3_1 <= 99) {Serial.print("3SS1"+(String)xx+(String)rpm3_1); Serial.print('\r'); delay(50);} else if (rpm3_1 == 100) {Serial.print("3SS1"+(String)x+(String)rpm3_1); Serial.print('\r'); delay(50);} if (way3_1 == 0){Serial.print("3J1"); Serial.print('\r'); delay(50);} else if (way3_1 == 1){Serial.print("3K1"); Serial.print('\r'); delay(50);} Serial.print("3H1"); Serial.print('\r'); delay(50);}
    if (rpm4_1 > 0){ if (rpm4_1 < 10) {Serial.print("4SS1"+(String)xxx+(String)rpm4_1); Serial.print('\r'); delay(50);} else if (rpm4_1 > 9 && rpm4_1 <= 99) {Serial.print("4SS1"+(String)xx+(String)rpm4_1); Serial.print('\r'); delay(50);} else if (rpm4_1 == 100) {Serial.print("4SS1"+(String)x+(String)rpm4_1); Serial.print('\r'); delay(50);} if (way4_1 == 0){Serial.print("4J1"); Serial.print('\r'); delay(50);} else if (way4_1 == 1){Serial.print("4K1"); Serial.print('\r'); delay(50);} Serial.print("4H1"); Serial.print('\r'); delay(50);}
    
    //if (relay1_1 == 1){ } if (relay2_1 == 1){ } if (relay3_1 == 1){ } if (relay4_1 == 1){digitalWrite(relayExt1, HIGH);} if (relay5_1 == 1){digitalWrite(relayExt2, HIGH);}
    
    lcd.setCursor(0, 0); lcd.print(F("==== Step 1 ====")); digitalWrite(relayRead, !relay1_1); digitalWrite(relayValve, !relay2_1); digitalWrite(relayHeat, !relay3_1); digitalWrite(relayExt1, !relay4_1); digitalWrite(relayExt2, !relay5_1);

    if (relay2_1 == 0){ servo.write(positionOne); }
    else { servo.write(positionTwo); }

    for (int i = 0; i <= 255; i++){                        
    if (beep1 == 1 && i == (time1-1)) { digitalWrite(buzzer, HIGH); }                     
    if (digitalRead(buttonCancel) == LOW || parar2 == 1){}  else { if ((i+1) <= time1) { lcd.setCursor(0, 1); lcd.print("Time: "); lcd.print(time1 - i); lcd.print("         "); delay(1000); servo.detach(); while (digitalRead(buttonLedRead) == LOW){ digitalWrite(relayRead, LOW); lcd.setCursor(12, 1); lcd.print("Read"); if (digitalRead(buttonLedRead) == HIGH){ digitalWrite(relayRead, HIGH);   break; }}      } }
    digitalWrite(buzzer, LOW);    
    }}        
 
    // Step 2
    if (digitalRead(buttonCancel) == HIGH && parar2 == 0 && time2 > 0){
    if (rpm1_2 == 0){Serial.print("1I1"); Serial.print('\r'); delay(50);} 
    if (rpm2_2 == 0){Serial.print("2I1"); Serial.print('\r'); delay(50);} 
    if (rpm3_2 == 0){Serial.print("3I1"); Serial.print('\r'); delay(50);} 
    if (rpm4_2 == 0){Serial.print("4I1"); Serial.print('\r'); delay(50);}
    if (rpm1_2 > 0){ if (rpm1_2 < 10) {Serial.print("1SS1"+(String)xxx+(String)rpm1_2); Serial.print('\r'); delay(50);} else if (rpm1_2 > 9 && rpm1_2 <= 99) {Serial.print("1SS1"+(String)xx+(String)rpm1_2); Serial.print('\r'); delay(50);} else if (rpm1_2 == 100) {Serial.print("1SS1"+(String)x+(String)rpm1_2); Serial.print('\r'); delay(50);} if (way1_2 == 0){Serial.print("1J1"); Serial.print('\r'); delay(50);} else if (way1_2 == 1){Serial.print("1K1"); Serial.print('\r'); delay(50);} Serial.print("1H1"); Serial.print('\r'); delay(50);}
    if (rpm2_2 > 0){ if (rpm2_2 < 10) {Serial.print("2SS1"+(String)xxx+(String)rpm2_2); Serial.print('\r'); delay(50);} else if (rpm2_2 > 9 && rpm2_2 <= 99) {Serial.print("2SS1"+(String)xx+(String)rpm2_2); Serial.print('\r'); delay(50);} else if (rpm2_2 == 100) {Serial.print("2SS1"+(String)x+(String)rpm2_2); Serial.print('\r'); delay(50);} if (way2_2 == 0){Serial.print("2J1"); Serial.print('\r'); delay(50);} else if (way2_2 == 1){Serial.print("2K1"); Serial.print('\r'); delay(50);} Serial.print("2H1"); Serial.print('\r'); delay(50);}
    if (rpm3_2 > 0){ if (rpm3_2 < 10) {Serial.print("3SS1"+(String)xxx+(String)rpm3_2); Serial.print('\r'); delay(50);} else if (rpm3_2 > 9 && rpm3_2 <= 99) {Serial.print("3SS1"+(String)xx+(String)rpm3_2); Serial.print('\r'); delay(50);} else if (rpm3_2 == 100) {Serial.print("3SS1"+(String)x+(String)rpm3_2); Serial.print('\r'); delay(50);} if (way3_2 == 0){Serial.print("3J1"); Serial.print('\r'); delay(50);} else if (way3_2 == 1){Serial.print("3K1"); Serial.print('\r'); delay(50);} Serial.print("3H1"); Serial.print('\r'); delay(50);}
    if (rpm4_2 > 0){ if (rpm4_2 < 10) {Serial.print("4SS1"+(String)xxx+(String)rpm4_2); Serial.print('\r'); delay(50);} else if (rpm4_2 > 9 && rpm4_2 <= 99) {Serial.print("4SS1"+(String)xx+(String)rpm4_2); Serial.print('\r'); delay(50);} else if (rpm4_2 == 100) {Serial.print("4SS1"+(String)x+(String)rpm4_2); Serial.print('\r'); delay(50);} if (way4_2 == 0){Serial.print("4J1"); Serial.print('\r'); delay(50);} else if (way4_2 == 1){Serial.print("4K1"); Serial.print('\r'); delay(50);} Serial.print("4H1"); Serial.print('\r'); delay(50);} 
        
    //      digitalWrite(28, LOW); digitalWrite(30, LOW); digitalWrite(32, LOW); digitalWrite(34, HIGH);
    //if (relay1_2 == 1){ } if (relay2_2 == 1){ } if (relay3_2 == 1){ } if (relay4_2 == 1){digitalWrite(relayExt1, HIGH);} if (relay5_2 == 1){digitalWrite(relayExt2, HIGH);}
    
    lcd.clear(); lcd.setCursor(0, 0); lcd.print(F("==== Step 2 ====")); digitalWrite(relayRead, !relay1_2); digitalWrite(relayValve, !relay2_2); digitalWrite(relayHeat, !relay3_2); digitalWrite(relayExt1, !relay4_2); digitalWrite(relayExt2, !relay5_2);

    servo.attach(pinServo);
    if (relay2_2 == 0){ servo.write(positionOne); }
    else { servo.write(positionTwo); }
        
    for (int i = 0; i <= 255; i++){                        
    if (beep2 == 1 && i == (time2-1)) { digitalWrite(buzzer, HIGH); }                         
    if (digitalRead(buttonCancel) == LOW || parar2 == 1){}  else { if ((i+1) <= time2) { lcd.setCursor(0, 1); lcd.print("Time: "); lcd.print(time2 - i); lcd.print("         "); delay(1000); servo.detach(); while (digitalRead(buttonLedRead) == LOW){ digitalWrite(relayRead, LOW);   lcd.setCursor(12, 1); lcd.print("Read"); if (digitalRead(buttonLedRead) == HIGH){ digitalWrite(relayRead, HIGH);   break; }}     } }
    digitalWrite(buzzer, LOW);  
    }}                                        

    // Step 3
    if (digitalRead(buttonCancel) == HIGH && parar2 == 0 && time3 > 0){ 
    if (rpm1_3 == 0){Serial.print("1I1"); Serial.print('\r'); delay(50);} 
    if (rpm2_3 == 0){Serial.print("2I1"); Serial.print('\r'); delay(50);} 
    if (rpm3_3 == 0){Serial.print("3I1"); Serial.print('\r'); delay(50);} 
    if (rpm4_3 == 0){Serial.print("4I1"); Serial.print('\r'); delay(50);}
    if (rpm1_3 > 0){ if (rpm1_3 < 10) {Serial.print("1SS1"+(String)xxx+(String)rpm1_3); Serial.print('\r'); delay(50);} else if (rpm1_3 > 9 && rpm1_3 <= 99) {Serial.print("1SS1"+(String)xx+(String)rpm1_3); Serial.print('\r'); delay(50);} else if (rpm1_3 == 100) {Serial.print("1SS1"+(String)x+(String)rpm1_3); Serial.print('\r'); delay(50);} if (way1_3 == 0){Serial.print("1J1"); Serial.print('\r'); delay(50);} else if (way1_3 == 1){Serial.print("1K1"); Serial.print('\r'); delay(50);} Serial.print("1H1"); Serial.print('\r'); delay(50);}
    if (rpm2_3 > 0){ if (rpm2_3 < 10) {Serial.print("2SS1"+(String)xxx+(String)rpm2_3); Serial.print('\r'); delay(50);} else if (rpm2_3 > 9 && rpm2_3 <= 99) {Serial.print("2SS1"+(String)xx+(String)rpm2_3); Serial.print('\r'); delay(50);} else if (rpm2_3 == 100) {Serial.print("2SS1"+(String)x+(String)rpm2_3); Serial.print('\r'); delay(50);} if (way2_3 == 0){Serial.print("2J1"); Serial.print('\r'); delay(50);} else if (way2_3 == 1){Serial.print("2K1"); Serial.print('\r'); delay(50);} Serial.print("2H1"); Serial.print('\r'); delay(50);}
    if (rpm3_3 > 0){ if (rpm3_3 < 10) {Serial.print("3SS1"+(String)xxx+(String)rpm3_3); Serial.print('\r'); delay(50);} else if (rpm3_3 > 9 && rpm3_3 <= 99) {Serial.print("3SS1"+(String)xx+(String)rpm3_3); Serial.print('\r'); delay(50);} else if (rpm3_3 == 100) {Serial.print("3SS1"+(String)x+(String)rpm3_3); Serial.print('\r'); delay(50);} if (way3_3 == 0){Serial.print("3J1"); Serial.print('\r'); delay(50);} else if (way3_3 == 1){Serial.print("3K1"); Serial.print('\r'); delay(50);} Serial.print("3H1"); Serial.print('\r'); delay(50);}
    if (rpm4_3 > 0){ if (rpm4_3 < 10) {Serial.print("4SS1"+(String)xxx+(String)rpm4_3); Serial.print('\r'); delay(50);} else if (rpm4_3 > 9 && rpm4_3 <= 99) {Serial.print("4SS1"+(String)xx+(String)rpm4_3); Serial.print('\r'); delay(50);} else if (rpm4_3 == 100) {Serial.print("4SS1"+(String)x+(String)rpm4_3); Serial.print('\r'); delay(50);} if (way4_3 == 0){Serial.print("4J1"); Serial.print('\r'); delay(50);} else if (way4_3 == 1){Serial.print("4K1"); Serial.print('\r'); delay(50);} Serial.print("4H1"); Serial.print('\r'); delay(50);}                                    
            
    //      digitalWrite(28, LOW); digitalWrite(30, LOW); digitalWrite(32, LOW); digitalWrite(34, HIGH);
    //if (relay1_3 == 1){ } if (relay2_3 == 1){ } if (relay3_3 == 1){ } if (relay4_3 == 1){digitalWrite(relayExt1, HIGH);} if (relay5_3 == 1){digitalWrite(relayExt2, HIGH);}
    
    lcd.clear(); lcd.setCursor(0, 0); lcd.print(F("==== Step 3 ====")); digitalWrite(relayRead, !relay1_3); digitalWrite(relayValve, !relay2_3); digitalWrite(relayHeat, !relay3_3); digitalWrite(relayExt1, !relay4_3); digitalWrite(relayExt2, !relay5_3);

    servo.attach(pinServo);
    if (relay2_3 == 0){ servo.write(positionOne); }
    else { servo.write(positionTwo); }
    
    for (int i = 0; i <= 255; i++){                        
    if (beep3 == 1 && i == (time3-1)) { digitalWrite(buzzer, HIGH); }                         
    if (digitalRead(buttonCancel) == LOW || parar2 == 1){}  else { if ((i+1) <= time3) { lcd.setCursor(0, 1); lcd.print("Time: "); lcd.print(time3 - i); lcd.print("         "); delay(1000); servo.detach(); while (digitalRead(buttonLedRead) == LOW){ digitalWrite(relayRead, LOW);   lcd.setCursor(12, 1); lcd.print("Read"); if (digitalRead(buttonLedRead) == HIGH){ digitalWrite(relayRead, HIGH);   break; }}     } }
    digitalWrite(buzzer, LOW);     
    }}     
      
    // Step 4
    if (digitalRead(buttonCancel) == HIGH && parar2 == 0 && time4 > 0){
    if (rpm1_4 == 0){Serial.print("1I1"); Serial.print('\r'); delay(50);} 
    if (rpm2_4 == 0){Serial.print("2I1"); Serial.print('\r'); delay(50);} 
    if (rpm3_4 == 0){Serial.print("3I1"); Serial.print('\r'); delay(50);} 
    if (rpm4_4 == 0){Serial.print("4I1"); Serial.print('\r'); delay(50);}
    if (rpm1_4 > 0){ if (rpm1_4 < 10) {Serial.print("1SS1"+(String)xxx+(String)rpm1_4); Serial.print('\r'); delay(50);} else if (rpm1_4 > 9 && rpm1_4 <= 99) {Serial.print("1SS1"+(String)xx+(String)rpm1_4); Serial.print('\r'); delay(50);} else if (rpm1_4 == 100) {Serial.print("1SS1"+(String)x+(String)rpm1_4); Serial.print('\r'); delay(50);} if (way1_4 == 0){Serial.print("1J1"); Serial.print('\r'); delay(50);} else if (way1_4 == 1){Serial.print("1K1"); Serial.print('\r'); delay(50);} Serial.print("1H1"); Serial.print('\r'); delay(50);}
    if (rpm2_4 > 0){ if (rpm2_4 < 10) {Serial.print("2SS1"+(String)xxx+(String)rpm2_4); Serial.print('\r'); delay(50);} else if (rpm2_4 > 9 && rpm2_4 <= 99) {Serial.print("2SS1"+(String)xx+(String)rpm2_4); Serial.print('\r'); delay(50);} else if (rpm2_4 == 100) {Serial.print("2SS1"+(String)x+(String)rpm2_4); Serial.print('\r'); delay(50);} if (way2_4 == 0){Serial.print("2J1"); Serial.print('\r'); delay(50);} else if (way2_4 == 1){Serial.print("2K1"); Serial.print('\r'); delay(50);} Serial.print("2H1"); Serial.print('\r'); delay(50);}
    if (rpm3_4 > 0){ if (rpm3_4 < 10) {Serial.print("3SS1"+(String)xxx+(String)rpm3_4); Serial.print('\r'); delay(50);} else if (rpm3_4 > 9 && rpm3_4 <= 99) {Serial.print("3SS1"+(String)xx+(String)rpm3_4); Serial.print('\r'); delay(50);} else if (rpm3_4 == 100) {Serial.print("3SS1"+(String)x+(String)rpm3_4); Serial.print('\r'); delay(50);} if (way3_4 == 0){Serial.print("3J1"); Serial.print('\r'); delay(50);} else if (way3_4 == 1){Serial.print("3K1"); Serial.print('\r'); delay(50);} Serial.print("3H1"); Serial.print('\r'); delay(50);}
    if (rpm4_4 > 0){ if (rpm4_4 < 10) {Serial.print("4SS1"+(String)xxx+(String)rpm4_4); Serial.print('\r'); delay(50);} else if (rpm4_4 > 9 && rpm4_4 <= 99) {Serial.print("4SS1"+(String)xx+(String)rpm4_4); Serial.print('\r'); delay(50);} else if (rpm4_4 == 100) {Serial.print("4SS1"+(String)x+(String)rpm4_4); Serial.print('\r'); delay(50);} if (way4_4 == 0){Serial.print("4J1"); Serial.print('\r'); delay(50);} else if (way4_4 == 1){Serial.print("4K1"); Serial.print('\r'); delay(50);} Serial.print("4H1"); Serial.print('\r'); delay(50);}                                     
                
    //      digitalWrite(28, LOW); digitalWrite(30, LOW); digitalWrite(32, LOW); digitalWrite(34, HIGH);
    //if (relay1_4 == 1){ } if (relay2_4 == 1){ } if (relay3_4 == 1){ } if (relay4_4 == 1){digitalWrite(relayExt1, HIGH);} if (relay5_4 == 1){digitalWrite(relayExt1, HIGH);}
    
    lcd.clear(); lcd.setCursor(0, 0); lcd.print(F("==== Step 4 ====")); digitalWrite(relayRead, !relay1_4); digitalWrite(relayValve, !relay2_4); digitalWrite(relayHeat, !relay3_4); digitalWrite(relayExt1, !relay4_4); digitalWrite(relayExt2, !relay5_4);

    servo.attach(pinServo);
    if (relay2_4 == 0){ servo.write(positionOne); }
    else { servo.write(positionTwo); }
    
    for (int i = 0; i <= 255; i++){                        
    if (beep4 == 1 && i == (time4-1)) { digitalWrite(buzzer, HIGH); }                        
    if (digitalRead(buttonCancel) == LOW || parar2 == 1){}  else { if ((i+1) <= time4) { lcd.setCursor(0, 1); lcd.print("Time: "); lcd.print(time4 - i); lcd.print("         "); delay(1000); servo.detach(); while (digitalRead(buttonLedRead) == LOW){ digitalWrite(relayRead, LOW);   lcd.setCursor(12, 1); lcd.print("Read"); if (digitalRead(buttonLedRead) == HIGH){ digitalWrite(relayRead, HIGH);   break; }}     } }
    digitalWrite(buzzer, LOW);     
    }}                                       
        
    // Step 5
    if (digitalRead(buttonCancel) == HIGH && parar2 == 0 && time5 > 0){
    if (rpm1_5 == 0){Serial.print("1I1"); Serial.print('\r'); delay(50);} 
    if (rpm2_5 == 0){Serial.print("2I1"); Serial.print('\r'); delay(50);} 
    if (rpm3_5 == 0){Serial.print("3I1"); Serial.print('\r'); delay(50);} 
    if (rpm4_5 == 0){Serial.print("4I1"); Serial.print('\r'); delay(50);}
    if (rpm1_5 > 0){ if (rpm1_5 < 10) {Serial.print("1SS1"+(String)xxx+(String)rpm1_5); Serial.print('\r'); delay(50);} else if (rpm1_5 > 9 && rpm1_5 <= 99) {Serial.print("1SS1"+(String)xx+(String)rpm1_5); Serial.print('\r'); delay(50);} else if (rpm1_5 == 100) {Serial.print("1SS1"+(String)x+(String)rpm1_5); Serial.print('\r'); delay(50);} if (way1_5 == 0){Serial.print("1J1"); Serial.print('\r'); delay(50);} else if (way1_5 == 1){Serial.print("1K1"); Serial.print('\r'); delay(50);} Serial.print("1H1"); Serial.print('\r'); delay(50);}
    if (rpm2_5 > 0){ if (rpm2_5 < 10) {Serial.print("2SS1"+(String)xxx+(String)rpm2_5); Serial.print('\r'); delay(50);} else if (rpm2_5 > 9 && rpm2_5 <= 99) {Serial.print("2SS1"+(String)xx+(String)rpm2_5); Serial.print('\r'); delay(50);} else if (rpm2_5 == 100) {Serial.print("2SS1"+(String)x+(String)rpm2_5); Serial.print('\r'); delay(50);} if (way2_5 == 0){Serial.print("2J1"); Serial.print('\r'); delay(50);} else if (way2_5 == 1){Serial.print("2K1"); Serial.print('\r'); delay(50);} Serial.print("2H1"); Serial.print('\r'); delay(50);}
    if (rpm3_5 > 0){ if (rpm3_5 < 10) {Serial.print("3SS1"+(String)xxx+(String)rpm3_5); Serial.print('\r'); delay(50);} else if (rpm3_5 > 9 && rpm3_5 <= 99) {Serial.print("3SS1"+(String)xx+(String)rpm3_5); Serial.print('\r'); delay(50);} else if (rpm3_5 == 100) {Serial.print("3SS1"+(String)x+(String)rpm3_5); Serial.print('\r'); delay(50);} if (way3_5 == 0){Serial.print("3J1"); Serial.print('\r'); delay(50);} else if (way3_5 == 1){Serial.print("3K1"); Serial.print('\r'); delay(50);} Serial.print("3H1"); Serial.print('\r'); delay(50);}
    if (rpm4_5 > 0){ if (rpm4_5 < 10) {Serial.print("4SS1"+(String)xxx+(String)rpm4_5); Serial.print('\r'); delay(50);} else if (rpm4_5 > 9 && rpm4_5 <= 99) {Serial.print("4SS1"+(String)xx+(String)rpm4_5); Serial.print('\r'); delay(50);} else if (rpm4_5 == 100) {Serial.print("4SS1"+(String)x+(String)rpm4_5); Serial.print('\r'); delay(50);} if (way4_5 == 0){Serial.print("4J1"); Serial.print('\r'); delay(50);} else if (way4_5 == 1){Serial.print("4K1"); Serial.print('\r'); delay(50);} Serial.print("4H1"); Serial.print('\r'); delay(50);}                                     
                    
    //      digitalWrite(28, LOW); digitalWrite(30, LOW); digitalWrite(32, LOW);  digitalWrite(34, HIGH);
    //if (relay1_5 == 1){ } if (relay2_5 == 1){ } if (relay3_5 == 1){ } if (relay4_5 == 1){digitalWrite(relayExt1, HIGH);} if (relay5_5 == 1){digitalWrite(relayExt2, HIGH);}
    
    lcd.clear(); lcd.setCursor(0, 0); lcd.print(F("==== Step 5 ====")); digitalWrite(relayRead, !relay1_5); digitalWrite(relayValve, !relay2_5); digitalWrite(relayHeat, !relay3_5); digitalWrite(relayExt1, !relay4_5); digitalWrite(relayExt2, !relay5_5);

    servo.attach(pinServo);
    if (relay2_5 == 0){ servo.write(positionOne); }
    else { servo.write(positionTwo); }
    
    for (int i = 0; i <= 255; i++){                        
    if (beep5 == 1 && i == (time5-1)) { digitalWrite(buzzer, HIGH); }                         
    if (digitalRead(buttonCancel) == LOW || parar2 == 1){}  else { if ((i+1) <= time5) { lcd.setCursor(0, 1); lcd.print("Time: "); lcd.print(time5 - i); lcd.print("         "); delay(1000); servo.detach(); while (digitalRead(buttonLedRead) == LOW){ digitalWrite(relayRead, LOW);   lcd.setCursor(12, 1); lcd.print("Read"); if (digitalRead(buttonLedRead) == HIGH){ digitalWrite(relayRead, HIGH);   break; }}     } }
    digitalWrite(buzzer, LOW);     
    }}     
                      
    // Step 6
    if (digitalRead(buttonCancel) == HIGH && parar2 == 0 && time6 > 0){  
    if (rpm1_6 == 0){Serial.print("1I1"); Serial.print('\r'); delay(50);} 
    if (rpm2_6 == 0){Serial.print("2I1"); Serial.print('\r'); delay(50);} 
    if (rpm3_6 == 0){Serial.print("3I1"); Serial.print('\r'); delay(50);} 
    if (rpm4_6 == 0){Serial.print("4I1"); Serial.print('\r'); delay(50);}
    if (rpm1_6 > 0){ if (rpm1_6 < 10) {Serial.print("1SS1"+(String)xxx+(String)rpm1_6); Serial.print('\r'); delay(50);} else if (rpm1_6 > 9 && rpm1_6 <= 99) {Serial.print("1SS1"+(String)xx+(String)rpm1_6); Serial.print('\r'); delay(50);} else if (rpm1_6 == 100) {Serial.print("1SS1"+(String)x+(String)rpm1_6); Serial.print('\r'); delay(50);} if (way1_6 == 0){Serial.print("1J1"); Serial.print('\r'); delay(50);} else if (way1_6 == 1){Serial.print("1K1"); Serial.print('\r'); delay(50);} Serial.print("1H1"); Serial.print('\r'); delay(50);}
    if (rpm2_6 > 0){ if (rpm2_6 < 10) {Serial.print("2SS1"+(String)xxx+(String)rpm2_6); Serial.print('\r'); delay(50);} else if (rpm2_6 > 9 && rpm2_6 <= 99) {Serial.print("2SS1"+(String)xx+(String)rpm2_6); Serial.print('\r'); delay(50);} else if (rpm2_6 == 100) {Serial.print("2SS1"+(String)x+(String)rpm2_6); Serial.print('\r'); delay(50);} if (way2_6 == 0){Serial.print("2J1"); Serial.print('\r'); delay(50);} else if (way2_6 == 1){Serial.print("2K1"); Serial.print('\r'); delay(50);} Serial.print("2H1"); Serial.print('\r'); delay(50);}
    if (rpm3_6 > 0){ if (rpm3_6 < 10) {Serial.print("3SS1"+(String)xxx+(String)rpm3_6); Serial.print('\r'); delay(50);} else if (rpm3_6 > 9 && rpm3_6 <= 99) {Serial.print("3SS1"+(String)xx+(String)rpm3_6); Serial.print('\r'); delay(50);} else if (rpm3_6 == 100) {Serial.print("3SS1"+(String)x+(String)rpm3_6); Serial.print('\r'); delay(50);} if (way3_6 == 0){Serial.print("3J1"); Serial.print('\r'); delay(50);} else if (way3_6 == 1){Serial.print("3K1"); Serial.print('\r'); delay(50);} Serial.print("3H1"); Serial.print('\r'); delay(50);}
    if (rpm4_6 > 0){ if (rpm4_6 < 10) {Serial.print("4SS1"+(String)xxx+(String)rpm4_6); Serial.print('\r'); delay(50);} else if (rpm4_6 > 9 && rpm4_6 <= 99) {Serial.print("4SS1"+(String)xx+(String)rpm4_6); Serial.print('\r'); delay(50);} else if (rpm4_6 == 100) {Serial.print("4SS1"+(String)x+(String)rpm4_6); Serial.print('\r'); delay(50);} if (way4_6 == 0){Serial.print("4J1"); Serial.print('\r'); delay(50);} else if (way4_6 == 1){Serial.print("4K1"); Serial.print('\r'); delay(50);} Serial.print("4H1"); Serial.print('\r'); delay(50);}                                   
                        
    //      digitalWrite(28, LOW); digitalWrite(30, LOW); digitalWrite(32, LOW); digitalWrite(34, HIGH);
    //if (relay1_6 == 1){ } if (relay2_6 == 1){ } if (relay3_6 == 1){ } if (relay4_6 == 1){digitalWrite(relayExt1, HIGH);} if (relay5_6 == 1){digitalWrite(relayExt2, HIGH);}
    
    lcd.clear(); lcd.setCursor(0, 0); lcd.print(F("==== Step 6 ====")); digitalWrite(relayRead, !relay1_6); digitalWrite(relayValve, !relay2_6); digitalWrite(relayHeat, !relay3_6); digitalWrite(relayExt1, !relay4_6); digitalWrite(relayExt2, !relay5_6);

    servo.attach(pinServo);
    if (relay2_6 == 0){ servo.write(positionOne); }
    else { servo.write(positionTwo); }
    
    for (int i = 0; i <= 255; i++){                        
    if (beep6 == 1 && i == (time6-1)) { digitalWrite(buzzer, HIGH); }                        
    if (digitalRead(buttonCancel) == LOW || parar2 == 1){}  else { if ((i+1) <= time6) { lcd.setCursor(0, 1); lcd.print("Time: "); lcd.print(time6 - i); lcd.print("         "); delay(1000); servo.detach(); while (digitalRead(buttonLedRead) == LOW){ digitalWrite(relayRead, LOW);   lcd.setCursor(12, 1); lcd.print("Read"); if (digitalRead(buttonLedRead) == HIGH){ digitalWrite(relayRead, HIGH);   break; }}     } }
    digitalWrite(buzzer, LOW);     
    }}                         
                            
    // Step 7
    if (digitalRead(buttonCancel) == HIGH && parar2 == 0 && time7 > 0){ 
    if (rpm1_7 == 0){Serial.print("1I1"); Serial.print('\r'); delay(50);} 
    if (rpm2_7 == 0){Serial.print("2I1"); Serial.print('\r'); delay(50);} 
    if (rpm3_7 == 0){Serial.print("3I1"); Serial.print('\r'); delay(50);} 
    if (rpm4_7 == 0){Serial.print("4I1"); Serial.print('\r'); delay(50);}
    if (rpm1_7 > 0){ if (rpm1_7 < 10) {Serial.print("1SS1"+(String)xxx+(String)rpm1_7); Serial.print('\r'); delay(50);} else if (rpm1_7 > 9 && rpm1_7 <= 99) {Serial.print("1SS1"+(String)xx+(String)rpm1_7); Serial.print('\r'); delay(50);} else if (rpm1_7 == 100) {Serial.print("1SS1"+(String)x+(String)rpm1_7); Serial.print('\r'); delay(50);} if (way1_7 == 0){Serial.print("1J1"); Serial.print('\r'); delay(50);} else if (way1_7 == 1){Serial.print("1K1"); Serial.print('\r'); delay(50);} Serial.print("1H1"); Serial.print('\r'); delay(50);}
    if (rpm2_7 > 0){ if (rpm2_7 < 10) {Serial.print("2SS1"+(String)xxx+(String)rpm2_7); Serial.print('\r'); delay(50);} else if (rpm2_7 > 9 && rpm2_7 <= 99) {Serial.print("2SS1"+(String)xx+(String)rpm2_7); Serial.print('\r'); delay(50);} else if (rpm2_7 == 100) {Serial.print("2SS1"+(String)x+(String)rpm2_7); Serial.print('\r'); delay(50);} if (way2_7 == 0){Serial.print("2J1"); Serial.print('\r'); delay(50);} else if (way2_7 == 1){Serial.print("2K1"); Serial.print('\r'); delay(50);} Serial.print("2H1"); Serial.print('\r'); delay(50);}
    if (rpm3_7 > 0){ if (rpm3_7 < 10) {Serial.print("3SS1"+(String)xxx+(String)rpm3_7); Serial.print('\r'); delay(50);} else if (rpm3_7 > 9 && rpm3_7 <= 99) {Serial.print("3SS1"+(String)xx+(String)rpm3_7); Serial.print('\r'); delay(50);} else if (rpm3_7 == 100) {Serial.print("3SS1"+(String)x+(String)rpm3_7); Serial.print('\r'); delay(50);} if (way3_7 == 0){Serial.print("3J1"); Serial.print('\r'); delay(50);} else if (way3_7 == 1){Serial.print("3K1"); Serial.print('\r'); delay(50);} Serial.print("3H1"); Serial.print('\r'); delay(50);}
    if (rpm4_7 > 0){ if (rpm4_7 < 10) {Serial.print("4SS1"+(String)xxx+(String)rpm4_7); Serial.print('\r'); delay(50);} else if (rpm4_7 > 9 && rpm4_7 <= 99) {Serial.print("4SS1"+(String)xx+(String)rpm4_7); Serial.print('\r'); delay(50);} else if (rpm4_7 == 100) {Serial.print("4SS1"+(String)x+(String)rpm4_7); Serial.print('\r'); delay(50);} if (way4_7 == 0){Serial.print("4J1"); Serial.print('\r'); delay(50);} else if (way4_7 == 1){Serial.print("4K1"); Serial.print('\r'); delay(50);} Serial.print("4H1"); Serial.print('\r'); delay(50);}                                    
                            
    //      digitalWrite(28, LOW); digitalWrite(30, LOW); digitalWrite(32, LOW); digitalWrite(34, HIGH);
    //if (relay1_7 == 1){ } if (relay2_7 == 1){ } if (relay3_7 == 1){ } if (relay4_7 == 1){digitalWrite(relayExt1, HIGH);} if (relay5_7 == 1){digitalWrite(relayExt2, HIGH);}
    
    lcd.clear(); lcd.setCursor(0, 0); lcd.print(F("==== Step 7 ====")); digitalWrite(relayRead, !relay1_7); digitalWrite(relayValve, !relay2_7); digitalWrite(relayHeat, !relay3_7); digitalWrite(relayExt1, !relay4_7); digitalWrite(relayExt2, !relay5_7);

    servo.attach(pinServo);
    if (relay2_7 == 0){ servo.write(positionOne); }
    else { servo.write(positionTwo); }
    
    for (int i = 0; i <= 255; i++){                        
    if (beep7 == 1 && i == (time7-1)) { digitalWrite(buzzer, HIGH); }                         
    if (digitalRead(buttonCancel) == LOW || parar2 == 1){}  else { if ((i+1) <= time7) { lcd.setCursor(0, 1); lcd.print("Time: "); lcd.print(time7 - i); lcd.print("         "); delay(1000); servo.detach(); while (digitalRead(buttonLedRead) == LOW){ digitalWrite(relayRead, LOW);   lcd.setCursor(12, 1); lcd.print("Read"); if (digitalRead(buttonLedRead) == HIGH){ digitalWrite(relayRead, HIGH);   break; }}     } }
    digitalWrite(buzzer, LOW);      
    }} 
                                         
    // Step 8
    if (digitalRead(buttonCancel) == HIGH && parar2 == 0 && time8 > 0){
    if (rpm1_8 == 0){Serial.print("1I1"); Serial.print('\r'); delay(50);} 
    if (rpm2_8 == 0){Serial.print("2I1"); Serial.print('\r'); delay(50);} 
    if (rpm3_8 == 0){Serial.print("3I1"); Serial.print('\r'); delay(50);} 
    if (rpm4_8 == 0){Serial.print("4I1"); Serial.print('\r'); delay(50);}
    if (rpm1_8 > 0){ if (rpm1_8 < 10) {Serial.print("1SS1"+(String)xxx+(String)rpm1_8); Serial.print('\r'); delay(50);} else if (rpm1_8 > 9 && rpm1_8 <= 99) {Serial.print("1SS1"+(String)xx+(String)rpm1_8); Serial.print('\r'); delay(50);} else if (rpm1_8 == 100) {Serial.print("1SS1"+(String)x+(String)rpm1_8); Serial.print('\r'); delay(50);} if (way1_8 == 0){Serial.print("1J1"); Serial.print('\r'); delay(50);} else if (way1_8 == 1){Serial.print("1K1"); Serial.print('\r'); delay(50);} Serial.print("1H1"); Serial.print('\r'); delay(50);}
    if (rpm2_8 > 0){ if (rpm2_8 < 10) {Serial.print("2SS1"+(String)xxx+(String)rpm2_8); Serial.print('\r'); delay(50);} else if (rpm2_8 > 9 && rpm2_8 <= 99) {Serial.print("2SS1"+(String)xx+(String)rpm2_8); Serial.print('\r'); delay(50);} else if (rpm2_8 == 100) {Serial.print("2SS1"+(String)x+(String)rpm2_8); Serial.print('\r'); delay(50);} if (way2_8 == 0){Serial.print("2J1"); Serial.print('\r'); delay(50);} else if (way2_8 == 1){Serial.print("2K1"); Serial.print('\r'); delay(50);} Serial.print("2H1"); Serial.print('\r'); delay(50);}
    if (rpm3_8 > 0){ if (rpm3_8 < 10) {Serial.print("3SS1"+(String)xxx+(String)rpm3_8); Serial.print('\r'); delay(50);} else if (rpm3_8 > 9 && rpm3_8 <= 99) {Serial.print("3SS1"+(String)xx+(String)rpm3_8); Serial.print('\r'); delay(50);} else if (rpm3_8 == 100) {Serial.print("3SS1"+(String)x+(String)rpm3_8); Serial.print('\r'); delay(50);} if (way3_8 == 0){Serial.print("3J1"); Serial.print('\r'); delay(50);} else if (way3_8 == 1){Serial.print("3K1"); Serial.print('\r'); delay(50);} Serial.print("3H1"); Serial.print('\r'); delay(50);}
    if (rpm4_8 > 0){ if (rpm4_8 < 10) {Serial.print("4SS1"+(String)xxx+(String)rpm4_8); Serial.print('\r'); delay(50);} else if (rpm4_8 > 9 && rpm4_8 <= 99) {Serial.print("4SS1"+(String)xx+(String)rpm4_8); Serial.print('\r'); delay(50);} else if (rpm4_8 == 100) {Serial.print("4SS1"+(String)x+(String)rpm4_8); Serial.print('\r'); delay(50);} if (way4_8 == 0){Serial.print("4J1"); Serial.print('\r'); delay(50);} else if (way4_8 == 1){Serial.print("4K1"); Serial.print('\r'); delay(50);} Serial.print("4H1"); Serial.print('\r'); delay(50);}                                     
                                
    //      digitalWrite(28, LOW); digitalWrite(30, LOW); digitalWrite(32, LOW); digitalWrite(34, HIGH);
    //if (relay1_8 == 1){ } if (relay2_8 == 1){ } if (relay3_8 == 1){ } if (relay4_8 == 1){digitalWrite(relayExt1, HIGH);} if (relay5_8 == 1){digitalWrite(relayExt2, HIGH);}
    
    lcd.clear(); lcd.setCursor(0, 0); lcd.print(F("==== Step 8 ====")); digitalWrite(relayRead, !relay1_8); digitalWrite(relayValve, !relay2_8); digitalWrite(relayHeat, !relay3_8); digitalWrite(relayExt1, !relay4_8); digitalWrite(relayExt2, !relay5_8);

    servo.attach(pinServo);
    if (relay2_8 == 0){ servo.write(positionOne); }
    else { servo.write(positionTwo); }
    
    for (int i = 0; i <= 255; i++){                        
    if (beep8 == 1 && i == (time8-1)) { digitalWrite(buzzer, HIGH); }                         
    if (digitalRead(buttonCancel) == LOW || parar2 == 1){}  else { if ((i+1) <= time8) { lcd.setCursor(0, 1); lcd.print("Time: "); lcd.print(time8 - i); lcd.print("         "); delay(1000); servo.detach(); while (digitalRead(buttonLedRead) == LOW){ digitalWrite(relayRead, LOW);   lcd.setCursor(12, 1); lcd.print("Read"); if (digitalRead(buttonLedRead) == HIGH){ digitalWrite(relayRead, HIGH);   break; }}     } }
    digitalWrite(buzzer, LOW);       
    }}                                      
                                         
    // Step 9
    if (digitalRead(buttonCancel) == HIGH && parar2 == 0 && time9 > 0){
    if (rpm1_9 == 0){Serial.print("1I1"); Serial.print('\r'); delay(50);} 
    if (rpm2_9 == 0){Serial.print("2I1"); Serial.print('\r'); delay(50);} 
    if (rpm3_9 == 0){Serial.print("3I1"); Serial.print('\r'); delay(50);} 
    if (rpm4_9 == 0){Serial.print("4I1"); Serial.print('\r'); delay(50);}
    if (rpm1_9 > 0){ if (rpm1_9 < 10) {Serial.print("1SS1"+(String)xxx+(String)rpm1_9); Serial.print('\r'); delay(50);} else if (rpm1_9 > 9 && rpm1_9 <= 99) {Serial.print("1SS1"+(String)xx+(String)rpm1_9); Serial.print('\r'); delay(50);} else if (rpm1_9 == 100) {Serial.print("1SS1"+(String)x+(String)rpm1_9); Serial.print('\r'); delay(50);} if (way1_9 == 0){Serial.print("1J1"); Serial.print('\r'); delay(50);} else if (way1_9 == 1){Serial.print("1K1"); Serial.print('\r'); delay(50);} Serial.print("1H1"); Serial.print('\r'); delay(50);}
    if (rpm2_9 > 0){ if (rpm2_9 < 10) {Serial.print("2SS1"+(String)xxx+(String)rpm2_9); Serial.print('\r'); delay(50);} else if (rpm2_9 > 9 && rpm2_9 <= 99) {Serial.print("2SS1"+(String)xx+(String)rpm2_9); Serial.print('\r'); delay(50);} else if (rpm2_9 == 100) {Serial.print("2SS1"+(String)x+(String)rpm2_9); Serial.print('\r'); delay(50);} if (way2_9 == 0){Serial.print("2J1"); Serial.print('\r'); delay(50);} else if (way2_9 == 1){Serial.print("2K1"); Serial.print('\r'); delay(50);} Serial.print("2H1"); Serial.print('\r'); delay(50);}
    if (rpm3_9 > 0){ if (rpm3_9 < 10) {Serial.print("3SS1"+(String)xxx+(String)rpm3_9); Serial.print('\r'); delay(50);} else if (rpm3_9 > 9 && rpm3_9 <= 99) {Serial.print("3SS1"+(String)xx+(String)rpm3_9); Serial.print('\r'); delay(50);} else if (rpm3_9 == 100) {Serial.print("3SS1"+(String)x+(String)rpm3_9); Serial.print('\r'); delay(50);} if (way3_9 == 0){Serial.print("3J1"); Serial.print('\r'); delay(50);} else if (way3_9 == 1){Serial.print("3K1"); Serial.print('\r'); delay(50);} Serial.print("3H1"); Serial.print('\r'); delay(50);}
    if (rpm4_9 > 0){ if (rpm4_9 < 10) {Serial.print("4SS1"+(String)xxx+(String)rpm4_9); Serial.print('\r'); delay(50);} else if (rpm4_9 > 9 && rpm4_9 <= 99) {Serial.print("4SS1"+(String)xx+(String)rpm4_9); Serial.print('\r'); delay(50);} else if (rpm4_9 == 100) {Serial.print("4SS1"+(String)x+(String)rpm4_9); Serial.print('\r'); delay(50);} if (way4_9 == 0){Serial.print("4J1"); Serial.print('\r'); delay(50);} else if (way4_9 == 1){Serial.print("4K1"); Serial.print('\r'); delay(50);} Serial.print("4H1"); Serial.print('\r'); delay(50);}                                     
                                    
    //      digitalWrite(28, LOW); digitalWrite(30, LOW); digitalWrite(32, LOW); digitalWrite(34, HIGH);
    //if (relay1_9 == 1){ } if (relay2_9 == 1){ } if (relay3_9 == 1){ } if (relay4_9 == 1){digitalWrite(relayExt1, HIGH);} if (relay5_9 == 1){digitalWrite(relayExt2, HIGH);}
    
    lcd.clear(); lcd.setCursor(0, 0); lcd.print(F("==== Step 9 ====")); digitalWrite(relayRead, !relay1_9); digitalWrite(relayValve, !relay2_9); digitalWrite(relayHeat, !relay3_9); digitalWrite(relayExt1, !relay4_9); digitalWrite(relayExt2, !relay5_9);

    servo.attach(pinServo);
    if (relay2_9 == 0){ servo.write(positionOne); }
    else { servo.write(positionTwo); }
    
    for (int i = 0; i <= 255; i++){                        
    if (beep9 == 1 && i == (time9-1)) { digitalWrite(buzzer, HIGH); }                        
    if (digitalRead(buttonCancel) == LOW || parar2 == 1){}  else { if ((i+1) <= time9) { lcd.setCursor(0, 1); lcd.print("Time: "); lcd.print(time9 - i); lcd.print("         "); delay(1000); servo.detach(); while (digitalRead(buttonLedRead) == LOW){ digitalWrite(relayRead, LOW);   lcd.setCursor(12, 1); lcd.print("Read"); if (digitalRead(buttonLedRead) == HIGH){ digitalWrite(relayRead, HIGH);   break; }}     } }
    digitalWrite(buzzer, LOW);       
    }}   
                                         
    // Step 10
    if (digitalRead(buttonCancel) == HIGH && parar2 == 0 && time10 > 0){
    if (rpm1_10 == 0){Serial.print("1I1"); Serial.print('\r'); delay(50);} 
    if (rpm2_10 == 0){Serial.print("2I1"); Serial.print('\r'); delay(50);} 
    if (rpm3_10 == 0){Serial.print("3I1"); Serial.print('\r'); delay(50);} 
    if (rpm4_10 == 0){Serial.print("4I1"); Serial.print('\r'); delay(50);}
    if (rpm1_10 > 0){ if (rpm1_10 < 10) {Serial.print("1SS1"+(String)xxx+(String)rpm1_10); Serial.print('\r'); delay(50);} else if (rpm1_10 > 9 && rpm1_10 <= 99) {Serial.print("1SS1"+(String)xx+(String)rpm1_10); Serial.print('\r'); delay(50);} else if (rpm1_10 == 100) {Serial.print("1SS1"+(String)x+(String)rpm1_10); Serial.print('\r'); delay(50);} if (way1_10 == 0){Serial.print("1J1"); Serial.print('\r'); delay(50);} else if (way1_10 == 1){Serial.print("1K1"); Serial.print('\r'); delay(50);} Serial.print("1H1"); Serial.print('\r'); delay(50);}
    if (rpm2_10 > 0){ if (rpm2_10 < 10) {Serial.print("2SS1"+(String)xxx+(String)rpm2_10); Serial.print('\r'); delay(50);} else if (rpm2_10 > 9 && rpm2_10 <= 99) {Serial.print("2SS1"+(String)xx+(String)rpm2_10); Serial.print('\r'); delay(50);} else if (rpm2_10 == 100) {Serial.print("2SS1"+(String)x+(String)rpm2_10); Serial.print('\r'); delay(50);} if (way2_10 == 0){Serial.print("2J1"); Serial.print('\r'); delay(50);} else if (way2_10 == 1){Serial.print("2K1"); Serial.print('\r'); delay(50);} Serial.print("2H1"); Serial.print('\r'); delay(50);}
    if (rpm3_10 > 0){ if (rpm3_10 < 10) {Serial.print("3SS1"+(String)xxx+(String)rpm3_10); Serial.print('\r'); delay(50);} else if (rpm3_10 > 9 && rpm3_10 <= 99) {Serial.print("3SS1"+(String)xx+(String)rpm3_10); Serial.print('\r'); delay(50);} else if (rpm3_10 == 100) {Serial.print("3SS1"+(String)x+(String)rpm3_10); Serial.print('\r'); delay(50);} if (way3_10 == 0){Serial.print("3J1"); Serial.print('\r'); delay(50);} else if (way3_10 == 1){Serial.print("3K1"); Serial.print('\r'); delay(50);} Serial.print("3H1"); Serial.print('\r'); delay(50);}
    if (rpm4_10 > 0){ if (rpm4_10 < 10) {Serial.print("4SS1"+(String)xxx+(String)rpm4_10); Serial.print('\r'); delay(50);} else if (rpm4_10 > 9 && rpm4_10 <= 99) {Serial.print("4SS1"+(String)xx+(String)rpm4_10); Serial.print('\r'); delay(50);} else if (rpm4_10 == 100) {Serial.print("4SS1"+(String)x+(String)rpm4_10); Serial.print('\r'); delay(50);} if (way4_10 == 0){Serial.print("4J1"); Serial.print('\r'); delay(50);} else if (way4_10 == 1){Serial.print("4K1"); Serial.print('\r'); delay(50);} Serial.print("4H1"); Serial.print('\r'); delay(50);}                                     
                                        
    //      digitalWrite(28, LOW); digitalWrite(30, LOW); digitalWrite(32, LOW); digitalWrite(34, HIGH);
    //if (relay1_10 == 1){ } if (relay2_10 == 1){ } if (relay3_10 == 1){ } if (relay4_10 == 1){digitalWrite(relayExt1, HIGH);} if (relay5_10 == 1){digitalWrite(relayExt2, HIGH);}
    
    lcd.clear(); lcd.setCursor(0, 0); lcd.print(F("==== Step10 ====")); digitalWrite(relayRead, !relay1_10); digitalWrite(relayValve, !relay2_10); digitalWrite(relayHeat, !relay3_10); digitalWrite(relayExt1, !relay4_10); digitalWrite(relayExt2, !relay5_10);

    servo.attach(pinServo);
    if (relay2_10 == 0){ servo.write(positionOne); }
    else { servo.write(positionTwo); }
    
    for (int i = 0; i <= 255; i++){                        
    if (beep10 == 1 && i == (time10-1)) { digitalWrite(buzzer, HIGH); }                         
    if (digitalRead(buttonCancel) == LOW || parar2 == 1){}  else { if ((i+1) <= time10) { lcd.setCursor(0, 1); lcd.print("Time: "); lcd.print(time10 - i); lcd.print("         "); delay(1000); servo.detach(); while (digitalRead(buttonLedRead) == LOW){ digitalWrite(relayRead, LOW);   lcd.setCursor(12, 1); lcd.print("Read"); if (digitalRead(buttonLedRead) == HIGH){ digitalWrite(relayRead, HIGH);   break; }}     } }
    digitalWrite(buzzer, LOW);    
    }} 
                                         
    // Step 11
    if (digitalRead(buttonCancel) == HIGH && parar2 == 0 && time11 > 0){
    if (rpm1_11 == 0){Serial.print("1I1"); Serial.print('\r'); delay(50);} 
    if (rpm2_11 == 0){Serial.print("2I1"); Serial.print('\r'); delay(50);} 
    if (rpm3_11 == 0){Serial.print("3I1"); Serial.print('\r'); delay(50);} 
    if (rpm4_11 == 0){Serial.print("4I1"); Serial.print('\r'); delay(50);}
    if (rpm1_11 > 0){ if (rpm1_11 < 10) {Serial.print("1SS1"+(String)xxx+(String)rpm1_11); Serial.print('\r'); delay(50);} else if (rpm1_11 > 9 && rpm1_11 <= 99) {Serial.print("1SS1"+(String)xx+(String)rpm1_11); Serial.print('\r'); delay(50);} else if (rpm1_11 == 100) {Serial.print("1SS1"+(String)x+(String)rpm1_11); Serial.print('\r'); delay(50);} if (way1_11 == 0){Serial.print("1J1"); Serial.print('\r'); delay(50);} else if (way1_11 == 1){Serial.print("1K1"); Serial.print('\r'); delay(50);} Serial.print("1H1"); Serial.print('\r'); delay(50);}
    if (rpm2_11 > 0){ if (rpm2_11 < 10) {Serial.print("2SS1"+(String)xxx+(String)rpm2_11); Serial.print('\r'); delay(50);} else if (rpm2_11 > 9 && rpm2_11 <= 99) {Serial.print("2SS1"+(String)xx+(String)rpm2_11); Serial.print('\r'); delay(50);} else if (rpm2_11 == 100) {Serial.print("2SS1"+(String)x+(String)rpm2_11); Serial.print('\r'); delay(50);} if (way2_11 == 0){Serial.print("2J1"); Serial.print('\r'); delay(50);} else if (way2_11 == 1){Serial.print("2K1"); Serial.print('\r'); delay(50);} Serial.print("2H1"); Serial.print('\r'); delay(50);}
    if (rpm3_11 > 0){ if (rpm3_11 < 10) {Serial.print("3SS1"+(String)xxx+(String)rpm3_11); Serial.print('\r'); delay(50);} else if (rpm3_11 > 9 && rpm3_11 <= 99) {Serial.print("3SS1"+(String)xx+(String)rpm3_11); Serial.print('\r'); delay(50);} else if (rpm3_11 == 100) {Serial.print("3SS1"+(String)x+(String)rpm3_11); Serial.print('\r'); delay(50);} if (way3_11 == 0){Serial.print("3J1"); Serial.print('\r'); delay(50);} else if (way3_11 == 1){Serial.print("3K1"); Serial.print('\r'); delay(50);} Serial.print("3H1"); Serial.print('\r'); delay(50);}
    if (rpm4_11 > 0){ if (rpm4_11 < 10) {Serial.print("4SS1"+(String)xxx+(String)rpm4_11); Serial.print('\r'); delay(50);} else if (rpm4_11 > 9 && rpm4_11 <= 99) {Serial.print("4SS1"+(String)xx+(String)rpm4_11); Serial.print('\r'); delay(50);} else if (rpm4_11 == 100) {Serial.print("4SS1"+(String)x+(String)rpm4_11); Serial.print('\r'); delay(50);} if (way4_11 == 0){Serial.print("4J1"); Serial.print('\r'); delay(50);} else if (way4_11 == 1){Serial.print("4K1"); Serial.print('\r'); delay(50);} Serial.print("4H1"); Serial.print('\r'); delay(50);}                                     
                                            
    //      digitalWrite(28, LOW); digitalWrite(30, LOW); digitalWrite(32, LOW); digitalWrite(34, HIGH);
    //if (relay1_11 == 1){ } if (relay2_11 == 1){ } if (relay3_11 == 1){ } if (relay4_11 == 1){digitalWrite(relayExt1, HIGH);} if (relay5_11 == 1){digitalWrite(relayExt2, HIGH);}
    
    lcd.clear(); lcd.setCursor(0, 0); lcd.print(F("==== Step11 ====")); digitalWrite(relayRead, !relay1_11); digitalWrite(relayValve, !relay2_11); digitalWrite(relayHeat, !relay3_11); digitalWrite(relayExt1, !relay4_11); digitalWrite(relayExt2, !relay5_11);

    servo.attach(pinServo);
    if (relay2_11 == 0){ servo.write(positionOne); }
    else { servo.write(positionTwo); }
    
    for (int i = 0; i <= 255; i++){                        
    if (beep11 == 1 && i == (time11-1)) { digitalWrite(buzzer, HIGH); }                        
    if (digitalRead(buttonCancel) == LOW || parar2 == 1){}  else { if ((i+1) <= time11) { lcd.setCursor(0, 1); lcd.print("Time: "); lcd.print(time11 - i); lcd.print("         "); delay(1000); servo.detach(); while (digitalRead(buttonLedRead) == LOW){ digitalWrite(relayRead, LOW);   lcd.setCursor(12, 1); lcd.print("Read"); if (digitalRead(buttonLedRead) == HIGH){ digitalWrite(relayRead, HIGH);   break; }}     } }
    digitalWrite(buzzer, LOW); 
    }}                                     
    
    // Step 12
    if (digitalRead(buttonCancel) == HIGH && parar2 == 0 && time12 > 0){
    if (rpm1_12 == 0){Serial.print("1I1"); Serial.print('\r'); delay(50);} 
    if (rpm2_12 == 0){Serial.print("2I1"); Serial.print('\r'); delay(50);} 
    if (rpm3_12 == 0){Serial.print("3I1"); Serial.print('\r'); delay(50);} 
    if (rpm4_12 == 0){Serial.print("4I1"); Serial.print('\r'); delay(50);}
    if (rpm1_12 > 0){ if (rpm1_12 < 10) {Serial.print("1SS1"+(String)xxx+(String)rpm1_12); Serial.print('\r'); delay(50);} else if (rpm1_12 > 9 && rpm1_12 <= 99) {Serial.print("1SS1"+(String)xx+(String)rpm1_12); Serial.print('\r'); delay(50);} else if (rpm1_12 == 100) {Serial.print("1SS1"+(String)x+(String)rpm1_12); Serial.print('\r'); delay(50);} if (way1_12 == 0){Serial.print("1J1"); Serial.print('\r'); delay(50);} else if (way1_12 == 1){Serial.print("1K1"); Serial.print('\r'); delay(50);} Serial.print("1H1"); Serial.print('\r'); delay(50);}
    if (rpm2_12 > 0){ if (rpm2_12 < 10) {Serial.print("2SS1"+(String)xxx+(String)rpm2_12); Serial.print('\r'); delay(50);} else if (rpm2_12 > 9 && rpm2_12 <= 99) {Serial.print("2SS1"+(String)xx+(String)rpm2_12); Serial.print('\r'); delay(50);} else if (rpm2_12 == 100) {Serial.print("2SS1"+(String)x+(String)rpm2_12); Serial.print('\r'); delay(50);} if (way2_12 == 0){Serial.print("2J1"); Serial.print('\r'); delay(50);} else if (way2_12 == 1){Serial.print("2K1"); Serial.print('\r'); delay(50);} Serial.print("2H1"); Serial.print('\r'); delay(50);}
    if (rpm3_12 > 0){ if (rpm3_12 < 10) {Serial.print("3SS1"+(String)xxx+(String)rpm3_12); Serial.print('\r'); delay(50);} else if (rpm3_12 > 9 && rpm3_12 <= 99) {Serial.print("3SS1"+(String)xx+(String)rpm3_12); Serial.print('\r'); delay(50);} else if (rpm3_12 == 100) {Serial.print("3SS1"+(String)x+(String)rpm3_12); Serial.print('\r'); delay(50);} if (way3_12 == 0){Serial.print("3J1"); Serial.print('\r'); delay(50);} else if (way3_12 == 1){Serial.print("3K1"); Serial.print('\r'); delay(50);} Serial.print("3H1"); Serial.print('\r'); delay(50);}
    if (rpm4_12 > 0){ if (rpm4_12 < 10) {Serial.print("4SS1"+(String)xxx+(String)rpm4_12); Serial.print('\r'); delay(50);} else if (rpm4_12 > 9 && rpm4_12 <= 99) {Serial.print("4SS1"+(String)xx+(String)rpm4_12); Serial.print('\r'); delay(50);} else if (rpm4_12 == 100) {Serial.print("4SS1"+(String)x+(String)rpm4_12); Serial.print('\r'); delay(50);} if (way4_12 == 0){Serial.print("4J1"); Serial.print('\r'); delay(50);} else if (way4_12 == 1){Serial.print("4K1"); Serial.print('\r'); delay(50);} Serial.print("4H1"); Serial.print('\r'); delay(50);}                                     
                                                
    //      digitalWrite(28, LOW); digitalWrite(30, LOW); digitalWrite(32, LOW); digitalWrite(34, HIGH);
    //if (relay1_12 == 1){ } if (relay2_12 == 1){ } if (relay3_12 == 1){ } if (relay4_12 == 1){digitalWrite(relayExt1, HIGH);} if (relay5_12 == 1){digitalWrite(relayExt2, HIGH);}
    
    lcd.clear(); lcd.setCursor(0, 0); lcd.print(F("==== Step12 ====")); digitalWrite(relayRead, !relay1_12); digitalWrite(relayValve, !relay2_12); digitalWrite(relayHeat, !relay3_12); digitalWrite(relayExt1, !relay4_12); digitalWrite(relayExt2, !relay5_12);

    servo.attach(pinServo);
    if (relay2_12 == 0){ servo.write(positionOne); }
    else { servo.write(positionTwo); }
    
    for (int i = 0; i <= 255; i++){                        
    if (beep12 == 1 && i == (time12-1)) { digitalWrite(buzzer, HIGH); }                         
    if (digitalRead(buttonCancel) == LOW || parar2 == 1){}  else { if ((i+1) <= time12) { lcd.setCursor(0, 1); lcd.print("Time: "); lcd.print(time12 - i); lcd.print("         "); delay(1000); servo.detach(); while (digitalRead(buttonLedRead) == LOW){ digitalWrite(relayRead, LOW); lcd.setCursor(12, 1); lcd.print("Read"); if (digitalRead(buttonLedRead) == HIGH){ digitalWrite(relayRead, HIGH); break; }}     } }
    digitalWrite(buzzer, LOW);       
    }} lcd.clear();                                     

                                                      
    //Finish of the program

    lcd.setCursor(0, 0); lcd.print("Finished"); cont++; 
    lcd.setCursor(0, 1); lcd.print("Read: "); lcd.print(cont);
    parar2 = 0;
    
    digitalWrite(relayRead, HIGH); digitalWrite(relayValve, HIGH); digitalWrite(relayHeat, HIGH); digitalWrite(relayExt1, HIGH); digitalWrite(relayExt2, HIGH);
    //Serial.print("1I1"); Serial.print('\r'); delay(50); Serial.print("2I1"); Serial.print('\r'); delay(50); Serial.print("3I1"); Serial.print('\r'); delay(50); Serial.print("4I1"); Serial.print('\r'); delay(50);
    
    digitalWrite(buzzer, HIGH); delay(100); digitalWrite(buzzer, LOW); delay(100); digitalWrite(buzzer, HIGH); delay(100); digitalWrite(buzzer, LOW);
    
    servo.attach(pinServo);
    servo.write(positionOne);
     
    delay(2000);
    
    servo.detach();
    
    lcd.clear();
}



void saveData(){

  if (program == 1){

    // TIME (1–12)
    EEPROM.write(1,  time1);
    EEPROM.write(2,  time2);
    EEPROM.write(3,  time3);
    EEPROM.write(4,  time4);
    EEPROM.write(5,  time5);
    EEPROM.write(6,  time6);
    EEPROM.write(7,  time7);
    EEPROM.write(8,  time8);
    EEPROM.write(9,  time9);
    EEPROM.write(10, time10);
    EEPROM.write(11, time11);
    EEPROM.write(12, time12);

    // BEEP (memoriaBeep)
    EEPROM.write(memoria1beep1, beep1);
    EEPROM.write(memoria1beep2, beep2);
    EEPROM.write(memoria1beep3, beep3);
    EEPROM.write(memoria1beep4, beep4);
    EEPROM.write(memoria1beep5, beep5);
    EEPROM.write(memoria1beep6, beep6);
    EEPROM.write(memoria1beep7, beep7);
    EEPROM.write(memoria1beep8, beep8);
    EEPROM.write(memoria1beep9, beep9);
    EEPROM.write(memoria1beep10, beep10);
    EEPROM.write(memoria1beep11, beep11);
    EEPROM.write(memoria1beep12, beep12);
    
    // RELAY (13–72)
    EEPROM.write(13, relay1_1);
    EEPROM.write(14, relay2_1);
    EEPROM.write(15, relay3_1);
    EEPROM.write(16, relay4_1);
    EEPROM.write(17, relay5_1);
    
    EEPROM.write(18, relay1_2);
    EEPROM.write(19, relay2_2);
    EEPROM.write(20, relay3_2);
    EEPROM.write(21, relay4_2);
    EEPROM.write(22, relay5_2);
    
    EEPROM.write(23, relay1_3);
    EEPROM.write(24, relay2_3);
    EEPROM.write(25, relay3_3);
    EEPROM.write(26, relay4_3);
    EEPROM.write(27, relay5_3);
    
    EEPROM.write(28, relay1_4);
    EEPROM.write(29, relay2_4);
    EEPROM.write(30, relay3_4);
    EEPROM.write(31, relay4_4);
    EEPROM.write(32, relay5_4);
    
    EEPROM.write(33, relay1_5);
    EEPROM.write(34, relay2_5);
    EEPROM.write(35, relay3_5);
    EEPROM.write(36, relay4_5);
    EEPROM.write(37, relay5_5);
    
    EEPROM.write(38, relay1_6);
    EEPROM.write(39, relay2_6);
    EEPROM.write(40, relay3_6);
    EEPROM.write(41, relay4_6);
    EEPROM.write(42, relay5_6);
    
    EEPROM.write(43, relay1_7);
    EEPROM.write(44, relay2_7);
    EEPROM.write(45, relay3_7);
    EEPROM.write(46, relay4_7);
    EEPROM.write(47, relay5_7);
    
    EEPROM.write(48, relay1_8);
    EEPROM.write(49, relay2_8);
    EEPROM.write(50, relay3_8);
    EEPROM.write(51, relay4_8);
    EEPROM.write(52, relay5_8);
    
    EEPROM.write(53, relay1_9);
    EEPROM.write(54, relay2_9);
    EEPROM.write(55, relay3_9);
    EEPROM.write(56, relay4_9);
    EEPROM.write(57, relay5_9);
    
    EEPROM.write(58, relay1_10);
    EEPROM.write(59, relay2_10);
    EEPROM.write(60, relay3_10);
    EEPROM.write(61, relay4_10);
    EEPROM.write(62, relay5_10);
    
    EEPROM.write(63, relay1_11);
    EEPROM.write(64, relay2_11);
    EEPROM.write(65, relay3_11);
    EEPROM.write(66, relay4_11);
    EEPROM.write(67, relay5_11);
    
    EEPROM.write(68, relay1_12);
    EEPROM.write(69, relay2_12);
    EEPROM.write(70, relay3_12);
    EEPROM.write(71, relay4_12);
    EEPROM.write(72, relay5_12);
    
    // WAY (73–120)
    EEPROM.write(73, way1_1);
    EEPROM.write(74, way2_1);
    EEPROM.write(75, way3_1);
    EEPROM.write(76, way4_1);
    
    EEPROM.write(77, way1_2);
    EEPROM.write(78, way2_2);
    EEPROM.write(79, way3_2);
    EEPROM.write(80, way4_2);
    
    EEPROM.write(81, way1_3);
    EEPROM.write(82, way2_3);
    EEPROM.write(83, way3_3);
    EEPROM.write(84, way4_3);
    
    EEPROM.write(85, way1_4);
    EEPROM.write(86, way2_4);
    EEPROM.write(87, way3_4);
    EEPROM.write(88, way4_4);
    
    EEPROM.write(89, way1_5);
    EEPROM.write(90, way2_5);
    EEPROM.write(91, way3_5);
    EEPROM.write(92, way4_5);
    
    EEPROM.write(93, way1_6);
    EEPROM.write(94, way2_6);
    EEPROM.write(95, way3_6);
    EEPROM.write(96, way4_6);
    
    EEPROM.write(97, way1_7);
    EEPROM.write(98, way2_7);
    EEPROM.write(99, way3_7);
    EEPROM.write(100, way4_7);
    
    EEPROM.write(101, way1_8);
    EEPROM.write(102, way2_8);
    EEPROM.write(103, way3_8);
    EEPROM.write(104, way4_8);
    
    EEPROM.write(105, way1_9);
    EEPROM.write(106, way2_9);
    EEPROM.write(107, way3_9);
    EEPROM.write(108, way4_9);
    
    EEPROM.write(109, way1_10);
    EEPROM.write(110, way2_10);
    EEPROM.write(111, way3_10);
    EEPROM.write(112, way4_10);
    
    EEPROM.write(113, way1_11);
    EEPROM.write(114, way2_11);
    EEPROM.write(115, way3_11);
    EEPROM.write(116, way4_11);
    
    EEPROM.write(117, way1_12);
    EEPROM.write(118, way2_12);
    EEPROM.write(119, way3_12);
    EEPROM.write(120, way4_12);
    
    // RPM (121–168)
    EEPROM.write(121, rpm1_1);
    EEPROM.write(122, rpm2_1);
    EEPROM.write(123, rpm3_1);
    EEPROM.write(124, rpm4_1);
    
    EEPROM.write(125, rpm1_2);
    EEPROM.write(126, rpm2_2);
    EEPROM.write(127, rpm3_2);
    EEPROM.write(128, rpm4_2);
    
    EEPROM.write(129, rpm1_3);
    EEPROM.write(130, rpm2_3);
    EEPROM.write(131, rpm3_3);
    EEPROM.write(132, rpm4_3);
    
    EEPROM.write(133, rpm1_4);
    EEPROM.write(134, rpm2_4);
    EEPROM.write(135, rpm3_4);
    EEPROM.write(136, rpm4_4);
    
    EEPROM.write(137, rpm1_5);
    EEPROM.write(138, rpm2_5);
    EEPROM.write(139, rpm3_5);
    EEPROM.write(140, rpm4_5);
    
    EEPROM.write(141, rpm1_6);
    EEPROM.write(142, rpm2_6);
    EEPROM.write(143, rpm3_6);
    EEPROM.write(144, rpm4_6);
    
    EEPROM.write(145, rpm1_7);
    EEPROM.write(146, rpm2_7);
    EEPROM.write(147, rpm3_7);
    EEPROM.write(148, rpm4_7);
    
    EEPROM.write(149, rpm1_8);
    EEPROM.write(150, rpm2_8);
    EEPROM.write(151, rpm3_8);
    EEPROM.write(152, rpm4_8);
    
    EEPROM.write(153, rpm1_9);
    EEPROM.write(154, rpm2_9);
    EEPROM.write(155, rpm3_9);
    EEPROM.write(156, rpm4_9);
    
    EEPROM.write(157, rpm1_10);
    EEPROM.write(158, rpm2_10);
    EEPROM.write(159, rpm3_10);
    EEPROM.write(160, rpm4_10);
    
    EEPROM.write(161, rpm1_11);
    EEPROM.write(162, rpm2_11);
    EEPROM.write(163, rpm3_11);
    EEPROM.write(164, rpm4_11);
    
    EEPROM.write(165, rpm1_12);
    EEPROM.write(166, rpm2_12);
    EEPROM.write(167, rpm3_12);
    EEPROM.write(168, rpm4_12);

    EEPROM.commit();
}

  if (program == 2){

    // TIME (169–180)
    EEPROM.write(169,  time1);
    EEPROM.write(170,  time2);
    EEPROM.write(171,  time3);
    EEPROM.write(172,  time4);
    EEPROM.write(173,  time5);
    EEPROM.write(174,  time6);
    EEPROM.write(175,  time7);
    EEPROM.write(176,  time8);
    EEPROM.write(177,  time9);
    EEPROM.write(178, time10);
    EEPROM.write(179, time11);
    EEPROM.write(180, time12);

    // BEEP (memoriaBeep)
    EEPROM.write(memoria2beep1, beep1);
    EEPROM.write(memoria2beep2, beep2);
    EEPROM.write(memoria2beep3, beep3);
    EEPROM.write(memoria2beep4, beep4);
    EEPROM.write(memoria2beep5, beep5);
    EEPROM.write(memoria2beep6, beep6);
    EEPROM.write(memoria2beep7, beep7);
    EEPROM.write(memoria2beep8, beep8);
    EEPROM.write(memoria2beep9, beep9);
    EEPROM.write(memoria2beep10, beep10);
    EEPROM.write(memoria2beep11, beep11);
    EEPROM.write(memoria2beep12, beep12);
    
    // RELAY (181–240)
    EEPROM.write(181, relay1_1);
    EEPROM.write(182, relay2_1);
    EEPROM.write(183, relay3_1);
    EEPROM.write(184, relay4_1);
    EEPROM.write(185, relay5_1);
    
    EEPROM.write(186, relay1_2);
    EEPROM.write(187, relay2_2);
    EEPROM.write(188, relay3_2);
    EEPROM.write(189, relay4_2);
    EEPROM.write(190, relay5_2);
    
    EEPROM.write(191, relay1_3);
    EEPROM.write(192, relay2_3);
    EEPROM.write(193, relay3_3);
    EEPROM.write(194, relay4_3);
    EEPROM.write(195, relay5_3);
    
    EEPROM.write(196, relay1_4);
    EEPROM.write(197, relay2_4);
    EEPROM.write(198, relay3_4);
    EEPROM.write(199, relay4_4);
    EEPROM.write(200, relay5_4);
    
    EEPROM.write(201, relay1_5);
    EEPROM.write(202, relay2_5);
    EEPROM.write(203, relay3_5);
    EEPROM.write(204, relay4_5);
    EEPROM.write(205, relay5_5);
    
    EEPROM.write(206, relay1_6);
    EEPROM.write(207, relay2_6);
    EEPROM.write(208, relay3_6);
    EEPROM.write(209, relay4_6);
    EEPROM.write(210, relay5_6);
    
    EEPROM.write(211, relay1_7);
    EEPROM.write(212, relay2_7);
    EEPROM.write(213, relay3_7);
    EEPROM.write(214, relay4_7);
    EEPROM.write(215, relay5_7);
    
    EEPROM.write(216, relay1_8);
    EEPROM.write(217, relay2_8);
    EEPROM.write(218, relay3_8);
    EEPROM.write(219, relay4_8);
    EEPROM.write(220, relay5_8);
    
    EEPROM.write(221, relay1_9);
    EEPROM.write(222, relay2_9);
    EEPROM.write(223, relay3_9);
    EEPROM.write(224, relay4_9);
    EEPROM.write(225, relay5_9);
    
    EEPROM.write(226, relay1_10);
    EEPROM.write(227, relay2_10);
    EEPROM.write(228, relay3_10);
    EEPROM.write(229, relay4_10);
    EEPROM.write(230, relay5_10);
    
    EEPROM.write(231, relay1_11);
    EEPROM.write(232, relay2_11);
    EEPROM.write(233, relay3_11);
    EEPROM.write(234, relay4_11);
    EEPROM.write(235, relay5_11);
    
    EEPROM.write(236, relay1_12);
    EEPROM.write(237, relay2_12);
    EEPROM.write(238, relay3_12);
    EEPROM.write(239, relay4_12);
    EEPROM.write(240, relay5_12);
    
    // WAY (241–288)
    EEPROM.write(241, way1_1);
    EEPROM.write(242, way2_1);
    EEPROM.write(243, way3_1);
    EEPROM.write(244, way4_1);
    
    EEPROM.write(245, way1_2);
    EEPROM.write(246, way2_2);
    EEPROM.write(247, way3_2);
    EEPROM.write(248, way4_2);
    
    EEPROM.write(249, way1_3);
    EEPROM.write(250, way2_3);
    EEPROM.write(251, way3_3);
    EEPROM.write(252, way4_3);
    
    EEPROM.write(253, way1_4);
    EEPROM.write(254, way2_4);
    EEPROM.write(255, way3_4);
    EEPROM.write(256, way4_4);
    
    EEPROM.write(257, way1_5);
    EEPROM.write(258, way2_5);
    EEPROM.write(259, way3_5);
    EEPROM.write(260, way4_5);
    
    EEPROM.write(261, way1_6);
    EEPROM.write(262, way2_6);
    EEPROM.write(263, way3_6);
    EEPROM.write(264, way4_6);
    
    EEPROM.write(265, way1_7);
    EEPROM.write(266, way2_7);
    EEPROM.write(267, way3_7);
    EEPROM.write(268, way4_7);
    
    EEPROM.write(269, way1_8);
    EEPROM.write(270, way2_8);
    EEPROM.write(271, way3_8);
    EEPROM.write(272, way4_8);
    
    EEPROM.write(273, way1_9);
    EEPROM.write(274, way2_9);
    EEPROM.write(275, way3_9);
    EEPROM.write(276, way4_9);
    
    EEPROM.write(277, way1_10);
    EEPROM.write(278, way2_10);
    EEPROM.write(279, way3_10);
    EEPROM.write(280, way4_10);
    
    EEPROM.write(281, way1_11);
    EEPROM.write(282, way2_11);
    EEPROM.write(283, way3_11);
    EEPROM.write(284, way4_11);
    
    EEPROM.write(285, way1_12);
    EEPROM.write(286, way2_12);
    EEPROM.write(287, way3_12);
    EEPROM.write(288, way4_12);
    
    // RPM (289–336)
    EEPROM.write(289, rpm1_1);
    EEPROM.write(290, rpm2_1);
    EEPROM.write(291, rpm3_1);
    EEPROM.write(292, rpm4_1);
    
    EEPROM.write(293, rpm1_2);
    EEPROM.write(294, rpm2_2);
    EEPROM.write(295, rpm3_2);
    EEPROM.write(296, rpm4_2);
    
    EEPROM.write(297, rpm1_3);
    EEPROM.write(298, rpm2_3);
    EEPROM.write(299, rpm3_3);
    EEPROM.write(300, rpm4_3);
    
    EEPROM.write(301, rpm1_4);
    EEPROM.write(302, rpm2_4);
    EEPROM.write(303, rpm3_4);
    EEPROM.write(304, rpm4_4);
    
    EEPROM.write(305, rpm1_5);
    EEPROM.write(306, rpm2_5);
    EEPROM.write(307, rpm3_5);
    EEPROM.write(308, rpm4_5);
    
    EEPROM.write(309, rpm1_6);
    EEPROM.write(310, rpm2_6);
    EEPROM.write(311, rpm3_6);
    EEPROM.write(312, rpm4_6);
    
    EEPROM.write(313, rpm1_7);
    EEPROM.write(314, rpm2_7);
    EEPROM.write(315, rpm3_7);
    EEPROM.write(316, rpm4_7);
    
    EEPROM.write(317, rpm1_8);
    EEPROM.write(318, rpm2_8);
    EEPROM.write(319, rpm3_8);
    EEPROM.write(320, rpm4_8);
    
    EEPROM.write(321, rpm1_9);
    EEPROM.write(322, rpm2_9);
    EEPROM.write(323, rpm3_9);
    EEPROM.write(324, rpm4_9);
    
    EEPROM.write(325, rpm1_10);
    EEPROM.write(326, rpm2_10);
    EEPROM.write(327, rpm3_10);
    EEPROM.write(328, rpm4_10);
    
    EEPROM.write(329, rpm1_11);
    EEPROM.write(330, rpm2_11);
    EEPROM.write(331, rpm3_11);
    EEPROM.write(332, rpm4_11);
    
    EEPROM.write(333, rpm1_12);
    EEPROM.write(334, rpm2_12);
    EEPROM.write(335, rpm3_12);
    EEPROM.write(336, rpm4_12);

    EEPROM.commit();
}



  if (program == 3){

    // TIME (337–348)
    EEPROM.write(337,  time1);
    EEPROM.write(338,  time2);
    EEPROM.write(339,  time3);
    EEPROM.write(340,  time4);
    EEPROM.write(341,  time5);
    EEPROM.write(342,  time6);
    EEPROM.write(343,  time7);
    EEPROM.write(344,  time8);
    EEPROM.write(345,  time9);
    EEPROM.write(346, time10);
    EEPROM.write(347, time11);
    EEPROM.write(348, time12);

    // BEEP (memoriaBeep)
    EEPROM.write(memoria3beep1, beep1);
    EEPROM.write(memoria3beep2, beep2);
    EEPROM.write(memoria3beep3, beep3);
    EEPROM.write(memoria3beep4, beep4);
    EEPROM.write(memoria3beep5, beep5);
    EEPROM.write(memoria3beep6, beep6);
    EEPROM.write(memoria3beep7, beep7);
    EEPROM.write(memoria3beep8, beep8);
    EEPROM.write(memoria3beep9, beep9);
    EEPROM.write(memoria3beep10, beep10);
    EEPROM.write(memoria3beep11, beep11);
    EEPROM.write(memoria3beep12, beep12);
    
    // RELAY (349–408)
    EEPROM.write(349, relay1_1);
    EEPROM.write(350, relay2_1);
    EEPROM.write(351, relay3_1);
    EEPROM.write(352, relay4_1);
    EEPROM.write(353, relay5_1);
    
    EEPROM.write(354, relay1_2);
    EEPROM.write(355, relay2_2);
    EEPROM.write(356, relay3_2);
    EEPROM.write(357, relay4_2);
    EEPROM.write(358, relay5_2);
    
    EEPROM.write(359, relay1_3);
    EEPROM.write(360, relay2_3);
    EEPROM.write(361, relay3_3);
    EEPROM.write(362, relay4_3);
    EEPROM.write(363, relay5_3);
    
    EEPROM.write(364, relay1_4);
    EEPROM.write(365, relay2_4);
    EEPROM.write(366, relay3_4);
    EEPROM.write(367, relay4_4);
    EEPROM.write(368, relay5_4);
    
    EEPROM.write(369, relay1_5);
    EEPROM.write(370, relay2_5);
    EEPROM.write(371, relay3_5);
    EEPROM.write(372, relay4_5);
    EEPROM.write(373, relay5_5);
    
    EEPROM.write(374, relay1_6);
    EEPROM.write(375, relay2_6);
    EEPROM.write(376, relay3_6);
    EEPROM.write(377, relay4_6);
    EEPROM.write(378, relay5_6);
    
    EEPROM.write(379, relay1_7);
    EEPROM.write(380, relay2_7);
    EEPROM.write(381, relay3_7);
    EEPROM.write(382, relay4_7);
    EEPROM.write(383, relay5_7);
    
    EEPROM.write(384, relay1_8);
    EEPROM.write(385, relay2_8);
    EEPROM.write(386, relay3_8);
    EEPROM.write(387, relay4_8);
    EEPROM.write(388, relay5_8);
    
    EEPROM.write(389, relay1_9);
    EEPROM.write(390, relay2_9);
    EEPROM.write(391, relay3_9);
    EEPROM.write(392, relay4_9);
    EEPROM.write(393, relay5_9);
    
    EEPROM.write(394, relay1_10);
    EEPROM.write(395, relay2_10);
    EEPROM.write(396, relay3_10);
    EEPROM.write(397, relay4_10);
    EEPROM.write(398, relay5_10);
    
    EEPROM.write(399, relay1_11);
    EEPROM.write(400, relay2_11);
    EEPROM.write(401, relay3_11);
    EEPROM.write(402, relay4_11);
    EEPROM.write(403, relay5_11);
    
    EEPROM.write(404, relay1_12);
    EEPROM.write(405, relay2_12);
    EEPROM.write(406, relay3_12);
    EEPROM.write(407, relay4_12);
    EEPROM.write(408, relay5_12);
    
    // WAY (409–456)
    EEPROM.write(409, way1_1);
    EEPROM.write(410, way2_1);
    EEPROM.write(411, way3_1);
    EEPROM.write(412, way4_1);
    
    EEPROM.write(413, way1_2);
    EEPROM.write(414, way2_2);
    EEPROM.write(415, way3_2);
    EEPROM.write(416, way4_2);
    
    EEPROM.write(417, way1_3);
    EEPROM.write(418, way2_3);
    EEPROM.write(419, way3_3);
    EEPROM.write(420, way4_3);
    
    EEPROM.write(421, way1_4);
    EEPROM.write(422, way2_4);
    EEPROM.write(423, way3_4);
    EEPROM.write(424, way4_4);
    
    EEPROM.write(425, way1_5);
    EEPROM.write(426, way2_5);
    EEPROM.write(427, way3_5);
    EEPROM.write(428, way4_5);
    
    EEPROM.write(429, way1_6);
    EEPROM.write(430, way2_6);
    EEPROM.write(431, way3_6);
    EEPROM.write(432, way4_6);
    
    EEPROM.write(433, way1_7);
    EEPROM.write(434, way2_7);
    EEPROM.write(435, way3_7);
    EEPROM.write(436, way4_7);
    
    EEPROM.write(437, way1_8);
    EEPROM.write(438, way2_8);
    EEPROM.write(439, way3_8);
    EEPROM.write(440, way4_8);
    
    EEPROM.write(441, way1_9);
    EEPROM.write(442, way2_9);
    EEPROM.write(443, way3_9);
    EEPROM.write(444, way4_9);
    
    EEPROM.write(445, way1_10);
    EEPROM.write(446, way2_10);
    EEPROM.write(447, way3_10);
    EEPROM.write(448, way4_10);
    
    EEPROM.write(449, way1_11);
    EEPROM.write(450, way2_11);
    EEPROM.write(451, way3_11);
    EEPROM.write(452, way4_11);
    
    EEPROM.write(453, way1_12);
    EEPROM.write(454, way2_12);
    EEPROM.write(455, way3_12);
    EEPROM.write(456, way4_12);
    
    // RPM (457–504)
    EEPROM.write(457, rpm1_1);
    EEPROM.write(458, rpm2_1);
    EEPROM.write(459, rpm3_1);
    EEPROM.write(460, rpm4_1);
    
    EEPROM.write(461, rpm1_2);
    EEPROM.write(462, rpm2_2);
    EEPROM.write(463, rpm3_2);
    EEPROM.write(464, rpm4_2);
    
    EEPROM.write(465, rpm1_3);
    EEPROM.write(466, rpm2_3);
    EEPROM.write(467, rpm3_3);
    EEPROM.write(468, rpm4_3);
    
    EEPROM.write(469, rpm1_4);
    EEPROM.write(470, rpm2_4);
    EEPROM.write(471, rpm3_4);
    EEPROM.write(472, rpm4_4);
    
    EEPROM.write(473, rpm1_5);
    EEPROM.write(474, rpm2_5);
    EEPROM.write(475, rpm3_5);
    EEPROM.write(476, rpm4_5);
    
    EEPROM.write(477, rpm1_6);
    EEPROM.write(478, rpm2_6);
    EEPROM.write(479, rpm3_6);
    EEPROM.write(480, rpm4_6);
    
    EEPROM.write(481, rpm1_7);
    EEPROM.write(482, rpm2_7);
    EEPROM.write(483, rpm3_7);
    EEPROM.write(484, rpm4_7);
    
    EEPROM.write(485, rpm1_8);
    EEPROM.write(486, rpm2_8);
    EEPROM.write(487, rpm3_8);
    EEPROM.write(488, rpm4_8);
    
    EEPROM.write(489, rpm1_9);
    EEPROM.write(490, rpm2_9);
    EEPROM.write(491, rpm3_9);
    EEPROM.write(492, rpm4_9);
    
    EEPROM.write(493, rpm1_10);
    EEPROM.write(494, rpm2_10);
    EEPROM.write(495, rpm3_10);
    EEPROM.write(496, rpm4_10);
    
    EEPROM.write(497, rpm1_11);
    EEPROM.write(498, rpm2_11);
    EEPROM.write(499, rpm3_11);
    EEPROM.write(500, rpm4_11);
    
    EEPROM.write(501, rpm1_12);
    EEPROM.write(502, rpm2_12);
    EEPROM.write(503, rpm3_12);
    EEPROM.write(504, rpm4_12);

    EEPROM.commit();
}

  EEPROM.write(0, program);
  EEPROM.commit();

  lcd.clear(); 
  lcd.setCursor(0,0);                                
  lcd.print(F("Program ")); lcd.print(program); 
  lcd.setCursor(0,1);
  lcd.print(F("was saved"));
  digitalWrite(buzzer, HIGH); delay(100); digitalWrite(buzzer, LOW); delay(100); digitalWrite(buzzer, HIGH); delay(100); digitalWrite(buzzer, LOW);
  delay(2000);
  lcd.clear();
}

void programUpdate(){
      if (program == 1) {
    
    time1 = EEPROM.read(memoria1time1);    
    time2 = EEPROM.read(memoria1time2);
    time3 = EEPROM.read(memoria1time3);
    time4 = EEPROM.read(memoria1time4);
    time5 = EEPROM.read(memoria1time5);
    time6 = EEPROM.read(memoria1time6);    
    time7 = EEPROM.read(memoria1time7);
    time8 = EEPROM.read(memoria1time8);
    time9 = EEPROM.read(memoria1time9);
    time10 = EEPROM.read(memoria1time10);
    time11 = EEPROM.read(memoria1time11);    
    time12 = EEPROM.read(memoria1time12);

    beep1 = EEPROM.read(memoria1beep1);
    beep2 = EEPROM.read(memoria1beep2);
    beep3 = EEPROM.read(memoria1beep3);
    beep4 = EEPROM.read(memoria1beep4);
    beep5 = EEPROM.read(memoria1beep5);
    beep6 = EEPROM.read(memoria1beep6);
    beep7 = EEPROM.read(memoria1beep7);
    beep8 = EEPROM.read(memoria1beep8);
    beep9 = EEPROM.read(memoria1beep9);
    beep10 = EEPROM.read(memoria1beep10);
    beep11 = EEPROM.read(memoria1beep11);
    beep12 = EEPROM.read(memoria1beep12);         
     
    relay1_1 = EEPROM.read(memoria1relay1_1);  
    relay2_1 = EEPROM.read(memoria1relay2_1);
    relay3_1 = EEPROM.read(memoria1relay3_1);  
    relay4_1 = EEPROM.read(memoria1relay4_1);
    relay5_1 = EEPROM.read(memoria1relay5_1);
    
    relay1_2 = EEPROM.read(memoria1relay1_2);  
    relay2_2 = EEPROM.read(memoria1relay2_2);  
    relay3_2 = EEPROM.read(memoria1relay3_2);  
    relay4_2 = EEPROM.read(memoria1relay4_2);
    relay5_2 = EEPROM.read(memoria1relay5_2);
    
    relay1_3 = EEPROM.read(memoria1relay1_3);  
    relay2_3 = EEPROM.read(memoria1relay2_3);  
    relay3_3 = EEPROM.read(memoria1relay3_3);  
    relay4_3 = EEPROM.read(memoria1relay4_3);
    relay5_3 = EEPROM.read(memoria1relay5_3);
    
    relay1_4 = EEPROM.read(memoria1relay1_4);  
    relay2_4 = EEPROM.read(memoria1relay2_4);  
    relay3_4 = EEPROM.read(memoria1relay3_4);  
    relay4_4 = EEPROM.read(memoria1relay4_4);
    relay5_4 = EEPROM.read(memoria1relay5_4);
    
    relay1_5 = EEPROM.read(memoria1relay1_5);  
    relay2_5 = EEPROM.read(memoria1relay2_5);  
    relay3_5 = EEPROM.read(memoria1relay3_5);  
    relay4_5 = EEPROM.read(memoria1relay4_5);
    relay5_5 = EEPROM.read(memoria1relay5_5);
    
    relay1_6 = EEPROM.read(memoria1relay1_6);  
    relay2_6 = EEPROM.read(memoria1relay2_6);  
    relay3_6 = EEPROM.read(memoria1relay3_6);  
    relay4_6 = EEPROM.read(memoria1relay4_6);
    relay5_6 = EEPROM.read(memoria1relay5_6);
    
    relay1_7 = EEPROM.read(memoria1relay1_7);  
    relay2_7 = EEPROM.read(memoria1relay2_7);  
    relay3_7 = EEPROM.read(memoria1relay3_7);  
    relay4_7 = EEPROM.read(memoria1relay4_7);
    relay5_7 = EEPROM.read(memoria1relay5_7);
    
    relay1_8 = EEPROM.read(memoria1relay1_8);  
    relay2_8 = EEPROM.read(memoria1relay2_8);  
    relay3_8 = EEPROM.read(memoria1relay3_8);  
    relay4_8 = EEPROM.read(memoria1relay4_8);
    relay5_8 = EEPROM.read(memoria1relay5_8);
    
    relay1_9 = EEPROM.read(memoria1relay1_9);  
    relay2_9 = EEPROM.read(memoria1relay2_9);  
    relay3_9 = EEPROM.read(memoria1relay3_9);  
    relay4_9 = EEPROM.read(memoria1relay4_9);
    relay5_9 = EEPROM.read(memoria1relay5_9);
    
    relay1_10 = EEPROM.read(memoria1relay1_10);  
    relay2_10 = EEPROM.read(memoria1relay2_10);  
    relay3_10 = EEPROM.read(memoria1relay3_10);  
    relay4_10 = EEPROM.read(memoria1relay4_10);
    relay5_10 = EEPROM.read(memoria1relay5_10);
    
    relay1_11 = EEPROM.read(memoria1relay1_11);  
    relay2_11 = EEPROM.read(memoria1relay2_11);  
    relay3_11 = EEPROM.read(memoria1relay3_11);  
    relay4_11 = EEPROM.read(memoria1relay4_11);
    relay5_11 = EEPROM.read(memoria1relay5_11);
    
    relay1_12 = EEPROM.read(memoria1relay1_12);  
    relay2_12 = EEPROM.read(memoria1relay2_12);  
    relay3_12 = EEPROM.read(memoria1relay3_12);  
    relay4_12 = EEPROM.read(memoria1relay4_12);
    relay5_12 = EEPROM.read(memoria1relay5_12);
      
    way1_1 = EEPROM.read(memoria1way1_1);  
    way2_1 = EEPROM.read(memoria1way2_1);
    way3_1 = EEPROM.read(memoria1way3_1);  
    way4_1 = EEPROM.read(memoria1way4_1);
    
    way1_2 = EEPROM.read(memoria1way1_2);  
    way2_2 = EEPROM.read(memoria1way2_2);  
    way3_2 = EEPROM.read(memoria1way3_2);  
    way4_2 = EEPROM.read(memoria1way4_2);
    
    way1_3 = EEPROM.read(memoria1way1_3);  
    way2_3 = EEPROM.read(memoria1way2_3);  
    way3_3 = EEPROM.read(memoria1way3_3);  
    way4_3 = EEPROM.read(memoria1way4_3);
    
    way1_4 = EEPROM.read(memoria1way1_4);  
    way2_4 = EEPROM.read(memoria1way2_4);  
    way3_4 = EEPROM.read(memoria1way3_4);  
    way4_4 = EEPROM.read(memoria1way4_4);
    
    way1_5 = EEPROM.read(memoria1way1_5);  
    way2_5 = EEPROM.read(memoria1way2_5);  
    way3_5 = EEPROM.read(memoria1way3_5);  
    way4_5 = EEPROM.read(memoria1way4_5);
    
    way1_6 = EEPROM.read(memoria1way1_6);  
    way2_6 = EEPROM.read(memoria1way2_6);  
    way3_6 = EEPROM.read(memoria1way3_6);  
    way4_6 = EEPROM.read(memoria1way4_6);
    
    way1_7 = EEPROM.read(memoria1way1_7);  
    way2_7 = EEPROM.read(memoria1way2_7);  
    way3_7 = EEPROM.read(memoria1way3_7);  
    way4_7 = EEPROM.read(memoria1way4_7);
    
    way1_8 = EEPROM.read(memoria1way1_8);  
    way2_8 = EEPROM.read(memoria1way2_8);  
    way3_8 = EEPROM.read(memoria1way3_8);  
    way4_8 = EEPROM.read(memoria1way4_8);
    
    way1_9 = EEPROM.read(memoria1way1_9);  
    way2_9 = EEPROM.read(memoria1way2_9);  
    way3_9 = EEPROM.read(memoria1way3_9);  
    way4_9 = EEPROM.read(memoria1way4_9);
    
    way1_10 = EEPROM.read(memoria1way1_10);  
    way2_10 = EEPROM.read(memoria1way2_10);  
    way3_10 = EEPROM.read(memoria1way3_10);  
    way4_10 = EEPROM.read(memoria1way4_10);
    
    way1_11 = EEPROM.read(memoria1way1_11);  
    way2_11 = EEPROM.read(memoria1way2_11);  
    way3_11 = EEPROM.read(memoria1way3_11);  
    way4_11 = EEPROM.read(memoria1way4_11);
    
    way1_12 = EEPROM.read(memoria1way1_12);  
    way2_12 = EEPROM.read(memoria1way2_12);  
    way3_12 = EEPROM.read(memoria1way3_12);  
    way4_12 = EEPROM.read(memoria1way4_12);
      
    rpm1_1 = EEPROM.read(memoria1rpm1_1);  
    rpm2_1 = EEPROM.read(memoria1rpm2_1);
    rpm3_1 = EEPROM.read(memoria1rpm3_1);  
    rpm4_1 = EEPROM.read(memoria1rpm4_1);
    
    rpm1_2 = EEPROM.read(memoria1rpm1_2);  
    rpm2_2 = EEPROM.read(memoria1rpm2_2);  
    rpm3_2 = EEPROM.read(memoria1rpm3_2);  
    rpm4_2 = EEPROM.read(memoria1rpm4_2);
    
    rpm1_3 = EEPROM.read(memoria1rpm1_3);  
    rpm2_3 = EEPROM.read(memoria1rpm2_3);  
    rpm3_3 = EEPROM.read(memoria1rpm3_3);  
    rpm4_3 = EEPROM.read(memoria1rpm4_3);
    
    rpm1_4 = EEPROM.read(memoria1rpm1_4);  
    rpm2_4 = EEPROM.read(memoria1rpm2_4);  
    rpm3_4 = EEPROM.read(memoria1rpm3_4);  
    rpm4_4 = EEPROM.read(memoria1rpm4_4);
    
    rpm1_5 = EEPROM.read(memoria1rpm1_5);  
    rpm2_5 = EEPROM.read(memoria1rpm2_5);  
    rpm3_5 = EEPROM.read(memoria1rpm3_5);  
    rpm4_5 = EEPROM.read(memoria1rpm4_5);
    
    rpm1_6 = EEPROM.read(memoria1rpm1_6);  
    rpm2_6 = EEPROM.read(memoria1rpm2_6);  
    rpm3_6 = EEPROM.read(memoria1rpm3_6);  
    rpm4_6 = EEPROM.read(memoria1rpm4_6);
    
    rpm1_7 = EEPROM.read(memoria1rpm1_7);  
    rpm2_7 = EEPROM.read(memoria1rpm2_7);  
    rpm3_7 = EEPROM.read(memoria1rpm3_7);  
    rpm4_7 = EEPROM.read(memoria1rpm4_7);
    
    rpm1_8 = EEPROM.read(memoria1rpm1_8);  
    rpm2_8 = EEPROM.read(memoria1rpm2_8);  
    rpm3_8 = EEPROM.read(memoria1rpm3_8);  
    rpm4_8 = EEPROM.read(memoria1rpm4_8);
    
    rpm1_9 = EEPROM.read(memoria1rpm1_9);  
    rpm2_9 = EEPROM.read(memoria1rpm2_9);  
    rpm3_9 = EEPROM.read(memoria1rpm3_9);  
    rpm4_9 = EEPROM.read(memoria1rpm4_9);
    
    rpm1_10 = EEPROM.read(memoria1rpm1_10);  
    rpm2_10 = EEPROM.read(memoria1rpm2_10);  
    rpm3_10 = EEPROM.read(memoria1rpm3_10);  
    rpm4_10 = EEPROM.read(memoria1rpm4_10);
    
    rpm1_11 = EEPROM.read(memoria1rpm1_11);  
    rpm2_11 = EEPROM.read(memoria1rpm2_11);  
    rpm3_11 = EEPROM.read(memoria1rpm3_11);  
    rpm4_11 = EEPROM.read(memoria1rpm4_11);
    
    rpm1_12 = EEPROM.read(memoria1rpm1_12);  
    rpm2_12 = EEPROM.read(memoria1rpm2_12);  
    rpm3_12 = EEPROM.read(memoria1rpm3_12);  
    rpm4_12 = EEPROM.read(memoria1rpm4_12);
    }







    if (program == 2) {
    
    time1 = EEPROM.read(memoria2time1);    
    time2 = EEPROM.read(memoria2time2);
    time3 = EEPROM.read(memoria2time3);
    time4 = EEPROM.read(memoria2time4);
    time5 = EEPROM.read(memoria2time5);
    time6 = EEPROM.read(memoria2time6);    
    time7 = EEPROM.read(memoria2time7);
    time8 = EEPROM.read(memoria2time8);
    time9 = EEPROM.read(memoria2time9);
    time10 = EEPROM.read(memoria2time10);
    time11 = EEPROM.read(memoria2time11);    
    time12 = EEPROM.read(memoria2time12);

    beep1 = EEPROM.read(memoria2beep1);
    beep2 = EEPROM.read(memoria2beep2);
    beep3 = EEPROM.read(memoria2beep3);
    beep4 = EEPROM.read(memoria2beep4);
    beep5 = EEPROM.read(memoria2beep5);
    beep6 = EEPROM.read(memoria2beep6);
    beep7 = EEPROM.read(memoria2beep7);
    beep8 = EEPROM.read(memoria2beep8);
    beep9 = EEPROM.read(memoria2beep9);
    beep10 = EEPROM.read(memoria2beep10);
    beep11 = EEPROM.read(memoria2beep11);
    beep12 = EEPROM.read(memoria2beep12);         
     
    relay1_1 = EEPROM.read(memoria2relay1_1);  
    relay2_1 = EEPROM.read(memoria2relay2_1);
    relay3_1 = EEPROM.read(memoria2relay3_1);  
    relay4_1 = EEPROM.read(memoria2relay4_1);
    relay5_1 = EEPROM.read(memoria2relay5_1);
    
    relay1_2 = EEPROM.read(memoria2relay1_2);  
    relay2_2 = EEPROM.read(memoria2relay2_2);  
    relay3_2 = EEPROM.read(memoria2relay3_2);  
    relay4_2 = EEPROM.read(memoria2relay4_2);
    relay5_2 = EEPROM.read(memoria2relay5_2);
    
    relay1_3 = EEPROM.read(memoria2relay1_3);  
    relay2_3 = EEPROM.read(memoria2relay2_3);  
    relay3_3 = EEPROM.read(memoria2relay3_3);  
    relay4_3 = EEPROM.read(memoria2relay4_3);
    relay5_3 = EEPROM.read(memoria2relay5_3);
    
    relay1_4 = EEPROM.read(memoria2relay1_4);  
    relay2_4 = EEPROM.read(memoria2relay2_4);  
    relay3_4 = EEPROM.read(memoria2relay3_4);  
    relay4_4 = EEPROM.read(memoria2relay4_4);
    relay5_4 = EEPROM.read(memoria2relay5_4);
    
    relay1_5 = EEPROM.read(memoria2relay1_5);  
    relay2_5 = EEPROM.read(memoria2relay2_5);  
    relay3_5 = EEPROM.read(memoria2relay3_5);  
    relay4_5 = EEPROM.read(memoria2relay4_5);
    relay5_5 = EEPROM.read(memoria2relay5_5);
    
    relay1_6 = EEPROM.read(memoria2relay1_6);  
    relay2_6 = EEPROM.read(memoria2relay2_6);  
    relay3_6 = EEPROM.read(memoria2relay3_6);  
    relay4_6 = EEPROM.read(memoria2relay4_6);
    relay5_6 = EEPROM.read(memoria2relay5_6);
    
    relay1_7 = EEPROM.read(memoria2relay1_7);  
    relay2_7 = EEPROM.read(memoria2relay2_7);  
    relay3_7 = EEPROM.read(memoria2relay3_7);  
    relay4_7 = EEPROM.read(memoria2relay4_7);
    relay5_7 = EEPROM.read(memoria2relay5_7);
    
    relay1_8 = EEPROM.read(memoria2relay1_8);  
    relay2_8 = EEPROM.read(memoria2relay2_8);  
    relay3_8 = EEPROM.read(memoria2relay3_8);  
    relay4_8 = EEPROM.read(memoria2relay4_8);
    relay5_8 = EEPROM.read(memoria2relay5_8);
    
    relay1_9 = EEPROM.read(memoria2relay1_9);  
    relay2_9 = EEPROM.read(memoria2relay2_9);  
    relay3_9 = EEPROM.read(memoria2relay3_9);  
    relay4_9 = EEPROM.read(memoria2relay4_9);
    relay5_9 = EEPROM.read(memoria2relay5_9);
    
    relay1_10 = EEPROM.read(memoria2relay1_10);  
    relay2_10 = EEPROM.read(memoria2relay2_10);  
    relay3_10 = EEPROM.read(memoria2relay3_10);  
    relay4_10 = EEPROM.read(memoria2relay4_10);
    relay5_10 = EEPROM.read(memoria2relay5_10);
    
    relay1_11 = EEPROM.read(memoria2relay1_11);  
    relay2_11 = EEPROM.read(memoria2relay2_11);  
    relay3_11 = EEPROM.read(memoria2relay3_11);  
    relay4_11 = EEPROM.read(memoria2relay4_11);
    relay5_11 = EEPROM.read(memoria2relay5_11);
    
    relay1_12 = EEPROM.read(memoria2relay1_12);  
    relay2_12 = EEPROM.read(memoria2relay2_12);  
    relay3_12 = EEPROM.read(memoria2relay3_12);  
    relay4_12 = EEPROM.read(memoria2relay4_12);
    relay5_12 = EEPROM.read(memoria2relay5_12);
      
    way1_1 = EEPROM.read(memoria2way1_1);  
    way2_1 = EEPROM.read(memoria2way2_1);
    way3_1 = EEPROM.read(memoria2way3_1);  
    way4_1 = EEPROM.read(memoria2way4_1);
    
    way1_2 = EEPROM.read(memoria2way1_2);  
    way2_2 = EEPROM.read(memoria2way2_2);  
    way3_2 = EEPROM.read(memoria2way3_2);  
    way4_2 = EEPROM.read(memoria2way4_2);
    
    way1_3 = EEPROM.read(memoria2way1_3);  
    way2_3 = EEPROM.read(memoria2way2_3);  
    way3_3 = EEPROM.read(memoria2way3_3);  
    way4_3 = EEPROM.read(memoria2way4_3);
    
    way1_4 = EEPROM.read(memoria2way1_4);  
    way2_4 = EEPROM.read(memoria2way2_4);  
    way3_4 = EEPROM.read(memoria2way3_4);  
    way4_4 = EEPROM.read(memoria2way4_4);
    
    way1_5 = EEPROM.read(memoria2way1_5);  
    way2_5 = EEPROM.read(memoria2way2_5);  
    way3_5 = EEPROM.read(memoria2way3_5);  
    way4_5 = EEPROM.read(memoria2way4_5);
    
    way1_6 = EEPROM.read(memoria2way1_6);  
    way2_6 = EEPROM.read(memoria2way2_6);  
    way3_6 = EEPROM.read(memoria2way3_6);  
    way4_6 = EEPROM.read(memoria2way4_6);
    
    way1_7 = EEPROM.read(memoria2way1_7);  
    way2_7 = EEPROM.read(memoria2way2_7);  
    way3_7 = EEPROM.read(memoria2way3_7);  
    way4_7 = EEPROM.read(memoria2way4_7);
    
    way1_8 = EEPROM.read(memoria2way1_8);  
    way2_8 = EEPROM.read(memoria2way2_8);  
    way3_8 = EEPROM.read(memoria2way3_8);  
    way4_8 = EEPROM.read(memoria2way4_8);
    
    way1_9 = EEPROM.read(memoria2way1_9);  
    way2_9 = EEPROM.read(memoria2way2_9);  
    way3_9 = EEPROM.read(memoria2way3_9);  
    way4_9 = EEPROM.read(memoria2way4_9);
    
    way1_10 = EEPROM.read(memoria2way1_10);  
    way2_10 = EEPROM.read(memoria2way2_10);  
    way3_10 = EEPROM.read(memoria2way3_10);  
    way4_10 = EEPROM.read(memoria2way4_10);
    
    way1_11 = EEPROM.read(memoria2way1_11);  
    way2_11 = EEPROM.read(memoria2way2_11);  
    way3_11 = EEPROM.read(memoria2way3_11);  
    way4_11 = EEPROM.read(memoria2way4_11);
    
    way1_12 = EEPROM.read(memoria2way1_12);  
    way2_12 = EEPROM.read(memoria2way2_12);  
    way3_12 = EEPROM.read(memoria2way3_12);  
    way4_12 = EEPROM.read(memoria2way4_12);
      
    rpm1_1 = EEPROM.read(memoria2rpm1_1);  
    rpm2_1 = EEPROM.read(memoria2rpm2_1);
    rpm3_1 = EEPROM.read(memoria2rpm3_1);  
    rpm4_1 = EEPROM.read(memoria2rpm4_1);
    
    rpm1_2 = EEPROM.read(memoria2rpm1_2);  
    rpm2_2 = EEPROM.read(memoria2rpm2_2);  
    rpm3_2 = EEPROM.read(memoria2rpm3_2);  
    rpm4_2 = EEPROM.read(memoria2rpm4_2);
    
    rpm1_3 = EEPROM.read(memoria2rpm1_3);  
    rpm2_3 = EEPROM.read(memoria2rpm2_3);  
    rpm3_3 = EEPROM.read(memoria2rpm3_3);  
    rpm4_3 = EEPROM.read(memoria2rpm4_3);
    
    rpm1_4 = EEPROM.read(memoria2rpm1_4);  
    rpm2_4 = EEPROM.read(memoria2rpm2_4);  
    rpm3_4 = EEPROM.read(memoria2rpm3_4);  
    rpm4_4 = EEPROM.read(memoria2rpm4_4);
    
    rpm1_5 = EEPROM.read(memoria2rpm1_5);  
    rpm2_5 = EEPROM.read(memoria2rpm2_5);  
    rpm3_5 = EEPROM.read(memoria2rpm3_5);  
    rpm4_5 = EEPROM.read(memoria2rpm4_5);
    
    rpm1_6 = EEPROM.read(memoria2rpm1_6);  
    rpm2_6 = EEPROM.read(memoria2rpm2_6);  
    rpm3_6 = EEPROM.read(memoria2rpm3_6);  
    rpm4_6 = EEPROM.read(memoria2rpm4_6);
    
    rpm1_7 = EEPROM.read(memoria2rpm1_7);  
    rpm2_7 = EEPROM.read(memoria2rpm2_7);  
    rpm3_7 = EEPROM.read(memoria2rpm3_7);  
    rpm4_7 = EEPROM.read(memoria2rpm4_7);
    
    rpm1_8 = EEPROM.read(memoria2rpm1_8);  
    rpm2_8 = EEPROM.read(memoria2rpm2_8);  
    rpm3_8 = EEPROM.read(memoria2rpm3_8);  
    rpm4_8 = EEPROM.read(memoria2rpm4_8);
    
    rpm1_9 = EEPROM.read(memoria2rpm1_9);  
    rpm2_9 = EEPROM.read(memoria2rpm2_9);  
    rpm3_9 = EEPROM.read(memoria2rpm3_9);  
    rpm4_9 = EEPROM.read(memoria2rpm4_9);
    
    rpm1_10 = EEPROM.read(memoria2rpm1_10);  
    rpm2_10 = EEPROM.read(memoria2rpm2_10);  
    rpm3_10 = EEPROM.read(memoria2rpm3_10);  
    rpm4_10 = EEPROM.read(memoria2rpm4_10);
    
    rpm1_11 = EEPROM.read(memoria2rpm1_11);  
    rpm2_11 = EEPROM.read(memoria2rpm2_11);  
    rpm3_11 = EEPROM.read(memoria2rpm3_11);  
    rpm4_11 = EEPROM.read(memoria2rpm4_11);
    
    rpm1_12 = EEPROM.read(memoria2rpm1_12);  
    rpm2_12 = EEPROM.read(memoria2rpm2_12);  
    rpm3_12 = EEPROM.read(memoria2rpm3_12);  
    rpm4_12 = EEPROM.read(memoria2rpm4_12);
    }






    if (program == 3) {
    
    time1 = EEPROM.read(memoria3time1);    
    time2 = EEPROM.read(memoria3time2);
    time3 = EEPROM.read(memoria3time3);
    time4 = EEPROM.read(memoria3time4);
    time5 = EEPROM.read(memoria3time5);
    time6 = EEPROM.read(memoria3time6);    
    time7 = EEPROM.read(memoria3time7);
    time8 = EEPROM.read(memoria3time8);
    time9 = EEPROM.read(memoria3time9);
    time10 = EEPROM.read(memoria3time10);
    time11 = EEPROM.read(memoria3time11);    
    time12 = EEPROM.read(memoria3time12);

    beep1 = EEPROM.read(memoria3beep1);
    beep2 = EEPROM.read(memoria3beep2);
    beep3 = EEPROM.read(memoria3beep3);
    beep4 = EEPROM.read(memoria3beep4);
    beep5 = EEPROM.read(memoria3beep5);
    beep6 = EEPROM.read(memoria3beep6);
    beep7 = EEPROM.read(memoria3beep7);
    beep8 = EEPROM.read(memoria3beep8);
    beep9 = EEPROM.read(memoria3beep9);
    beep10 = EEPROM.read(memoria3beep10);
    beep11 = EEPROM.read(memoria3beep11);
    beep12 = EEPROM.read(memoria3beep12);         
     
    relay1_1 = EEPROM.read(memoria3relay1_1);  
    relay2_1 = EEPROM.read(memoria3relay2_1);
    relay3_1 = EEPROM.read(memoria3relay3_1);  
    relay4_1 = EEPROM.read(memoria3relay4_1);
    relay5_1 = EEPROM.read(memoria3relay5_1);
    
    relay1_2 = EEPROM.read(memoria3relay1_2);  
    relay2_2 = EEPROM.read(memoria3relay2_2);  
    relay3_2 = EEPROM.read(memoria3relay3_2);  
    relay4_2 = EEPROM.read(memoria3relay4_2);
    relay5_2 = EEPROM.read(memoria3relay5_2);
    
    relay1_3 = EEPROM.read(memoria3relay1_3);  
    relay2_3 = EEPROM.read(memoria3relay2_3);  
    relay3_3 = EEPROM.read(memoria3relay3_3);  
    relay4_3 = EEPROM.read(memoria3relay4_3);
    relay5_3 = EEPROM.read(memoria3relay5_3);
    
    relay1_4 = EEPROM.read(memoria3relay1_4);  
    relay2_4 = EEPROM.read(memoria3relay2_4);  
    relay3_4 = EEPROM.read(memoria3relay3_4);  
    relay4_4 = EEPROM.read(memoria3relay4_4);
    relay5_4 = EEPROM.read(memoria3relay5_4);
    
    relay1_5 = EEPROM.read(memoria3relay1_5);  
    relay2_5 = EEPROM.read(memoria3relay2_5);  
    relay3_5 = EEPROM.read(memoria3relay3_5);  
    relay4_5 = EEPROM.read(memoria3relay4_5);
    relay5_5 = EEPROM.read(memoria3relay5_5);
    
    relay1_6 = EEPROM.read(memoria3relay1_6);  
    relay2_6 = EEPROM.read(memoria3relay2_6);  
    relay3_6 = EEPROM.read(memoria3relay3_6);  
    relay4_6 = EEPROM.read(memoria3relay4_6);
    relay5_6 = EEPROM.read(memoria3relay5_6);
    
    relay1_7 = EEPROM.read(memoria3relay1_7);  
    relay2_7 = EEPROM.read(memoria3relay2_7);  
    relay3_7 = EEPROM.read(memoria3relay3_7);  
    relay4_7 = EEPROM.read(memoria3relay4_7);
    relay5_7 = EEPROM.read(memoria3relay5_7);
    
    relay1_8 = EEPROM.read(memoria3relay1_8);  
    relay2_8 = EEPROM.read(memoria3relay2_8);  
    relay3_8 = EEPROM.read(memoria3relay3_8);  
    relay4_8 = EEPROM.read(memoria3relay4_8);
    relay5_8 = EEPROM.read(memoria3relay5_8);
    
    relay1_9 = EEPROM.read(memoria3relay1_9);  
    relay2_9 = EEPROM.read(memoria3relay2_9);  
    relay3_9 = EEPROM.read(memoria3relay3_9);  
    relay4_9 = EEPROM.read(memoria3relay4_9);
    relay5_9 = EEPROM.read(memoria3relay5_9);
    
    relay1_10 = EEPROM.read(memoria3relay1_10);  
    relay2_10 = EEPROM.read(memoria3relay2_10);  
    relay3_10 = EEPROM.read(memoria3relay3_10);  
    relay4_10 = EEPROM.read(memoria3relay4_10);
    relay5_10 = EEPROM.read(memoria3relay5_10);
    
    relay1_11 = EEPROM.read(memoria3relay1_11);  
    relay2_11 = EEPROM.read(memoria3relay2_11);  
    relay3_11 = EEPROM.read(memoria3relay3_11);  
    relay4_11 = EEPROM.read(memoria3relay4_11);
    relay5_11 = EEPROM.read(memoria3relay5_11);
    
    relay1_12 = EEPROM.read(memoria3relay1_12);  
    relay2_12 = EEPROM.read(memoria3relay2_12);  
    relay3_12 = EEPROM.read(memoria3relay3_12);  
    relay4_12 = EEPROM.read(memoria3relay4_12);
    relay5_12 = EEPROM.read(memoria3relay5_12);
      
    way1_1 = EEPROM.read(memoria3way1_1);  
    way2_1 = EEPROM.read(memoria3way2_1);
    way3_1 = EEPROM.read(memoria3way3_1);  
    way4_1 = EEPROM.read(memoria3way4_1);
    
    way1_2 = EEPROM.read(memoria3way1_2);  
    way2_2 = EEPROM.read(memoria3way2_2);  
    way3_2 = EEPROM.read(memoria3way3_2);  
    way4_2 = EEPROM.read(memoria3way4_2);
    
    way1_3 = EEPROM.read(memoria3way1_3);  
    way2_3 = EEPROM.read(memoria3way2_3);  
    way3_3 = EEPROM.read(memoria3way3_3);  
    way4_3 = EEPROM.read(memoria3way4_3);
    
    way1_4 = EEPROM.read(memoria3way1_4);  
    way2_4 = EEPROM.read(memoria3way2_4);  
    way3_4 = EEPROM.read(memoria3way3_4);  
    way4_4 = EEPROM.read(memoria3way4_4);
    
    way1_5 = EEPROM.read(memoria3way1_5);  
    way2_5 = EEPROM.read(memoria3way2_5);  
    way3_5 = EEPROM.read(memoria3way3_5);  
    way4_5 = EEPROM.read(memoria3way4_5);
    
    way1_6 = EEPROM.read(memoria3way1_6);  
    way2_6 = EEPROM.read(memoria3way2_6);  
    way3_6 = EEPROM.read(memoria3way3_6);  
    way4_6 = EEPROM.read(memoria3way4_6);
    
    way1_7 = EEPROM.read(memoria3way1_7);  
    way2_7 = EEPROM.read(memoria3way2_7);  
    way3_7 = EEPROM.read(memoria3way3_7);  
    way4_7 = EEPROM.read(memoria3way4_7);
    
    way1_8 = EEPROM.read(memoria3way1_8);  
    way2_8 = EEPROM.read(memoria3way2_8);  
    way3_8 = EEPROM.read(memoria3way3_8);  
    way4_8 = EEPROM.read(memoria3way4_8);
    
    way1_9 = EEPROM.read(memoria3way1_9);  
    way2_9 = EEPROM.read(memoria3way2_9);  
    way3_9 = EEPROM.read(memoria3way3_9);  
    way4_9 = EEPROM.read(memoria3way4_9);
    
    way1_10 = EEPROM.read(memoria3way1_10);  
    way2_10 = EEPROM.read(memoria3way2_10);  
    way3_10 = EEPROM.read(memoria3way3_10);  
    way4_10 = EEPROM.read(memoria3way4_10);
    
    way1_11 = EEPROM.read(memoria3way1_11);  
    way2_11 = EEPROM.read(memoria3way2_11);  
    way3_11 = EEPROM.read(memoria3way3_11);  
    way4_11 = EEPROM.read(memoria3way4_11);
    
    way1_12 = EEPROM.read(memoria3way1_12);  
    way2_12 = EEPROM.read(memoria3way2_12);  
    way3_12 = EEPROM.read(memoria3way3_12);  
    way4_12 = EEPROM.read(memoria3way4_12);
      
    rpm1_1 = EEPROM.read(memoria3rpm1_1);  
    rpm2_1 = EEPROM.read(memoria3rpm2_1);
    rpm3_1 = EEPROM.read(memoria3rpm3_1);  
    rpm4_1 = EEPROM.read(memoria3rpm4_1);
    
    rpm1_2 = EEPROM.read(memoria3rpm1_2);  
    rpm2_2 = EEPROM.read(memoria3rpm2_2);  
    rpm3_2 = EEPROM.read(memoria3rpm3_2);  
    rpm4_2 = EEPROM.read(memoria3rpm4_2);
    
    rpm1_3 = EEPROM.read(memoria3rpm1_3);  
    rpm2_3 = EEPROM.read(memoria3rpm2_3);  
    rpm3_3 = EEPROM.read(memoria3rpm3_3);  
    rpm4_3 = EEPROM.read(memoria3rpm4_3);
    
    rpm1_4 = EEPROM.read(memoria3rpm1_4);  
    rpm2_4 = EEPROM.read(memoria3rpm2_4);  
    rpm3_4 = EEPROM.read(memoria3rpm3_4);  
    rpm4_4 = EEPROM.read(memoria3rpm4_4);
    
    rpm1_5 = EEPROM.read(memoria3rpm1_5);  
    rpm2_5 = EEPROM.read(memoria3rpm2_5);  
    rpm3_5 = EEPROM.read(memoria3rpm3_5);  
    rpm4_5 = EEPROM.read(memoria3rpm4_5);
    
    rpm1_6 = EEPROM.read(memoria3rpm1_6);  
    rpm2_6 = EEPROM.read(memoria3rpm2_6);  
    rpm3_6 = EEPROM.read(memoria3rpm3_6);  
    rpm4_6 = EEPROM.read(memoria3rpm4_6);
    
    rpm1_7 = EEPROM.read(memoria3rpm1_7);  
    rpm2_7 = EEPROM.read(memoria3rpm2_7);  
    rpm3_7 = EEPROM.read(memoria3rpm3_7);  
    rpm4_7 = EEPROM.read(memoria3rpm4_7);
    
    rpm1_8 = EEPROM.read(memoria3rpm1_8);  
    rpm2_8 = EEPROM.read(memoria3rpm2_8);  
    rpm3_8 = EEPROM.read(memoria3rpm3_8);  
    rpm4_8 = EEPROM.read(memoria3rpm4_8);
    
    rpm1_9 = EEPROM.read(memoria3rpm1_9);  
    rpm2_9 = EEPROM.read(memoria3rpm2_9);  
    rpm3_9 = EEPROM.read(memoria3rpm3_9);  
    rpm4_9 = EEPROM.read(memoria3rpm4_9);
    
    rpm1_10 = EEPROM.read(memoria3rpm1_10);  
    rpm2_10 = EEPROM.read(memoria3rpm2_10);  
    rpm3_10 = EEPROM.read(memoria3rpm3_10);  
    rpm4_10 = EEPROM.read(memoria3rpm4_10);
    
    rpm1_11 = EEPROM.read(memoria3rpm1_11);  
    rpm2_11 = EEPROM.read(memoria3rpm2_11);  
    rpm3_11 = EEPROM.read(memoria3rpm3_11);  
    rpm4_11 = EEPROM.read(memoria3rpm4_11);
    
    rpm1_12 = EEPROM.read(memoria3rpm1_12);  
    rpm2_12 = EEPROM.read(memoria3rpm2_12);  
    rpm3_12 = EEPROM.read(memoria3rpm3_12);  
    rpm4_12 = EEPROM.read(memoria3rpm4_12);
    }
    
    EEPROM.write(0, program);
    EEPROM.commit();
}





// Lê EEPROM para o array
void loadProgramNames() {
  for (int i = 0; i < 3; i++) {
    char buf[17]; // 13 chars + '\0'
    for (int j = 0; j < 16; j++) {
      buf[j] = EEPROM.read(505 + i*16 + j); 
    }
    buf[16] = '\0';
    programNames[i] = String(buf);
  }
}

// Salva um nome no índice (0,1,2)
void saveProgramName(int index, String name) {
  if (name.length() > 16) name = name.substring(0,16);
  for (int i = 0; i < 16; i++) {
    char c = (i < name.length()) ? name[i] : '\0';
    EEPROM.write(505 + index*16 + i, c); 
  }
  EEPROM.commit(); // salva os dados na flash
  programNames[index] = name;
}
