package Model;

public abstract class Hotel {
	private long num_rooms;
	private double prices[] = new double[4];
	private String name;
	private boolean occupation[];
	private char rooms_types[]; 

//	public Hotel() {
//		super();
//	}
//	
//	public Hotel(String name, long num_rooms, char[] types) {
//		this();
//		setName(name);
//		setNum_rooms(num_rooms);
//		setRooms_types(types);
//		this.occupation = new boolean [(int) num_rooms];		
//	}
	public boolean isFreeRoom(long i) {
		if(occupation[(int) i]) {
			return false;
		}
		return true;
	}
	public double priceRoom(long i) {
		if(rooms_types[(int)i] == 'a') {
			return prices[0];
		}else if(rooms_types[(int)i] == 'b') {
			return prices[1];
		}else if(rooms_types[(int)i] == 'c') {
			return prices[2];
		}else if(rooms_types[(int)i] == 'd') {
			return prices[3];
		}
		return (Double) null;
	}
	public boolean occupyRoom(long i) {
		if(!occupation[(int) i]) {
			occupation[(int)i] = true;
			return true;
		}
		return false;
		
	}
	public boolean freeRoom(long i) {
		if(occupation[(int) i]) {
			occupation[(int)i] = false;
			return true;
		}
		return false;
		
	}

	public long getNum_rooms() {
		return num_rooms;
	}

	public void setNum_rooms(long num_rooms) {
			this.num_rooms = num_rooms;
	}

	public double[] getPrices() {
		return prices;
	}

	public void setPrices(double[] prices) {
		this.prices = prices;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public boolean[] getOccupation() {
		return occupation;
	}

	public void setOccupation(boolean[] occupation) {
		this.occupation = occupation;
	}

	public char[] getRooms_types() {
		return rooms_types;
	}

	public void setRooms_types(char[] rooms_types) {
		this.rooms_types = rooms_types;
	}
	
	
}
