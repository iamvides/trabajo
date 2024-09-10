import java.util.Scanner; //Importamos la libreria Scanner

public class FormularioRegistro { //Definimos la clase

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        try {
            System.out.print("Ingrese su nombre: "); // El usuario ingresa su nombre
            String nombre = scanner.nextLine();
            validarNombre(nombre);

            System.out.print("Ingrese su edad: "); // El usuario ingresa su edad
            int edad = Integer.parseInt(scanner.nextLine());
            validarEdad(edad);

            System.out.print("Ingrese su correo electrónico: "); // El usuario ingresa su correo 
            String correo = scanner.nextLine();
            validarCorreo(correo);

            System.out.println("Registro completado con éxito."); // Mensaje de registro exitoso

        } catch (Exception e) {
            System.out.println("Error: " + e.getMessage()); // Atrapa un error y muestra el mensaje implementado en la Excepcion
        } finally {
            scanner.close(); //Cierra el Scanner
        }
    }

    public static void validarNombre(String nombre) throws Exception { //Valida el ingreso de datos 
        if (nombre == null) {
            throw new Exception("El nombre no puede estar vacío.");
        }
    }

    public static void validarEdad(int edad) throws Exception {
        if (edad <= 0) {
            throw new Exception("La edad debe ser un número positivo.");
        }
    }

    public static void validarCorreo(String correo) throws Exception {
        if (!correo.contains("@") || !correo.contains(".")) {
            throw new Exception("El correo electrónico debe contener al menos un '@' y un '.'");
        }
    }
}
