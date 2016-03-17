package org.news.exception;

public class NewsServiceException extends Exception {
	private static final long serialVersionUID = 1L;

	public NewsServiceException(Throwable e) {
		super(e);
	}
}
