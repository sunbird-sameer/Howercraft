#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
    #include <ESP8266WiFi.h>
    #include <BlynkSimpleEsp8266.h>

    // You should get Auth Token in the Blynk App.
    // Go to the Project Settings (nut icon).
  char auth[] = "auth";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "ssid";
char pass[] = "pasword";


    //Standard PWM DC control
    int E1 = 5;     //M1 Speed Control D1 Motor A
    int E2 = 4;     //M2 Speed Control D2 Motor B




    /* --GPIO Define
    2     function initGPIO()
    3     --1,2EN     D1 GPIO5
    4     --3,4EN     D2 GPIO4
    5     --1A  ~2A   D3 GPIO0
    6     --3A  ~4A   D4 GPIO2
    */  

    void setup()
    {
       pinMode(5, OUTPUT);//power to motor
       pinMode(4, OUTPUT);//power to motor

       int lm=0;
       int rm=0;

       
       analogWrite (E1,lm);
       analogWrite (E2,rm);

       
      Serial.begin(9600);
      Blynk.begin(auth, ssid, pass);    }
    // This function will be called every time
    // when App writes value to Virtual Pin 1



      BLYNK_WRITE(V1) {
      int x = param[0].asInt();
      int y = param[1].asInt();

      // Do something with x and y

      int lm=0;
      int rm=0;

      if (x<=512){
        lm=1023-2*(513-x);
        rm=1023;
      }
      else if (x>512){
      rm =1023-2*(x-512);
      lm=1023;
      }

      Serial.print("LM = ");
      Serial.println(lm);
      Serial.print(" RM = ");
      Serial.println(rm);


    /*  if (y > 30 && x < -30){
      analogWrite (E1,1-(y+abs(x)));      //PWM Speed Control
      digitalWrite(M1,LOW);    
      analogWrite (E2,1-(y-abs(x)));    
      digitalWrite(M2,HIGH);
      }

       if (y > 30 && x > 30){
       analogWrite (E1,1-(y-abs(x)));      //PWM Speed Control
      digitalWrite(M1,LOW);    
      analogWrite (E2,1-y+abs(x));    
      digitalWrite(M2,HIGH);
      }*/
     
     /* else if (x < -30 && y > 0){
     // analogWrite (E1,1+(y-abs(x)));      //PWM Speed Control
     analogWrite (E1,-y-abs(x));
      digitalWrite(M1,LOW);    
      analogWrite (E2,-y+abs(x));  
      digitalWrite(M2,HIGH);
      }

      else if (x > 30 && y > 0){
      analogWrite  (E1,-y+abs(x));       //PWM Speed Control
      digitalWrite(M1,LOW);    
      analogWrite (E2,-y-abs(x));  
      digitalWrite(M2,HIGH);
      }*/


       analogWrite (E1,lm);
       analogWrite (E2,rm);

    }
     

    void loop()
    {
      Blynk.run();

    }


