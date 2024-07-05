# Sistema de Gestión de Clientes

Este programa permite gestionar un registro de clientes con diversas funcionalidades como agregar, editar, eliminar y visualizar clientes. 

### Estructura del Programa

- `variables.h`: Contiene las definiciones de estructuras y constantes globales.
- `funciones.cpp`: Implementa las funcionalidades principales del programa.
- `menu.cpp`: Define el menú principal e integra las funcionalidades para su uso interactivo.
- `title.cpp`: Muestra el título del programa al inicio.

### Funcionalidades

1. **Ordenar y Guardar Clientes**: Ordena los clientes alfabéticamente por nombre y los guarda en un archivo llamado `clientes_ordenados.txt`.
2. **Mostrar Todos los Clientes**: Muestra una lista de todos los clientes registrados. Si no hay clientes, muestra una advertencia.
3. **Editar Cliente**: Permite editar la información de un cliente específico, incluyendo el ID.
4. **Salir**: Permite cerrar el programa en cualquier momento.

### Particularidades

- **Verificación de Longitud**: Al agregar o editar datos de clientes, si se excede el límite de caracteres permitido, se mostrará un mensaje de error.
- **Validación de ID**: No se permite insertar un ID negativo para un cliente. Si se intenta, se mostrará una advertencia y se solicitará ingresar el ID nuevamente.
- **Edición de ID Existente**: Esta funcionalidad ha sido corregida para permitir la edición de los ID existentes sin errores.

### Uso del Programa

1. Ejecute el programa y seleccione la opción deseada del menú.
2. Siga las instrucciones en pantalla para agregar, editar o visualizar clientes.
3. Para ordenar y guardar los clientes, seleccione la opción correspondiente y verifique el archivo generado.
4. Para salir del programa, seleccione la opción "Salir" en cualquier momento.

¡Disfrute usando el programa de gestión de clientes!
