package view;

import org.eclipse.swt.widgets.*;
import org.eclipse.wb.swt.SWTResourceManager;

import org.eclipse.swt.SWT;
import org.eclipse.swt.events.SelectionAdapter;
import org.eclipse.swt.events.SelectionEvent;
import org.eclipse.swt.widgets.Button;

public class TelaLogin {
	
	private Display display = new Display();
	private TelaLoginController lgController = new TelaLoginController(this);
	protected Shell shell;
	private Text textUser;
	private Text textSenha;
	
	public TelaLogin() {
		try {
			exibirTelaLogin();
		} catch (Exception e) {
			e.printStackTrace();
			
		}
	}
	
	protected void exibirTelaLogin() {
		shell = new Shell(display);
		shell.setSize(500, 395);
		shell.setText("Biblioteca");
		
		Label lblLogin = new Label(shell, SWT.NONE);
		lblLogin.setFont(SWTResourceManager.getFont("Noto Sans", 15, SWT.NORMAL));
		lblLogin.setBounds(10, 10, 106, 32);
		lblLogin.setText("Login");
		
		Label lblUser = new Label(shell, SWT.NONE);
		lblUser.setBounds(10, 48, 58, 17);
		lblUser.setText("Usuário:");
		
		textUser = new Text(shell, SWT.BORDER);
		textUser.setBounds(10, 71, 255, 23);
		
		Label lblSenha = new Label(shell, SWT.NONE);
		lblSenha.setBounds(10, 109, 58, 17);
		lblSenha.setText("Senha:");
		
		textSenha = new Text(shell, SWT.BORDER | SWT.PASSWORD);
		textSenha.setBounds(10, 132, 255, 23);
		
		Button btnEntrar = new Button(shell, SWT.NONE);
		btnEntrar.setBounds(10, 180, 83, 23);
		btnEntrar.setText("Entrar");
		
		Button btnClear = new Button(shell, SWT.NONE);
		btnClear.setBounds(99, 180, 83, 23);
		btnClear.setText("Limpar");
		
		limparTela();
		
		SelectionAdapter sa = new SelectionAdapter() {
			@Override
			public void widgetSelected(SelectionEvent e) {
				if (((Button) e.getSource()).getText().equals("Entrar")) {
					if (validaDados()) {
						lgController.setEvent(e);
					} else {
						mensagemErro();
					}
				}else {
					lgController.setEvent(e);
				}
			}
		};		
		btnEntrar.addSelectionListener(sa);
		btnClear.addSelectionListener(sa);
		
		shell.open();
		while (!shell.isDisposed()) {
			if (!display.readAndDispatch()) {
				display.sleep();
			}
		}
	}
	
	public boolean validaDados() {
		if(textUser.getText().equals("") || textSenha.getText().equals("")) {
			return false;
		}
		return true;
	}
	
	public void limparTela() {
		textUser.setText("");
		textSenha.setText("");
	}
	
	public void mensagemErro() {
		MessageBox mensBox = new MessageBox(shell, SWT.ICON_WARNING);
		mensBox.setText("Aviso");
		mensBox.setMessage("Preencha todos os campos corretamente");
		mensBox.open();
	}
	
	public void mensagemLoginErro() {
		MessageBox mensBox = new MessageBox(shell, SWT.ICON_CANCEL);
		mensBox.setText("Aviso");
		mensBox.setMessage("Email ou senha incorretos");
		mensBox.open();
	}
	
	public void setVisible(boolean aux) {
		shell.setVisible(aux);
		display.close();
	}
	
	public String getUser() {
		return textUser.getText().toString();
	}
	
	public String getSenha() {
		return textSenha.getText();
	}
	
}
