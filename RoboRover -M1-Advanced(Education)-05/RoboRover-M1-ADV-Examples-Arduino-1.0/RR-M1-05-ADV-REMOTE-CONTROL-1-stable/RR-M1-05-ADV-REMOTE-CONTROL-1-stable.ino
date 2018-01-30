#include <MotorL298NRoboRoverM1_05.h>
#include <IRremote.h>
#include <ServoRoboRoverM1_05.h>
#include <Servo.h>

ServoMotor myServo;
Motors myMotors;
int RECV_PIN = 12;

IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  myMotors.attach();
  myServo.attach();
}

void loop() {

  // Программа по управлению роботом при помощи ИК-пульта. Не забудь достать защитную пленку из пульта! Батарейка внутри пульта.

  // Введение:

  // 1. Подключи робота к компьютеру и загрузи программу в робота через Arduino IDE.
  // 2. Поставь два переключателя в крайнее левое положение.
  // 3. Управляй роботом стрелочками, ОК-стоп. 1-сервопривод влево, 2-сервопривод центральное положение, 3-сервопривод вправо. Если на роботе установлен зеленый кожух, то он снижает уровень приема сигнала от пульта. Рекомендуется управлять роботом без кожуха.

  if (irrecv.decode(&results))
  {
    Serial.println(results.value);
    if (results.value == 16718055) //прямо
    {
      myMotors.write(255, 255);
    }
    if (results.value == 16726215) //стоп
    {
      myMotors.write(0, 0);
    }
    if (results.value == 16730805) //назад
    {
      myMotors.write(-255, -255);
    }
    if (results.value == 16716015) //влево
    {
      myMotors.write(-255, 255);
    }
    if (results.value == 16734885) //вправо
    {
      myMotors.write(255, -255);
    }
    if (results.value == 16736925) //серво центр
    {
      myServo.write(90);
    }
    if (results.value == 16753245) //серво влево
    {
      myServo.write(145);
    }
    if (results.value == 16769565) //серво вправо
    {
      myServo.write(35);
    }
    irrecv.resume();
  }
}
