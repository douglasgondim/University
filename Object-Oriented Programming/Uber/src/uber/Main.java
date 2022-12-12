package uber;

public class Main {

	public static void main(String[] args) {
		Uber u1 = new Uber();

		int atendidos=0;

		while(true) {
			for(int i=0;i<u1.getClientes().length;i++) {
				if(u1.getClientes()[i].isAtendido()==false) {
					if(u1.getClientes()[i].isDesistiu()==true || u1.getClientes()[i].chamarUber(u1) != null) {
						atendidos++;
					}
				}
				
			}

			if(atendidos==u1.getClientes().length) {
				break;
			}

		}
		
		for(int i =0;i<u1.getClientes().length;i++) {
//			if(u1.getClientes()[i].isAtendido()) {
				System.out.println(u1.getClientes()[i].getNome() + " " + u1.getClientes()[i].isDesistiu());
//			}
		}

		System.out.println("Lucro empresa Uber: " + u1.getDinheiro());

		for(int i=0;i<u1.getMotoristas().length;i++) {
			System.out.println(u1.getMotoristas()[i].getNome() + " " + u1.getMotoristas()[i].getDinheiro());
		}







	}

}
