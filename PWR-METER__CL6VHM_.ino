 /*
   RF_pwr_metro
   Lee una entrada analógica en el pin 0, la convierte a voltaje, dBm y W e imprime el resultado en el monitor serie.
   El hardware se basa en el amplificador de registro AD8307 (detector de potencia). Consulte la página 21, figura 41 en la hoja de datos.
   Creado por Victor Hernández Miteff(CL6VHM)
  */
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // Initialize serial communication and LCD
  Serial.begin(9600);
  lcd.begin(16, 2);

  // Display a startup message on the LCD
  lcd.setCursor(5, 0);
  lcd.print("CL6VHM");
  lcd.setCursor(1, 1);
  lcd.print("RF-Power meter");
  delay(4000);
  lcd.clear();
}
void loop() {
  // Read analog input on pin A0
  float sensorValue = analogRead(A0);

  // Convert analog reading to voltage
  float voltage1 = sensorValue * (5.047 / 1023.0);
  float voltage = voltage1 / 2; // Divide by 2 because of 2x opamp on input

  // Calculate dBm, power in uW, mW, and W
  double dBm = (40 * voltage - 40);
  double Pu = pow(10.0, (dBm + 30) / 10.0);
  double Pm = pow(10.0, dBm / 10.0);
  double Pw = pow(10.0, (dBm - 30) / 10.0);

  // Print voltage and dBm on the Serial monitor
  Serial.print(voltage);
  Serial.print("V ");
  Serial.print(dBm);
  Serial.print("dBm ");

  // Display dBm on the LCD
  lcd.setCursor(0, 0);
  lcd.print(dBm);
  lcd.print("dBm ");

  // Display power information on the LCD
  lcd.setCursor(0, 1);
  if (dBm <= 0) {
    // If dBm is less than or equal to 0, display power in uW
    Serial.print(Pu);
    if (dBm <= 0) {
      Serial.println("uW");
    }
    if (dBm <= 0) {
      lcd.print(Pu);
    }
    if (dBm <= 0) {
      lcd.println("uW");
    }
  } else if (dBm >= 30) {
    // If dBm is greater than or equal to 30, display power in W
    Serial.print(Pw);
    if (dBm >= 30) {
      Serial.println("W");
    }
    if (dBm >= 30) {
      lcd.print(Pw);
    }
    if (dBm >= 30) {
      lcd.println("W");
    }
  } else {
    // Otherwise, display power in mW
    Serial.print(Pm);
    Serial.println("mW ");
    lcd.print(Pm);
    lcd.print("mW ");
  }

  // Delay before the next iteration
  delay(500);
}
