-- phpMyAdmin SQL Dump
-- version 4.0.10.18
-- https://www.phpmyadmin.net
--
-- Host: localhost:3306
-- Generation Time: Apr 20, 2017 at 07:08 AM
-- Server version: 5.6.28-76.1-log
-- PHP Version: 5.6.30

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `donovan9_NBA`
--

DELIMITER $$
--
-- Procedures
--
CREATE DEFINER=`donovan9`@`localhost` PROCEDURE `controlDepth`(IN `pName` VARCHAR(255), IN `pNumber` INT(2), IN `pPosition` CHAR(2), IN `pTeam` VARCHAR(255), OUT `status` VARCHAR(255))
    NO SQL
begin
  if depthChart(pTeam) < 3 then
	 insert into player (name,number,position,team) Values (pName,pNumber,pPosition,pTeam);
     set status = 'ok';
  else
     set status = 'Too many players';
  end if;
  commit;
end$$

--
-- Functions
--
CREATE DEFINER=`donovan9`@`localhost` FUNCTION `depthChart`(`pName` VARCHAR(255)) RETURNS int(1)
    DETERMINISTIC
BEGIN
declare lenDepth int(1);
set lenDepth = (select count(*) from player where team = pName);
return lenDepth;
END$$

DELIMITER ;

-- --------------------------------------------------------

--
-- Table structure for table `championship`
--

CREATE TABLE IF NOT EXISTS `championship` (
  `team` varchar(255) DEFAULT NULL,
  `year` int(4) NOT NULL DEFAULT '0',
  `mvp` varchar(255) DEFAULT NULL,
  `id` int(11) NOT NULL AUTO_INCREMENT,
  PRIMARY KEY (`id`),
  UNIQUE KEY `year` (`year`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=5 ;

--
-- Dumping data for table `championship`
--

INSERT INTO `championship` (`team`, `year`, `mvp`, `id`) VALUES
('Ravens ', 1990, 'Ray Lewis', 1),
('Spurs', 1989, 'Kawhi Leonard', 2),
('Mavericks', 2011, 'Dirk Nowitski', 4);

-- --------------------------------------------------------

--
-- Table structure for table `coach`
--

CREATE TABLE IF NOT EXISTS `coach` (
  `name` varchar(255) DEFAULT NULL,
  `team` varchar(255) NOT NULL DEFAULT '',
  `contract` varchar(11) NOT NULL DEFAULT '0',
  `id` int(11) NOT NULL AUTO_INCREMENT,
  PRIMARY KEY (`id`),
  UNIQUE KEY `team` (`team`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=13 ;

--
-- Dumping data for table `coach`
--

INSERT INTO `coach` (`name`, `team`, `contract`, `id`) VALUES
('Chris Myers', 'Cavaliers', '200', 8),
('Mike Dantoni', 'Rockets', '700', 9),
('Bryan Steele', 'bobcats', '600', 12);

-- --------------------------------------------------------

--
-- Stand-in structure for view `coachPlayer`
--
CREATE TABLE IF NOT EXISTS `coachPlayer` (
`playername` varchar(255)
,`coachname` varchar(255)
);
-- --------------------------------------------------------

--
-- Table structure for table `MVP`
--

CREATE TABLE IF NOT EXISTS `MVP` (
  `name` varchar(255) DEFAULT NULL,
  `year` int(4) NOT NULL DEFAULT '0',
  `team` varchar(255) DEFAULT NULL,
  `points` int(2) NOT NULL DEFAULT '0',
  `rebounds` int(2) NOT NULL DEFAULT '0',
  `assists` int(2) NOT NULL DEFAULT '0',
  `id` int(11) NOT NULL AUTO_INCREMENT,
  PRIMARY KEY (`id`),
  UNIQUE KEY `year` (`year`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=4 ;

--
-- Dumping data for table `MVP`
--

INSERT INTO `MVP` (`name`, `year`, `team`, `points`, `rebounds`, `assists`, `id`) VALUES
('Lebron James', 2000, 'Cavaliers', 22, 11, 14, 1),
('Stephen Curry', 1999, 'Warriors', 25, 9, 14, 2);

-- --------------------------------------------------------

--
-- Table structure for table `owner`
--

CREATE TABLE IF NOT EXISTS `owner` (
  `name` varchar(255) DEFAULT NULL,
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `team` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `team` (`team`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=6 ;

--
-- Dumping data for table `owner`
--

INSERT INTO `owner` (`name`, `id`, `team`) VALUES
('Mark Cuban', 3, 'Rockets');

-- --------------------------------------------------------

--
-- Table structure for table `player`
--

CREATE TABLE IF NOT EXISTS `player` (
  `name` varchar(255) DEFAULT NULL,
  `position` char(2) DEFAULT NULL,
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `number` int(2) DEFAULT NULL,
  `team` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `UC_player` (`team`,`number`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=67 ;

--
-- Dumping data for table `player`
--

INSERT INTO `player` (`name`, `position`, `id`, `number`, `team`) VALUES
('Yuppy', 'SG', 60, 17, 'Cavaliers'),
('James Harden', 'SG', 61, 13, 'Rockets'),
('Adam Sims', 'PG', 62, 55, 'Rockets'),
('Noah', 'C', 66, 44, 'Rockets');

-- --------------------------------------------------------

--
-- Table structure for table `standings`
--

CREATE TABLE IF NOT EXISTS `standings` (
  `name` varchar(255) NOT NULL DEFAULT '',
  `wins` int(2) NOT NULL DEFAULT '0',
  `losses` int(2) NOT NULL DEFAULT '0',
  `id` int(11) NOT NULL AUTO_INCREMENT,
  PRIMARY KEY (`id`),
  KEY `name` (`name`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=38 ;

--
-- Dumping data for table `standings`
--

INSERT INTO `standings` (`name`, `wins`, `losses`, `id`) VALUES
('Hawks', 0, 3, 29),
('Cavaliers', 1, 0, 31),
('Warriors', 0, 0, 33);

-- --------------------------------------------------------

--
-- Table structure for table `team`
--

CREATE TABLE IF NOT EXISTS `team` (
  `name` varchar(255) NOT NULL DEFAULT '',
  `conference` varchar(4) DEFAULT NULL,
  `rank` char(2) NOT NULL,
  `id` int(11) NOT NULL AUTO_INCREMENT,
  PRIMARY KEY (`id`),
  UNIQUE KEY `rank` (`rank`),
  UNIQUE KEY `rank_2` (`rank`),
  UNIQUE KEY `rank_3` (`rank`),
  UNIQUE KEY `name` (`name`,`rank`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=53 ;

--
-- Dumping data for table `team`
--

INSERT INTO `team` (`name`, `conference`, `rank`, `id`) VALUES
('Hawks', 'East', '6', 47),
('Cavaliers', 'East', '2', 49),
('Warriors', 'West', '8', 50);

--
-- Triggers `team`
--
DROP TRIGGER IF EXISTS `addStanding`;
DELIMITER //
CREATE TRIGGER `addStanding` AFTER INSERT ON `team`
 FOR EACH ROW INSERT INTO standings (name)
      VALUES (new.name)
//
DELIMITER ;
DROP TRIGGER IF EXISTS `deleteOld`;
DELIMITER //
CREATE TRIGGER `deleteOld` BEFORE UPDATE ON `team`
 FOR EACH ROW Delete FROM standings
    WHERE standings.name = old.name
//
DELIMITER ;
DROP TRIGGER IF EXISTS `deleteStanding`;
DELIMITER //
CREATE TRIGGER `deleteStanding` BEFORE DELETE ON `team`
 FOR EACH ROW Delete FROM standings
    WHERE standings.name = old.name
//
DELIMITER ;
DROP TRIGGER IF EXISTS `updateOldStanding`;
DELIMITER //
CREATE TRIGGER `updateOldStanding` AFTER UPDATE ON `team`
 FOR EACH ROW INSERT INTO standings (name)
      VALUES (new.name)
//
DELIMITER ;

-- --------------------------------------------------------

--
-- Structure for view `coachPlayer`
--
DROP TABLE IF EXISTS `coachPlayer`;

CREATE ALGORITHM=UNDEFINED DEFINER=`donovan9`@`localhost` SQL SECURITY DEFINER VIEW `coachPlayer` AS select `s`.`name` AS `playername`,`c`.`name` AS `coachname` from (`player` `s` join `coach` `c` on((`s`.`team` = `c`.`team`)));

--
-- Constraints for dumped tables
--

--
-- Constraints for table `standings`
--
ALTER TABLE `standings`
  ADD CONSTRAINT `standings_ibfk_1` FOREIGN KEY (`name`) REFERENCES `team` (`name`);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
