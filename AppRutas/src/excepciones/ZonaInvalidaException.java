package excepciones;

public class ZonaInvalidaException extends RuntimeException {
    public ZonaInvalidaException(String mensaje) {
        super(mensaje);
    }
}
