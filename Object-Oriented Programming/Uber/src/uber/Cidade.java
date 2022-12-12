package uber;


public class Cidade {
	final static int INF = 99999;
	private int paradas;
	private float[][] mapa;
	private float[][] distancias;

	
	public Cidade() {
		lerArquivo();
		this.distancias = floydWarshall(mapa);
		
	}
	
	public float acharMenorDistancia(int ponto_partida, int ponto_chegada) {
		return distancias[ponto_partida-1][ponto_chegada-1];
				
	}
	private void lerArquivo(){
		LerArquivo leitor = new LerArquivo();
		leitor.abrirArquivoCidade();
		this.mapa = leitor.lerArquivoCidade();
		this.paradas = mapa.length;		
		leitor.fecharArquivo();
		
		
	}
	
	private float[][] floydWarshall(float mapa[][]) { 
        distancias = new float[paradas][paradas]; 
        int i, j, k; 
  
        for (i = 0; i < paradas; i++) 
            for (j = 0; j < paradas; j++) 
                distancias[i][j] = mapa[i][j]; 
  
        for (k = 0; k < paradas; k++) { 
            for (i = 0; i < paradas; i++){ 
                for (j = 0; j < paradas; j++){ 
                    if (distancias[i][k] + distancias[k][j] < distancias[i][j]) 
                        distancias[i][j] = distancias[i][k] + distancias[k][j]; 
                } 
            } 
        } 
        return distancias;
	}

	// ---------------------------------- INICIO GETTERS E SETTERS -----------------------------------
	
	public int getParadas() {
		return paradas;
	}

	public void setParadas(int paradas) {
		this.paradas = paradas;
	}

	public float[][] getMapa() {
		return mapa;
	}

	public void setMapa(float[][] mapa) {
		this.mapa = mapa;
	}
	
	// ---------------------------------- FIM GETTERS E SETTERS -----------------------------------
	

}
