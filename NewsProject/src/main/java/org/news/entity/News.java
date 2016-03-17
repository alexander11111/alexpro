package org.news.entity;

import java.util.Date;
import java.util.List;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.JoinColumn;
import javax.persistence.ManyToOne;
import javax.persistence.OneToMany;
import javax.persistence.Table;
import javax.persistence.Temporal;
import javax.persistence.TemporalType;

@Entity
@Table(name = "N_NEWS")
public class News {
	@Id
	@GeneratedValue(strategy = GenerationType.AUTO)
	@Column(name = "NEWS_ID")
	private long newsId;
	@Column(name = "TITLE")
	private String title;
	@Column(name = "BRIEF")
	private String brief;
	@Column(name = "CONTENT")
	private String content;
	@Column(name = "CREATED")
	@Temporal(TemporalType.TIMESTAMP)
	private Date created;
	@Column(name = "LAST_MODIFIED")
	@Temporal(TemporalType.TIMESTAMP)
	private Date lastModified;
	@ManyToOne()
	@JoinColumn(name = "USER_ID")
	private User author;
	@OneToMany(mappedBy = "news")
	private List<Comment> comments;
	@ManyToOne
	@JoinColumn(name = "CATEGORY_ID")
	private Category category;

	public News() {

	}

	public long getNewsId() {
		return newsId;
	}

	public void setNewsId(long newsId) {
		this.newsId = newsId;
	}

	public String getTitle() {
		return title;
	}

	public void setTitle(String title) {
		this.title = title;
	}

	public String getBrief() {
		return brief;
	}

	public void setBrief(String brief) {
		this.brief = brief;
	}

	public String getContent() {
		return content;
	}

	public void setContent(String content) {
		this.content = content;
	}

	public Date getCreated() {
		return created;
	}

	public void setCreated(Date created) {
		this.created = created;
	}

	public Date getLastModified() {
		return lastModified;
	}

	public void setLastModified(Date lastModified) {
		this.lastModified = lastModified;
	}

	public User getAuthor() {
		return author;
	}

	public void setAuthor(User author) {
		this.author = author;
	}

	public List<Comment> getComments() {
		return comments;
	}

	public void setComments(List<Comment> comments) {
		this.comments = comments;
	}

	public Category getCategory() {
		return category;
	}

	public void setCategory(Category category) {
		this.category = category;
	}
}
