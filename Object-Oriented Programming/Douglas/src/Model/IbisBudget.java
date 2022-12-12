package Model;

public class IbisBudget extends Ibis{
	
	public IbisBudget() {
		super();
	}
	public IbisBudget(double fixed_price) {
		
	}

	public IbisBudget(String name, long num_rooms, char[] types, double fixed_price) {
		super(name, num_rooms, types, gambiarra(fixed_price));
	}
	private static double[] gambiarra(double fixed_price) { 
		double [] priceAux = new double [1];
		priceAux[0]=fixed_price;
		return priceAux;
	}
}
