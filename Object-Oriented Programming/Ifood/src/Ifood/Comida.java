package Ifood;

public class Comida {
	private String nome;
	private float  preco;
	private String categoria;
	private float peso;
	
	// construtor vazio Comida
	public Comida() {}
	
	// Construtor Comida
	public Comida(String nome, float preco, String categoria, float peso) {
		this.nome = nome;
		this.preco = preco;
		this.categoria = categoria;
		this.peso = peso;
	}
	
	// Construtor para comidas por peso
	public Comida(String nome, String categoria, float peso) {
		this.nome = nome;
		this.categoria = categoria;
		this.peso = peso;
	}
	
	
	// GETTERS E SETTERS----------------
	public void setNome(String nome) {
		this.nome = nome;
	}

	public void setCategoria(String categoria) {
		this.categoria = categoria;
	}

	public void setPeso(float peso) {
		this.peso = peso;
	}

	public float getPreco() {
		return preco;
	}

	public String getCategoria() {
		return categoria;
	}

	public String getNome() {
		return nome;
	}

	public float getPeso() {
		return peso;
	}

	public void setPreco(float preco) {
		this.preco = preco;
	}
	
	// GETTERS E SETTERS----------------
		
	}
