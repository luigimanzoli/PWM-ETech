#include <stdio.h> //biblioteca padrão da linguagem C
#include "pico/stdlib.h" //subconjunto central de bibliotecas do SDK Pico
#include "hardware/pwm.h" //biblioteca para controlar o hardware de PWM

#define PWM_LED 22 //pino do LED conectado a GPIO como PWM

const uint16_t WRAP_PERIOD = 49999; //valor máximo do contador - WRAP
const float PWM_DIVISER = 50.0; //divisor do clock para o PWM
const uint16_t LED_STEP = 5000; //passo de incremento/decremento para o duty cycle do LED
uint16_t led_level = 2000; //nível inicial do pwm (duty cycle)

//função para configurar o módulo PWM
void pwm_setup()
{
    gpio_set_function(PWM_LED, GPIO_FUNC_PWM); //habilitar o pino GPIO como PWM

    uint slice = pwm_gpio_to_slice_num(PWM_LED); //obter o canal PWM da GPIO

    pwm_set_clkdiv(slice, PWM_DIVISER); //define o divisor de clock do PWM

    pwm_set_wrap(slice, WRAP_PERIOD); //definir o valor de wrap

    pwm_set_gpio_level(PWM_LED, 100); //definir o cico de trabalho (duty cycle) do pwm

    pwm_set_enabled(slice, true); //habilita o pwm no slice correspondente

    int freqPWM = 125000000/((PWM_DIVISER)*(WRAP_PERIOD+1));

    printf("fPWM = %i Hz\n", freqPWM);
}


//função principal
int main()
{
    stdio_init_all(); //inicializa o sistema padrão de I/O
    
    pwm_setup(); //configura o PWM

    printf("Sistema inicializado.\n");

    uint up_down = 1; //variável para controlar se o nível do LED aumenta ou diminui

    while (true) {

        printf("Ciclo ativo:%d\n", led_level);//imprimir ciclo ativo do PWM - valor máximo é 2000
        
        pwm_set_gpio_level(PWM_LED, led_level); //define o nível atual do PWM (duty cycle)

        sleep_ms(100); // Atraso de 1 segundo

        if (up_down) 
        {
            led_level += LED_STEP; // Incrementa o nível do LED
            if (led_level >= WRAP_PERIOD)
                up_down = 0; // Muda direção para diminuir quando atingir o período máximo
        }
        else
        {
            led_level -= LED_STEP; // Decrementa o nível do LED
            if (led_level <= LED_STEP)
                up_down = 1; // Muda direção para aumentar quando atingir o mínimo
        }

    }
}
