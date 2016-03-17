package org.news.service;

import java.util.List;

import org.news.dto.CommentDTO;
import org.news.dto.NewsDTO;
import org.news.exception.NewsPersistanceException;
import org.news.exception.NewsServiceException;
import org.news.model.Comment;
import org.news.model.NewsModel;

public interface NewsService {
	public List<NewsModel> getNewsCat(long categoryID) throws NewsServiceException;

	public List<NewsModel> getNewsList() throws NewsServiceException;

	public void addNews(NewsModel news) throws NewsServiceException;

	public NewsModel getNews(long id) throws NewsServiceException;
	
	public Long addComment(org.news.model.Comment comment) throws NewsServiceException;
	
	public boolean checkUser(String email,String password) throws NewsServiceException;
	
	public void delNews(Long newsID) throws NewsServiceException;
	
	public void delComments(Comment comm) throws NewsServiceException;
	
	public void delCommentID(Long id) throws NewsServiceException;
	
}
