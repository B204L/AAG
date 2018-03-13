void oledPh() {
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(10,0);
  display.clearDisplay();
  display.println("pH \n" + phString);
  display.display();
  }

void oledORP() {
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(10,0);
  display.clearDisplay();
  display.println("ORP \n" + orpString);
  display.display();
  }

void oledEC() {
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(10,0);
  display.clearDisplay();
  display.println("EC \n" + ecString);
  display.display();
  }

