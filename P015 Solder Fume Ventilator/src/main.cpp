// P015 Solder Fume Extractor

// INFO
// PC-FAN 4-Wire Pinout: https://www.techpowerup.com/forums/attachments/4-pin-fan-wiring-diagram-basic-electronics-wiring-diagram-jpg.159557/

// BOM - search on Ali and youl find plenty of options :)
// RP2040 Board (Color: RP2040 TYPE-C 4MB) -> yes this is overkill but i whanted to use a RP2040 for a project...
// Switch momentary:     https://de.aliexpress.com/item/4000164264475.html?spm=a2g0o.order_list.order_list_main.107.3d625c5fIIlSB3&gatewayAdapt=glo2deu
// Potentiomieter 10k:
// Battery 18650
// TP4065 Charger
// Transistor 2N2222 (may not be necessary when using a 5V board, as the signal to the PC-FAN is 5V, didn't test it with 3.3V)
// Resistor 1K
// PC-FAN 90/92mm 4-Wire (3 used -> 12V, GND, PWM)
// Convertter 12V to 5V L7805CV (there may be a design that works without this but i find it convenient to switch power only after the charger module)
// Booster 5V to 12V
// USB-C Power Connector
// 6x M5 Screws 6-14mm should work fine

// Code

#include <Arduino.h>
#include "RP2040_PWM.h"

#define _PWM_LOGLEVEL_ 3

// creates pwm instance
RP2040_PWM *PWM_Instance;

float frequency = 25000;
float dutyCycle;

#define pinToUse 8
#define pinPoti 28

int potVal = 0;

void setup()
{
  // put your setup code here, to run once:

  Serial.begin(115200);

  // assigns pin 25 (built in LED), with frequency of 25 KHz and a duty cycle of 0%
  PWM_Instance = new RP2040_PWM(pinToUse, frequency, dutyCycle);
  pinMode(pinPoti, INPUT);
}

void loop()
{
  // put your main code here, to run repeatedly:

  //  testSequence();

  potVal = analogRead(pinPoti);
  dutyCycle = map(potVal, 10, 1023, 0, 100);
  PWM_Instance->setPWM(pinToUse, frequency, dutyCycle);

  //  Serial.println(potVal);
  //  delay(1000);
}

void testSequence() // for tests only
{
  Serial.println("100%");
  dutyCycle = 100;
  PWM_Instance->setPWM(pinToUse, frequency, dutyCycle);
  delay(3000);

  Serial.println("65%");
  dutyCycle = 65;
  PWM_Instance->setPWM(pinToUse, frequency, dutyCycle);
  delay(3000);

  Serial.println("50%");
  dutyCycle = 50;
  PWM_Instance->setPWM(pinToUse, frequency, dutyCycle);
  delay(3000);

  Serial.println("25%");
  dutyCycle = 25;
  PWM_Instance->setPWM(pinToUse, frequency, dutyCycle);
  delay(3000);

  Serial.println("0%");
  dutyCycle = 0;
  PWM_Instance->setPWM(pinToUse, frequency, dutyCycle);
  delay(3000);
}