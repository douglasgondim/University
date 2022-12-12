
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
