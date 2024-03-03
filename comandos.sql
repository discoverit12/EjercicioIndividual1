DROP DATABASE IF EXISTS Bd;
CREATE DATABASE Bd;
USE Bd;


CREATE TABLE Jugador (
					  id INTEGER PRIMARY KEY NOT NULL, 
					  nombre TEXT NOT NULL,
					  contraseña TEXT NOT NULL
					  )ENGINE = InnoDB;

CREATE TABLE Puntos (
					 id INTEGER PRIMARY KEY NOT NULL, 
					 puntos INTEGER NOT NULL
					 )ENGINE = InnoDB;

CREATE TABLE Partida (
					  id INTEGER PRIMARY KEY NOT NULL, 
					  id_p INTEGER NOT NULL, 
					  id_j INTEGER NOT NULL,
					  fechayhora INTEGER NOT NULL,
					  duracion INTEGER NOT NULL,
					  Puntos_g INTEGER NOT NULL,
					  FOREIGN KEY (id_p) REFERENCES Puntos(id),
					  FOREIGN KEY (id_j) REFERENCES Jugador(id)
					  )ENGINE = InnoDB;


INSERT INTO Jugador VALUES(1, 'AlexCaptain', 'pocosegura');
INSERT INTO Jugador VALUES(2, 'MrSamurott', 'algosegura');
INSERT INTO Jugador VALUES(3, 'MaikelDeCervantes', 'segura');
INSERT INTO Jugador VALUES(4, 'ElCrochete', 'muysegura');

INSERT INTO Puntos VALUES(1, 55);
INSERT INTO Puntos VALUES(2, 69);
INSERT INTO Puntos VALUES(3, 40);
INSERT INTO Puntos VALUES(4, 20);

INSERT INTO Partida VALUES(1,1,1,141501022024,5,55);
INSERT INTO Partida VALUES(1,2,1,173001022024,10,54);
INSERT INTO Partida VALUES(1,3,2,123301032024,15,69);
