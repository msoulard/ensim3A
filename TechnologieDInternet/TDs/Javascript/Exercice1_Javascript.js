function convertirEuroDollar(){
	var euro = document.getElementById("textEuro");
	var dollar = euro*1.12;
	alert("dollar :"+dollar);
	return dollar;
}

function afficherConversion(){
	var dollar = convertirEuroDollar();
	alert("dollar :"+dollar);
	document.getElementById("textDollar").innerHTML = dollar;
}