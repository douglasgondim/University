package Hotel2;

public class IBISBudget extends IBIS{
	public double fixed_price;
	
	public IBISBudget() {}
	
	public IBISBudget(char[] name, long num_rooms, char[] room_type, double fixed_price) {
		super(name, num_rooms, room_type);
		this.fixed_price = fixed_price;
	}	
	
	public double priceRoom(long i) {
		return fixed_price;
	}

}
