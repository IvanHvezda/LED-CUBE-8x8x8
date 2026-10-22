/*/////////////////////////////////////////////////////////////////////////////Tutorial na program/////////////////////////////////////////////////////////////////////*/
/*

_|_|_|                                      _|    _|                              _|                _|_|_|                                                                      
   _|    _|      _|    _|_|_|  _|_|_|        _|    _|  _|      _|  _|_|_|_|    _|_|_|    _|_|_|      _|    _|  _|  _|_|    _|_|      _|_|_|  _|  _|_|    _|_|_|  _|_|_|  _|_|    
   _|    _|      _|  _|    _|  _|    _|      _|_|_|_|  _|      _|      _|    _|    _|  _|    _|      _|_|_|    _|_|      _|    _|  _|    _|  _|_|      _|    _|  _|    _|    _|  
   _|      _|  _|    _|    _|  _|    _|      _|    _|    _|  _|      _|      _|    _|  _|    _|      _|        _|        _|    _|  _|    _|  _|        _|    _|  _|    _|    _|  
 _|_|_|      _|        _|_|_|  _|    _|      _|    _|      _|      _|_|_|_|    _|_|_|    _|_|_|      _|        _|          _|_|      _|_|_|  _|          _|_|_|  _|    _|    _|  
                                                                                                                                         _|                                      
                                                                                                                                     _|_|                                        

Program se skládá ze dvou částí

  1. První je .ino program(hlavní program)
  2. .h soubory, kde řeším jednotlivé funkce

Můj kód je příliš dlouhý (asi přes 7000 řádků). Části kódu jsou prakticky stejné v každé funkci, proto rozeberu problematiku funkcí v header filu abc.h
Dále popíši hlavní program, protože se o dost liší od ostatních programů a ještě okomentuji variables.h

Knihovny, kde jsem čerpal, jsou vy zdrojích mé textové části

*/
/*/////////////////////////////////////////////////////////////////////////////Tutorial na program/////////////////////////////////////////////////////////////////////*/




/*/////////////////////////////////////////////////////////////////////////////include/////////////////////////////////////////////////////////////////////*/

#include "sign.h" //přidání header file sign.h
#include "abc.h" //přidání header file abc.h
#include "ascii.h" //přidání header file ascii.h
#include "full.h" //přidání header file full.h
#include "none.h" //přidání header file none.h
#include "pivo.h" //přidání header file pivo.h
#include "num.h" //přidání header file num.h
#include "temp1.h" //přidání header file temp1.h
#include "temp2.h" //přidání header file temp2.h
#include "celsia.h" //přidání header file celsia.h
#include "procento.h" //přidání header file procento.h
#include "datum.h" //přidání header file datum.h
#include "cas.h" //přidání header file cas.h
#include "snakelayered.h" //přidání header file snakelayered.h
#include "xyz.h" //přidání header file xyz.h
#include "front.h" //přidání header file front.h
#include "side.h" //přidání header file side.h
#include "christmass.h" //přidání header file christmass.h
#include "cross.h" //přidání header file cross.h
#include "stairs.h" //přidání header file stairs.h
#include "top.h" //přidání header file top.h
#include "rain.h" //přidání header file rain.h
#include "fall.h" //přidání header file fall.h
#include "cube8.h" //přidání header file cube8.h
#include "cube7.h" //přidání header file cube7.h
#include "cube6.h" //přidání header file cube6.h
#include "cube5.h" //přidání header file cube5.h
#include "cube4.h" //přidání header file cube4.h
#include "cube3.h" //přidání header file cube3.h
#include "cube2.h" //přidání header file cube2.h
#include "cube1.h" //přidání header file cube1.h
#include "cubetocube.h" //přidání header file cubetocube.h
#include "ball.h" //přidání header file ball.h

#include "variables.h" //přidání header file variables.h


/*/////////////////////////////////////////////////////////////////////////////include/////////////////////////////////////////////////////////////////////*/

void setup(){ // void setup - zde nastavuji piny, sériovou komunikaci atd..

  Serial.begin(9600); // nastavení sériové komunikace

  pinMode(led_start, OUTPUT); // nastavení pinu led_start na výstup
  
  randomSeed(analogRead(A1)); // funkce random, v módu náhodný výběr

  for(int i = 0; i <=24;i++){ //for cyklus, kde nastavuji opět sloupce na výstup
    pinMode(pins[i],OUTPUT);
    delay(5);
  }

  for(int i  = 0;i <=layersNum;i++){ //for cyklus, kde nastavuji řádky na výstup
    pinMode(layers[i],OUTPUT);
    delay(5);
  }
  for(int i  = 0;i <=layersNum;i++){ //for cyklus, kde vypínám všechny řádky (to znamená, že LED kostka na začátku nesvítí)
    digitalWrite(layers[i],1);
    delay(5);
  }

  delay(50); // časový delay na 50 milisekund




  
  Serial.println("Led cube startuje"); // oznámení pro mě, když programuji LED kostku, abych věděl, že LED kostka je připravena
  delay(50); // časový delay na 50 milisekund
  none(); // funkce none (LED nesvítí)
  delay(50); // časový delay na 50 milisekund
  sign(); // funkce sign (3D LED metrix: MADE BY IVAN HVEZDA)
  delay(50); // časový delay na 50 milisekund

}

void loop(){
  //date(); 
 currentmain = millis();
  if(currentmain-prevmain>intervalmain){ // funkce millis() na blikání signalizační LED 
    prevmain = currentmain;
     if (led_state==0) led_state=1; else led_state=0;
    digitalWrite(led_start,led_state);
   }
  if(Serial.available() > 0) {   //Zde začíná to nejdůležitější a to je: když se mobil spáruje s LED kostkou
   digitalWrite(led_start,1); //Signalizační LED dioda už jen svítí
    Serial.println("start"); // Signál pro mě, když LED kostku programuju: jsem v této sekci a LED kostka přijímá data
  while(true){ // nekonečná smyčka
 
  slovo = Serial.readString();  //slovo je proměnná, která se zabývá příchozími daty
  Serial.println(slovo); // vypsání příchozích dat z aplikace

/*****************************************************************************************************/
  //mód rychly vyber
  if(slovo == "rychly"){
    while(true){
       slovo = Serial.readString(); // přijímání dat
      Serial.println(slovo); //vypsání příchozích dat z aplikace

    //zde třídím příchozí data a podle toho se promítne funkce, která náleží datům
    // používám zde if a ne switch, protože jsem if moc v projektu neměl a přijde mi to trošku přehlednější v tomto případě než u switch
       if(slovo =="num"){
         none();
         num();
         none();

       }
       if(slovo == "zpet"){ // odejdu s módu rychký výběr
         Serial.println("zpet"); // signál pro mě, že jsem odešel z módu, "zpet" se vypíše do sériového monitoru
         none();
         break;
       }
       if(slovo =="abc"){
         none();
         abc();
         none();

       }
       if(slovo =="pivo"){
         none();
         pivo();
         none();

       }
       if(slovo =="sign"){
         none();
         sign();
         none();

       }
       if(slovo =="rain"){
         none();
         rain();
         none();

       }
       if(slovo =="full"){
         none();
         full();
         delay(5000);   
         none();
       }
       if(slovo =="cube1"){
        none();
          for(int i = 0;i<=200;i++){
            kostka1();
          }
         none();
       }
       if(slovo =="cube2"){
          none();
           for(int i = 0;i<=200;i++){
            kostka2();
          }
          none();
       }
       if(slovo =="cube3"){
         none();
          for(int i = 0;i<=200;i++){
            kostka3();
          }
         none();

       }
       if(slovo =="cube4"){
         none();
          for(int i = 0;i<=200;i++){
            kostka4();
          }
         none();
       }
       if(slovo =="cube5"){
         none();
          for(int i = 0;i<=200;i++){
            kostka5();
          }
         none();
       }
       if(slovo =="cube6"){
         none();
          for(int i = 0;i<=200;i++){
            kostka6();
          }
         none();
       }
       if(slovo =="cube7"){
         none();
          for(int i = 0;i<=200;i++){
            kostka7();
          }
         none();
       }
       if(slovo =="cube8"){
         none();
          for(int i = 0;i<=200;i++){
            kostka8();
          }
         none();
       }
       if(slovo =="cubetocube"){
         none();
         kostkatokostka();
         none();

       }
       if(slovo =="temp1"){
         none();
         temp1();
         cels();
         none();

       }
       if(slovo =="temp2"){
         none();
         temp2();
         procent();
         none();

       }
       if(slovo =="snakelayered"){
         none();
         snake__layered();
         none();
       }
       if(slovo =="xyz"){
         none();
         xyz();
         none();
       }
       if(slovo =="cas"){
         none();
         time();
         none();

       }
       if(slovo =="datum"){
         none();
         date();
         none();

       }
       if(slovo =="front"){
         none();
         front();
         none();

       }
       if(slovo =="side"){
         none();
         side();
         none();

       }
       if(slovo =="top"){
         none();
         top();
         none();
       }
       if(slovo =="christmass"){
         none();
         christmass();
         none();
       }
       if(slovo =="cross"){
         none();
          for(int i = 0;i<=200;i++){
            cross();
          }
         none();
       }
       if(slovo =="stairs"){
         none();
         stairs();
         none();

       }
       if(slovo =="fall"){
         none();
         fall();
         none();

       }
       if(slovo =="ball"){
         none();
          for(int i = 0;i<=200;i++){
            koule();
          }
         none();
       }
     }
   }

/*****************************************************************************************************/
  //mód nahodne mody
  if(slovo == "nahodny"){
    while(true){
      slovo = Serial.readString();
        
       if(slovo == "zpet"){
         break;
       }
      if(slovo == "nahodazap"){
  
      prochazenicisel = random(1,28); //funkce random
      Serial.println(prochazenicisel);

        

            switch(prochazenicisel){ // switch, kde řeším proměnnou prochazenícisel a podle toho se promítne funkce, která náleží výstupu random funkce
        case 1:
          none();
          abc();
          none();
        break;
        case 2:
          none();
          full();
          delay(5000);
          none();
        break;
        case 3:
          none();
          pivo();
          none();
        break;
        case 4:
          none();
          num();
          none();
        break;
        case 5:
          none();
          for(int i = 0;i<=200;i++){
            kostka1();
          }
         none();
        break;
        case 6:
         none();
          for(int i = 0;i<=200;i++){
            kostka2();
          }
         none();
        break;
        case 7:
          none();
          for(int i = 0;i<=200;i++){
            kostka3();
          }
         none();
        break;
        case 8:
          none();
          for(int i = 0;i<=200;i++){
            kostka4();
          }
         none();
        break;
        case 9:
          none();
          for(int i = 0;i<=200;i++){
            kostka5();
          }
         none();
        break;
        case 10:
          none();
          for(int i = 0;i<=200;i++){
            kostka6();
          }
         none();
        break;
        case 11:
          none();
          for(int i = 0;i<=200;i++){
            kostka7();
          }
         none();
        break;
        case 12:
          none();
          for(int i = 0;i<=200;i++){
            kostka8();
          }
         none();
        break;
        case 13:
          none();
          kostkatokostka();
          none();
        break;
        case 14:
          none();
          for(int i = 0;i<=200;i++){
            koule();
          }
         none();
        break;
        case 15:
          none();
          temp1();
          cels();
          none();
        break;
        case 16:
          none();
          temp2();
          procent();
          none();
        break;
        case 17:
          none();
          date();
          none();
        break;
        case 18:  
          none();
          time();
          none();
        break;
        case 19:
          none();
          xyz();
          none();
        break;
        case 20:
          none();
          snake__layered();
          none();
        break;
        case 21:
          none();
          front();
          none();
        break;
        case 22:
          none();
          side();
          none();
        break;
        case 23:
          none();
          top();
          none();
        break;
        case 24:
          none();
          christmass();
          none();
        break;
        case 25:
          none();
          stairs();
          none();
        break;
        case 26:
          none();
          for(int i = 0;i<=200;i++){
            cross();
          }
         none();
        break;
        case 27:
          none();
          rain();
          none();
        break;
        case 28:
          none();
          fall();
          none();
        break;
      }
    }
  }
  }

/*****************************************************************************************************/
  //mód on ,off

  if (slovo == "off") { 
    none(); // vypnutí všech LED
  } 
  if (slovo == "on") {
    full(); // zapnutí všech LED
  } 

/*****************************************************************************************************/
  //mód ovladani textem,hlasem

  if(slovo == "text"){
    none();
   
while(true){
  slovo = Serial.readString();  
  if(slovo == "zpet"){  
      break;
    }else{
      ascii(); // funkce ascii
    }
  }
  }
  /*****************************************************************************************************/
}
}
}

