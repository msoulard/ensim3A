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
		<div class="menu" id="menu">
			<h1 class="nomLudotheque" id="nomLudotheque">Ludothèque du Mans</h1>
			<button class="buttonAccueil" id="buttonAccueil" onclick="ouvrirAccueil()">Accueil</button>
			<button class="buttonJeux" id="buttonJeux" onclick="ouvrirJeux()">Nos Jeux</button>
			<button class="buttonCompte" id="buttonCompte">Mon compte</button>
			<input type="text" class="recherche" id="recherche" value="Recherche">
			<img src="icons8-chercher-24.png"class="imageRecherche" id="imageRecherche">
		</div>	
		<h2 class="titre" id="titre">Bienvenue à la Ludothèque du Mans</h2>	
		<div><p class="pDexcription" id="description"><?php obtenirDescriptionLudotheque();?></p></div>
		<div><img src="<?php obtenirImageJeux(1)?>" class="imageJeux"></div>
		<footer>
			<div class="piedDePage" id="piedDePage">
				<text class="textAdresse" id="textAdresse">Adresse : <br> <?php obtenirAdresseLudotheque();?></text>
				<text class="textContact" id="textContact">Nous contacter : <br> <?php obtenirNumTelLudotheque();?> <br> <?php obtenirAdresseMailLudotheque();?></text>
			</div>
		</footer>		
	</body>
</html>