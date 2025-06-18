package algoritmos;

import modelo.*;
import java.util.*;

public class Dijkstra {

    public static Map<String, Integer> calcularRutas(Grafo grafo, String origenId) {
        Map<String, Integer> distancias = new HashMap<>();
        Map<String, Vertice> vertices = grafo.getVertices();

        if (!vertices.containsKey(origenId)) {
            throw new IllegalArgumentException("Vértice origen '" + origenId + "' no existe en el grafo.");
        }

        for (String id : vertices.keySet()) {
            distancias.put(id, Integer.MAX_VALUE);
        }

        distancias.put(origenId, 0);
        PriorityQueue<Vertice> cola = new PriorityQueue<>(Comparator.comparingInt(v -> distancias.getOrDefault(v.getId(), Integer.MAX_VALUE)));
        cola.add(vertices.get(origenId));

        Set<String> visitados = new HashSet<>();

        while (!cola.isEmpty()) {
            Vertice actual = cola.poll();
            if (visitados.contains(actual.getId())) continue;
            visitados.add(actual.getId());

            for (Arista arista : actual.getAdyacentes()) {
                Vertice vecino = arista.getDestino();
                int nuevaDistancia = distancias.get(actual.getId()) + arista.getPeso();
                if (nuevaDistancia < distancias.getOrDefault(vecino.getId(), Integer.MAX_VALUE)) {
                    distancias.put(vecino.getId(), nuevaDistancia);
                    cola.add(vecino);
                }
            }
        }

        return distancias;
    }

    public static void mostrarRutaMasCorta(Grafo grafo, String origen) {
        try {
            Map<String, Integer> rutas = calcularRutas(grafo, origen);
            System.out.println("Distancias mínimas desde " + origen + ":");
            for (Map.Entry<String, Integer> entry : rutas.entrySet()) {
                System.out.println("A " + entry.getKey() + ": " +
                    (entry.getValue() == Integer.MAX_VALUE ? "inaccesible" : entry.getValue()));
            }
        } catch (Exception e) {
            System.err.println("Error en cálculo de rutas: " + e.getMessage());
        }
    }
}
