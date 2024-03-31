package avion;
import java.util.*;
public class vuelo {
    public static void main(String[] args) {
        avion plane;
        plane= new avion();
        mision mition;
        mition= new mision();
        String opc="SI";
        Scanner sc = new Scanner(System.in);
        do {
            plane.setTipo();
            plane.setNumP();
            plane.setTeam();
            mition.setDestino();
            mition.setTime();
            mition.setoil();
            mition.logro();
            opc=sc.nextLine();
        } while (opc.equals("SI"));
        
    }
}
