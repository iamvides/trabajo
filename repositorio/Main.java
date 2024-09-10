interface Instrumento { //Definimos la interfas
    void tocar(); // defnicomos funcion
    void afinar(); // definimos funcion
}

class Piano implements Instrumento { // clase piano que implementa la interfas
    @Override
    public void tocar() { // sobreescritura
        System.out.println("Piano tocado con exito");
    }

    @Override
    public void afinar() { // sobreescritura
        System.out.println("Piano afinado con exito");
    }
}

class Saxo implements Instrumento { // calse saxo que implementa la iterfas
    @Override
    public void tocar() { // sobreescritura
        System.out.println("Saxo tocado con exito");
    }

    @Override
    public void afinar() { // sobreescritura
        System.out.println("Saxo afinado con exito");
    }
}

public class Main { // calse main
    public static void main(String[] args) {
        Instrumento[] instrumentos = {new Piano(), new Saxo()};

        for (Instrumento instrumento : instrumentos) {
            instrumento.tocar();
            instrumento.afinar();
        }   
    }
}
