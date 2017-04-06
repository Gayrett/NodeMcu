var express = require('express');
var router = express.Router();
var stc = require('../controllers/statusController.js');
var _ = require('lodash');

router.post('/', function(req, res){
	var cartID = req.body.cartID;
	stc.getStatus(cartID)
		.then(function(result){
			if(!(_.isEmpty(result))){
				res.json({result: result});
			} else{
				res.json({result: "error"});
			}
		})
		.catch(function(err){
			console.log(err);
		});
});

module.exports = router;