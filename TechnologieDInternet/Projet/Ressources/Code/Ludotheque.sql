-- phpMyAdmin SQL Dump
-- version 5.0.1
-- https://www.phpmyadmin.net/
--
-- Hôte : localhost
-- Généré le : mar. 07 déc. 2021 à 17:09
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

-- --------------------------------------------------------

--
-- Structure de la table `Adherent`
--

CREATE TABLE `Adherent` (
  `idAdherent` int(11) NOT NULL,
  `nom` text NOT NULL,
  `prenom` text NOT NULL,
  `identifant` text NOT NULL,
  `motDePasse` text NOT NULL,
  `dateDeNaissance` date NOT NULL,
  `adresse` text NOT NULL,
  `adresseMail` text NOT NULL,
  `numTel` varchar(10) NOT NULL,
  `idJeuxEmprunte` int(11) NOT NULL,
  `idHistoriqueJeux` int(11) NOT NULL,
  `idLudotheque` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Structure de la table `Administrateur`
--

CREATE TABLE `Administrateur` (
  `idAdmin` int(11) NOT NULL,
  `idLudo` int(11) NOT NULL,
  `nom` text NOT NULL,
  `prenom` text NOT NULL,
  `identifiant` text NOT NULL,
  `motDePasse` text NOT NULL,
  `adresseMail` text NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Structure de la table `HistoriqueJeux`
--

CREATE TABLE `HistoriqueJeux` (
  `idHistoriqueJeux` int(11) NOT NULL,
  `idJeux` int(11) NOT NULL,
  `idAdherent` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Structure de la table `ImageJeux`
--

CREATE TABLE `ImageJeux` (
  `idImage` int(11) NOT NULL,
  `idJeux` int(11) NOT NULL,
  `cheminImage` text NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Structure de la table `Jeux`
--

CREATE TABLE `Jeux` (
  `idJeux` int(11) NOT NULL,
  `idHistoriqueJeux` int(11) NOT NULL,
  `idJeuxEmprunte` int(11) NOT NULL,
  `nom` text NOT NULL,
  `description` text NOT NULL,
  `age` int(11) NOT NULL,
  `duree` time NOT NULL,
  `activite` text NOT NULL,
  `type` text NOT NULL,
  `idLudotheque` int(11) NOT NULL,
  `quantite` int(11) NOT NULL,
  `idImage` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Structure de la table `JeuxEmprunte`
--

CREATE TABLE `JeuxEmprunte` (
  `idJeuxEmprunte` int(11) NOT NULL,
  `idJeux` int(11) NOT NULL,
  `idAdherent` int(11) NOT NULL,
  `dateEmprunt` date NOT NULL,
  `dateRetour` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Structure de la table `Ludotheque`
--

CREATE TABLE `Ludotheque` (
  `idLudotheque` int(11) NOT NULL,
  `nom` text NOT NULL,
  `adresse` text NOT NULL,
  `numTel` varchar(10) NOT NULL,
  `adresseMail` text NOT NULL,
  `description` text NOT NULL,
  `idAdmin` int(11) DEFAULT NULL,
  `idAdherent` int(11) DEFAULT NULL,
  `idJeux` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Déchargement des données de la table `Ludotheque`
--

INSERT INTO `Ludotheque` (`idLudotheque`, `nom`, `adresse`, `numTel`, `adresseMail`, `description`, `idAdmin`, `idAdherent`, `idJeux`) VALUES
(1, 'Ludothèque du Mans', '3 rue de la République\r\n72000 Le Mans', '0243567292', 'ludotheque.lemans@ludo.com', 'La ludothèque permet d’emprunter des jeux de société que nous n’avons pas chez nous.\r\nNotre ludothèque vous propose des jeux de sociétés pour tous les goûts et tous les âges mais aussi un service de personnalisation en fonction de vos envies.', NULL, NULL, NULL);

--
-- Index pour les tables déchargées
--

--
-- Index pour la table `Adherent`
--
ALTER TABLE `Adherent`
  ADD PRIMARY KEY (`idAdherent`);

--
-- Index pour la table `Administrateur`
--
ALTER TABLE `Administrateur`
  ADD PRIMARY KEY (`idAdmin`);

--
-- Index pour la table `HistoriqueJeux`
--
ALTER TABLE `HistoriqueJeux`
  ADD PRIMARY KEY (`idHistoriqueJeux`);

--
-- Index pour la table `ImageJeux`
--
ALTER TABLE `ImageJeux`
  ADD PRIMARY KEY (`idImage`);

--
-- Index pour la table `Jeux`
--
ALTER TABLE `Jeux`
  ADD PRIMARY KEY (`idJeux`);

--
-- Index pour la table `JeuxEmprunte`
--
ALTER TABLE `JeuxEmprunte`
  ADD PRIMARY KEY (`idJeuxEmprunte`);

--
-- Index pour la table `Ludotheque`
--
ALTER TABLE `Ludotheque`
  ADD PRIMARY KEY (`idLudotheque`);

--
-- AUTO_INCREMENT pour les tables déchargées
--

--
-- AUTO_INCREMENT pour la table `Adherent`
--
ALTER TABLE `Adherent`
  MODIFY `idAdherent` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pour la table `Administrateur`
--
ALTER TABLE `Administrateur`
  MODIFY `idAdmin` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pour la table `HistoriqueJeux`
--
ALTER TABLE `HistoriqueJeux`
  MODIFY `idHistoriqueJeux` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pour la table `ImageJeux`
--
ALTER TABLE `ImageJeux`
  MODIFY `idImage` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pour la table `Jeux`
--
ALTER TABLE `Jeux`
  MODIFY `idJeux` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pour la table `JeuxEmprunte`
--
ALTER TABLE `JeuxEmprunte`
  MODIFY `idJeuxEmprunte` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pour la table `Ludotheque`
--
ALTER TABLE `Ludotheque`
  MODIFY `idLudotheque` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
