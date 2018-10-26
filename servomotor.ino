#include <Servo.h> //서보 라이브러리를 불러옵니다.

Servo myservo;  // 향수 서보를 제어할 서보 오브젝트를 만듭니다.
Servo underservo;  // 아래 서보를 제어할 서보 오브젝트를 만듭니다.            
   
int pos = 0;     // 서보 위치를 저장할 변수를 선언합니다.
int underpos = 0; //아래 서보모터 각도
int st = 0; // 위 서보 모터 각도 지정 값 75~0 이동

/* 적외선 거리 센서는 4~30cm 확인이 가능한 센서 이용 ( 모델명 : Sharp GP2Y0A41SKOF ) */
#define sensor1 A0 // 적외선 센서 1
#define sensor2 A1  // 적외선 센서 2
#define sensor3 A2  // 적외선 센서 3

int firstPoint = 40; // 1번 위치
int secondPoint = 90; // 2번 위치
int thirdPoint = 133; // 3번 위치

int distance1 = 0; // 1번 적외선 센서 거리 측정 값
int distance2 = 0; // 2번 적외선 센서 거리 측정 값
int distance3 = 0; // 3번 적외선 센서 거리 측정 값

void setup() 
{ 
  Serial.begin(9600);
  underservo.attach(9);  // 아래 서보 모터 연결
  myservo.attach(10);  // 위에 서보 모터 연결
  startUnderMotor(); // 아래 서보 모터 초기 값 맞추기
  delay(2000); // 2초 지연
  closeMotor(); // 서보 모터 연결 해제 함수
} 
 
 
void loop() 
{ 
  checkDistance(); // 적외선 센서를 통한 거리 확인 함수 
  if (Serial.available()) // 시리얼 통신 유무 확인
  {
    char ch = Serial.read();
   if( ch >= '1' && ch <='3')
   {
    underMotor(ch);
   }
  }
} 

