package algoritmos;

import modelo.*;
import java.util.*;

public class DFS {
    private final Set<String> visitados;

    public DFS() {
        this.visitados = new HashSet<>();
    }

    public void recorrer(Grafo grafo, String inicio) {
        visitados.clear();
        Vertice vInicio = grafo.getVertice(inicio);
        if (vInicio == null) {
            System.out.println("Vértice de inicio no existe: " + inicio);
            return;
        }
        System.out.println("Recorrido DFS desde: " + inicio);
        dfs(vInicio);
    }

    private void dfs(Vertice actual) {
        if (actual == null || visitados.contains(actual.getId())) return;
        System.out.println("Visitado: " + actual.getId());
        visitados.add(actual.getId());
        for (Arista arista : actual.getAdyacentes()) {
            dfs(arista.getDestino());
        }
    }

    public Set<String> getVisitados() {
        return visitados;
    }
}
