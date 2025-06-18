package algoritmos;

import modelo.*;
import java.util.*;

public class CicloDetector {
    private final Set<String> visitados = new HashSet<>();
    private final Set<String> enRecorrido = new HashSet<>();
    private boolean tieneCiclo = false;

    public boolean detectar(Grafo grafo) {
        visitados.clear();
        enRecorrido.clear();
        tieneCiclo = false;

        for (Vertice v : grafo.getVertices().values()) {
            if (!visitados.contains(v.getId())) {
                if (dfs(v)) {
                    tieneCiclo = true;
                    break;
                }
            }
        }

        return tieneCiclo;
    }

    private boolean dfs(Vertice actual) {
        visitados.add(actual.getId());
        enRecorrido.add(actual.getId());

        for (Arista arista : actual.getAdyacentes()) {
            Vertice vecino = arista.getDestino();
            if (!visitados.contains(vecino.getId())) {
                if (dfs(vecino)) return true;
            } else if (enRecorrido.contains(vecino.getId())) {
                return true;
            }
        }

        enRecorrido.remove(actual.getId());
        return false;
    }
}
