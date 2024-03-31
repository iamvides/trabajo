package avion;

import java.util.Scanner;

public class mision {
    private int oil;
    private int time;
    private String destino;
    private int distancia;
    Scanner sc= new Scanner(System.in);
    public void setDestino(){
        int elec;
        String country;
        do {
            System.out.println("¿Qué tipo de vuelo hará?");
            System.out.println("1. Nacional o 2. Internacional");
            elec = sc.nextInt();
            sc.nextLine(); // Consumir el carácter de nueva línea
        } while (elec != 1 && elec != 2);
        
        System.out.println("Ingrese cuál será su destino:");
        country = sc.nextLine();
        destino = country;
        distancia = elec;
    }
    
    public void setTime(){
        int tiempo;
        System.out.println("cuanto tarda la mision?(en horas)");
        tiempo=sc.nextInt();
        time=tiempo;
    }
    public void setoil(){
        int gasolina;
        System.out.println("Cuanto combustible cargara en el avion");
        System.out.println("recordar que para cargar combustibles es el numero de horas multiplicado por 500 galones");
        System.out.println("ya que para volar una hora se requieren de 500 galones");
        gasolina=sc.nextInt();
        oil=gasolina;
    }
    public void logro(){
        if(distancia==1){
            if(oil>(500*time)){         //cada hora de vuelo es igual a 500 galones 
                System.out.println("Felicidades su vuelo nacional fue exitosa logro llegar de Peru a "+destino);
            }
        }
        else{
            if(oil<(500*time)){         //cada hora de vuelo es igual a 500 galones 
                System.out.println("Su vuelo nacional de Peru a  "+destino + " ah fallado por falta de combustible");
            }
        }
        if(distancia==2){
            if(oil>(500*time)){         //cada hora de vuelo es igual a 500 galones 
                System.out.println("Felicidades su vuelo internacional fue exitosa logro llegar de Peru a "+destino);
            }
        }
        else{
            if(oil<(500*time)){         //cada hora de vuelo es igual a 500 galones 
                System.out.println("Su vuelo internacional de Peru a  "+destino + " ah fallado por falta de combustible");
            }
        }
    }
}
