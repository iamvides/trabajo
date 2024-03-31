package lab2;
import java.util.*;

public class carreras {
    private int numV;       // el numero de vueltas
    private String difficult;       // dificultad
    Scanner sc = new Scanner(System.in);
    List<String> Dificultad;
    public void Dificultades() {
        String di;
        Dificultad = new ArrayList<>();
        Dificultad.add("Facil");
        Dificultad.add("Media");
        Dificultad.add("Dificil");
        Dificultad.add("Profesional");
        do {
            System.out.println("Seleccione una dificultad:");
            for (String show : Dificultad) {
                System.out.println(show);
            }
            di = sc.nextLine();
        } while (!Dificultad.contains(di));
        difficult = di;
    }
    public void setNumV(){
        int vuel;
        do {
            System.out.println("ingrese el numero de vueltas (maximo 3 vueltas)");
            vuel=sc.nextInt();
        } while (vuel<0 || vuel>3);
        numV=vuel;
    }
    public void ganador(List<String> lista){
        Random rand = new Random();
        if (lista.size()<3){                
            if (lista.size()==1){
                lista.add("chatgpt");
                lista.add("gemini");
            }
            if (lista.size()==2)
            {
                lista.add("chatgpt");
            }
        }
        else{
            lista.add("chatgpt");
        }
        int indiceAleatorio = rand.nextInt(lista.size());
        String valorAleatorio = lista.get(indiceAleatorio);
        System.out.println("el ganor de la carrera fue "+valorAleatorio);
    }
}

