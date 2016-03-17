package org.news.dal;

import org.hibernate.HibernateException;
import org.hibernate.Query;
import org.hibernate.Session;
import org.hibernate.SessionFactory;
import org.news.dto.UserDTO;
import org.news.entity.User;
import org.news.exception.NewsPersistanceException;
import org.news.exception.UserPersistanceException;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Repository;
import org.springframework.transaction.annotation.Transactional;

import static org.news.util.ServiceConverter.*;
import static org.news.util.StorageConverter.convert;

@Repository
@Transactional
public class UserHibernateDAOImpl implements IUserDAO {
	@Autowired
	private SessionFactory sessionFactory;

	@Override
	public UserDTO getUser(String login, String password)
			throws UserPersistanceException {
		User user = null;
		try {
			Query query = currentSession().createQuery(
					"FROM User where login=:ln and password = :pswd");
			query.setParameter("ln", login);
			query.setParameter("pswd", password);
			if (query.list().size()!=0)
			user = (User)query.uniqueResult(); else
				user = new User();
		} catch (HibernateException e) {
			throw new UserPersistanceException(e);
		}
		return convert(user);
	}
	public void addUser(UserDTO user) throws UserPersistanceException{
		try {
			currentSession().save(convert(user));
		} catch (HibernateException e) {
			throw new UserPersistanceException(e);
		}	
	}

	private Session currentSession() {
		Session currentSession = sessionFactory.getCurrentSession();
		// Session currentSession = sessionFactory.openSession();
		return currentSession;
	}

}
