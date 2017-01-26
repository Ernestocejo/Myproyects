class Ejemplo2{
public static void main(String[] args) {

    int sum = 0;

	for(int i=1;i <= 10;i++){ // se recorren numeros del 1 al 10
       System.out.println("\n---------------------");
       System.out.println("\nTabla de Multiplicar del: "+i);
       for(int j=1; j<=10;j++){
       	System.out.println(i + "x" + j + "="+ i*j);// en este punto se hace la multiplicacion
       }
	}

} 
}