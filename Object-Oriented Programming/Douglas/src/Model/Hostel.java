package Model;

public class Hostel extends Hotel {
	private long guests[];
	private static long size_rooms;
	
	public Hostel(String name, long num_rooms, char[] types, double[] prices) {
		setName(name);
		setNum_rooms(num_rooms);
		setRooms_types(types);
		setOccupation(new boolean [(int)num_rooms]);
		setPrices(prices);
		setGuests(new long [(int) num_rooms]);
	}
	
	public boolean occupyRoom(long i) {
		if(guests[(int)i] < size_rooms) {
			guests[(int)i]++;
			return true;
		}
		return false;	
	}
	
	public boolean freeRoom(long i) {
		if(guests[(int)i] > 0) {
			guests[(int)i]--;
			return true;
		}
		return false;
	}

	public long[] getGuests() {
		return guests;
	}

	public void setGuests(long[] guests) {
		this.guests = guests;
	}

	public long getSize_rooms() {
		return size_rooms;
	}

	public void setSize_rooms(long size_rooms) {
		this.size_rooms = size_rooms;
	}
	
}
