// C++ code
#include <Adafruit_LiquidCrystal.h>

int sendPin = 4;
Adafruit_LiquidCrystal lcd_1(0);

// Advertisement messages
const char* ads[] = {
  "50% OFF Shoes!",
  "Buy1 Get1 Pizza",
  "Super Sale Today",
  "Discount @ Mall",
  "Gym 20% OFF Now"
};
const int adCount = 5;
int currentAd = 0;

unsigned long lastAdChange = 0; // for timing

void setup() {
  pinMode(sendPin, INPUT);  // setup input pin
  lcd_1.begin(16, 2);
  lcd_1.print("Traffic Display");
  delay(800);
}

void loop() {
  int state = digitalRead(sendPin);

  if (state == HIGH) {
    // Red Light (ads running but backlight OFF)
    
    lcd_1.setCursor(0, 0);
    lcd_1.print("GO!!");
    lcd_1.setCursor(0, 1);
    lcd_1.print("No Ads");
    
	lcd_1.setBacklight(0);
  } else if (state == LOW) {
    // Green/Yellow Light (backlight ON, no ads)
    lcd_1.setBacklight(1);
    lcd_1.clear();
    // show current ad
      // dim the LCD

    // Change ad every 2 seconds
    if (millis() - lastAdChange >= 2000) {
      lastAdChange = millis();
      currentAd = (currentAd + 1) % adCount;
      lcd_1.clear();
      lcd_1.setCursor(0, 0);
      lcd_1.print("STOP - RED");
      lcd_1.setCursor(0, 1);
      lcd_1.print(ads[currentAd]);
      
      delay(2000);
      lcd_1.clear();
    }
    delay(200);
  }

   // small delay to avoid flicker
}
