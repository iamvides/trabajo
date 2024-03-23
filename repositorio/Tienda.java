import java.util.*;

public class Tienda {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int opc;    //la eleccion del cliente
        int ele;    //eleecion del producto
        int cantidad;   //la cantidad del pedido
        String conti;   
        Productos leche = new Productos("leche", 2.50);
        Productos huevos = new Productos("java de huevos", 3.00);
        Productos sal = new Productos("bolsa de sal", 1.20);
        Productos azucar = new Productos("bolsa de azucar", 1.50);
        Productos agua = new Productos("botella de agua", 1.00);
        do {
            do {
                do {
                    System.out.println("Menu:");
                    System.out.println("1. Hacer un pedido");
                    System.out.println("2. Reporte de la tienda (solo empleados)");
                    System.out.println("3. Finalización de pedido");
                    opc = sc.nextInt();
                } while (opc < 1 || opc > 3);
                if (opc==1) {
                    System.out.println("productos disponbles");
                    System.out.println("1.lata de leche precio 2.50$");
                    System.out.println("2.java de huevos precio 3.00$");
                    System.out.println("3.bolsa de sal precio 1.20$");
                    System.out.println("4.bolsa de azucar 1.50$");
                    System.out.println("5.botella de agua 1.00$");
                    do {
                        ele= sc.nextInt();
                    } while (ele<0 || ele>5);
                    if (ele==1){
                        do {
                            System.out.println("Ingrese la cantidad que desea comprar el stock actual es "+leche.inventario);
                            cantidad = sc.nextInt();
                        } while (cantidad>leche.inventario);
                        leche.Inven(cantidad);
                    }
                    if (ele==2){
                        do {
                            System.out.println("Ingrese la cantidad que desea comprar el stock actual es "+huevos.inventario);
                            cantidad = sc.nextInt();
                        } while (cantidad>huevos.inventario);
                        huevos.Inven(cantidad);
                    }
                    if (ele==3){
                        do {
                            System.out.println("Ingrese la cantidad que desea comprar el stock actual es "+sal.inventario);
                            cantidad = sc.nextInt();
                        } while (cantidad>sal.inventario);
                        sal.Inven(cantidad);
                    }
                    if (ele==4){
                        do {
                            System.out.println("Ingrese la cantidad que desea comprar el stock actual es "+azucar.inventario);
                            cantidad = sc.nextInt();
                        } while (cantidad>azucar.inventario);
                        azucar.Inven(cantidad);
                    }
                    if (ele==5){
                        do {
                            System.out.println("Ingrese la cantidad que desea comprar el stock actual es "+agua.inventario);
                            cantidad = sc.nextInt();
                        } while (cantidad>agua.inventario);
                        agua.Inven(cantidad);
                    }
                }
                if (opc==2) {
                    leche.AvisarT();
                    huevos.AvisarT();
                    sal.AvisarT();
                    azucar.AvisarT();
                    agua.AvisarT();
                }
            } while (opc != 3);
            leche.AvisarC();
            huevos.AvisarC();
            sal.AvisarC();
            azucar.AvisarC();
            agua.AvisarC();
            System.out.println("felicidades su pedido esta listo");
            System.out.println("Desea hacer otro pedido? SI o NO");
            conti= sc.next();
        } while (conti=="SI");
        
    }
}
