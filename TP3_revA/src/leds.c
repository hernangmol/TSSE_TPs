/*============================================================================
 * Testing de software en sistemas embebidos
 * Trabajo práctico n° 3
 * Archivo: leds.c
 * Fecha 13/11/2021
 * Alumno: Hernán Gomez Molino
 *===========================================================================*/

#include "leds.h"
#include "errores.h"

#define LEDS_ALL_OFF    0x0000
#define LEDS_ALL_ON     0xFFFF
#define LEDS_OFFSET     1
#define LED_ON_STATE    1
#define LED_OFF_STATE   0 

static uint16_t *puerto;

uint16_t LedToMask(int led)
{
    return(LED_ON_STATE << (led-LEDS_OFFSET));
}

void LedsCreate(uint16_t * direccion)
{
    puerto = direccion;
    *direccion = LEDS_ALL_OFF;
}

void LedsOn(int led)
{
    if ((led >= 1) && (led <= 16))
    {
       *puerto |= LedToMask(led);
    }
    else
    {
        RegistrarMensaje(0,__FUNCTION__, __LINE__, "Numero de led invalido");   
    }
    
}

void LedsOff(int led)
{
    *puerto &= ~LedToMask(led);
}

void LedsAllOn(uint16_t * puerto)
{
    *puerto = LEDS_ALL_ON;
}

void LedsAllOff(uint16_t * puerto)
{
    *puerto = LEDS_ALL_OFF;
}

int LedsStatus(int led)
{
    if((*puerto && LedToMask(led)) == 0)
    {
        return(LED_OFF_STATE);
    }
    else
    {
        return(LED_ON_STATE);
    }
    
} 