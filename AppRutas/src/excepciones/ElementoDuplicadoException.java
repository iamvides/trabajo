package excepciones;

public class ElementoDuplicadoException extends RuntimeException {
    public ElementoDuplicadoException(String mensaje) {
        super(mensaje);
    }
}
