<?php
    function obtenirNomLudotheque(){
	include('connexionBdd.php');
	$Query = "SELECT nom FROM Ludotheque WHERE idLudotheque=1";
	$Result = $Connect->query($Query);
	while($Data = mysqli_fetch_array($Result)){
            echo utf8_decode($Data[0]);
	}
	mysqli_close ($Connect);
    }
	
    function obtenirDescriptionLudotheque(){
	include('connexionBdd.php');
	$Query = "SELECT description FROM Ludotheque WHERE idLudotheque=1";
	$Result = $Connect->query($Query);
	while($Data = mysqli_fetch_array($Result)){
            echo utf8_decode($Data[0]);
	}
	mysqli_close ($Connect);
    }
    
    function obtenirAdresseLudotheque(){
	include('connexionBdd.php');
	$Query = "SELECT adresse FROM Ludotheque WHERE idLudotheque=1";
	$Result = $Connect->query($Query);
	while($Data = mysqli_fetch_array($Result)){
            echo utf8_decode($Data[0]);
	}
	mysqli_close ($Connect); 
    }
	
    function obtenirNumTelLudotheque(){
	include('connexionBdd.php');
        $Query = "SELECT numTel FROM Ludotheque WHERE idLudotheque=1";
	$Result = $Connect->query($Query);
	while($Data = mysqli_fetch_array($Result)){
            echo utf8_decode($Data[0]);
	}
        mysqli_close ($Connect); 
    }
	
    function obtenirAdresseMailLudotheque(){
    	include('connexionBdd.php');
	$Query = "SELECT adresseMail FROM Ludotheque WHERE idLudotheque=1";
	$Result = $Connect->query($Query);
	while($Data = mysqli_fetch_array($Result)){
		echo utf8_decode($Data[0]);
	}
	mysqli_close ($Connect); 
    }

    function obtenirImageJeux($id){
	include('connexionBdd.php');
	$Query = "SELECT cheminImage FROM ImageJeux WHERE idJeux=$id";
	$Result = $Connect->query($Query);
	$Data = mysqli_fetch_array($Result);
	mysqli_close ($Connect); 
	echo utf8_encode($Data[0]);
	return utf8_encode($Data[0]);		
    }
    
    function obtenirNomJeux($id){
        include('connexionBdd.php');
	$Query = "SELECT nom FROM Jeux WHERE idJeux=$id";
	$Result = $Connect->query($Query);
	$Data = mysqli_fetch_array($Result);
	mysqli_close ($Connect);
	return utf8_decode($Data[0]);
    }
    
    /*function compteConnexion(){
        include('connexionBdd.php');
        $identifiant=filter_input(INPUT_POST,'id');
        $mdp=filter_input(INPUT_POST,'motdp');
        $Query = "SELECT identifiant, motDePasse FROM adherent AND administrateur WHERE identifiant=$identifiant and motDePasse=$mdp";
        $Result = $Connect->query($Query);
        $Data = mysqli_fetch_array($Result);        
        mysqli_close ($Connect);
        
        if($Result == true)
            echo "<script>console.log('vous etes connecté !');</script>";
        else
            echo "Erreur d'identifiant ! ";
            
              
        
    }*/
?>

