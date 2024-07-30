Este es un proyecto creado por estudiantes de Ingeniería Electrónica para el final de la materia "Técnicas Digitales 2". El proyecto es un sistema de control de nivel de gas y de nivel de un tanque de agua usando el microcontrolador programable PSoC 5.

Para el sistema de control de gas utilizamos un sensor MQ2, el cual detecta el nivel de gas en el ambiente. Cuando dicho nivel sobrepasa una determinada cantidad, se activa un servomotor que simula una válvula que se cierra para impedir que el gas siga fluyendo y, a su 
vez, se activa un cooler para la ventilación que disipará dicho gas. Este sensor se utiliza como pin de entrada analógica, convirtiendo los valores detectados de analógicos a digitales a través de un ADC en el PSoC.

Para el sistema de control de nivel de agua utilizamos dos sensores de nivel de agua configurados como pines de entrada digital. Uno se utiliza para detectar el nivel mínimo, mientras que el otro para detectar el nivel máximo del tanque. La condición en la programación 
de estos sensores es: cuando los dos detectan simultáneamente, es decir, que el tanque se encuentra entre estos valores, la bomba de agua permanece apagada. Adicionalmente, cuando el sensor de nivel máximo detecta, nos da un aviso de que el tanque se encuentra lleno, 
mientras que cuando detecta el sensor de nivel mínimo nos avisa que el tanque se encuentra por encima de dicho valor. Si el tanque está por debajo del nivel mínimo, la bomba se activa y "carga" el tanque hasta su nivel máximo.

Los valores de gas, junto con la información, se transmiten e imprimen a tiempo real en una pantalla LCD con módulo de interfaz I2C.

También utilizamos un módulo Bluetooth HC-05, mediante el cual conectamos a nuestro PSoC usando comunicación serie UART, y podemos enviar instrucciones desde algún dispositivo, como por ejemplo nuestro celular. Dependiendo de la instrucción que enviemos, podremos 
activar o desactivar la ventilación y la bomba de agua, abrir o cerrar la válvula, e imprimir la información en la pantalla.
