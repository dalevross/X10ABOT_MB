//#include "Actuator.h"
#include "X10ABOT_MB.h"
/**
 * Actuator Constructor
 *
 * @param  byte db_address   Sets the  daughterboard's address
 * @param  byte port_number  Sets the  port_number on the daughterboard specified
 */
//Actuator::Actuator(byte db_address, byte port_number)

/**
 * Actuator Constructor
 *
 * @param  byte db_address  Sets the  daughterboard's address
 * @param  byte port_number  Sets the  port_number on the daughterboard specified
 * @param  byte port_number  Selects either pin A(0) or B(1) on the selected port
 */
/*Actuator::Actuator(byte db_address, byte port_number, byte pin_select){
    _db = db_address;
    _port = port_number;
    _pin = pin_select;
}
*/
/**
 * Actuator Destructor
 * no params
 */
Actuator::~Actuator(){
  /*nothing to destruct*/
}

X10ABOT_MB actuator(LOGGING);

/**
 * Actuator run
 *
 * @param  byte power  Drives the actuator in the negative or positive direction based on the power level. It operates btween -100 and +100.
 */

void Actuator::run(byte power){
  if (power>100)
  {
    power=100;
  }else if (power<(-100))
  {
    power = -100;
  }

  if (power>0)
  {
    actuator.pwm(A, _db, _port, 255*power/100);
    actuator.digital(HI,_db,_port,A);
    actuator.digital(LO,_db,_port,B);
  }
  else{
    actuator.pwm(A, _db, _port, 255*power/100);
    actuator.digital(LO,_db,_port,A);
    actuator.digital(HI,_db,_port,B);
  }
}

void Actuator::on(byte power){
  actuator.digital(HI,_db,_port,A);
  actuator.digital(HI,_db,_port,B);
}

void Actuator::on(){
  Serial.println("Motor ON!");
  actuator.digital(HI,_db,_port,A);
  actuator.digital(HI,_db,_port,B);
}

void Actuator::off(){
  actuator.digital(LO,_db,_port,A);
  actuator.digital(LO,_db,_port,B);
}

void Actuator::on_a(byte power){
  actuator.digital(HI,_db,_port,A);
}

void Actuator::off_a(){
  actuator.digital(LO,_db,_port,A);
}

void Actuator::on_b(byte power){
  actuator.digital(HI,_db,_port,B);
}

void Actuator::off_b(){
  actuator.digital(LO,_db,_port,B);
}

void Actuator::stop(){
  actuator.digital(LO,_db,_port,B);
  delay(100);
  actuator.digital(HI,_db,_port,B);
  delay(100);
}
