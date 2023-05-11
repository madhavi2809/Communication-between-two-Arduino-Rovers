#include <VirtualWire.h>
char *data;
char input;
int LED = 9;

void setup(){
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  
  Serial.begin(9600);  
  vw_set_tx_pin(3);
  vw_setup(2000);
  pinMode(LED, OUTPUT);
}

void loop(){
  digitalWrite(LED, LOW);
  
  while(Serial.available())
  {
    digitalWrite(LED, HIGH);
    input = Serial.read();
    
    Serial.println(input);

    if(input == 'F')
    {
      data = "F";
      vw_send((uint8_t *)data, strlen(data));
      vw_wait_tx();
      forward();
    }
    else if (input== 'R')
    {
      data = "R";
      vw_send((uint8_t *)data, strlen(data));
      vw_wait_tx();
      right();
    }
    else if (input== 'L')
    {
      data = "L";
      vw_send((uint8_t *)data, strlen(data));
      vw_wait_tx();
      left();
    }
    else if (input== 'G')
    {
      data = "G";
      vw_send((uint8_t *)data, strlen(data));
      vw_wait_tx();
      backward();
    }  
    else if (input== 'S')
    {
      data = "S";
      vw_send((uint8_t *)data, strlen(data));
      vw_wait_tx();
      stop();
    }
  }
}
void stop(){;
  digitalWrite(7, LOW);
  digitalWrite(6, LOW);
  digitalWrite(5, LOW);
  digitalWrite(4, LOW);
}
void backward()
{
  digitalWrite(7, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(4, HIGH);
}
void forward()
{
  digitalWrite(7, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(4, LOW);
}
void left()
{
  digitalWrite(7, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(5, LOW);
  digitalWrite(4, LOW);
}
void right()
{
  digitalWrite(7, LOW);
  digitalWrite(6, LOW);
  digitalWrite(5, LOW);
  digitalWrite(4, HIGH);
}
