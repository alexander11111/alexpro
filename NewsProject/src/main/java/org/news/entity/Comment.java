package org.news.entity;

import java.util.Date;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.JoinColumn;
import javax.persistence.ManyToOne;
import javax.persistence.Table;
import javax.persistence.Temporal;
import javax.persistence.TemporalType;

@Entity
@Table(name = "N_COMMENT")
public class Comment {
	@Id
	@GeneratedValue(strategy = GenerationType.AUTO)
	@Column(name = "COMMENT_ID")
	private long commentId;
	@ManyToOne
	@JoinColumn(name = "USER_ID")
	private User author;
	@Column(name="MESSAGE")
	private String message;
	@Column(name="CREATED")
	@Temporal(TemporalType.TIMESTAMP)
	private Date created;
	@ManyToOne
	@JoinColumn(name = "NEWS_ID")
	private News news;

	public Comment() {

	}

	public long getCommentId() {
		return commentId;
	}

	public void setCommentId(long commentId) {
		this.commentId = commentId;
	}

	public User getAuthor() {
		return author;
	}

	public void setAuthor(User author) {
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

	public News getNews() {
		return news;
	}

	public void setNews(News news) {
		this.news = news;
	}
}
