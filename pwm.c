#include <stdio.h> //biblioteca padrão da linguagem C
#include "pico/stdlib.h" //subconjunto central de bibliotecas do SDK Pico
#include "hardware/pwm.h" //biblioteca para controlar o hardware de PWM

#define PWM_LED 22 //pino do LED conectado a GPIO como PWM

const uint16_t WRAP_PERIOD = 50000; //valor máximo do contador - WRAP
const float PWM_DIVISER = 50.0; //divisor do clock para o PWM
const uint16_t LED_STEP = 5000; //passo de incremento/decremento para o duty cycle do LED

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

    printf("Duty Cicle definido para 12%%.\n");
    pwm_set_gpio_level(PWM_LED, 6000); // Definindo o duty cicle de 12%

    sleep_ms(1000); // Atraso de 5 segundos

    printf("Duty Cicle definido para 7.35%%.\n");
    pwm_set_gpio_level(PWM_LED, 3675); // Definindo o duty cicle de 7.35%

    sleep_ms(1000); // Atraso de 5 segundos

    printf("Duty Cicle definido para 2.5%%.\n");
    pwm_set_gpio_level(PWM_LED, 1250); // Definindo o duty cicle de 2.5%

    sleep_ms(1000); // Atraso de 5 segundos

    printf("Variação do Duty Cicle de 2.5%% até 12%%.\n");

    double level = 1250;
    int control = 1;

    while (true) {

        if (control == 1){
            pwm_set_gpio_level(PWM_LED, level);
            level = level + 4.75;
            sleep_ms(1);
            
            if (level == 6000){
                control = 0;
            }
        }
        else if (control == 0){
            pwm_set_gpio_level(PWM_LED, level);
            level = level - 4.75;
            sleep_ms(1);

            if (level == 1250){
                control = 1;
            }
        }
    }
}
