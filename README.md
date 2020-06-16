# HC-SR04_Atmega328P
HC-SR04 distance sensor program on ATMega328P. It uses 8-bit Timer0 and interrupt on INT0 pin. 

Distance is displayed on 2x16 LCD HD44780 using I2C transmission. 
In I2C/i2c.c you can also find i2c scanner to locate yours device address.
