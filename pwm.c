#include <stdio.h> 
#include "pico/stdlib.h" 
#include "hardware/pwm.h" 

#define PWM_LED 22 // Pino que será configurado como PWM. 22 - Servo (Simulação WokWi); 12 - LED (Placa BitDogLab);

const uint16_t WRAP_PERIOD = 50000;     // Valor do WRAP - máxima contagem
const float PWM_DIVISER = 50.0;         // Divisor do clock

// Configuração do PWM
void pwm_setup()
{
    gpio_set_function(PWM_LED, GPIO_FUNC_PWM);      // Função para habilitar o pino escolhido como PWM

    uint slice = pwm_gpio_to_slice_num(PWM_LED);    // Obtenção do canal PWM - Slice

    pwm_set_clkdiv(slice, PWM_DIVISER);             // Definindo o divisor para o slice

    pwm_set_wrap(slice, WRAP_PERIOD);               // Definindo o valor do contador

    pwm_set_enabled(slice, true);                   // Habilitando o PWM no slice

    int freqPWM = 125000000/((PWM_DIVISER)*(WRAP_PERIOD)); // Calculando o valor da frequência do PWM

    printf("Frequência do PWM = %i Hz\n", freqPWM); // Imprimindo o valor da frequência
}

int main()
{
    stdio_init_all();
    
    pwm_setup();

    printf("Sistema inicializado.\n");

    printf("Duty Cicle definido para 12%%.\n");
    pwm_set_gpio_level(PWM_LED, 6000); // Definindo o duty cicle de 12%

    sleep_ms(5000); // Atraso de 5 segundos

    printf("Duty Cicle definido para 7.35%%.\n");
    pwm_set_gpio_level(PWM_LED, 3675); // Definindo o duty cicle de 7.35%

    sleep_ms(5000); // Atraso de 5 segundos

    printf("Duty Cicle definido para 2.5%%.\n");
    pwm_set_gpio_level(PWM_LED, 1250); // Definindo o duty cicle de 2.5%

    sleep_ms(5000); // Atraso de 5 segundos

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
