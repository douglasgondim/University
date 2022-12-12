import java.util.concurrent.Semaphore;

public class Dropbox {
    static Semaphore consumerSemaphore = new Semaphore(0);
    static Semaphore producerSemaphore = new Semaphore(1);

    private int number;
    private boolean evenNumber = false;

    public int take(final boolean even) {
        try {
            consumerSemaphore.acquire();
        }
        catch (InterruptedException e) {}

        if(even != evenNumber) {
            consumerSemaphore.release();
            return -1;
        }
        System.out.format("%s CONSUMIDOR obtem %d.%n", even ? "PAR" : "IMPAR", number);
        producerSemaphore.release();
        return number;
    }

    public void put(int number) {
        try {
            producerSemaphore.acquire();
        }
        catch (InterruptedException e) {}

        this.number = number;
        this.evenNumber = number % 2 == 0;
        System.out.format("PRODUTOR gera %d.%n", number);
        consumerSemaphore.release();
    }
}
