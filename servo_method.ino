
void moveMotor() // 향수를 뿌리는 서보 모터 각도 조절 함수
{
  attachMyservo(); // 위 서보 모터 attach
  for(pos = 75; pos >= st; pos -= 1)  // 75 -> 0 각도로 서보 모터 이동
  {                                  
    myservo.write(pos);              // pos각도로 서보 모터 이동
    delay(5);                       
  } 
  for(pos = st; pos <= 75; pos += 1)  // 0 -> 75 서보 모터 이동
  {                                  
    myservo.write(pos);              
    delay(5);                       
  }
}

void underMotor(char ch) // 판을 이동 시키는 서보 모터 함수
{
  attachUnderservo(); // 아래 서보 모터 attach
  if(ch=='1') // 1번 위치로 
  {
    if(underpos != firstPoint) // 1번 위치가 아닐 경우 for문을 통한 각도 조절
    {
      for( ; underpos >= firstPoint; underpos -= 1)  
      {                                  
        underservo.write(underpos);              
        delay(20);                       
      } 
      underpos= firstPoint;
    }
  }
  if(ch=='2') // 2번 위치
  {
    attachUnderservo();
    if(underpos == firstPoint) // 아래 서보 모터가 1번 위치인 경우 for문을 통해 2번 위치까지 서보 각도 조절
    {
      for(; underpos <= secondPoint; underpos += 1)  
      {                                 
        underservo.write(underpos);           
        delay(20);                   
      } 
      underpos = secondPoint;
    }
    else if(underpos == thirdPoint) // 아래 서보 모터가 2번 위치인 경우 for문을 통해 2번 위치까지 서보 각도 조절
    {
      for( ; underpos >= 82; underpos -= 1) 
      {                              
        underservo.write(underpos);          
        delay(20);                    
      } 
      underpos = secondPoint;
    }
    
  }
  if(ch =='3') // 3번 위치
  {
    if(underpos!=thirdPoint) // 서보 모터가 3번 위치가 아닌 경우 3번 위치까지 서보 모터 각도 조절
    {
      for( ; underpos <= thirdPoint; underpos += 1)  
      {                                
        underservo.write(underpos);              
        delay(20);                       
      } 
      underpos = thirdPoint;
    }
  }
  delay(1000);
  moveMotor();
  delay(2000);
  closeMotor(); // 서보 모터 연결 해제( 2개다 )
}

void attachUnderservo() // 아래 서보 모터 연결
{
  underservo.attach(9);  // 아래 서보 모터 연결
  if(myservo.attached()) // 위 서보 모터 연결 확인 연결 되어 있는 경우 서보 모터 연결 해제
  {
    myservo.detach();  
  }
}

void attachMyservo() // 위 서보 모터 연결
{
  myservo.attach(10);  // 위 서보 모터 연결
  if(underservo.attached()) // 아래 서보 모터 연결 확인 연결 되어 있는 경우 서보 모터 연결 해제
  {
  underservo.detach();  
  }
}

void startUnderMotor() // 프로그램 시작시 각각의 서보 모터 각도 조절
{
  attachUnderservo();
  underservo.write(45);
  delay(2000);
  underservo.write(90);
  underpos = 90;
}

void closeMotor()// 서보 모터 두개 연결 해제
{
  
  if(underservo.attached())
    underservo.detach();
  if(myservo.attached())
    myservo.detach();
  
}


