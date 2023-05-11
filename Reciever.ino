#include <VirtualWire.h>
char *data;
char input;

void setup() {
pinMode (4, OUTPUT);
pinMode(5, OUTPUT);
pinMode(6, OUTPUT);
pinMode(7, OUTPUT);

Serial.begin(96000);

vw_set_rx_pin(3);
vw_setup(2000);
pinMode(3,OUTPUT);
vw_rx_start();
}

void loop() {
uint8_t buf[VW_MAX_MESSAGE_LEN];
uint8_t buflen=VW_MAX_MESSAGE_LEN;
Serial.print(buf[0]);
if(vw_get_message(buf, buflen))
{
  if(buf[0] == 'F')
  {
    forward(); 
  }
  else if(buf[0] == 'G')
  {
    backward();
  }
  else if(buf[0] == 'L')
  {
    left();
  }
  else if(buf[0] == 'R')
  {
    right();
  }
  else if(buf[0] == 'S')
  {
    stop();
  }
}
}

void forward()
  {
  digitalWrite(7, HIGH  );
  digitalWrite(6, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(4, LOW);
}

void stop()
  {
  digitalWrite(4, LOW );
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
}

void backward()
  {
  digitalWrite(7, LOW  );
  digitalWrite(6,HIGH);
  digitalWrite(5, LOW);
  digitalWrite(4, HIGH);
}

void right()
  {
  digitalWrite(7, LOW  );
  digitalWrite(6, LOW);
  digitalWrite(5, LOW);
  digitalWrite(4, HIGH);
}

void left()
  {
  digitalWrite(7, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(5, LOW);
  digitalWrite(4, LOW);
}
