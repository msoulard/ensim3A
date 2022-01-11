-- phpMyAdmin SQL Dump
-- version 5.0.4
-- https://www.phpmyadmin.net/
--
-- Hôte : 127.0.0.1
-- Généré le : mar. 11 jan. 2022 à 12:19
-- Version du serveur :  10.4.17-MariaDB
-- Version de PHP : 8.0.1

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de données : `e2103704`
--

-- --------------------------------------------------------

--
-- Structure de la table `adherent`
--

CREATE TABLE `adherent` (
  `idAdherent` int(11) NOT NULL,
  `nom` text CHARACTER SET utf8 NOT NULL,
  `prenom` text CHARACTER SET utf8 NOT NULL,
  `identifiant` text CHARACTER SET utf8 NOT NULL,
  `motDePasse` text CHARACTER SET utf8 NOT NULL,
  `dateDeNaissance` date NOT NULL,
  `adresse` text CHARACTER SET utf8 NOT NULL,
  `adresseMail` text CHARACTER SET utf8 NOT NULL,
  `numTel` varchar(10) CHARACTER SET utf8 NOT NULL,
  `idLudotheque` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Déchargement des données de la table `adherent`
--

INSERT INTO `adherent` (`idAdherent`, `nom`, `prenom`, `identifiant`, `motDePasse`, `dateDeNaissance`, `adresse`, `adresseMail`, `numTel`, `idLudotheque`) VALUES
(1, 'Durand', 'Jean-Pierre', 'jpdurand', '1j2p3d', '1965-05-10', '15 avenue Durand 72000 Le Mans', 'jp.durand@laposte.net', '0665891523', 1);

-- --------------------------------------------------------

--
-- Structure de la table `administrateur`
--

CREATE TABLE `administrateur` (
  `idAdmin` int(11) NOT NULL,
  `idLudo` int(11) NOT NULL,
  `nom` text CHARACTER SET utf8 NOT NULL,
  `prenom` text CHARACTER SET utf8 NOT NULL,
  `identifiant` text CHARACTER SET utf8 NOT NULL,
  `motDePasse` text CHARACTER SET utf8 NOT NULL,
  `adresseMail` text CHARACTER SET utf8 NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Déchargement des données de la table `administrateur`
--

INSERT INTO `administrateur` (`idAdmin`, `idLudo`, `nom`, `prenom`, `identifiant`, `motDePasse`, `adresseMail`) VALUES
(1, 1, 'Georges', 'Marie', 'admin', 'ludotheque', 'marie.georges@ludotheque_lemans.com');

-- --------------------------------------------------------

--
-- Structure de la table `historiquejeux`
--

CREATE TABLE `historiquejeux` (
  `idHistoriqueJeux` int(11) NOT NULL,
  `idJeux` int(11) NOT NULL,
  `idAdherent` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Structure de la table `imagejeux`
--

CREATE TABLE `imagejeux` (
  `idImage` int(11) NOT NULL,
  `idJeux` int(11) NOT NULL,
  `cheminImage` text CHARACTER SET utf8 NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Déchargement des données de la table `imagejeux`
--

INSERT INTO `imagejeux` (`idImage`, `idJeux`, `cheminImage`) VALUES
(1, 1, '../Jeux/crazyCups.png'),
(2, 2, '../Jeux/jeu-Mito.png');

-- --------------------------------------------------------

--
-- Structure de la table `jeux`
--

CREATE TABLE `jeux` (
  `idJeux` int(11) NOT NULL,
  `nom` text CHARACTER SET utf8 NOT NULL,
  `description` text CHARACTER SET utf8 NOT NULL,
  `age` text CHARACTER SET utf8 NOT NULL,
  `duree` time NOT NULL,
  `activite` text CHARACTER SET utf8 NOT NULL,
  `type` text CHARACTER SET utf8 NOT NULL,
  `idLudotheque` int(11) NOT NULL,
  `quantite` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Déchargement des données de la table `jeux`
--

INSERT INTO `jeux` (`idJeux`, `nom`, `description`, `age`, `duree`, `activite`, `type`, `idLudotheque`, `quantite`) VALUES
(1, 'Crazy Cups', 'Dans Crazy Cups, chaque joueur reçoit cinq gobelets en cinq couleurs. A chaque début de tour, une carte combinant cinq éléments reprenant les mêmes couleurs que les gobelets est révélée. Les joueurs doivent alors aligner ou empiler rapidement leurs gobelets afin de reproduire exactement la même disposition que celle des éléments de la carte. Attention, il est important de bien suivre l\'ordre et le sens des couleurs ! Dès qu\'un joueur a terminé, il appuie vite sur la sonnette. Le plus rapide à réaliser correctement sa série remporte la carte en jeu et c\'est reparti pour un tour. Restez bien attentifs et ne perdez pas de vue votre objectif car pour gagner à Crazy Cups, il faut avoir de la suite dans les gobelets !', 'Enfant', '00:15:00', 'Dynamique', 'Ludique', 1, 5),
(2, 'Mito', 'Dans ce jeu de cartes tous les joueurs ont le droit de tricher sauf 1 : la gardienne punaise. En effet il faut tricher mais ne surtout pas se faire prendre par la gardienne punaise car si un joueur se fait prendre il devient à son tour la gardienne punaise et n\'a plus le droit de tricher. Chaque joueur reçoit 8 cartes et lorsque la gardienne a fini de distribuer le bluff peut débuter. La punaise commence et pose une carte sur la pile de la défausse, la valeur de la carte doit être supérieur ou inférieure de 1 à la carte visible sur la défausse. Lorsqu\'un joueur ne peut pas jouer il pioche. Certaines cartes spéciales sont dissimulées parmi les autres, telle que la carte Mito dont on doit absolument se débarrasser en trichant. Attention la triche reste réglementée, en effet la main de cartes doit toujours rester au-dessus de la table, il est interdit de faire disparaître plusieurs cartes à la fois, si un joueur se fait prendre, plus personne ne peut tricher avant que la vérification soit terminée et il est interdit de faire disparaître sa dernière carte.', 'Enfant', '00:15:00', 'Dynamique', 'Cartes', 1, 5),
(3, 'SOS Ouistiti', 'SOS Ouistiti est le jeu de société des petits singes de la forêt. \r\n\r\nL’objectif est de retirer une par une les branches en évitant de faire tomber les singes. Il faudra rester bien calme et utiliser toute sa dextérité ! Le joueur qui fait tomber un ou plusieurs singes, les garde. Lorsque tous les singes sont tombés, c’est le joueur qui en possède le moins qui a gagné.\r\n\r\nSOS Ouistiti est un jeu d\'ambiance et familial qui permettra aux petits à partir de 5 ans de pouvoir jouer comme les grands !', 'Enfant', '00:15:00', 'Dynamique', 'Ludique', 1, 3);

-- --------------------------------------------------------

--
-- Structure de la table `jeuxemprunte`
--

CREATE TABLE `jeuxemprunte` (
  `idJeuxEmprunte` int(11) NOT NULL,
  `idJeux` int(11) NOT NULL,
  `idAdherent` int(11) NOT NULL,
  `dateEmprunt` date NOT NULL,
  `dateRetour` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Structure de la table `ludotheque`
--

CREATE TABLE `ludotheque` (
  `idLudotheque` int(11) NOT NULL,
  `nom` text CHARACTER SET utf8 NOT NULL,
  `adresse` text CHARACTER SET utf8 NOT NULL,
  `numTel` varchar(10) CHARACTER SET utf8 NOT NULL,
  `adresseMail` text CHARACTER SET utf8 NOT NULL,
  `description` text CHARACTER SET utf8 NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Déchargement des données de la table `ludotheque`
--

INSERT INTO `ludotheque` (`idLudotheque`, `nom`, `adresse`, `numTel`, `adresseMail`, `description`) VALUES
(1, 'Ludothèque du Mans', '3 rue de la République\r\n72000 Le Mans', '0243567292', 'ludotheque.lemans@ludo.com', 'La ludothèque permet d’emprunter des jeux de société que nous n’avons pas chez nous.\r\nNotre ludothèque vous propose des jeux de sociétés pour tous les goûts et tous les âges mais aussi un service de personnalisation en fonction de vos envies.');

--
-- Index pour les tables déchargées
--

--
-- Index pour la table `adherent`
--
ALTER TABLE `adherent`
  ADD PRIMARY KEY (`idAdherent`);

--
-- Index pour la table `administrateur`
--
ALTER TABLE `administrateur`
  ADD PRIMARY KEY (`idAdmin`);

--
-- Index pour la table `historiquejeux`
--
ALTER TABLE `historiquejeux`
  ADD PRIMARY KEY (`idHistoriqueJeux`);

--
-- Index pour la table `imagejeux`
--
ALTER TABLE `imagejeux`
  ADD PRIMARY KEY (`idImage`);

--
-- Index pour la table `jeux`
--
ALTER TABLE `jeux`
  ADD PRIMARY KEY (`idJeux`);

--
-- Index pour la table `jeuxemprunte`
--
ALTER TABLE `jeuxemprunte`
  ADD PRIMARY KEY (`idJeuxEmprunte`);

--
-- Index pour la table `ludotheque`
--
ALTER TABLE `ludotheque`
  ADD PRIMARY KEY (`idLudotheque`);

--
-- AUTO_INCREMENT pour les tables déchargées
--

--
-- AUTO_INCREMENT pour la table `adherent`
--
ALTER TABLE `adherent`
  MODIFY `idAdherent` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;

--
-- AUTO_INCREMENT pour la table `administrateur`
--
ALTER TABLE `administrateur`
  MODIFY `idAdmin` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;

--
-- AUTO_INCREMENT pour la table `historiquejeux`
--
ALTER TABLE `historiquejeux`
  MODIFY `idHistoriqueJeux` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pour la table `imagejeux`
--
ALTER TABLE `imagejeux`
  MODIFY `idImage` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;

--
-- AUTO_INCREMENT pour la table `jeux`
--
ALTER TABLE `jeux`
  MODIFY `idJeux` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;

--
-- AUTO_INCREMENT pour la table `jeuxemprunte`
--
ALTER TABLE `jeuxemprunte`
  MODIFY `idJeuxEmprunte` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pour la table `ludotheque`
--
ALTER TABLE `ludotheque`
  MODIFY `idLudotheque` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
