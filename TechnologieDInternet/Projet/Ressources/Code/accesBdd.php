<?php
	$serveur = "http://e-srv-lamp/phpmyadmin/";
	$user="e2103704";
	$mdp="Eck114mt";
	$db="e2103704";
	$Connect = mysqli_connect($server, $user, $mdp, $db); 
	if(!$Connect){
		echo "Connexion à la base de données impossible";
	}
	else{
		echo "Connexion à la base de données réussie";
	}
	function obtenirDescriptionLudotheque(){
		$Query = "SELECT description FROM Ludotheque WHERE idLudotheque=1";
		$Result = $Connect->query($Query);
		$description = mysqli_fetch_array(result);
		echo $description;
		return $description;
	}
?>