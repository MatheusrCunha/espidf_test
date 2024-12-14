#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

// Define o pino onde o LED está conectado
#define LED_PIN 2

void app_main(void) {
    // Configura o pino como saída
    gpio_config_t io_conf = {
        .pin_bit_mask = (1ULL << LED_PIN), // Máscara do pino
        .mode = GPIO_MODE_OUTPUT,         // Modo de saída
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .pull_up_en = GPIO_PULLUP_DISABLE,
        .intr_type = GPIO_INTR_DISABLE    // Sem interrupção
    };
    gpio_config(&io_conf);

    while (1) {
        // Liga o LED
        gpio_set_level(LED_PIN, 1);
        vTaskDelay(500 / portTICK_PERIOD_MS); // Espera 500 ms

        // Desliga o LED
        gpio_set_level(LED_PIN, 0);
        vTaskDelay(500 / portTICK_PERIOD_MS); // Espera 500 ms
    }
}
