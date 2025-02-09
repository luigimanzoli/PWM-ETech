#  EmbarcaTech - PWM


##  Materiais utilizados:

  

Neste projeto, são utilizados os seguintes componentes conectados:

- Dentro do Simulador Wokwi:

    - Servo Motor, sendo conectado ao pino 22.

- À placa BitDogLab:
  
    - LED Azul, com os pinos conectados a GPIO 12.

##  Funcionalidades Implementadas:

1) Definição da frequência de PWM para, aproximadamente, 50Hz – período de 20ms.

2) Ciclo ativo do módulo PWM definido para 2.400µs (microssegundos) – Ciclo de Trabalho (Duty Cycle) de 0,12%. isto
ajustará a flange (braço) do servomotor para a posição de, aproximadamente, 180 graus. (Intervalo de 5 segundos)

3) Ciclo ativo do módulo PWM definido para 1.470µs (microssegundos) – Ciclo de Trabalho (Duty Cycle) de 0,0735%. Isto ajustará a flange do servomotor para a posição de, aproximadamente, 90 graus. (Intervalo de 5 segundos)

4) Ciclo ativo do módulo PWM definido para 500µs (microssegundos) – Ciclo de Trabalho (Duty Cycle) de 0,025%.Isto ajustará a flange do servomotor para a posição de, aproximadamente, 0 graus. Aguarde 05 segundos nesta posição. (10% da nota)

5) Rotina de movimentação periódica do braço do servomotor entre os ângulos de 0 e 180 graus.

##  Tecnologias:

  
1. Git e Github;

2. VScode;

3. Linguagem C;

4. Simulador Wokwi;


##  Desenvolvedor:
**Luigi Manzoli Almeida Lopez**

  

##  Demonstração: https://youtube.com/shorts/J5A3JAwwOYg