package pedidos;
import java.util.*;

public class tienda2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String opc;    //la eleccion del cliente
        int ele;
        pedido shop;
        shop= new pedido();
        do{
            do {
                System.out.println("elija una accion");
                System.out.println("1. actualizar stock");
                System.out.println("2. Hacer un pedido");
                System.out.println("3. Pedir su factura");
                ele=sc.nextInt();
            } while (ele<0 || ele>3);
            if (ele==1){
                shop.IngresoP();
            }
            if(ele==2){
                shop.EstadoP();
            }
            if (ele==3){
                shop.Factura();
            }
            System.out.println("desea continuar con sus pedidos? SI o NO");
            opc= sc.next();
        } while (opc.equals("SI"));
        
    }
}
