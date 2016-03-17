package org.news.entity;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.Table;

@Entity
@Table(name = "N_USER")
public class User {
	@Id
	@GeneratedValue(strategy = GenerationType.AUTO)
	@Column(name = "USER_ID")
	private long userId;
	@Column(name = "LOGIN")
	private String login;
	@Column(name = "PASSWORD")
	private String password;
	@Column(name = "USERNAME")
	private String userName;
	@Column(name = "EMAIL")
	private String email;

	public User() {

	}

	public long getUserId() {
		return userId;
	}
	
	public String getUserInfo() {
		return "userId: "+userId+" login: "+login+" password: "+password+
				" userName: "+userName+" email: "+email;
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
