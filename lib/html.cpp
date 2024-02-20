#include <html.h>
void handleRootPath(){

    String html ="<html><head><meta charset=\"UTF-8\"><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\"><style>";
    html +="body { font-family: Arial, sans-serif; background-color:#9dc8e7; } ";
    html +="input[type=text] {width: 100%; padding: 12px 20px; margin: 8px 0; display: inline-block; border: 1px solid #ccc; border-radius: 4px; box-sizing: border-box; }";
    html +="button { width: 100%; background-color: #4CAF50; color: white; padding: 14px 20px; margin: 8px 0;border: none; border-radius: 4px; cursor: pointer; }" ;
    html +="</style></head><body>";

    html +="<h1> ДАПРОС </h1>";
    html +="</br>";

    html +="<form action=\"/submit\" method=\"get\">";
    html +="Surname<input type=\"text\" name=\"surname\"><br>";
    html +="Name:<input type=\"text\" name=\"name\"><br>";
    html +="Email: <input type=\"text\" name=\"email\"><br>";
    html +="Date of Birth: <input type=\"date\", name = \"data\"><br>";
    html +="<button type=\"submit\" value=\"Submit\">Send</button>";
    html +="</form> ";
    html +="<form action=\"/show\" method=\"get\">";
    html +="<button>Show Data</button>";
    html +="</form>";
    html +="</body></html>";

    server.send(200,"text/html",html);
}