#pragma once

#ifndef LCD_HPP_
#define LCD_HPP_

#include <mraa/i2c.h>
#include <unistd.h>
#include <iostream>
#include <string>

// définir les adresses nécessaire à accéder par le bus I2C
#define DEFAULT_I2C_BUS			0

#define LCD_CTRL_ADR			0x3E
#define RGB_CTRL_ADR			0x62

#define LCD_CLEARDISPLAY 		0x01
#define LCD_ENTRYMODESET 		0x04
#define LCD_FUNCTIONSET 		0x20
#define LCD_DATA 				0x40
#define LCD_CMD 				0x80
#define LCD_DISPLAYCONTROL 		0x08
#define LCD_DISPLAYON 			0x04

#define LCD_ENTRYLEFT 			0x02
#define LCD_ENTRYSHIFTDECREMENT 0x00

#define LCD_2LINE 				0x08

/**
 * @brief API pour l'afficheur LCD
 * Fonctionnements: écrire un message à une position sélectionnée, choisir la couleur du fond
 */
class Lcd {
public:

	/**
	 * Constructeur qui initialise l'affichage des caratères et la couleur du fond
	 */
	Lcd();

	/**
	 * Destructeur
	 */
	~Lcd();

	/**
	 * Ecrire un message en position courante du cursor
	 *
	 * @param  le message à écrire, type String
	 * @return void
	 */
	void writeMsg(std::string msg);

	/**
	 * Changer la couleur du fond, type RGB
	 *
	 * @param  r la valeur du rouge
	 * @param  g la valeur du vert
	 * @param  b la valeur du bleu
	 * @return void
	 */
	void setColor(int r, int g, int b);

	/**
	 * Changer la position du cursor, col de gauche à droit, row de bas à haut
	 *
	 * @param  row la ligne
	 * @param  col la colonne
	 * @return void
	 */
	void setPos(int row, int col);

	/**
	 * Activer/Désactiver l'affichage
	 *
	 * @param  val si vrai, activer l'affichage et si faux, le désactiver
	 * @return void
	 */
	void display(bool val);
private:
	mraa_i2c_context myLcd;
	mraa_i2c_context myRgb;

	/**
	 * Ecrire une commande vers le module
	 *
	 * @param  ctx le contexte i2c à écrire
	 * @param  val la valeur à écrire
	 * @return void
 	 */
	void writeCmd(mraa_i2c_context ctx, uint8_t val);

	/**
	 * Ecrire un data vers le module
	 *
	 * @param  ctx le contexte i2c à écrire
	 * @param  val la valeur à écrire
	 * @return void
 	 */
	void writeData(mraa_i2c_context ctx, uint8_t val);

	/**
	 * Ecrire au registre
	 *
	 * @param  ctx le contexte i2c à écrire
	 * @param  devAdr l'adresse du dispositif
	 * @param  adr adresse du registre
	 * @param  val la valeur à écrire
	 * @return void
 	 */
	void writeReg(mraa_i2c_context ctx, int devAdr, uint8_t adr, uint8_t val);
};

#endif /* LCD_HPP_ */
