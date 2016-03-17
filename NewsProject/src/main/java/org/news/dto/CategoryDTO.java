package org.news.dto;

import java.util.List;



public class CategoryDTO {

	private long categoryId;
	private String categoryName;
	private List<NewsDTO> news;

	public CategoryDTO() {

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

	public List<NewsDTO> getNews() {
		return news;
	}

	public void setNews(List<NewsDTO> news) {
		this.news = news;
	}
}
