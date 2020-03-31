function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "PotTest"};
	this.sidHashMap["PotTest"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<S1>"] = {sid: "PotTest:9"};
	this.sidHashMap["PotTest:9"] = {rtwname: "<S1>"};
	this.rtwnameHashMap["<Root>/Analog Input"] = {sid: "PotTest:1"};
	this.sidHashMap["PotTest:1"] = {rtwname: "<Root>/Analog Input"};
	this.rtwnameHashMap["<Root>/Display"] = {sid: "PotTest:5"};
	this.sidHashMap["PotTest:5"] = {rtwname: "<Root>/Display"};
	this.rtwnameHashMap["<Root>/Display1"] = {sid: "PotTest:10"};
	this.sidHashMap["PotTest:10"] = {rtwname: "<Root>/Display1"};
	this.rtwnameHashMap["<Root>/Display2"] = {sid: "PotTest:15"};
	this.sidHashMap["PotTest:15"] = {rtwname: "<Root>/Display2"};
	this.rtwnameHashMap["<Root>/Gain"] = {sid: "PotTest:14"};
	this.sidHashMap["PotTest:14"] = {rtwname: "<Root>/Gain"};
	this.rtwnameHashMap["<Root>/MATLAB Function"] = {sid: "PotTest:9"};
	this.sidHashMap["PotTest:9"] = {rtwname: "<Root>/MATLAB Function"};
	this.rtwnameHashMap["<Root>/Scope"] = {sid: "PotTest:4"};
	this.sidHashMap["PotTest:4"] = {rtwname: "<Root>/Scope"};
	this.rtwnameHashMap["<S1>:1"] = {sid: "PotTest:9:1"};
	this.sidHashMap["PotTest:9:1"] = {rtwname: "<S1>:1"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();
