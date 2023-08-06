# securesp32
# Sistema de Alarma con Contraseña en Arduino

Este proyecto implementa un sistema de alarma con contraseña utilizando un Arduino, un teclado y una pantalla LCD. El sistema permite al usuario ingresar una contraseña y, si es correcta, muestra un mensaje de bienvenida. Si la contraseña es incorrecta, muestra un mensaje de error y decrementa el número de intentos restantes.

## Requisitos

- Arduino board
- Teclado matricial
- Pantalla LCD
- Buzzer
- Conocimientos básicos de programación en Arduino

## Instalación

1. Conecta el teclado matricial y la pantalla LCD al Arduino según el esquema de conexión proporcionado.
2. Abre el archivo del proyecto en el IDE de Arduino.
3. Compila y carga el programa en el Arduino.

## Uso

1. Al encender el sistema, se mostrará en la pantalla LCD un mensaje para ingresar la contraseña.
2. Utiliza las teclas del teclado matricial para ingresar la contraseña.
3. Si la contraseña es correcta, se mostrará un mensaje de bienvenida y se activará el buzzer.
4. Si la contraseña es incorrecta, se mostrará un mensaje de error y se decrementará el número de intentos restantes.
5. Después de un número determinado de intentos fallidos, el sistema se bloqueará.
