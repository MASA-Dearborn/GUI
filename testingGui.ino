int i=10000;
void setup() {
Serial.begin(9600);

}

void loop() {
  Serial.print("#");
  String a=String("!"+String(i)+","+String(i)+","+String(i)+","+String(i)+","+String(i)+",");
  Serial.println(a);
  i++;
  delay(50);
}
