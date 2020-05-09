/*
 * Example of iParse function.
*/

int resultz[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};


void setup() {
  Serial.begin(115200);
  delay(10);
  Serial.println();
  Serial.println(F("iParse() demo"));

  char buf[10];                             //Make a real string.
  strcpy(buf, "10,11,12");

  Serial.print(F("buf= "));
  Serial.println(buf);
  Serial.println();

  iParse(buf, ",", resultz);

  for (int i = 0; i < 3; i++) {             //Show the values array
    Serial.print(F("resultz["));
    Serial.print(i);
    Serial.print(F("]= "));
    Serial.println(resultz[i]);
  }
  Serial.println();
}


void loop() {
}
