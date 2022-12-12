
public class MyCounter {
	long counter;
	
	MyCounter(){
		counter=0;
	}
	void start() {
		counter=0;
		
	}
	long check() {
		return counter;
	}
	void increment() {
		counter++;
		
	}
	long reset() {
		long aux=counter;
		counter=0;
		return aux;
		
	}

}


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

