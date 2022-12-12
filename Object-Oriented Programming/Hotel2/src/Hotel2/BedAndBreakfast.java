package Hotel2;

public class BedAndBreakfast extends Hotel {
	private double fixed_price;
	
	public BedAndBreakfast() {}
	
	public BedAndBreakfast(String name, long num_rooms, Room[] rooms) {
		super(name, num_rooms, rooms);
	}
	
	public double priceRoom(long i) {
		return fixed_price;
	}
	
	public String getRoomType(long i) {
		return "quarto com café";
	}
	

}
