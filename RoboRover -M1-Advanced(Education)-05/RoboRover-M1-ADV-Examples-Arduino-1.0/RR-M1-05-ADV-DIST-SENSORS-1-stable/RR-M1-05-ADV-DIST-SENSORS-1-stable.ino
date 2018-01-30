#include <ServoRoboRoverM1_05.h>
#include <SharpA21RoboRoverM1_05.h>
#include <HCSR04RoboRoverM1_05.h>

ServoMotor myServo;
Sharp mySharpA0;
Sharp mySharpA1;
Ultrasonic myUltrasonic;

void setup() {
  Serial.begin(9600);
  myServo.attach();
  mySharpA0.attach(A0);
  mySharpA1.attach(A1);
  myUltrasonic.attach();
}

void loop() {
  // Программа по выводу значений с ИК-датчиков расстояния в Монитор последовательного порта Arduino IDE.

  // Введение:
  // Для работы программы не требуется подавать питание на моторы и сервопривод через Тумблеры питания.

  // 1. Подключи робота к компьютеру и загрузи программу в робота через Arduino IDE.
  // 2. Открой Монитор последовательного порта в Arduino IDE и смотри показания с датчика.

  // Описание программы:
  // Настройка -В программе настраивается Последовательной порт Serial на скорости 9600 бод/с. Настраивается сервопривод робота.

  // Цикл -В Монитор последовательного порта выводятся показания с левого ИК-датчика, а затем с правого ИК-датчика. Потом происходит задержка в 1 секунду и цикл повторяется вновь.
  "Справка о программе. Кликни на знак ?";

  myServo.write(90);
  Serial.print("Расстояние с левого ИК-датчика ");
  Serial.println(mySharpA0.read());
  Serial.print("Расстояние с правого ИК-датчика ");
  Serial.println(mySharpA1.read());
  Serial.print("Расстояние с УЗ-датчика ");
  Serial.println(myUltrasonic.read());
  Serial.println("");
  delay(1000);

}
