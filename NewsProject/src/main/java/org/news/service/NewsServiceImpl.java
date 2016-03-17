package org.news.service;

import java.util.Date;
import java.util.List;

import org.news.dal.INewsDAO;
import org.news.exception.NewsPersistanceException;
import org.news.exception.NewsServiceException;
import org.news.model.Comment;
import org.news.model.NewsModel;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import static org.news.util.ServiceConverter.*;

@Service
public class NewsServiceImpl implements NewsService {

	@Autowired
	private INewsDAO storage;

	@Override
	public List<NewsModel> getNewsList() throws NewsServiceException {
		List<NewsModel> newsList = null;
		try {
			newsList = convert(storage.getNews());
		} catch (NewsPersistanceException e) {
			throw new NewsServiceException(e);
		}
		return newsList;
	}

	public void setStorage(INewsDAO storage) {
		this.storage = storage;
	}

	@Override
	public void addNews(NewsModel news) throws NewsServiceException {
		news.setCreated(new Date());
		news.setLastModified(new Date());
		try {
			storage.addNews(convert(news));
		} catch (NewsPersistanceException e) {
			throw new NewsServiceException(e);
		}
	}
	
	@Override
	public Long addComment(org.news.model.Comment comment) throws NewsServiceException {
		try {
			return storage.addComment(convertmd(comment));
		} catch (NewsPersistanceException e) {
			throw new NewsServiceException(e);
		}
	}
	@Override
	public void delNews(Long newsID) throws NewsServiceException{
		try {
			storage.delNews(newsID);
		} catch (NewsPersistanceException e) {
			throw new NewsServiceException(e);
		}		
	}
	@Override
	public void delComments(Comment comm) throws NewsServiceException{
		try {
			storage.delComments(convertmd(comm));
		} catch (NewsPersistanceException e) {
			throw new NewsServiceException(e);
		}		
	}
	
	@Override
	public void delCommentID(Long id) throws NewsServiceException{
	try {
		storage.delCommentID(id);
	} catch (NewsPersistanceException e) {
		throw new NewsServiceException(e);
	}		
    }	

	@Override
	public NewsModel getNews(long id) throws NewsServiceException {
		try {
			return convert(storage.getNews(id));
		} catch (NewsPersistanceException e) {
			throw new NewsServiceException(e);
		}
	}

	@Override
	public List<NewsModel> getNewsCat(long categoryID)
			throws NewsServiceException {
		try {
			return convert(storage.getNewsCat(categoryID));
		} catch (NewsPersistanceException e) {
			throw new NewsServiceException(e);
		}
	}
	
	public boolean checkUser(String email,String password) throws NewsServiceException {
		try {
			return storage.checkUser(email,password);
		} catch (NewsPersistanceException e) {
			throw new NewsServiceException(e);
		}
	}
}
