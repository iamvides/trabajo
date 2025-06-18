import modelo.*;
import algoritmos.*;
import excepciones.*;

import java.util.*;

public class Main {
    public static void main(String[] args) {
        try {
            Grafo grafo = new Grafo();

            // --- AGREGANDO ZONAS (vértices) ---
            grafo.agregarVertice("ZonaA");
            grafo.agregarVertice("ZonaB");
            grafo.agregarVertice("ZonaC");
            grafo.agregarVertice("ZonaD");

            // --- AGREGANDO VIAS (aristas) ---
            grafo.agregarArista("ZonaA", "ZonaB", 5);
            grafo.agregarArista("ZonaB", "ZonaC", 3);
            grafo.agregarArista("ZonaC", "ZonaD", 2);
            grafo.agregarArista("ZonaD", "ZonaA", 7); // genera un ciclo
            grafo.agregarArista("ZonaB", "ZonaD", 1);

            // --- AGREGANDO ELEMENTOS A LAS ZONAS (árbol B+) ---
            Vertice zonaA = grafo.getVertice("ZonaA");
            zonaA.getZona().agregarElemento("Parque A1");
            zonaA.getZona().agregarElemento("Comisaria A2");
            zonaA.getZona().agregarElemento("Mercado A3");

            Vertice zonaB = grafo.getVertice("ZonaB");
            zonaB.getZona().agregarElemento("Edificio B1");

            System.out.println("Estructura interna de ZonaA:");
            System.out.println(zonaA.getZona());

            // --- RECORRIDOS ---
            System.out.println("\n--- DFS ---");
            new DFS().recorrer(grafo, "ZonaA");

            System.out.println("\n--- BFS ---");
            new BFS().recorrer(grafo, "ZonaA");

            // --- DIJKSTRA ---
            System.out.println("\n--- RUTA MÁS CORTA desde ZonaA ---");
            Dijkstra.mostrarRutaMasCorta(grafo, "ZonaA");

            // --- CICLOS ---
            CicloDetector detector = new CicloDetector();
            boolean hayCiclo = detector.detectar(grafo);
            System.out.println("\n¿El grafo tiene ciclo? " + (hayCiclo ? "Sí" : "No"));

            // --- CONECTIVIDAD ---
            boolean esConexo = Conectividad.esConexo(grafo);
            System.out.println("¿El grafo es fuertemente conexo? " + (esConexo ? "Sí" : "No"));

            List<Set<String>> componentes = Conectividad.componentesConexas(grafo);
            System.out.println("Componentes conexas:");
            for (Set<String> comp : componentes) {
                System.out.println("- " + comp);
            }

            // --- ZONAS AISLADAS ---
            Set<String> aisladas = grafo.zonasAisladas();
            System.out.println("Zonas aisladas: " + (aisladas.isEmpty() ? "ninguna" : aisladas));

            // --- SIMULACIÓN: Cierre de vía ZonaB -> ZonaD ---
            grafo.eliminarArista("ZonaB", "ZonaD");
            System.out.println("\nVía entre ZonaB y ZonaD eliminada temporalmente.");
            Dijkstra.mostrarRutaMasCorta(grafo, "ZonaA");

            // --- MANEJO DE ERRORES ---
            System.out.println("\n--- PRUEBA DE VALIDACIONES ---");
            try {
                grafo.agregarVertice("ZonaA"); // ya existe
            } catch (ElementoDuplicadoException e) {
                System.out.println("Error esperado: " + e.getMessage());
            }

            try {
                grafo.agregarArista("ZonaX", "ZonaB", 10); // zona inexistente
            } catch (ElementoNoEncontradoException e) {
                System.out.println("Error esperado: " + e.getMessage());
            }

        } catch (Exception e) {
            System.err.println("Error general en ejecución: " + e.getMessage());
        }
    }
}
