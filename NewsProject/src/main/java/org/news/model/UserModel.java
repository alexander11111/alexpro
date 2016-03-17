package org.news.model;

public class UserModel {
	private long userId;
	private String login;
	private String password;
	private String cpassword;
	private String userName;
	private String email;
	private long isAutorized;

	public UserModel() {

	}

	public long getisAutorized() {
		return isAutorized;
	}

	public void setisAutorized(long isAutorized) {
		this.isAutorized = isAutorized;
	}
	
	public long getUserId() {
		return userId;
	}
	
	public String getUserInfo() {
		return "userId: "+userId+" login: "+login+" password: "+password+" cpassword: "+
				cpassword+" userName: "+userName+" email: "+email;
	}

	public void setUserId(long userId) {
		this.userId = userId;
	}

	public String getLogin() {
		return login;
	}

	public void setLogin(String login) {
		this.login = login;
	}

	public String getPassword() {
		return password;
	}

	public void setPassword(String password) {
		this.password = password;
	}
	
	public String getCpassword() {
		return cpassword;
	}

	public void setCpassword(String cpassword) {
		this.cpassword = cpassword;
	}
	public String getUserName() {
		return userName;
	}

	public void setUserName(String userName) {
		this.userName = userName;
	}

	public String getEmail() {
		return email;
	}

	public void setEmail(String email) {
		this.email = email;
	}

}
