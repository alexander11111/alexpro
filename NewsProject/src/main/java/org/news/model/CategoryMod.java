package org.news.model;

import java.util.List;




public class CategoryMod {
	private long categoryId;
	private String categoryName;

	private List<NewsModel> news;

	public CategoryMod() {

	}

	public long getCategoryId() {
		return categoryId;
	}

	public void setCategoryId(long categoryId) {
		this.categoryId = categoryId;
	}

	public String getCategoryName() {
		return categoryName;
	}

	public void setCategoryName(String categoryName) {
		this.categoryName = categoryName;
	}

	public List<NewsModel> getNews() {
		return news;
	}

	public void setNews(List<NewsModel> news) {
		this.news = news;
	}
}
