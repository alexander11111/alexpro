package org.news.dto;

import java.util.Date;
import java.util.List;


import org.news.entity.User;

public class NewsDTO {
	private long newsId;
	private String title;
	private String brief;
	private String content;
	private Date created;
	private String strcreated;
	private Date lastModified;
	private UserDTO author;
	private List<CommentDTO> comments;
	private CategoryDTO category;

	public NewsDTO() {

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

	public String getstrcreated() {
		return strcreated;
	}
	
	public void setstrcreated(String strcreated) {
		this.strcreated = strcreated;
	}	

	public Date getLastModified() {
		return lastModified;
	}

	public void setLastModified(Date lastModified) {
		this.lastModified = lastModified;
	}

	public UserDTO getAuthor() {
		return author;
	}

	public void setAuthor(UserDTO author) {
		this.author = author;
	}

	public List<CommentDTO> getComments() {
		return comments;
	}

	public void setComments(List<CommentDTO> comments) {
		this.comments = comments;
	}

	public CategoryDTO getCategory() {
		return category;
	}

	public void setCategory(CategoryDTO category) {
		this.category = category;
	}
}
