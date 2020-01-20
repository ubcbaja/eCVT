function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "ArduinoTest"};
	this.sidHashMap["ArduinoTest"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<S1>"] = {sid: "ArduinoTest:1"};
	this.sidHashMap["ArduinoTest:1"] = {rtwname: "<S1>"};
	this.rtwnameHashMap["<Root>/Analog Input"] = {sid: "ArduinoTest:7"};
	this.sidHashMap["ArduinoTest:7"] = {rtwname: "<Root>/Analog Input"};
	this.rtwnameHashMap["<Root>/Digital Output"] = {sid: "ArduinoTest:1"};
	this.sidHashMap["ArduinoTest:1"] = {rtwname: "<Root>/Digital Output"};
	this.rtwnameHashMap["<Root>/Discrete Pulse Generator"] = {sid: "ArduinoTest:2"};
	this.sidHashMap["ArduinoTest:2"] = {rtwname: "<Root>/Discrete Pulse Generator"};
	this.rtwnameHashMap["<Root>/Scope"] = {sid: "ArduinoTest:4"};
	this.sidHashMap["ArduinoTest:4"] = {rtwname: "<Root>/Scope"};
	this.rtwnameHashMap["<Root>/Scope1"] = {sid: "ArduinoTest:8"};
	this.sidHashMap["ArduinoTest:8"] = {rtwname: "<Root>/Scope1"};
	this.rtwnameHashMap["<S1>/In1"] = {sid: "ArduinoTest:1:7"};
	this.sidHashMap["ArduinoTest:1:7"] = {rtwname: "<S1>/In1"};
	this.rtwnameHashMap["<S1>/Data Type Conversion"] = {sid: "ArduinoTest:1:11"};
	this.sidHashMap["ArduinoTest:1:11"] = {rtwname: "<S1>/Data Type Conversion"};
	this.rtwnameHashMap["<S1>/Digital Output"] = {sid: "ArduinoTest:1:12"};
	this.sidHashMap["ArduinoTest:1:12"] = {rtwname: "<S1>/Digital Output"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();
