CREATE DATABASE Lab7;
USE Lab7;

CREATE TABLE User(
	userID INT(11) PRIMARY KEY NOT NULL AUTO_INCREMENT,
	username VARCHAR(255) NOT NULL,
	password VARCHAR(255) NOT NULL,
	winNum INT(11) NOT NULL,
	loseNum INT(11) NOT NULL
);

INSERT INTO User (username, password, winNum, loseNum) VALUES ('Xiaoyang', 'Qiao', 5, 0);
INSERT INTO User (username, password, winNum, loseNum) VALUES ('123', '123', 0, 0);
INSERT INTO User (username, password, winNum, loseNum) VALUES ('1234', '1234', 3, 0);