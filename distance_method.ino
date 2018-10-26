int checkDistance() // 거리 체크 함수
{
  int count = 0;  
  if(light1() == true)
  {
     underMotor('1');
  }
  else if(light2() == true)
  {
     underMotor('2');
  }
  else if(light3() == true)
  {
     underMotor('3');
  }
  else
  {
    
  }
}
boolean light1() // 1번 적외선 센서 거리 값 측정
{
  
  boolean check = false;
  
  float volts = analogRead(sensor1) * 0.0048828125; 

  distance1 = 13 * pow(volts, -1);

  delay(500);

  if(distance1 <= 6)
  {
    check = true;
  }

  return check;
}

boolean light2() // 2번 적외선 센서 거리 값 측정
{
  
  boolean check = false;
    
  float volts = analogRead(sensor2) * 0.0048828125; 

  distance2 = 13 * pow(volts, -1);

  delay(500);

  if(distance2 <= 6)
  {
    check = true;
  }

  return check;
}

boolean light3() // 3번 적외선 센서 거리 값 측정
{
  boolean check = false;
  
  float volts = analogRead(sensor3) * 0.0048828125; 

  distance3 = 13 * pow(volts, -1);

  delay(500);

  if(distance3 <= 6)
  {
    check = true;
  }

  return check;

}

