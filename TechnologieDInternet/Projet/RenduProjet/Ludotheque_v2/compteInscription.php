<!DOCTYPE html>
<html>
    <head>
        <meta charset="UTF-8">
        <title>Ludothèque Le Mans</title>
        <link href="styleCompteInscription.css" rel="stylesheet" type="text/css"/>
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
            <h2 class="titre" id="titre">Inscription</h2>
            <p class="pNom" id="pNom">Nom</p>
            <input type="text" class="inputNom" id="inputNom">
            <p class="pPrenom" id="pPrenom">Prénom</p>
            <input type="text" class="inputPrenom" id="inputPrenom">
            <p class="pDateNaissance" id="pDateNaissance">Date de naissance</p>
            <input type="text" class="inputDateNaissance" id="inputDateNaissance">
            <p class="pAdresseMail" id="pAdresseMail">Adresse mail</p>
            <input type="text" class="inputAdresseMail" id="inputAdresseMail">
            <p class="pTelephone" id="pTelephone">Téléphone</p>
            <input type="text" class="inputTelephone" id="inputTelephone">
            <p class="pAdresse" id="pAdresse">Adresse</p>
            <input type="text" class="inputAdresse" id="inputAdresse">
            <p class="pMotDePasse" id="pMotDePasse">Mot de passe</p>
            <input type="password" class="inputMotDePasse" id="inputMotDePasse">
            <button class="buttonInscription" id="buttonInscription">Inscription</button>
            <p class="pQuestion" id="pQuestion">Un compte ?</p>
            <p class="pConnexion" id="pConnexion" onclick="ouvrirCompteConnexion();">Connectez-vous</p>
        </div>
        <footer class="piedDePage" id="piedDePage">
            <p class="textAdresse" id="textAdresse">Adresse : <br> <?php obtenirAdresseLudotheque();?></p>
            <p class="textContact" id="textContact">Nous contacter : <br> <?php obtenirNumTelLudotheque();?> <br> <?php obtenirAdresseMailLudotheque();?></p>
	</footer>
    </body>
</html>
