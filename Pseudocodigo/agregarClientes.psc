Proceso agregarClientes
	
	Definir Correos,Nombres,Telefonos,Direcciones,Fechas_Nacimientos Como Caracter;
	Definir cantClientes como Entero;
	
	Escribir ("inserte cantidad de clientes a agregar");
	Leer cantClientes;
	
	
	Definir i Como Entero;
	Para i<-0 hasta cantClientes-1 Hacer
		Escribir "Ingreso de los datos del cliente No° ",i+1,":";
		
		Escribir("Ingrese el correo del cliente:");
		Leer Correos;
		
		Escribir("Ingrese el nombre del cliente:");
		Leer Nombres;	
		
		Escribir("Ingrese el número de teléfono del cliente:");
		Leer Telefonos;
		
		Escribir("Ingrese la dirección del cliente:");
		Leer Direcciones;
		
		Escribir("Ingrese la fecha de nacimiento del cliente:");
		Leer Fechas_Nacimientos;
		
		Escribir("Los datos completos del cliente son: ");
		Escribir Correos, " ", Nombres," ", Telefonos, " ", Direcciones," " ,Fechas_Nacimientos;
		Escribir(" ");
	FinPara
	
	Escribir cantClientes, (" clientes fueron añadidos satisfactoriamente");
	
	
FinProceso
