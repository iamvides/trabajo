package modelo;

import java.util.*;

public class Vertice {
    private final String id;
    private final List<Arista> adyacentes;
    private final Zona zona; // Cada vértice representa una zona urbana

    public Vertice(String id) {
        this.id = id;
        this.adyacentes = new ArrayList<>();
        this.zona = new Zona(id);
    }

    public String getId() {
        return id;
    }

    public List<Arista> getAdyacentes() {
        return adyacentes;
    }

    public Zona getZona() {
        return zona;
    }

    public void agregarArista(Arista arista) {
        adyacentes.add(arista);
    }

    public void eliminarAristaHacia(String destinoId) {
        adyacentes.removeIf(a -> a.getDestino().getId().equals(destinoId));
    }

    @Override
    public String toString() {
        return "Zona: " + id + " con " + adyacentes.size() + " conexiones.";
    }
}
