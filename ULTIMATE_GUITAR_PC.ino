 /* 
By JACKSON F. DA SILVA
I'VE USED EXTERNAL 4.7K OHMS RESISTORS INSTEAD ARDUINO BUILT IN RESISTORS
YOU CAN USE IT IF YOU WANT TO CALLING THE PIN MODE FUNCTION  
PROGRAMMED USING IO PORTS OF ATmega 32U4 CONTROLLER INSTEAD OF THE SLOWER ARDUINO'S digitalRead FUNCTION. 


GUITAR BUTTONS  | ARDUINO PINS |ATMEGA PORTS
     GREEN            P2           PD1           
     RED              P3           PD0            
     YELLOW           P4           PD4            
     BLUE             P5           PC6           
     ORANGE           P6           PD7           
     START            P7           PE6           
     DPAD UP          P8           PB4           
     DPAD DOWN        P9           PB5           
     DPAD LEFT        P10          PB6           
     DPAD RIGHT       P11          PB7           
     SELECT           P12          PD6           
 */
 
#include <Joystick.h>
#define Whammy A0 

Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID,JOYSTICK_TYPE_JOYSTICK,
  7, 1,                     // Button Count, Hat Switch Count (ONE DPAD)
  false, false, true,      // No X ,No Y , only  Z Axis
  false, false, false,    // NO Rx, No Ry or Rz
  false, false,          // No rudder or throttle
  false, false, false); // No accelerator, brake, or steering

 
  int WhammyBarValue = 0; 
  int WhammyBarValueByte = 0;
  
void setup() {
 
// Initialize the Joystick Library | INICIALIZA A BIBLIOTECA JOYSTICK
    Joystick.begin();
    
// DECLARE PORTS IN RESPECTIVE BANKS AS INPUT(0), FOR OUPUT USE(1) | DECLARA AS PORTAS EM SEUS RESPECTIVOS BANCOS COMO ENTRADA(0), PARA SAIDA USE(1)
     
    //EXAMPLE: DDRB = B | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
    // IS EQUAL TO:     |PB7|PB6|PB5|PB4|PB3|PB2|PB1|PB0|
     
    DDRB = B00000000;
    DDRC = B00000000;
    DDRD = B00000000;
    DDRE = B00000000;
    
 }
void loop() {

//The while function is a loop inside Void loop | A função while é um loop dentro de voip loop
while(true){
  
// READ BUTTONS WHEN PRESSED | LÊ OS BOTÕES QUANDO PRESSIONADOS
// THE BUTTON 0 ON THE CODE CORRESPONDS TO THE BUTTON 1 ON THE CONTROLLER | O BOTÃO 0 NO CODIGO CORRESPONDE AO BOTÃO 1 NO CONTROLE
// PIN FUNCTION READ THE STATE OF INPUT PINS | FUNÇÃO PIN LÊ O ESTADO DOS PINOS DE ENTRADA

  Joystick.setButton(0,!(PIND & (0x01 << 1))); //GREEN
  Joystick.setButton(1,!(PIND & (0x01 << 0))); //RED
  Joystick.setButton(2,!(PIND & (0x01 << 4))); //YELLOW
  Joystick.setButton(3,!(PINC & (0x01 << 6))); //BLUE
  Joystick.setButton(4,!(PIND & (0x01 << 7))); //ORANGE
  Joystick.setButton(5,!(PIND & (0x01 << 6))); //START
  Joystick.setButton(6,!(PINE & (0x01 << 6))); //SELECT

// READ DPAD WHEN PRESSED  | LÊ O DIRECIONAL QUANDO PRESSIONADO

  if (!(PINB & (0x01 << 4))){
  Joystick.setHatSwitch(0,0);} // DPAD-UP
  
  else if (!(PINB & (0x01 << 5))){
  Joystick.setHatSwitch(0,180);} // DPAD-DOWN
  
  else if (!(PINB & (0x01 << 6))){
  Joystick.setHatSwitch(0,270);} // DPAD-LEFT
  
  else if (!(PINB & (0x01 << 7))){
  Joystick.setHatSwitch(0,90);} // DPAD-RIGHT
   
  else { Joystick.setHatSwitch(0,-1);} // DPAD BACK TO ZERO
 
// READ THE WHAMMY BAR - A0 | LÊ A ALAVANCA - A0 

     WhammyBarValue = analogRead(Whammy);
     if (WhammyBarValue >= 3) {
     WhammyBarValueByte = WhammyBarValue *1;
     } else { WhammyBarValueByte = 0;
     } Joystick.setZAxis(WhammyBarValueByte);
    }
  }
