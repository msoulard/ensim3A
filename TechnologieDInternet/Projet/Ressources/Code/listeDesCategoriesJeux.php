<!doctype html>
<html lang="fr">
	<head>
		<meta charset="UTF-8">
		<title>Ludothèque du Mans</title>
		<link rel="stylesheet" href="listeDesCategoriesJeux.css"/>
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
		<h2 id="titre">Nos jeux par catégories</h2>
		<ul class="listeCategories" id="liAge">
			<li>Selon l'âge</li>		
			<button class="categoriesJeux" id="buttonBambin">Bambin</button>
			<button class="categoriesJeux" id="buttonEnfant">Enfant</button>
			<button class="categoriesJeux" id="buttonAdolescent">Adolescent</button>
			<button class="categoriesJeux" id="buttonAdulte">Adulte</button>
			<button class="categoriesJeux" id="buttonTouteLaFamille">Toute la famille</button>
		</ul>
		<ul class="listeCategories" id="liActivite">
			<li>Selon l'activité</li>
			<button class="categoriesJeux" id="buttonCalme">Calme</button>
			<button class="categoriesJeux" id="buttonDynamique">Dynamique</button>
		</ul>
		<ul class="listeCategories"  id="liType">
			<li>Selon le type</li>
			<button class="categoriesJeux" id="buttonLudique">Ludique</button>
			<button class="categoriesJeux" id="buttonPlateau">Plateau</button>
			<button class="categoriesJeux" id="buttonCartes">Cartes</button>
			<button class="categoriesJeux" id="buttonCulturel">Culturel</button>
			<button class="categoriesJeux" id="buttonFiction">Fiction</button>
			<button class="categoriesJeux" id="buttonJeuxVideos">JeuxVidéos</button>
		</ul>
		<button class="categoriesJeux" id="buttonTousLesJeux">Tous les jeux</button>
		<footer>
			<div id="piedDePage">
				<text id="adresse">Adresse : <br> <?php obtenirAdresseLudotheque();?></text>
				<text id="contact">Nous contacter : <br> <?php obtenirNumTelLudotheque();?> <br> <?php obtenirAdresseMailLudotheque();?></text>
			</div>
		</footer>		
	</body>
</html>