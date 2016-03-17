package org.news.dal;

import org.news.dto.UserDTO;
import org.news.entity.User;
import org.news.exception.NewsPersistanceException;
import org.news.exception.UserPersistanceException;

public interface IUserDAO {
	public UserDTO getUser(String login, String password)
			throws UserPersistanceException;
	public void addUser(UserDTO user)
			throws UserPersistanceException;
}
