#include <Wire.h>
#include <Adafruit_MCP4725.h>   // incluye libreria Adafruit MCP4725

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
const uint8_t ancho = 128; //px
const uint8_t alto = 32; // 32px
#define OLED_RESET 4              // necesario por la libreria pero no usado
Adafruit_SSD1306 oled(ancho, alto, &Wire, OLED_RESET);


Adafruit_MCP4725 dac_mA;     // crear objeto con nombre dac
Adafruit_MCP4725 dac_V;     // crear objeto con nombre dac

unsigned int valor;

void setup() {
  Wire.begin();
  Serial.begin(9600);
  dac_mA.begin(0x60);      // inicializa DAC con direccion 0x62 GND o 0x63 VCC "ADDR"
  dac_V.begin(0x61);      // inicializa DAC con direccion 0x62 GND o 0x63 VCC "ADDR"
  Serial.println("Iniciando... I2C mA-V"); // texto estatico

  oled.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  oled.clearDisplay();
  oled.setTextColor(WHITE); // establece color al unico disponible (pantalla monocromo)
  oled.setCursor(5, 0);
  oled.setTextSize(2);
  oled.print("JADSA TV"); // escribe texto
  oled.setCursor(10, 16);
  oled.setTextSize(1);
  oled.print("  OLED"); // escribe texto
  oled.setCursor(10, 24);
  oled.setTextSize(1);
  oled.print("  128x32"); // escribe texto
  oled.display();
  delay(100);
}

void loop() {
  //valor = analogRead(0) * 4; // 1023*4 =4092
  //Serial.println(valor);
  dac_mA.setVoltage(3276, false);  // 4mA=819 8mA=1638 12mA=2457 16mA=3276 20mA=4095
  dac_V.setVoltage(2457, false);  // 2V=819  4V=1638  6V=2457   8V=3276   10V=4095
  delay(10000);
}
