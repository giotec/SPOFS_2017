/*
 * Light.h
 *
 *  Created on: Apr 10, 2016
 *      Author: Stuff
 */

#ifndef LIGHT_H_
#define LIGHT_H_

class Light {
public:
	Light(uint8_t group, uint8_t bit);
	~Light();

	uint8_t GetBit() { return _GPIOBit; }
	uint8_t GetGroup() { return _GPIOGroup; }

	void On();
	void Off();

private:
	const uint8_t _GPIOBit;
	const uint8_t _GPIOGroup;
};

#endif /* LIGHT_H_ */
