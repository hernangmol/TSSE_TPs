/*============================================================================
 * Testing de software en sistemas embebidos
 * Trabajo práctico n° 3
 * Archivo: leds.h
 * Fecha 13/11/2021
 * Alumno: Hernán Gomez Molino
 *===========================================================================*/ 

#include <stdint.h>

void LedsCreate(uint16_t * puerto);

void LedsOn(int led);

void LedsOff(int led);

void LedsAllOn(uint16_t * puerto);

void LedsAllOff(uint16_t * puerto);

int LedsStatus(int led);