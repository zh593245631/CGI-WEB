-- MySQL dump 10.13  Distrib 5.7.26, for Linux (x86_64)
--
-- Host: localhost    Database: db
-- ------------------------------------------------------
-- Server version	5.7.26

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Current Database: `db`
--

CREATE DATABASE /*!32312 IF NOT EXISTS*/ `db` /*!40100 DEFAULT CHARACTER SET utf8 */;

USE `db`;

--
-- Table structure for table `管理`
--

DROP TABLE IF EXISTS `管理`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `管理` (
  `基本工资` varchar(10) NOT NULL,
  PRIMARY KEY (`基本工资`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `管理`
--

LOCK TABLES `管理` WRITE;
/*!40000 ALTER TABLE `管理` DISABLE KEYS */;
/*!40000 ALTER TABLE `管理` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `comment`
--

DROP TABLE IF EXISTS `comment`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `comment` (
  `ID` int(11) NOT NULL AUTO_INCREMENT,
  `CID` varchar(20) DEFAULT NULL,
  `posttime` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `message` varchar(100) NOT NULL,
  `Ispass` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`),
  KEY `CID` (`CID`),
  CONSTRAINT `comment_ibfk_1` FOREIGN KEY (`CID`) REFERENCES `user` (`username`)
) ENGINE=InnoDB AUTO_INCREMENT=75 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `comment`
--

LOCK TABLES `comment` WRITE;
/*!40000 ALTER TABLE `comment` DISABLE KEYS */;
INSERT INTO `comment` VALUES (1,'yhs','2019-07-04 05:38:25','此评论已被屏蔽',1),(3,'hlb','2019-07-04 05:38:48','杀杀杀',1),(4,'yhs','2019-07-04 05:55:26','0.0',1),(5,'yhs','2019-07-04 05:47:08','heehhe',1),(6,'yhs','2019-07-04 05:47:19','heehhe',1),(7,'yhs','2019-07-04 05:47:51','heehhe',1),(8,'yhs','2019-07-04 05:50:44','heehhe',1),(9,'yhs','2019-07-04 07:24:23','dwdwd',0),(47,'yhs','2019-07-04 07:23:21','jjj',1),(48,'yhs','2019-07-04 07:23:25','ujj',1),(49,'yhs','2019-07-04 07:23:28','ffffff',1),(50,'yhs','2019-07-04 07:23:56','ffffff',1),(51,'yhs','2019-07-04 07:24:05','aaaa',1),(52,'yhs','2019-07-04 07:24:08','t44',1),(53,'yhs','2019-07-04 07:24:13','dwdwd',1),(56,'root','2019-07-04 08:16:52','heheh',1),(57,'root','2019-07-04 08:30:59','heheh',1),(59,'zzh','2019-07-05 02:51:56','sss',0),(60,'yhs','2019-07-05 04:18:58','asd',1),(61,'yhs','2019-07-05 04:19:01','asd',1),(63,'root','2019-07-05 04:28:43','sss',0),(64,'yhs','2019-07-05 09:51:33','0.0',0),(65,'yhs','2019-07-05 09:51:36','0.0',0),(66,'root','2019-07-06 01:52:13','i+am+root',1),(68,'root','2019-07-06 08:28:41','%E5%93%88%E5%93%88',1),(69,'root','2019-07-06 08:29:08','%E5%93%88%E5%93%88',0),(70,'root','2019-07-07 08:53:15','%E5%93%88%E5%93%88',0),(71,'root','2019-07-08 18:41:28','%E5%93%88%E5%93%88',0),(72,'root','2019-07-09 17:33:06','%E5%93%88%E5%93%88',0),(73,'root','2019-07-10 19:05:08','%E5%93%88%E5%93%88',0),(74,'root','2019-07-11 18:49:12','%E5%93%88%E5%93%88',0);
/*!40000 ALTER TABLE `comment` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `message`
--

DROP TABLE IF EXISTS `message`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `message` (
  `ID` int(11) NOT NULL AUTO_INCREMENT,
  `Title` varchar(100) NOT NULL,
  `pDate` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `zd` char(2) NOT NULL DEFAULT '1',
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB AUTO_INCREMENT=8 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `message`
--

LOCK TABLES `message` WRITE;
/*!40000 ALTER TABLE `message` DISABLE KEYS */;
INSERT INTO `message` VALUES (2,'JAVA作业','2019-07-04 01:59:27','1'),(3,'web课程设计','2019-07-04 02:20:00','1'),(4,'sql语句的使用','2019-07-04 02:20:07','1'),(5,'Linux开发','2019-07-04 02:20:11','1'),(6,'每日一题','2019-07-04 02:20:16','1'),(7,'今日资讯','2019-07-04 02:20:19','1');
/*!40000 ALTER TABLE `message` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `resource`
--

DROP TABLE IF EXISTS `resource`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `resource` (
  `ID` int(11) NOT NULL AUTO_INCREMENT,
  `lesson` varchar(50) NOT NULL,
  `content` varchar(100) NOT NULL,
  `pDate` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `visit` int(100) NOT NULL DEFAULT '0',
  `PID` varchar(20) DEFAULT NULL,
  PRIMARY KEY (`ID`),
  KEY `PID` (`PID`),
  CONSTRAINT `resource_ibfk_1` FOREIGN KEY (`PID`) REFERENCES `user` (`username`)
) ENGINE=InnoDB AUTO_INCREMENT=8 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `resource`
--

LOCK TABLES `resource` WRITE;
/*!40000 ALTER TABLE `resource` DISABLE KEYS */;
INSERT INTO `resource` VALUES (2,'JAVA','循环语句','2019-07-03 13:10:08',65,'yhs'),(3,'C','循环','2019-07-03 13:11:18',74,'yhs'),(4,'数据结构','顺序表','2019-07-03 13:29:11',4,'yhs'),(5,'数据结构','哈哈','2019-07-03 13:32:14',6,'zzh'),(6,'C++','哦哦哦','2019-07-04 01:03:03',1,'yhs'),(7,'C++','内容','2019-07-04 03:07:25',0,'yhs');
/*!40000 ALTER TABLE `resource` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `user`
--

DROP TABLE IF EXISTS `user`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `user` (
  `username` varchar(20) NOT NULL,
  `password` varchar(20) NOT NULL,
  `access` int(11) DEFAULT '0',
  PRIMARY KEY (`username`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `user`
--

LOCK TABLES `user` WRITE;
/*!40000 ALTER TABLE `user` DISABLE KEYS */;
INSERT INTO `user` VALUES ('a','1234',1),('aa','1234',0),('aaa','1234',1),('hlb','1234',1),('mht','1234',1),('root','1234',3),('root0','1234',0),('yhs','1234',2),('zzh','1234',1);
/*!40000 ALTER TABLE `user` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `video`
--

DROP TABLE IF EXISTS `video`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `video` (
  `ID` int(11) NOT NULL AUTO_INCREMENT,
  `lesson` varchar(50) NOT NULL,
  `content` varchar(100) NOT NULL,
  `pDate` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `visit` int(100) NOT NULL DEFAULT '0',
  `PID` varchar(20) DEFAULT NULL,
  PRIMARY KEY (`ID`),
  KEY `PID` (`PID`),
  CONSTRAINT `video_ibfk_1` FOREIGN KEY (`PID`) REFERENCES `user` (`username`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `video`
--

LOCK TABLES `video` WRITE;
/*!40000 ALTER TABLE `video` DISABLE KEYS */;
INSERT INTO `video` VALUES (1,'C语言学习视频','1.mp4','2019-07-04 01:32:35',1,'yhs'),(2,'C语言学习视频','2.mp4','2019-07-04 01:32:54',3,'zzh'),(3,'JAVA学习视频','3.mp4','2019-07-04 01:33:09',0,'zzh'),(4,'JAVA学习视频','4.mp4','2019-07-04 01:33:20',7,'yhs');
/*!40000 ALTER TABLE `video` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2019-07-21 13:05:34
