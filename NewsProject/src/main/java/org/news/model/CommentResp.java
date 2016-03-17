package org.news.model;

import java.util.Date;

public class CommentResp {
	private long isAutorized;
	private long commentId;
	private long newsId;
	private long categoryId;
	private long userId;
	private long savestate;
	private String strcreated;
	private String userName;

	public CommentResp() {

	}
	public long getisAutorized() {
		return isAutorized;
	}

	public void setisAutorized(long isAutorized) {
		this.isAutorized = isAutorized;
	}
	
	public long getcommentId() {
		return commentId;
	}

	public void setcommentId(long commentId) {
		this.commentId = commentId;
	}
	
	public long getsavestate() {
		return savestate;
	}

	public void setsavestate(long savestate) {
		this.savestate = savestate;
	}
	
	public long getnewsId() {
		return newsId;
	}

	public void setnewsId(long newsId) {
		this.newsId = newsId;
	}	
	
	public long getcategoryId() {
		return categoryId;
	}

	public void setcategoryId(long categoryId) {
		this.categoryId = categoryId;
	}	
	
	public long getuserId() {
		return userId;
	}

	public void setuserId(long userId) {
		this.userId = userId;
	}	
	
	public String getstrcreated() {
		return strcreated;
	}

	public void setstrcreated(String strcreated) {
		this.strcreated = strcreated;
	}	
	public String getuserName() {
		return userName;
	}

	public void setuserName(String userName) {
		this.userName = userName;
	}
}
