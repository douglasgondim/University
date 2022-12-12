package Hotel2;

public class Main {
	
	public static void main(String[] args) {
		
		Hotel h1 = new BedAndBreakfast(new char[] {'p','o','u','s','a','d','a'}, 10, 
				new char[] {'c','c','c','c','c','c','c','c','c','c'}, 140);
		
		Hotel h2 = new Hostel(new char[] {'a','l','b','e','r','g','u','e'}, 10,
				new char[] {'c','c','c','c','c','c','c','c','c','c'}, new double[] {0, 50, 0, 0},8);
		
		Hotel h3 = new IBISBudget(new char[] {'i','b','i','s','P','o','b','r','e'}, 20,
				new char[] {'c','c','c','c','c','c','c','c','c','c','c','c','c','c','c','c','c','c','c','c'},
				110);
		
		Hotel h4 = new IBIS(new char[] {'i','b','i','s','R','i','c','o'}, 40,
				new char[] {'d','d','d','d','d','d','d','d','d','d','c','c','c','c','c','c','c','c','c','c',
						    'b','b','b','b','b','b','b','b','b','b','a','a','a','a','a','a','a','a','a','a'},
				new double[] {90, 110, 190, 300});
		
		
		//ocupar os 5 primeiros quartos de cada hotel
		for(int i=0;i<5;i++) {
			h1.occupeRoom(i);
			h2.occupeRoom(i);
			h3.occupeRoom(i);
			h4.occupeRoom(i);
		}
		
	
		//ocupar mais 7 vezes os 3 primeiros quartos do hostel
		for(int i=0;i<7;i++) {
			h2.occupeRoom(0);
			h2.occupeRoom(1);
			h2.occupeRoom(2);
		}
		
		
		// imprime para pousada quarto + numero + status + preço + tipo
		System.out.println(h1.getName());
		
		for(long i=0;i< h1.getNum_rooms();i++) {
			System.out.print("Quarto "+ i);
			if(h1.isFreeRoom(i)==true) {
				System.out.print(" LIVRE ");
			}else {
				System.out.print(" OCUPADO ");
			}
			System.out.print((int)h1.priceRoom(i));
			
			switch(h1.getRoom_type(i)) {
			case 'a' : System.out.println(" super-luxo");
				break;
			case 'b' : System.out.println(" luxo");
				break;
			case 'c' : System.out.println(" normal");
				break;
			case 'd' : System.out.println(" eco");
				break;
				
			}
			
		}
		System.out.println();
		
		// imprime para albergue quarto + numero + status + preço + tipo
		System.out.println(h2.getName());
		for(long i=0;i< h2.getNum_rooms();i++) {
			System.out.print("Quarto "+ i);
			if(h2.isFreeRoom(i)==true) {
				System.out.print(" LIVRE ");
			}else {
				System.out.print(" OCUPADO ");
			}
			System.out.print((int)h2.priceRoom(i));
			
			switch(h2.getRoom_type(i)) {
			case 'a' : System.out.println(" super-luxo");
				break;
			case 'b' : System.out.println(" luxo");
				break;
			case 'c' : System.out.println(" normal");
				break;
			case 'd' : System.out.println(" eco");
				break;
				
			}
			
		}
		System.out.println();
		
		
		// imprime para ibisPobre quarto + numero + status + preço + tipo
		System.out.println(h3.getName());
		
		for(long i=0;i< h3.getNum_rooms();i++) {
			System.out.print("Quarto "+ i);
			if(h3.isFreeRoom(i)==true) {
				System.out.print(" LIVRE ");
			}else {
				System.out.print(" OCUPADO ");
			}
			System.out.print((int)h3.priceRoom(i));
			
			switch(h3.getRoom_type(i)) {
			case 'a' : System.out.println(" super-luxo");
				break;
			case 'b' : System.out.println(" luxo");
				break;
			case 'c' : System.out.println(" normal");
				break;
			case 'd' : System.out.println(" eco");
				break;
				
			}
			
		}
		System.out.println();
		
		
		// imprime para ibisRico quarto + numero + status + preço + tipo
		System.out.println(h4.getName());
		
		for(long i=0;i< h4.getNum_rooms();i++) {
			System.out.print("Quarto "+ i);
			if(h4.isFreeRoom(i)==true) {
				System.out.print(" LIVRE ");
			}else {
				System.out.print(" OCUPADO ");
			}
			System.out.print((int)h4.priceRoom(i));
			
			switch(h4.getRoom_type(i)) {
			case 'a' : System.out.println(" super-luxo");
				break;
			case 'b' : System.out.println(" luxo");
				break;
			case 'c' : System.out.println(" normal");
				break;
			case 'd' : System.out.println(" eco");
				break;
				
			}
			
		}
		System.out.println();
		
		
		
		//cria 3 clientes novos
		Client c1 = new Client(new char[] {'g','e','o','r','g','e'}, 100); 
		Client c2 = new Client(new char[] {'h','a','r','r','y'}, 200); 
		Client c3 = new Client(new char[] {'r','a','y'}, 300); 
		
		
		//imprime para cada quarto da pousada se o cliente 1,2 e 3 pode ou nao pagar
		System.out.println(h1.getName()); 
		for(int i=0;i<h1.getNum_rooms();i++) {
			System.out.print("Quarto " + i + " Cliente 1");
			if(c1.canPay(h1.priceRoom(i))==true) {
				System.out.print(" SIM");
			}else {
				System.out.print(" NÃO");
			}
			
			System.out.print(" Cliente 2");
			if(c2.canPay(h1.priceRoom(i))==true) {
				System.out.print(" SIM");
			}else {
				System.out.print(" NÃO");
			}
			
			System.out.print(" Cliente 3");
			
			if(c3.canPay(h1.priceRoom(i))==true) {
				System.out.println(" SIM");
			}else {
				System.out.println(" NÃO");
			}
			
			
		}
		System.out.println();
		

		//imprime para cada quarto do albergue se o cliente 1,2 e 3 pode ou nao pagar
			System.out.println(h2.getName()); 
			for(int i=0;i<h2.getNum_rooms();i++) {
				System.out.print("Quarto " + i + " Cliente 1");
				if(c1.canPay(h2.priceRoom(i))==true) {
					System.out.print(" SIM");
				}else {
					System.out.print(" NÃO");
				}
				
				System.out.print(" Cliente 2");
				if(c2.canPay(h2.priceRoom(i))==true) {
					System.out.print(" SIM");
				}else {
					System.out.print(" NÃO");
				}
				
				System.out.print(" Cliente 3");
				
				if(c3.canPay(h2.priceRoom(i))==true) {
					System.out.println(" SIM");
				}else {
					System.out.println(" NÃO");
				}
				
				
			}
			System.out.println();
	
			
			//imprime para cada quarto do ibisPobre se o cliente 1,2 e 3 pode ou nao pagar
			System.out.println(h3.getName()); 
			for(int i=0;i<h3.getNum_rooms();i++) {
				System.out.print("Quarto " + i + " Cliente 1");
				if(c1.canPay(h3.priceRoom(i))==true) {
					System.out.print(" SIM");
				}else {
					System.out.print(" NÃO");
				}
				
				System.out.print(" Cliente 2");
				if(c2.canPay(h3.priceRoom(i))==true) {
					System.out.print(" SIM");
				}else {
					System.out.print(" NÃO");
				}
				
				System.out.print(" Cliente 3");
				
				if(c3.canPay(h3.priceRoom(i))==true) {
					System.out.println(" SIM");
				}else {
					System.out.println(" NÃO");
				}
				
				
			}
			System.out.println();
			
			//imprime para cada quarto do ibisRico se o cliente 1,2 e 3 pode ou nao pagar
			System.out.println(h4.getName()); 
			for(int i=0;i<h4.getNum_rooms();i++) {
				System.out.print("Quarto " + i + " Cliente 1");
				if(c1.canPay(h4.priceRoom(i))==true) {
					System.out.print(" SIM");
				}else {
					System.out.print(" NÃO");
				}
				
				System.out.print(" Cliente 2");
				if(c2.canPay(h4.priceRoom(i))==true) {
					System.out.print(" SIM");
				}else {
					System.out.print(" NÃO");
				}
				
				System.out.print(" Cliente 3");
				
				if(c3.canPay(h4.priceRoom(i))==true) {
					System.out.println(" SIM");
				}else {
					System.out.println(" NÃO");
				}
				
				
			}
		
	}

}
