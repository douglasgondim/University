package view;

import org.eclipse.swt.events.SelectionEvent;
import org.eclipse.swt.widgets.Button;

import dao.LoginDao;

public class TelaLoginController {
	private TelaLogin view;
	private LoginDao logind = new LoginDao();
	
	public TelaLoginController(TelaLogin view) {
		this.view = view;
	}
	
	public void setEvent(SelectionEvent sa) {
		if ((sa.getSource() instanceof Button)) {
			if (((Button) sa.getSource()).getText().equals("Entrar")) {
				if(logind.verificar(view.getUser(), view.getSenha(), 1)) {
					String aux = view.getUser();
					view.setVisible(false);
					new TelaBibliotecario(aux);
				}else {
					view.mensagemLoginErro();
				}
			} else {
				if (((Button) sa.getSource()).getText().equals("Limpar")) {
					view.limparTela();
				}
			}
		}
	}
}
