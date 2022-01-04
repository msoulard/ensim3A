-- phpMyAdmin SQL Dump
-- version 5.0.1
-- https://www.phpmyadmin.net/
--
-- Hôte : localhost
-- Généré le : mar. 04 jan. 2022 à 17:10
-- Version du serveur :  10.4.12-MariaDB-log
-- Version de PHP : 7.2.11

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de données : `e2103704`
--
CREATE DATABASE IF NOT EXISTS `e2103704` DEFAULT CHARACTER SET latin1 COLLATE latin1_swedish_ci;
USE `e2103704`;

-- --------------------------------------------------------

--
-- Structure de la table `Adherent`
--

DROP TABLE IF EXISTS `Adherent`;
CREATE TABLE IF NOT EXISTS `Adherent` (
  `idAdherent` int(11) NOT NULL AUTO_INCREMENT,
  `nom` text NOT NULL,
  `prenom` text NOT NULL,
  `identifant` text NOT NULL,
  `motDePasse` text NOT NULL,
  `dateDeNaissance` date NOT NULL,
  `adresse` text NOT NULL,
  `adresseMail` text NOT NULL,
  `numTel` varchar(10) NOT NULL,
  `idLudotheque` int(11) NOT NULL,
  PRIMARY KEY (`idAdherent`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=latin1;

--
-- Déchargement des données de la table `Adherent`
--

INSERT INTO `Adherent` (`idAdherent`, `nom`, `prenom`, `identifant`, `motDePasse`, `dateDeNaissance`, `adresse`, `adresseMail`, `numTel`, `idLudotheque`) VALUES
(1, 'Durand', 'Jean-Pierre', 'jpdurand', '1j2p3d', '1965-05-10', '15 avenue Durand 72000 Le Mans', 'jp.durand@laposte.net', '0665891523', 1);

-- --------------------------------------------------------

--
-- Structure de la table `Administrateur`
--

DROP TABLE IF EXISTS `Administrateur`;
CREATE TABLE IF NOT EXISTS `Administrateur` (
  `idAdmin` int(11) NOT NULL AUTO_INCREMENT,
  `idLudo` int(11) NOT NULL,
  `nom` text CHARACTER SET utf8 NOT NULL,
  `prenom` text CHARACTER SET utf8 NOT NULL,
  `identifiant` text CHARACTER SET utf8 NOT NULL,
  `motDePasse` text CHARACTER SET utf8 NOT NULL,
  `adresseMail` text CHARACTER SET utf8 NOT NULL,
  PRIMARY KEY (`idAdmin`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=latin1;

--
-- Déchargement des données de la table `Administrateur`
--

INSERT INTO `Administrateur` (`idAdmin`, `idLudo`, `nom`, `prenom`, `identifiant`, `motDePasse`, `adresseMail`) VALUES
(1, 1, 'Georges', 'Marie', 'admin', 'ludotheque', 'marie.georges@ludotheque_lemans.com');

-- --------------------------------------------------------

--
-- Structure de la table `HistoriqueJeux`
--

DROP TABLE IF EXISTS `HistoriqueJeux`;
CREATE TABLE IF NOT EXISTS `HistoriqueJeux` (
  `idHistoriqueJeux` int(11) NOT NULL AUTO_INCREMENT,
  `idJeux` int(11) NOT NULL,
  `idAdherent` int(11) NOT NULL,
  PRIMARY KEY (`idHistoriqueJeux`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Structure de la table `ImageJeux`
--

DROP TABLE IF EXISTS `ImageJeux`;
CREATE TABLE IF NOT EXISTS `ImageJeux` (
  `idImage` int(11) NOT NULL AUTO_INCREMENT,
  `idJeux` int(11) NOT NULL,
  `cheminImage` text NOT NULL,
  PRIMARY KEY (`idImage`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=latin1;

--
-- Déchargement des données de la table `ImageJeux`
--

INSERT INTO `ImageJeux` (`idImage`, `idJeux`, `cheminImage`) VALUES
(1, 1, '../Jeux/crazyCups.png'),
(2, 2, '../Jeux/jeu-Mito.png');

-- --------------------------------------------------------

--
-- Structure de la table `Jeux`
--

DROP TABLE IF EXISTS `Jeux`;
CREATE TABLE IF NOT EXISTS `Jeux` (
  `idJeux` int(11) NOT NULL AUTO_INCREMENT,
  `nom` text NOT NULL,
  `description` text NOT NULL,
  `age` int(11) NOT NULL,
  `duree` time NOT NULL,
  `activite` text NOT NULL,
  `type` text NOT NULL,
  `idLudotheque` int(11) NOT NULL,
  `quantite` int(11) NOT NULL,
  PRIMARY KEY (`idJeux`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=latin1;

--
-- Déchargement des données de la table `Jeux`
--

INSERT INTO `Jeux` (`idJeux`, `nom`, `description`, `age`, `duree`, `activite`, `type`, `idLudotheque`, `quantite`) VALUES
(1, 'Crazy Cups', 'Dans Crazy Cups, chaque joueur reçoit cinq gobelets en cinq couleurs. A chaque début de tour, une carte combinant cinq éléments reprenant les mêmes couleurs que les gobelets est révélée. Les joueurs doivent alors aligner ou empiler rapidement leurs gobelets afin de reproduire exactement la même disposition que celle des éléments de la carte. Attention, il est important de bien suivre l’ordre et le sens des couleurs ! Dès qu’un joueur a terminé, il appuie vite sur la sonnette. Le plus rapide à réaliser correctement sa série remporte la carte en jeu et c’est reparti pour un tour. Restez bien attentifs et ne perdez pas de vue votre objectif car pour gagner à Crazy Cups, il faut avoir de la suite dans les gobelets !', 6, '00:15:00', 'Dynamique', 'Ludique', 1, 5),
(2, 'Mito', 'Dans ce jeu de cartes tous les joueurs ont le droit de tricher sauf 1 : la gardienne punaise. En effet il faut tricher mais ne surtout pas se faire prendre par la gardienne punaise car si un joueur se fait prendre il devient à son tour la gardienne punaise et n’a plus le droit de tricher. Chaque joueur reçoit 8 cartes et lorsque la gardienne a fini de distribuer le bluff peut débuter. La punaise commence et pose une carte sur la pile de la défausse, la valeur de la carte doit être supérieur ou inférieure de 1 à la carte visible sur la défausse. Lorsqu’un joueur ne peut pas jouer il pioche. Certaines cartes spéciales sont dissimulées parmi les autres, telle que la carte Mito dont on doit absolument se débarrasser en trichant. Attention la triche reste réglementée, en effet la main de cartes doit toujours rester au-dessus de la table, il est interdit de faire disparaître plusieurs cartes à la fois, si un joueur se fait prendre, plus personne ne peut tricher avant que la vérification soit terminée et il est interdit de faire disparaître sa dernière carte.', 7, '00:15:00', 'Dynamique', 'Cartes', 1, 5);

-- --------------------------------------------------------

--
-- Structure de la table `JeuxEmprunte`
--

DROP TABLE IF EXISTS `JeuxEmprunte`;
CREATE TABLE IF NOT EXISTS `JeuxEmprunte` (
  `idJeuxEmprunte` int(11) NOT NULL AUTO_INCREMENT,
  `idJeux` int(11) NOT NULL,
  `idAdherent` int(11) NOT NULL,
  `dateEmprunt` date NOT NULL,
  `dateRetour` date NOT NULL,
  PRIMARY KEY (`idJeuxEmprunte`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Structure de la table `Ludotheque`
--

DROP TABLE IF EXISTS `Ludotheque`;
CREATE TABLE IF NOT EXISTS `Ludotheque` (
  `idLudotheque` int(11) NOT NULL AUTO_INCREMENT,
  `nom` text CHARACTER SET utf8 NOT NULL,
  `adresse` text CHARACTER SET utf8 NOT NULL,
  `numTel` varchar(10) CHARACTER SET utf8 NOT NULL,
  `adresseMail` text CHARACTER SET utf8 NOT NULL,
  `description` text CHARACTER SET utf8 NOT NULL,
  PRIMARY KEY (`idLudotheque`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=latin1;

--
-- Déchargement des données de la table `Ludotheque`
--

INSERT INTO `Ludotheque` (`idLudotheque`, `nom`, `adresse`, `numTel`, `adresseMail`, `description`) VALUES
(1, 'Ludothèque du Mans', '3 rue de la République\r\n72000 Le Mans', '0243567292', 'ludotheque.lemans@ludo.com', 'La ludothèque permet d’emprunter des jeux de société que nous n’avons pas chez nous.\r\nNotre ludothèque vous propose des jeux de sociétés pour tous les goûts et tous les âges mais aussi un service de personnalisation en fonction de vos envies.');
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
