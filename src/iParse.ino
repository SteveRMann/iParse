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



void iParse(char *buf, char *delim, int (& intArray) [10]) {
  /*
   * buf contains a set of integers in a c-string, for example '12,13,14'
   * delim is the delimiter between integers, ","
   * intArray is an integer array that will receive the results
   * 
   * Why did I write this instead of using strtok()?
   * The strtok() function cannot properly handle blank data.
   * If the input data is, for example, '12,,14', strok() returns 12 and 14.
   * (If you are running it on an ESP processor, it will crash).
   * iParse would return 12,0, and 14 in this example.
   * This has only been tested on an Wemos D1 Mini (ESP8266).
   * 
   */
  int values[2];                            // Temporary results go here
  char tmpBuf[10];                          // Temp buffer, we build the results here
  int j = 0;
  int intArrayPtr = 0;

  for (int i = 0; i < strlen(buf); i++) {   //For each character in the input buffer...
    if (buf[i] != 44) {                     //Is this a delimiter character?
      tmpBuf[j++] = buf[i];                 //No, copy the character into the result
    } else {
      intArray[intArrayPtr++] = atoi(tmpBuf);   //Save the numeric result in the values array
      j = 0;                                //clear the result array.
      memset(tmpBuf, 0, sizeof(tmpBuf));
    }
  }
  intArray[intArrayPtr] = atoi(tmpBuf);         //Save the last numeric result in the values array
}
