package lab2;

import java.util.*;

public class auto {
    private int numJ;       //numero de jugadores
    List<String>Gamer;
    Scanner sc = new Scanner(System.in);
    public void setNumJ(){           //total de jugadores
        int total;
        do {
            System.out.println("ingrese la cantidad de jugadores ( maximo 3)");
            total= sc.nextInt();
        } while (total<0 || total>3);
        numJ=total;
    }
    public void registro(){
        String names;               //nombre de los jugadores
        Gamer = new ArrayList<>();
        System.out.println("ingrese el nombre de los jugadores");
        for (int i=-1;i<numJ;i++){
            names=sc.nextLine();
            Gamer.add(names);
        }
    }
}
