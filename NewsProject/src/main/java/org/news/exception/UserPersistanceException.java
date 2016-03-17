package org.news.exception;

public class UserPersistanceException extends Exception {
	private static final long serialVersionUID = 1L;

	public UserPersistanceException(Throwable e) {
		super(e);
	}
}
