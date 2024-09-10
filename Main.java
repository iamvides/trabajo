interface Instrumento { //Definimos la interfas
    void tocar();
    void afinar();
}

class Piano implements Instrumento {
    @Override
    public void tocar() {
        System.out.println("Piano tocado con exito");
    }

    @Override
    public void afinar() {
        System.out.println("Piano afinado con exito");
    }
}

class Saxo implements Instrumento {
    @Override
    public void tocar() {
        System.out.println("Saxo tocado con exito");
    }

    @Override
    public void afinar() {
        System.out.println("Saxo afinado con exito");
    }
}

public class Main {
    public static void main(String[] args) {
        Instrumento[] instrumentos = {new Piano(), new Saxo()};

        for (Instrumento instrumento : instrumentos) {
            instrumento.tocar();
            instrumento.afinar();
        }   
    }
}
