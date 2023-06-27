#include "ws2812.pio.h"
#include "pico/time.h"

void main() {
    ws2812_program_init
        (pio0
        ,0 /* use state machine 0 */
        ,pio_add_program(pio0, &ws2812_program)
        ,PICO_DEFAULT_WS2812_PIN
        ,800*1000
        ,false
        );

    /* Turn on the LED */
    gpio_init(PICO_DEFAULT_WS2812_POWER_PIN);
    gpio_set_dir(PICO_DEFAULT_WS2812_POWER_PIN, GPIO_OUT);
    gpio_put(PICO_DEFAULT_WS2812_POWER_PIN, 1);

    while (true) {
        pio_sm_put_blocking(pio0, 0, 0xFFFF0000); /* Green + Red */
        sleep_ms(1000);

        pio_sm_put_blocking(pio0, 0, 0x00FFFF00); /* Red + Blue */
        sleep_ms(1000);
    }
}
