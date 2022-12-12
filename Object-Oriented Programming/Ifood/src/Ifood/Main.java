package Ifood;

public class Main {

	public static void main(String[] args) {
		// cria novo restaurante RU passando (Nome: RU, dinheiro total dele: 0, preço do cartão desconto = R$ 15, 
		// quantidade de uso do cartão desconto = 10, porcentagem de desconto do cartao = 15%, numero de opções no menu = 50,
		// preço da taxa de entrega = R$ 4 e tamanho do histórico deste restaurante = 50.)
		Restaurante RU = new Restaurante("RU", 0, 15, 10, 15, 50, 4, 50);
		
		// cria novo cliente que possui 50 reais, endereço: 402 Wall St, nome: Jhonson
		Cliente c1 = new Cliente(50, "402 Wall St", "Jhonson");
		
		// cria novo cliente vip que possui R$ 100, edereço: 1405 Madison St e nome: Constance 
		ClienteVip cv1 = new ClienteVip(100, "1405 Madison St", "Constance");
		
		// cria comida Arroz, custa 5 reais, do tipo Graos, 100g dele
		Comida comida1 = new Comida("Arroz", 5, "Graos", 100);
		
		// cria comida Feijão, custa 7 reais, do tipo Graos, 80g dele
		Comida comida2 = new Comida("Feijao", 7, "Graos", 80);
		
		// cria comida Carne-Bovina, custa 10 reais, do tipo Carne, 50g dela
		Comida comida3 = new Comida("Carne-Bovina", 10, "Carne", 50);
		
		// cria comida Salada, custa 3 reais, do tipo Legumes, 20g dela
		Comida comida4 = new Comida("Salada", 3, "Legumes", 20);
		
		// cria comida por peso Açaí, do tipo Gelados, 500g dele e custa R$ 32.99 o Kg
		ComidaPorPeso cpp1 = new ComidaPorPeso("Açaí", "Gelados", 500, 32.99f);
		
		
		// adiciona as 5 comidas no Menu em suas respectivas quantidades
		RU.getiFood().getMenu().adicionarComida(comida1, 2);
		RU.getiFood().getMenu().adicionarComida(comida2, 3);
		RU.getiFood().getMenu().adicionarComida(comida3, 4);
		RU.getiFood().getMenu().adicionarComida(comida4, 1);
		RU.getiFood().getMenu().adicionarComida(cpp1, 1);
		
		// mostra o menu do RU
		RU.getiFood().getMenu().mostrarMenu();
			
		// dinheiro inicial dos clientes normal e vip
		System.out.println("\nDinheiro inicial do cliente normal:");
		System.out.printf("R$ %.2f\n", c1.getDinheiro());
		
		System.out.println("Dinheiro incial do cliente vip:");
		System.out.printf("R$ %.2f\n", cv1.getDinheiro());
		
		
		// clientes normal e cliente vip obtêm carrinho do RU
		c1.obterCarrinho(RU);
		cv1.obterCarrinho(RU);
		
		
		// adiciona comidas nos carrinho do cliente normal e do cliente vip
		c1.getCarrinho().adicionarComida("Carne-Bovina");
		c1.getCarrinho().adicionarComida("Feijao");
		
		cv1.getCarrinho().adicionarComida("Açaí");
		cv1.getCarrinho().adicionarComida("Salada");
		
		// mostra carrinho do cliente normal
		System.out.println("\nCarrinho do cliente normal: ");
		c1.getCarrinho().verItens();
		
		// mostra carrinho do cliente Vip
		System.out.println("\nCarrinho do cliente vip: ");
		cv1.getCarrinho().verItens();
				
		
		// Restaurante realiza entrega dos carrinhos dos cliente normal e vip
		RU.EntregarComida(c1);
		RU.EntregarComida(cv1);
		
		// dinheiro atualizado dos clientes normal e vip
		System.out.println("\nDinheiro atualizado depois da compra do cliente normal:");
		System.out.printf("R$ %.2f\n", c1.getDinheiro());
		
		System.out.println("Dinheiro atualizado depois da compra do cliente vip:");
		System.out.printf("R$ %.2f\n", cv1.getDinheiro());

		
	}

}
