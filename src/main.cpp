#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

#define LEDS_VERDE 18
#define LED1_ROJO 27
#define LED2_ROJO 26
#define LED3_ROJO 25
#define LED4_ROJO 33

#define TECLA_1 34
#define TECLA_2 19
#define TECLA_3 16
#define TECLA_4 15

#define BUZZER  23


char letra[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p',
                 'q','r','s','t','u','v','w','x','y', 'z'};


char pasword[] = { 'h', 'o', 'l', 'a'};
int intentos = 4;

void setup() {

    lcd.init();
    lcd.backlight();
    lcd.setCursor(5,0);
    lcd.print("ALARMSEC");
    delay(3000);

    pinMode(TECLA_1, INPUT_PULLUP);
    pinMode(TECLA_2, INPUT_PULLUP);
    pinMode(TECLA_3, INPUT_PULLUP);
    pinMode(TECLA_4, INPUT_PULLUP);

    pinMode(LEDS_VERDE, OUTPUT);
    pinMode(LED1_ROJO, OUTPUT);
    pinMode(LED2_ROJO, OUTPUT);
    pinMode(LED3_ROJO, OUTPUT);
    pinMode(LED4_ROJO, OUTPUT);

    pinMode(BUZZER, OUTPUT);
    ledcSetup(0, 8000, 8);
    ledcAttachPin(BUZZER, 0);

    digitalWrite(LEDS_VERDE, HIGH);
    digitalWrite(LED1_ROJO, HIGH);
    digitalWrite(LED2_ROJO, HIGH);
    digitalWrite(LED3_ROJO, HIGH);
    digitalWrite(LED4_ROJO, HIGH);
    delay(1000);
    digitalWrite(LEDS_VERDE, LOW);
    digitalWrite(LED1_ROJO, LOW);
    digitalWrite(LED2_ROJO, LOW);
    digitalWrite(LED3_ROJO, LOW);
    digitalWrite(LED4_ROJO, LOW);

}

void loop() {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Introduzca la co");
    lcd.setCursor(0,1);
    lcd.print("ntrasenia:");

    char nuev[4];

    while(intentos !=0){
        int i=0;
        int pintado = 0;
        while(true){
            if(pintado == 0) {
                lcd.setCursor(11, 1);
                lcd.print(letra[i]);
                pintado = 1;
            }
            if(digitalRead(TECLA_1) == HIGH) {
                if (i == 25) {
                    i = 0;
                } else {
                    i++;
                    delay(500);
                }
                pintado = 0;
            }
            if(digitalRead(TECLA_3) == false) {
                if (i == 0) {
                    i = 25;
                    delay(500);
                } else {
                    i--;
                    delay(500);
                }
                pintado = 0;
            }
            if(digitalRead(TECLA_2) == false){
                delay(500);
                nuev[0] = letra[i];
                break;
            }
        }


        pintado = 0;
        i = 0;
        while(true){
            if(pintado == 0) {
                lcd.setCursor(12, 1);
                lcd.print(letra[i]);
                pintado = 1;
            }
            if (digitalRead(TECLA_1) == HIGH) {
                if (i == 25) {
                    i = 0;
                    delay(500);
                } else {
                    i++;
                    delay(500);
                }
                pintado = 0;
            }if(digitalRead(TECLA_3) == false) {
                if (i == 0) {
                    i = 25;
                    delay(500);
                } else {
                    i--;
                    delay(500);
                }
                pintado = 0;
            }
            if(digitalRead(TECLA_2) == false){
                delay(500);
                nuev[1] = letra[i];
                break;
            }
        }


        pintado = 0;
        i = 0;
        while(true){
            if(pintado == 0) {
                lcd.setCursor(13, 1);
                lcd.print(letra[i]);
                pintado = 1;
            }
            if (digitalRead(TECLA_1) == HIGH) {
                if (i == 25) {
                    i = 0;
                    delay(500);
                } else {
                    i++;
                    delay(500);
                }
                pintado = 0;
            }if(digitalRead(TECLA_3) == false) {
                if (i == 0) {
                    i = 25;
                    delay(500);
                } else {
                    i--;
                    delay(500);
                }
                pintado = 0;
            }
            if(digitalRead(TECLA_2) == false){
                delay(500);
                nuev[2] = letra[i];
                break;
            }
        }


        pintado = 0;
        i = 0;
        while(true){
            if(pintado == 0) {
                lcd.setCursor(14, 1);
                lcd.print(letra[i]);
                pintado = 1;
            }
            if(digitalRead(TECLA_1) == HIGH) {
                if (i == 25) {
                    i = 0;
                    delay(500);
                } else {
                    i++;
                    delay(500);
                }
                pintado = 0;
            }if(digitalRead(TECLA_3) == false) {
                if (i == 0) {
                    i = 25;
                    delay(500);
                } else {
                    i--;
                    delay(500);
                }
                pintado = 0;
            }
            if(digitalRead(TECLA_2) == false) {
                delay(500);
                nuev[3] = letra[i];
                break;
            }
        }
        delay(500);


        while (1) {
            if(digitalRead(TECLA_4) == false){
                if(nuev[0] == pasword[0] && nuev[1] == pasword[1] && nuev[2] == pasword[2] &&
                   nuev[3] == pasword[3]) {
                    lcd.clear();
                    lcd.setCursor(5,0);
                    lcd.print("CORRECTO");
                    digitalWrite(LEDS_VERDE, HIGH);
                    delay(3000);
                    intentos = 0;
                    ledcWriteNote(0, NOTE_G, 4);
                    delay(1000);
                    ledcWrite(0, 0);
                    if (intentos == 0) {
                        lcd.clear();
                        lcd.setCursor(3,0);
                        lcd.print("BIENVENIDO");
                    }
                } else {
                    lcd.clear();
                    lcd.setCursor(5,0);
                    lcd.print("INCORRECTO");
                    delay(2000);
                    intentos--;
                    if (intentos == 3) digitalWrite(LED1_ROJO, HIGH);
                    if (intentos == 2) digitalWrite(LED2_ROJO, HIGH);
                    if (intentos == 1) digitalWrite(LED3_ROJO, HIGH);
                    if(intentos == 0) {
                        digitalWrite(LED4_ROJO, HIGH);
                        lcd.clear();
                        delay(100);
                        lcd.setCursor(0, 0);
                        lcd.print("ACCESO DENEGADO");
                        ledcWriteNote(0, NOTE_A, 4);
                        delay(1000);
                        ledcWrite(0, 0);
                    } else {
                        break;
                    }

                }
            }
        }

    }
}