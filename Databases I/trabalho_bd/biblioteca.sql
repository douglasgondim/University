-- MySQL dump 10.13  Distrib 8.0.16, for macos10.14 (x86_64)
--
-- Host: localhost    Database: Biblioteca
-- ------------------------------------------------------
-- Server version	8.0.16

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
 SET NAMES utf8mb4 ;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `acervo_livro`
--

DROP TABLE IF EXISTS `acervo_livro`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
 SET character_set_client = utf8mb4 ;
CREATE TABLE `acervo_livro` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `titulo` longtext NOT NULL,
  `autor` longtext NOT NULL,
  `capa` longtext NOT NULL,
  `sumario` longtext NOT NULL,
  `numeroExemplares` int(11) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `acervo_livro`
--

LOCK TABLES `acervo_livro` WRITE;
/*!40000 ALTER TABLE `acervo_livro` DISABLE KEYS */;
/*!40000 ALTER TABLE `acervo_livro` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `auth_group`
--

DROP TABLE IF EXISTS `auth_group`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
 SET character_set_client = utf8mb4 ;
CREATE TABLE `auth_group` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(150) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `name` (`name`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `auth_group`
--

LOCK TABLES `auth_group` WRITE;
/*!40000 ALTER TABLE `auth_group` DISABLE KEYS */;
/*!40000 ALTER TABLE `auth_group` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `auth_group_permissions`
--

DROP TABLE IF EXISTS `auth_group_permissions`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
 SET character_set_client = utf8mb4 ;
CREATE TABLE `auth_group_permissions` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `group_id` int(11) NOT NULL,
  `permission_id` int(11) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `auth_group_permissions_group_id_permission_id_0cd325b0_uniq` (`group_id`,`permission_id`),
  KEY `auth_group_permissio_permission_id_84c5c92e_fk_auth_perm` (`permission_id`),
  CONSTRAINT `auth_group_permissio_permission_id_84c5c92e_fk_auth_perm` FOREIGN KEY (`permission_id`) REFERENCES `auth_permission` (`id`),
  CONSTRAINT `auth_group_permissions_group_id_b120cbf9_fk_auth_group_id` FOREIGN KEY (`group_id`) REFERENCES `auth_group` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `auth_group_permissions`
--

LOCK TABLES `auth_group_permissions` WRITE;
/*!40000 ALTER TABLE `auth_group_permissions` DISABLE KEYS */;
/*!40000 ALTER TABLE `auth_group_permissions` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `auth_permission`
--

DROP TABLE IF EXISTS `auth_permission`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
 SET character_set_client = utf8mb4 ;
CREATE TABLE `auth_permission` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(255) NOT NULL,
  `content_type_id` int(11) NOT NULL,
  `codename` varchar(100) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `auth_permission_content_type_id_codename_01ab375a_uniq` (`content_type_id`,`codename`),
  CONSTRAINT `auth_permission_content_type_id_2f476e4b_fk_django_co` FOREIGN KEY (`content_type_id`) REFERENCES `django_content_type` (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=57 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `auth_permission`
--

LOCK TABLES `auth_permission` WRITE;
/*!40000 ALTER TABLE `auth_permission` DISABLE KEYS */;
INSERT INTO `auth_permission` VALUES (1,'Can add log entry',1,'add_logentry'),(2,'Can change log entry',1,'change_logentry'),(3,'Can delete log entry',1,'delete_logentry'),(4,'Can view log entry',1,'view_logentry'),(5,'Can add permission',2,'add_permission'),(6,'Can change permission',2,'change_permission'),(7,'Can delete permission',2,'delete_permission'),(8,'Can view permission',2,'view_permission'),(9,'Can add group',3,'add_group'),(10,'Can change group',3,'change_group'),(11,'Can delete group',3,'delete_group'),(12,'Can view group',3,'view_group'),(13,'Can add user',4,'add_user'),(14,'Can change user',4,'change_user'),(15,'Can delete user',4,'delete_user'),(16,'Can view user',4,'view_user'),(17,'Can add content type',5,'add_contenttype'),(18,'Can change content type',5,'change_contenttype'),(19,'Can delete content type',5,'delete_contenttype'),(20,'Can view content type',5,'view_contenttype'),(21,'Can add session',6,'add_session'),(22,'Can change session',6,'change_session'),(23,'Can delete session',6,'delete_session'),(24,'Can view session',6,'view_session'),(25,'Can add login',7,'add_login'),(26,'Can change login',7,'change_login'),(27,'Can delete login',7,'delete_login'),(28,'Can view login',7,'view_login'),(29,'Can add livro',8,'add_livro'),(30,'Can change livro',8,'change_livro'),(31,'Can delete livro',8,'delete_livro'),(32,'Can view livro',8,'view_livro'),(33,'Can add autor',9,'add_autor'),(34,'Can change autor',9,'change_autor'),(35,'Can delete autor',9,'delete_autor'),(36,'Can view autor',9,'view_autor'),(37,'Can add editora',10,'add_editora'),(38,'Can change editora',10,'change_editora'),(39,'Can delete editora',10,'delete_editora'),(40,'Can view editora',10,'view_editora'),(41,'Can add exemplar',11,'add_exemplar'),(42,'Can change exemplar',11,'change_exemplar'),(43,'Can delete exemplar',11,'delete_exemplar'),(44,'Can view exemplar',11,'view_exemplar'),(45,'Can add reserva',12,'add_reserva'),(46,'Can change reserva',12,'change_reserva'),(47,'Can delete reserva',12,'delete_reserva'),(48,'Can view reserva',12,'view_reserva'),(49,'Can add contato',13,'add_contato'),(50,'Can change contato',13,'change_contato'),(51,'Can delete contato',13,'delete_contato'),(52,'Can view contato',13,'view_contato'),(53,'Can add usuario',14,'add_usuario'),(54,'Can change usuario',14,'change_usuario'),(55,'Can delete usuario',14,'delete_usuario'),(56,'Can view usuario',14,'view_usuario');
/*!40000 ALTER TABLE `auth_permission` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `auth_user`
--

DROP TABLE IF EXISTS `auth_user`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
 SET character_set_client = utf8mb4 ;
CREATE TABLE `auth_user` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `password` varchar(128) NOT NULL,
  `last_login` datetime(6) DEFAULT NULL,
  `is_superuser` tinyint(1) NOT NULL,
  `username` varchar(150) NOT NULL,
  `first_name` varchar(30) NOT NULL,
  `last_name` varchar(150) NOT NULL,
  `email` varchar(254) NOT NULL,
  `is_staff` tinyint(1) NOT NULL,
  `is_active` tinyint(1) NOT NULL,
  `date_joined` datetime(6) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `username` (`username`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `auth_user`
--

LOCK TABLES `auth_user` WRITE;
/*!40000 ALTER TABLE `auth_user` DISABLE KEYS */;
/*!40000 ALTER TABLE `auth_user` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `auth_user_groups`
--

DROP TABLE IF EXISTS `auth_user_groups`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
 SET character_set_client = utf8mb4 ;
CREATE TABLE `auth_user_groups` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `user_id` int(11) NOT NULL,
  `group_id` int(11) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `auth_user_groups_user_id_group_id_94350c0c_uniq` (`user_id`,`group_id`),
  KEY `auth_user_groups_group_id_97559544_fk_auth_group_id` (`group_id`),
  CONSTRAINT `auth_user_groups_group_id_97559544_fk_auth_group_id` FOREIGN KEY (`group_id`) REFERENCES `auth_group` (`id`),
  CONSTRAINT `auth_user_groups_user_id_6a12ed8b_fk_auth_user_id` FOREIGN KEY (`user_id`) REFERENCES `auth_user` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `auth_user_groups`
--

LOCK TABLES `auth_user_groups` WRITE;
/*!40000 ALTER TABLE `auth_user_groups` DISABLE KEYS */;
/*!40000 ALTER TABLE `auth_user_groups` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `auth_user_user_permissions`
--

DROP TABLE IF EXISTS `auth_user_user_permissions`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
 SET character_set_client = utf8mb4 ;
CREATE TABLE `auth_user_user_permissions` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `user_id` int(11) NOT NULL,
  `permission_id` int(11) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `auth_user_user_permissions_user_id_permission_id_14a6b632_uniq` (`user_id`,`permission_id`),
  KEY `auth_user_user_permi_permission_id_1fbb5f2c_fk_auth_perm` (`permission_id`),
  CONSTRAINT `auth_user_user_permi_permission_id_1fbb5f2c_fk_auth_perm` FOREIGN KEY (`permission_id`) REFERENCES `auth_permission` (`id`),
  CONSTRAINT `auth_user_user_permissions_user_id_a95ead1b_fk_auth_user_id` FOREIGN KEY (`user_id`) REFERENCES `auth_user` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `auth_user_user_permissions`
--

LOCK TABLES `auth_user_user_permissions` WRITE;
/*!40000 ALTER TABLE `auth_user_user_permissions` DISABLE KEYS */;
/*!40000 ALTER TABLE `auth_user_user_permissions` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Autor`
--

DROP TABLE IF EXISTS `Autor`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
 SET character_set_client = utf8mb4 ;
CREATE TABLE `Autor` (
  `nome` varchar(80) DEFAULT NULL,
  `pk_id_autor` int(11) NOT NULL AUTO_INCREMENT,
  `biografia` varchar(1000) DEFAULT NULL,
  `foto` varchar(500) DEFAULT NULL,
  PRIMARY KEY (`pk_id_autor`)
) ENGINE=InnoDB AUTO_INCREMENT=7 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Autor`
--

LOCK TABLES `Autor` WRITE;
/*!40000 ALTER TABLE `Autor` DISABLE KEYS */;
INSERT INTO `Autor` VALUES ('Aluísio Azevedo',1,'Aluísio Tancredo Gonçalves de Azevedo (São Luís, 14 de abril de 1857 — Buenos Aires, 21 de janeiro de 1913) foi um romancista, contista, cronista, diplomata, caricaturista e jornalista brasileiro; além de bom desenhista e discreto pintor.','https://upload.wikimedia.org/wikipedia/commons/4/4e/Aluisio_Azevedo.jpg'),('Machado de Assis',2,'Joaquim Maria Machado de Assis (Rio de Janeiro, 21 de junho de 1839 — Rio de Janeiro, 29 de setembro de 1908) foi um escritor brasileiro, considerado por muitos críticos, estudiosos, escritores e leitores um dos maiores senão o maior nome da literatura do Brasil.','https://upload.wikimedia.org/wikipedia/commons/thumb/9/98/Machado_de_Assis_1904.jpg/250px-Machado_de_Assis_1904.jpg'),('Lima Barreto',3,'Afonso Henriques de Lima Barreto, mais conhecido como Lima Barreto (Rio de Janeiro, 13 de maio de 1881 — Rio de Janeiro, 1 de novembro de 1922) foi um jornalista e escritor que publicou romances, sátiras, contos, crônicas e uma vasta obra em periódicos, principalmente em revistas populares ilustradas e periódicos anarquistas do início do século XX','https://upload.wikimedia.org/wikipedia/commons/thumb/0/0f/LimaBarreto.jpg/220px-LimaBarreto.jpg'),('Graciliano Ramos',4,'Graciliano Ramos de Oliveira (Quebrangulo, 27 de outubro de 1892 — Rio de Janeiro, 20 de março de 1953) foi um romancista, cronista, contista, jornalista, político, militante comunista e memorialista brasileiro do século XX, mais conhecido por sua obra Vidas Secas (1938).','https://upload.wikimedia.org/wikipedia/pt/thumb/0/09/GracilianoRamos.jpg/200px-GracilianoRamos.jpg'),('João Cabral de Melo Neto',5,'João Cabral de Melo Neto (Recife, 9 de janeiro de 1920 — Rio de Janeiro, 9 de outubro de 1999) foi um poeta e diplomata brasileiro.','https://upload.wikimedia.org/wikipedia/pt/thumb/a/a0/JoaoCabral.JPG/200px-JoaoCabral.JPG'),('Clarice Lispector',6,'Clarice Lispector, nascida Chaya Pinkhasovna Lispector, foi uma escritora e jornalista ucraniana naturalizada brasileira. Autora de romances, contos e ensaios, é considerada uma das escritoras brasileiras mais importantes do século XX e a maior escritora judia desde Franz Kafka.','https://upload.wikimedia.org/wikipedia/pt/thumb/5/5a/Clarice_Lispector.jpg/200px-Clarice_Lispector.jpg');
/*!40000 ALTER TABLE `Autor` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Contato`
--

DROP TABLE IF EXISTS `Contato`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
 SET character_set_client = utf8mb4 ;
CREATE TABLE `Contato` (
  `pk_contato` int(11) NOT NULL AUTO_INCREMENT,
  `telefone` int(11) DEFAULT NULL,
  `endereco` varchar(300) DEFAULT NULL,
  `cidade` varchar(80) DEFAULT NULL,
  `estado` varchar(3) DEFAULT NULL,
  `cep` int(11) DEFAULT NULL,
  PRIMARY KEY (`pk_contato`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Contato`
--

LOCK TABLES `Contato` WRITE;
/*!40000 ALTER TABLE `Contato` DISABLE KEYS */;
INSERT INTO `Contato` VALUES (1,90901111,'Rua 1','Russas','CE',62900000),(2,90901112,'Rua 2','Russas','CE',62900000),(3,90901113,'Rua 3','Russas','CE',62900000);
/*!40000 ALTER TABLE `Contato` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Devolucao`
--

DROP TABLE IF EXISTS `Devolucao`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
 SET character_set_client = utf8mb4 ;
CREATE TABLE `Devolucao` (
  `pk_codigo` int(11) NOT NULL AUTO_INCREMENT,
  `fk_cod_exemp` int(11) DEFAULT NULL,
  `data_devolucao` date DEFAULT NULL,
  `fk_id_bibliotecario` int(11) DEFAULT NULL,
  `multa` float DEFAULT NULL,
  `fk_cod_emp` int(11) DEFAULT NULL,
  PRIMARY KEY (`pk_codigo`),
  KEY `fk_cod_emp` (`fk_cod_emp`),
  KEY `fk_cod_exemp` (`fk_cod_exemp`),
  KEY `fk_id_bibliotecario` (`fk_id_bibliotecario`),
  CONSTRAINT `devolucao_ibfk_1` FOREIGN KEY (`fk_cod_emp`) REFERENCES `emprestimo` (`pk_codigo`) ON UPDATE CASCADE,
  CONSTRAINT `devolucao_ibfk_2` FOREIGN KEY (`fk_cod_exemp`) REFERENCES `exemplar` (`pk_cod_exemp`) ON UPDATE CASCADE,
  CONSTRAINT `devolucao_ibfk_3` FOREIGN KEY (`fk_id_bibliotecario`) REFERENCES `usuario` (`pk_id`) ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Devolucao`
--

LOCK TABLES `Devolucao` WRITE;
/*!40000 ALTER TABLE `Devolucao` DISABLE KEYS */;
INSERT INTO `Devolucao` VALUES (1,7,'2019-03-04',1,-2.1,8),(2,3,'2019-03-05',2,-1.8,9);
/*!40000 ALTER TABLE `Devolucao` ENABLE KEYS */;
UNLOCK TABLES;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
/*!50003 CREATE*/ /*!50017 DEFINER=`root`@`localhost`*/ /*!50003 TRIGGER `tg_multa` BEFORE INSERT ON `devolucao` FOR EACH ROW Set New.multa = DATEDIFF(New.data_devolucao, (SELECT E.data_limite_devolucao FROM(Emprestimo as E) Where E.fk_cod_exemp=New.fk_cod_exemp))*0.30 */;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
/*!50003 CREATE*/ /*!50017 DEFINER=`root`@`localhost`*/ /*!50003 TRIGGER `tg_dev` AFTER INSERT ON `devolucao` FOR EACH ROW Update Livro as L set L.qtd_exemp = L.qtd_exemp+1 where ((SELECT E.fk_cod_livro FROM(Exemplar as E ) Where E.pk_cod_exemp=New.fk_cod_exemp)=L.pk_cod_livro) */;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
/*!50003 CREATE*/ /*!50017 DEFINER=`root`@`localhost`*/ /*!50003 TRIGGER `tg_exempSet1` AFTER INSERT ON `devolucao` FOR EACH ROW Update Exemplar as E set E.disp = 1 where E.pk_cod_exemp = NEW.fk_cod_exemp */;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;

--
-- Table structure for table `django_admin_log`
--

DROP TABLE IF EXISTS `django_admin_log`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
 SET character_set_client = utf8mb4 ;
CREATE TABLE `django_admin_log` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `action_time` datetime(6) NOT NULL,
  `object_id` longtext,
  `object_repr` varchar(200) NOT NULL,
  `action_flag` smallint(5) unsigned NOT NULL,
  `change_message` longtext NOT NULL,
  `content_type_id` int(11) DEFAULT NULL,
  `user_id` int(11) NOT NULL,
  PRIMARY KEY (`id`),
  KEY `django_admin_log_content_type_id_c4bce8eb_fk_django_co` (`content_type_id`),
  KEY `django_admin_log_user_id_c564eba6_fk_auth_user_id` (`user_id`),
  CONSTRAINT `django_admin_log_content_type_id_c4bce8eb_fk_django_co` FOREIGN KEY (`content_type_id`) REFERENCES `django_content_type` (`id`),
  CONSTRAINT `django_admin_log_user_id_c564eba6_fk_auth_user_id` FOREIGN KEY (`user_id`) REFERENCES `auth_user` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `django_admin_log`
--

LOCK TABLES `django_admin_log` WRITE;
/*!40000 ALTER TABLE `django_admin_log` DISABLE KEYS */;
/*!40000 ALTER TABLE `django_admin_log` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `django_content_type`
--

DROP TABLE IF EXISTS `django_content_type`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
 SET character_set_client = utf8mb4 ;
CREATE TABLE `django_content_type` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `app_label` varchar(100) NOT NULL,
  `model` varchar(100) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `django_content_type_app_label_model_76bd3d3b_uniq` (`app_label`,`model`)
) ENGINE=InnoDB AUTO_INCREMENT=15 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `django_content_type`
--

LOCK TABLES `django_content_type` WRITE;
/*!40000 ALTER TABLE `django_content_type` DISABLE KEYS */;
INSERT INTO `django_content_type` VALUES (9,'acervo','autor'),(10,'acervo','editora'),(11,'acervo','exemplar'),(8,'acervo','livro'),(1,'admin','logentry'),(3,'auth','group'),(2,'auth','permission'),(4,'auth','user'),(5,'contenttypes','contenttype'),(7,'login','login'),(12,'reserva','reserva'),(6,'sessions','session'),(13,'usuario','contato'),(14,'usuario','usuario');
/*!40000 ALTER TABLE `django_content_type` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `django_migrations`
--

DROP TABLE IF EXISTS `django_migrations`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
 SET character_set_client = utf8mb4 ;
CREATE TABLE `django_migrations` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `app` varchar(255) NOT NULL,
  `name` varchar(255) NOT NULL,
  `applied` datetime(6) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=26 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `django_migrations`
--

LOCK TABLES `django_migrations` WRITE;
/*!40000 ALTER TABLE `django_migrations` DISABLE KEYS */;
INSERT INTO `django_migrations` VALUES (1,'acervo','0001_initial','2019-06-21 21:23:23.118243'),(2,'acervo','0002_auto_20190522_1618','2019-06-21 21:23:23.183897'),(3,'acervo','0003_auto_20190522_1626','2019-06-21 21:23:23.188968'),(4,'acervo','0004_auto_20190523_0008','2019-06-21 21:23:23.197392'),(5,'acervo','0005_auto_20190525_1431','2019-06-21 21:23:23.202070'),(6,'contenttypes','0001_initial','2019-06-21 21:23:23.372306'),(7,'auth','0001_initial','2019-06-21 21:23:23.484750'),(8,'admin','0001_initial','2019-06-21 21:23:23.983342'),(9,'admin','0002_logentry_remove_auto_add','2019-06-21 21:23:24.095694'),(10,'admin','0003_logentry_add_action_flag_choices','2019-06-21 21:23:24.107429'),(11,'contenttypes','0002_remove_content_type_name','2019-06-21 21:23:24.245540'),(12,'auth','0002_alter_permission_name_max_length','2019-06-21 21:23:24.310105'),(13,'auth','0003_alter_user_email_max_length','2019-06-21 21:23:24.366072'),(14,'auth','0004_alter_user_username_opts','2019-06-21 21:23:24.380038'),(15,'auth','0005_alter_user_last_login_null','2019-06-21 21:23:24.422402'),(16,'auth','0006_require_contenttypes_0002','2019-06-21 21:23:24.425659'),(17,'auth','0007_alter_validators_add_error_messages','2019-06-21 21:23:24.437469'),(18,'auth','0008_alter_user_username_max_length','2019-06-21 21:23:24.527407'),(19,'auth','0009_alter_user_last_name_max_length','2019-06-21 21:23:24.577032'),(20,'auth','0010_alter_group_name_max_length','2019-06-21 21:23:24.599293'),(21,'auth','0011_update_proxy_permissions','2019-06-21 21:23:24.614278'),(22,'login','0001_initial','2019-06-21 21:23:24.620940'),(23,'reserva','0001_initial','2019-06-21 21:23:24.626475'),(24,'sessions','0001_initial','2019-06-21 21:23:24.653281'),(25,'usuario','0001_initial','2019-06-21 21:23:24.686212');
/*!40000 ALTER TABLE `django_migrations` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `django_session`
--

DROP TABLE IF EXISTS `django_session`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
 SET character_set_client = utf8mb4 ;
CREATE TABLE `django_session` (
  `session_key` varchar(40) NOT NULL,
  `session_data` longtext NOT NULL,
  `expire_date` datetime(6) NOT NULL,
  PRIMARY KEY (`session_key`),
  KEY `django_session_expire_date_a5c62663` (`expire_date`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `django_session`
--

LOCK TABLES `django_session` WRITE;
/*!40000 ALTER TABLE `django_session` DISABLE KEYS */;
INSERT INTO `django_session` VALUES ('7jv40c2vfl959mkh03iewy2gldrv9pq0','OWFhZDAzMzYzNDY2YjdmYTdlNDczODgzOTIwODUwNmNmNzI1ZjMxMjp7InVzZXJfZW1haWwiOiJkb3VnbGFzQGhvdG1haWwuY29tIiwidXNlcl9pZCI6MywiX3Nlc3Npb25fZXhwaXJ5Ijo2MDB9','2019-06-21 21:34:05.550084');
/*!40000 ALTER TABLE `django_session` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Editora`
--

DROP TABLE IF EXISTS `Editora`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
 SET character_set_client = utf8mb4 ;
CREATE TABLE `Editora` (
  `pk_codigo` int(11) NOT NULL AUTO_INCREMENT,
  `nome` varchar(80) DEFAULT NULL,
  `contato` int(11) DEFAULT NULL,
  `cnpj` varchar(15) DEFAULT NULL,
  PRIMARY KEY (`pk_codigo`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Editora`
--

LOCK TABLES `Editora` WRITE;
/*!40000 ALTER TABLE `Editora` DISABLE KEYS */;
INSERT INTO `Editora` VALUES (1,'Vale',1,'111'),(2,'Saraiva',2,'112'),(3,'Net',3,'113'),(4,'Chamec',4,'114');
/*!40000 ALTER TABLE `Editora` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Emprestimo`
--

DROP TABLE IF EXISTS `Emprestimo`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
 SET character_set_client = utf8mb4 ;
CREATE TABLE `Emprestimo` (
  `pk_codigo` int(11) NOT NULL AUTO_INCREMENT,
  `fk_cod_exemp` int(11) DEFAULT NULL,
  `fk_id_usuario` int(11) DEFAULT NULL,
  `fk_id_bibliotecario` int(11) DEFAULT NULL,
  `data_retirada` date DEFAULT NULL,
  `data_limite_devolucao` date DEFAULT NULL,
  PRIMARY KEY (`pk_codigo`),
  KEY `fk_cod_exemp` (`fk_cod_exemp`),
  KEY `fk_id_usuario` (`fk_id_usuario`),
  KEY `fk_id_bibliotecario` (`fk_id_bibliotecario`),
  CONSTRAINT `emprestimo_ibfk_1` FOREIGN KEY (`fk_cod_exemp`) REFERENCES `exemplar` (`pk_cod_exemp`) ON UPDATE CASCADE,
  CONSTRAINT `emprestimo_ibfk_2` FOREIGN KEY (`fk_id_usuario`) REFERENCES `usuario` (`pk_id`) ON UPDATE CASCADE,
  CONSTRAINT `emprestimo_ibfk_3` FOREIGN KEY (`fk_id_bibliotecario`) REFERENCES `usuario` (`pk_id`) ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Emprestimo`
--

LOCK TABLES `Emprestimo` WRITE;
/*!40000 ALTER TABLE `Emprestimo` DISABLE KEYS */;
INSERT INTO `Emprestimo` VALUES (1,1,3,1,'2019-02-09','2019-07-21'),(2,7,3,2,'2019-02-09','2019-03-11'),(3,3,3,1,'2019-02-09','2019-03-11'),(4,7,4,1,'2019-06-23','2019-07-21');
/*!40000 ALTER TABLE `Emprestimo` ENABLE KEYS */;
UNLOCK TABLES;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
/*!50003 CREATE*/ /*!50017 DEFINER=`root`@`localhost`*/ /*!50003 TRIGGER `tg_calData` BEFORE INSERT ON `emprestimo` FOR EACH ROW Set New.data_limite_devolucao = DATE_ADD(New.data_retirada, INTERVAL 30 DAY) */;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
/*!50003 CREATE*/ /*!50017 DEFINER=`root`@`localhost`*/ /*!50003 TRIGGER `tg_emp` AFTER INSERT ON `emprestimo` FOR EACH ROW Update Livro as L set L.qtd_exemp = L.qtd_exemp-1 where ((SELECT E.fk_cod_livro FROM(Exemplar as E ) Where E.pk_cod_exemp=New.fk_cod_exemp)=L.pk_cod_livro) */;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
/*!50003 CREATE*/ /*!50017 DEFINER=`root`@`localhost`*/ /*!50003 TRIGGER `tg_exempSet0` AFTER INSERT ON `emprestimo` FOR EACH ROW Update Exemplar as E set E.disp = 0 where E.pk_cod_exemp = NEW.fk_cod_exemp */;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;

--
-- Table structure for table `Exemplar`
--

DROP TABLE IF EXISTS `Exemplar`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
 SET character_set_client = utf8mb4 ;
CREATE TABLE `Exemplar` (
  `pk_cod_exemp` int(11) NOT NULL AUTO_INCREMENT,
  `fk_cod_livro` int(11) DEFAULT NULL,
  `edicao` int(11) DEFAULT NULL,
  `ano` int(11) DEFAULT NULL,
  `estado` varchar(80) DEFAULT NULL,
  `disp` tinyint(1) DEFAULT NULL,
  PRIMARY KEY (`pk_cod_exemp`),
  KEY `fk_cod_livro` (`fk_cod_livro`),
  CONSTRAINT `exemplar_ibfk_1` FOREIGN KEY (`fk_cod_livro`) REFERENCES `livro` (`pk_cod_livro`) ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=29 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Exemplar`
--

LOCK TABLES `Exemplar` WRITE;
/*!40000 ALTER TABLE `Exemplar` DISABLE KEYS */;
INSERT INTO `Exemplar` VALUES (1,1,1,2019,'furo de bala',0),(2,2,1,2019,'da pra ler',1),(3,3,1,2019,'meio rasgado',1),(4,4,1,2019,'da pra ler',1),(5,5,1,2019,'da pra ler',1),(6,6,1,2019,'da pra ler',1),(7,7,1,2019,'da pra ler',0),(8,1,1,1980,'bom',1),(9,2,1,1990,'ruim',1),(10,3,1,2000,'otimo',1),(11,4,1,1998,'otimo',1),(12,5,1,1943,'otimo',1),(13,6,1,1950,'bom',1),(14,7,1,1988,'ruim',1),(15,1,1,1980,'bom',1),(16,2,1,1990,'ruim',1),(17,3,1,2000,'otimo',1),(18,4,1,1998,'otimo',1),(19,5,1,1943,'otimo',1),(20,6,1,1950,'bom',1),(21,7,1,1988,'ruim',1),(22,1,1,1980,'bom',1),(23,2,1,1990,'ruim',1),(24,3,1,2000,'otimo',1),(25,4,1,1998,'otimo',1),(26,5,1,1943,'otimo',1),(27,6,1,1950,'bom',1),(28,7,1,1988,'ruim',1);
/*!40000 ALTER TABLE `Exemplar` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `livro`
--

DROP TABLE IF EXISTS `livro`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
 SET character_set_client = utf8mb4 ;
CREATE TABLE `livro` (
  `pk_cod_livro` int(11) NOT NULL AUTO_INCREMENT,
  `titulo` varchar(200) DEFAULT NULL,
  `fk_id_autor` int(11) DEFAULT NULL,
  `fk_id_editora` int(11) DEFAULT NULL,
  `genero` varchar(80) DEFAULT NULL,
  `capa` varchar(500) DEFAULT NULL,
  `sumario` varchar(1000) DEFAULT NULL,
  `num_pags` int(11) DEFAULT NULL,
  `pais` varchar(80) DEFAULT NULL,
  `ano_publicacao` int(11) DEFAULT NULL,
  `qtd_exemp` int(11) DEFAULT NULL,
  `palavras_chave` varchar(80) DEFAULT NULL,
  PRIMARY KEY (`pk_cod_livro`),
  KEY `fk_id_autor` (`fk_id_autor`),
  KEY `fk_id_editora` (`fk_id_editora`),
  CONSTRAINT `livro_ibfk_1` FOREIGN KEY (`fk_id_autor`) REFERENCES `autor` (`pk_id_autor`) ON UPDATE CASCADE,
  CONSTRAINT `livro_ibfk_2` FOREIGN KEY (`fk_id_editora`) REFERENCES `editora` (`pk_codigo`) ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=8 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `livro`
--

LOCK TABLES `livro` WRITE;
/*!40000 ALTER TABLE `livro` DISABLE KEYS */;
INSERT INTO `livro` VALUES (1,'O Cortiço',1,1,'Romance Naturalista','http://2.bp.blogspot.com/-3pk7saw5dz4/TrfJzTpbPyI/AAAAAAAAAOA/dbyA6bm38_4/s1600/O+CORTI%25C3%2587O.jpg','O cenário do romance de Aluísio Azevedo é o cortiço São Romão, situado no Rio de Janeiro, durante o século XIX. O proprietário do estabelecimento é João Romão, um português que se muda para o Brasil em busca de uma vida melhor e consegue montar seu próprio estabelecimento.',354,'Brasil',1890,20,'Cortiço. Rio de Janeiro. classico. São Romão'),(2,'Dom Casmurro',2,2,'Realismo Psicológico','https://upload.wikimedia.org/wikipedia/commons/thumb/0/05/DomCasmurroMachadodeAssis.jpg/240px-DomCasmurroMachadodeAssis.jpg','Narrado com foco narrativo em primeira pessoa, seu personagem principal é o carioca de 54 anos Bento de Albuquerque Santiago, advogado solitário e bem-estabelecido que, após ter reproduzido tal qual, no Engenho Novo, a casa em que foi criado \"na antiga R. de Matacavalos\" (hoje Riachuelo), pretende \"atar as duas pontas da vida e resgatar na velhice a adolescência\".',354,'Brasil',1900,16,'Dom. Casmurro. Advogado. Imperadores. Romanos. Cesar'),(3,'Triste fim de Policarpo Quaresma',3,4,'Romance','https://www.paulus.com.br/loja/images/products/G/9788534940337.jpg','Buscando saídas políticas, econômicas e culturais para o Brasil, Policarpo passa grande parte de seu tempo enfiado nos livros, pelo que é criticado por parte da vizinhança que não consegue aceitar que alguém sem titulação acadêmica possa possuir livros - uma crítica ao academicismo, muito presente na obra de Lima Barreto - e que o critica ainda mais quando ele decide aprender a tocar um instrumento mal visto pela burguesa sociedade carioca da época, o violão, por considerá-lo um representante do espírito popular do país.',352,'Brasil',1915,25,'Policarpo. Crítica. Academicismo. Tragédia'),(4,'Perto do Coração Selvagem',6,3,'Romance','http://statics.livrariacultura.net.br/products/capas_lg/731/170731.jpg','Escrito quando Clarice Lispector tinha vinte anos de idade, o livro tem como protagonista Joana, que narra sua história em dois planos: sua infância e o início de sua vida adulta. A literatura brasileira era, naquela altura, dominada por uma tendência essencialmente regionalista, com personagens contando as dificuldades da realidade social do país na época. Lispector surpreendeu a crítica com seu romance.',202,'Brasil',1943,6,'Joana. Literatura. Regionalista. Dificuldade'),(5,'O Alienista',2,2,'Conto','https://upload.wikimedia.org/wikipedia/pt/thumb/c/c1/Resumo-do-livro-o-alienista-de-machado-de-assis.jpg/230px-Resumo-do-livro-o-alienista-de-machado-de-assis.jpg','Depois de conquistar respeito em sua carreira de médico na Europa e no Brasil, o Dr. Simão Bacamarte retorna à sua terra-natal, Itaguaí, para se dedicar ainda mais a sua profissão. Após um tempo na cidade, casa-se com a já viúva D. Evarista, uma mulher por volta dos vinte e cinco anos e que não era nem bonita e nem simpática. O médico a escolheu por julgá-la capaz de lhe gerar bons filhos e de pensar, que apesar de tal não ter acontecido, que ela tinha origem alienista, daí a origem do título , mas ela acaba não tendo nenhum.',39,'Brasil',1882,9,'Alienista. Médico. Europa. Simão'),(6,'São Bernardo',4,2,'romance','https://upload.wikimedia.org/wikipedia/pt/thumb/4/47/Sao-bernardo-graciliano-ramos-1-edico.jpg/230px-Sao-bernardo-graciliano-ramos-1-edico.jpg','A obra consiste na história de Paulo Honório, um homem simples mas ambicioso que acaba por se transformar num grande fazendeiro do sertão de Alagoas. Casa-se com Madalena para conseguir um herdeiro. Incapaz de entender a forma humanitária pela qual a mulher vê o mundo, ele tenta anulá-la com seu autoritarismo.',272,'Brasil',1934,1,'Graciliano.romance.bernardo.Alagoas.Madalena'),(7,'A Hora da Estrela',6,1,'romance','https://upload.wikimedia.org/wikipedia/pt/thumb/c/ce/A_Hora_da_Estrela.jpg/230px-A_Hora_da_Estrela.jpg','A Hora da Estrela é um romance literário da escritora brasileira Clarice Lispector. O romance narra a história da datilógrafa alagoana, Macabéa, que migra para o Rio de Janeiro, tendo sua rotina narrada por um escritor fictício chamado Rodrigo S.M.',87,'Brasil',1977,0,'Clarice.Estrela.romance.Macabéa.Rio de Janeiro');
/*!40000 ALTER TABLE `livro` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Login`
--

DROP TABLE IF EXISTS `Login`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
 SET character_set_client = utf8mb4 ;
CREATE TABLE `Login` (
  `pk_email` varchar(100) NOT NULL,
  `senha` varchar(40) DEFAULT NULL,
  `nivel` tinyint(1) DEFAULT NULL,
  PRIMARY KEY (`pk_email`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Login`
--

LOCK TABLES `Login` WRITE;
/*!40000 ALTER TABLE `Login` DISABLE KEYS */;
INSERT INTO `Login` VALUES ('alan@hotmail.com','1234',1),('aluno@hotmail.com','123',0),('arimateia@hotmail.com','1234',1),('douglas@hotmail.com','azul',0);
/*!40000 ALTER TABLE `Login` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Reserva`
--

DROP TABLE IF EXISTS `Reserva`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
 SET character_set_client = utf8mb4 ;
CREATE TABLE `Reserva` (
  `pk_codigo` int(11) NOT NULL AUTO_INCREMENT,
  `fk_id_usuario` int(11) DEFAULT NULL,
  `fk_cod_livro` int(11) DEFAULT NULL,
  `data_limite` date DEFAULT NULL,
  `disponivel` tinyint(1) DEFAULT NULL,
  PRIMARY KEY (`pk_codigo`),
  KEY `fk_id_usuario` (`fk_id_usuario`),
  KEY `fk_cod_livro` (`fk_cod_livro`),
  CONSTRAINT `reserva_ibfk_1` FOREIGN KEY (`fk_id_usuario`) REFERENCES `usuario` (`pk_id`) ON UPDATE CASCADE,
  CONSTRAINT `reserva_ibfk_2` FOREIGN KEY (`fk_cod_livro`) REFERENCES `livro` (`pk_cod_livro`) ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=8 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Reserva`
--

LOCK TABLES `Reserva` WRITE;
/*!40000 ALTER TABLE `Reserva` DISABLE KEYS */;
INSERT INTO `Reserva` VALUES (3,3,3,'2019-06-23',1);
/*!40000 ALTER TABLE `Reserva` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Usuario`
--

DROP TABLE IF EXISTS `Usuario`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
 SET character_set_client = utf8mb4 ;
CREATE TABLE `Usuario` (
  `pk_id` int(11) NOT NULL AUTO_INCREMENT,
  `nome` varchar(80) DEFAULT NULL,
  `cpf` varchar(15) DEFAULT NULL,
  `rg` varchar(15) DEFAULT NULL,
  `fk_email` varchar(100) DEFAULT NULL,
  `fk_contato` int(11) DEFAULT NULL,
  `foto` varchar(500) DEFAULT NULL,
  `limite_livro` int(11) DEFAULT NULL,
  PRIMARY KEY (`pk_id`),
  KEY `fk_contato` (`fk_contato`),
  KEY `fk_email` (`fk_email`),
  CONSTRAINT `usuario_ibfk_1` FOREIGN KEY (`fk_contato`) REFERENCES `contato` (`pk_contato`) ON UPDATE CASCADE,
  CONSTRAINT `usuario_ibfk_2` FOREIGN KEY (`fk_email`) REFERENCES `login` (`pk_email`) ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Usuario`
--

LOCK TABLES `Usuario` WRITE;
/*!40000 ALTER TABLE `Usuario` DISABLE KEYS */;
INSERT INTO `Usuario` VALUES (1,'Arimateia','12345678911','123456789123','arimateia@hotmail.com',1,'foto',9999),(2,'Alan','12345678912','123456789124','alan@hotmail.com',2,'foto',9999),(3,'Douglas','12345678913','123456789125','douglas@hotmail.com',3,'foto',10),(4,'aluno','9898779879','98797987','aluno@hotmail.com',1,'link_foto',10);
/*!40000 ALTER TABLE `Usuario` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2019-06-21 21:59:32
