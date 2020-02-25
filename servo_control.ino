#include<Servo.h>
Servo myservo;
int pos = 0;

void setup()  
{  
 Serial.begin(9600);  
 myservo.attach(9); 
 myservo.write(0);
 delay(10000);
}  

void loop()  
{   
   while(Serial.available())  //读取HC-05接收到的字符串
   {  char c;
      c=Serial.read();
      Serial.println (c);
      switch(c){
        case '1':servo_init();
        break;
        case '2':open_the_door();
        break;
        case '3':close_the_door();
        break;
        default:servo_init();
        
      }
   }

}

void servo_init()  //舵机初始化
{   
  myservo.write(0);
  delay(1000);
}

void open_the_door()  //舵机开门
{  
    for (pos = 0; pos <= 180; pos += 1) { 
    myservo.write(pos);            
    delay(5);                       
  }
}

void close_the_door()  //舵机关门
{  
    for (pos = 180; pos >= 0; pos -= 1) { 
    myservo.write(pos);              
    delay(5);   
    }
}
