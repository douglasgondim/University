package view;

import java.util.ArrayList;

import org.eclipse.swt.SWT;
import org.eclipse.swt.custom.CTabFolder;
import org.eclipse.swt.custom.CTabItem;
import org.eclipse.swt.events.SelectionAdapter;
import org.eclipse.swt.events.SelectionEvent;
import org.eclipse.swt.widgets.Button;
import org.eclipse.swt.widgets.Composite;
import org.eclipse.swt.widgets.Display;
import org.eclipse.swt.widgets.Group;
import org.eclipse.swt.widgets.Label;
import org.eclipse.swt.widgets.MessageBox;
import org.eclipse.swt.widgets.Shell;
import org.eclipse.swt.widgets.Text;
import org.eclipse.wb.swt.SWTResourceManager;

import org.eclipse.swt.widgets.Table;
import org.eclipse.swt.widgets.TableItem;
import org.eclipse.swt.widgets.TableColumn;
import org.eclipse.swt.widgets.TabFolder;
import org.eclipse.swt.widgets.TabItem;

public class TelaBibliotecario {
	
	private Display display = new Display();
	private TelaBibliotecarioController tbController = new TelaBibliotecarioController(this);
	private String user;
	protected Shell shell;
	private CTabFolder tabFolder;
	private CTabItem tbtmBusca;
	private CTabItem tbtmCadastro;
	
	//Janela de Busca
	private Text textBusca;
	private Label lblBusca;
	int selRadio = 1;
	private Group group;
	private Composite compositeBusca;
	private Button btnRadioButtonLivro;
	private Button btnRadioButtonUsuario;
	private Button btnRadioButtonEmprestimo;
	private Button btnRadioButtonDevolucao;
	private Button btnRadioButtonReserva;
	private Table table;
	private TableItem tableItem;
	private TableColumn tblclmnNewColumn_1;
	private TableColumn tblclmnNewColumn_2;
	private TableColumn tblclmnNewColumn_3;
	private TableColumn tblclmnNewColumn_4;
	private Button btnBuscar;
	private Button btnLimpar;
	
	//Janela de Cadastro -- Na ordem Livro, Usuario, Autor, Editora (CL, CU, CA, CE)
	private TabFolder tabFolderCadastro;
	private TabItem tbtmCLivro;
	private TabItem tbtmCUsuario;
	private TabItem tbtmCAutor;
	private TabItem tbtmCEditora;
	private TabItem tbtmCExemplar;
	private Composite compositeCLivro;
	private Composite compositeCExemplar;
	private Composite compositeCUsuario;
	private Composite compositeCAutor;
	private Composite compositeCEditora;
	private Label lblCLNome;
	private Label lblCLAutor;
	private Label lblCLEditora;
	private Label lblCLGenero;
	private Label lblCLCapa;
	private Label lblCLSumario;
	private Label lblCLPalavras_chave;
	private Label lblCLNum_pags;
	private Label lblCLPais;
	private Label lblCLAno_public;
	private Label lblCLQtd_exemp;
	private Label lblCExCod_livro;
	private Label lblCExEdicao;
	private Label lblCExAno;
	private Label lblCExDisp;
	private Label lblCExEstado;
	private Label lblCUNome;
	private Label lblCUCpf;
	private Label lblCURg;
	private Label lblCUFoto;
	private Label lblCULim_livro;
	private Label lblCUEmail;
	private Label lblCUSenha;
	private Label lblCUNivel;
	private Label lblCUTelefone;
	private Label lblCUEndereco;
	private Label lblCUCidade;
	private Label lblCUEstado;
	private Label lblCUCep;
	private Label lblCANome;
	private Label lblCABiografia;
	private Label lblCAFoto;
	private Label lblCENome;
	private Label lblCEContato;
	private Label lblCECnpj;
	private Text textCLTitulo;
	private Text textCLAutor;
	private Text textCLEditora;	
	private Text textCLGenero;
	private Text textCLCapa;
	private Text textCLSumario;
	private Text textCLPalavras_chave;
	private Text textCLNum_pags;
	private Text textCLPais;
	private Text textCLQtd_exemp;
	private Text textCLAno_public;
	private Text textCExCod_livro;
	private Text textCExEdicao;
	private Text textCExAno;
	private Text textCExEstado;
	private Text textCExDisp;
	private Text textCUNome;
	private Text textCUCpf;
	private Text textCUSenha;
	private Text textCURg;
	private Text textCUFoto;
	private Text textCULim_livros;
	private Text textCUEmail;
	private Text textCUNivel;
	private Text textCUTelefone;
	private Text textCUEndereco;
	private Text textCUCidade;
	private Text textCUEstado;
	private Text textCUCep;
	private Text textCANome;
	private Text textCABiografia;
	private Text textCAFoto;
	private Text textCENome;
	private Text textCEContato;
	private Text textCECnpj;
	private Button btnCLCadastrar;
	private Button btnCLLimpar;
	private Button btnCExCadastrar;
	private Button btnCExLimpar;
	private Button btnCUCadastrar;
	private Button btnCULimpar;
	private Button btnCACadastrar;
	private Button btnCALimpar;
	private Button btnCECadastrar;
	private Button btnCELimpar;
	
	//Janela Autorizar e Receber
	
	private CTabItem tbtmEmprestimo;
	private Composite compositeEmp_Dev;
	private Label lblEDAluno;
	private Label lblEDSenha;
	private Label lblEDLivro;
	private Label lblEDMulta;
	private Label lblEDValorMulta;
	private Text textEDAluno;
	private Text textEDLivro;
	private Text textEDSenha;
	private Button btnEDAutorizar;
	private Button btnEDLimpar;
	private Button btnEDDevolucao;
	
	public TelaBibliotecario(String user) {
		this.user = user;
		try {
			exibirTelaBiblio();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	protected void exibirTelaBiblio() {
		shell = new Shell(display);
		shell.setSize(1000, 500);
		shell.setText("Biblioteca");
		
		tabFolder = new CTabFolder(shell, SWT.BORDER);
		tabFolder.setBounds(0, 0, 994, 432);
		tabFolder.setSelectionBackground(Display.getCurrent().getSystemColor(SWT.COLOR_TITLE_INACTIVE_BACKGROUND_GRADIENT));
		
		//Primeira Tela "Busca"
		
		tbtmBusca = new CTabItem(tabFolder, SWT.NONE);
		tbtmBusca.setText("Busca");
		
		compositeBusca = new Composite(tabFolder, SWT.NONE);
		tbtmBusca.setControl(compositeBusca);
				
		textBusca = new Text(compositeBusca, SWT.BORDER);
		textBusca.setBounds(10, 42, 466, 23);
		
		lblBusca = new Label(compositeBusca, SWT.NONE);
		lblBusca.setFont(SWTResourceManager.getFont("Noto Sans", 14, SWT.NORMAL));
		lblBusca.setBounds(10, 10, 71, 26);
		lblBusca.setText("Busca:");
		
		group = new Group(compositeBusca, SWT.NONE);
		group.setBounds(10, 71, 466, 26);
		
		btnRadioButtonLivro = new Button(group, SWT.RADIO);
		btnRadioButtonLivro.setBounds(0, 4, 91, 17);
		btnRadioButtonLivro.setSelection(true);
		btnRadioButtonLivro.setText("Livros");
		
		btnRadioButtonUsuario = new Button(group, SWT.RADIO);
		btnRadioButtonUsuario.setBounds(97, 4, 91, 17);
		btnRadioButtonUsuario.setText("Usuário");
		
		btnRadioButtonEmprestimo = new Button(group, SWT.RADIO);
		btnRadioButtonEmprestimo.setBounds(194, 4, 91, 17);
		btnRadioButtonEmprestimo.setText("Empréstimo");
				
		btnRadioButtonDevolucao = new Button(group, SWT.RADIO);
		btnRadioButtonDevolucao.setBounds(291, 4, 91, 17);
		btnRadioButtonDevolucao.setText("Devolução");
		
		btnRadioButtonReserva = new Button(group, SWT.RADIO);
		btnRadioButtonReserva.setBounds(388, 4, 76, 17);
		btnRadioButtonReserva.setText("Reserva");
		
		btnBuscar = new Button(compositeBusca, SWT.NONE);
		btnBuscar.setBounds(10, 103, 83, 23);
		btnBuscar.setText("Buscar");
		
		btnLimpar = new Button(compositeBusca, SWT.NONE);
		btnLimpar.setBounds(99, 103, 83, 23);
		btnLimpar.setText("Limpar");
		
		table = new Table(compositeBusca, SWT.BORDER | SWT.FULL_SELECTION);
		table.setBounds(482, 42, 500, 250);
		table.setHeaderVisible(true);
		table.setLinesVisible(true);
		
		tblclmnNewColumn_1 = new TableColumn(table, SWT.NONE);
		tblclmnNewColumn_1.setWidth(124);
		
		tblclmnNewColumn_2 = new TableColumn(table, SWT.NONE);
		tblclmnNewColumn_2.setWidth(124);
		
		tblclmnNewColumn_3 = new TableColumn(table, SWT.NONE);
		tblclmnNewColumn_3.setWidth(124);
		
		tblclmnNewColumn_4 = new TableColumn(table, SWT.NONE);
		tblclmnNewColumn_4.setWidth(124);
						
		limparTela();
		
		SelectionAdapter sa = new SelectionAdapter() {
			@Override
			public void widgetSelected(SelectionEvent e) {
				switch (((Button) e.getSource()).getText()){
				case "Livros":
					selRadio = 1;
					break;
				case "Usuário":
					selRadio = 2;
					break;
				case "Empréstimo":
					selRadio = 3;
					break;
				case "Devolução":
					selRadio = 4;
					break;
				case "Reserva":
					selRadio = 5;
					break;
				}
				if (((Button) e.getSource()).getText().equals("Buscar")) {
					table.removeAll();
					tbController.setEvent(e, selRadio);
				}else {
					tbController.setEvent(e, selRadio);
				}
			}
		};
		
		btnRadioButtonLivro.addSelectionListener(sa);
		btnRadioButtonUsuario.addSelectionListener(sa);
		btnRadioButtonEmprestimo.addSelectionListener(sa);
		btnRadioButtonDevolucao.addSelectionListener(sa);
		btnRadioButtonReserva.addSelectionListener(sa);
		btnBuscar.addSelectionListener(sa);
		btnLimpar.addSelectionListener(sa);
		
		//Segunda Tela "Cadastro"
		
		tbtmCadastro = new CTabItem(tabFolder, SWT.NONE);
		tbtmCadastro.setText("Cadastrar");
		
		tabFolderCadastro = new TabFolder(tabFolder, SWT.NONE);
		tbtmCadastro.setControl(tabFolderCadastro);
		
		//Cadastro de livro
		tbtmCLivro = new TabItem(tabFolderCadastro, SWT.NONE);
		tbtmCLivro.setText("Livro");
		
		compositeCLivro = new Composite(tabFolderCadastro, SWT.NONE);
		tbtmCLivro.setControl(compositeCLivro);
		
		lblCLNome = new Label(compositeCLivro, SWT.NONE);
		lblCLNome.setBounds(10, 21, 37, 17);
		lblCLNome.setText("Titulo:");
		
		lblCLAutor = new Label(compositeCLivro, SWT.NONE);
		lblCLAutor.setBounds(10, 53, 37, 17);
		lblCLAutor.setText("Autor:");
		
		lblCLEditora = new Label(compositeCLivro, SWT.NONE);
		lblCLEditora.setBounds(10, 89, 52, 17);
		lblCLEditora.setText("Editora:");
		
		lblCLGenero = new Label(compositeCLivro, SWT.NONE);
		lblCLGenero.setBounds(10, 125, 52, 17);
		lblCLGenero.setText("Gênero:");
		
		lblCLCapa = new Label(compositeCLivro, SWT.NONE);
		lblCLCapa.setBounds(10, 165, 37, 17);
		lblCLCapa.setText("Capa:");
		
		lblCLNum_pags = new Label(compositeCLivro, SWT.NONE);
		lblCLNum_pags.setBounds(10, 205, 102, 17);
		lblCLNum_pags.setText("Num. de páginas:");
		
		lblCLPais = new Label(compositeCLivro, SWT.NONE);
		lblCLPais.setBounds(10, 240, 37, 17);
		lblCLPais.setText("País:");
		
		lblCLAno_public = new Label(compositeCLivro, SWT.NONE);
		lblCLAno_public.setBounds(10, 283, 95, 17);
		lblCLAno_public.setText("Ano publicação:");
		
		lblCLQtd_exemp = new Label(compositeCLivro, SWT.NONE);
		lblCLQtd_exemp.setBounds(10, 328, 83, 17);
		lblCLQtd_exemp.setText("Qtd. exemplar:");
		
		lblCLSumario = new Label(compositeCLivro, SWT.NONE);
		lblCLSumario.setBounds(441, 21, 58, 17);
		lblCLSumario.setText("Sumario:");
		
		lblCLPalavras_chave = new Label(compositeCLivro, SWT.NONE);
		lblCLPalavras_chave.setBounds(441, 205, 95, 17);
		lblCLPalavras_chave.setText("Palavras chave:");
		
		textCLTitulo = new Text(compositeCLivro, SWT.BORDER);
		textCLTitulo.setBounds(54, 15, 304, 23);
		
		textCLAutor = new Text(compositeCLivro, SWT.BORDER);
		textCLAutor.setBounds(54, 47, 47, 23);
		
		textCLEditora = new Text(compositeCLivro, SWT.BORDER);
		textCLEditora.setBounds(68, 83, 47, 23);
		
		textCLGenero = new Text(compositeCLivro, SWT.BORDER);
		textCLGenero.setBounds(68, 119, 126, 23);
		
		textCLCapa = new Text(compositeCLivro, SWT.BORDER);
		textCLCapa.setBounds(54, 159, 304, 23);
		
		textCLNum_pags = new Text(compositeCLivro, SWT.BORDER);
		textCLNum_pags.setBounds(117, 199, 47, 23);
		
		textCLPais = new Text(compositeCLivro, SWT.BORDER);
		textCLPais.setBounds(54, 234, 126, 23);
		
		textCLAno_public = new Text(compositeCLivro, SWT.BORDER | SWT.SetData);
		textCLAno_public.setBounds(111, 277, 47, 23);
		
		textCLQtd_exemp = new Text(compositeCLivro, SWT.BORDER);
		textCLQtd_exemp.setBounds(99, 322, 47, 23);
		
		textCLSumario = new Text(compositeCLivro, SWT.BORDER | SWT.MULTI);
		textCLSumario.setBounds(441, 47, 370, 135);
		
		textCLPalavras_chave = new Text(compositeCLivro, SWT.BORDER | SWT.MULTI);
		textCLPalavras_chave.setBounds(441, 228, 370, 60);
		
		btnCLCadastrar = new Button(compositeCLivro, SWT.NONE);
		btnCLCadastrar.setBounds(814, 330, 83, 23);
		btnCLCadastrar.setText("Cadastrar");
		
		btnCLLimpar = new Button(compositeCLivro, SWT.NONE);
		btnCLLimpar.setBounds(903, 330, 83, 23);
		btnCLLimpar.setText("Limpar");
		
		limparTelaCLivro();
		
		SelectionAdapter sa_1 = new SelectionAdapter() {
			@Override
			public void widgetSelected(SelectionEvent e) {
				if (((Button) e.getSource()).getText().equals("Cadastrar")) {
					if(textCLTitulo.getText().equals("") || textCLEditora.getText().equals("") ||
							textCLAutor.getText().equals("") || textCLGenero.getText().equals("") || textCLCapa.getText().equals("") || textCLPalavras_chave.getText().equals("")
							|| !textCLAutor.getText().matches("[0-9]*") || !textCLEditora.getText().matches("[0-9]*") || !textCLQtd_exemp.getText().matches("[0-9]*")
							|| !textCLNum_pags.getText().matches("[0-9]*") || textCLSumario.getText().equals("") || textCLAno_public.getText().equals("")) {
						mensagemErro();
					}else {
						tbController.setEventCLivro();
					}
				}else {
					limparTelaCLivro();
				}
			}
		};
		btnCLCadastrar.addSelectionListener(sa_1);
		btnCLLimpar.addSelectionListener(sa_1);
		
		tbtmCExemplar = new TabItem(tabFolderCadastro, SWT.NONE);
		tbtmCExemplar.setText("Exemplar");
		
		compositeCExemplar = new Composite(tabFolderCadastro, SWT.NONE);
		tbtmCExemplar.setControl(compositeCExemplar);
		
		lblCExCod_livro = new Label(compositeCExemplar, SWT.NONE);
		lblCExCod_livro.setBounds(10, 10, 58, 17);
		lblCExCod_livro.setText("Cod. Livro:");
		
		lblCExEdicao = new Label(compositeCExemplar, SWT.NONE);
		lblCExEdicao.setBounds(10, 52, 50, 17);
		lblCExEdicao.setText("Edição:");
		
		lblCExAno = new Label(compositeCExemplar, SWT.NONE);
		lblCExAno.setBounds(10, 93, 37, 17);
		lblCExAno.setText("Ano:");
		
		lblCExEstado = new Label(compositeCExemplar, SWT.NONE);
		lblCExEstado.setBounds(10, 140, 50, 17);
		lblCExEstado.setText("Estado:");
		
		lblCExDisp = new Label(compositeCExemplar, SWT.NONE);
		lblCExDisp.setBounds(10, 179, 89, 17);
		lblCExDisp.setText("Disponibilidade:");
		
		textCExCod_livro = new Text(compositeCExemplar, SWT.BORDER);
		textCExCod_livro.setBounds(74, 4, 83, 23);
		
		textCExEdicao = new Text(compositeCExemplar, SWT.BORDER);
		textCExEdicao.setBounds(66, 46, 55, 23);
		
		textCExAno = new Text(compositeCExemplar, SWT.BORDER);
		textCExAno.setBounds(53, 87, 55, 23);
		
		textCExEstado = new Text(compositeCExemplar, SWT.BORDER);
		textCExEstado.setBounds(66, 134, 110, 23);
		
		textCExDisp = new Text(compositeCExemplar, SWT.BORDER);
		textCExDisp.setBounds(105, 173, 55, 23);
		
		btnCExCadastrar = new Button(compositeCExemplar, SWT.NONE);
		btnCExCadastrar.setBounds(10, 226, 83, 23);
		btnCExCadastrar.setText("Cadastrar");
		
		btnCExLimpar = new Button(compositeCExemplar, SWT.NONE);
		btnCExLimpar.setBounds(105, 226, 83, 23);
		btnCExLimpar.setText("Limpar");
		
		limparTelaCExemplar();
		
		SelectionAdapter sa_2 = new SelectionAdapter() {
			@Override
			public void widgetSelected(SelectionEvent e) {
				if (((Button) e.getSource()).getText().equals("Cadastrar")) {
					if(!textCExEdicao.getText().matches("[0-9]*") || !textCExAno.getText().matches("[0-9]*") || !textCExCod_livro.getText().matches("[0-9]*")
							|| !textCExDisp.getText().matches("[0-9]*") || textCExEstado.getText().equals("")) {
						mensagemErro();
					}else {
						tbController.setEventCExemplar();
					}
				}else {
					limparTelaCExemplar();
				}
			}
		};
		btnCExCadastrar.addSelectionListener(sa_2);
		btnCExLimpar.addSelectionListener(sa_2);
		
		//Cadastro de Usuario
		tbtmCUsuario = new TabItem(tabFolderCadastro, SWT.NONE);
		tbtmCUsuario.setText("Usuário");
		
		compositeCUsuario = new Composite(tabFolderCadastro, SWT.NONE);
		tbtmCUsuario.setControl(compositeCUsuario);
		
		lblCUNome = new Label(compositeCUsuario, SWT.NONE);
		lblCUNome.setBounds(10, 21, 37, 17);
		lblCUNome.setText("Nome : ");
		
		lblCUCpf = new Label(compositeCUsuario, SWT.NONE);
		lblCUCpf.setBounds(10, 53, 37, 17);
		lblCUCpf.setText("CPF :");
		
		lblCURg = new Label(compositeCUsuario, SWT.NONE);
		lblCURg.setText("RG:");
		lblCURg.setBounds(10, 89, 29, 17);
		
		lblCUFoto = new Label(compositeCUsuario, SWT.NONE);
		lblCUFoto.setBounds(10, 125, 37, 17);
		lblCUFoto.setText("Foto:");
		
		lblCULim_livro = new Label(compositeCUsuario, SWT.NONE);
		lblCULim_livro.setBounds(10, 166, 91, 17);
		lblCULim_livro.setText("Limite de livros:");
		
		lblCUEmail = new Label(compositeCUsuario, SWT.NONE);
		lblCUEmail.setBounds(403, 21, 37, 17);
		lblCUEmail.setText("Email:");
		
		lblCUSenha = new Label(compositeCUsuario, SWT.NONE);
		lblCUSenha.setBounds(403, 59, 52, 17);
		lblCUSenha.setText("Senha :");
		
		lblCUNivel = new Label(compositeCUsuario, SWT.NONE);
		lblCUNivel.setBounds(403, 95, 37, 17);
		lblCUNivel.setText("Nivel:");
		
		lblCUTelefone = new Label(compositeCUsuario, SWT.NONE);
		lblCUTelefone.setBounds(660, 21, 58, 17);
		lblCUTelefone.setText("Telefone:");
		
		lblCUEndereco = new Label(compositeCUsuario, SWT.NONE);
		lblCUEndereco.setBounds(660, 59, 58, 17);
		lblCUEndereco.setText("Endereço:");
		
		lblCUCidade = new Label(compositeCUsuario, SWT.NONE);
		lblCUCidade.setBounds(660, 95, 47, 17);
		lblCUCidade.setText("Cidade:");
		
		lblCUEstado = new Label(compositeCUsuario, SWT.NONE);
		lblCUEstado.setBounds(660, 131, 47, 17);
		lblCUEstado.setText("Estado:");
		
		lblCUCep = new Label(compositeCUsuario, SWT.NONE);
		lblCUCep.setBounds(660, 166, 37, 17);
		lblCUCep.setText("CEP:");
		
		textCUNome = new Text(compositeCUsuario, SWT.BORDER);
		textCUNome.setBounds(54, 15, 304, 23);
		
		textCUCpf = new Text(compositeCUsuario, SWT.BORDER);
		textCUCpf.setBounds(53, 53, 189, 23);
		
		textCURg = new Text(compositeCUsuario, SWT.BORDER);
		textCURg.setBounds(54, 89, 188, 23);
		
		textCUFoto = new Text(compositeCUsuario, SWT.BORDER);
		textCUFoto.setBounds(53, 125, 304, 23);
		
		textCULim_livros = new Text(compositeCUsuario, SWT.BORDER);
		textCULim_livros.setBounds(106, 160, 47, 23);
		
		textCUEmail = new Text(compositeCUsuario, SWT.BORDER);
		textCUEmail.setBounds(446, 15, 163, 23);
		
		textCUSenha = new Text(compositeCUsuario, SWT.BORDER | SWT.PASSWORD);
		textCUSenha.setBounds(456, 53, 163, 23);
		
		textCUNivel = new Text(compositeCUsuario, SWT.BORDER);
		textCUNivel.setBounds(446, 89, 47, 23);
		
		textCUTelefone = new Text(compositeCUsuario, SWT.BORDER);
		textCUTelefone.setBounds(724, 15, 188, 23);
		
		textCUEndereco = new Text(compositeCUsuario, SWT.BORDER);
		textCUEndereco.setBounds(724, 53, 257, 23);
		
		textCUCidade = new Text(compositeCUsuario, SWT.BORDER);
		textCUCidade.setBounds(708, 89, 188, 23);
		
		textCUEstado = new Text(compositeCUsuario, SWT.BORDER);
		textCUEstado.setBounds(708, 125, 188, 23);
		
		textCUCep = new Text(compositeCUsuario, SWT.BORDER);
		textCUCep.setBounds(698, 160, 91, 23);
		
		btnCUCadastrar = new Button(compositeCUsuario, SWT.NONE);
		btnCUCadastrar.setBounds(814, 330, 83, 23);
		btnCUCadastrar.setText("Cadastrar");
		
		btnCULimpar = new Button(compositeCUsuario, SWT.NONE);
		btnCULimpar.setBounds(903, 330, 83, 23);
		btnCULimpar.setText("Limpar");
		
		SelectionAdapter sa_3 = new SelectionAdapter() {
			@Override
			public void widgetSelected(SelectionEvent e) {
				if (((Button) e.getSource()).getText().equals("Cadastrar")) {
					if(textCUNome.getText().equals("") || textCUCpf.getText().equals("") || textCURg.getText().equals("")
							|| textCUFoto.getText().equals("") || textCULim_livros.getText().equals("") || !textCULim_livros.getText().matches("[0-9]*")
							|| !textCUCpf.getText().matches("[0-9]*") || !textCURg.getText().matches("[0-9]*") || textCUEmail.getText().equals("") || textCUSenha.getText().equals("")
							|| textCUNivel.getText().equals("") || !textCUNivel.getText().matches("[0-9]*") || textCUTelefone.getText().equals("") || textCUEndereco.getText().equals("")
							|| textCUCidade.getText().equals("") || textCUEstado.getText().equals("") || textCUCep.getText().equals("") || !textCUTelefone.getText().matches("[0-9]*") || !textCUCep.getText().matches("[0-9]*")) {
						mensagemErro();
					}else {
						tbController.setEventCUsuario();
					}
				}else {
					limparTelaCUsuario();
				}
			}
		};
		btnCULimpar.addSelectionListener(sa_3);
		btnCUCadastrar.addSelectionListener(sa_3);
		
		//Cadastro de Autor
		tbtmCAutor = new TabItem(tabFolderCadastro, SWT.NONE);
		tbtmCAutor.setText("Autor");
		
		compositeCAutor = new Composite(tabFolderCadastro, SWT.NONE);
		tbtmCAutor.setControl(compositeCAutor);
		
		lblCANome = new Label(compositeCAutor, SWT.NONE);
		lblCANome.setBounds(10, 21, 37, 17);
		lblCANome.setText("Nome:");
		
		lblCAFoto = new Label(compositeCAutor, SWT.NONE);
		lblCAFoto.setBounds(10, 47, 37, 17);
		lblCAFoto.setText("Foto:");
		
		lblCABiografia = new Label(compositeCAutor, SWT.NONE);
		lblCABiografia.setBounds(10, 84, 62, 17);
		lblCABiografia.setText("Biografia:");
		
		textCANome = new Text(compositeCAutor, SWT.BORDER);
		textCANome.setBounds(53, 15, 235, 23);
		
		textCAFoto = new Text(compositeCAutor, SWT.BORDER);
		textCAFoto.setBounds(53, 47, 312, 23);
		
		textCABiografia = new Text(compositeCAutor, SWT.BORDER | SWT.MULTI);
		textCABiografia.setBounds(78, 84, 369, 120);
		
		btnCACadastrar = new Button(compositeCAutor, SWT.NONE);
		btnCACadastrar.setBounds(275, 210, 83, 23);
		btnCACadastrar.setText("Cadastrar");
		
		btnCALimpar = new Button(compositeCAutor, SWT.NONE);
		btnCALimpar.setBounds(364, 210, 83, 23);
		btnCALimpar.setText("Limpar");
		
		SelectionAdapter sa_4 = new SelectionAdapter() {
			@Override
			public void widgetSelected(SelectionEvent e) {
				if (((Button) e.getSource()).getText().equals("Cadastrar")) {
					if(textCANome.getText().equals("") || textCABiografia.getText().equals("") || textCAFoto.getText().equals("")) {
						mensagemErro();
					}else {
						tbController.setEventCAutor();
					}
				}else {
					limparTelaCAutor();
				}
			}
		};
		btnCACadastrar.addSelectionListener(sa_4);
		btnCALimpar.addSelectionListener(sa_4);
		
		//Cadastro de Editora
		tbtmCEditora = new TabItem(tabFolderCadastro, SWT.NONE);
		tbtmCEditora.setText("Editora");
		
		compositeCEditora = new Composite(tabFolderCadastro, SWT.NONE);
		tbtmCEditora.setControl(compositeCEditora);
		
		lblCENome = new Label(compositeCEditora, SWT.NONE);
		lblCENome.setBounds(10, 21, 37, 17);
		lblCENome.setText("Nome:");
		
		lblCEContato = new Label(compositeCEditora, SWT.NONE);
		lblCEContato.setBounds(10, 53, 62, 17);
		lblCEContato.setText("Contato:");
		
		lblCECnpj = new Label(compositeCEditora, SWT.NONE);
		lblCECnpj.setBounds(10, 89, 62, 17);
		lblCECnpj.setText("CNPJ:");
		
		textCENome = new Text(compositeCEditora, SWT.BORDER);
		textCENome.setBounds(53, 15, 235, 23);
		
		textCEContato = new Text(compositeCEditora, SWT.BORDER);
		textCEContato.setBounds(72, 47, 190, 23);
		
		textCECnpj = new Text(compositeCEditora, SWT.BORDER);
		textCECnpj.setBounds(72, 83, 190, 23);
		
		btnCECadastrar = new Button(compositeCEditora, SWT.NONE);
		btnCECadastrar.setBounds(72, 112, 83, 23);
		btnCECadastrar.setText("Cadastrar");
		
		btnCELimpar = new Button(compositeCEditora, SWT.NONE);
		btnCELimpar.setBounds(179, 112, 83, 23);
		btnCELimpar.setText("Limpar");
		
		SelectionAdapter sa_5 = new SelectionAdapter() {
			@Override
			public void widgetSelected(SelectionEvent e) {
				if (((Button) e.getSource()).getText().equals("Cadastrar")) {
					if(textCENome.getText().equals("") || textCEContato.getText().equals("") || textCECnpj.getText().equals("")
							|| !textCEContato.getText().matches("[0-9]*") || !textCECnpj.getText().matches("[0-9]*")) {
						mensagemErro();
					}else {
						tbController.setEventCEditora();
					}
				}else {
					limparTelaCEditora();
				}
			}
		};
		btnCECadastrar.addSelectionListener(sa_5);
		btnCELimpar.addSelectionListener(sa_5);
		
		//Terceira Tela "Autorizar e Receber"
		
		tbtmEmprestimo = new CTabItem(tabFolder, SWT.NONE);
		tbtmEmprestimo.setText("Emprestimo");
		
		compositeEmp_Dev = new Composite(tabFolder, SWT.NONE);
		tbtmEmprestimo.setControl(compositeEmp_Dev);
		
		lblEDAluno = new Label(compositeEmp_Dev, SWT.NONE);
		lblEDAluno.setBounds(10, 10, 72, 17);
		lblEDAluno.setText("Login aluno:");
		
		lblEDSenha = new Label(compositeEmp_Dev, SWT.NONE);
		lblEDSenha.setBounds(10, 65, 58, 17);
		lblEDSenha.setText("Senha:");
		
		lblEDLivro = new Label(compositeEmp_Dev, SWT.NONE);
		lblEDLivro.setBounds(10, 126, 58, 17);
		lblEDLivro.setText("Livro:");
		
		textEDAluno = new Text(compositeEmp_Dev, SWT.BORDER);
		textEDAluno.setBounds(10, 33, 250, 23);
		
		textEDSenha = new Text(compositeEmp_Dev, SWT.BORDER | SWT.PASSWORD);
		textEDSenha.setBounds(10, 88, 250, 23);
		
		textEDLivro = new Text(compositeEmp_Dev, SWT.BORDER);
		textEDLivro.setBounds(10, 148, 72, 23);
		
		btnEDAutorizar = new Button(compositeEmp_Dev, SWT.NONE);
		btnEDAutorizar.setBounds(10, 177, 101, 23);
		btnEDAutorizar.setText("Empréstimo");
		
		btnEDDevolucao = new Button(compositeEmp_Dev, SWT.NONE);
		btnEDDevolucao.setText("Devolução");
		btnEDDevolucao.setBounds(117, 177, 101, 23);
		
		btnEDLimpar = new Button(compositeEmp_Dev, SWT.NONE);
		btnEDLimpar.setBounds(10, 206, 83, 23);
		btnEDLimpar.setText("Limpar");
		
		lblEDMulta = new Label(compositeEmp_Dev, SWT.NONE);
		lblEDMulta.setFont(SWTResourceManager.getFont("Noto Sans", 14, SWT.NORMAL));
		lblEDMulta.setBounds(300, 33, 58, 26);
		lblEDMulta.setText("Multa:");
		
		lblEDValorMulta = new Label(compositeEmp_Dev, SWT.NONE);
		lblEDValorMulta.setFont(SWTResourceManager.getFont("Noto Sans", 14, SWT.NORMAL));
		lblEDValorMulta.setBounds(364, 33, 129, 23);
		lblEDValorMulta.setText("-");
		
		limparTelaEmp_Dev();
		SelectionAdapter sa_6 = new SelectionAdapter() {
			@Override
			public void widgetSelected(SelectionEvent e) {
				if (((Button) e.getSource()).getText().equals("Empréstimo")) {
					if(textEDAluno.getText().equals("") || textEDSenha.getText().equals("") || !textEDLivro.getText().matches("[0-9]*")) {
						mensagemErro();
					}else {
						tbController.setEventEmprestimo();						
					}
				}else {
					if(((Button) e.getSource()).getText().equals("Devolução")) {
						if(textEDAluno.getText().equals("") || textEDSenha.getText().equals("") || !textEDLivro.getText().matches("[0-9]*")) {
							mensagemErro();
						} else {
							tbController.setEventDevolucao();							
						}						
					}else {
						limparTelaEmp_Dev();
					}
				}
				
			}
		};
		btnEDAutorizar.addSelectionListener(sa_6);
		btnEDLimpar.addSelectionListener(sa_6);
		btnEDDevolucao.addSelectionListener(sa_6);
		
		//Fazer Logout
		
		Button btnSair = new Button(shell, SWT.NONE);
		btnSair.setBounds(907, 433, 83, 34);
		btnSair.setText("Sair");
		
		SelectionAdapter sa_logout = new SelectionAdapter() {
			@Override
			public void widgetSelected(SelectionEvent e) {
				setVisible(false);
			}
		};
		btnSair.addSelectionListener(sa_logout);
		
		shell.open();
		while (!shell.isDisposed()) {
			if (!display.readAndDispatch()) {
				display.sleep();
			}
		}
	}
	
	public void mensagemErro() {
		MessageBox mensBox = new MessageBox(shell, SWT.ICON_WARNING);
		mensBox.setText("Aviso");
		mensBox.setMessage("Preencha todos os campos corretamente");
		mensBox.open();
	}
	
	public void mensagemErroEmail() {
		MessageBox mensBox = new MessageBox(shell, SWT.ICON_WARNING);
		mensBox.setText("Aviso");
		mensBox.setMessage("Email já cadastrado");
		mensBox.open();
	}
	
	public void cadastroRealizado(String cod) {
		MessageBox mensBox = new MessageBox(shell, SWT.ICON_INFORMATION);
		mensBox.setText("Info");
		mensBox.setMessage("Cadastro realizado com sucesso\n Código = " + cod);
		mensBox.open();
	}
	
	public void mensagemEmp_Dev(String msn) {
		MessageBox mensBox = new MessageBox(shell, SWT.ICON_INFORMATION);
		mensBox.setText("Info");
		mensBox.setMessage(msn);
		mensBox.open();
	}
	
	public String getUser() {
		return this.user;
	}
	
	//Metodos da Primeira Tela - "Busca"
	public void limparTela() {
		textBusca.setText("");
		tblclmnNewColumn_1.setText("");
		tblclmnNewColumn_2.setText("");
		tblclmnNewColumn_3.setText("");
		tblclmnNewColumn_4.setText("");
		table.removeAll();
	}

	public String getBusca() {
		return textBusca.getText();
	}
	
	public void resultBusca(ArrayList<Object> vec, int sel) {
		table.setVisible(true);
		switch (sel){
		case 1:
			tblclmnNewColumn_1.setText("Identificador");
			tblclmnNewColumn_2.setText("Livro");
			tblclmnNewColumn_3.setText("Autor");
			tblclmnNewColumn_4.setText("Editora");
			for (int i = 0; i < vec.size(); i+=4) {
				tableItem = new TableItem(table, SWT.NONE);
				tableItem.setText(0, vec.get(i).toString());
				tableItem.setText(1, vec.get(i+1).toString());
				tableItem.setText(2, vec.get(i+2).toString());
				tableItem.setText(3, vec.get(i+3).toString());
			}
			break;
		case 2:
			tblclmnNewColumn_1.setText("Identificador");
			tblclmnNewColumn_2.setText("Nome");
			tblclmnNewColumn_3.setText("Cpf");
			tblclmnNewColumn_4.setText("Limite livros");
			for (int i = 0; i < vec.size(); i+=4) {
				tableItem = new TableItem(table, SWT.NONE);
				tableItem.setText(0, vec.get(i).toString());
				tableItem.setText(1, vec.get(i+1).toString());
				tableItem.setText(2, vec.get(i+2).toString());
				tableItem.setText(3, vec.get(i+3).toString());
			}
			break;
		case 3:
			tblclmnNewColumn_1.setText("Usuario");
			tblclmnNewColumn_2.setText("Livro");
			tblclmnNewColumn_3.setText("Data Emprestimo");
			tblclmnNewColumn_4.setText("Data Devolucao");
			for (int i = 0; i < vec.size(); i+=4) {
				tableItem = new TableItem(table, SWT.NONE);
				tableItem.setText(0, vec.get(i).toString());
				tableItem.setText(1, vec.get(i+1).toString());
				tableItem.setText(2, vec.get(i+2).toString());
				tableItem.setText(3, vec.get(i+3).toString());
			}
			break;
		case 4:
			tblclmnNewColumn_1.setText("Nome");
			tblclmnNewColumn_2.setText("Titulo");
			tblclmnNewColumn_3.setText("Data Devolucao");
			tblclmnNewColumn_4.setText("Multa");
			for (int i = 0; i < vec.size(); i+=4) {
				tableItem = new TableItem(table, SWT.NONE);
				tableItem.setText(0, vec.get(i).toString());
				tableItem.setText(1, vec.get(i+1).toString());
				tableItem.setText(2, vec.get(i+2).toString());
				if(Double.parseDouble(vec.get(i+3).toString()) < 0) {
					tableItem.setText(3, "0");
				}else {
					tableItem.setText(3, vec.get(i+3).toString());
				}
				
			}
			break;
		case 5:
			tblclmnNewColumn_1.setText("Nome");
			tblclmnNewColumn_2.setText("Titulo");
			tblclmnNewColumn_3.setText("Data Pedido");
			tblclmnNewColumn_4.setText("Data Previsao");
			for (int i = 0; i < vec.size(); i+=4) {
				tableItem = new TableItem(table, SWT.NONE);
				tableItem.setText(0, vec.get(i).toString());
				tableItem.setText(1, vec.get(i+1).toString());
				tableItem.setText(2, vec.get(i+2).toString());
				tableItem.setText(3, vec.get(i+3).toString());
			}
			break;
		}
	}
	
	//Metodos da Segunda Tela - "Cadastro"
	
	public void limparTelaCLivro() {
		textCLTitulo.setText("");
		textCLAutor.setText("");
		textCLEditora.setText("");
		textCLGenero.setText("");
		textCLCapa.setText("");
		textCLSumario.setText("");
		textCLNum_pags.setText("");
		textCLPalavras_chave.setText("");
		textCLPais.setText("");
		textCLAno_public.setText("");
		textCLQtd_exemp.setText("");
	}
	
	public void limparTelaCExemplar() {
		textCExCod_livro.setText("");
		textCExEstado.setText("");
		textCExAno.setText("");
		textCExDisp.setText("");
		textCExEdicao.setText("");
	}
	
	public void limparTelaCUsuario() {
		textCUNome.setText("");
		textCUCpf.setText("");
		textCURg.setText("");
		textCUFoto.setText("");
		textCULim_livros.setText("");
		textCUEmail.setText("");
		textCUSenha.setText("");
		textCUNivel.setText("");
		textCUTelefone.setText("");
		textCUEndereco.setText("");
		textCUCidade.setText("");
		textCUEstado.setText("");
		textCUCep.setText("");
	}
	
	public void limparTelaCAutor() {
		textCANome.setText("");
		textCABiografia.setText("");
		textCAFoto.setText("");
	}
	
	public void limparTelaCEditora() {
		textCENome.setText("");
		textCEContato.setText("");
		textCECnpj.setText("");
	}
	
	public void valuesCLivro(ArrayList<Object> vec) {
		vec.add(textCLTitulo.getText());
		vec.add(textCLAutor.getText());
		vec.add(textCLEditora.getText());
		vec.add(textCLGenero.getText());
		vec.add(textCLCapa.getText());
		vec.add(textCLNum_pags.getText());
		vec.add(textCLPais.getText());
		vec.add(textCLAno_public.getText());
		vec.add(textCLQtd_exemp.getText());
		vec.add(textCLSumario.getText());
		vec.add(textCLPalavras_chave.getText());
	}
	
	public void valuesCExemplar(ArrayList<Object> vec) {
		vec.add(textCExCod_livro.getText());
		vec.add(textCExEdicao.getText());
		vec.add(textCExAno.getText());
		vec.add(textCExEstado.getText());
		vec.add(textCExDisp.getText());
	}
	
	public void valuesCUsuario(ArrayList<Object> vec) {
		vec.add(textCUNome.getText());
		vec.add(textCUCpf.getText());		
		vec.add(textCURg.getText());
		vec.add(textCUFoto.getText());
		vec.add(textCULim_livros.getText());
		vec.add(textCUEmail.getText());
		vec.add(textCUSenha.getText());
		vec.add(textCUNivel.getText());
		vec.add(textCUTelefone.getText());
		vec.add(textCUEndereco.getText());
		vec.add(textCUCidade.getText());
		vec.add(textCUEstado.getText());
		vec.add(textCUCep.getText());
	}
	
	public void valuesCAutor(ArrayList<Object> vec) {
		vec.add(textCANome.getText());
		vec.add(textCABiografia.getText());
		vec.add(textCAFoto.getText());
	}
	
	public void valuesCEditora(ArrayList<Object> vec) {
		vec.add(textCENome.getText());
		vec.add(textCEContato.getText());
		vec.add(textCECnpj.getText());
	}
	
	//Metodos terceira tela -- "Emprestimos"
	
	public void limparTelaEmp_Dev() {
		textEDAluno.setText("");
		textEDSenha.setText("");
		textEDLivro.setText("");
		lblEDMulta.setVisible(false);
		lblEDValorMulta.setVisible(false);
	}
	
	public void valuesEmp_Dev(ArrayList<Object> vec) {
		vec.add(textEDAluno.getText());
		vec.add(textEDSenha.getText());
		vec.add(textEDLivro.getText());
	}
	
	public void valorMulta(double valor) {
		lblEDMulta.setVisible(true);
		lblEDValorMulta.setVisible(true);
		if(valor > 0) {
			lblEDValorMulta.setText("R$ " + valor);
		}else {
			lblEDValorMulta.setText("R$ 0.00");
		}
	}
	
	public void setVisible(boolean aux) {
		shell.setVisible(aux);
		display.close();
		new TelaLogin();
	}
	
}