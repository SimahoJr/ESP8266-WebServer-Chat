#include <templates.h>

// Templates Files
String index_html  = little_readFile("/templates/index.html");
String chat  = little_readFile("/templates/chat.html");

// Static Files
String js  = little_readFile("/static/js/js.js");
String img  = little_readFile("/static/img/logo.png");
String css  = little_readFile("/static/css/chat.css");

String indexHTML(){
    // String script = "src:/static/js/js.js";
    // index_html.replace(script, js);
    USE_SERIAL.println(index_html);
    return index_html;
}