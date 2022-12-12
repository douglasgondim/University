package Model;

public abstract class Ibis extends Hotel {
	public Ibis() {
		super();
	}
	
	public Ibis(String name, long num_rooms, char[] types, double[] prices) {
		this();
		setName(name);
		setNum_rooms(num_rooms);
		setRooms_types(types);
		setOccupation(new boolean [(int)num_rooms]);
		setPrices(prices);
	}
}
