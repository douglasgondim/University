package Hotel2;

public class Client {
	private char[] name = new char[200];
	private double money;
	
	public Client() {}
	
	public Client(char[] name, double money) {
		this.name = name;
		this.money = money;
		
	}
	
	public boolean canPay(double value) {
		if(money>=value) {
			return true;
		}
		return false;
	}
	
	public boolean pay(double value) {
		if(canPay(value)==true) {
			money -= value;
			return true;			
		}
		return false;
	}
	
	
	

}
