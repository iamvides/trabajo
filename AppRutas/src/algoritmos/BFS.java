package algoritmos;

import modelo.*;
import java.util.*;

public class BFS {
    public void recorrer(Grafo grafo, String inicio) {
        Vertice vInicio = grafo.getVertice(inicio);
        if (vInicio == null) {
            System.out.println("Vértice de inicio no existe: " + inicio);
            return;
        }

        Set<String> visitados = new HashSet<>();
        Queue<Vertice> cola = new LinkedList<>();

        cola.add(vInicio);
        visitados.add(vInicio.getId());

        System.out.println("Recorrido BFS desde: " + inicio);
        while (!cola.isEmpty()) {
            Vertice actual = cola.poll();
            System.out.println("Visitado: " + actual.getId());

            for (Arista arista : actual.getAdyacentes()) {
                Vertice vecino = arista.getDestino();
                if (!visitados.contains(vecino.getId())) {
                    cola.add(vecino);
                    visitados.add(vecino.getId());
                }
            }
        }
    }
}
