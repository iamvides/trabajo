package lab2;
import java.util.*;
public class juego {
    public static void main(String[] args) {
        auto play;
        carreras ia;
        play= new auto();       //objeto de los jugadores
        ia= new carreras();     //objeto de la maquina
         Scanner sc = new Scanner(System.in);
        String opc="SI";
        do {
            play.setNumJ();
            play.registro();
            ia.Dificultades();
            ia.setNumV();
            ia.ganador(play.Gamer);
            System.out.println("Desea otra carrera?(SI o NO)");
            opc= sc.nextLine();
        } while (opc.equals("SI"));         //funcion para comparar

    }
}
