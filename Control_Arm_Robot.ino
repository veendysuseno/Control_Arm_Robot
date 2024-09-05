// Control_Arm_Robot
#include <Servo.h>  
Servo servo1; 
Servo servo2; 
Servo servo3; 
Servo servo4; 
Servo servo5; 
unsigned int sudut;
String inString="",temStr;
char str;
unsigned int nomor,l,i;
void setup(){  
  Serial.begin(9600);  
  servo1.attach(2);//pin 2=servo1
  servo2.attach(3);//pin 3=servo2
  servo3.attach(4);//pin 4=servo3
  servo4.attach(5);//pin 5=servo4
  servo5.attach(6);//pin 6=servo5
  servo1.write(90);
  servo2.write(90);
  servo3.write(90);
  servo4.write(90);
  servo5.write(90); 
  Serial.println("ROBOT ARM CONTROLLER");
}

void loop(){
if(Serial.available()>0) 
  {    
      str = Serial.read();
      if(str!='\n')
        {  
          inString += (char)str;          
        }  
      else if (str == '\n')      
        {                    
        temStr=inString.substring(0,1);
        nomor=temStr.toInt();
        temStr=inString.substring(2);
        sudut=temStr.toInt(); 
        Serial.print(nomor);
        Serial.print(" : ");
        Serial.println(sudut);
        switch(nomor){
            case 1:servo1.write(sudut); break;
            case 2:servo2.write(sudut); break;
            case 3:servo3.write(sudut); break;
            case 4:servo4.write(sudut); break;
            case 5:servo5.write(sudut); break;
        }          
        inString = "";
        }
  }
}

