# PCB
Obtener una PCB funcional para cualquier prototipo que estés desarrollando puede ser una tarea significativa, ya que requiere tiempo, investigación y numerosas pruebas. Estar seguro de que el prototipo que tienes será el ultimo antes de mandar a fabricar. Es por ello que en esta sección del repositorio, te comparto una opción viable que podrías considerar a la hora de realizar un microsumo.

## Tabla de Contenidos
1. [Descripción](#descripción)
2. [Esquemático](#esquemático)
3. [PinOut](#pinout)
4. [Programación](#programación)

## Descripción
Como mencioné anteriormente, esta es una tarea significativa. Si logras encontrar una PCB comercial, el proceso será mucho más sencillo, ya que alguien más habrá realizado este trabajo por ti.

En caso de que no tengas acceso a una, aquí te comparto una PCB diseñada específicamente para este propósito. Sus dimensiones son 45 mm x 25 mm, lo que la hace perfecta para las especificaciones de un microsumo. Esta PCB fue diseñada en EasyEDA, y puedes cargar el archivo Gerber en el servicio de JLCPCB para su fabricación.

Es muy posible que cuando encuentres este repositorio, ya sea por un video, una investigación o cualquier otro medio, no tengas acceso a los componentes necesarios. Por ello, aquí incluyo una sección del esquemático para que puedas replicar la PCB.

Si eres nuevo en este mundo, lo más probable es que debas investigar y buscar los componentes que utilizarás. Aunque no es un proceso complicado, puede resultar algo tedioso. Mi recomendación es que utilices componentes con medidas 0603, ya que tienen un tamaño ideal para soldar con cautín, en caso de que no cuentes con una estación de soldadura.

En cuanto a proveedores, te sugiero LCSC Electronics, que forma parte de JLCPCB, o también Aliexpress como alternativa.

Si no tienes experiencia soldando PCBs, te recomiendo tomarlo con calma y tener paciencia. Soldar requiere práctica, pero es algo que se puede aprender desde cero. Personalmente, todas mis PCBs las he ensamblado usando únicamente un cautín RADOX, y ha funcionado perfectamente. 

Por ultimo, la placa tiene como mCU un Atmega328p-au por lo que puedes programar usando el IDE de Arduino. En la sección de código explico sobre como cargar el programa usando un Arduino nano.

**Nota: Si usas cautín, te recomiendo tener malla desoldadora de cobre.**

## Esquemático
###



## PinOut

## Programación
