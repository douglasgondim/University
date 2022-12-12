package Hotel2;

public class Room {
	protected boolean occupation;
	protected String room_type;
	protected double price;
	
	public Room() {}
	
	public Room(String room_type, double price) {
		this.room_type = room_type;
		this.price = price;		
	}
	
	public boolean isFree() {
		if(occupation==true) {
			return false;
		}
		return true;
	}

	public String getRoom_type() {
		return room_type;
	}
	
	public double getPrice() {
		return price;
	}
	
	public boolean occupeRoom() {
		if(occupation == false) {
			occupation = true;
			return true;
		}
		return false;		
	}
	
	public boolean releaseRoom() {
		if(occupation = true) {
			occupation = false;
			return true;
		}
		return false;
	}
	
	
	}
