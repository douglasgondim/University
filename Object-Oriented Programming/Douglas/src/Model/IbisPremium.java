package Model;

public class IbisPremium extends Ibis {
	private long luxRooms;
	private double luxPrice;
	private boolean[] luxOccupation;

	public IbisPremium(String name, long num_rooms, char[] types, double[] prices, long luxrooms, double luxprice) {
		setName(name);
		setNum_rooms(num_rooms);
		setRooms_types(types);
		setOccupation(new boolean[(int) num_rooms]);
		setPrices(prices);
	}

	public boolean isFreeLuxRoom(long i) {
		return false;
	}

	public double priceLuxRoom(long i) {
		return 0;
	}

	public boolean occupyLuxRoom(long i) {
		return false;
	}

	public boolean freeLuxRoom(long i) {
		return false;
	}
}
