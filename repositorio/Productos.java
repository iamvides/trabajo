public class Productos{
    int inventario=1000;     //stock del producto
    double precio;   //precio del producto
    String name;    //nombre del producto
    int pedido;     //Cantidad a pedir
    double total;
    
    public Productos(String name, double precio){    //constructor
        this.name=name;
        this.precio=precio;
    }
    public void Inven(int pedido){ //control del pedido
        this.pedido=pedido;
        inventario-=pedido;
        total=pedido*precio;
    }
    public void AvisarC(){      //avisar al cliente sobre su pedido
        System.out.println(" usted pidio "+pedido+" unidades de "+name +" el precio a pagar es "+ total);
    }
    public void AvisarT(){      //reporte de la tienda
        System.out.println("Se vendio la cantidad de "+pedido +" de " + name + " en el stock queda "+inventario );
    }
}