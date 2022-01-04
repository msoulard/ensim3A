<?php
	$server = "e-srv-lamp";
	$user="e2103704";
	$pwd="Eck114mt";
	$db="e2103704";
	$Connect = mysqli_connect($server, $user, $pwd, $db); 
	if(!$Connect){
		echo "Connexion à la base de données impossible";
	}
	?>