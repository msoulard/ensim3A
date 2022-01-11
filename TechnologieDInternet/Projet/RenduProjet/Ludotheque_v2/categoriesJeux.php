<!DOCTYPE html>
<html>
    <head>
        <meta charset="UTF-8">
        <title>Ludothèque Le Mans</title>
        <link href="styleCategoriesJeux.css" rel="stylesheet" type="text/css"/>
        <script src="changerPage.js" type="text/javascript"></script>
    </head>
    <body>
        <?php include('accesBdd.php');?>
        <div class="menu" id="menu">
            <h1 class="nomLudotheque" id="nomLudotheque">Ludothèque du Mans</h1>
            <button class="buttonAccueil" id="buttonAccueil" onclick="ouvrirAccueil()">Accueil</button>
            <button class="buttonJeux" id="buttonJeux" onclick="ouvrirCategoriesJeux()">Nos Jeux</button>
            <button class="buttonCompte" id="buttonCompte" onclick="ouvrirCompteConnexion()">Mon compte</button>
            <input type="text" class="recherche" id="recherche" value="Recherche">
            <img src="icons8-chercher-24.png"class="imageRecherche" id="imageRecherche">
	</div>	
        <div class="corps" id="corps">
            <h2 class="titre" id="titre">Nos jeux par catégories</h2>
		<ul class="listeCategories" id="liAge">
			<li>Selon l'âge</li>		
			<button class="categoriesJeux" id="buttonBambin">Bambin</button>
                        <button class="categoriesJeux" id="buttonEnfant" onclick="ouvrirJeuxEnfant();">Enfant</button>
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
		<button class="categoriesJeux" id="buttonTousLesJeux" onclick="ouvrirTousLesJeux();">Tous les jeux</button>
        </div>
	<footer class="piedDePage" id="piedDePage">
            <p class="textAdresse" id="textAdresse">Adresse : <br> <?php obtenirAdresseLudotheque();?></p>
            <p class="textContact" id="textContact">Nous contacter : <br> <?php obtenirNumTelLudotheque();?> <br> <?php obtenirAdresseMailLudotheque();?></p>
	</footer>
    </body>
</html>
