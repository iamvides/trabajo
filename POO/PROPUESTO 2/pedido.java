package pedidos;
import java.util.*;
public class pedido {
    List<String> stock;
    List<String> agotado;
    List<String> pedidos;
    Scanner sc = new Scanner(System.in);
    public void IngresoP() { // ingreso de productos
        stock = new ArrayList<>();
        agotado = new ArrayList<>();
        String opc = "SI";
        String name;
        int estado;
        do {
            System.out.println("Ingrese el nombre del producto");
            name = sc.nextLine();
            System.out.println("Ingrese cual es el estado del producto: 1. Agotado, 2. En stock");
            estado = sc.nextInt();
            sc.nextLine();
            if (estado == 1) {
                agotado.add(name);
            } else {
                stock.add(name);
            }
            System.out.println("¿Desea seguir ingresando productos? (SI o NO)");
            opc = sc.nextLine();
        } while (opc.equals("SI"));
    }
    public void EstadoP() { // estado de los productos
        pedidos = new ArrayList<>();
        String ped;
        String continuar = "SI";
        System.out.println("Los productos en stock son:");
        for (int i = 0; i < stock.size(); i++) {
            System.out.println(stock.get(i));
        }
        System.out.println("Los productos agotados son:");
        for (int i = 0; i < agotado.size(); i++) {
            System.out.println(agotado.get(i));
        }
        System.out.println("Ingrese su pedido:");
        do {
            ped = sc.nextLine();
            if (stock.contains(ped)) {
                pedidos.add(ped);
            }
            else{
                System.out.println("el producto que esta pidiendo esta agotado");
            }
            System.out.println("¿Desea ingresar otro pedido? (SI o NO)");
            continuar = sc.nextLine();
        } while (continuar.equals("SI"));
    }
    public void Factura() { // Factura
        System.out.println("La factura es:");
        for (int i = 0; i < pedidos.size(); i++) {
            System.out.println(pedidos.get(i));
        }
    }
}

