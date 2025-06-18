package modelo;

import excepciones.*;

import java.util.*;

public class Grafo {
    private final Map<String, Vertice> vertices;

    public Grafo() {
        this.vertices = new HashMap<>();
    }

    public void agregarVertice(String id) {
        if (vertices.containsKey(id)) {
            throw new ElementoDuplicadoException("El vértice '" + id + "' ya existe.");
        }
        vertices.put(id, new Vertice(id));
    }

    public void eliminarVertice(String id) {
        if (!vertices.containsKey(id)) {
            throw new ElementoNoEncontradoException("El vértice '" + id + "' no existe.");
        }
        vertices.remove(id);
        for (Vertice v : vertices.values()) {
            v.eliminarAristaHacia(id);
        }
    }

    public void agregarArista(String origen, String destino, int peso) {
        if (!vertices.containsKey(origen) || !vertices.containsKey(destino)) {
            throw new ElementoNoEncontradoException("Origen o destino no encontrados.");
        }
        Vertice vOrigen = vertices.get(origen);
        Vertice vDestino = vertices.get(destino);
        vOrigen.agregarArista(new Arista(vDestino, peso));
    }

    public void eliminarArista(String origen, String destino) {
        if (!vertices.containsKey(origen)) {
            throw new ElementoNoEncontradoException("El vértice origen no existe.");
        }
        vertices.get(origen).eliminarAristaHacia(destino);
    }

    public boolean contieneVertice(String id) {
        return vertices.containsKey(id);
    }

    public Vertice getVertice(String id) {
        return vertices.get(id);
    }

    public Map<String, Vertice> getVertices() {
        return vertices;
    }

    public Set<String> zonasAisladas() {
        Set<String> aisladas = new HashSet<>();
        for (Vertice v : vertices.values()) {
            boolean sinEntradas = true;
            for (Vertice otro : vertices.values()) {
                if (otro == v) continue;
                for (Arista a : otro.getAdyacentes()) {
                    if (a.getDestino().equals(v)) {
                        sinEntradas = false;
                        break;
                    }
                }
            }
            if (sinEntradas && v.getAdyacentes().isEmpty()) {
                aisladas.add(v.getId());
            }
        }
        return aisladas;
    }
}
