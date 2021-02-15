#include <MHZ19_uart.h>

#define BOARD_LED_PIN 2 // D4 on board

#define MHZ_RX 0  // D3 on board
#define MHZ_TX 4  // D2 on board

MHZ19_uart mhz19;
int dispCO2;

void setup() {
  // Serial  
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(BOARD_LED_PIN, OUTPUT);
  // <----------- CO2 sensor -----------> //
  mhz19.begin(MHZ_TX, MHZ_RX);
  mhz19.setAutoCalibration(false);
  mhz19.getStatus();    // первый запрос, в любом случае возвращает -1
  if (mhz19.getStatus() == 0) Serial.println(F("CO2 sensor OK"));
  else Serial.println(F("CO2 sensor FAILER"));
    
    

}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(BOARD_LED_PIN, HIGH);
  delay(500);
  digitalWrite(BOARD_LED_PIN, LOW);
  delay(500);
  dispCO2 = mhz19.getPPM();
  Serial.println(dispCO2);
}
