/*
 * ButtonCol.h
 *
 *  Created on: Dec 18, 2015
 *      Author: Stuff
 */

#ifndef BUTTONCOL_H_
#define BUTTONCOL_H_

class ButtonCol {
public:
  ButtonCol(int8_t* Btns[2], unsigned int ButtonCount);
  virtual ~ButtonCol();

private:
  Button *Buttons;
};

#endif /* BUTTONCOL_H_ */
