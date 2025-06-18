package modelo;

public class Arista {
    private Vertice destino;
    private int peso;

    public Arista(Vertice destino, int peso) {
        if (peso < 0) throw new IllegalArgumentException("El peso no puede ser negativo.");
        this.destino = destino;
        this.peso = peso;
    }

    public Vertice getDestino() {
        return destino;
    }

    public int getPeso() {
        return peso;
    }

    public void setPeso(int nuevoPeso) {
        if (nuevoPeso < 0) throw new IllegalArgumentException("El nuevo peso no puede ser negativo.");
        this.peso = nuevoPeso;
    }

    @Override
    public String toString() {
        return "-> " + destino.getId() + " (peso: " + peso + ")";
    }
}
