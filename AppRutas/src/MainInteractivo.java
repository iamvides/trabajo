import modelo.*;
import algoritmos.*;
import excepciones.*;

import java.util.*;

public class MainInteractivo {
    private static final Scanner scanner = new Scanner(System.in);
    private static final Grafo grafo = new Grafo();

    public static void main(String[] args) {
        int opcion;
        do {
            mostrarMenu();
            opcion = leerEntero("Seleccione una opción:");
            ejecutarOpcion(opcion);
        } while (opcion != 12);
    }

    private static void mostrarMenu() {
        System.out.println("\n=== APPDERUTAS - SISTEMA DE ZONAS Y RUTAS ===");
        System.out.println("1. Agregar Zona (vértice)");
        System.out.println("2. Agregar Vía entre Zonas (arista)");
        System.out.println("3. Agregar Elemento a una Zona");
        System.out.println("4. Buscar / Eliminar Elemento de una Zona");
        System.out.println("5. Calcular Ruta Más Corta (Dijkstra)");
        System.out.println("6. Mostrar Zonas Aisladas");
        System.out.println("7. Recorridos DFS / BFS");
        System.out.println("8. Detectar Ciclos");
        System.out.println("9. Ver Componentes Conexas");
        System.out.println("10. Cerrar Temporalmente una Vía");
        System.out.println("11. Mostrar estructura completa del Grafo");
        System.out.println("12. Salir del sistema");
        System.out.println("=============================================");
    }

    private static void ejecutarOpcion(int opcion) {
        switch (opcion) {
            case 1 -> {
                System.out.println("\n🟢 AGREGAR ZONA:");
                String id = leerTexto("Ingrese el ID (nombre) de la nueva zona:");
                try {
                    grafo.agregarVertice(id);
                    System.out.println("✔ Zona '" + id + "' agregada correctamente.");
                } catch (ElementoDuplicadoException e) {
                    System.out.println("⚠ " + e.getMessage());
                }
            }
            case 2 -> {
                System.out.println("\n🟢 CONECTAR ZONAS CON UNA VÍA:");
                mostrarZonas();
                if (grafo.getVertices().size() < 2) {
                    System.out.println("⚠ Debe haber al menos 2 zonas para conectar.");
                    return;
                }
                String origen = leerTexto("Seleccione zona de ORIGEN:");
                String destino = leerTexto("Seleccione zona de DESTINO:");
                int peso = leerEntero("Ingrese el PESO (distancia) de la vía:");
                try {
                    grafo.agregarArista(origen, destino, peso);
                    System.out.println("✔ Vía agregada de " + origen + " → " + destino);
                } catch (Exception e) {
                    System.out.println("⚠ Error: " + e.getMessage());
                }
            }
            case 3 -> {
                System.out.println("\n🟢 AGREGAR ELEMENTO A UNA ZONA:");
                mostrarZonas();
                String zona = leerTexto("Seleccione la zona:");
                if (!grafo.contieneVertice(zona)) {
                    System.out.println("⚠ Zona no encontrada.");
                    return;
                }
                String elem = leerTexto("Ingrese el elemento a agregar (Ej: Parque, Edificio):");
                grafo.getVertice(zona).getZona().agregarElemento(elem);
                System.out.println("✔ Elemento agregado a " + zona);
            }
            case 4 -> {
                System.out.println("\n🟢 BUSCAR O ELIMINAR ELEMENTO EN UNA ZONA:");
                mostrarZonas();
                String zona = leerTexto("Seleccione la zona:");
                if (!grafo.contieneVertice(zona)) {
                    System.out.println("⚠ Zona no encontrada.");
                    return;
                }
                Zona z = grafo.getVertice(zona).getZona();
                System.out.println("📦 Contenido actual: " + z);
                String elem = leerTexto("Elemento a buscar o eliminar:");
                String accion = leerTexto("¿Desea (b)uscar o (e)liminar?");
                if (accion.equalsIgnoreCase("b")) {
                    System.out.println(z.buscarElemento(elem) ? "✔ Encontrado." : "❌ No existe.");
                } else {
                    z.eliminarElemento(elem);
                    System.out.println("✔ Elemento eliminado (si existía).");
                }
            }
            case 5 -> {
                System.out.println("\n🟢 CALCULAR RUTA MÁS CORTA:");
                mostrarZonas();
                String origen = leerTexto("Zona de ORIGEN:");
                Dijkstra.mostrarRutaMasCorta(grafo, origen);
            }
            case 6 -> {
                System.out.println("\n🟢 ZONAS AISLADAS:");
                Set<String> aisladas = grafo.zonasAisladas();
                System.out.println(aisladas.isEmpty() ? "✔ No hay zonas aisladas." : "❗Zonas sin conexiones: " + aisladas);
            }
            case 7 -> {
                System.out.println("\n🟢 RECORRIDOS DFS / BFS:");
                mostrarZonas();
                String inicio = leerTexto("Zona de inicio:");
                System.out.println("--- DFS ---");
                new DFS().recorrer(grafo, inicio);
                System.out.println("--- BFS ---");
                new BFS().recorrer(grafo, inicio);
            }
            case 8 -> {
                System.out.println("\n🟢 DETECCIÓN DE CICLOS:");
                boolean ciclo = new CicloDetector().detectar(grafo);
                System.out.println("¿Existe un ciclo en el grafo? " + (ciclo ? "✔ Sí" : "❌ No"));
            }
            case 9 -> {
                System.out.println("\n🟢 COMPONENTES CONEXAS:");
                List<Set<String>> comp = Conectividad.componentesConexas(grafo);
                for (Set<String> c : comp) System.out.println("🔗 Componente: " + c);
            }
            case 10 -> {
                System.out.println("\n🟢 CERRAR VÍA TEMPORALMENTE:");
                mostrarZonas();
                String o = leerTexto("Zona ORIGEN:");
                String d = leerTexto("Zona DESTINO:");
                grafo.eliminarArista(o, d);
                System.out.println("✔ Vía eliminada temporalmente.");
            }
            case 11 -> {
                System.out.println("\n🟢 ESTRUCTURA DEL GRAFO:");
                for (Vertice v : grafo.getVertices().values()) {
                    System.out.println("🌐 " + v.getId() + " → " + v.getAdyacentes());
                    System.out.println("    📦 Elementos: " + v.getZona());
                }
            }
            case 12 -> System.out.println("👋 Cerrando APPDERUTAS... ¡Hasta pronto!");
            default -> System.out.println("❌ Opción inválida.");
        }
    }

    // Utilidades
    private static String leerTexto(String mensaje) {
        System.out.print(mensaje + " ");
        return scanner.nextLine().trim();
    }

    private static int leerEntero(String mensaje) {
        while (true) {
            try {
                System.out.print(mensaje + " ");
                return Integer.parseInt(scanner.nextLine().trim());
            } catch (NumberFormatException e) {
                System.out.println("⚠ Ingrese un número válido.");
            }
        }
    }

    private static void mostrarZonas() {
        if (grafo.getVertices().isEmpty()) {
            System.out.println("⚠ Aún no se ha creado ninguna zona.");
        } else {
            System.out.println("📍 Zonas disponibles: " + grafo.getVertices().keySet());
        }
    }
}
