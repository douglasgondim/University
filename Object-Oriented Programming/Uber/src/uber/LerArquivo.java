package uber;

import java.io.*;
import java.util.*;

public class LerArquivo {
	private Scanner leitor;

	public LerArquivo() {}

	public void abrirArquivoCidade() {
		try {
			leitor = new Scanner(new File("cidade"));
		}
		catch(Exception e) {
			System.out.println("Arquivo não encontrado");
		}
	}

	public void abrirArquivoClientes() {
		try {
			leitor = new Scanner(new File("clientes"));
		}
		catch(Exception e) {
			System.out.println("Arquivo não encontrado");
		}
	}

	public void abrirArquivoMotoristas() {
		try {
			leitor = new Scanner(new File("motoristas"));
		}
		catch(Exception e) {
			System.out.println("Arquivo não encontrado");
		}
	}

	public float[][] lerArquivoCidade() {


		int paradas = Integer.parseInt(leitor.next());
		float[][] mapa = new float[paradas][paradas];

		while(leitor.hasNextLine()) {
			int x = Integer.parseInt(leitor.next());
			int y = Integer.parseInt(leitor.next());
			float distancia = Float.valueOf(leitor.next());
			mapa[x-1][y-1] = distancia;
			mapa[y-1][x-1] = distancia;
		}

		return mapa;
	}
	


	public Cliente[] lerArquivoCliente() {
		int tam=0, i=0;
		while(leitor.hasNextLine()) {
			tam++;
			leitor.nextLine();
		}
		fecharArquivo();		
		abrirArquivoClientes();
		
		Cliente[] clientes = new Cliente[tam];
		while(leitor.hasNextLine()) {
			Cliente novo = new Cliente(leitor.next(), leitor.nextInt(), leitor.nextInt());
			clientes[i] = novo;
			i++;
		}
		return clientes;
	}

	public Motorista[] lerArquivoMotorista() {
		int tam=0, i=0;
		while(leitor.hasNextLine()) {
			tam++;
			leitor.nextLine();
		}
		fecharArquivo();
		abrirArquivoMotoristas();
	
		Motorista[] motoristas = new Motorista[tam];
		while(leitor.hasNextLine()) {
			Motorista novo = new Motorista(leitor.next(), leitor.nextInt(), leitor.nextFloat(), leitor.nextFloat());
			motoristas[i] = novo;
			i++;
		}
		return motoristas;
	}



	public void fecharArquivo() {
		leitor.close();
	}

	public static void main(String[] args) {
		LerArquivo a = new LerArquivo();
		a.abrirArquivoClientes();
		a.lerArquivoCliente();
		a.fecharArquivo();
		System.out.println("a");
	}

	public Scanner getLeitor() {
		return leitor;
	}

	public void setLeitor(Scanner leitor) {
		this.leitor = leitor;
	}



}
