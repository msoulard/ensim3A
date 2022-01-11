<!DOCTYPE html>
<html>
    <head>
        <meta charset="UTF-8">
        <title></title>
        <link href="styleDescriptionJeux.css" rel="stylesheet" type="text/css"/>
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
            <img src="icons8-chercher-24.png" class="imageRecherche" id="imageRecherche">
	</div>	
        <div class="corps" id="corps">
            <h2 class="titre" id="titre"></h2>
        </div>
	<footer class="piedDePage" id="piedDePage">
            <p class="textAdresse" id="textAdresse">Adresse : <br> <?php obtenirAdresseLudotheque();?></p>
            <p class="textContact" id="textContact">Nous contacter : <br> <?php obtenirNumTelLudotheque();?> <br> <?php obtenirAdresseMailLudotheque();?></p>
	</footer>
    </body>
</html>
