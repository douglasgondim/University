package view;

import dao.AutorDao;
import dao.ContatoDao;
import dao.DevolucaoDao;
import dao.EditoraDao;
import dao.EmprestimoDao;
import dao.ExemplarDao;
import dao.LivroDao;
import dao.LoginDao;
import dao.ReservaDao;
import dao.UsuarioDao;
import entidades.Autor;
import entidades.Contato;
import entidades.Editora;
import entidades.Exemplar;
import entidades.Livro;
import entidades.Login;
import entidades.Usuario;

import java.util.*;

import org.eclipse.swt.events.SelectionEvent;
import org.eclipse.swt.widgets.Button;

public class TelaBibliotecarioController {
	private ArrayList<Object> vec = new ArrayList<Object>();
	private TelaBibliotecario view;
	private AutorDao autd;
	private EditoraDao editd;
	private LivroDao ld;
	private UsuarioDao userd;
	private EmprestimoDao empd;
	private DevolucaoDao devd;
	private ReservaDao resd;
	private LoginDao logd;
	private ContatoDao contd;
	private ExemplarDao exd;
	
	
	public TelaBibliotecarioController(TelaBibliotecario view) {
		this.view = view;
	}
	
	public void setEvent(SelectionEvent se, int selRadio) {
		if ((se.getSource() instanceof Button)) {
			if (((Button) se.getSource()).getText().equals("Buscar")) {
				switch (selRadio){
				case 1:
					//Livro
					ld = new LivroDao();
					ld.busca(view.getBusca(), vec);
					break;
				case 2:
					//Usuário
					userd = new UsuarioDao();
					userd.busca(view.getBusca(), vec);
					break;
				case 3:
					//Empréstimo
					empd = new EmprestimoDao();
					empd.busca(view.getBusca(), vec);
					break;
				case 4:
					//Devolução
					devd = new DevolucaoDao();
					devd.busca(view.getBusca(), vec);
					break;
				case 5:
					//Reserva
					resd = new ReservaDao();
					resd.busca(view.getBusca(), vec);
					break;
				}
				view.resultBusca(vec, selRadio);
				vec.clear();
			} else {
				if (((Button) se.getSource()).getText().equals("Limpar")) {
					view.limparTela();
				}
			}
		}
	}
	
	public void setEventCLivro() {
		view.valuesCLivro(vec);
		Livro l = new Livro();
		l.setTitulo(vec.get(0).toString());
		l.setFk_id_autor(Integer.parseInt(vec.get(1).toString()));
		l.setFk_id_editora(Integer.parseInt(vec.get(2).toString()));
		l.setGenero(vec.get(3).toString());
		l.setCapa(vec.get(4).toString());
		l.setNum_pags(Integer.parseInt(vec.get(5).toString()));
		l.setPais(vec.get(6).toString());
		l.setAno_publicacao(Integer.parseInt(vec.get(7).toString()));
		l.setQtd_exemp(Integer.parseInt(vec.get(8).toString()));
		l.setSumario(vec.get(9).toString());
		l.setPalavras_chave(vec.get(10).toString());		
		ld = new LivroDao();
		ld.insert(l);
		view.cadastroRealizado(ld.getPk_cod_livro(vec.get(0).toString()));
		view.limparTelaCLivro();
		vec.clear();
	}
	
	public void setEventCExemplar() {
		view.valuesCExemplar(vec);
		Exemplar ex = new Exemplar();
		ex.setFk_cod_livro(Integer.parseInt(vec.get(0).toString()));
		ex.setEdicao(Integer.parseInt(vec.get(1).toString()));
		ex.setAno(Integer.parseInt(vec.get(2).toString()));
		ex.setEstado(vec.get(3).toString());
		ex.setDisp(Integer.parseInt(vec.get(4).toString()) == 1);
		exd = new ExemplarDao();
		exd.insert(ex);
		view.cadastroRealizado(exd.getPk_cod_exemp(Integer.parseInt(vec.get(0).toString())));
		view.limparTelaCExemplar();
		vec.clear();
	}
	
	public void setEventCUsuario() {
		view.valuesCUsuario(vec);
		logd = new LoginDao();
		if(logd.verifEmail(vec.get(5).toString())) {
			view.mensagemErroEmail();
		}else {
			Usuario u = new Usuario();
			Login l = new Login();
			Contato c = new Contato();
			l.setEmail(vec.get(5).toString());
			l.setSenha(vec.get(6).toString());
			l.setNivel(Integer.parseInt(vec.get(7).toString())==1);
			logd.insert(l);
			c.setTelefone(vec.get(8).toString());
			c.setEndereco(vec.get(9).toString());
			c.setCidade(vec.get(10).toString());
			c.setEstado(vec.get(11).toString());
			c.setCep(vec.get(12).toString());
			contd = new ContatoDao();
			contd.insert(c);
			u.setNome(vec.get(0).toString());
			u.setCpf(vec.get(1).toString());
			u.setRg(vec.get(2).toString());
			u.setFoto(vec.get(3).toString());
			u.setLimite_livro(Integer.parseInt(vec.get(4).toString()));
			userd = new UsuarioDao();
			userd.insert(u, vec.get(5).toString(), contd.buscar(c));
			view.cadastroRealizado(userd.getPk_id(vec.get(5).toString()));
			view.limparTelaCUsuario();
		}
		vec.clear();
	}
	
	public void setEventCAutor() {
		view.valuesCAutor(vec);
		Autor a = new Autor();
		a.setNome(vec.get(0).toString());
		a.setBiografia(vec.get(1).toString());
		a.setFoto(vec.get(2).toString());
		autd = new AutorDao();
		autd.insert(a);
		view.cadastroRealizado(autd.getPk_id_autor(vec.get(0).toString()));
		view.limparTelaCAutor();
		vec.clear();
	}
	
	public void setEventCEditora() {
		view.valuesCEditora(vec);
		Editora e = new Editora();
		e.setNome(vec.get(0).toString());
		e.setContato(vec.get(1).toString());
		e.setCnpj(vec.get(2).toString());
		editd = new EditoraDao();
		editd.insert(e);
		view.cadastroRealizado(editd.getPk_codigo(vec.get(0).toString()));
		view.limparTelaCEditora();
		vec.clear();
	}
	
	public void setEventEmprestimo() {
		view.valuesEmp_Dev(vec);
		logd = new LoginDao();
		exd = new ExemplarDao();
		if(logd.verificar(vec.get(0).toString(), vec.get(1).toString(), 0) && exd.dispExemplar(Integer.parseInt(vec.get(2).toString()))) {
			empd = new EmprestimoDao();
			empd.insert(vec.get(0).toString(), Integer.parseInt(vec.get(2).toString()), view.getUser());
			view.mensagemEmp_Dev("Empréstimo realizado");
			view.limparTelaEmp_Dev();
		}else {
			view.mensagemEmp_Dev("Empréstimo não autorizado");
		}
		vec.clear();
	}
	
	public void setEventDevolucao() {
		view.valuesEmp_Dev(vec);
		logd = new LoginDao();
		exd = new ExemplarDao();
		if(logd.verificar(vec.get(0).toString(), vec.get(1).toString(), 0) && !exd.dispExemplar(Integer.parseInt(vec.get(2).toString()))) {
			devd = new DevolucaoDao();
			devd.insert(Integer.parseInt(vec.get(2).toString()), view.getUser());
			view.valorMulta(devd.valorMulta(Integer.parseInt(vec.get(2).toString())));
			view.mensagemEmp_Dev("Devolução realizada");
			view.limparTelaEmp_Dev();
		}else {
			view.mensagemEmp_Dev("Erro na devolução");
		}
		vec.clear();
	}
	
}
