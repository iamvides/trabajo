package modelo;

import java.util.*;

public class BPlusTree {
    private final TreeMap<String, String> datos;

    public BPlusTree() {
        this.datos = new TreeMap<>();
    }

    public void insertar(String clave) {
        if (clave == null || clave.isEmpty()) return;
        datos.put(clave, clave);
    }

    public boolean buscar(String clave) {
        return datos.containsKey(clave);
    }

    public void eliminar(String clave) {
        datos.remove(clave);
    }

    public List<String> listar() {
        return new ArrayList<>(datos.keySet());
    }

    @Override
    public String toString() {
        return datos.keySet().toString();
    }
}
