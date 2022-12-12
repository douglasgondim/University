package Model;

public class Client {
	private String name;
	private double money;
	
	public Client(String name, double money){
		setName(name);
		setMoney(money);
	}
	
	public boolean canPay(double value) {
		if(value>money) {
			return false;
		}
		return pay(value);
	}
	
	private boolean pay(double value) {
		setMoney(getMoney() - value);
		return true;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public double getMoney() {
		return money;
	}

	public void setMoney(double money) {
		this.money = money;
	}
	

}
