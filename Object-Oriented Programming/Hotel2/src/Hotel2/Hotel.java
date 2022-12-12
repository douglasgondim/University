package Hotel2;

public abstract class Hotel {
	
	protected long num_rooms;
	protected Room rooms[];
	protected String name;

	
	public Hotel() {}
	
	public Hotel(String name, long num_rooms, Room[] rooms) {
		this.name = name;
		this.num_rooms = num_rooms;
				
	}
	
	public long getNum_rooms() {
		return num_rooms;
	}		

	public boolean isFreeRoom(long i) {
		if(rooms[(int) i].isFree()==true) {
			return true;
		}
		return false;
	}
	
	public double priceRoom(long i) {
		return rooms[(int) i].getPrice();
	}
	
	public boolean occupeRoom(long i) {
		return rooms[(int) i].occupeRoom();
	}
	
	public boolean freeRoom(long i) {
		return rooms[(int) i].isFree();
	}
	
	public String getRoomtype(long i) {
		return rooms[(int)i].getRoom_type();
		
		
	}
	

}
