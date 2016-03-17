package org.news.dal;

import java.util.List;

import org.hibernate.HibernateException;
import org.hibernate.Query;
import org.hibernate.Session;
import org.hibernate.SessionFactory;
import org.news.dto.CommentDTO;
import org.news.dto.NewsDTO;
import org.news.dto.UserDTO;
import org.news.entity.Category;
import org.news.entity.Comment;
import org.news.entity.News;
import org.news.entity.User;
import org.news.exception.NewsPersistanceException;
import org.news.exception.NewsServiceException;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Repository;
import org.springframework.transaction.annotation.Transactional;

import static org.news.util.StorageConverter.*;

@Repository
@Transactional
public class NewsHibernateDAOImpl implements INewsDAO {
	@Autowired
	private SessionFactory sessionFactory;

	@SuppressWarnings("unchecked")
	@Override
	public List<NewsDTO> getNews() throws NewsPersistanceException {
		try {
			return convert(currentSession().createQuery("From News ORDER BY created").list());
		} catch (HibernateException e) {
			throw new NewsPersistanceException(e);
		}
	}
	
	@SuppressWarnings("unchecked")
	@Override
	public List<NewsDTO> getNewsCat(long categoryID) throws NewsPersistanceException {
		try {
			//List<Category> category = (List<Category>)currentSession().createQuery("From Category where categoryId="+categoryID).list();
			//return convert(category.get(0).getNews());
			//return convert(category.get(0));
			return convert(currentSession().createQuery("From News where CATEGORY_ID="+categoryID+" ORDER BY created").list());
		} catch (HibernateException e) {
			throw new NewsPersistanceException(e);
		}
	}
	
	public boolean checkUser(String email,String password) throws NewsPersistanceException{
		List<User> user=null;
		try {
			user =  (List<User>)(currentSession().createQuery("From User where EMAIL='"+email+"' AND PASSWORD='"+password+"'").list());
			if (user==null) return false;
			if (user.size()==0) return false;
		} catch (HibernateException e) {
			return false;
			//throw new NewsPersistanceException(e);
		}
		return true;
	}

	@Override
	public NewsDTO getNews(long newsId) throws NewsPersistanceException {
		try {
			News nEntity = (News) currentSession().get(News.class, newsId);
			return convert(nEntity);
		} catch (HibernateException e) {
			throw new NewsPersistanceException(e);
		}
	}
	
	@Override
	public void addNews(NewsDTO news) throws NewsPersistanceException {
		try {
			currentSession().save(convert(news));
		} catch (HibernateException e) {
			throw new NewsPersistanceException(e);
		}
	}

	@Override
	public void delete(NewsDTO news) throws NewsPersistanceException {
		try {
			currentSession().delete(news);
		} catch (HibernateException e) {
			throw new NewsPersistanceException(e);
		}
	}
	
	@Override
	public void delNews(Long newsID) throws NewsPersistanceException {
		try {
			News news = (News) currentSession().get(News.class, newsID);
			for (org.news.entity.Comment comment : news.getComments()) {
				Query query = currentSession().createQuery("delete Comment where COMMENT_ID="+comment.getCommentId());
				query.executeUpdate();
			}
			Query query = currentSession().createQuery("delete News where NEWS_ID="+news.getNewsId());
			query.executeUpdate();
		} catch (HibernateException e) {
			throw new NewsPersistanceException(e);
		}
	}
	@Override
	public void delComments(CommentDTO comm) throws NewsPersistanceException {
		try {
			currentSession().delete(convert(comm));
		} catch (HibernateException e) {
			throw new NewsPersistanceException(e);
		}
	}
	public void delCommentID(Long id) throws NewsPersistanceException{
		try {
			Query query = currentSession().createQuery("delete Comment where COMMENT_ID="+id);
			query.executeUpdate();
		} catch (HibernateException e) {
			throw new NewsPersistanceException(e);
		}		
	}
	@Override
	public void update(NewsDTO news) throws NewsPersistanceException {
		try {
			currentSession().update(news);
		} catch (HibernateException e) {
			throw new NewsPersistanceException(e);
		}
	}

	@Override
	public List<CommentDTO> getComments(int newsId)
			throws NewsPersistanceException {
		try {
			return currentSession().createQuery(
					"From Comment where NEWS_ID = " + newsId).list();
		} catch (HibernateException e) {
			throw new NewsPersistanceException(e);
		}
	}

	@Override
	public Long addComment(CommentDTO comment) throws NewsPersistanceException {
		try {
			Comment comm = org.news.util.ServiceConverter.convertmd(comment);
			currentSession().save(comm);
			return comm.getCommentId();
		} catch (HibernateException e) {
			throw new NewsPersistanceException(e);
		}
	}

	private Session currentSession() {
		Session currentSession = sessionFactory.getCurrentSession();
		// Session currentSession = sessionFactory.openSession();
		return currentSession;
	}

}
