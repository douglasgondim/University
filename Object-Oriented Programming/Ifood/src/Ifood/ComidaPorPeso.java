package Ifood;

public class ComidaPorPeso extends Comida{
	private float taxaPorQuilo;
	
	// construtor vazio de Comida por peso
	public ComidaPorPeso() {}
	
	// construtor Comida por peso
	public ComidaPorPeso(String nome, String categoria, float peso, float taxaPorQuilo) {
		super(nome, categoria, peso);
		this.taxaPorQuilo = taxaPorQuilo;
		// calcula o preço da comida de acordo com seu peso
		calcularPrecoPorPeso();
		
	}
	
	// GETTERS E SETTERS----------------
	public float getTaxaPorQuilo() {
		return taxaPorQuilo;
	}


	public void setTaxaPorQuilo(float taxaPorQuilo) {
		this.taxaPorQuilo = taxaPorQuilo;
	}
	// GETTERS E SETTERS----------------

	// calcula o preço da comida multiplicando taxa por Kilo pelo peso em Kg
	private void calcularPrecoPorPeso(){
		setPreco(taxaPorQuilo * (getPeso()/1000));	
	}
	

}
