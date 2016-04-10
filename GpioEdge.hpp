#ifndef GPIOEDGE_HPP_
#define GPIOEDGE_HPP_

#include <mraa/gpio.h>
#include <unistd.h>
#include <iostream>

/**
 * @brief API pour le GPIO en mode input
 */
class GpioEdge {
public:

	/**
	 * Initialiser le GPIO
	 * Mode: input, interruption en front descendant
	 * Note: d'après la documentation du fabriquant, l'interruption ne marche qu'en mode MRAA_GPIO_BOTH_EDGE
	 * mais la carte ne détecte que les fronts descendants
	 *
	 * @param le pin qui reçoit du signal
	 */
	GpioEdge(int pin);

	/**
	 * Assesseur de l'instance state, qui change à chaque fois un front descendant détecté
	 *
	 * @param  aucun
	 * @return bool l'état courant de l'instance state
	 */
	bool getState();

	/**
	 * Lire la valeur du GPIO
	 *
	 * @param  aucun
	 * @return la valeur du GPIO, soit 0 soit 1, la valeur -1 signifie une erreur fatale
	 */
	int read();

	/**
	 * Destructeur
	 */
	~GpioEdge();

private:
	mraa_gpio_context myTouch;

	/**
	 * La fonction statique qui sera être appelée lorsqu'il y a un évennement détecté
	 * Cette fonction va changer l'état courant state
	 *
	 * @param  un pointeur de vers un objet de type quelconque
	 * @return void
	 */
	static void edgeDetect(void* ctx);
	bool state;
};

#endif /* GPIOEDGE_HPP_ */
