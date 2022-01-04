<?php
	function obtenirDescriptionLudotheque(){
		include('connectionBdd.php');
		$Query = "SELECT description FROM Ludotheque WHERE idLudotheque=1";
		$Result = $Connect->query($Query);
		while($Data = mysqli_fetch_array($Result)){
			echo utf8_encode($Data[0]);
		}
		mysqli_close ($Connect);
	}
	function obtenirAdresseLudotheque(){
		include('connectionBdd.php');
		$Query = "SELECT adresse FROM Ludotheque WHERE idLudotheque=1";
		$Result = $Connect->query($Query);
		while($Data = mysqli_fetch_array($Result)){
			echo utf8_encode($Data[0]);
		}
		mysqli_close ($Connect); 
	}
	
	function obtenirNumTelLudotheque(){
		include('connectionBdd.php');
		$Query = "SELECT numTel FROM Ludotheque WHERE idLudotheque=1";
		$Result = $Connect->query($Query);
		while($Data = mysqli_fetch_array($Result)){
			echo utf8_encode($Data[0]);
		}
		mysqli_close ($Connect); 
	}
	
	function obtenirAdresseMailLudotheque(){
		include('connectionBdd.php');
		$Query = "SELECT adresseMail FROM Ludotheque WHERE idLudotheque=1";
		$Result = $Connect->query($Query);
		while($Data = mysqli_fetch_array($Result)){
			echo utf8_encode($Data[0]);
		}
		mysqli_close ($Connect); 
	}
	
	function obtenirImageJeux($id){
		include('connectionBdd.php');
		$Query = "SELECT cheminImage FROM ImageJeux WHERE idJeux=$id";
		$Result = $Connect->query($Query);
		$Data = mysqli_fetch_array($Result);
		mysqli_close ($Connect); 
		echo utf8_encode($Data[0]);
		return utf8_encode($Data[0]);		
	}
?>