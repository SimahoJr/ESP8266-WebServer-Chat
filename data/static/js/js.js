
var wsUri = 'ws://' + document.domain + ':8080';
websocket = new WebSocket(wsUri); 
var output;
var messages;
var out_message;
var rand_id = 0;

// Load JS First
window.addEventListener("load", init, true);

function init(){
    // for writeToScreen OUTPUT
    output = document.getElementById("status");
    messages = document.getElementById('messages');
    // websocket functions
    websocket.onopen = function(evt) { onOpen(evt.data) };
    websocket.onclose = function(evt) { onClose(evt.data) };
    websocket.onmessage = function(evt) { onMessage(evt.data) };
    websocket.onerror = function(evt) { onError(evt.data) };
    console.log("ESP8266 Document Ready Loaded");
};

// Functions
function onOpen(msg)  {
    msg = "You have Joined the Chat";

    // Give Special ID (Not So Special ID)
    msg = setID(msg)

    getMessages(msg, "both");
    ws_send(msg);
    console.log("onOpen: " + msg);
}

function onClose(msg)  {
    msg = "You left the chat";

    // Give Special ID (Not So Special ID)
    msg = setID(msg)

    getMessages(msg, "both");
    ws_send(msg);
    console.log("onClose: " + msg)
}

function onMessage(msg)  {
    msg = setID(msg)
    getMessages(msg, "in");
    console.log("onMessage: " + msg);
}

function onError(msg)  {

    // Give Special ID (Not So Special ID)
    msg = setID(msg)

    msg = msg + "Connection Error" ;
    getMessages(msg, "both");
    ws_send(msg);
    console.log("onError: " + msg)
}


// SubFunctions
function ws_send(message)  {
    websocket.send(message);
}

function incomingMessage(input_message){
    // separate_id_msg(input_message) return [my_id, my_msg];
    msg = separate_id_msg(input_message)

    // check if it was the broadcast message
    if(out_message === input_message) return;

    var para = document.createElement("P");
    para.id = "para_incoming"                
    para.style.position = "relative";
    para.style.width = "50%";
    para.style.textAlign = "left";
    para.style.left = "0%";
    para.style.background = "DarkSlateGray";
    para.style.padding = "10px 2px 4px 6px";

    var para1 = document.createElement("H2");
    para1.innerHTML = msg[0]; 
    
    var para2 = document.createElement("P");               
    para2.innerHTML = msg[1]; 

    para.appendChild(para1);
    para.appendChild(para2);
    
    messages.appendChild(para);

}

function outgoingMessage(input_message){
    // separate_id_msg(input_message) return [my_id, my_msg];
    msg = separate_id_msg(input_message)

    var para = document.createElement("P");
    para.id = "para_outgoing"                
    para.style.position = "relative";
    para.style.width = "50%";
    para.style.left = "40%";
    para.style.background = "MidnightBlue";
    para.style.padding = "10px 2px 4px 6px";
    para.style.textAlign = "right";

    var para1 = document.createElement("H2");
    para1.innerHTML = msg[0]; 
    
    var para2 = document.createElement("P");               
    para2.innerHTML = msg[1]; 


    para.appendChild(para1);
    para.appendChild(para2);
    
    messages.appendChild(para);

    // Send message out
    out_message = input_message;
    ws_send(input_message);
}

function statusMessage(input_message){
    // separate_id_msg(input_message) return [my_id, my_msg];
    msg = separate_id_msg(input_message)

    var para = document.createElement("P");
    para.id = "para_status"                
    para.style.position = "relative";
    para.style.width = "90%";
    para.style.textAlign = "center";
    para.style.left = "0%";
    para.style.background = "Maroon";
    para.style.padding = "10px 2px 4px 6px";

    var para1 = document.createElement("H2");
    para1.innerHTML = msg[0]; 
    
    var para2 = document.createElement("P");               
    para2.innerHTML = msg[1]; 

    para.appendChild(para1);
    para.appendChild(para2);
    
    messages.appendChild(para);

    // Send message out
    out_message = input_message;
    ws_send(input_message);
}

function getMessages(msg, where) {
	// Prior to getting your messages.
    shouldScroll = messages.scrollTop + messages.clientHeight === messages.scrollHeight;
    /*
    * Get your messages, we'll just simulate it by appending a new one syncronously.
    */

    // Check where we came from and append message 
    if(where=="in") incomingMessage(msg);
    if(where=="out") outgoingMessage(msg);
    if(where=="both") statusMessage(msg);

    // After getting your messages.
    if (!shouldScroll) {
    scrollToBottom();
    }
}

function scrollToBottom() {
    messages.scrollTop = messages.scrollHeight;
}

function submitChat(){
    // difference between form and input???
    var msg;

    // Get the value of the input field with id="input_message"
    msg = document.getElementById("input_message").value;

    // Give Special ID (Not So Special ID)
    msg = setID(msg)

    // Send message to a Server and Display
    getMessages(msg, "out")
    // ws_send(msg);

    console.log("Chat Message: " + msg);
    console.log(msg);

    // clearTextInput
    document.getElementById("input_message").value = "";
}

function separate_id_msg(msg){
    // We are sure we have an ID now
    var my_id = "";
    var my_msg = "";

    my_id = msg.substring(msg.indexOf("id"), a = msg.indexOf(" "))
    // the "id: " is a bug will give empty ID
    if(my_id==="") my_id = msg.substring(2, a = msg.indexOf(" "))
    if(my_id.includes("id:")) my_id = my_id.replace("id:", " ");
    if(my_id.includes("id = ")) my_id = my_id.replace("id = ", " ");
    if(my_id.includes("id: ")) my_id = my_id.replace("id: ", " ");
    if(my_id.includes("id :")) my_id = my_id.replace("id :", " ");
    if(my_id.includes("id=")) my_id = my_id.replace("id=", " ");

    my_msg = msg.substring(a);

    console.log([my_id, my_msg]);
    return [my_id, my_msg];  
}


function setID(msg){
    // Set id only if it is not there.
    if(msg.includes("id=")||msg.includes("id:")||msg.includes("id =")||msg.includes("id :")){
        console.log(msg);
        return msg;
    }
    else{
        if(rand_id===0) {
            rand_id = Math.floor((Math.random() * 100) + 1);
            msg = "id:User_" + rand_id + " " + msg;
            console.log(msg);
            return msg;
        }
        else{
            msg = "id:User_" + rand_id + " " + msg;
            console.log(msg);
            return msg; 
        }
    }
      
}

