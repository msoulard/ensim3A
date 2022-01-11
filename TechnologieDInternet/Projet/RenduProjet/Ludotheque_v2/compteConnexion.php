<!DOCTYPE html>
<html>
    <head>
        <meta charset="UTF-8">
        <title>Ludothèque du Mans</title>
        <link href="styleCompteConnexion.css" rel="stylesheet" type="text/css"/>
        <script src="changerPage.js" type="text/javascript"></script>
    </head>
    <body>
        <?php include('accesBdd.php'); ?>
        <div class="menu" id="menu">
            <h1 class="nomLudotheque" id="nomLudotheque">Ludothèque du Mans</h1>
            <button class="buttonAccueil" id="buttonAccueil" onclick="ouvrirAccueil()">Accueil</button>
            <button class="buttonJeux" id="buttonJeux" onclick="ouvrirCategoriesJeux()">Nos Jeux</button>
            <button class="buttonCompte" id="buttonCompte" onclick="ouvrirCompteConnexion()">Mon compte</button>
            <input type="text" class="recherche" id="recherche" value="Recherche">
            <img src="icons8-chercher-24.png" class="imageRecherche" id="imageRecherche">
        </div>
        <div class="corps" id="corps">
            <h2 class="titre" id="titre">Connexion</h2>
            <?php
                include ('connexionBdd.php');
                session_start();
            
                if(isset($_POST['submit'])){
                    $username = stripslashes($_REQUEST['identifiant']);
                    $username = mysqli_real_escape_string($Connect, $username);
                    $pwd = stripslashes($_REQUEST['mdp']);
                    $pwd = mysqli_real_escape_string($Connect, $pwd);
                    $id = stripslashes($_REQUEST['idAdherent']);
                    $id = mysqli_real_escape_string($Connect, $id);
                
                    $Query = "select * from adherent";
                    $Result = $Connect->query($Query);
                    $verif = false;
                    while($Data = mysqli_fetch_array($Result) && $verif != true){
                        if(($Data['idAdherent'] == $id) && ($Data['identifiant'] == $username) && ($Data['motDePasse'] == $pwd)){
                            $verif = true;
                        }
                    }
                    if($verif == true){
                        $_SESSION['idAdherent'] = $id;
                        header("Location:categoriesJeux.php");
                        echo "Vous êtes connecté";
                    }
                    else{
                        echo "Identifiant ou mot de passe incorect";
                    }
                    mysqli_close ($Connect);
                }
            ?>
            <form method="post" name="login">
                <p class="pNumCarte" id="pNumCarte">Numéro de carte</p>
                <input type="text" name="idAdherent" class="inputNumCarte" id="inputNumCarte">
                <p class="pIdentifiant" id="pIdentifiant">Identifiant</p>
                <input type="text" name="identifiant" class="inputIdentifiant" name="id">
                <p class="pMotDePasse" id="pMotDePasse">Mot de passe</p>
                <input type="password" name="mdp" class="inputMotDePasse" id="inputMotDePasse" name="motdp">
                <input type="submit" name="submit" class="buttonConnexion" id="buttonConnexion" value="Connexion">
            </form>
            <p class="pQuestion" id="pQuestion">Pas de compte ?</p>
            <p class="pInscription" id="pInscription" onclick="ouvrirCompteInscription();">Inscrivez-vous</p>
        </div>
        <footer class="piedDePage" id="piedDePage">
            <p class="textAdresse" id="textAdresse">Adresse : <br> <?php obtenirAdresseLudotheque(); ?></p>
            <p class="textContact" id="textContact">Nous contacter : <br> <?php obtenirNumTelLudotheque(); ?> <br> <?php obtenirAdresseMailLudotheque(); ?></p>
        </footer>
    </body>
</html>
