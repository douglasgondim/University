
public class Main {

	public static void main(String[] args) throws InterruptedException {
		MyCounter counter = new MyCounter();
		counter.start();
		for(int i=0;i<500;i++) {
			System.out.println(counter.check());
			Thread.sleep(500);
			counter.increment();
			
		}

	}

}
