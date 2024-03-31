package avion;

import java.util.*;

public class avion {
    private String tipo;    //tipo de avion
    private int numP;    //Numero de pasajeros
    private int team;   //tripulacion
    List<String> aviones;
    Scanner sc = new Scanner(System.in);

    public void setTipo(){
        int type;
        aviones= new ArrayList<>();
        aviones.add("1.pequeño");
        aviones.add("2.mediano");
        aviones.add("3.grande");
        do {
            System.out.println("que tipo de avion se usara(1,2 o 3)");
            for (int i=0; i<aviones.size();i++){
                System.out.println(aviones.get(i));
            }
            type=sc.nextInt();
        } while (type<0 || type>3);
        if (type==1){
            tipo="pequeño";
        }
        if (type==2){
            tipo="mediano";
        }
        if (type==3){
            tipo="grande";
        }
    }
    public void setNumP(){
        int num=0;
        if (tipo.equals("pequeño")){
            do {
                System.out.println("Ingrese cuantos pasajeros van a viajar(maximo 30) ");
                num= sc.nextInt();
            } while (num<0 || num>30);
        }
        if (tipo.equals("mediano")){
            do {
                System.out.println("Ingrese cuantos pasajeros van a viajar(minimo 50, maximo 100) ");
                num= sc.nextInt();
            } while (num<50 || num>100);
        }
        if (tipo.equals("grande")){
            do {
                System.out.println("Ingrese cuantos pasajeros van a viajar(minimo 100 maximo 400) ");
                num= sc.nextInt();
            } while (num<100 || num>400);
        }
        numP=num;
    }
    public void setTeam(){
        int equipo = 0;
        if (tipo.equals("pequeño")){
            do {
                System.out.println("Ingrese por cuántas personas se compondrá la tripulación (1 o 2)");
                equipo = sc.nextInt();
                sc.nextLine(); // Consume el carácter de nueva línea restante
            } while (equipo < 1 || equipo > 2);
        }
        if (tipo.equals("mediano")){
            do {
                System.out.println("Ingrese por cuántas personas se compondrá la tripulación (2 o 3)");
                equipo = sc.nextInt();
                sc.nextLine(); // Consume el carácter de nueva línea restante
            } while (equipo < 2 || equipo > 3);
        }
        if (tipo.equals("grande")){
            do {
                System.out.println("Ingrese por cuántas personas se compondrá la tripulación (7 o 10)");
                equipo = sc.nextInt();
                sc.nextLine(); // Consume el carácter de nueva línea restante
            } while (equipo < 7 || equipo > 10);
        }
        team = equipo;
    }
    
}
