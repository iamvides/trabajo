package modelo;

public class Zona {
    private final String nombre;
    private final BPlusTree estructura;

    public Zona(String nombre) {
        this.nombre = nombre;
        this.estructura = new BPlusTree();
    }

    public String getNombre() {
        return nombre;
    }

    public void agregarElemento(String elemento) {
        estructura.insertar(elemento);
    }

    public boolean buscarElemento(String elemento) {
        return estructura.buscar(elemento);
    }

    public void eliminarElemento(String elemento) {
        estructura.eliminar(elemento);
    }

    @Override
    public String toString() {
        return "Zona " + nombre + " contiene: " + estructura;
    }
}
