package Model;

public class BedAndBreakfast extends Hotel {
	private double fixed_price;

	public BedAndBreakfast(String name, long num_rooms, char[] types, double fixed_prince) {
		setName(name);
		setNum_rooms(num_rooms);
		setRooms_types(types);
		setOccupation(new boolean [(int)num_rooms]);
	}
		
	public double priceRoom(long i) {
		return getFixed_price();
	}
		
	public double getFixed_price() {
		return fixed_price;
	}

	public void setFixed_price(double fixed_price) {
		this.fixed_price = fixed_price;
	}
	
	
}
