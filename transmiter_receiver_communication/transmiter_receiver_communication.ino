#include <RH_ASK.h>
#ifdef RH_HAVE_HARDWARE_SPI
#include <SPI.h> // Not actually used but needed to compile
#endif
 
RH_ASK driver(2000, 3, 12, 0);
// RH_ASK driver(2000, 4, 5, 0); // ESP8266 or ESP32: do not use pin 11 or 2
// RH_ASK driver(2000, 3, 4, 0); // ATTiny, RX on D3 (pin 2 on attiny85) TX on D4 (pin 3 on attiny85), 
// RH_ASK driver(2000, PD14, PD13, 0); STM32F4 Discovery: see tx and rx on Orange and Red LEDS
 
void setup()
{
  #ifdef RH_HAVE_SERIAL
      Serial.begin(9600);   // Debugging only
  #endif
      if (!driver.init())
  #ifdef RH_HAVE_SERIAL
          Serial.println("init failed");
  #else
          ;
  #endif
}
 
void loop()
{
  // transmitter part
  //  const char *msg = "hello";
  //  driver.send((uint8_t *)msg, strlen(msg));
  //  driver.waitPacketSent();
  //  delay(200);

  // receiver part
    uint8_t buf[RH_ASK_MAX_MESSAGE_LEN];
    uint8_t buflen = sizeof(buf);
    if (driver.recv(buf, &buflen)) // Non-blocking
    {
        int i;
        // Message with a good checksum received, dump it.
        driver.printBuffer("Got:", buf, buflen);
    }
}