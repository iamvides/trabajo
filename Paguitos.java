interface EstrategiaPagos {
    void procesarPagos(double monto);
}

class PagoTarjeta implements EstrategiaPagos {
    @Override
    public void procesarPagos(double monto) {
        System.out.println("El pago realizado con su tarjeta es de: " + monto);
    }
}

class PagoPayPal implements EstrategiaPagos {
    @Override
    public void procesarPagos(double monto) {
        System.out.println("El pago realizado con su Paypal es de: " + monto);
    }
}

class CarritoDeCompras {
    private EstrategiaPagos estrategiaPagos;

    public CarritoDeCompras(EstrategiaPagos estrategiaPagos) {
        this.estrategiaPagos = estrategiaPagos;
    }

    public void pagar(double monto) {
        estrategiaPagos.procesarPagos(monto);
    }
}

public class Paguitos {
    public static void main(String[] args) {
        EstrategiaPagos pagoTarjeta = new PagoTarjeta();
        CarritoDeCompras carrito1 = new CarritoDeCompras(pagoTarjeta);
        carrito1.pagar(129.50);

        EstrategiaPagos pagoPayPal = new PagoPayPal();
        CarritoDeCompras carrito2 = new CarritoDeCompras(pagoPayPal);
        carrito2.pagar(13.21);
    }
}