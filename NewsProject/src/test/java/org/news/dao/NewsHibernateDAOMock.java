package org.news.dao;

import java.util.ArrayList;
import java.util.List;

import org.news.dal.INewsDAO;
import org.news.dto.CommentDTO;
import org.news.dto.NewsDTO;
import org.news.exception.NewsPersistanceException;

public class NewsHibernateDAOMock implements INewsDAO {

	public List<NewsDTO> newsList = new ArrayList<>();

	@Override
	public List<NewsDTO> getNews() throws NewsPersistanceException {
		return newsList;
	}

	@Override
	public NewsDTO getNews(long newsId) throws NewsPersistanceException {
		for (NewsDTO news : newsList) {
			if (news.getNewsId() == newsId) {
				return news;
			}
		}
		return null;
	}

	@Override
	public void addNews(NewsDTO news) throws NewsPersistanceException {
		newsList.add(news);
	}

	@Override
	public void delete(NewsDTO news) throws NewsPersistanceException {
		// TODO Auto-generated method stub

	}

	@Override
	public void update(NewsDTO news) throws NewsPersistanceException {
		// TODO Auto-generated method stub

	}

	@Override
	public List<CommentDTO> getComments(int newsId)
			throws NewsPersistanceException {
		// TODO Auto-generated method stub
		return null;
	}

	

	public void clean() {
		newsList.clear();
	}

	@Override
	public Long addComment(CommentDTO comment) throws NewsPersistanceException {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public List<NewsDTO> getNewsCat(long categoryID) throws NewsPersistanceException {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public boolean checkUser(String email, String password) throws NewsPersistanceException {
		// TODO Auto-generated method stub
		return false;
	}

	@Override
	public void delNews(Long newsID) throws NewsPersistanceException {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void delComments(CommentDTO comm) throws NewsPersistanceException {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void delCommentID(Long id) throws NewsPersistanceException {
		// TODO Auto-generated method stub
		
	}

}
