template <typename T>
void gerar_pior_caso_rec(T *v, int i, int j, int num){
	
	if(i <= j){
		int posPivot = pivo(i, j);
		v[posPivot] = num;

		gerar_pior_caso_rec(v,i, posPivot-1, num+1);
		gerar_pior_caso_rec(v,posPivot+1, j, num+1);
	}
}

