package algoritmos;

import modelo.*;
import java.util.*;

public class Conectividad {

    public static boolean esConexo(Grafo grafo) {
        if (grafo.getVertices().isEmpty()) return true;

        Set<String> visitados = new HashSet<>();
        Queue<Vertice> cola = new LinkedList<>();

        Vertice inicio = grafo.getVertices().values().iterator().next();
        cola.add(inicio);
        visitados.add(inicio.getId());

        while (!cola.isEmpty()) {
            Vertice actual = cola.poll();
            for (Arista arista : actual.getAdyacentes()) {
                Vertice vecino = arista.getDestino();
                if (!visitados.contains(vecino.getId())) {
                    cola.add(vecino);
                    visitados.add(vecino.getId());
                }
            }
        }

        return visitados.size() == grafo.getVertices().size();
    }

    public static List<Set<String>> componentesConexas(Grafo grafo) {
        Set<String> visitados = new HashSet<>();
        List<Set<String>> componentes = new ArrayList<>();

        for (Vertice v : grafo.getVertices().values()) {
            if (!visitados.contains(v.getId())) {
                Set<String> componente = new HashSet<>();
                dfs(v, componente, visitados);
                componentes.add(componente);
            }
        }

        return componentes;
    }

    private static void dfs(Vertice actual, Set<String> componente, Set<String> visitados) {
        visitados.add(actual.getId());
        componente.add(actual.getId());

        for (Arista arista : actual.getAdyacentes()) {
            Vertice vecino = arista.getDestino();
            if (!visitados.contains(vecino.getId())) {
                dfs(vecino, componente, visitados);
            }
        }
    }
}
