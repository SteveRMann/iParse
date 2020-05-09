# iParse
Function to parse integers from a char array (c-string).

---------------
Why did I write this instead of using strtok()?
The strtok() function cannot properly handle blank data.
If the input data is, for example, '12,,14', strok() returns 12 and 14.
(If you are running it on an ESP processor, it will crash).
iParse would return 12,0, and 14 in this example.

* This has only been tested on an Wemos D1 Mini (ESP8266).
