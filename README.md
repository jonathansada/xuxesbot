# Xuxesbot
Xuxesbot proyecto educativo desarrollado en colaboración del [Punt Multimèdia](http://www.puntmultimedia.org/) con la idea de fabricar un vehículo basado en Arduino UNO teledirigido mediante un móvil Android con Bluetooth.

## Materiales necesarios:
- [Arduino UNO](<https://www.amazon.es/Arduino-UNO-A000066-microcontrolador-ATmega328/dp/B008GRTSV6/ref=sr_1_6?ie=UTF8&qid=1489249802&sr=8-6&keywords=Arduino+UNO>)
- [Modulo Bluetooth HC06](<https://www.amazon.es/SunFounder-Wireless-Bluetooth-Transceiver-Backplane/dp/B00GAXG9A6/ref=sr_1_1?ie=UTF8&qid=1489249739&sr=8-1&keywords=HC06>).
- [Puente H L293D](<https://www.amazon.es/L293D-conductor-motor-pasos-Integrati/dp/B008XCGLNM/ref=sr_1_1?ie=UTF8&qid=1489249690&sr=8-1&keywords=l293d>).
- [2 x Motor DC y ruedas](<https://www.amazon.es/Gaoxing-Tech-neum%C3%A1tico-pl%C3%A1stico-engranaje/dp/B01NH7SASE/ref=sr_1_5?ie=UTF8&qid=1489248472&sr=8-5&keywords=motor+dc+con+neumatico>).
- Portapilas AA x 4*
- Portapilas 9v*
- Cables para Breadboard.
- [Breadboard](<https://www.amazon.es/Neuftech%C2%AE-protoboard-Contactos-Breadboard-Raspberry/dp/B00PQC72ZS/ref=sr_1_8?ie=UTF8&qid=1489249842&sr=8-8&keywords=Breadboard>).
- Un móvil Android con la aplicación [RoboPad](<https://play.google.com/store/apps/details?id=com.bq.robotic.robopad>) instalada .

\* Los dos portapilas se pueden substituir por uno de 8 pilas AA o una fuente de alimentación tipo lipo de entre 7 y 12v.

## Circuito
En el esquema **schemas/xuxesbot_conexiones_recomedada.fzz**  se muestran dos fuentes de alimentación (las pilas AA y la batería de 9v) así se mantiene separada la alimentación del motor (6v) de la del Arduino (9v).

Si no se quieren utilizar dos fuente se puede usar el esquema **schema/xuxesbot_conexiones_fuente_unica.fzz** donde alimentamos al arduino con 12v y a los motores mediante la salida de 5v de Arduino. Como contrapartida encontramos que limitamos el voltaje que entregamos a los motores y no podremos obtener el 100% de su potencia.

## Configuración del bluetooth
Cargar el programa **code\configuracion_bluetooth** y abrir el "Monitor de Serie".
El programa intentara conectarse al modulo bluetooth probando las velocidades de trasmisión soportadas por el mismo. Una vez haya conseguido conectarse veremos el mensaje **Conected**
Una vez conectado lanzaremos mediante el monitor de serie los siguientes comandos:
- **AT** si todo va bien nos devolverá un OK
- **AT+NAME{NOMBRE}**
	donde *{NOMBRE}* és el nombre que se vera al sincronizar el dispositivo. Responderá OKsetname si todo ha ido bien.
- **AT+PIN{CONTRASEÑA}**
	dodne *{CONTRASEÑA}* és el pin que usaremos para sincronizar el dispositivo. Respondera OKsetPIN si todo ha ido bien.
- **AT+BAUD5**
	para configurar la velocidad de transmisión a 19200 baudios que es la velocidad utilizada por la aplicacion RoboPad. Si todo va bien se perdera la comunicación por haber cambiado la velocidad, se puede reiniciar el programa y comprobar que se conecta a la nueva velocidad.
	
## Software
Se incluyen varios archivos a modo de lecciones a seguir:
1. **code\control_serial_simple**
 Permite controlar el vehículo mandandole las ordenes mediante el "Monitor de Serie" de Arduino.
	
	W => Avanzar
	S => Retroceder
	D => Girar a la derecha
	A => Girar a la izquierda

2. **code\comunicacion_robopad**
 Conecta el vehículo mediante la app móvil de bq [RoboPad](<https://play.google.com/store/apps/details?id=com.bq.robotic.robopad>) y permite ver que datos se reciben al pulsar en los botones
	
3. **code\control_robopad**:
 En esta aplicación unimos los dos ejercicios anteriores para controlar el vehículo con las ordenes que se reciben desde RoboPad
	
4. **code\control_robopad_buffer**:
 El código de la anterior se simplifica mediante el uso de una función y se agrega un buffer de acciones que permite girar mientras se avanza o retrocede.
	
## Modelo 3D
El modelo ha sido diseñado con la ayuda del Punt Multimèdia y modelado por Belen Fernández mediante SketchUp

Twitter: @belenferfra
Facebook: https://www.facebook.com/belen.fernandez.37454961
	
