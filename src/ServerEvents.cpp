#include <ServerEvents.h>

ESP8266WebServer server(SERVER_PORT);

void ServerEventsBegin(){
  server.on("/", handleIndex);
  server.on("/api", handleAPI);
  server.on("/esp", handleESP);
  server.on("/static/css/styles.css", handleCSS);
  server.on("/static/js/js.js", handleJS);
  server.on("/static/js/jquery-1.10.2.min.js", handleMinJS);
  server.on("/static/img/logo.png", handleLOGO);
  server.onNotFound(handleNotFound);
  server.begin();
}

void ServerEventsLoop(){
  server.handleClient();
}

void LittleFS_testing(){
  little_begin();
  little_listDir("/static/img");
  little_listDir("/static/css");
  little_listDir("/static/js");
  little_listDir("/templates");
}

// Handles
void handleNotFound()
{
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i = 0; i<server.args(); i++){
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", message);
}

void handleESP()
{
  server.send_P(200, "text/html", "API Ready");
}

void handleAPI()
{
  server.send_P(200, "text/html", "API Connected");
}


// MIME IMPORTANT
// String getContentType(String filename) { // convert the file extension to the MIME type
//   if (filename.endsWith(".html")) return "text/html";
//   else if (filename.endsWith(".css")) return "text/css";
//   else if (filename.endsWith(".js")) return "application/javascript";
//   else if (filename.endsWith(".ico")) return "image/x-icon";
//   else if (filename.endsWith(".gz")) return "application/x-gzip";
//   return "text/plain";
// }

void handleIndex()
{   
    String index  = little_readFile("/templates/index.html");
    server.send(200, "text/html", index);
}

void handleChat()
{   
    String chat  = little_readFile("/templates/chat.html");
    server.send(200, "text/html", chat);
}

void handleCSS()
{
  String css  = little_readFile("/static/css/styles.css");
  server.send(200, "text/css", css);
}

void handleJS()
{
  String js  = little_readFile("/static/js/js.js");
  server.send(200, "application/javascript", js);
}

void handleMinJS()
{
  String js  = little_readFile("/static/js/jquery-1.10.2.min.js");
  server.send(200, "application/javascript", js);
}

void handleLOGO()
{
  String img  = little_readFile("/static/img/logo.png");
  // Check MIME
  server.send(200, "text/img", img);

}