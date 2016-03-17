package org.news.dal;

import java.util.List;

import org.news.dto.CommentDTO;
import org.news.dto.NewsDTO;
import org.news.entity.Comment;
import org.news.exception.NewsPersistanceException;
import org.news.exception.NewsServiceException;

public interface INewsDAO {
	public List<NewsDTO> getNews() throws NewsPersistanceException;

	public NewsDTO getNews(long newsId) throws NewsPersistanceException;

	public void addNews(NewsDTO news) throws NewsPersistanceException;

	public void delete(NewsDTO news) throws NewsPersistanceException;

	public void update(NewsDTO news) throws NewsPersistanceException;

	public List<CommentDTO> getComments(int newsId)
			throws NewsPersistanceException;

	public Long addComment(CommentDTO comment) throws NewsPersistanceException;

	public List<NewsDTO> getNewsCat(long categoryID) throws NewsPersistanceException;
	
	public boolean checkUser(String email,String password) throws NewsPersistanceException;
	
	public void delNews(Long newsID) throws NewsPersistanceException;
	
	public void delComments(CommentDTO comm) throws NewsPersistanceException;
	
	public void delCommentID(Long id) throws NewsPersistanceException;
}
