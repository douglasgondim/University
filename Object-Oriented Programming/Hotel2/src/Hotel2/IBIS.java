package Hotel2;

public class IBIS extends Hotel{
	
	public IBIS() {}
	
	public IBIS(char[] name, long num_rooms, char[] room_type, double[] prices) {
		super(name, num_rooms, room_type, prices);
		
	}

	public IBIS(char[] name, long num_rooms, char[] room_type) {
		super(name, num_rooms, room_type);
	}
	

}
