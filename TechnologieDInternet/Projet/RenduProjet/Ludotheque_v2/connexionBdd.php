<?php
    $server = "127.0.0.1";
    $user="root";
    $pwd="";
    $db="e2103704";
    $Connect = mysqli_connect($server, $user, $pwd, $db); 
    if(!$Connect){
	echo "Connexion à la base de données impossible";
    }
?>

