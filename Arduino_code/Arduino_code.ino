char data;
void setup()
 {
  Serial.begin(115200);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  digitalWrite(6, LOW);
  digitalWrite(5, LOW);
}

void loop()
{
   if(Serial.available() > 0) 
  {
    data = Serial.read();
    Serial.print(data);
    Serial.print("\n");         
    else if(data == '3')      
      digitalWrite(6, HIGH);  
    else if(data == '4')      
      digitalWrite(6, LOW);  
      else if(data == 'q')      
      digitalWrite(5, HIGH);  
    else if(data == '2')      
      digitalWrite(5, LOW); 
  }                           
}
