package org.news.dto;

import java.util.Date;

public class CommentDTO {
	private long commentId;
	private UserDTO author;
	private String message;
	private Date created;
	private NewsDTO news;

	public CommentDTO() {

	}

	public long getCommentId() {
		return commentId;
	}

	public void setCommentId(long commentId) {
		this.commentId = commentId;
	}

	public UserDTO getAuthor() {
		return author;
	}

	public void setAuthor(UserDTO author) {
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

	public NewsDTO getNews() {
		return news;
	}

	public void setNews(NewsDTO news) {
		this.news = news;
	}
}
