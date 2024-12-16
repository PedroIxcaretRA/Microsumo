# PCB
Obtener una PCB funcional para cualquier prototipo que estés desarrollando puede ser una tarea significativa, ya que requiere tiempo, investigación y numerosas pruebas. Estar seguro de que el prototipo que tienes será el último antes de mandarlo a fabricar es crucial. Es por eso que en esta sección del repositorio, te comparto una opción viable que podrías considerar a la hora de realizar un microsumo.

## Tabla de Contenidos
1. [Descripción](#descripción)
2. [Esquemático](#esquemático)
3. [PCB MOCteam](#pcb-mocteam)
   1. [PINOUT](#pinout)

## Descripción
Como mencioné anteriormente, esta es una tarea significativa. Si logras encontrar una PCB comercial, el proceso será mucho más sencillo, ya que alguien más habrá realizado este trabajo por ti.

En caso de que no tengas acceso a una, aquí te comparto una PCB diseñada específicamente para este propósito. Sus dimensiones son 45 mm x 25 mm, lo que la hace perfecta para las especificaciones de un microsumo. Esta PCB fue diseñada en EasyEDA, y puedes cargar el archivo Gerber en el servicio de JLCPCB para su fabricación.

Es muy posible que cuando encuentres este repositorio, ya sea por un video, una investigación o cualquier otro medio, no tengas acceso a los componentes necesarios. Por ello, aquí incluyo una sección del esquemático para que puedas replicar la PCB.

Si eres nuevo en este mundo, lo más probable es que debas investigar y buscar los componentes que utilizarás. Aunque no es un proceso complicado, puede resultar algo tedioso. Mi recomendación es que utilices componentes con medidas 0603, ya que tienen un tamaño ideal para soldar con cautín, en caso de que no cuentes con una estación de soldadura.

En cuanto a proveedores, te sugiero LCSC Electronics, que forma parte de JLCPCB, o también Aliexpress como alternativa.

Si no tienes experiencia soldando PCBs, te recomiendo tomarlo con calma y tener paciencia. Soldar requiere práctica, pero es algo que se puede aprender desde cero. Personalmente, todas mis PCBs las he ensamblado usando únicamente un cautín RADOX, y ha funcionado perfectamente. 

Por ultimo, la placa tiene como mCU un Atmega328p-au por lo que puedes programar usando el IDE de Arduino. En la sección de código explico sobre como cargar el programa usando un Arduino nano.

**Nota: Si usas cautín, te recomiendo tener malla desoldadora de cobre.**

**Nota: El esquematico pdf y el gerber son diferentes pero es basicamente lo mismo**

## Esquemático

[***Los componentes se encuentran en el BOOM***](BOM_Microsumo_30_11_2024_2024-12-15.csv)

[***Archivo completo en el PDF Schematic_Microsumo***](Schematic_Microsumo_30_11_2024_2024-12-15.pdf)

En la primera parte, tenemos dos headers que nos servirán para la conexión de las baterías (batería de Li-ion 3.7V a 140mAh) y el interruptor. Al momento de diseñar la PCB, sugiero que estos headers estén lo más cerca posible, ya que se requiere un jumper para la suma de voltajes.

![Conexión baterias](Figuras/esquematico_part1.png)

En la segunda parte, tenemos el circuito de regulación de voltaje con un 7805. Esta sección incluye un LED que nos indicará cuando la PCB esté energizada.

![Regulador](Figuras/esquematico_part2.png)

La tercera parte es nuestro microcontrolador (MCU), el IC Atmega328p-au, con los componentes necesarios para que funcione de manera eficiente. Aquí es importante prestar atención, ya que si queremos añadir el pin de DTR, se debe colocar una conexión con un capacitor (0.1µF) entre el RPB y la resistencia de 10k, y la otra conexión al pin asociado al DTR. El SPB en el código estará configurado como PULLUP, por lo que está conectado de esta manera. Además, si se quiere habilitar el pin TX, se debe colocar un indicador que lo mande a ese pin (31).

![mCU](Figuras/esquematico_part3.png)

En la cuarta parte tenemos el arrancador y el RGB. Podemos agregar otro RGB, solo necesitamos habilitar el pin DI y conectarlo al DO de nuestro nuevo RGB; lo demás es igual. Si queremos agregar el pin RDY de nuestro arrancador, podemos asociarlo a un pin disponible de nuestro mCU.

![Arr](Figuras/esquematico_part4.png)

La quinta parte corresponde a la alimentación y señal de nuestros sensores. En P1 podría agregarse el pin TX y DTR, y es donde se programara nuestra PCB.

![Alimentación](Figuras/esquematico_part5.png)

La sexta y última parte corresponde a nuestro controlador de motores, que es el TB6612FNG, un componente bastante eficiente para controlar motores DC.

![la_TB](Figuras/esquematico_part6.png)

[***Esquemático del Arduino pro mini***](https://www.arduino.cc/en/uploads/Main/Arduino-Pro-Mini-schematic.pdf)

## PCB MOCteam

Si has decidido mandar a fabricar la opción que te presenté, aquí te explicaré qué es y dónde está cada entrada y salida de la tarjeta.

Una vez fabricada y ensamblada, tendrás las PCBs como se muestra a continuación, ya con todos los componentes soldados. Si observas, cada pin está identificado mediante **serigrafía**, lo que facilita saber a qué está asociado. 

*En la figura de abajo no contiene componentes para una mejor compresión.*

![PCB](Figuras/PCB_MICRO_3D.png)

En la etapa de regulación consiste en soldar dos baterías con dos header para poder cargarlas, se debe añadir un jumper en la parte externa de los headers. Además del regulador, un led como indicador, compontes pasivos y un diodo para protección de la tarjeta.

![ERegulacion](Figuras/Regulacion_voltaje.png)

Para cargar el programa a la PCB, necesitarás un Arduino Nano. Solo se utilizarán los pines RST, GND y RX. Conecta el Arduino Nano a la computadora y carga el programa como lo haría normalmente. Durante el proceso, el LED asociado al pin 13 de cada placa parpadeara, y cuando en el IDE de Arduino aparezca el mensaje de que la carga ha finalizado, el proceso habrá concluido.

![CP](Figuras/CP.png)

**Nota: Si no se carga el programa, puede ser debido a que el mCU no tiene el [bootloader](https://tutoriales.rantec.mx/manual-para-cargar-bootloader-en-arduino/), en cuyo caso tendrás que quemarlo. También puede ser que el resonador no esté bien soldado.**

### PINOUT

No hay mucho que agregar sobre el Pinout, ya que está serigrafiado, lo que facilita identificar a qué pin está asociado cada componente. Sin embargo, a continuación se detallan algunos puntos clave por si surge alguna duda:

- Recuadro color rosa: Contiene un botón pulsador (PBS) de propósito general, el cual está asociado al pin D2.
- Recuadro color amarillo: Incluye un LED conectado al pin D13.
- Recuadro color rojo: Está asociado a los pines que se conectan directamente al controlador de motores.
- Recuadro color naranja: Corresponde a los pines de entrada para los sensores. Aunque comúnmente se utilizan como pines analógicos, también pueden configurarse como entradas digitales, es decir, tienen - - -- funcionalidad dual. Los pines asociados son D14, D15, D16, D17, D18 y D19.
- Recuadro color morado: Contiene los LEDs RGB, que funcionan con un único pin de control, el D10.
- Recuadro color azul: Corresponde al arrancador, asociado al pin D12.

![PINOUT](Figuras/PINOUT.png)

Al final de tener toda esta explicación la PCB debería verse de la siguiente manera. 
