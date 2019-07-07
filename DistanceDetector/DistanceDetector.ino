//Извикваме библиотеката, необходима за ползване на дисплея 
#include <LiquidCrystal.h>

//Инициализираме обект от библиотеката, като в него поставяме номерата
//на необходимите ни пинове, чрез които правим връзката между дисплея и платката
const int rs = 12, e = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, e, d4, d5, d6, d7);

//Декларираме елементите от сензора, които изпращат и получат вълните
const int trigPin = 10;
const int echoPin = 9;

float cm = 0;

long readUltrasonicDistance(int trigPin, int echoPin)
{
  //Изчиства предишен резултат, изчаква и изпраща вълна до обекта
  pinMode(trigPin, OUTPUT); 
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  pinMode(echoPin, INPUT);

  //echoPin прочита времето на връщане на звуковата вълна в микросекунди
  return pulseIn(echoPin, HIGH);
}

//Тук стартираме дисплея 
void setup()
{
lcd.begin(16, 2);
}

void loop()
{
  //Превръща измерените микросекунди в сантиметри и ги записва в променливата
  cm = 0.01723 * readUltrasonicDistance(10, 9);
  
  //Изписва съобщението, след това минава на втория ред, където изписва
  //измереното разстояние чрез променливата cm
  lcd.print("Distance:");  
  lcd.setCursor(0, 1);
  lcd.print(cm);

  //Изчаква 1000 милисекунди и изчиства дисплея, за да може да се заредят 
  //новите данни
  delay(1000); 
  lcd.clear(); 
}
