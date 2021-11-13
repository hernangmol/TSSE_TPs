/*============================================================================
 * Testing de software en sistemas embebidos
 * Trabajo práctico n° 3
 * Archivo: test_leds.c
 * Fecha 13/11/2021
 * Alumno: Hernán Gomez Molino
 *===========================================================================*/

#include "unity.h"
#include "leds.h"
#include "mock_errores.h" 

#define LED 3
#define LED_BIT(x) (1<<(x-1))

static uint16_t puertoVirtual;

void setUp(void)
{
    LedsCreate(&puertoVirtual);
}

/* Despues de la configuración todos los leds deben quedar apagados _______EN CLASE*/
void test_todos_los_leds_inician_apagados(void)
{
    uint16_t puertoVirtual= 0xFFFF;
    LedsCreate(&puertoVirtual);
    TEST_ASSERT_EQUAL_HEX16(0x0000, puertoVirtual);
}

/* Prender un led cualquiera _______EN CLASE*/
void test_prender_led(void)
{
    LedsOn(LED);
    TEST_ASSERT_EQUAL_HEX16(LED_BIT(LED),puertoVirtual);
}

/* Apagar un led cualquiera _______EN CLASE*/
void test_apagar_led(void)
{
    LedsOn(LED);
    LedsOff(LED);
    TEST_ASSERT_EQUAL_HEX16(0x0000,puertoVirtual);
}

/* Prender y apagar algunos leds _______EN CLASE*/
void test_prender_apagar_varios(void)
{
    LedsOn(LED);
    LedsOn(LED + 3);
    LedsOff(LED); 
    TEST_ASSERT_EQUAL_HEX16(LED_BIT(LED + 3),puertoVirtual);
}

/* Probar valores inválidos para los parámetros _______EN CLASE*/ 
void test_valores_invalidos(void)
{
    RegistrarMensaje_Expect(0,"LedsOn",0,"Numero de led invalido");
    RegistrarMensaje_IgnoreArg_linea();
    LedsOn(17);
}

/* Prender todos los leds juntos _____ENTREGA*/
void test_prender_todos_los_leds(void)
{
    LedsAllOn(&puertoVirtual);
    TEST_ASSERT_EQUAL_HEX16(0xFFFF,puertoVirtual);
}

/* Apagar todos los leds juntos _____ENTREGA*/
void test_apagar_todos_los_leds(void)
{
    LedsAllOn(&puertoVirtual);
    LedsAllOff(&puertoVirtual);
    TEST_ASSERT_EQUAL_HEX16(0x0000,puertoVirtual);
}

/* Consultar el estado de un led apagado ____ENTREGA*/
void test_chequear_estado_led_apagado(void)
{
    LedsOff(LED);
    TEST_ASSERT_EQUAL(0, LedsStatus(LED));
}

/* Consultar el estado de un led encendido ____ENTREGA*/
void test_chequear_estado_led_encendido(void)
{
    LedsOn(LED);
    TEST_ASSERT_EQUAL(1, LedsStatus(LED));
}

/* La consulta no modifica estado____AGREGADA POR MI*/ 
void test_consulta_no_modifica_estado(void)
{
    LedsOn(LED);
    LedsStatus(LED);
    TEST_ASSERT_EQUAL_HEX16(LED_BIT(LED),puertoVirtual);
}