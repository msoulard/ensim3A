<!DOCTYPE html>
<html>
    <head>
        <meta charset="UTF-8">
        <title>Ludothèque du Mans</title>
        <link href="styleJeuxEnfant.css" rel="stylesheet" type="text/css"/>
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
            <h2 class="titre" id="titre">Jeux pour enfant</h2>
            <div class='imagesJeux' id='imagesJeux'>
                <?php include('connexionBdd.php');
                $Query = "SELECT idJeux FROM Jeux WHERE age='Enfant'";
                $Result = $Connect->query($Query);
                $Data = mysqli_fetch_array($Result);
                while($Data = mysqli_fetch_array($Result)){
                $Query2 = "SELECT cheminImage FROM ImageJeux WHERE idJeux=$Data[idJeux]";
                $Result2 = $Connect->query($Query2);            
                    while($Data2 = mysqli_fetch_array($Result2)){
                        echo "<img src='".$Data2['cheminImage']."' class='imageJeux' id='imageJeux'>";
                    }
                }
                mysqli_close ($Connect);
                ?>
            </div>
        </div>
	<footer class="piedDePage" id="piedDePage">
            <p class="textAdresse" id="textAdresse">Adresse : <br> <?php obtenirAdresseLudotheque();?></p>
            <p class="textContact" id="textContact">Nous contacter : <br> <?php obtenirNumTelLudotheque();?> <br> <?php obtenirAdresseMailLudotheque();?></p>
	</footer>
    </body>
</html>
