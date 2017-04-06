var express = require('express');
var app = express();
var bodyParser = require('body-parser');
var config = require('./config/config');
var port = config.port;

app.use(bodyParser.urlencoded({
	extended :true
}));
app.use(bodyParser.json());

var mongoose = require('mongoose');
mongoose.connect('mongodb://localhost:27017/statusDB');
console.log("Connected to DB");

app.use('/update', require('./routers/updateStatusRouter'));
app.use('/getStatus', require('./routers/getStatusRouter'));

app.listen(port, function(err){
	if(err)
		console.log("nope");
	console.log("Listening");
})