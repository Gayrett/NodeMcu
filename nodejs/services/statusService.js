var Status = require('../models/status.js');
var _ = require('lodash');
var config = require('../config/config');
var c,s;

module.exports.getStatus = function(cartID){
	c = config.const+cartID;
	return new Promise(function(resolve, reject){
		Status.find({cartID: c})
			.then(function(result){
				resolve(result);
			})
			.catch(function(err){
				reject(err);
			})
	});
};

module.exports.updateStatus = function(cartID, status){
	c = config.const+cartID;
	s = config[status];
	return new Promise(function(resolve, reject){
		if(s) {
			var updateObj = {status: s};
			Status.update({cartID: c}, updateObj)
				.then(function(result){
					if(result.nModified === 1){
						resolve({message: "Updated"});
					} else {
						reject({message: "error while updating"});
					}
				});
		} else {
			reject({message: "error while updating"});
		}
	});
};