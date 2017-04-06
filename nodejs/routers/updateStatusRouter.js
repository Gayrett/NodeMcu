var express = require('express');
var router = express.Router();
var stc = require('../controllers/statusController.js');
var _ = require('lodash');

router.post('/', function(req, res){
	var cartID = req.body.cartID;
	var status = req.body.status;
	stc.updateStatus(cartID, status)
		.then(function(result){
			res.json({result : result});
		})
		.catch(function(err){
			res.json(err);
		});
});

module.exports = router;