<!doctype html>
<html lang="fr">
	<head>
		<meta charset="UTF-8">
		<title>Ludothèque du Mans</title>
		<link rel="stylesheet" href="pageAccueil.css"/>
		<script src="changerPage.js"></script>		
	</head>
	<body>
		<?php include('accesBdd.php');?>
		<div id="menu">
			<h1 id="nomLudotheque">Ludothèque du Mans</h1>
			<button class="boutonsMenu" id="buttonAccueil" onclick="ouvrirAccueil()">Accueil</button>
			<button class="boutonsMenu" id="buttonJeux" onclick="ouvrirJeux()">Nos Jeux</button>
			<button class="boutonsMenu" id="buttonCompte">Mon compte</button>
			<input type="text" id="recherche" value="Recherche">
			<img src="icons8-chercher-24.png" id="imageRecherche">
		</div>	
		<h2 id="titre">Bienvenue à la Ludothèque du Mans</h2>	
		<p id="description">bonjour</p>
		<footer>
			<div id="piedDePage">
				<text id="adresse">Adresse :</text>
				<text id="contact">Nous contacter :</text>
			</div>
		</footer>		
	</body>
</html>