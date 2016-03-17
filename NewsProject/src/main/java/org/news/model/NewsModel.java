package org.news.model;

import java.util.Date;
import java.util.List;
import org.news.entity.User;
public class NewsModel {
	private long newsId;
	private String title;
	private String brief;
	private String content;
	private Date created;
	private String strcreated;
	private Date lastModified;
	private UserModel author;
	private List<Comment> comments;
	private CategoryMod category;
	private long isAutorized;

	public NewsModel() {

	}

	public String getNewsInfo() {
		return " newsId:"+newsId+
				" title:"+title+
				" brief:"+brief+
				" content:"+content;
	}
	
	public long getisAutorized() {
		return isAutorized;
	}

	public void setisAutorized(long isAutorized) {
		this.isAutorized = isAutorized;
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

	public UserModel getAuthor() {
		return author;
	}

	public void setAuthor(UserModel author) {
		this.author = author;
	}

	public List<Comment> getComments() {
		return comments;
	}

	public void setComments(List<Comment> comments) {
		this.comments = comments;
	}

	public CategoryMod getCategory() {
		return category;
	}
	public void setCategory(CategoryMod category) {
		this.category = category;
	}


}
