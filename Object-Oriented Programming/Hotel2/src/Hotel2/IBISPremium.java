package Hotel2;

public class IBISPremium extends IBIS {
	private long luxRooms;
	private double luxPrice;
	private boolean[] luxOccupation;
	
	public IBISPremium() {}
	
	public IBISPremium(char[] name, long num_rooms, char[] room_type, double[] prices, long luxRooms, double luxPrice) {
		super(name, num_rooms, room_type, prices);
		this.luxRooms = luxRooms;
		this.luxPrice = luxPrice;
		
		this.luxOccupation = new boolean[(int) luxRooms];
	}
	
	public boolean isFreeLuxRoom(long i) {
		if(luxOccupation[(int) i]==false) {
			return true;
		}
		return false;
	}
	
	public double priceLuxRoom(long i) {
		return luxPrice;
	}
	
	public boolean occupeLuxRoom(long i) {
		if(luxOccupation[(int) i]==false) {
			luxOccupation[(int) i]=true;
			return true;
		}
		return false;
	}
	
	public boolean freeLuxRoom(long i) {
		if(luxOccupation[(int) i]==true) {
			luxOccupation[(int) i]=false;
			return true;
		}
		return false;
	}
	

}
