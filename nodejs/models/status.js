var mongoose = require('mongoose');
var Schema = mongoose.Schema;

var statusSchema = new Schema({
	cartID: String,
	status: String
});

module.exports = mongoose.model('Status', statusSchema);