package Hotel2;

public class Hostel extends Hotel {
	private long[] guests;
	private long size_room;
	
	public Hostel(){}
	
	public Hostel(String name, long num_rooms, Room[] rooms, long size) {
		super(name, num_rooms, rooms);
		this.size_room = size;
		
		this.guests = new long[(int) size_room];
	
	}
	
	public boolean occupeRoom(long i) {
		if(guests[(int) i]<size_room) {
			guests[(int) i]++;
			return true;
		}
		rooms[(int) i].occupeRoom();
		return false;
	}
	
	public boolean freeRoom(long i) {
		if(guests[(int) i]>0) {
			guests[(int) i]--;
			rooms[(int) i].releaseRoom();
			return true;
		}
		return false;
	}
	
		
}
