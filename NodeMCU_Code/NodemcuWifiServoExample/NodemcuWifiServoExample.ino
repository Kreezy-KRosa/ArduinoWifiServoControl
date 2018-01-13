//Wifi Arduino Servo Control with NodeMCU Example Code
//by Kreezy(KRosa) 1.12.2018

//Example Video can be found @ https://youtu.be/q4Ya8fxmjBw

//Upload this to your ESP8266 NodeMCU

#include <ESP8266WiFi.h>                // include esp8266wifi library 
 
const char* ssid = "SSID";             // enter your wifi's ssid name inside the ""'s

const char* password = "PASSWORD";     // enter your wifi's password inside the ""'s
 

WiFiServer server(80);                // wifi server setup
 
void setup() {
  Serial.begin(115200);               // serial connection for debugging
  delay(10);
  pinMode(5, OUTPUT);                 // pins used to turn devices on/off are set to outputs here
  pinMode(4, OUTPUT);
  pinMode(0, OUTPUT);
  pinMode(13, OUTPUT);
  digitalWrite(5, LOW);               // turns all buttons to a default off state
  digitalWrite(4, LOW);
  digitalWrite(0, LOW);
  digitalWrite(13, LOW);
 
                                      // Connects to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
 
                                      // Starts the server
  server.begin();
  Serial.println("Server started");
 
                                      // Prints the IP address. Use serial monitor to double check the server ip
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
 
}
 
void loop() {
                                       // Checks if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
 
                                       // Waits until the client sends some data
  Serial.println("new client");
  while(!client.available()){
    delay(1);
  }
 
                                        // Reads the first line of the request
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();
 
                                       // Matches the request
 
 
  if (request.indexOf("/light1on") > 0)  {
    digitalWrite(5, HIGH);
   
  }
  if (request.indexOf("/light1off") >0)  {
    digitalWrite(5, LOW);
   
  }

   if (request.indexOf("/light2on") > 0)  {
    digitalWrite(4, HIGH);
   
  }
  if (request.indexOf("/light2off") >0)  { 
    digitalWrite(4, LOW);                         // Set ledPin according to the request
                                                  //digitalWrite(ledPin, value);
  }
    if (request.indexOf("/light3on") >0)  {
    digitalWrite(0, HIGH);
   
  }
  if (request.indexOf("/light3off") > 0)  {
    digitalWrite(0, LOW);
   
  }
   if (request.indexOf("/light4on") > 0)  {
    digitalWrite(13, HIGH);
   
  }
  if (request.indexOf("/light4off") > 0)  {
    digitalWrite(13, LOW);
   
  }
                              
 
                                        // Return the response
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); //  do not forget this one
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.println("<head>");
  client.println("<meta name='apple-mobile-web-app-capable' content='yes' />");
  client.println("<meta name='apple-mobile-web-app-status-bar-style' content='black-translucent' />");
 client.println("</head>");
  client.println("<body bgcolor = \"#f7e6ec\">"); 
  client.println("<hr/><hr>");
  client.println("<h4><center> Kreezy's Wifi Servo Dashboard </center></h4>");
  client.println("<hr/><hr>");
  client.println("<br><br>");
  client.println("<br><br>");
  client.println("<center>");
  client.println("Device 1");
  client.println("<a href=\"/light1on\"\"><button>Turn On </button></a>");
  client.println("<a href=\"/light1off\"\"><button>Turn Off </button></a><br />");  
  client.println("</center>");   
  client.println("<br><br>");
   client.println("<center>");
   client.println("Device 2");
  client.println("<a href=\"/light2on\"\"><button>Turn On </button></a>");
  client.println("<a href=\"/light2off\"\"><button>Turn Off </button></a><br />");  
client.println("</center>"); 
  client.println("<br><br>");
    client.println("<center>");
   client.println("Device 3");
  client.println("<a href=\"/light3on\"\"><button>Turn On </button></a>");
  client.println("<a href=\"/light3off\"\"><button>Turn Off </button></a><br />");  
client.println("</center>"); 
  client.println("<br><br>");
   client.println("<center>");
   client.println("Device 4");
  client.println("<a href=\"/light4on\"\"><button>Turn On </button></a>");
  client.println("<a href=\"/light4off\"\"><button>Turn Off </button></a><br />");  
client.println("</center>"); 
  client.println("<br><br>");
  client.println("<center>");
  client.println("<table border=\"5\">");
 client.println("<tr>");
  if (digitalRead(5))
         { 
           client.print("<td>180 Degs is ON</td>");
        
         }
          else
          {
            client.print("<td>180 Degs is OFF</td>");
      
        }
     
        client.println("<br />");
             
         if (digitalRead(4))
          { 
           client.print("<td>Light 2 is ON</td>");

         }
          else
          {

            client.print("<td>Light 2 is OFF</td>");

          }
          client.println("</tr>");


          client.println("<tr>");

          if (digitalRead(0))

          { 
           client.print("<td>Light 3 is ON</td>");

          }

          else

          {
            client.print("<td>Light 3 is OFF</td>");
          }


          if (digitalRead(13))


          { 


           client.print("<td>Light 4 is ON</td>");

          }


          else


          {


            client.print("<td>Light 4 is OFF</td>");


          }

          client.println("</tr>");


          client.println("</table>");

          client.println("</center>");
  client.println("</html>"); 
  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");
 
}
