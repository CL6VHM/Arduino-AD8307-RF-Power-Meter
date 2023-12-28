# Arduino-AD8307-RF-Power-Meter
Arduino-AD8307-RF-Power-Meter
In this project, an AD8307 is used as an RF sensor and an Arduino nano is used to display dBm values ​​and their equivalence in uW, mW or W through an LCD16x2.
*Description of how the code works:
To measure PWR, one of the analog inputs of the Arduino is used to measure the output voltage of the AD8307, and according to the AD8307 technical sheet, it is converted from voltage to dBm and using a conversion table it is converted from dBm to W and the power values ​​in dBm and W are displayed through the 16x2 LCD.
**Please note, the code has not been tested yet and may contain errors.**
**Suggestions are accepted**
