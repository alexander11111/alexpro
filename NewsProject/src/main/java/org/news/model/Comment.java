package org.news.model;

import java.util.Date;

public class Comment {
	private long commentId;
	private UserModel author;
	private String message;
	private Date created;
	private String strcreated;
	private NewsModel news;

	public Comment() {

	}

	public long getCommentId() {
		return commentId;
	}

	public void setCommentId(long commentId) {
		this.commentId = commentId;
	}

	public UserModel getAuthor() {
		return author;
	}

	public void setAuthor(UserModel author) {
		this.author = author;
	}

	public String getMessage() {
		return message;
	}

	public void setMessage(String message) {
		this.message = message;
	}

	public Date getCreated() {
		return created;
	}

	public void setCreated(Date created) {
		this.created = created;
	}

	public NewsModel getNews() {
		return news;
	}

	public void setNews(NewsModel news) {
		this.news = news;
	}
	
	public String getstrcreated() {
		return strcreated;
	}

	public void setstrcreated(String strcreated) {
		this.strcreated = strcreated;
	}
}
